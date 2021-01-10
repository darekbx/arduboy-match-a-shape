// Settings screen

#define settingsItems 4
byte settingsSelection = 0;

void settingsScreen_loop() {
  handleSettingsButtons();
  
  drawCenterText("Audio On", 7, settingsSelection == 0);
  drawCenterText("Reset game", 21, settingsSelection == 1);
  drawCenterText("Credits", 35, settingsSelection == 2);
  drawCenterText("Back", 49, settingsSelection == 3);
}

void confirmSettingsSelection() {
  switch (settingsSelection) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      currentScreen = menu_screen;
      break;
  }
  settingsSelection = 0;
}

void handleSettingsButtons() {

  // B is a select button
  if (arduboy.justPressed(B_BUTTON)) {
    confirmSettingsSelection();
  }
  
  // Selection movement
  if (arduboy.justPressed(UP_BUTTON) && settingsSelection > 0) {
    settingsSelection = settingsSelection - 1;
  }
  if (arduboy.justPressed(DOWN_BUTTON) && settingsSelection < settingsItems - 1) {
    settingsSelection = settingsSelection + 1;
  }
}
