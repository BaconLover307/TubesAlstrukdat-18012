/* File : player.c */
/* Implementasi ADT Player */

#include "player.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
? typedef struct {
*    int duration;       Durasi (turn) efektif Shield, max 2 turn lawan
*    boolean activeSH;   True jika durasi > 0
? } ShieldFX;

? typedef struct {
*    boolean attackUp;
*    boolean criticalHit;
*    ShieldFX shield;
*    boolean extraTurn;
? } StatusEffect;

? typedef struct {
*    Queue queueSkill;      queue penyimpan skill
*    List listBangunan;     list penyimpan kepemilikan listbangunan
*    Warna color;           warna bangunan pemain
*    StatusEffect FX;       skill-skill pemain yang sedang aktif
? } Player;

! ********* AKSES (Selektor) *********
? Jika P adalah Player, maka akses elemen :
* #define Color(P) (P).color
* #define Skill(P) (P).queueSkill
* #define ListBan(P) (P).listBangunan
* #define ET(P) (P).extraTurn

? Jika F adalah FX, maka akses elemen :
* #define AU(F) (F).attackUp
* #define CH(F) (F).criticalHit
* #define SH(F) (F).shield
* #define ET(F) (F).extraTurn

? Jika SH adalah shield, maka akses elemen :
* #define ActiveSH(SH) (SH).activeSH
* #define Duration(SH) (SH).duration
*/


// $ ******************* Prototype *******************

// $ ************* Condition Check *************

boolean IsLose(Player P) {
    return IsEmptyList(ListBan(P));
}

// $ *************** Creator ***************
void CreatePlayer(Player *P) {
    // * Handling Queue Skill
    CreateQueue(&Skill(*P),10);
    CheckGetIU(&Skill(*P));
    // * Handling Status Effect
    AU(FX(*P)) = false;
    CH(FX(*P)) = false;
    Duration(SH(FX(*P))) = 0;
    ActiveSH(SH(FX(*P))) = false;
    ET(FX(*P)) = false;
    // * Handling List Bangunan
    CreateEmptyList(&ListBan(*P));
    // * Handling Warna Default, Normal
    LoadPlayerWarna(P,'X');
}

// $ ************* Fungsi Untuk FX Shield *************
boolean IsSHWornOut(Player P) {
    return Duration(SH(FX(P))) == 0;
}

boolean IsSHMax(Player P) {
    return Duration(SH(FX(P))) == 2;
}
void CheckActive(Player *P) {
    ActiveSH(SH(FX(*P))) = (Duration(SH(FX(*P))) > 0);
}

void ReduceDurationSH(Player *P) {
    if (!IsSHWornOut(*P)) {
        Duration(SH(FX(*P))) -= 1;
    }
    CheckActive(P);
}

// $ *************** Basic Operators ***************

// $ ************* Color Handling *************
void LoadPlayerWarna(Player *P, Warna C) {
    Color(*P) = C;
}

void SetPlayerWarna(Player *P, TabColor * Palet) {
    // $ Kamus Lokal
    boolean Found = false;
    int i;

    // $ Algoritma
    PrintBukuWarna(*Palet);
    printf("\n");
    printf("Choose your color: ");
    do {
        scanf(" %c", &Color(*P));
        i = 1;
        while (i<=ColNeff(*Palet) && !Found) {
            if (ColElmt(*Palet,i) == Color(*P) && Color(*P)!='_') Found = true;
            i++;
        }
        if (!Found) {
            printf("Please choose an available color from the pallete!\n");
            PrintBukuWarna(*Palet);
            printf("\n");
            printf("Choose your color: ");
        }
    } while (!Found);
    ColElmt(*Palet,i-1) = '_';
}

// $ *************** Skills ***************

// $ ************* Use Skill *************

void InstantUpgrade(Player *P, Bangunan *B) {
    // $ Kamus Lokal
    address A;
    // $ Algoritma
    
    A = First(ListBan(*P));
    while (Next(A) != Nil) {
        if (Level(ElmtBan(*B, Info(A))) < 4) {
            Level(ElmtBan(*B, Info(A)))++;
        }
        A = Next(A);
    }
    if (Level(ElmtBan(*B, Info(A))) <= 4){
            Level(ElmtBan(*B, Info(A)))++;
        }
}

void Shield(Player *P) {
    Duration(SH(FX(*P))) = 2;
    ActiveSH(SH(FX(*P))) = true;
}

void ExtraTurn(Player *P) {
    ET(FX(*P)) = true;
}

void AttackUp(Player *P) {
    AU(FX(*P)) = true;
}

void CriticalHit(Player *P) {
    CH(FX(*P)) = true;
}

void InstantReinforcement(Player *P, Bangunan *B) {
    // $ Kamus Lokal    
    address A;
    // $ Algoritma
    A = First(ListBan(*P));
    while (Next(A) != Nil){
        Tentara(ElmtBan(*B, Info(A))) += 5;
        A = Next(A);
    }
    Tentara(ElmtBan(*B, Info(A))) += 5;
}

void Barrage(Player *P, Player *E, Bangunan *B) {
    // $ Kamus Lokal
    address A;
    // $ Algoritma
    A = First(ListBan(*E));
    while (Next(A) != Nil){
        if (Tentara(ElmtBan(*B, Info(A))) > 10){
            Tentara(ElmtBan(*B, Info(A))) -= 10;
        }

        else{
            Tentara(ElmtBan(*B, Info(A))) = 0;
            capture(&ListBan(*P), &ListBan(*E), A);       
        }
        A = Next(A);
    }

    if (Tentara(ElmtBan(*B, Info(A))) > 10){
            Tentara(ElmtBan(*B, Info(A))) -= 10;
        }

        else{
            Tentara(ElmtBan(*B, Info(A))) = 0;
            capture(&ListBan(*P), &ListBan(*E), A);
        }

}

// $ ************* Detect Skill *************

void CheckGetIU(Queue *Q) {
    QAdd(Q, "IU");
}

void CheckGetSH(Player P, Queue *Q) {
    if (NbElmtList(ListBan(P)) == 2) 
    QAdd(Q, "SH");
}

void CheckGetET(Queue *Q) {
    QAdd(Q, "ET");
}

void CheckGetAU(Player P, Queue *Q, Bangunan databuild) {
    // $ KAMUS LOKAL
    address Adr;
    int totalT;
    List L = ListBan(P);

    // $ ALGORITMA
    if (!IsEmptyList(L)) {
        Adr = First(L);
        totalT = 0;
        while (Adr != Nil) {
            if (Name(ElmtBan(databuild,Info(Adr))) == "T")
            totalT++;
            Adr = Next(Adr);
        }
    }
    if (totalT == 3) QAdd(Q, "AU");
}


void CheckGetCH(Queue *Q) {
    QAdd(Q, "CH");
}

void CheckGetIR(Player *P, Bangunan *B) {
    // Kamus Lokal
    boolean get;
    address A;
    // Algoritma
    get = true;
    A = First(ListBan(*P));
    while (Next(A) != Nil && get) {
        if (Level(ElmtBan(*B, Info(A))) != 4){
            get = false;
        }
        A = Next(A);
    }
    if (Level(ElmtBan(*B, Info(A))) != 4){
        get = false;
    }

    if (get == true){
        QAdd(&Skill(*P), "IR");
    }
}

void CheckGetBA(Player P, Queue *Q) {
    if (NbElmtList(ListBan(P)) == 10)
    QAdd(Q, "BA");
}
