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
    /*
    printf("Tuliskan warnamu: ");
    scanf("%c",&color1);
    SetPlayerWarna(&P1,color1);
    print_warna(Color(P1),'M');
    printf("\n");
    */
    char skil[2];
    strcpy(skil,InfoTail(Skill(P1)));
    printf("Skill player: %s",skil);
    getchar();
}
