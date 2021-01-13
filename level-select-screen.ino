// Level select screen

#define levelRectWidth 60
#define levelRectHeigth 44
#define levelCenterX 35
#define levelCenterY 16
#define levelRectPadding 10
#define starYPosition 24

short levelSelection = 0;
byte lockedLevelIndex = 0;
bool isLockedDialogShow = false;

void levelSelectScreen_loop() {
  handleLevelSelectButtons();

  drawCenterText("Select level", 2, false);
  
  game_level selectedlevel;
  bool isPreviousNotSolved = false;
  bool hasLockedLevel = false;
 
  for (byte levelIndex = 0; levelIndex < LEVELS_COUNT; levelIndex++) {
    memcpy_P(&selectedlevel, &levels[levelIndex], sizeof(game_level));
    byte movesMade = readLevelMoves(levelIndex + 1);

    short levelRectPosition = (levelIndex + levelSelection) * (levelRectWidth + levelRectPadding);
    drawLevelCard(levelRectPosition, levelIndex);
    
    if (movesMade > 0) {
      drawStars(levelRectPosition, movesMade, selectedlevel);
    } else if (movesMade == 0 && isPreviousNotSolved) {
      if (!hasLockedLevel) {
        lockedLevelIndex = levelIndex;
        hasLockedLevel = true;
        
        #if ALL_LEVELS_UNLOCKED
          lockedLevelIndex = LEVELS_COUNT;
          hasLockedLevel = false;
          #endif
      }
      arduboy.drawBitmap(
        levelCenterX + levelRectPosition + 22, 
        levelCenterY + starYPosition, 
        padlock, ICON_SIZE, ICON_SIZE, WHITE);
    }
    
    if (movesMade == 0 && !isPreviousNotSolved) {
      isPreviousNotSolved = true;
    }
  }

  if (isLockedDialogShow) {
    drawLockedDialog();
  }
}

void drawLevelCard(short levelRectPosition, byte levelIndex) {
  arduboy.drawRoundRect(levelCenterX + levelRectPosition, levelCenterY, levelRectWidth, levelRectHeigth, 6);
  
  arduboy.setCursor(levelCenterX + levelRectPosition + 4, levelCenterY + 6);
  arduboy.print("Level ");
  arduboy.setCursor(levelCenterX + levelRectPosition + 40, levelCenterY + 6);
  arduboy.print(String(levelIndex + 1));
}

void drawLockedDialog() {
  arduboy.fillRoundRect(10, 10, 112, 48, 4);
  arduboy.setCursor(15, 15);
  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);
  
  arduboy.print("Level is locked!");
  
  arduboy.setTextBackground(BLACK);
  arduboy.setTextColor(WHITE);
}

void drawStars(short levelRectPosition, byte movesMade, game_level level) {  
  short starX = levelCenterX + levelRectPosition;
  byte starY = levelCenterY + starYPosition;
  byte starsNumber = 0;

  if (movesMade <= level.stars[0]) {
    starsNumber = 3;
  } else if (movesMade <= level.stars[1]) {
    starsNumber = 2;
  } else if (movesMade > 0) {
    starsNumber = 1;
  }

  char *firstStar = starsNumber > 0 ? starFilled: starEmpty;
  char *secondStar = starsNumber > 1 ? starFilled : starEmpty;
  char *thirdStar = starsNumber > 2 ? starFilled : starEmpty;

  arduboy.drawBitmap(starX + 3, starY, firstStar, ICON_SIZE, ICON_SIZE);
  arduboy.drawBitmap(starX + 22, starY, secondStar, ICON_SIZE, ICON_SIZE);
  arduboy.drawBitmap(starX + 41, starY, thirdStar, ICON_SIZE, ICON_SIZE);
}

void handleLevelSelectButtons() {

  // A button is exiting to menu
  if (arduboy.justPressed(A_BUTTON)) {
    if (isLockedDialogShow) {
      isLockedDialogShow = false;
      return;
    }
    currentScreen = menu_screen;
  }

  // B is a select button
  if (arduboy.justPressed(B_BUTTON)) {
    if (isLockedDialogShow) {
      isLockedDialogShow = false;
      return;
    } 

    if (lockedLevelIndex > 0 && abs(levelSelection) >= lockedLevelIndex) {
      isLockedDialogShow = true;
      return;
    }
    
    prepareLevel(abs(levelSelection));
    currentScreen = game_screen;
  }
  
  // Level selection movement
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    levelSelection = max(levelSelection - 1, -(LEVELS_COUNT - 1));
  }
  if (arduboy.justPressed(LEFT_BUTTON)) {
    levelSelection = min(levelSelection + 1, 0);
  }
}
