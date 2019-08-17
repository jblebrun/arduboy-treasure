#include "ArduRenderer.h"

Arduboy2 boy;
ArduRenderer rend(boy);
Game game(rend);

void setup()
{  
  rend.Init();
}

void
loop()
{

  if (!rend.NextFrame()) {
    return;
  }

  rend.Tick();

  if (boy.pressed(UP_BUTTON)) {
    game.Up();
  }
  if (boy.pressed(DOWN_BUTTON)) {
    game.Down();
  }
  if (boy.pressed(LEFT_BUTTON)) {
    game.Left();
  }
  if (boy.pressed(RIGHT_BUTTON)) {
    game.Right();
  }
  if (boy.pressed(B_BUTTON)) {
    game.B();
  }

  game.Render();
  
  
}