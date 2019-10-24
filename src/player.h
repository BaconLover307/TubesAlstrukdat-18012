/* File : player.h */
/* Definisi ADT Player */

#ifndef player_H
#define player_H

#include "boolean.h"
//#include "skill.h"
//#include "bangunan.h"
#include "queue.h"
#include "pcolor.h"

//#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
//typedef int infotype;
//typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    Queue queueSkill;       /* queue penyimpan skill */
    //List listBangunan;      /* list penyimpan kepemilikan bangunan */
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
boolean IsLose(listBangunan B);
// Mengirim true jika list kepemilikan bangunan kosong

// $ ***** Creator *****
void CreatePlayer(Player *P, Warna C);
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


#endif