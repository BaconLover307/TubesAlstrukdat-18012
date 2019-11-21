/* Program          : stackt.c */
/* Deskripsi        : Implementasi Stackt */
/* Definisi Stack   : Model Implementasi dengan tabel kontigu dan ukuran sama */

#include "stackt.h"
#include "string.h"
#include <stdio.h>

// $ ************ Prototype ************
// $ *** Konstruktor/Kreator ***
void StartTurn(Stack *S, Player P1, Player P2, int Turn) {
    Top(*S) = SNil;
    P1Info(Curr(*S)) = P1;
    P2Info(Curr(*S)) = P2;
    TurnInfo(Curr(*S)) = Turn;
}
void ClearStack(Stack *S) {
    Sinfotype temp;
    while(!IsFirstAct(*S)) {
        Pop(S,&temp);
    }
}

// $ ************ Predikat Untuk test keadaan KOLEKSI ************
boolean IsFirstAct(Stack S) {
    return (Top(S) == SNil);
}

boolean IsFull(Stack S) {
    return (Top(S) == MaxSEl);
}

// $ ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, Sinfotype X) {
    Top(*S) += 1;
    InfoTop(*S) = X;
}

// $ ************ Menghapus sebuah elemen Stack ************
void Pop(Stack *S, Sinfotype *X) {
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

// $ ************ Turn Handling ************

Player GetCurrPlayer(Stack S) {
    if (TurnInfo(Curr(S)) == 1) {
        return (P1Info(Curr(S)));
    } else if (TurnInfo(Curr(S)) == 2) {
        return (P2Info(Curr(S)));
    }
}

void ChangeTurn(Stack *S, Bangunan *B) {
    // $ Kamus Lokal
    Player *CurrP, *EnemyP;
    List *Lcurr, *Lenemy;
    if (TurnInfo(Curr(*S)) == 1) {
        CurrP = &P1Info(Curr(*S));
        EnemyP = &P2Info(Curr(*S));
    } else {
        CurrP = &P2Info(Curr(*S));
        EnemyP = &P1Info(Curr(*S));
    }
    Lcurr = &ListBan(*CurrP);
    Lenemy = &ListBan(*EnemyP);
    // $ Algoritma
    if (!ET(FX(*CurrP))) {
        TurnInfo(Curr(*S)) = TurnInfo(Curr(*S)) % 2 + 1;
        //printf("Changing turns"); sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf("\n\n");
    }
    // ! Reset FX Extra Turn
    ET(FX(*CurrP)) = false;
    // ! Reset FX Attack Up
    AU(FX(*CurrP)) = false;
    // ! Reduce Shield
    ReduceDurationSH(EnemyP);
    // * Clear Stack
    ClearStack(S);
}

void PrintCurr(Stack S) {
    // $ Kamus Lokal
    Player CurrP = GetCurrPlayer(S);
    // $ Algoritma
    printf("[] ==== ==== ====  Player %d  ==== ==== ==== []\n\n", TurnInfo(Curr(S))),
    //printbuilding
    printf("  <= Active Effects =>\n");
    printf("<> == <> == <> == <> == <>   [] ===== [] == []\n ");
    if (AU(FX(CurrP))) printf(" [AU] "); else printf(" [  ] ");
    if (CH(FX(CurrP))) printf(" [CH] "); else printf(" [  ] ");
    if (ActiveSH(SH(FX(CurrP)))) printf(" [SH] "); else printf(" [  ] ");
    if (ET(FX(CurrP))) printf(" [ET] "); else printf(" [  ] ");
    printf("    || SKILL ");
    PrintQueue(Skill(CurrP));
    printf("\n");
    printf("<> == <> == <> == <> == <>   [] ===== [] == []\n");
    printf("\n");
}
