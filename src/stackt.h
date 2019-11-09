/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "player.h"
#include "array.h"
#include "queue.h"
#include "matriks.h"
#include "listlinier.h"

#define SNil 0
#define MaxSEl 10000
/* SNil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int Saddress;   /* indeks tabel */
typedef struct {
    Player pemain1;
    Player pemain2;
    int turn;
} Sinfotype;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  Sinfotype T[MaxSEl+1]; /* tabel penyimpan elemen */
  Saddress TOP;  /* alamat TOP: elemen puncak */
  Sinfotype init; /* kondisi paling awal yang tidak bisa diundo */
} Stack;
/* Definisi stack S kosong : S.TOP = SNil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxSEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Init(S) (S).init
#define P1Info(I) (I).pemain1
#define P2Info(I) (I).pemain2
#define TurnInfo(I) (I).turn

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxSEl */
/* jadi indeksnya antara 1.. MaxSEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP Sbernilai SNil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Sinfotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, Sinfotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void ChangeTurn (Stack *S);
// Mengganti giliran
// I.S. sembarang
// F.S. Stack state menjadi kosong, turn berubah
#endif