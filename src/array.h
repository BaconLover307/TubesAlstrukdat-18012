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

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBangunan (Bangunan * B, int maxel);
/* I.S. B sembarang, maxel > 0 */
/* F.S. Terbentuk tabel B kosong dengan kapasitas maxel + 1 */

void DealokasiBangunan(Bangunan *B);
/* I.S. B terdefinisi; */
/* F.S. BI(B) dikembalikan ke system, MaxEl(B)=0; Neff(B)=0 */

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
/* Prekondisi : Banyaknya elemen B itu valid */
/* Proses : membaca banyaknya elemen B dan mengisi semua nilainya dengan Mesin Kata */

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
void InvadedShield (Bangunan * B, IdxType i, int N);
/* I.S. Bangunan B terdefinisi
        i pasti ada di dalam indeks bangunan B
        Skill Shield itu aktif sekali          */
/* F.S. Bangunan ke-i mengalami pengurangan jumlah tentara (mungkin minus)
        dengan perhitungan adanya pertahanan */

void TentaraInvaded (Bangunan * B, boolean Critical_Hit, boolean Attack_Up, int Shield, IdxType i, int N);
/* I.S. Bangunan B terdefinisi
        i pasti ada di dalam indeks bangunan B
        Mengetahui skill-skill tertentu aktif atau tidak*/
/* F.S. Bangunan ke-i mengalami pengurangan jumlah tentara (mungkin minus) */

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
