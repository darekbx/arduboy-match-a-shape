#define settingsItems 4

byte settingsSelection = 0;
boolean isResetMemoryDialogShown = false;
boolean isResetDoneDialogShown = false;
boolean isCreditsDialogShown = false;
boolean resetSkipFrame = false;

void settingsScreen_setup() {
  settingsSelection = 0;
}

void settingsScreen_loop() {
  if (isResetMemoryDialogShown) {
    handleResetMemoryDialogButtons();
  } else if (isCreditsDialogShown) {
    handleCreditDialogButtons();
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
  } else if (isCreditsDialogShown) {
    showCreditsDialog();
  } else if (isResetDoneDialogShown) {
    // display done dialog for 2 seconds
    drawDoneDialog();
  }
}

void confirmSettingsSelection() {
  if (settingsSelection == 0) {
    changeAudioState();
  } else if (settingsSelection == 1) {
    isResetMemoryDialogShown = true;
  } else if (settingsSelection == 2) {
    isCreditsDialogShown = true;
  } else if (settingsSelection == 3) {
    currentScreen = menu_screen;
  }
}

void changeAudioState() {
  bool currentAudioState = isAudioOn();
  saveAudioState(!currentAudioState);
}

void showCreditsDialog() {
  drawDialogBase();
  
  arduboy.print("Credits: ");
  arduboy.setCursor(7, 26);
  arduboy.print("darekbx @2021");
  arduboy.setCursor(7, 37);
  arduboy.print(VERSION);
  
  resetTextColor();
}

void drawResetMemoryDialog() {
  drawDialogBase();
  
  arduboy.print("Reset game?");
  arduboy.setCursor(7, 48);
  arduboy.print("Yes(A)  No(B)");
  
  resetTextColor();
}

void drawDoneDialog() {
  drawDialogBase();
  arduboy.print("Game was reset.");
  resetTextColor();
}

void handleCreditDialogButtons() {
  // A and B button is closing
  if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
    isCreditsDialogShown = false;
  }
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
