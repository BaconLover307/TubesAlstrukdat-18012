/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File header: array.h */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "point.h"

/*  Kamus Umum */
#define IdxMax 29
/* Indeks maksimum array */
#define IdxMin 1
/* Indeks minimum array */
#define CharUndef 'Z'
/* Nama Bangunan yang tidak terdefinisi */
#define ValUndef 0 // ! Untuk Relate (sementara)
/* Nilai elemen tak terdefinisi */

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */ // ! Untuk Relate (sementara)

typedef struct {
  ElType RI[IdxMax + 1]; /* memori tempat penyimpanan elemen (container) */
} RELATE; /* class yang menyimpan dengan hubungan bangunan ke-berapa aja */
// ! Ini untuk sementara doang

typedef struct {
  char name; /* tipe bangunan */
  POINT posisi; /* posisi bangunan */
  int level; /* level bangunan */
  RELATE hubungan; /* hubungan dengan bangunan ke-berapa */ // ! Sementara doang
  int tentara; /* jumlah tentara yang dimiliki bangunan */
} info_bangunan;

typedef struct {
  info_bangunan BI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
} Bangunan;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika B adalah Bangunan, cara deklarasi dan akses: */
/* Deklarasi : B : Bangunan */
/* Maka cara akses:
   B.BI    untuk mengakses seluruh nilai elemen tabel
   B.BI[i] untuk mengakses elemen ke-i */
/* Definisi :
   Definisi elemen pertama : B.BI[i] dengan i=1
   Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
/* B adalah Bangunan      */
/* e adalah info_bangunan */
/* R adalah Relate        */
#define BI(B)         (B).BI
#define ElmtBan(B,i)  (B).BI[(i)]

#define Name(e)       (e).name
#define Posisi(e)     (e).posisi
#define Level(e)      (e).level
#define Relate(e)     (e).hubungan
#define Tentara(e)    (e).tentara

#define RI(R)         (R).RI
#define ElmtRel(R,i)  (R).RI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBangunan (Bangunan * B);
/* I.S. B sembarang */
/* F.S. Terbentuk tabel B kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua nama elemen tabel B dengan charUndef */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtBan (Bangunan B);
/* Mengirimkan banyaknya elemen efektif tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstBan (Bangunan B);
/* Prekondisi : Tabel B tidak kosong */
/* Mengirimkan indeks elemen B pertama */
IdxType GetLastBan (Bangunan B);
/* Prekondisi : Tabel B tidak kosong */
/* Mengirimkan indeks elemen B terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyBan (Bangunan B);
/* Mengirimkan true jika tabel B kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullBan (Bangunan B);
// ? Entah perlu fungsi ini gak ya?  
/* Mengirimkan true jika tabel B penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaBangunan (Bangunan * B);
/* I.S. B sembarang */
/* F.S. Tabel B terdefinisi */
/* Proses : membaca banyaknya elemen B dan mengisi semua nilainya dengan Mesin Kata */
// Todo Menunggu yang kerjain Configure 

/*********************** Tentara Attack ****************************/
boolean CheckAttackTentara (Bangunan B, IdxType X, int N);
/* Mengecek apakah bangunan ke-X memiliki jumlah tentara yang >= N */
/* Jika iya maka True dan sebaliknya */

void TentaraAttack (Bangunan * B, IdxType X, int N);
/* I.S. Bangunan B terdefinisi
        X pasti ada di dalam List 
        Jumlah N pasti normal (sudah dicek pakai CheckAttackTentara) */
/* F.S. Bangunan ke-X mengalami pengurangan jumlah tentara sebesar N */        

/*********************** Tentara Invaded **************************/
void TentaraInvaded (Bangunan * B, IdxType i, int N);
/* I.S. Bangunan B terdefinisi 
        i pasti ada di dalam indeks bangunan B */
/* F.S. Bangunan ke-i mengalami penurunan jumlah tentara sebesar N (mungkin minus) */

boolean CanCapture (Bangunan B, IdxType i);
/* Mengecek apakah Bangunan ke-i memiliki jumlah tentara yang <= 0 */
/* Jika iya maka true dan sebaliknya */

void TentaraAbsolute (Bangunan * B, IdxType X);
/* I.S. Bangunan B terdefinisi
        X pasti ada di dalam List */
/* F.S. Bangunan ke-X yang memiliki jumlah tentara <= 0 dimutlakkan
        nilai jumlahnya */

/*************************** Level-Up Bangunan ********************************/
boolean CheckLevelUp (Bangunan B, IdxType X);
/* Mengecek apakah bangunan tertentu sudah melewati jumlah yang seharusnya 
   atau belum */
/* Jika iya maka True dan sebaliknya */
// ! Jika udah level 4 maka tidak bisa Level Up lagi

void LevelUp (Bangunan * B, IdxType X);
/* I.S. Bangunan B terdefinisi
        Bangunan ke-X sudah pasti bisa Level-Up */
/* F.S. Bangunan ke-X mengalami pengurangan jumlah tentara sebesar 1/2 dari 
        jumlah sebelumnya.
        Bangunan ke-X menglami penaikan 1 level. */

#endif
