#include "Game.h"

const uint8_t sprites[][10] PROGMEM = { {
                                          0x8,
                                          0x8,
                                          0x3C,
                                          0x42,
                                          0x81,
                                          0x81,
                                          0x81,
                                          0x81,
                                          0x42,
                                          0x3C,
                                        },
                                        {
                                          8,
                                          8,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x18,
                                          0x18,
                                          0x0,
                                          0x0,
                                          0x0,
                                        },
                                        {
                                          8,
                                          8,
                                          0xFF,
                                          0x81,
                                          0x81,
                                          0xBD,
                                          0xBD,
                                          0x81,
                                          0x81,
                                          0xFF,
                                        },
                                        {
                                          8,
                                          8,
                                          0x7E,
                                          0x81,
                                          0x95,
                                          0xA1,
                                          0xA1,
                                          0x95,
                                          0x81,
                                          0x7E,
                                        },
                                        {
                                          8,
                                          8,
                                          0x18,
                                          0x3C,
                                          0x7E,
                                          0xFF,
                                          0xFF,
                                          0x7E,
                                          0x3C,
                                          0x18,
                                        } };

const uint8_t MAP_W = 32;
const uint8_t MAP_H = 16;
const uint8_t m[MAP_H][MAP_W] PROGMEM = {
  { 2, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 2, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 2, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 2, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 4, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 2, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 2, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 2, 0, 1 },
};

Game::Game(Renderer& r)
  : renderer(r)
{}

uint8_t
Game::tileAt(uint16_t x, uint16_t y)
{
  // Return the tile correspond to the upper-left part of player
  uint8_t tx = ((x + mo.x) >> 3) % MAP_W;
  uint8_t ty = ((y + mo.y) >> 3) % MAP_H;
  return pgm_read_byte(&m[ty][tx]);
}

bool
Game::checkCollisions(uint8_t target)
{
  return (tileAt(po.x, po.y) == target) || (tileAt(po.x, po.y + 8) == target) ||
         (tileAt(po.x + 8, po.y) == target) ||
         (tileAt(po.x + 8, po.y + 8) == target);
}

void
Game::Up()
{
  if (state != PLAY) {
    return;
  }
  if (po.y <= PY_MIN) {
    mo.y--;
  } else {
    po.y--;
  }
  check();
}

void
Game::Down()
{
  if (state != PLAY) {
    return;
  }
  if (po.y >= PY_MAX) {
    mo.y++;
  } else {
    po.y++;
  }
  check();
}

void
Game::Left()
{
  if (state != PLAY) {
    return;
  }
  if (po.x <= PX_MIN) {
    mo.x--;
  } else {
    po.x--;
  }
  check();
}

void
Game::Right()
{
  if (state != PLAY) {
    return;
  }
  if (po.x >= PX_MAX) {
    mo.x++;
  } else {
    po.x++;
  }
  check();
}

void
Game::B()
{
  state = PLAY;
  mo = (struct offset){};
  po = (struct offset){ .x = 64 - 4, .y = 32 - 4 };
}

void
Game::check()
{
  if (stepCounter == 0) {
    renderer.Sound(55, 75, 1);
    stepCounter = 4;
  }
  stepCounter--;

  if (checkCollisions(2)) {
    renderer.Sound(110, 130, 15);
    state = DEAD;
  } else if (checkCollisions(4)) {
    renderer.Sound(440, 680, 15);
    state = WIN;
  }
}

void
Game::drawPlayer()
{
  renderer.DrawBitmap(po.x, po.y, sprites[3], 8, 8, true);
}

void
Game::drawMap()
{
  int16_t txs = mo.x >> 3;
  int16_t tys = mo.y >> 3;
  uint8_t pox = mo.x & 0x7;
  uint8_t poy = mo.y & 0x7;

  for (int16_t iy = 0; iy < 10; iy++) {
    for (int16_t ix = 0; ix < 18; ix++) {
      int16_t tx = (txs + ix) % MAP_W;
      int16_t ty = (tys + iy) % MAP_H;
      uint8_t s = pgm_read_byte(&m[ty][tx]);
      renderer.DrawBitmap(ix * 8 - pox, iy * 8 - poy, sprites[s], 8, 8);
    }
  }
}

void
Game::Render()
{
  renderer.Clear();
  switch (state) {
    case TITLE:
      renderer.Print("FIND THE TREASURE");
      break;
    case DEAD:
      renderer.Print("YOU DIED");
      break;
    case WIN:
      renderer.Print("YOU DID IT!");
      break;
    default:
      drawMap();
      drawPlayer();
  }
  renderer.Display();
}
