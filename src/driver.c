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
    Qinfotype buangSkill;
    Player CurrP = GetCurrPlayer(S);
    Queue Qcoba1,Qcoba2;
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
    //SKILL(&S);
    //PrintQueue(Skill(P1Info(Curr(S))));
    printf("==========\n");
    CreateQueue(&Qcoba1,10);
    CreateQueue(&Qcoba2,10);
    QAdd(&Qcoba1,"A");
    QAdd(&Qcoba1,"B");
    QAdd(&Qcoba1,"C");
    QAdd(&Qcoba1,"D");
    QAdd(&Qcoba2,"C");
    QAdd(&Qcoba2,"D");
    PrintQueue(Qcoba1); printf("\n");
    PrintQueue(Qcoba2); printf("\n");
    ReplaceQueue(Qcoba1,&Qcoba2);
    PrintQueue(Qcoba2);
    printf("\n");
    printf("==========\n");
    PrintCurr(S);
    PrintQueue(Skill(GetCurrPlayer(S))); printf("\n");
    SKILL(&S);
    PrintQueue(Skill(GetCurrPlayer(S))); printf("\n");
    SKILL(&S);
    PrintQueue(Skill(GetCurrPlayer(S))); printf("\n");
    printf("==========\n");
    //PrintQueue(Skill(P2Info(Curr(S))));
    //Player Test = GetCurrPlayer(S);
    //PrintInfoHead(Skill(Test));
    //strcpy(skil,InfoTail(Skill(P1)));
    //printf("Skill player: %s",skil);
    //getchar();
}
