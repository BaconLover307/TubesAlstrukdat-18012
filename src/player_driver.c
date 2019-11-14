#include "stackt.h"
#include "command.h"
#include <stdio.h>
#include <stdlib.h>

// $ Kamus
Player P1,P2;
char color1,color2;
Stack S;
int T = 1;

int main(){
    CreatePlayer(&P1);
    CreatePlayer(&P2);
    StartTurn(&S,P1,P2,T);
    /*
    printf("Tuliskan warnamu: ");
    scanf("%c",&color1);
    SetPlayerWarna(&P1,color1);
    print_warna(Color(P1),'M');
    printf("\n");
    */
    char skil[2];
    //COMMAND(&S);
    //printf("pass\n");
    //PrintInfoHead(Skill(P2Info(Curr(S))));
    //printf("\npass\n");
    SKILL(&S);
    //Player Test = GetCurrPlayer(S);
    //PrintInfoHead(Skill(Test));
    //strcpy(skil,InfoTail(Skill(P1)));
    //printf("Skill player: %s",skil);
    //getchar();
}
