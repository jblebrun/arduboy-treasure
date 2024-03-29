
#include "src/ArduRenderer.h"

Arduboy2 boy;
ArduRenderer rend(boy);
Game game(rend);

void setup() { rend.Init();
      rend.PlaySong(1, 10, true);
      Serial.begin(115200);
}

void loop() {

  if (!rend.NextFrame()) {
    return;
  }

  rend.Tick();

  boy.pollButtons();

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
  if (boy.justPressed(B_BUTTON)) {
    game.B();
  }

  game.Render();
}
