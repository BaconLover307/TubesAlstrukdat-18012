/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File body: array.c */

#include <stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBangunan (Bangunan * B) {
/* I.S. B sembarang */
/* F.S. Terbentuk tabel B kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua nama elemen tabel B dengan charUndef */

  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for (i = IdxMin; i <= IdxMax; i++) {
    Name(ElmtBan(*B, i)) = CharUndef;
  }    
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtBan (Bangunan B) {
/* Mengirimkan banyaknya elemen efektif tabel */

  /* KAMUS LOKAL */
  int i;
  boolean found;

  /* ALGORITMA */
  i = IdxMin;
  found = false;
  while ((i <= IdxMax) && (!found)) {
    if (Name(ElmtBan(B, i)) == CharUndef) {
      found = true;
    }
    i++;
  }

  if (found) {
    return (i - 2);
  } else /* !found */ {
    return (IdxMax);
  }
}

/* *** Selektor INDEKS *** */
IdxType GetFirstBan (Bangunan B) {
/* Prekondisi : Tabel B tidak kosong */
/* Mengirimkan indeks elemen B pertama */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return IdxMin;
}

IdxType GetLastBan (Bangunan B) {
/* Prekondisi : Tabel B tidak kosong */
/* Mengirimkan indeks elemen B terakhir */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return NbElmtBan(B);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyBan (Bangunan B) {
/* Mengirimkan true jika tabel B kosong, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (Name(ElmtBan(B, IdxMin)) == CharUndef);    
}

/* *** Test tabel penuh *** */
boolean IsFullBan (Bangunan B) {
/* Mengirimkan true jika tabel B penuh, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (NbElmtBan(B) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaBangunan (Bangunan * B) {
/* I.S. B sembarang */
/* F.S. Tabel B terdefinisi */
/* Prekondisi : Banyaknya elemen B itu valid */
/* Proses : membaca banyaknya elemen B dan mengisi semua nilainya dengan Mesin Kata */
// Todo Menunggu yang kerjain Configure
 
}

/*********************** Tentara Invaded **************************/
void TentaraInvaded (Bangunan * B, IdxType i, int N) {
/* I.S. Bangunan B terdefinisi 
        i pasti ada di dalam indeks bangunan B */
/* F.S. Bangunan ke-i mengalami penurunan jumlah tentara sebesar N (mungkin minus) */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  if (Name(ElmtBan(*B, i)) == 'T') {
    Tentara(ElmtBan(*B, i)) = Tentara(ElmtBan(*B, i)) - (N * 3 / 4);
  } else if (Name(ElmtBan(*B, i)) == 'F') {
    if ((Level(ElmtBan(*B, i)) == 3) || (Level(ElmtBan(*B, i)) == 4)) {
      Tentara(ElmtBan(*B, i)) = Tentara(ElmtBan(*B, i)) - (N * 3 / 4);
    } else /* (Level(ElmtBan(*B, i)) == 1) || (Level(ElmtBan(*B, i)) == 2) */ {
      Tentara(ElmtBan(*B, i)) -= N;
    }
  } else /* (Name(ElmtBan(*B, i)) == 'C') || (Name(ElmtBan(*B, i)) == 'V') */ {
    Tentara(ElmtBan(*B, i)) -= N;
  }
}

boolean CanCapture (Bangunan B, IdxType i) {
/* Mengecek apakah Bangunan ke-i memiliki jumlah tentara yang <= 0 */
/* Jika iya maka true dan sebaliknya */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (Tentara(ElmtBan(B, i)) <= 0);
}