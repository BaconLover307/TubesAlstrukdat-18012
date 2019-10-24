/* File : player.h */
/* Definisi ADT Player */

#ifndef player_H
#define player_H

#include "boolean.h"
#include "skill.h"
#include "bangunan.h"

//#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
//typedef int infotype;
//typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    Skill queueSkill;       /* queue penyimpan skill */
    List listBangunan;      /* list penyimpan kepemilikan bangunan */
    string warna; 
//    boolean stateAttack;       /* menyimpan kondisi giliran */
//    address TAIL;    /* alamat penambahan */
//    int MaxEl = 100; /* Max elemen queue */
} Player;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Warna(P) (P).warna
#define Skill(P) (P).queueSkill
#define 
//#define Tail(Q) (Q).TAIL
//#define InfoHead(Q) (Q).T[(Q).HEAD]
//#define InfoTail(Q) (Q).T[(Q).TAIL]
//#define MaxEl(Q) (Q).MaxEl

// $ ********* Prototype *********
boolean IsLose(listBangunan B);
// Mengirim true jika list kosong

boolean IsFull(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

// $ *** Kreator ***
void CreatePlayer(Player *P, warna C);
/* I.S. P terdefinisi */
/* F.S. Sebuah P terbentuk dengan karakter bangunan akan sesuai yan salah satu kondisi sbb: */
/* warna yang telah dipilih */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */

// $ *** Primitif ***
void updateBangunan (Player *P, listBangunan B);


#endif