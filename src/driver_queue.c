#include "player.h"
#include "pcolor.h"
#include "string.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// $ Kamus
Player P1,P2;
char color1,color2;

int main(){
    CreatePlayer(&P1);

    char skil [10];
    char temp [10];

    PrintInfoHead(Skill(P1));
    getchar();

    QAdd(&Skill(P1), "B");
    PrintInfoHead(Skill(P1));
    getchar();

    QDel(&Skill(P1), &temp);
    PrintInfoHead(Skill(P1));
    getchar();

    QDel(&Skill(P1), &temp);
    PrintInfoHead(Skill(P1));
    getchar();

    QAdd(&Skill(P1), "AB");
    QAdd(&Skill(P1), "BC");
    QAdd(&Skill(P1), "CD");
    PrintQueue(Skill(P1));

    
}
