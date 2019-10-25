/* File : player.h */
/* Definisi ADT Player */

#ifndef player_H
#define player_H

#include "boolean.h"
//#include "skill.h"
//#include "bangunan.h"
#include "queue.h"
#include "pcolor.h"
#include "listlinier.h"

//#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
//typedef int infotype;
//typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    Queue queueSkill;       /* queue penyimpan skill */
    List listBangunan;      /* list penyimpan kepemilikan bangunan */
    Warna color; 
//    boolean stateAttack;       /* menyimpan kondisi giliran */
//    address TAIL;    /* alamat penambahan */
//    int MaxEl = 100; /* Max elemen queue */
} Player;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Color(P) (P).color
#define Skill(P) (P).queueSkill
#define ListBgn(P) (P).listBangunan
//#define InfoHead(Q) (Q).T[(Q).HEAD]

// $ ********* Prototype *********

// $ *** Condition Check ***
//boolean IsLose(listBangunan B);
// Mengirim true jika list kepemilikan bangunan kosong

// $ ***** Creator *****
void CreatePlayer(Player *P);
/* I.S. P terdefinisi
F.S. Sebuah P terbentuk dengan karakter bangunan akan sesuai
konfigurasi dan warna bangunan sesuai yang dipilih */

// $ ***** Basic Operators *****

// $ *** Color Handling ***
void SetPlayerWarna(Player *P, Warna C);
/* I.S. Player terdefinisi
F.S. Warna bangunan player akan menjadi C */

/* 
void updateBangunan(Player *P, listBangunan B);
*/


// $ *** Skills ****
void InstantUpgrade(Player *P, Bangunan *B);
/* I.S. Player P terdefinisi dan bangunan B terdefinisi
/* F.S. Seluruh bangunan yang dimiliki pemain P akan naik 1 level secara instan tanpa perlu ada jumlah tentara M/2
    pada bangunan itu dan tanpa pengurangan jumlah tentara sebanyak M/2 saat kenaikan level*/
/* Pemain mendapat skill ini hanya saat awal permainan */


/* PENDING DULU :(
void Shield(Player *P);

void ExtraTurn();

void AttackUp(Player *P);

void CriticalHit();

*/


void InstantReinforcement(Player *P, Bangunan *B);
/* I.S. Player P dan Bangunan B terdefinisi
/* F.S. Seluruh bangunan mendapat tambahan 5 pasukan jika jumlah tentara setelah ditambah tidak melebihi batas maksimum.*/
/* Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki memiliki level 4 */

void Barrage(Player *P, Bangunan *B);
/* I.S. Player P dan Bangunan B terdefinisi. 
/* F.S. Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10. 
    Jika jumlah pasukan >= 10, akan dilakukan pengurangan sebanyak 10, tapi jika jumlah pasukan <1,
    jumlah pasukan menjadi 0 */
/* Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi 10 */

#endif
