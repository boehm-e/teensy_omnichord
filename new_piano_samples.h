#pragma once
#include <Audio.h>

extern const AudioSynthWavetable::sample_data new_piano_samples[1];
const uint8_t new_piano_ranges[] = {127, };

const AudioSynthWavetable::instrument_data new_piano = {1, new_piano_ranges, new_piano_samples };


extern const uint32_t sample_0_new_piano_PDSinewave_C1[33152];
