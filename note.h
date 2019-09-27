// create a structure for each note

typedef struct{
    String name;
    AudioSynthWaveformModulated *waveform;
    AudioEffectEnvelope *envelope;
    AudioEffectFade *fade;
    Bounce *button;
    float frequency;
    int buttonPin;
} Note;

Note createNote(String name, int buttonPin, AudioSynthWaveformModulated *waveform, AudioEffectEnvelope *envelope, AudioEffectFade *fade, int from, int to, int attack, float sustain, int decay, int release, int fadeIn) {
  Bounce *_button = new Bounce(buttonPin, 10);
  pinMode(buttonPin, INPUT_PULLUP);
  waveform->begin(from, to, WAVEFORM_SQUARE);
  waveform->amplitude(1.0);
//  envelope->attack(attack);
//  envelope->sustain(sustain);
//  envelope->decay(decay);
  envelope->release(release);
  fade->fadeIn(fadeIn);
  
  Note note = {name, waveform, envelope, fade, _button, from, buttonPin};
  return note;
}
