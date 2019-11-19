/* Program          : stackt_driver.c */
/* Deskripsi        : Driver Stackt */

#include "stackt.h"
#include <stdio.h>

// $ Kamus
Player P1, P2;
int Turn;

// $ Algo
// $ ************ Prototype ************
// $ *** Konstruktor/Kreator ***

void StartTurn(Stack *S, Player P1, Player P2, int Turn) {
    Top(*S) = SNil;
    P1Info(Curr(*S)) = P1;
    P2Info(Curr(*S)) = P2;
    TurnInfo(Curr(*S)) = Turn;
}

// $ ************ Predikat Untuk test keadaan KOLEKSI ************
boolean IsFirstAct(Stack S)
{
    return (Top(S) == SNil);
}

boolean IsFull(Stack S)
{
    return (Top(S) == MaxSEl);
}

// $ ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, Sinfotype X)
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}

// $ ************ Menghapus sebuah elemen Stack ************
void Pop(Stack *S, Sinfotype *X)
{
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

// $ ************ Turn Handling ************

Player GetCurrPlayer(Stack S)
{
    if (TurnInfo(Curr(S)) == 1)
    {
        return (P1Info(Curr(S)));
    }
    else if (TurnInfo(Curr(S)) == 2)
    {
        return (P2Info(Curr(S)));
    }
}

void ChangeTurn(Stack *S)
{
    // $ Kamus Lokal
    Sinfotype LastState;
    // $ Algoritma
    Pop(S, &LastState);
    if (!ET(P1Info(LastState)) && !ET(P2Info(LastState)))
    {
        TurnInfo(LastState) = TurnInfo(LastState) % 2 + 1;
    }
    StartTurn(S, P1Info(LastState), P2Info(LastState), TurnInfo(LastState));
}
