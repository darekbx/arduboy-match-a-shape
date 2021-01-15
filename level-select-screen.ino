#define levelRectWidth 60
#define levelRectHeigth 50
#define levelCenterX 35
#define levelCenterY 14
#define levelRectPadding 10
#define starYPosition 29

short lastSolvedLevelIndex = 0;
short levelSelection = 0;
byte lockedLevelIndex = 0;
bool isLockedDialogShow = false;

void levelSelectScreen_setup() {
  if (getLastSolvedLevelIndex() > 0) {
    levelSelection = -getLastSolvedLevelIndex();
  } else {
    levelSelection = 0;
  }
}

bool a = false;

void levelSelectScreen_loop() {
  handleLevelSelectButtons();

  drawCenterText("Select level", 2, false);
  
  game_level selectedlevel;
  bool isPreviousNotSolved = false;
  bool hasLockedLevel = false;

  // Render only selected level and two on the left and on the right
  short startIndex = max(0, abs(levelSelection) - 2);
  short endIndex = min(LEVELS_COUNT - 1, abs(levelSelection) + 2);
  
  for (byte levelIndex = startIndex; levelIndex <= endIndex; levelIndex++) {
    memcpy_P(&selectedlevel, &levels[levelIndex], sizeof(game_level));
    byte movesMade = readLevelMoves(levelIndex + 1);

    short levelRectPosition = (levelIndex + levelSelection) * (levelRectWidth + levelRectPadding);
    drawLevelCard(levelRectPosition, levelIndex, movesMade);

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
    } else {
      drawEmptyStars(levelRectPosition);
    }
    
    if (movesMade == 0 && !isPreviousNotSolved) {
      isPreviousNotSolved = true;
    }
  }

  if (isLockedDialogShow) {
    drawLockedDialog();
  }
}

void drawLevelCard(short levelRectPosition, byte levelIndex, byte movesMade) {
  arduboy.drawRoundRect(levelCenterX + levelRectPosition, levelCenterY, levelRectWidth, levelRectHeigth, 6);
  short xPosition1Row = levelCenterX + levelRectPosition + 5;
  short xPosition2Row = levelCenterX + levelRectPosition + 34;
  byte yPosition1Row = levelCenterY + 4;
  byte yPosition2Row = levelCenterY + 17;

  arduboy.fillRoundRect(levelCenterX + levelRectPosition, levelCenterY, levelRectWidth, 10, 6);
  arduboy.fillRect(levelCenterX + levelRectPosition, levelCenterY + 4, levelRectWidth, 10);
  arduboy.setCursor(xPosition1Row, yPosition1Row);
  
  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);
  arduboy.print("Level " + String(levelIndex + 1));
  arduboy.setTextColor(WHITE);
  arduboy.setTextBackground(BLACK);

  if (movesMade > 0) {
    arduboy.setCursor(xPosition1Row, yPosition2Row);
    arduboy.print("Moves " + String(movesMade));
  }
}

void drawLockedDialog() {
  drawDialogBase();
  arduboy.print("Level is locked!");
  resetTextColor();
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

void drawEmptyStars(short levelRectPosition) {  
  short starX = levelCenterX + levelRectPosition;
  byte starY = levelCenterY + starYPosition;
  arduboy.drawBitmap(starX + 3, starY, starEmpty, ICON_SIZE, ICON_SIZE);
  arduboy.drawBitmap(starX + 22, starY, starEmpty, ICON_SIZE, ICON_SIZE);
  arduboy.drawBitmap(starX + 41, starY, starEmpty, ICON_SIZE, ICON_SIZE);
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
    switchToGameScreen();
  }
  
  // Level selection movement
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    levelSelection = max(levelSelection - 1, -(LEVELS_COUNT - 1));
  }
  if (arduboy.justPressed(LEFT_BUTTON)) {
    levelSelection = min(levelSelection + 1, 0);
  }
}
