/* File : player.c */
/* Implementasi ADT Player */

#include "player.h"
#include <stdio.h>

// $ ********* Prototype *********

// $ *** Condition Check ***
boolean IsLose(listBangunan B) {
    return NBBangunan(B) == 0;
}
// $ ***** Creator *****
void CreatePlayer(Player *P, Warna C) {
    // * Handling Queue Skill
    CreateQueue(Skill(*P));
    Add(Skill(*P),'UI');
    // * Handling List Bangunan
    CreateList(ListBgn(*P));
    // * Handling Warna
    SetPlayerWarna(*P,C);
}

// $ ***** Basic Operators *****

// $ *** Color Handling ***
void SetPlayerWarna(Player *P, Warna C) {
    Warna(*P) = C;
}