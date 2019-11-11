/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File body: array.c */

#include <stdio.h>
#include <stdlib.h>
#include "array_daniel.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBangunan (Bangunan * B, int maxel) {
/* I.S. B sembarang, maxel > 0 */
/* F.S. Terbentuk tabel B kosong dengan kapasitas maxel + 1 */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  BI(*B) = (info_bangunan *) malloc ((maxel + 1)* sizeof(info_bangunan));
  MaxEl(*B) = maxel;
  Neff(*B) = 0;
}

void DealokasiBangunan(Bangunan *B) {
/* I.S. B terdefinisi; */
/* F.S. BI(B) dikembalikan ke system, MaxEl(B)=0; Neff(B)=0 */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(BI(*B));
  MaxEl(*B) = 0;
  Neff(*B) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtBan (Bangunan B) {
/* Mengirimkan banyaknya elemen efektif tabel */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return Neff(B);
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
  return Neff(B);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyBan (Bangunan B) {
/* Mengirimkan true jika tabel B kosong, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (Neff(B) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFullBan (Bangunan B) {
// ? Entah perlu fungsi ini gak ya?
/* Mengirimkan true jika tabel B penuh, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (Neff(B) == MaxEl(B));
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

/*********************** Tentara Attack ****************************/
boolean CheckAttackTentara (Bangunan B, IdxType X, int N) {
/* Mengecek apakah bangunan ke-X memiliki jumlah tentara yang >= N */
/* Jika iya maka True dan sebaliknya */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (Tentara(ElmtBan(B, X)) >= N);
}

void TentaraAttack (Bangunan * B, IdxType X, int N) {
/* I.S. Bangunan B terdefinisi
        X pasti ada di dalam List
        Jumlah N pasti normal (sudah dicek pakai CheckAttackTentara) */
/* F.S. Bangunan ke-X mengalami pengurangan jumlah tentara sebesar N */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  Tentara(ElmtBan(*B, X)) -= N;

}

/*********************** Tentara Invaded **************************/
void InvadedShield (Bangunan * B, IdxType i, int N) {
/* I.S. Bangunan B terdefinisi
        i pasti ada di dalam indeks bangunan B
        Skill Shield itu aktif sekali          */
/* F.S. Bangunan ke-i mengalami pengurangan jumlah tentara (mungkin minus)
        dengan perhitungan adanya pertahanan */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  if (Tentara(ElmtBan(*B, i)) > N * 3 / 4) {
    Tentara(ElmtBan(*B, i)) = Tentara(ElmtBan(*B, i)) - N * 3 / 4;
  } else /* Tentara(ElmtBan(*B, i)) <= N * 3 / 4 */ {
    Tentara(ElmtBan(*B, i)) = (-1) * (N - Tentara(ElmtBan(*B, i)) * 4 / 3);
  }
}

void TentaraInvaded (Bangunan * B, boolean Critical_Hit, boolean Attack_Up, int Shield, IdxType i, int N) {
/* I.S. Bangunan B terdefinisi
        i pasti ada di dalam indeks bangunan B
        Mengetahui skill-skill tertentu aktif atau tidak*/
/* F.S. Bangunan ke-i mengalami pengurangan jumlah tentara (mungkin minus) */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  if (Critical_Hit) {
    if (Tentara(ElmtBan(*B, i)) > 2 * N) {
      Tentara(ElmtBan(*B, i)) = Tentara(ElmtBan(*B, i)) - 2 * N;
    } else /* Tentara(ElmtBan(*B, i) <= 2 * N */ {
      if (Tentara(ElmtBan(*B, i)) % 2 == 1) {
        Tentara(ElmtBan(*B, i)) += 1;
      }

      Tentara(ElmtBan(*B, i)) = (-1) * (N - Tentara(ElmtBan(*B, i)) / 2);
    }

  } else /* !Critical_Hit */ {
    if (Attack_Up) {
      Tentara(ElmtBan(*B, i)) -= N;

    } else /* !Attack_Up */ {
      if (Shield == 2) { // * Skill Shield digunakan 2 kali
        /* Tidak ada penurunan jumlah tentara */
      } else if (Shield == 1) { // * Skill Shield digunaka 1 kali
        InvadedShield(B, i, N);

      } else /* Shield == 0 */ { //* Skill apapun tidak aktif yang berhubungan dengan Attack
        if (Name(ElmtBan(*B, i)) == 'T') {
          InvadedShield(B, i, N);
        } else if (Name(ElmtBan(*B, i)) == 'F') {
          if ((Level(ElmtBan(*B, i)) == 3) || (Level(ElmtBan(*B, i)) == 4)) {
            InvadedShield(B, i, N);

          } else /* (Level(ElmtBan(*B, i)) == 1) || (Level(ElmtBan(*B, i)) == 2) */ {
            Tentara(ElmtBan(*B, i)) -= N;
          }

        } else /* (Name(ElmtBan(*B, i)) == 'C') || (Name(ElmtBan(*B, i)) == 'V') */ {
          Tentara(ElmtBan(*B, i)) -= N;
        }
      }
    }
  }
}

boolean CanCapture (Bangunan B, IdxType i) {
/* Mengecek apakah Bangunan ke-i memiliki jumlah tentara yang <= 0 */
/* Jika iya maka true dan sebaliknya */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (Tentara(ElmtBan(B, i)) <= 0);
}

void TentaraAbsolute (Bangunan * B, IdxType X) {
/* I.S. Bangunan B terdefinisi
        X pasti ada di dalam List */
/* F.S. Bangunan ke-X yang memiliki jumlah tentara <= 0 dimutlakkan
        nilai jumlahnya */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  Tentara(ElmtBan(*B, X)) = abs(Tentara(ElmtBan(*B, X)));
}

/*************************** Level-Up Bangunan ********************************/
boolean CheckLevelUp (Bangunan B, IdxType X) {
/* Mengecek apakah bangunan tertentu sudah melewati jumlah yang seharusnya
   atau belum */
/* Jika iya maka True dan sebaliknya */
// ! Jika udah level 4 maka tidak bisa Level Up lagi

  /* KAMUS LOKAL */

  /* ALGORITMA */
  if (Name(ElmtBan(B, X)) == 'C') {
    if (Level(ElmtBan(B, X)) == 1) {
      return (Tentara(ElmtBan(B, X)) >= 40);

    } else if (Level(ElmtBan(B, X)) == 2) {
      return (Tentara(ElmtBan(B, X)) >= 60);

    } else if (Level(ElmtBan(B, X)) == 3) {
      return (Tentara(ElmtBan(B, X)) >= 80);

    } else /* Level(ElmtBan(B, X)) == 4 */ {
      return false;

    }
  } else if (Name(ElmtBan(B, X)) == 'T') {
    if (Level(ElmtBan(B, X)) == 1) {
      return (Tentara(ElmtBan(B, X)) >= 20);

    } else if (Level(ElmtBan(B, X)) == 2) {
      return (Tentara(ElmtBan(B, X)) >= 30);

    } else if (Level(ElmtBan(B, X)) == 3) {
      return (Tentara(ElmtBan(B, X)) >= 40);

    } else /* Level(ElmtBan(B, X)) == 4 */ {
      return false;

    }
  } else if (Name(ElmtBan(B, X)) == 'F') {
    if (Level(ElmtBan(B, X)) == 1) {
      return (Tentara(ElmtBan(B, X)) >= 20);

    } else if (Level(ElmtBan(B, X)) == 2) {
      return (Tentara(ElmtBan(B, X)) >= 40);

    } else if (Level(ElmtBan(B, X)) == 3) {
      return (Tentara(ElmtBan(B, X)) >= 60);

    } else /* Level(ElmtBan(B, X)) == 4 */ {
      return false;

    }
  } else /* Name(ElmtBan(B, X)) == 'V' */ {
    if (Level(ElmtBan(B, X)) == 1) {
      return (Tentara(ElmtBan(B, X)) >= 20);

    } else if (Level(ElmtBan(B, X)) == 2) {
      return (Tentara(ElmtBan(B, X)) >= 30);

    } else if (Level(ElmtBan(B, X)) == 3) {
      return (Tentara(ElmtBan(B, X)) >= 40);

    } else /* Level(ElmtBan(B, X)) == 4 */ {
      return false;

    }
  }
}

void LevelUp (Bangunan * B, IdxType X) {
/* I.S. Bangunan B terdefinisi
        Bangunan ke-X sudah pasti bisa Level-Up */
/* F.S. Bangunan ke-X mengalami pengurangan jumlah tentara sebesar 1/2 dari
        jumlah sebelumnya.
        Bangunan ke-X menglami penaikan 1 level. */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  if (Tentara(ElmtBan(*B, X)) % 2 == 1) { //apabila jumlah tentaranya ganjil
    Tentara(ElmtBan(*B, X)) -= 1;
  }

  Tentara(ElmtBan(*B, X)) /= 2;
  Level(ElmtBan(*B, X)) += 1;
}        
