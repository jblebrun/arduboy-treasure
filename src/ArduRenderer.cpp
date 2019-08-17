#include "ArduRenderer.h"

Sprites sprites;

const int song1[] = {220, 880, 330, 1220, 440, 330, 0};
const int song2[] = {220, 330, 440, 660, 880, 1320, 1660, 2640, 0};

const int *songs[] = {0, song1, song2};

ArduRenderer::ArduRenderer(Arduboy2 &_boy) : boy(_boy) {}

void ArduRenderer::Init() {
  boy.begin();
  boy.setFrameRate(60);
  b1.begin();
  b2.begin();
  boy.print("HELLO?");
  boy.display();
}

void ArduRenderer::DrawBitmap(uint16_t x, uint16_t y, const uint8_t *sprite) {
  sprites.drawOverwrite(x, y, sprite, 0);
}

void ArduRenderer::Tick() {
  b1.timer();
  b2.timer();

  if (playSong > 0 && noteCounter <= 0) {
    noteCounter = songSpeed;
    b1.tone(b1.freq(songs[playSong][note]), 2);
    note++;
    if (songs[playSong][note] == 0) {
      if (songLoop) {
        note = 0;
      } else {
        playSong = 0;
      }
    }
  }
  noteCounter--;
}

void ArduRenderer::Print(const char *msg) {
  boy.setCursor(0, 0);
  boy.print(msg);
}

void ArduRenderer::Sound(int f1, int f2, int dur) {
  b1.tone(b1.freq(f1), dur);
  b2.tone(b2.freq(f2), dur);
}
void ArduRenderer::Clear() { boy.clear(); }
void ArduRenderer::Display() { boy.display(); }

bool ArduRenderer::NextFrame() { return boy.nextFrame(); }

void ArduRenderer::PlaySong(int song, int speed, bool loop) {
  playSong = song;
  songSpeed = speed;
  note = 0;
  songLoop = loop;
}
