#pragma once

#include <Arduboy2.h>
#include <Arduino.h>

class Renderer
{
public:
  virtual void DrawBitmap(uint16_t,
                          uint16_t,
                          const uint8_t*,
                          uint8_t,
                          uint8_t,
                          bool clear = false) = 0;
  virtual void Sound(int, int, int) = 0;
  virtual void Print(const char*) = 0;
  virtual void Clear() = 0;
  virtual void Display() = 0;
  virtual void Tick() = 0;
  virtual bool NextFrame() = 0;
};

struct offset
{
  uint8_t x;
  uint8_t y;
};

class Game
{

  const uint8_t PY_MAX = 44;
  const uint8_t PY_MIN = 10;
  const uint8_t PX_MAX = 100;
  const uint8_t PX_MIN = 20;

  uint8_t state = TITLE;

  struct offset mo = (struct offset){
    .x = 0,
    .y = 0,
  };
  struct offset po = (struct offset){
    .x = 64 - 4,
    .y = 32 - 4,
  };

  int stepCounter = 0;
  Renderer& renderer;
  void check();
  void drawPlayer();
  void drawMap();
  uint8_t tileAt(uint16_t x, uint16_t y);
  bool checkCollisions(uint8_t target);

public:
  Game(Renderer& renderer);

  static const uint8_t TITLE = 1;
  static const uint8_t DEAD = 2;
  static const uint8_t PLAY = 3;
  static const uint8_t WIN = 4;

  void Up();
  void Down();
  void Left();
  void Right();
  void B();
  void Render();
};
