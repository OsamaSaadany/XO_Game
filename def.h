#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>



void drawBoard(uint8_t *board);
void updateBoard (uint8_t *board, uint8_t position, uint8_t value);
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);
void loadAndUpdate(uint8_t playerNumber);
void getGameState(uint8_t *board, uint8_t *gameState);

#endif // DEF_H_INCLUDED
