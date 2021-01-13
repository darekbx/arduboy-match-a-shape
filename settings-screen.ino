// Settings screen

#define settingsItems 4
byte settingsSelection = 0;
bool leftSettings = false;
boolean isResetMemoryDialogShown = false;
boolean isResetDoneDialogShown = false;
boolean resetSkipFrame = false;

void settingsScreen_loop() {
  if (leftSettings) {
    settingsSelection = 0;
    leftSettings = false;
  }

  if (isResetMemoryDialogShown) {
    handleResetMemoryDialogButtons();
  } else {
    handleSettingsButtons();
  }

  if (!resetSkipFrame && isResetDoneDialogShown) {
    arduboy.delayShort(2000); 
    isResetDoneDialogShown = false;
  }

  resetSkipFrame = false;
  
  String audioState = "Audio On";
  if (!isAudioOn()) {
    audioState = "Audio Off";
  }
  
  drawCenterText(audioState, 7, settingsSelection == 0);
  drawCenterText("Reset game", 21, settingsSelection == 1);
  drawCenterText("Credits", 35, settingsSelection == 2);
  drawCenterText("Back", 49, settingsSelection == 3);

  if (isResetMemoryDialogShown) {
    drawResetMemoryDialog();
  } else if (isResetDoneDialogShown) {
    // display done dialog for 2 seconds
    drawDoneDialog();
  }
}

void confirmSettingsSelection() {
  if (settingsSelection == 0) {
    bool currentAudioState = isAudioOn();
    saveAudioState(!currentAudioState);
  } else if (settingsSelection == 1) {
    isResetMemoryDialogShown = true;
  } else if (settingsSelection == 2) {
    
    // leftSettings = true;
  } else if (settingsSelection == 3) {
    currentScreen = menu_screen;
    leftSettings = true;
  }
}

void drawResetMemoryDialog() {
  arduboy.fillRoundRect(10, 10, 112, 48, 4);
  arduboy.setCursor(15, 15);
  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);
  
  arduboy.print("Reset game?");
  arduboy.setCursor(15, 44);
  arduboy.print("Yes(A)");
  arduboy.setCursor(66, 44);
  arduboy.print("No(B)");
  
  arduboy.setTextBackground(BLACK);
  arduboy.setTextColor(WHITE);
}

void drawDoneDialog() {
  arduboy.fillRoundRect(10, 10, 112, 48, 4);
  arduboy.setCursor(15, 15);
  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);

  arduboy.print("Game state was");
  arduboy.setCursor(15, 24);
  arduboy.print("reset.");
  arduboy.setTextBackground(BLACK);
  arduboy.setTextColor(WHITE);
}

void handleResetMemoryDialogButtons() {
  // A button is reseting game
  if (arduboy.justPressed(A_BUTTON)) {
    resetGame();
    isResetMemoryDialogShown = false;
    isResetDoneDialogShown = true;
    resetSkipFrame = true;
  } else if (arduboy.justPressed(B_BUTTON)) {
    isResetMemoryDialogShown = false;
  }
}

void handleSettingsButtons() {
  // B is a select button
  if (arduboy.justPressed(B_BUTTON)) {
    confirmSettingsSelection();
  }
  // A is exiting
  if (arduboy.justPressed(A_BUTTON)) {
    currentScreen = menu_screen;
  }
  
  // Selection movement
  if (arduboy.justPressed(UP_BUTTON) && settingsSelection > 0) {
    settingsSelection = settingsSelection - 1;
  }
  if (arduboy.justPressed(DOWN_BUTTON) && settingsSelection < settingsItems - 1) {
    settingsSelection = settingsSelection + 1;
  }
}
