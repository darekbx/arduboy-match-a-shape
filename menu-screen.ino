// Menu screen

// TODO:
// Menu positions:
// 1. Start
//    a. level select like in original game carousel, selected level is zoomed with starts and moves, level index
// 2. How to play
// 3. Settings
//    a. audio on/off
//    b. reset game progress
//    c. credits - dialog

#define menuItems 3
byte menuSelection = 0;

void menuScreen_loop() {
  handleMenuButtons();
  
  drawCenterText("Start", 14, menuSelection == 0);
  drawCenterText("How to play", 28, menuSelection == 1);
  drawCenterText("Settings", 42, menuSelection == 2);
}

void confirmMenuSelection() {
  switch (menuSelection) {
    case 0:
      prepareLevel(2);
      // TODO should be: level_select_screen
      currentScreen = game_screen;
      break;
    case 1:
      currentScreen = how_to_play_screen;
      break;
    case 2:
      currentScreen = settings_screen;
      break;
  }
  menuSelection = 0;
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
  if (arduboy.justPressed(DOWN_BUTTON) && menuSelection < menuItems - 1) {
    menuSelection = menuSelection + 1;
  }
}
