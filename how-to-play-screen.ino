
#define LINES_COUNT 16
#define SCROLL_LIMIT 95
#define SCROLL_STEP 4

String howToPlayText[] = {
  "Each level contains",
  "a shape which should",
  "be matched to the",
  "smaller shape on the",
  "right, by rotating",
  "selected part.",
  "To rotate press",
  "B button and use",
  "arrows to change",
  "selected part.",
  "Button A is used to",
  "exit from the game.",
  "",
  "Fewer movements you",
  "make, the more",
  "stars you get!"
};

short scrollPosition = 0;

void howToPlayScreen_setup() {
  scrollPosition = 0;
}

void howToPlayScreen_loop() {
  handleHowToPlayButtons();
  
  for (byte i = 0; i < LINES_COUNT; i++) {
    arduboy.setCursor(0, (i * 9) + 17 - scrollPosition);
    arduboy.print(howToPlayText[i]);
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
