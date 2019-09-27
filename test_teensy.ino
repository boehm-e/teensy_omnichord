// includes
#include <Bounce.h>
#include "Adafruit_MPR121.h"
#include "new_piano_samples.h"
#include "guitools.h"
#include "note.h"

// first capacitive "slider"
Adafruit_MPR121 cap1 = Adafruit_MPR121();
Adafruit_MPR121 cap2 = Adafruit_MPR121();

// MPR121
// Keeps track of the last pins touched 
// so we know when buttons are 'released'
uint16_t lasttouched1 = 0;
uint16_t currtouched1 = 0;
uint16_t lasttouched2 = 0;
uint16_t currtouched2 = 0;
AudioSynthWavetable* strum_wavetables[24] = {&wavetable, &wavetable1, &wavetable2, &wavetable3, &wavetable4, &wavetable5, &wavetable6, &wavetable7, &wavetable8, &wavetable9, &wavetable10, &wavetable11, &wavetable12, &wavetable13, &wavetable14, &wavetable15, &wavetable16, &wavetable17, &wavetable18, &wavetable19, &wavetable20, &wavetable21, &wavetable22, &wavetable23};
AudioMixer4* mixers_strum_first[6] = {&mixer, &mixer1, &mixer2, &mixer3, &mixer4, &mixer5};


// create 3x9 notes
Note notes[27];


void setup(void)
{

  // Set up
  AudioMemory(250);

  // setup capacitive
  if (!cap1.begin(0x5D)) {
    Serial.println("MPR121 1 not found, check wiring?");
    while (1);
  }
  // setup capacitive
  if (!cap2.begin(0x5A)) {
    Serial.println("MPR121 2 not found, check wiring?");
    while (1);
  }

  // setup mixers for Notes Chords
  float gain = 1.0;
  mixer1.gain(0, gain);
  mixer1.gain(1, gain);
  mixer1.gain(2, gain);
  mixer1.gain(3, gain);
  mixer2.gain(0, gain);
  mixer2.gain(1, gain);
  mixer2.gain(2, gain);
  mixer2.gain(3, gain);
  mixer3.gain(0, gain);

  // setup mixers for strum
  for (int i=0; i<6; i++) {
    mixers_strum_first[i]->gain(0, 1.0);
    mixers_strum_first[i]->gain(1, 1.0);
    mixers_strum_first[i]->gain(2, 1.0);
    mixers_strum_first[i]->gain(3, 1.0);
  }
  mixer_sub_1.gain(0, 1.0);
  mixer_sub_1.gain(1, 1.0);
  mixer_sub_1.gain(2, 1.0);
  mixer_sub_2.gain(0, 1.0);
  mixer_sub_2.gain(1, 1.0);
  mixer_sub_2.gain(2, 1.0);
  mixer_main_strum.gain(0, 1.0);
  mixer_main_strum.gain(1, 1.0);

  // setup instrument for strum wavetable
  for (int i=0; i<24; i++) {
    strum_wavetables[i]->setInstrument(new_piano);
    strum_wavetables[i]->amplitude(1.0);
  }

  // setup main mixer
  mixer_main.gain(0, 0.2);// reduce sound from notes (chords)
  mixer_main.gain(1, 2.0);

  // setup notes
  // Major
  notes[0] = createNote("C", 24, &waveform3, &envelope3, &fade3, 262, 262, 0, 0.0, 500, 500, 250);
  notes[1] = createNote("D", 25, &waveform4, &envelope4, &fade4, 294, 294, 0, 0.0, 500, 500, 250);
  notes[2] = createNote("E", 26, &waveform5, &envelope5, &fade5, 330, 330, 0, 0.0, 500, 500, 250);
  notes[3] = createNote("F", 27, &waveform6, &envelope6, &fade6, 349, 349, 0, 0.0, 500, 500, 250);
  notes[4] = createNote("G", 28, &waveform7, &envelope7, &fade7, 392, 392, 0, 0.0, 500, 500, 250);
  notes[5] = createNote("A", 29, &waveform1, &envelope1, &fade1, 440, 440, 0, 0.0,500, 500, 250);
  notes[6] = createNote("B", 30, &waveform2, &envelope2, &fade2, 496, 496, 0, 0.0, 500, 500, 250);
  notes[7] = createNote("-", 31, &waveform8, &envelope8, &fade8, 523, 523, 0, 0.0, 500, 500, 250);
  notes[8] = createNote("-", 32, &waveform9, &envelope9, &fade9, 554, 554, 0, 0.0, 500, 500, 250);
  // Minor
  notes[9]  = createNote("1", 4, &waveform3, &envelope3, &fade3, 262, 262, 0, 0.0, 500, 500, 250);
  notes[10] = createNote("2", 5, &waveform4, &envelope4, &fade4, 294, 294, 0, 0.0, 500, 500, 250);
  notes[11] = createNote("3", 6, &waveform5, &envelope5, &fade5, 330, 330, 0, 0.0, 500, 500, 250);
  notes[12] = createNote("4", 7, &waveform6, &envelope6, &fade6, 349, 349, 0, 0.0, 500, 500, 250);
  notes[13] = createNote("5", 8, &waveform7, &envelope7, &fade7, 392, 392, 0, 0.0, 500, 500, 250);
  notes[14] = createNote("6", 9, &waveform1, &envelope1, &fade1, 440, 440, 0, 0.0,500, 500, 250);
  notes[15] = createNote("7", 10, &waveform2, &envelope2, &fade2, 496, 496, 0, 0.0, 500, 500, 250);
  notes[16] = createNote("8", 11, &waveform8, &envelope8, &fade8, 523, 523, 0, 0.0, 500, 500, 250);
  notes[17] = createNote("9", 12, &waveform9, &envelope9, &fade9, 554, 554, 0, 0.0, 500, 500, 250);
  // 7th
  notes[18] = createNote("a1", 37, &waveform3, &envelope3, &fade3, 262, 262, 0, 0.0, 500, 500, 250);
  notes[19] = createNote("a2", 36, &waveform4, &envelope4, &fade4, 294, 294, 0, 0.0, 500, 500, 250);
  notes[20] = createNote("a3", 35, &waveform5, &envelope5, &fade5, 330, 330, 0, 0.0, 500, 500, 250);
  notes[21] = createNote("a4", 34, &waveform6, &envelope6, &fade6, 349, 349, 0, 0.0, 500, 500, 250);
  notes[22] = createNote("a5", 33, &waveform7, &envelope7, &fade7, 392, 392, 0, 0.0, 500, 500, 250);
  notes[23] = createNote("a6", 0, &waveform1, &envelope1, &fade1, 440, 440, 0, 0.0,500, 500, 250);
  notes[24] = createNote("a7", 1, &waveform2, &envelope2, &fade2, 496, 496, 0, 0.0, 500, 500, 250);
  notes[25] = createNote("a8", 2, &waveform8, &envelope8, &fade8, 523, 523, 0, 0.0, 500, 500, 250);
  notes[26] = createNote("a9", 3, &waveform9, &envelope9, &fade9, 554, 554, 0, 0.0, 500, 500, 250);
}

