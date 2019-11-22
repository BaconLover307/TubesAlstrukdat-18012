/* File : command.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef command_H
#define command_H

#include "boolean.h"
#include "stackt.h"
#include "graph.h"


// Prosedur untuk melakukan ATTACK
void ATTACK(Sinfotype *state, Bangunan *databuild, Graph relasi);

// Prosedur untuk Melakukan LEVEL UP
void LEVEL_UP(Sinfotype *state);

// Prosedur untuk mamakai skill yang sedang dimiliki pemain
void SKILL(Stack *gamestate, Bangunan *databuild);

// Prosedur untuk melakukan UNDO
void UNDO(Stack *gamestate);

// Prosedur untuk melakukan END_TURN
boolean END_TURN(Sinfotype *state);

// Prosedur untuk melakukan MOVE
void MOVE(Sinfotype *state, Bangunan *databuild, Graph relasi);

// Prosedur untuk melakukan SAVE
void SAVE(Sinfotype *state);

// Prosedur untuk melakukan EXIT Game
boolean EXIT(Sinfotype *state);

#endif
