// GUITOOLS generated code
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


// GUItool: begin automatically generated code
AudioSynthWavetable      wavetable4;     //xy=275,1149.25
AudioSynthWavetable      wavetable;      //xy=276,961.25
AudioSynthWavetable      wavetable7;     //xy=277,1245.25
AudioSynthWavetable      wavetable8;     //xy=277,1304.25
AudioSynthWavetable      wavetable3;     //xy=278,1057.25
AudioSynthWavetable      wavetable5;     //xy=278,1181.25
AudioSynthWavetable      wavetable6;     //xy=278,1213.25
AudioSynthWavetable      wavetable1;     //xy=279,993.25
AudioSynthWavetable      wavetable2;     //xy=279,1025.25
AudioSynthWavetable      wavetable12;    //xy=278,1469.25
AudioSynthWavetable      wavetable11;    //xy=279,1400.25
AudioSynthWavetable      wavetable9;     //xy=280,1336.25
AudioSynthWavetable      wavetable10;    //xy=280,1368.25
AudioSynthWaveformModulated waveform3;      //xy=284,397
AudioSynthWaveformModulated waveform4;      //xy=284,450
AudioSynthWaveformModulated waveform8; //xy=283,714
AudioSynthWavetable      wavetable20;    //xy=279,1793.25
AudioSynthWavetable      wavetable15;    //xy=280,1565.25
AudioSynthWavetable      wavetable16;    //xy=280,1635.25
AudioSynthWaveformModulated waveform7;      //xy=284,656
AudioSynthWavetable      wavetable13;    //xy=281,1501.25
AudioSynthWavetable      wavetable14;    //xy=281,1533.25
AudioSynthWaveformModulated waveform1;      //xy=286,289
AudioSynthWaveformModulated waveform2;      //xy=286,343
AudioSynthWaveformModulated waveform5;      //xy=286,548
AudioSynthWaveformModulated waveform9; //xy=285,810
AudioSynthWaveformModulated waveform6;      //xy=286,602
AudioSynthWavetable      wavetable23;    //xy=281,1889.25
AudioSynthWavetable      wavetable19;    //xy=282,1731.25
AudioSynthWavetable      wavetable21;    //xy=282,1825.25
AudioSynthWavetable      wavetable22;    //xy=282,1857.25
AudioSynthWavetable      wavetable17;    //xy=283,1667.25
AudioSynthWavetable      wavetable18;    //xy=283,1699.25
AudioEffectEnvelope      envelope3;      //xy=456,396
AudioEffectEnvelope      envelope4;      //xy=456,449
AudioEffectEnvelope      envelope8; //xy=455,713
AudioEffectEnvelope      envelope7;      //xy=456,655
AudioEffectEnvelope      envelope1;      //xy=458,288
AudioEffectEnvelope      envelope2;      //xy=458,342
AudioEffectEnvelope      envelope5;      //xy=458,547
AudioEffectEnvelope      envelope9; //xy=457,809
AudioEffectEnvelope      envelope6;      //xy=458,601
AudioMixer4              mixer4; //xy=491,1197.25
AudioMixer4              mixer;          //xy=492,1009.25
AudioMixer4              mixer5; //xy=493,1352.25
AudioMixer4              mixer6;         //xy=494,1517.25
AudioMixer4              mixer7;         //xy=495,1841.25
AudioMixer4              mixer8;         //xy=496,1683.25
AudioEffectFade          fade3;          //xy=644,396
AudioEffectFade          fade4;          //xy=644,449
AudioEffectFade          fade8; //xy=643,713
AudioEffectFade          fade7;          //xy=644,655
AudioEffectFade          fade1;          //xy=646,288
AudioEffectFade          fade2;          //xy=646,342
AudioEffectFade          fade5;          //xy=646,547
AudioEffectFade          fade9; //xy=645,809
AudioEffectFade          fade6;          //xy=646,601
AudioMixer4              mixer_sub_2;    //xy=758,1535.25
AudioMixer4              mixer_sub_1;    //xy=759,1348.25
AudioMixer4              mixer3; //xy=837,829
AudioMixer4              mixer1;         //xy=842,368
AudioMixer4              mixer2;         //xy=842,607
AudioMixer4              mixer_main_strum; //xy=1081.250015258789,1441.750020980835
AudioMixer4              mixer_main_chords;     //xy=1095.000015258789,615.2500076293945
AudioMixer4              mixer_main; //xy=1300,977.5
AudioOutputAnalogStereo  dac;            //xy=1550.7500228881836,974.0000133514404
AudioConnection          patchCord1(wavetable4, 0, mixer4, 0);
AudioConnection          patchCord2(wavetable, 0, mixer, 0);
AudioConnection          patchCord3(wavetable7, 0, mixer4, 3);
AudioConnection          patchCord4(wavetable8, 0, mixer5, 0);
AudioConnection          patchCord5(wavetable3, 0, mixer, 3);
AudioConnection          patchCord6(wavetable5, 0, mixer4, 1);
AudioConnection          patchCord7(wavetable6, 0, mixer4, 2);
AudioConnection          patchCord8(wavetable1, 0, mixer, 1);
AudioConnection          patchCord9(wavetable2, 0, mixer, 2);
AudioConnection          patchCord10(wavetable12, 0, mixer6, 0);
AudioConnection          patchCord11(wavetable11, 0, mixer5, 3);
AudioConnection          patchCord12(wavetable9, 0, mixer5, 1);
AudioConnection          patchCord13(wavetable10, 0, mixer5, 2);
AudioConnection          patchCord14(waveform3, envelope3);
AudioConnection          patchCord15(waveform4, envelope4);
AudioConnection          patchCord16(waveform8, envelope8);
AudioConnection          patchCord17(wavetable20, 0, mixer7, 0);
AudioConnection          patchCord18(wavetable15, 0, mixer6, 3);
AudioConnection          patchCord19(wavetable16, 0, mixer8, 0);
AudioConnection          patchCord20(waveform7, envelope7);
AudioConnection          patchCord21(wavetable13, 0, mixer6, 1);
AudioConnection          patchCord22(wavetable14, 0, mixer6, 2);
AudioConnection          patchCord23(waveform1, envelope1);
AudioConnection          patchCord24(waveform2, envelope2);
AudioConnection          patchCord25(waveform5, envelope5);
AudioConnection          patchCord26(waveform9, envelope9);
AudioConnection          patchCord27(waveform6, envelope6);
AudioConnection          patchCord28(wavetable23, 0, mixer7, 3);
AudioConnection          patchCord29(wavetable19, 0, mixer8, 3);
AudioConnection          patchCord30(wavetable21, 0, mixer7, 1);
AudioConnection          patchCord31(wavetable22, 0, mixer7, 2);
AudioConnection          patchCord32(wavetable17, 0, mixer8, 1);
AudioConnection          patchCord33(wavetable18, 0, mixer8, 2);
AudioConnection          patchCord34(envelope3, fade3);
AudioConnection          patchCord35(envelope4, fade4);
AudioConnection          patchCord36(envelope8, fade8);
AudioConnection          patchCord37(envelope7, fade7);
AudioConnection          patchCord38(envelope1, fade1);
AudioConnection          patchCord39(envelope2, fade2);
AudioConnection          patchCord40(envelope5, fade5);
AudioConnection          patchCord41(envelope9, fade9);
AudioConnection          patchCord42(envelope6, fade6);
AudioConnection          patchCord43(mixer4, 0, mixer_sub_1, 1);
AudioConnection          patchCord44(mixer, 0, mixer_sub_1, 0);
AudioConnection          patchCord45(mixer5, 0, mixer_sub_1, 2);
AudioConnection          patchCord46(mixer6, 0, mixer_sub_2, 0);
AudioConnection          patchCord47(mixer7, 0, mixer_sub_2, 2);
AudioConnection          patchCord48(mixer8, 0, mixer_sub_2, 1);
AudioConnection          patchCord49(fade3, 0, mixer1, 2);
AudioConnection          patchCord50(fade4, 0, mixer1, 3);
AudioConnection          patchCord51(fade8, 0, mixer2, 3);
AudioConnection          patchCord52(fade7, 0, mixer2, 2);
AudioConnection          patchCord53(fade1, 0, mixer1, 0);
AudioConnection          patchCord54(fade2, 0, mixer1, 1);
AudioConnection          patchCord55(fade5, 0, mixer2, 0);
AudioConnection          patchCord56(fade9, 0, mixer3, 0);
AudioConnection          patchCord57(fade6, 0, mixer2, 1);
AudioConnection          patchCord58(mixer_sub_2, 0, mixer_main_strum, 1);
AudioConnection          patchCord59(mixer_sub_1, 0, mixer_main_strum, 0);
AudioConnection          patchCord60(mixer3, 0, mixer_main_chords, 2);
AudioConnection          patchCord61(mixer1, 0, mixer_main_chords, 0);
AudioConnection          patchCord62(mixer2, 0, mixer_main_chords, 1);
AudioConnection          patchCord63(mixer_main_strum, 0, mixer_main, 1);
AudioConnection          patchCord64(mixer_main_chords, 0, mixer_main, 0);
AudioConnection          patchCord65(mixer_main, 0, dac, 0);
AudioConnection          patchCord66(mixer_main, 0, dac, 1);
// GUItool: end automatically generated code