float map(float s, float a1, float a2, float b1, float b2)
{
    return b1 + (s-a1)*(b2-b1)/(a2-a1);
}

float last_frequency_note = 0.0;
void loop() {

  // for each buttons, check if it is touched
  for (int i=0; i<27; i++) {
    Note note = notes[i];
    if (note.button->update()) {
      if (note.button->fallingEdge()) {
        Serial.println(note.name);
        note.envelope->noteOn();
        last_frequency_note = note.frequency;
      }
      if (note.button->risingEdge()) {
        note.envelope->noteOff();
      }
    }
  }

//  Serial.println(last_frequency_note);


  // STRUMMING
  // Get the currently touched pads 1
  currtouched1 = cap1.touched();
  for (uint8_t i=0; i<12; i++) {
    if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
//      strum_wavetables[i]->playFrequency(map(i, 0, 23, last_frequency_note*0.5, last_frequency_note*3));
      strum_wavetables[i]->playNote(10+i+int(last_frequency_note/10.0));
    }
    if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
      //Serial.print(i); Serial.println(" released");
    }
  }
  lasttouched1 = currtouched1;

  // Get the currently touched pads 2
  currtouched2 = cap2.touched();
  for (uint8_t i=0; i<12; i++) {
    if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
      Serial.print(i+12); Serial.println(" touched");
//      strum_wavetables[i]->playFrequency(map(i+12, 0, 23, last_frequency_note*0.5, last_frequency_note*3));
      strum_wavetables[i+12]->playNote(10+(i+12)+int(last_frequency_note/10.0));
    }
    if (!(currtouched2 & _BV(i)) && (lasttouched2 & _BV(i)) ) {
      //Serial.print(i+12); Serial.println(" released");
    }
  }
  lasttouched2 = currtouched2;


  delay(20);

}
