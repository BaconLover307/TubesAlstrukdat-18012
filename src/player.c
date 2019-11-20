/* File : player.c */
/* Implementasi ADT Player */

#include "player.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
? typedef struct {
*    boolean attackUp;
*    boolean criticalHit;
*    boolean shield;
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
*/

// $ ********* Prototype *********

// $ *** Condition Check ***

boolean IsLose(Player P) {
    return IsEmptyList(ListBan(P));
}

// $ ***** Creator *****
void CreatePlayer(Player *P) {
    // * Handling Queue Skill
    CreateQueue(&Skill(*P),10);
    QAdd(&Skill(*P),"IU");
    // * Handling Status Effect
    AU(FX(*P)) = false;
    CH(FX(*P)) = false;
    SH(FX(*P)) = false;
    ET(FX(*P)) = false;
    // * Handling List Bangunan
    CreateEmptyList(&ListBan(*P));
}

// $ ***** Basic Operators *****


// $ *** Color Handling ***
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

// $ ***** Skills *****

// $ *** Use Skill ***

void InstantUpgrade(Player *P, Bangunan *B) {
    // $ Kamus Lokal
    address A;
    // $ Algoritma
    
    A = First(ListBan(*P));
    while (Next(A) != Nil) {
        if (Level(ElmtBan(*B, Info(A))) < 4){
            Level(ElmtBan(*B, Info(A)))++;
        }
        A = Next(A);
    }

    if (Level(ElmtBan(*B, Info(A))) <= 4){
            Level(ElmtBan(*B, Info(A)))++;
        }
}
/*
*/
/*
void Shield(Player *P) {
    /* I.S.
    /* F.S. Seluruh bangunan yang dimiliki pemain akan memiliki pertahanan selama 2 turn */
    /* Pemain mendapat skill ini jika sebuah lawan menyerang, bangunan pemain berkurang 1, menjadi sisa 2 */
//}


void ExtraTurn(Player *P) {
    ET(FX(*P)) = true;
}

/*
void AttackUp(Player *P){
    /* I.S.......
    /* F.S. Pada giliran ini, pertahanan bangunan musuh tidak akan mempengaruhi penyerangan */
    /* Pemain mendapat skill ini jika pemain baru saja menyerang tower lawan dan jumlah towernya menjadi 3 */
//}

/* */
void CriticalHit() {
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

void Barrage(Player *P, Bangunan *B) {
    // $ Kamus Lokal
    address A;
    // $ Algoritma
    A = First(ListBan(*P));
    while (Next(A) != Nil){
        if (Tentara(ElmtBan(*B, Info(A))) >= 10){
            Tentara(ElmtBan(*B, Info(A))) -= 10;
        }

        else{
            Tentara(ElmtBan(*B, Info(A))) = 0;
        }
        A = Next(A);
    }

    if (Tentara(ElmtBan(*B, Info(A))) >= 10){
            Tentara(ElmtBan(*B, Info(A))) -= 10;
        }

        else{
            Tentara(ElmtBan(*B, Info(A))) = 0;
        }

}

// $ *** Detect Skill ***

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

void GetCH(Queue *Q) {
    QAdd(Q, "CH");
}