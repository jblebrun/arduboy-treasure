#pragma once
#include "Arduboy2.h"
#include "Arduino.h"
#include "Game.h"

class ArduRenderer : public Renderer {
  Arduboy2 &boy;
  BeepPin1 b1;
  BeepPin2 b2;

  int playSong;
  bool songLoop;
  int note = 0;
  int noteCounter = 0;
  int songSpeed = 0;

public:
  ArduRenderer(Arduboy2 &boy);
  virtual void DrawBitmap(uint16_t, uint16_t, const uint8_t *);
  virtual void Sound(int, int, int);
  virtual void Print(const char *);
  virtual void Clear();
  virtual void Display();
  virtual void Tick();
  virtual bool NextFrame();
  virtual void Init();
  virtual void PlaySong(int song, int speed, bool loop);
};
