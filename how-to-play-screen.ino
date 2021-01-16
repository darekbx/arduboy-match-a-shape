
#define LINES_COUNT 16
#define SCROLL_LIMIT 95
#define SCROLL_STEP 4

const char* const howToPlayText[] PROGMEM = {
  howToPlayLine1,
  howToPlayLine2,
  howToPlayLine3,
  howToPlayLine4,
  howToPlayLine5,
  howToPlayLine6,
  howToPlayLine7,
  howToPlayLine8,
  howToPlayLine9,
  howToPlayLine10,
  howToPlayLine11,
  howToPlayLine12,
  howToPlayLine13,
  howToPlayLine14,
  howToPlayLine15,
  howToPlayLine16
};

short scrollPosition = 0;

void howToPlayScreen_setup() {
  scrollPosition = 0;
}

void howToPlayScreen_loop() {
  handleHowToPlayButtons();
  char tBuffer[22];
  
  for (byte i = 0; i < LINES_COUNT; i++) {
    arduboy.setCursor(0, (i * 9) + 17 - scrollPosition);
    String line = strcpy_P(tBuffer, (char*)pgm_read_word(&(howToPlayText[i])));
    arduboy.print(line);
  }

  arduboy.fillRect(0, 0, 128, 16, BLACK);
  drawCenterText("How to play", 2, false);
  arduboy.drawLine(0, 13, 128, 13);

  if (scrollPosition == 0) {
    drawScrollArrowDown();
  } else if (scrollPosition >= SCROLL_LIMIT - 1) {
    drawScrollArrowUp();
  } else {
    drawScrollArrowUp();
    drawScrollArrowDown();
  }
}

void drawScrollArrowUp() {
  arduboy.fillTriangle(120, 4, 126, 4, 123, 1);  
}

void drawScrollArrowDown() {
  arduboy.fillTriangle(120, 6, 126, 6, 123, 9); 
}

void handleHowToPlayButtons() {
  // A and B is closing
  if (arduboy.justPressed(B_BUTTON) || arduboy.justPressed(A_BUTTON)) {
    currentScreen = menu_screen;
  }
  
  // Scroll movement
  if (arduboy.justPressed(UP_BUTTON) && scrollPosition > 0) {
    scrollPosition = scrollPosition - SCROLL_STEP;
  }
  if (arduboy.justPressed(DOWN_BUTTON) && scrollPosition <= SCROLL_LIMIT) {
    scrollPosition = scrollPosition + SCROLL_STEP;
  }
}
