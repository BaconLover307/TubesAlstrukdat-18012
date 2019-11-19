/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "player.h"
#include "matriks.h"

#define SNil 0
#define MaxSEl 100
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
  Sinfotype curr; /* turn yang sedang berlangsung */
} Stack;
/* Definisi stack S kosong : S.TOP = SNil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxSEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

// $ ********* AKSES (Selektor) *********
// $ Jika S adalah Stack dan I adalah Infotop, maka akses elemen :
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Curr(S) (S).curr
#define P1Info(I) (I).pemain1
#define P2Info(I) (I).pemain2
#define TurnInfo(I) (I).turn

// $ ************ Prototype ************ */
// $ *** Konstruktor/Kreator *** */


// $ ************ Predikat Untuk test keadaan KOLEKSI ************
void StartTurn(Stack *S, Player P1, Player P2, int Turn);
// * I.S. sembarang
// * F.S. Membuat sebuah stack S yang kosong berkapasitas MaxSEl
// * Memulai turn

void ClearStack(Stack *S);
// * I.S. Stack terdefinisi, mungkin kosong
// * F.S. Menghabiskan isi sebuah stack S

// $ ************ Predikat Untuk test keadaan KOLEKSI ************
boolean IsFirstAct(Stack S);
// * Mengirim true jika gamestate paling awal
boolean IsFull(Stack S);
// * Mengirim true jika tabel penampung Snilai elemen stack penuh

// $ ************ Menambahkan sebuah elemen ke Stack ************
void Push(Stack *S, Sinfotype X);
// * Menambahkan X sebagai elemen Stack S.
// * I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
// * F.S. X menjadi TOP yang baru,TOP bertambah 1

// $ ************ Menghapus sebuah elemen Stack ************
void Pop(Stack *S, Sinfotype *X);
// * Menghapus X dari Stack S.
// * I.S. S  tidak mungkin kosong
// * F.S. X adalah Snilai elemen TOP yang lama, TOP berkurang 1

// $ ************ Turn Handling ************
Player GetCurrPlayer(Stack S);
// * Mengembalikan Player yang sedang berjalan turn-nya

void ChangeTurn(Stack *S);
// * Mengganti giliran pemain
// * I.S. Game sedang berlangsung
// * F.S. Jika salah satu pemain memiliki skill Extra Turn, maka giliran
// * tidak berubah. Jika tidak, maka giliran akan berubah

void PrintCurr(Stack S);
// * Menuliskan kondisi yang sedang berlangsung

#endif