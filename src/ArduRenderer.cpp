#include "ArduRenderer.h"

Sprites sprites;

ArduRenderer::ArduRenderer(Arduboy2& _boy)
  : boy(_boy)
{}

void
ArduRenderer::Init()
{
  boy.begin();
  boy.setFrameRate(120);
  b1.begin();
  b2.begin();
  boy.print("HELLO?");
  boy.display();
}

void
ArduRenderer::DrawBitmap(uint16_t x,
                         uint16_t y,
                         const uint8_t* sprite,
                         uint8_t w,
                         uint8_t h,
                         bool clear = false)
{
  sprites.drawOverwrite(x, y, sprite, 0);
}

void
ArduRenderer::Tick()
{
  b1.timer();
  b2.timer();
}

void
ArduRenderer::Print(const char* msg)
{
  boy.setCursor(0, 0);
  boy.print(msg);
}

void
ArduRenderer::Sound(int f1, int f2, int dur)
{
  b1.tone(b1.freq(f1), dur);
  b2.tone(b2.freq(f2), dur);
}
void
ArduRenderer::Clear()
{
  boy.clear();
}
void
ArduRenderer::Display()
{
  boy.display();
}

bool
ArduRenderer::NextFrame()
{
  return boy.nextFrame();
}
