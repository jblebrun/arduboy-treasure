#pragma once

#include <Arduboy2.h>
#include <Arduino.h>

class Renderer {
public:
  virtual void DrawBitmap(uint16_t, uint16_t, const uint8_t *) = 0;
  virtual void Sound(int, int, int) = 0;
  virtual void Print(const char *) = 0;
  virtual void Clear() = 0;
  virtual void Display() = 0;
  virtual void Tick() = 0;
  virtual bool NextFrame() = 0;
  virtual void PlaySong(int song, int speed, bool loop=false) = 0;
};

struct offset {
  uint8_t x;
  uint8_t y;
};

class Game {

  const uint8_t PY_MAX = HEIGHT - 8 * 4;
  const uint8_t PY_MIN = 8 * 3;
  const uint8_t PX_MAX = WIDTH - 8 * 4;
  const uint8_t PX_MIN = 8 * 3;
  ;

  uint8_t state = TITLE;

  offset mo = (offset){
      .x = 0,
      .y = 0,
  };
 offset po = (offset){
      .x = 64 - 4,
      .y = 32 - 4,
  };
  offset eo = (offset){
      .x = 24 - 4,
      .y = 12 - 4,
  };

  int stepCounter = 0;
  int level = 0;

  Renderer &renderer;
  void check(offset next);
  void drawPlayer();
  void drawMap();
  void drawEnemy();
  uint8_t tileAt(uint16_t x, uint16_t y);
  bool checkCollisions(uint8_t target);

public:
  Game(Renderer &renderer);

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
