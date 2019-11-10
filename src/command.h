/* File : command.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef command_H
#define command_H
#include "main.c"

// Main Prosedur untuk command
void COMMAND(Stack *gamestate);

// Prosedur untuk melakukan ATTACK
void ATTACK(Stack *gamestate);

// Prosedur untuk Melakukan LEVEL UP
void LEVEL_UP(Stack *gamestate);

// Prosedur untuk mamakai skill yang sedang dimiliki pemain
void SKILL(Stack *gamestate);

// Prosedur untuk melakukan UNDO
void UNDO(Stack *gamestate);

// Prosedur untuk melakukan END_TURN
void END_TURN(Stack *gamestate);

// Prosedur untuk melakukan SAVE
void SAVE(Stack *gamestate);

// Prosedur untuk melakukan MOVE
void MOVE(Stack *gamestate);

// Prosedur untuk melakukan EXIT Game
void EXIT(Stack *gamestate);

#endif
