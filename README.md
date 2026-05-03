Morsen
======


Morse Code Oscillator for [NTS-1 mkII](https://github.com/korginc/logue-sdk/tree/main/platform/nts-1_mkii)

Converts MIDI notes to Morse code patterns using [DasBeep](https://github.com/gbraad-music/dasbeep)


## See It In Action

A simple Morse code unit that beeps based on the played note/letter.

  - Video on [YouTube](https://youtu.be/wYbnO9P4fbs)
  - Download [Morse Code Oscillator for NTS-1 mkII](https://gbraad.itch.io/morsen-logue)  
    Full implementation using DasBeep to translate MIDI notes to Morse code.


## Note mapping

### Octave 2 (C2-B2): A-L

  | Note | MIDI | Letter | Morse Code |
  |------|------|--------|------------|
  | C2   | 48   | A      | .-         |
  | C#2  | 49   | B      | -...       |
  | D2   | 50   | C      | -.-.       |
  | D#2  | 51   | D      | -..        |
  | E2   | 52   | E      | .          |
  | F2   | 53   | F      | ..-.       |
  | F#2  | 54   | G      | --.        |
  | G2   | 55   | H      | ....       |
  | G#2  | 56   | I      | ..         |
  | A2   | 57   | J      | .---       |
  | A#2  | 58   | K      | -.-        |
  | B2   | 59   | L      | .-..       |

### Octave 3 (C3-B3): M-X

  | Note | MIDI | Letter | Morse Code |
  |------|------|--------|------------|
  | C3   | 60   | M      | --         |
  | C#3  | 61   | N      | -.         |
  | D3   | 62   | O      | ---        |
  | D#3  | 63   | P      | .--.       |
  | E3   | 64   | Q      | --.-       |
  | F3   | 65   | R      | .-.        |
  | F#3  | 66   | S      | ...        |
  | G3   | 67   | T      | -          |
  | G#3  | 68   | U      | ..-        |
  | A3   | 69   | V      | ...-       |
  | A#3  | 70   | W      | .--        |
  | B3   | 71   | X      | -..-       |

### Octave 4 (C4-C#4): Y-Z

  | Note | MIDI | Letter | Morse Code |
  |------|------|--------|------------|
  | C4   | 72   | Y      | -.--       |
  | C#4  | 73   | Z      | --..       |


## Examples

  - `SOS`: F#3, D3, F#3
  - `EMERGENCY`: E2, C3, E2, F3, G2, E2, C3, C2, G#2
