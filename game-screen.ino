// Game screen

game_level level;

byte actualLevelIndex;
byte hashedShape[25];
byte cellSize;
byte xSelect;
byte ySelect;
byte maxSelect;
byte movesMade;
boolean isSolved = false;

#define shapeX 1
#define shapeY 1
#define cellPadding 2
#define previewCellPadding 1
#define previewCellSize 9
#define previewLocation 74

void gameScreen_loop() {
  arduboy.digitalWriteRGB(GREEN_LED, RGB_OFF);

  drawLevel();
  drawLevelInfo();
    
  if (isSolved) {
    drawSolvedDialog();
  } else {
    handleGameButtons();
    drawMoves();
  }
}

void prepareLevel(byte levelIndex) {
  actualLevelIndex = levelIndex;
  xSelect = 0;
  ySelect = 0;
  movesMade = 0;
  isSolved = false;

  switch (levelIndex) {
    case 1: level = level1; break;
    case 2: level = level2; break;
    case 3: level = level3; break;
    case 4: level = level4; break;
    case 5: level = level5; break;
  }

  memcpy(hashedShape, level.hashedShape, sizeof(level.hashedShape[0])*25);
}

void drawMoves() {
  arduboy.setCursor(70, 57);
  arduboy.print("Moves: " + String(movesMade));
}

void drawLevelInfo() {
  arduboy.setCursor(70, 46);
  arduboy.print("Level: " + String(actualLevelIndex));
}

void drawLevel() {
  switch (level.levelSize) {
    case 4:
      cellSize = 14;
      maxSelect = 2;
      break;
    case 5:
      cellSize = 11;
      maxSelect = 3;
      break;
  }
  
  drawShape(hashedShape, level.levelSize, shapeX, shapeY, cellSize, cellPadding);
  drawShape(level.correctShape, level.levelSize, previewLocation, shapeY, previewCellSize, previewCellPadding);

  arduboy.drawRect(
    (shapeX + (xSelect * (cellSize + cellPadding)) - 1), 
    (shapeY + (ySelect * (cellSize + cellPadding)) - 1), 
    cellSize * 2 + cellPadding * 1 + 2,
    cellSize * 2 + cellPadding * 1 + 2
  );
}

void drawShape(byte shape[], byte levelSize, byte left, byte top, byte cellSize, byte padding) {
  byte cornerRadius = 1;
  for (byte y = 0; y < levelSize; y++) {
    for (byte x = 0; x < levelSize; x++) {
      byte value = shape[y * levelSize + x];
      byte startX = left + x * (cellSize + padding);
      byte startY = top + y * (cellSize + padding);
      if (value == 1 || value == 2 || value == 3) {
        // Stroke
        arduboy.drawRoundRect(startX, startY, cellSize, cellSize, cornerRadius);
      }
      if (value == 0) {
        // Solid
        arduboy.fillRoundRect(startX, startY, cellSize, cellSize, cornerRadius);
      } else if (value == 2) {
        // Lines
        arduboy.drawLine(startX + 1, startY + 1, startX + cellSize - 2, startY + cellSize - 2);
        arduboy.drawLine(startX + 1, startY + cellSize - 2, startX + cellSize - 2, startY + 1);
      } else if (value == 3) {
        // Dots
        for (byte iy = 2; iy < cellSize - 1; iy += 2) {
          for (byte ix = 2; ix < cellSize - 1; ix += 2) {
            arduboy.drawPixel(startX + ix, startY + iy);
          }
        }
      }
    }
  }
}

void drawSolvedDialog() {
  arduboy.fillRoundRect(10, 10, 112, 48, 4);
  arduboy.setCursor(14, 14);
  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);
  arduboy.print("Level 1, Solved! 3 stars!"); 
  arduboy.setTextBackground(BLACK);
  arduboy.setTextColor(WHITE);
}

void rotateSelection() {
  byte startOffset = ySelect * level.levelSize + xSelect;
  
  byte levelPart[4] = {
    hashedShape[startOffset], hashedShape[startOffset + 1],
    hashedShape[startOffset + level.levelSize], hashedShape[startOffset + level.levelSize + 1],
  };

  hashedShape[startOffset] = levelPart[2];
  hashedShape[startOffset + 1] = levelPart[0];
  hashedShape[startOffset + level.levelSize] = levelPart[3];
  hashedShape[startOffset + level.levelSize + 1] = levelPart[1];
}

boolean isShapeCorrect() {
  for (byte n = 0; n < 25; n++) { 
    if (hashedShape[n] != level.correctShape[n]) {
      return false;
    }
  }
  return true;
}

void handleGameButtons() {

  // A button is exiting to menu
  if (arduboy.justPressed(A_BUTTON)) {
    // TODO: Exit with confirmation
  }

  // B button is rotating
  if (arduboy.justPressed(B_BUTTON)) {
    //beep.tone(beep.freq(523.251), 1);
    rotateSelection();

    if (isShapeCorrect()) {
      isSolved = true;
      arduboy.digitalWriteRGB(GREEN_LED, RGB_ON);
    } else {
      movesMade = movesMade + 1;
    }
  }

  // Selection movement
  if (arduboy.justPressed(LEFT_BUTTON) && xSelect > 0) {
    xSelect = xSelect - 1;
  }
  if (arduboy.justPressed(RIGHT_BUTTON) && xSelect < maxSelect) {
    xSelect = xSelect + 1;
  }
  if (arduboy.justPressed(UP_BUTTON) && ySelect > 0) {
    ySelect = ySelect - 1;
  }
  if (arduboy.justPressed(DOWN_BUTTON) && ySelect < maxSelect) {
    ySelect = ySelect + 1;
  }
}
