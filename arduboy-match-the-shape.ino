#include <Arduboy2.h>
#include "game-assets.h"

#define SERIAL_ENABLED false
#define ALL_LEVELS_UNLOCKED false

Arduboy2 arduboy;
BeepPin1 beep;

/*
 * TODO:
 *  - add boot logo
 *  - add background animated logo for menu screen
 *  - beep on rotate
 */

enum matchTheShapeScreen {
  menu_screen,
  game_screen,
  level_select_screen,
  how_to_play_screen,
  settings_screen
};

matchTheShapeScreen currentScreen = menu_screen;

void setup() {
  #if SERIAL_ENABLED
    Serial.begin(9600);
    while (!Serial) { }
    Serial.println("Serial Ready");
    #endif

  arduboy.boot();
  arduboy.display();
  arduboy.flashlight();
  arduboy.waitNoButtons();
  arduboy.setFrameDuration(50);
  
  arduboy.audio.on();
  beep.begin();
}

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }
  
  arduboy.clear();
  arduboy.pollButtons();

  switch (currentScreen) {
    case menu_screen:
      menuScreen_loop();
      break;
    case game_screen:
      gameScreen_loop();
      break;
    case level_select_screen:
      levelSelectScreen_loop();
      break;
    case how_to_play_screen:
      howToPlayScreen_loop();
      break;
    case settings_screen:
      settingsScreen_loop();
      break;
  }
  
  arduboy.display();
}

void drawCenterText(String text, int yPosition, boolean isSelected) {
  const byte CHAR_WIDTH = 6;
  const byte CHAR_HEIGHT = 8;
  
  byte textWidth = text.length() * CHAR_WIDTH - 1;
  byte x = (WIDTH - textWidth) / 2;
  arduboy.setCursor(x, yPosition);
  arduboy.print(text);
  
  if (isSelected) {
    byte selectionOffset = 4;
    arduboy.drawRoundRect(
      x - selectionOffset, 
      yPosition - selectionOffset, 
      textWidth + selectionOffset * 2, 
      CHAR_HEIGHT + selectionOffset * 2, 
      4); 
  }
}
