/* Program          : stackt.c */
/* Deskripsi        : Implementasi Stackt */
/* Definisi Stack   : Model Implementasi dengan tabel kontigu dan ukuran sama */

#include "stackt.h"
#include "string.h"
#include <stdio.h>

// $ ************ Prototype ************
// $ *** Konstruktor/Kreator ***
void StartTurn(Stack *S, Player P1, Player P2, int Turn, Bangunan DataBuild) {
    Top(*S) = 1;
    P1Info(InfoTop(*S)) = P1;
    P2Info(InfoTop(*S)) = P2;
    TurnInfo(InfoTop(*S)) = Turn;
    DataB(InfoTop(*S)) = CopyBangunan(DataBuild);
}
void ResetStack(Stack *S) {
    Sinfotype temp, buang;
    Pop(S,&temp);
    while(!IsEmptyStack(*S)) {
        Pop(S,&buang);
    }
    Push(S,temp);
}

// $ ************ Predikat Untuk test keadaan KOLEKSI ************
boolean IsFirstAct(Stack S) {
    return ((Top(S) - 1) == SNil);
}

boolean IsEmptyStack(Stack S) {
    return (Top(S) == SNil);
}

boolean IsFull(Stack S) {
    return (Top(S) == MaxSEl);
}

// $ ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, Sinfotype X) {
    Top(*S)++;
    InfoTop(*S) = CopyState(X);
}

// $ ************ Menghapus sebuah elemen Stack ************
void Pop(Stack *S, Sinfotype *X) {
    *X = CopyState(InfoTop(*S));
    Top(*S)--;
}

// $ ************ Turn Handling ************

Player GetTopPlayer(Stack S) {
    if (TurnInfo(InfoTop(S)) == 1) {
        return (P1Info(InfoTop(S)));
    } else if (TurnInfo(InfoTop(S)) == 2) {
        return (P2Info(InfoTop(S)));
    }
}

void ChangeTurn(Stack *S) {
    // $ Kamus Lokal
    Player *TopP, *EnemyP;
    List *Ltop, *Lenemy;
    Sinfotype Temp;
    if (TurnInfo(InfoTop(*S)) == 1) {
        TopP = &P1Info(InfoTop(*S));
        EnemyP = &P2Info(InfoTop(*S));
    } else {
        TopP = &P2Info(InfoTop(*S));
        EnemyP = &P1Info(InfoTop(*S));
    }
    Ltop = &ListBan(*TopP);
    Lenemy = &ListBan(*EnemyP);
    // $ Algoritma
    if (!ET(FX(*TopP))) {
        TurnInfo(InfoTop(*S)) = TurnInfo(InfoTop(*S)) % 2 + 1;
        //printf("Changing turns"); sleep(0.3);printf(".");sleep(0.3);printf(".");sleep(0.3);printf("\n\n");
    }
    ResetStack(S);

    // ! Reset FX Extra Turn
    ET(FX(*TopP)) = false;
    // ! Reset FX Attack Up
    AU(FX(*TopP)) = false;
    // ! Reduce Shield
    ResetBuildingStatus(*Ltop, &DataB(InfoTop(*S)));
    ReduceDurationSH(EnemyP);
    // * Clear Stack
}

void ResetBuildingStatus(List L, Bangunan *B) {
    // $ Kamus Lokal
    address P = First(L);
    // $ Algoritma
    while (P != Nil) {
        Moved(ElmtBan(*B,Info(P))) = false;
        Attacked(ElmtBan(*B,Info(P))) = false;
        P = Next(P);
    }
}

boolean CheckAllMoved(List L, Bangunan B) {
    // $ Kamus Lokal
    address P = First(L);
    // $ Algoritma
    while (P != Nil) {
        if (Moved(ElmtBan(B,Info(P))) == false)
            return false;
        P = Next(P);
    }
    return true;
}

boolean CheckAllAttacked(List L, Bangunan B) {
    // $ Kamus Lokal
    address P = First(L);
    // $ Algoritma
    while (P != Nil) {
        if (Attacked(ElmtBan(B,Info(P))) == false)
            return false;

        P = Next(P);
    }
    return true;
}


void PrintCondition(Sinfotype top) {
    // $ Kamus Lokal
    Player TopP;
    if (TurnInfo(top) == 1) {
        TopP = P1Info(top);
    } else {
        TopP = P2Info(top);
    }
    Bangunan DataBuild = DataB(top);
    List Ltop = ListBan(TopP);
    // $ Algoritma
    printf("[] ==== ==== ====  Player %d  ==== ==== ==== []\n\n", TurnInfo(top)),
    printf("   <= Active Effects =>\n");
    printf("<> == <> == <> == <> == <>   [] ===== [] == []\n ");
    if (AU(FX(TopP)))
        printf(" [AU] ");
    else
        printf(" [  ] ");
    if (CH(FX(TopP)))
        printf(" [CH] ");
    else
        printf(" [  ] ");
    if (ActiveSH(SH(FX(TopP))))
        printf(" [SH] ");
    else
        printf(" [  ] ");
    if (ET(FX(TopP)))
        printf(" [ET] ");
    else
        printf(" [  ] ");
    printf("    || SKILL ");
    PrintQueue(Skill(TopP));
    printf("\n");
    printf("<> == <> == <> == <> == <>   [] ===== [] == []\n");
    printf("\n");
    printf(" __\n[__] ==== List of Buildings ==== [P%d]\n", TurnInfo(top));
    PrintInfo(Ltop, DataBuild);
    printf("\n");
}

Sinfotype CopyState(Sinfotype S) {
    Sinfotype ret;
    P1Info(ret) = CopyPlayer(P1Info(S));
    P2Info(ret) = CopyPlayer(P2Info(S));
    TurnInfo(ret) = TurnInfo(S);
    DataB(ret) = CopyBangunan(DataB(S));
    return ret;
}
