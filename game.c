#include "game.h"

#include <stdio.h>

#include "raylib.h"

void drawMapLimits(Texture2D limitBlock) {
    // First line
    DrawTexture(limitBlock, 176, 37, WHITE);
    DrawTexture(limitBlock, 240, 37, WHITE);
    DrawTexture(limitBlock, 304, 37, WHITE);
    DrawTexture(limitBlock, 368, 37, WHITE);
    DrawTexture(limitBlock, 432, 37, WHITE);
    DrawTexture(limitBlock, 496, 37, WHITE);
    DrawTexture(limitBlock, 560, 37, WHITE);

    // Second line
    DrawTexture(limitBlock, 176, 101, WHITE);
    DrawTexture(limitBlock, 560, 101, WHITE);

    // Third line
    DrawTexture(limitBlock, 176, 165, WHITE);
    DrawTexture(limitBlock, 560, 165, WHITE);

    // Fourth line
    DrawTexture(limitBlock, 176, 229, WHITE);
    DrawTexture(limitBlock, 368, 229, WHITE);
    DrawTexture(limitBlock, 560, 229, WHITE);

    // Fifth line
    DrawTexture(limitBlock, 176, 293, WHITE);
    DrawTexture(limitBlock, 240, 293, WHITE);
    DrawTexture(limitBlock, 304, 293, WHITE);
    DrawTexture(limitBlock, 368, 293, WHITE);
    DrawTexture(limitBlock, 560, 293, WHITE);

    // Sixth line
    DrawTexture(limitBlock, 176, 357, WHITE);
    DrawTexture(limitBlock, 368, 357, WHITE);
    DrawTexture(limitBlock, 560, 357, WHITE);

    // Seventh line
    DrawTexture(limitBlock, 176, 421, WHITE);
    DrawTexture(limitBlock, 560, 421, WHITE);

    // Eight line
    DrawTexture(limitBlock, 176, 485, WHITE);
    DrawTexture(limitBlock, 560, 485, WHITE);

    // Last line
    DrawTexture(limitBlock, 176, 549, WHITE);
    DrawTexture(limitBlock, 240, 549, WHITE);
    DrawTexture(limitBlock, 304, 549, WHITE);
    DrawTexture(limitBlock, 368, 549, WHITE);
    DrawTexture(limitBlock, 432, 549, WHITE);
    DrawTexture(limitBlock, 496, 549, WHITE);
    DrawTexture(limitBlock, 560, 549, WHITE);
}

void drawGround(Texture2D groundTexture, Texture2D targetTexture) {
    // First line
    DrawTexture(groundTexture, 240, 101, WHITE);
    DrawTexture(groundTexture, 304, 101, WHITE);
    DrawTexture(groundTexture, 368, 101, WHITE);
    DrawTexture(groundTexture, 432, 101, WHITE);
    DrawTexture(groundTexture, 496, 101, WHITE);

    // Second line
    DrawTexture(groundTexture, 240, 165, WHITE);
    DrawTexture(groundTexture, 304, 165, WHITE);
    DrawTexture(groundTexture, 368, 165, WHITE);
    DrawTexture(groundTexture, 432, 165, WHITE);
    DrawTexture(groundTexture, 496, 165, WHITE);

    // Third line
    DrawTexture(groundTexture, 240, 229, WHITE);
    DrawTexture(targetTexture, 304, 229, WHITE);
    DrawTexture(groundTexture, 432, 229, WHITE);
    DrawTexture(groundTexture, 496, 229, WHITE);

    // Fourth line
    DrawTexture(groundTexture, 432, 293, WHITE);
    DrawTexture(groundTexture, 496, 293, WHITE);

    // Fifth line
    DrawTexture(groundTexture, 240, 357, WHITE);
    DrawTexture(groundTexture, 304, 357, WHITE);
    DrawTexture(groundTexture, 432, 357, WHITE);
    DrawTexture(groundTexture, 496, 357, WHITE);

    // Sixth line
    DrawTexture(groundTexture, 240, 421, WHITE);
    DrawTexture(groundTexture, 304, 421, WHITE);
    DrawTexture(groundTexture, 368, 421, WHITE);
    DrawTexture(groundTexture, 432, 421, WHITE);
    DrawTexture(groundTexture, 496, 421, WHITE);

    // Seventh line
    DrawTexture(groundTexture, 240, 485, WHITE);
    DrawTexture(groundTexture, 304, 485, WHITE);
    DrawTexture(groundTexture, 368, 485, WHITE);
    DrawTexture(groundTexture, 432, 485, WHITE);
    DrawTexture(groundTexture, 496, 485, WHITE);
}

void writeSaveGame(Vector2 characterPosition, Vector2 boxPosition) {
    char fileName[14] = "save_game.csv";
    FILE *saveGameOutput = fopen(fileName, "w");

    if (saveGameOutput != NULL) {
        fprintf(saveGameOutput, "%.2f;%.2f;%.2f;%.2f", characterPosition.x, characterPosition.y, boxPosition.x, boxPosition.y);
        fclose(saveGameOutput);
    } else {
        puts("Erro! nao foi possivel salvar o game!");
    }
}

void readSaveGame(Vector2 *loadedPositionCharacter, Vector2 *loadedPositionBox) {
    FILE *memoryCard = fopen("save_game.csv", "r");

    if (memoryCard != NULL) {
        fscanf(memoryCard, "%f;%f;%f;%f", &loadedPositionCharacter->x, &loadedPositionCharacter->y, &loadedPositionBox->x, &loadedPositionBox->y);
        fclose(memoryCard);
    } else {
        puts("Ocorreu um erro na leitura do arquivo.");
    }
}
