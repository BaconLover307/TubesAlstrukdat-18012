/* File : player.c */
/* Implementasi ADT Player */

#include "player.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

// $ ********* Prototype *********

// $ *** Condition Check ***
/*
boolean IsLose(listBangunan B) {
    return NBBangunan(B) == 0;
}
*/
// $ ***** Creator *****
void CreatePlayer(Player *P) {
    // * Handling Queue Skill
    CreateQueue(&Skill(*P),1000);
    char skill[2];
    skill[0] = 'U';
    skill[1] = 'I';
    QAdd(&Skill(*P),skill);
    // * Handling List Bangunan
    //CreateList(ListBgn(*P));
}

// $ ***** Basic Operators *****

// $ *** Color Handling ***
void SetPlayerWarna(Player *P, Warna C) {
    Color(*P) = C;
}