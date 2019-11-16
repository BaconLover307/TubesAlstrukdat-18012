/* File : player.c */
/* Implementasi ADT Player */

#include "player.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    // * Handling List Bangunan
    // CreateEmptyList(ListBan(*P));
}

// $ ***** Basic Operators *****


// $ *** Color Handling ***
void SetPlayerWarna(Player *P, Warna C) {
    Color(*P) = C;
}


// $ ***** Skills *****
//void UseSkill(Player) {}



void InstantUpgrade(Player *P, Bangunan *B) {
    /* I.S. Player P terdefinisi dan bangunan B terdefinisi
    /* F.S. Seluruh bangunan yang dimiliki pemain P akan naik 1 level secara instan tanpa perlu ada jumlah tentara M/2
       pada bangunan itu dan tanpa pengurangan jumlah tentara sebanyak M/2 saat kenaikan level*/
    /* Pemain mendapat skill ini hanya saat awal permainan */
    address A;
    
    A = First(ListBan(*P));
    while (Next(A) != Nil) {
        if (Level(ElmtBan(*B, Info(A))) <= 4){
            Level(ElmtBan(*B, Info(A)))++;
        }
        A = Next(A);
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

/*
void ExtraTurn(){
    /* I.S.......
    /* F.S. Setelah end_turn (giliran berkhir), pemain selanjutnya tetap pemain yang sama */
    /* Pemain mendapat skill ini jika Fort pemain direbut lawan */
//}

/*
void AttackUp(Player *P){
    /* I.S.......
    /* F.S. Pada giliran ini, pertahanan bangunan musuh tidak akan mempengaruhi penyerangan */
    /* Pemain mendapat skill ini jika pemain baru saja menyerang tower lawan dan jumlah towernya menjadi 3 */
//}

/*
void CriticalHit(){
    /* I.S.......
    /* F.S. Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan 
       serangan tepat selanjutnya hanya berkurang 1/2 dari jumlah seharusnya*/
    /* Pemain mendapat skill ini jika lawan baru saja mengaktifkan extra turn */

//}
//void InstantReinforcement(Player *P, Bangunan *B) {
    /* I.S. Player P dan Bangunan B terdefinisi
    /* F.S. Seluruh bangunan mendapat tambahan 5 pasukan jika jumlah tentara setelah ditambah tidak melebihi batas maksimum.*/
    /* Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki memiliki level 4 */
    // Kamus Lokal    
/*
    address A;
    // Algoritma
    A = First(ListBan(*P));
    while (Next(A) != Nil){
        if (CheckTambahTentara(ListBan(*P), *B, Info(A))){
            Tentara(ElmtBan(*B, Info(A))) += 5;
        }
        A = Next(A);
    }

 
}
*/
//void Barrage(Player *P, Bangunan *B) {
    /* I.S. Player P dan Bangunan B terdefinisi. 
    /* F.S. Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10. 
       Jika jumlah pasukan >= 10, akan dilakukan pengurangan sebanyak 10, tapi jika jumlah pasukan <1,
       jumlah pasukan menjadi 0 */
    /* Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi 10 */
    // Kamus Lokal
/*    address A;
    // Algoritma
    A = First(ListBan(*P));
    while (Next(A) != Nil){
        if (Tentara(ElmtBan(*B, Info(A))) >= 10){
            Tentara(ElmtBan(*B, Info(A))) -= 10;;
        }

        else{
            Tentara(ElmtBan(*B, Info(A))) = 0;
        }
        A = Next(A);
    }

}

*/