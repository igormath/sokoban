#ifndef GAME_H_
#define GAME_H_
#include <raylib.h>

void drawMapLimits(Texture2D limitBlock);
void drawGround(Texture2D groundTexture, Texture2D targetTexture);
void writeSaveGame(Vector2 characterPosition, Vector2 boxPosition);
void readSaveGame(Vector2 *loadedPositionCharacter, Vector2 *loadedPositionBox);

#endif /* GAME_H_ */