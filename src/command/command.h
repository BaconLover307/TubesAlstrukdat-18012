/* File : command.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef command_H
#define command_H

#include "../boolean/boolean.h"
#include "../stackt/stackt.h"
#include "../graph/graph.h"
#include "../save/save.h"

boolean ExitMenu; // = false;
boolean EndTurn;  // = false;
boolean AksiValid;

// Prosedur untuk melakukan ATTACK
void ATTACK(Sinfotype *state, Graph relasi);

// Prosedur untuk Melakukan LEVEL UP
void LEVEL_UP(Sinfotype *state);

// Prosedur untuk mamakai skill yang sedang dimiliki pemain
void SKILL(Stack *gamestate, Bangunan *databuild);

// Prosedur untuk melakukan UNDO
void UNDO(Stack *gamestate);

// Prosedur untuk melakukan MOVE
void MOVE(Sinfotype *state, Graph relasi);

// Prosedur untuk melakukan END_TURN
void END_TURN(Stack *gamestate);

// Prosedur untuk melakukan SAVE
void SAVE(Sinfotype *state, Graph relasi, MATRIKS map);

// Prosedur untuk melakukan EXIT Game
void EXIT(Sinfotype *state, Graph relasi, MATRIKS map);

#endif
