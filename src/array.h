/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518012 */
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
#define IdxMin 1
/* Indeks minimum array */

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */ // ! Untuk Relate (sementara)

typedef struct {
  char name; /* tipe bangunan */
  POINT posisi; /* posisi bangunan */
  int level; /* level bangunan */
  int tentara; /* jumlah tentara yang dimiliki bangunan */
} info_bangunan;

typedef struct {
  info_bangunan *BI; /* memori tempat penyimpan elemen (container) */
  int Neff;   /* >=0, banyaknya elemen efektif */
  int MaxEl;  /* ukuran elemen */
} Bangunan;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika B adalah Bangunan, cara deklarasi dan akses: */
/* Deklarasi : B : Bangunan */
/* Maka cara akses:
   B.Neff  untuk mengetahui banyaknya elemen
   B.BI    untuk mengakses seluruh nilai elemen tabel
   B.BI[i] untuk mengakses elemen ke-i */
/* Definisi :
   Tabel kosong: B.Neff = 0
   Definisi elemen pertama : B.BI[i] dengan i=1
   Definisi elemen terakhir yang terdefinisi: B.BI[i] dengan i=B.Neff */

/* ********** SELEKTOR ********** */
/* B adalah Bangunan      */
/* e adalah info_bangunan */
#define Neff(B)       (B).Neff
#define BI(B)         (B).BI
#define ElmtBan(B,i)  (B).BI[(i)]
#define MaxEl(B)      (B).MaxEl

#define Name(e)       (e).name
#define Posisi(e)     (e).posisi
#define Level(e)      (e).level
#define Tentara(e)    (e).tentara

// $ ********** KONSTRUKTOR **********

// $ Konstruktor : create tabel kosong
// * I.S. B sembarang, maxel > 0
// * F.S. Terbentuk tabel B kosong dengan kapasitas maxel + 1
void MakeEmptyBangunan (Bangunan * B, int maxel);

// * I.S. B terdefinisi;
// * F.S. BI(B) dikembalikan ke system, MaxEl(B)=0; Neff(B)=0
void DealokasiBangunan(Bangunan *B);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

/* Mengirimkan banyaknya elemen efektif tabel */
int NbElmtBan (Bangunan B);

/* *** Selektor INDEKS *** */

/* Prekondisi : Tabel B tidak kosong */
/* Mengirimkan indeks elemen B pertama */
IdxType GetFirstBan (Bangunan B);

/* Prekondisi : Tabel B tidak kosong */
/* Mengirimkan indeks elemen B terakhir */
IdxType GetLastBan (Bangunan B);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */

/* Mengirimkan true jika tabel B kosong, mengirimkan false jika tidak */
boolean IsEmptyBan (Bangunan B);

/* *** Test tabel penuh *** */

/* Mengirimkan true jika tabel B penuh, mengirimkan false jika tidak */
boolean IsFullBan (Bangunan B);
// ? Entah perlu fungsi ini gak ya?

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

/* I.S. B sembarang */
/* F.S. Tabel B terdefinisi */
/* Prekondisi : Banyaknya elemen B itu valid */
/* Proses : membaca banyaknya elemen B dan mengisi semua nilainya dengan Mesin Kata */
void BacaBangunan (Bangunan * B);

/*********************** Tentara Attack ****************************/

/* Mengecek apakah bangunan ke-X memiliki jumlah tentara yang >= N */
/* Jika iya maka True dan sebaliknya */
boolean CheckAttackTentara (Bangunan B, IdxType X, int N);

/* I.S. Bangunan B terdefinisi
        X pasti ada di dalam List
        Jumlah N pasti normal (sudah dicek pakai CheckAttackTentara) */
/* F.S. Bangunan ke-X mengalami pengurangan jumlah tentara sebesar N */
void TentaraAttack (Bangunan * B, IdxType X, int N);

/*********************** Tentara Invaded **************************/

/* I.S. Bangunan B terdefinisi
        i pasti ada di dalam indeks bangunan B
        Skill Shield itu aktif sekali          */
/* F.S. Bangunan ke-i mengalami pengurangan jumlah tentara (mungkin minus)
        dengan perhitungan adanya pertahanan */
void InvadedShield (Bangunan * B, IdxType i, int N);

/* I.S. Bangunan B terdefinisi
        i pasti ada di dalam indeks bangunan B
        Mengetahui skill-skill tertentu aktif atau tidak*/
/* F.S. Bangunan ke-i mengalami pengurangan jumlah tentara (mungkin minus) */
void TentaraInvaded (Bangunan * B, boolean Critical_Hit, boolean Attack_Up, boolean Shield, IdxType i, int N);

/* Mengecek apakah Bangunan ke-i memiliki jumlah tentara yang <= 0 */
/* Jika iya maka true dan sebaliknya */
boolean CanCapture (Bangunan B, IdxType i);

/* I.S. Bangunan B terdefinisi
        X pasti ada di dalam List */
/* F.S. Bangunan ke-X yang memiliki jumlah tentara <= 0 dimutlakkan
        nilai jumlahnya */
void TentaraAbsolute (Bangunan * B, IdxType X);

/*************************** Level-Up Bangunan ********************************/

/* Mengecek apakah bangunan tertentu sudah melewati jumlah yang seharusnya
   atau belum */
/* Jika iya maka True dan sebaliknya */
boolean CheckLevelUp (Bangunan B, IdxType X);
// ! Jika udah level 4 maka tidak bisa Level Up lagi

/* I.S. Bangunan B terdefinisi
        Bangunan ke-X sudah pasti bisa Level-Up */
/* F.S. Bangunan ke-X mengalami pengurangan jumlah tentara sebesar 1/2 dari
        jumlah sebelumnya.
        Bangunan ke-X menglami penaikan 1 level. */
void LevelUp (Bangunan * B, IdxType X);

#endif
