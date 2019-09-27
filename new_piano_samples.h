#pragma once
#include <Audio.h>

extern const AudioSynthWavetable::sample_data new_piano_samples[2];
const uint8_t new_piano_ranges[] = {119, 127, };

const AudioSynthWavetable::instrument_data new_piano = {2, new_piano_ranges, new_piano_samples };


extern const uint32_t sample_0_new_piano_femalevoiceg2[4480];

extern const uint32_t sample_1_new_piano_kpianob5[2816];
