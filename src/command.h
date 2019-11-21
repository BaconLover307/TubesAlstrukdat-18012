/* File : command.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef command_H
#define command_H

#include "boolean.h"
#include "stackt.h"


// Prosedur untuk melakukan ATTACK
void ATTACK(Stack *gamestate, Bangunan *databuild);

// Prosedur untuk Melakukan LEVEL UP
void LEVEL_UP(Stack *gamestate, Bangunan *databuild);

// Prosedur untuk mamakai skill yang sedang dimiliki pemain
void SKILL(Stack *gamestate, Bangunan *databuild);

// Prosedur untuk melakukan UNDO
void UNDO(Stack *gamestate);

// Prosedur untuk melakukan END_TURN
boolean END_TURN(Stack *gamestate);

// Prosedur untuk melakukan MOVE
void MOVE(Stack *gamestate);

// Prosedur untuk melakukan SAVE
void SAVE(Stack *gamestate);

// Prosedur untuk melakukan EXIT Game
boolean EXIT(Stack *gamestate);

#endif
