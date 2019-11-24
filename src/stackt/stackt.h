/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "../boolean/boolean.h"
#include "../player/player.h"
#include "../matriks/matriks.h"
#include "../pcolor/pcolor.h"

#define SNil 0
#define MaxSEl 100
/* SNil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int Saddress;   /* indeks tabel */
typedef struct {
    Player pemain1;
    Player pemain2;
    int turn;
    Bangunan databuild;
} Sinfotype;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  Sinfotype T[MaxSEl+1]; /* tabel penyimpan elemen */
  Saddress TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = SNil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxSEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

// $ ********* AKSES (Selektor) *********
// $ Jika S adalah Stack dan I adalah Infotype, maka akses elemen :
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
//#define Curr(S) (S).curr

#define P1Info(I) (I).pemain1
#define P2Info(I) (I).pemain2
#define TurnInfo(I) (I).turn
#define DataB(I) (I).databuild

// $ ************ Prototype ************ */
// $ *** Konstruktor/Kreator *** */


// $ ************ Predikat Untuk test keadaan KOLEKSI ************

void EmptyState(Sinfotype * S);

// * I.S. sembarang
// * F.S. Membuat sebuah stack S yang kosong berkapasitas MaxSEl
// * Memulai turn
void StartTurn(Stack *S, Player P1, Player P2, int Turn, Bangunan DataBuild);

// * I.S. Stack terdefinisi, mungkin kosong
// * F.S. Menghabiskan isi sebuah stack S, dan mengisinya dengan InfoTop saat
// *      sebelum dihabisi
void ResetStack(Stack *S);

// $ ************ Predikat Untuk test keadaan KOLEKSI ************

// * Mengirim true jika gamestate paling awal
boolean IsFirstAct(Stack S);

// * Mengirim true jika stack kosong
boolean IsEmptyStack(Stack S);

// * Mengirim true jika tabel penampung Snilai elemen stack penuh
boolean IsFull(Stack S);

// $ ************ Menambahkan sebuah elemen ke Stack ************

// * Menambahkan X sebagai elemen Stack S.
// * I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
// * F.S. X menjadi TOP yang baru,TOP bertambah 1
void Push(Stack *S, Sinfotype X);

// $ ************ Menghapus sebuah elemen Stack ************

// * Menghapus X dari Stack S.
// * I.S. S  tidak mungkin kosong
// * F.S. X adalah Snilai elemen TOP yang lama, TOP berkurang 1
void Pop(Stack *S, Sinfotype *X);

// $ ************ State Handling ************

// * Mereset status bangunan yang sudah MOVE atau ATTACK
void ResetBuildingStatus(List L, Bangunan *B);

// * Memeriksa apakah semua bangunan di List L telah MOVE
// * Mengirimkan true jika semua sudah MOVE
boolean CheckAllMoved(List L, Bangunan B);

// * Memeriksa apakah semua bangunan di List L telah ATTACK
// * Mengirimkan true jika semua sudah ATTACK
boolean CheckAllAttacked(List L, Bangunan B);

// * Menuliskan kondisi yang sedang berlangsung
void PrintCondition(Sinfotype top);

// * S terdefinisi, mengembalikan isi state S
Sinfotype CopyState(Sinfotype S);

#endif
