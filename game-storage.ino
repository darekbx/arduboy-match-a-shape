// Game storage

/* 
 * EEPROM memory structure 
 * [0] - Solved levels count
 * [1] - Audio state, 0 - off, 1 - on
 * [level_index + LEVEL_ADDRESS_OFFSET] - made steps count for each level
 * 
 * if memory address for level_index is -1 or 0, then level is not solved
 */

#define LEVEL_ADDRESS_OFFSET 1
#define AUDIO_STATE_ADDRESS 1

void clearMemory() {
  for (int i = 0; i < EEPROM.length(); i++) {
    EEPROM.write(i, 0);
  }
}

void resetGame() {
  for (int levelIndex = LEVEL_ADDRESS_OFFSET; levelIndex <= LEVELS_COUNT; levelIndex++) {
    EEPROM.write(levelIndex + 1, 0);
  }
}

bool isAudioOn() {
  return readValue(AUDIO_STATE_ADDRESS) == 1;
}

void saveAudioState(bool isOn) {
  saveValue(AUDIO_STATE_ADDRESS, isOn ? 1 : 0);
}

void saveLevelMoves(int levelIndex, byte movesMade) {
  // levelIndex starts with 1
  saveValue(levelIndex + LEVEL_ADDRESS_OFFSET, movesMade);
}

byte readLevelMoves(int levelIndex) {
  // levelIndex starts with 1
  return readValue(levelIndex + LEVEL_ADDRESS_OFFSET);
}

void saveValue(int address, byte number) {
  EEPROM.write(address, number & 0xFF);
}

byte readValue(int address) {
  return EEPROM.read(address);
}
