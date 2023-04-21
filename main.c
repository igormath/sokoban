#include <raylib.h>
#include <stdio.h>
#define GRAYGROUND        \
    CLITERAL(Color) {     \
        89, 106, 107, 255 \
    }
#define BOX_SIZE 64
#define CHARACTER_INITIAL_POSITION_X 304
#define CHARACTER_INITIAL_POSITION_Y 357
#define BOX_INITIAL_POSITION_X 304
#define BOX_INITIAL_POSITION_Y 421

#include "game.h"

int main(void) {
    int screenWidth = 800, screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Projeto 3 - Programacao 1");
    InitAudioDevice();

    Music backgroundMusic = LoadMusicStream("resources/pisadinha-8bits.mp3");
    int characterVelocity = 0;
    int boxVelocity = 0;
    // Carrega texturas do ambiente
    Texture2D limitBlockTexture = LoadTexture("assets/map/block_01.png");
    Texture2D groundTexture = LoadTexture("assets/map/ground_06.png");
    Texture2D targetTexture = LoadTexture("assets/map/ground_03.png");

    // Carrega texturas do personagem
    Texture2D characterUp = LoadTexture("assets/player/player_up.png");
    Texture2D characterDown = LoadTexture("assets/player/player_down.png");
    Texture2D characterLeft = LoadTexture("assets/player/player_left.png");
    Texture2D characterRight = LoadTexture("assets/player/player_right.png");
    Texture2D characterTexture = characterDown;

    // Carrega textura da caixa
    Texture2D boxTexture = LoadTexture("assets/crate/crate.png");

    Vector2 characterPosition = {CHARACTER_INITIAL_POSITION_X, CHARACTER_INITIAL_POSITION_Y};
    Vector2 boxPosition = {BOX_INITIAL_POSITION_X, BOX_INITIAL_POSITION_Y};
    Vector2 loadedPositionCharacter = {0};
    Vector2 loadedPositionBox = {0};
    Vector2 finalBox = {304, 229};
    Rectangle finalRectangle = {finalBox.x, finalBox.y, BOX_SIZE, BOX_SIZE};

    Rectangle finalCollisionRec = {0};

    // Retangulos de limite do mapa.
    Rectangle mapLimitLine1 = {240, 357, 3, 192};
    Rectangle mapLimitLine2 = {240, 357, 128, 3};
    Rectangle mapLimitLine3 = {368, 357, 3, 64};
    Rectangle mapLimitLine4 = {240, 549, 320, 3};
    Rectangle mapLimitLine5 = {560, 101, 3, 448};
    Rectangle mapLimitLine6 = {240, 101, 320, 3};
    Rectangle mapLimitLine7 = {240, 101, 3, 192};
    Rectangle mapLimitLine8 = {240, 293, 128, 3};
    Rectangle mapLimitLine9 = {368, 229, 3, 64};
    Rectangle mapLimitLine10 = {370, 229, 62, 3};
    Rectangle mapLimitLine11 = {432, 229, 3, 192};
    Rectangle mapLimitLine12 = {368, 421, 64, 3};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateMusicStream(backgroundMusic);
        PlayMusicStream(backgroundMusic);

        characterVelocity = 2;
        boxVelocity = 2;

        if (IsKeyDown(KEY_W)) {
            characterPosition.y -= characterVelocity;
            characterTexture = characterUp;
        } else if (IsKeyDown(KEY_S)) {
            characterPosition.y += characterVelocity;
            characterTexture = characterDown;
        } else if (IsKeyDown(KEY_A)) {
            characterTexture = characterLeft;
            characterPosition.x -= characterVelocity;
        } else if (IsKeyDown(KEY_D)) {
            characterPosition.x += characterVelocity;
            characterTexture = characterRight;
        }

        if (IsKeyDown(KEY_R)) {
            characterPosition.x = CHARACTER_INITIAL_POSITION_X;
            characterPosition.y = CHARACTER_INITIAL_POSITION_Y;
            boxPosition.x = BOX_INITIAL_POSITION_X;
            boxPosition.y = BOX_INITIAL_POSITION_Y;
            characterTexture = characterDown;
        }

        if (IsKeyDown(KEY_P)) {
            writeSaveGame(characterPosition, boxPosition);
        }

        Rectangle characterRectangle = {characterPosition.x, characterPosition.y, BOX_SIZE, BOX_SIZE};
        Rectangle boxRectangle = {boxPosition.x, boxPosition.y, BOX_SIZE, BOX_SIZE};

        if (CheckCollisionRecs(characterRectangle, boxRectangle)) {
            float collisionRight = (characterRectangle.x - (boxRectangle.x + BOX_SIZE));
            float collisionLeft = ((characterRectangle.x + BOX_SIZE) - boxRectangle.x);
            float collisionTop = ((characterRectangle.y + BOX_SIZE) - boxRectangle.y);
            float collisionBottom = (characterRectangle.y - (boxRectangle.y + BOX_SIZE));

            if (collisionRight <= -90) {
                boxPosition.x += boxVelocity;
            } else if (collisionLeft >= 90) {
                boxPosition.x -= boxVelocity;
            } else if (collisionTop >= 90) {
                boxPosition.y -= boxVelocity;
            } else if (collisionBottom <= -90) {
                boxPosition.y += boxVelocity;
            }
        }

        // Limit 1
        if (CheckCollisionRecs(characterRectangle, mapLimitLine1)) {
            if (characterPosition.x < mapLimitLine1.x) {
                characterPosition.x = mapLimitLine1.x;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine1)) {
            if (boxPosition.x < mapLimitLine1.x) {
                boxPosition.x = mapLimitLine1.x;
                characterPosition.x = mapLimitLine1.x + BOX_SIZE;
            }
        }

        // Limit 2
        if (CheckCollisionRecs(characterRectangle, mapLimitLine2)) {
            if (characterPosition.y < mapLimitLine2.y) {
                characterPosition.y = mapLimitLine2.y;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine2)) {
            if (boxPosition.y < mapLimitLine2.y) {
                boxPosition.y = mapLimitLine2.y;
                characterPosition.y = mapLimitLine2.y + BOX_SIZE;
            }
        }

        // Limit 3
        if (CheckCollisionRecs(characterRectangle, mapLimitLine3)) {
            if (characterPosition.x < mapLimitLine3.x) {
                characterPosition.x = mapLimitLine3.x - BOX_SIZE;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine3)) {
            if (boxPosition.x < mapLimitLine3.x) {
                boxPosition.x = mapLimitLine3.x - BOX_SIZE;
                characterPosition.x = mapLimitLine3.x - BOX_SIZE * 2;
            }
        }

        // Limit 4
        if (CheckCollisionRecs(characterRectangle, mapLimitLine4)) {
            if (characterPosition.y + BOX_SIZE > mapLimitLine4.y) {
                characterPosition.y = mapLimitLine4.y - BOX_SIZE;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine4)) {
            if (boxPosition.y + BOX_SIZE > mapLimitLine4.y) {
                boxPosition.y = mapLimitLine4.y - BOX_SIZE;
                characterPosition.y = mapLimitLine4.y - BOX_SIZE * 2;
            }
        }

        // Limit 5
        if (CheckCollisionRecs(characterRectangle, mapLimitLine5)) {
            if (characterPosition.x + BOX_SIZE > mapLimitLine5.x) {
                characterPosition.x = mapLimitLine5.x - BOX_SIZE;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine5)) {
            if (boxPosition.x + BOX_SIZE > mapLimitLine5.x) {
                boxPosition.x = mapLimitLine5.x - BOX_SIZE;
                characterPosition.x = boxPosition.x - BOX_SIZE;
            }
        }

        // Limit 6
        if (CheckCollisionRecs(characterRectangle, mapLimitLine6)) {
            if (characterPosition.y < mapLimitLine6.y) {
                characterPosition.y = mapLimitLine6.y;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine6)) {
            if (boxPosition.y < mapLimitLine6.y) {
                boxPosition.y = mapLimitLine6.y;
                characterPosition.y = boxPosition.y + BOX_SIZE;
            }
        }

        // Limit 7
        if (CheckCollisionRecs(characterRectangle, mapLimitLine7)) {
            if (characterPosition.x < mapLimitLine7.x) {
                characterPosition.x = mapLimitLine7.x;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine7)) {
            if (boxPosition.x < mapLimitLine7.x) {
                boxPosition.x = mapLimitLine7.x;
                characterPosition.x = boxPosition.x + BOX_SIZE;
            }
        }

        // Limit 8
        if (CheckCollisionRecs(characterRectangle, mapLimitLine8)) {
            if (characterPosition.y + BOX_SIZE > mapLimitLine8.y) {
                characterPosition.y = mapLimitLine8.y - BOX_SIZE;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine8)) {
            if (boxPosition.y + BOX_SIZE > mapLimitLine8.y) {
                boxPosition.y = mapLimitLine8.y - BOX_SIZE;
                characterPosition.y = boxPosition.y - BOX_SIZE;
            }
        }

        // Limit 9
        if (CheckCollisionRecs(characterRectangle, mapLimitLine9)) {
            if (characterPosition.x + BOX_SIZE > mapLimitLine9.x) {
                characterPosition.x = mapLimitLine9.x - BOX_SIZE;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine9)) {
            if (boxPosition.x + BOX_SIZE > mapLimitLine9.x) {
                boxPosition.x = mapLimitLine9.x - BOX_SIZE;
                characterPosition.x = boxPosition.x - BOX_SIZE;
            }
        }

        // Limit 10
        if (CheckCollisionRecs(characterRectangle, mapLimitLine10)) {
            if (characterPosition.y + BOX_SIZE > mapLimitLine10.y) {
                characterPosition.y = mapLimitLine10.y - BOX_SIZE;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine10)) {
            if (boxPosition.y + BOX_SIZE > mapLimitLine10.y) {
                boxPosition.y = mapLimitLine10.y - BOX_SIZE;
                characterPosition.y = boxPosition.y - BOX_SIZE;
            }
        }

        // Limit 11
        if (CheckCollisionRecs(characterRectangle, mapLimitLine11)) {
            if (characterPosition.x < mapLimitLine11.x) {
                characterPosition.x = mapLimitLine11.x;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine11)) {
            if (boxPosition.x < mapLimitLine11.x) {
                boxPosition.x = mapLimitLine11.x;
                characterPosition.x = boxPosition.x + BOX_SIZE;
            }
        }

        // Limit 12
        if (CheckCollisionRecs(characterRectangle, mapLimitLine12)) {
            if (characterPosition.y < mapLimitLine12.y) {
                characterPosition.y = mapLimitLine12.y;
            }
        }
        if (CheckCollisionRecs(boxRectangle, mapLimitLine12)) {
            if (boxPosition.y < mapLimitLine12.y) {
                boxPosition.y = mapLimitLine12.y;
                characterPosition.y = boxPosition.y + BOX_SIZE;
            }
        }

        readSaveGame(&loadedPositionCharacter, &loadedPositionBox);

        BeginDrawing();

        ClearBackground(GRAYGROUND);
        if (loadedPositionCharacter.x > 0) {
            DrawText("Jogo salvo detectado! Aperte 'O' para continuar", 5, 620, 20, BLACK);
            if (IsKeyDown(KEY_O)) {
                characterPosition.x = loadedPositionCharacter.x;
                characterPosition.y = loadedPositionCharacter.y;
                boxPosition.x = loadedPositionBox.x;
                boxPosition.y = loadedPositionBox.y;
            }
        }
        DrawText("R = reiniciar o jogo", 5, 10, 20, BLACK);
        DrawText("P = salvar o jogo", 550, 10, 20, BLACK);
        drawMapLimits(limitBlockTexture);
        drawGround(groundTexture, targetTexture);

        // Desenha o personagem e a caixa
        DrawTexture(characterTexture, characterPosition.x, characterPosition.y, WHITE);
        DrawTexture(boxTexture, boxPosition.x, boxPosition.y, WHITE);

        if (CheckCollisionRecs(finalRectangle, boxRectangle)) {
            finalCollisionRec = GetCollisionRec(finalRectangle, boxRectangle);
            if ((finalCollisionRec.height >= 55) && (finalCollisionRec.width >= 55)) {
                DrawText("Fim de Jogo!!!", (screenWidth / 2) - 50, screenHeight / 2, 50, GREEN);
            }
        }

        EndDrawing();
    }

    // Depois de usadas, descarrega as texturas e a musica
    UnloadMusicStream(backgroundMusic);
    UnloadTexture(groundTexture);
    UnloadTexture(limitBlockTexture);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
