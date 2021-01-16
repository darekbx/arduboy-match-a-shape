// Game assets and levels

struct game_level {
  byte correctShape[25];
  byte hashedShape[25];
  byte stars[2];
  byte levelSize;
};

#define LEVELS_COUNT 50
#define ICON_SIZE 16

PROGMEM const unsigned char starFilled[] = {
  0x40, 0xe0, 0xe0, 0xe0, 
  0xe0, 0xe0, 0xf8, 0xff, 
  0xff, 0xfc, 0xe0, 0xe0, 
  0xe0, 0xe0, 0xe0, 0x40, 
  0x00, 0x00, 0x01, 0xf3, 
  0xff, 0x7f, 0x3f, 0x1f, 
  0x1f, 0x3f, 0x7f, 0xff, 
  0xf3, 0x01, 0x00, 0x00 
};
PROGMEM const unsigned char starEmpty[] = {
  0x40, 0xc0, 0xc0, 0xc0, 
  0x40, 0x40, 0x78, 0x1e, 
  0x1e, 0x78, 0x60, 0x40, 
  0xc0, 0xc0, 0xc0, 0x40, 
  0x00, 0x00, 0x00, 0xe1, 
  0x7f, 0x66, 0x30, 0x10, 
  0x10, 0x30, 0x66, 0x7f, 
  0xe1, 0x00, 0x00, 0x00
};
PROGMEM const unsigned char padlock[] = {
  0x00, 0x80, 0xc0, 0xfc, 
  0xfe, 0xff, 0xc7, 0xc7, 
  0xc7, 0xc7, 0xff, 0xfe, 
  0xfc, 0xc0, 0x80, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xe3, 
  0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0x7f, 0x00
};

PROGMEM const unsigned char gameLogo[] = {
  0x00, 0x00, 0xf8, 0xf8, 0xf8, 0x18, 0xf8, 0xf8, 0xf8, 0xf8, 0x18, 0xf8, 0xf8, 0xf0, 0x00, 0x80, 
  0xd8, 0xd8, 0xd8, 0xd8, 0xf8, 0xf8, 0xf0, 0x00, 0x18, 0xfe, 0xfe, 0xfe, 0x18, 0x18, 0xe0, 0xf0, 
  0xf8, 0x38, 0x18, 0x18, 0x18, 0x00, 0x00, 0xff, 0xff, 0xff, 0x18, 0x18, 0xf8, 0xf8, 0xf0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x18, 0xfe, 0xfe, 0xfe, 0x18, 0x18, 0x00, 0xff, 0xff, 0xff, 0x18, 0x18, 
  0xf8, 0xf8, 0xf0, 0xe0, 0xf0, 0xf8, 0xf8, 0xd8, 0xd8, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x30, 0x78, 0xf8, 0xd8, 0xd8, 0xd8, 0xd8, 0x00, 0x00, 0xff, 0xff, 0xff, 0x18, 0x18, 0xf8, 
  0xf8, 0xf0, 0x80, 0xd8, 0xd8, 0xd8, 0xd8, 0xf8, 0xf8, 0xf0, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0x10, 
  0x10, 0xf0, 0xf0, 0xe0, 0x00, 0xe0, 0xe0, 0xf0, 0xf8, 0xd8, 0xd8, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x07, 0x07, 0x07, 0x07, 0x00, 0x07, 0x07, 0x07, 0x00, 0x03, 
  0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x07, 0x00, 0x00, 0x03, 0x07, 0x07, 0x06, 0x06, 0x01, 0x03, 
  0x07, 0x07, 0x06, 0x06, 0x06, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x06, 0x06, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 
  0x07, 0x07, 0x07, 0x01, 0x03, 0x07, 0x07, 0x06, 0x06, 0x06, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x02, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x01, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x07, 
  0x07, 0x07, 0x03, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x07, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x06,
  0x06, 0x07, 0x07, 0x03, 0x00, 0x01, 0x03, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, 0x00
};

