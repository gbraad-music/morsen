/**
 * Morse Code Oscillator for NTS-1 mkII
 * 
 * (c) 2026 Gerard Braad <me@gbraad.nl>
 * 
 * Converts MIDI notes to Morse code patterns using DasBeep
 */

#include "unit_osc.h"

const __unit_header unit_header_t unit_header = {
    .header_size = sizeof(unit_header_t),
    .target = UNIT_TARGET_PLATFORM | k_unit_module_osc,
    .api = UNIT_API_VERSION,
    .dev_id = 0x72677276U,  // 'rgrv'
    .unit_id = 0x4D4F5253U, // 'MORS'
    .version = 0x00010000U,
    .name = "Morsen",
    .num_params = 2,
    .params = {
        // Shape knob - Speed (WPM)
        {5, 30, 15, 12, k_unit_param_type_none, 0, 0, 0, {"Speed"}},

        // Alt knob - Tone (Hz)
        {400, 1200, 800, 800, k_unit_param_type_none, 0, 0, 0, {"Tone"}},

        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
    }
};
