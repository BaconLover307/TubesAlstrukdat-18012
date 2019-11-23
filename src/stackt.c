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

// $ ************ State Handling ************

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
    
    // * Display Header
    switch (Color(TopP)) {
    case 'R': printf("%s", RED); break;
    case 'G': printf("%s", GREEN); break;
    case 'B': printf("%s", BLUE); break;
    case 'C': printf("%s", CYAN); break;
    case 'M': printf("%s", MAGENTA); break;
    default: printf("%s", NORMAL); break;
    }
    printf("[] ==== ==== ====  Player %d  ==== ==== ==== []\n\n", TurnInfo(top)),
    printf("%s", NORMAL);
    
    // * Display Effects
    printf("   <= Active Effects =>\n");
    printf("<> == <> == <> == <> == <>   [] ===== [] == []\n ");
    if (AU(FX(TopP))) printf(" [AU] ");
    else printf(" [  ] ");

    if (CH(FX(TopP))) printf(" [CH] ");
    else printf(" [  ] ");
    
    if (ActiveSH(SH(FX(TopP)))) printf(" [SH] ");
    else printf(" [  ] ");
    
    if (ET(FX(TopP))) printf(" [ET] ");
    else printf(" [  ] ");
    
    // * Display Skill
    printf("    || SKILL ");
    PrintQueue(Skill(TopP));
    printf("\n");
    printf("<> == <> == <> == <> == <>   [] ===== [] == []\n");
    printf("\n");
    
    // * Display Buildings
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