const char howToPlayLine1[] PROGMEM = "Each level contains";
const char howToPlayLine2[] PROGMEM = "a shape which should";
const char howToPlayLine3[] PROGMEM = "be matched to the";
const char howToPlayLine4[] PROGMEM = "smaller shape on the";
const char howToPlayLine5[] PROGMEM = "right, by rotating";
const char howToPlayLine6[] PROGMEM = "selected part.";
const char howToPlayLine7[] PROGMEM = "To rotate press";
const char howToPlayLine8[] PROGMEM = "B button and use";
const char howToPlayLine9[] PROGMEM = "arrows to change";
const char howToPlayLine10[] PROGMEM = "selected part.";
const char howToPlayLine11[] PROGMEM = "Button A is used to";
const char howToPlayLine12[] PROGMEM = "exit from the game.";
const char howToPlayLine13[] PROGMEM = "";
const char howToPlayLine14[] PROGMEM = "Fewer movements you";
const char howToPlayLine15[] PROGMEM = "make, the more";
const char howToPlayLine16[] PROGMEM = "stars you get!";

/*
 * Cell kind:
 * 0 - solid
 * 1 - stroke
 * 2 - lines
 * 3 - dots 
 */
const struct game_level levels[LEVELS_COUNT] PROGMEM = {
  // Level 1
  {
    { 1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1 }, 
    { 1,1,1,1,1,0,1,1,0,1,1,1,0,1,1,0 },
    { 5,8 },
    4
  },
  // Level 2
  {
    { 0,1,1,3,1,1,1,1,1,1,1,1,2,1,1,0 }, 
    { 1,0,3,1,1,1,1,1,1,1,1,0,1,2,1,1 },
    { 6,8 },
    4
  },
  // Level 3
  {
    { 2,1,1,2,1,2,2,1,1,0,0,1,0,1,1,0 }, 
    { 2,2,1,1,0,2,1,0,1,1,1,0,0,1,2,1 },
    { 10,16 },
    4
  },
  // Level 4
  {
    { 1,1,3,3,1,2,3,3,3,3,2,1,3,3,1,1 }, 
    { 3,3,2,3,1,3,1,3,1,1,1,3,3,1,3,2 },
    { 12,20 },
    4
  },
  // Level 5
  {
    { 2,2,1,1,2,1,1,3,2,1,1,3,1,1,3,3 },
    { 1,2,1,3,2,2,2,3,3,1,1,1,1,1,1,3 },
    { 12,18 },
    4
  },
  // Level 6
  {
    { 1,2,1,2,1,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,1,2,1,2,1 },
    { 1,2,2,2,1,1,1,1,1,1,1,2,2,1,1,1,1,2,1,1,1,2,1,2,1 },
    { 2,6 },
    5
  },
  // Level 7
  {
    { 3,1,3,1,3,1,1,1,1,1,3,1,3,1,3,1,1,1,1,1,3,1,3,1,3 },
    { 3,1,1,1,3,3,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,3,3 },
    { 9,12 },
    5
  },
  // Level 8
  {
    { 1,1,1,2,1,1,2,2,2,1,1,2,1,1,1,1,2,2,2,1,1,1,1,2,1 },
    { 2,1,1,2,2,1,1,1,1,1,1,2,2,1,1,1,1,2,1,2,2,1,1,2,1 },
    { 9,14 },
    5
  },
  // Level 9
  {
    { 1,1,1,1,1,1,2,3,2,1,1,1,1,1,1,1,2,3,2,1,1,1,1,1,1 },
    { 1,1,1,1,2,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,3,1,1,1,3 },
    { 12,20 },
    5
  },
  // Level 10
  {
    { 1,1,1,1,1,3,1,1,1,3,1,3,3,3,1,3,1,1,1,3,1,1,1,1,1 },
    { 1,3,1,1,3,1,1,3,3,1,3,1,1,1,1,1,1,3,1,3,1,1,1,1,1 },
    { 9,20 },
    5
  },
  // Level 11
  {
    { 3,1,1,1,3,3,1,1,1,3,1,3,1,3,1,1,3,1,3,1,1,1,3,1,1 },
    { 1,1,3,1,3,1,3,1,3,1,1,1,3,1,3,3,1,3,1,1,1,1,1,1,3 },
    { 10,20 },
    5
  },
  // Level 12
  {
    { 1,1,1,1,1,3,1,1,1,2,3,3,1,2,2,3,1,1,2,1,1,1,1,1,1 },
    { 1,3,1,1,1,1,1,1,2,1,3,1,1,2,1,3,1,1,2,1,3,1,1,1,2 },
    { 11,20 },
    5
  },
  // Level 13
  {
    { 1,1,2,1,1,1,1,2,1,1,1,3,3,3,1,1,1,2,1,1,1,1,2,1,1 },
    { 1,1,2,1,1,1,1,1,1,1,3,3,1,2,2,1,1,2,3,1,1,1,1,1,1 },
    { 7,14 },
    5
  },
  // Level 14
  {
    { 1,1,3,1,1,1,3,3,3,1,1,3,0,3,1,1,3,3,3,1,1,1,3,1,1 },
    { 3,1,1,3,1,3,3,1,1,1,3,3,0,3,1,1,3,3,1,1,1,1,1,1,3 },
    { 11,16 },
    5
  },
  // Level 15
  {
    { 2,1,1,1,1,2,1,1,1,1,3,3,3,3,3,1,1,1,1,2,1,1,1,1,2 }, 
    { 1,1,1,3,1,2,1,1,1,1,2,1,1,1,1,3,1,3,1,3,2,3,1,2,1 },
    { 17,24 },
    5
  },
  // Level 16
  {
    { 2,1,1,1,1,1,3,3,1,1,1,3,3,3,1,1,1,3,3,1,1,1,1,1,2 },
    { 1,1,3,3,3,1,2,1,1,1,1,3,3,3,1,1,1,1,1,1,3,1,2,1,1 },
    { 18,28 },
    5
  },
  // Level 17
  {
    { 1,1,1,1,1,0,0,3,0,0,1,1,3,1,1,0,0,3,0,0,1,1,1,1,1 },
    { 0,1,1,1,0,0,1,0,1,0,1,1,3,3,0,1,1,1,0,1,1,1,1,0,3 },
    { 18,26 },
    5
  },
  // Level 18
  {
    { 2,1,1,2,2,2,1,1,1,1,1,1,3,1,1,1,1,1,1,2,2,2,1,1,2 },
    { 1,2,1,1,2,1,1,1,1,1,2,2,3,2,2,1,1,1,2,1,1,1,2,1,1 },
    { 13,20 },
    5
  },
  // Level 19
  {
    { 1,1,1,1,1,2,1,3,1,2,1,0,1,0,1,2,1,3,1,2,1,1,1,1,1 },
    { 1,1,1,1,0,0,1,1,1,1,3,1,2,1,1,1,2,1,3,1,1,1,1,2,2 },
    { 16,24 },
    5
  },
  // Level 20
  {
    { 1,1,1,1,1,3,1,1,1,3,3,3,3,3,3,3,1,1,1,3,1,1,1,1,1 },
    { 3,1,3,1,1,1,3,3,1,1,1,3,3,1,3,1,1,3,1,1,1,1,3,1,1 },
    { 15,22 },
    5
  },
  // Level 21
  {
    { 1,1,2,1,1,1,1,3,1,1,2,3,2,3,2,1,1,3,1,1,1,1,2,1,1 },
    { 3,1,2,3,1,1,2,1,2,3,1,1,2,1,1,1,1,1,1,1,3,1,1,1,2 },
    { 17,26 },
    5
  },
  // Level 22
  {
    { 1,1,1,1,1,1,2,2,2,1,1,2,3,3,1,1,2,3,3,1,1,1,1,1,1 },
    { 1,2,1,3,1,1,2,2,1,1,1,2,1,3,1,1,3,1,3,1,1,2,1,1,1 },
    { 8,16 },
    5
  },
  // Level 23
  {
    { 1,3,3,3,1,3,1,2,1,3,1,1,2,1,1,3,1,2,1,3,1,3,3,3,1 },
    { 3,1,1,3,3,1,3,2,1,3,1,3,1,1,1,2,1,3,2,1,3,3,1,1,3 },
    { 16,24 },
    5
  },
  // Level 24
  {
    { 1,1,1,1,1,1,2,2,2,1,1,1,2,1,1,1,1,3,1,1,1,3,3,3,1 },
    { 1,2,2,3,1,2,1,3,1,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,2 },
    { 18,25 },
    5
  },
  // Level 25
  {
    { 1,1,1,1,1,1,2,2,2,1,1,2,3,2,1,1,2,2,2,1,1,1,1,1,1 },
    { 2,1,1,2,1,1,2,1,1,1,2,1,2,1,1,3,2,1,1,1,1,2,2,1,1 },
    { 15,20 },
    5
  },
  // Level 26
  {
    { 1,1,1,1,1,1,3,1,3,1,2,3,2,3,2,2,1,2,1,2,1,1,1,1,1 },
    { 1,1,2,1,1,1,1,1,2,1,3,2,3,2,1,3,2,1,1,1,3,2,1,1,1 },
    { 21,30 },
    5
  },
  // Level 27
  {
    { 0,1,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,0 },
    { 1,1,1,1,0,1,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,0,1,0,1 },
    { 15,24 },
    5
  },
  // Level 28
  {
    { 1,1,0,1,2,0,0,0,1,2,0,1,3,1,1,1,1,3,3,3,1,1,1,1,3 },
    { 3,3,0,2,3,0,0,0,1,1,1,1,1,2,1,3,3,1,0,1,1,1,1,1,1 },
    { 25,35 },
    5
  },
  // Level 29
  {
    { 1,1,1,1,1,1,3,1,3,1,1,3,3,3,1,2,2,3,2,2,2,2,2,2,2 },
    { 2,3,1,1,2,2,2,1,2,1,3,3,1,2,3,3,1,1,1,3,1,2,2,2,1 },
    { 30,40 },
    5
  },
  // Level 30
  {
    { 1,1,1,1,1,1,2,1,2,1,2,2,3,2,2,1,2,1,2,1,1,1,1,1,1 },
    { 1,1,2,1,1,2,1,1,2,2,1,1,2,1,1,1,2,2,3,1,1,2,1,1,1 },
    { 12,20 },
    5
  },
  // Level 31
  {
    { 0,1,1,1,0,1,0,1,0,1,1,1,2,1,1,1,0,1,0,1,0,1,1,1,0 },
    { 1,2,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,1,0 },
    { 12,20 }, 
    5
  },
  // Level 32
  {
    { 1,1,2,1,1,1,2,3,2,1,1,1,2,1,1,1,1,0,1,1,0,0,0,0,0 },
    { 1,2,1,0,1,2,1,1,1,1,1,1,0,0,0,2,1,0,1,2,1,0,1,3,1 },
    { 25,30 }, 
    5
  },
  // Level 33
  {
    { 2,1,1,1,2,2,1,1,1,2,2,0,0,0,2,2,0,0,0,2,2,2,2,2,2 },
    { 2,2,0,2,2,1,1,2,0,0,2,2,1,0,2,2,1,0,0,2,1,2,1,2,2 },
    { 22,28 }, 
    5
  },
  // Level 34
  {
    { 0,1,1,1,0,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,0,1,1,1,0 },
    { 1,1,1,1,2,2,1,1,1,1,1,1,0,2,0,2,1,1,1,1,1,0,1,1,0 },
    { 16,26 }, 
    5
  },
  // Level 35
  {
    { 2,1,2,1,2,1,3,1,3,1,1,1,0,1,1,1,3,1,3,1,2,1,2,1,2 },
    { 1,1,2,3,3,1,1,1,2,1,3,1,0,2,1,2,1,3,1,2,1,1,1,1,2 },
    { 22,30 }, 
    5
  },
  // Level 37
  {
    { 1,1,1,0,0,1,1,1,0,0,1,1,3,1,1,0,0,1,1,1,0,0,1,1,1 },
    { 0,1,3,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1 },
    { 18,25 }, 
    5
  },
  // Level 38
  {
    { 1,1,1,1,1,1,3,3,3,1,2,2,1,2,2,1,3,3,3,1,1,1,1,1,1 },
    { 2,1,1,1,1,1,1,3,1,3,1,3,3,2,1,1,2,2,1,1,1,1,3,1,3 },
    { 21,30 }, 
    5
  },
  // Level 39
  {
    { 1,1,1,1,1,2,3,1,3,2,2,1,3,1,2,2,3,1,3,2,1,1,1,1,1 },
    { 1,3,2,2,3,3,1,1,1,3,1,2,1,2,1,1,1,2,1,1,1,1,3,2,1 },
    { 22,28 }, 
    5
  },
  // Level 40
  {
    { 0,0,2,0,0,0,1,1,1,0,2,1,1,1,2,0,1,1,1,0,0,0,2,0,0 },
    { 1,0,1,0,0,0,0,0,1,1,2,0,1,2,1,1,0,0,2,1,2,0,0,0,1 },
    { 32,40 }, 
    5
  },
  // Level 41
  {
    { 2,1,1,3,1,1,2,1,1,3,1,1,1,1,1,3,1,1,2,1,1,3,1,1,2 },
    { 1,1,2,2,1,3,1,1,1,1,3,1,1,2,1,3,1,1,1,3,1,1,1,2,1 },
    { 19,24 },
    5
  },
  // Level 42
  {
    { 1,1,1,1,1,1,2,2,2,2,3,1,1,1,2,3,3,3,3,1,1,1,1,1,1 },
    { 3,1,1,1,2,1,2,1,3,2,1,3,3,2,1,1,1,3,2,1,1,1,1,1,1 },
    { 20,26 },
    5
  },
  // Level 43
  {
    { 1,1,1,1,1,1,2,3,2,1,1,3,3,3,1,1,2,3,2,1,1,1,1,1,1 },
    { 2,3,1,3,1,1,1,1,3,1,2,2,1,1,1,1,1,1,1,3,1,3,1,2,1 },
    { 21,30 },
    5
  },
  // Level 44
  {
    { 1,2,3,3,1,1,2,1,1,1,1,2,2,2,1,1,1,1,2,1,1,3,3,2,1 },
    { 3,1,1,2,1,1,3,1,1,2,3,1,2,2,2,1,1,2,3,1,1,2,1,1,1 },
    { 25,35 },
    5
  },
  // Level 45
  {
    { 1,0,0,0,1,2,1,1,1,2,2,1,1,1,2,2,1,1,1,2,1,0,0,0,1 },
    { 1,2,1,0,0,2,1,1,2,0,1,2,1,1,1,1,0,0,1,2,1,0,1,2,1 },
    { 27,33 }, 
    5
  },
  // Level 46
  {
    { 3,1,1,1,3,1,3,1,3,1,1,2,2,2,1,1,3,1,3,1,3,1,1,1,3 },
    { 3,2,3,1,1,1,1,3,3,1,2,2,3,1,1,3,1,3,1,1,1,3,1,1,1 },
    { 29,35 },
    5
  },
  // Level 47
  {
    { 3,3,3,3,3,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,2,2,2,2,2 },
    { 1,3,2,1,3,1,2,1,1,2,1,3,3,1,1,2,1,1,1,3,0,0,1,0,2 },
    { 27,32 },
    5
  },
  // Level 48
  {
    { 1,1,2,1,1,1,1,2,2,1,3,3,1,2,2,1,3,3,1,1,1,1,3,1,1 },
    { 2,3,1,1,1,1,2,1,3,1,3,2,1,1,1,1,3,1,2,1,1,3,1,1,2 },
    { 30,40 },
    5
  },
  // Level 48
  {
    { 3,3,1,1,1,3,2,2,1,1,1,2,0,2,1,1,1,2,2,3,1,1,1,3,3 },
    { 2,2,1,3,2,3,1,1,1,1,1,0,3,2,1,1,2,1,1,1,2,3,3,3,1 },
    { 35,40 },
    5
  },
  // Level 49
  {
    { 1,0,1,0,1,1,0,0,0,1,1,3,3,3,1,1,2,2,2,1,1,2,1,2,1 },
    { 1,1,3,0,0,2,1,1,0,1,1,1,1,1,2,3,2,1,0,3,1,1,0,2,2 },
    { 42,52 },
    5
  },
  // Level 50
  {
    { 1,2,2,2,1,3,1,2,1,3,3,3,0,3,3,3,1,2,1,3,1,2,2,2,1 },
    { 2,1,3,2,3,1,2,1,3,1,1,3,3,2,3,1,1,2,0,3,2,2,2,1,3 },
    { 58,70 },
    5
  }
};
