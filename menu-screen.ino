
#define MENU_ITEMS_COUNT 3
#define MENU_TOP_POSITION 24

byte menuSelection = 0;
bool leftMenu = false; 

void menuScreen_loop() {
  if (leftMenu) {
    menuSelection = 0;
    leftMenu = false;
  }
  
  handleMenuButtons();
  
  drawCenterText("Start", MENU_TOP_POSITION, menuSelection == 0);
  drawCenterText("How to play", MENU_TOP_POSITION + 12, menuSelection == 1);
  drawCenterText("Settings", MENU_TOP_POSITION + 12 * 2, menuSelection == 2);

  arduboy.fillRect(0, 16, 128, 2);
  arduboy.drawRect(0, 0, 128, 64);
  arduboy.drawRect(1, 1, 126, 62);
  
  arduboy.drawBitmap(0, 2, gameLogo, 128, 14);
}

void confirmMenuSelection() {
  switch (menuSelection) {
    case 0:
      switchToSelectLevelScreen();
      break;
    case 1:
      switchToHowToPlayScreen();
      break;
    case 2:
      switchToSettingsScreen();
      break;
  }
  leftMenu = true;
}

void handleMenuButtons() {

  // B is a select button
  if (arduboy.justPressed(B_BUTTON)) {
    confirmMenuSelection();
  }
  
  // Selection movement
  if (arduboy.justPressed(UP_BUTTON) && menuSelection > 0) {
    menuSelection = menuSelection - 1;
  }
  if (arduboy.justPressed(DOWN_BUTTON) && menuSelection < MENU_ITEMS_COUNT - 1) {
    menuSelection = menuSelection + 1;
  }
}
