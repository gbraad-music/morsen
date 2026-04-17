#pragma once
/*
 * Morse Code Oscillator for NTS-1 mkII
 * 
 * (c) 2026 Gerard Braad <me@gbraad.nl>
 * 
 * Converts MIDI notes to Morse code patterns using DasBeep
 */


#include <cstddef>
#include <cstdint>
#include <cstring>
#include "unit.h"

extern "C" {
#define DASBEEP_WITH_MORSE  // Enable Morse code tables
#include "dasbeep.h"
}


class Synth {
public:
    Synth()
        : sample_rate_(48000)
        , speed_wpm_(12)
        , tone_hz_(800)
        , is_playing_(false)
    {
    }

    inline int8_t Init(const unit_runtime_desc_t *desc) {
        if (desc->samplerate != 48000)
            return k_unit_err_samplerate;

        if (desc->output_channels != 2)
            return k_unit_err_geometry;

        sample_rate_ = desc->samplerate;

        dasbeep_init(&beep_, sample_rate_);
        beep_.frequency = tone_hz_;
        beep_.amplitude = 0.8f;  // Boost from default 0.3

        // Set initial timing based on speed
        updateTiming();

        return k_unit_err_none;
    }

    inline void Teardown() {}

    inline void Reset() {
        dasbeep_stop(&beep_);
    }

    inline void Resume() {}

    inline void Suspend() {}

    fast_inline void Render(float *out, size_t frames) {
        float *y = out;
        const float *y_end = out + (frames * 2);

        for (; y != y_end; y += 2) {
            float sample = dasbeep_process(&beep_);

            // If pattern finished, output very low level to keep voice alive
            if (sample == 0.0f && dasbeep_is_active(&beep_) == false) {
                sample = 0.00001f;  // Inaudible, but keeps voice allocated
            }

            y[0] = sample;  // Left
            y[1] = sample;  // Right
        }
    }

    inline void setParameter(uint8_t index, int32_t value) {
        switch (index) {
            case 0:  // Speed (WPM)
                speed_wpm_ = value;
                updateTiming();
                break;
            case 1:  // Tone frequency
                tone_hz_ = value;
                beep_.frequency = (float)tone_hz_;
                break;
        }
    }

    inline const char *getParameterStrValue(uint8_t index, int32_t value) {
        (void)index;
        (void)value;
        return "";
    }

    inline void NoteOn(uint8_t note, uint8_t velocity) {
        (void)velocity;

        // Don't retrigger if already playing
        if (dasbeep_is_active(&beep_)) {
            return;
        }

        // Map chromatic scale to A-Z (26 letters across 3 octaves)
        // C2=48: A-L (12 notes)
        // C3=60: M-X (12 notes)
        // C4=72: Y-Z (2 notes)

        const char* pattern = nullptr;
        int letter_index = -1;

        if (note >= 48 && note <= 59) {
            // Octave 2: C2-B2 = A-L
            letter_index = note - 48;  // 0-11 = A-L
        } else if (note >= 60 && note <= 71) {
            // Octave 3: C3-B3 = M-X
            letter_index = 12 + (note - 60);  // 12-23 = M-X
        } else if (note >= 72 && note <= 73) {
            // Octave 4: C4-C#4 = Y-Z
            letter_index = 24 + (note - 72);  // 24-25 = Y-Z
        }

        if (letter_index >= 0 && letter_index < 26) {
            pattern = dasbeep_morse_alphabet[letter_index];
        }

        if (pattern) {
            dasbeep_start(&beep_, pattern);
        }
    }

    inline void NoteOff(uint8_t note) {
        (void)note;
        // Let pattern complete naturally
    }

    inline void AllNoteOff() {
        dasbeep_stop(&beep_);
    }

    inline void PitchBend(uint16_t bend) {
        (void)bend;
    }

    inline void ChannelPressure(uint8_t press) {
        (void)press;
    }

    inline void Aftertouch(uint8_t note, uint8_t press) {
        (void)note;
        (void)press;
    }


private:
    inline void updateTiming() {
        // WPM = Words Per Minute (PARIS standard: 50 dit units per word)
        // Dit length (ms) = 1200 / WPM
        // Dah = 3 × dit
        // Gap between elements = 1 dit
        // Gap between letters = 3 dits

        uint32_t dit_ms = 1200 / speed_wpm_;
        beep_.dit_ms = dit_ms;
        beep_.dah_ms = dit_ms * 3;
        beep_.gap_ms = dit_ms;
        beep_.silence_ms = dit_ms * 3;
    }

    uint32_t sample_rate_;
    int32_t speed_wpm_;
    int32_t tone_hz_;
    bool is_playing_;
    DasBeep beep_;
};
