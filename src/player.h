/* File : player.h */
/* Definisi ADT Player */

#ifndef player_H
#define player_H

#include "boolean.h"
#include "array.h"
#include "queue.h"
#include "pcolor.h"
#include "listlinier.h"

typedef struct {
    Queue queueSkill;       /* queue penyimpan skill */
    List listBangunan;      /* list penyimpan kepemilikan listbangunan */
    Warna color; 
    boolean extraTurn;
} Player;
//    boolean stateAttack;       /* menyimpan kondisi giliran */
//    address TAIL;    /* alamat penambahan */
//    int MaxEl = 100; /* Max elemen queue */
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

// ! ********* AKSES (Selektor) *********
// $ Jika P adalah Player, maka akses elemen :
#define Color(P) (P).color
#define Skill(P) (P).queueSkill
#define ListBan(P) (P).listBangunan
#define ET(P) (P).extraTurn


// $ ********* Prototype *********

// $ *** Condition Check ***
boolean IsLose(Player P);
// * Mengirim true jika list kepemilikan listbangunan kosong

// $ ***** Creator *****
void CreatePlayer(Player *P);
// * I.S. P terdefinisi
// * F.S. Sebuah P terbentuk dengan karakter listbangunan akan sesuai
// * konfigurasi dan warna listbangunan sesuai yang dipilih

// $ ***** Basic Operators *****

// $ *** Color Handling ***
void SetPlayerWarna(Player *P, Warna C);
// * I.S. Player terdefinisi
// * F.S. Warna listbangunan player akan menjadi C

/* 
void updatelistBangunan(Player *P, listlistBangunan B);
*/


// $ *** Skills ****
void InstantUpgrade(Player *P, Bangunan *B);
// * I.S. Player P terdefinisi dan listbangunan B terdefinisi
// * F.S. Seluruh bangunan yang dimiliki pemain P akan naik 1 level secara instan tanpa perlu ada jumlah tentara M/2
// *    pada listbangunan itu dan tanpa pengurangan jumlah tentara sebanyak M/2 saat kenaikan level*/
// * Pemain mendapat skill ini hanya saat awal permainan


/* PENDING DULU :(
void Shield(Player *P);

void ExtraTurn();

void AttackUp(Player *P);

void CriticalHit();

*/


//void InstantReinforcement(Player *P, listBangunan *B);
/* I.S. Player P dan listBangunan B terdefinisi
/* F.S. Seluruh listbangunan mendapat tambahan 5 pasukan jika jumlah tentara setelah ditambah tidak melebihi batas maksimum.*/
/* Pemain mendapat skill ini di akhir gilirannya bila semua listbangunan yang ia miliki memiliki level 4 */

//void Barrage(Player *P, listBangunan *B);
/* I.S. Player P dan listBangunan B terdefinisi. 
/* F.S. Jumlah pasukan pada seluruh listbangunan musuh akan berkurang sebanyak 10. 
    Jika jumlah pasukan >= 10, akan dilakukan pengurangan sebanyak 10, tapi jika jumlah pasukan <1,
    jumlah pasukan menjadi 0 */
/* Pemain mendapat skill ini jika lawan baru saja bertambah listbangunannya menjadi 10 */



#endif
