/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518012 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File header: graph.c */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graph.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Graph kosong  */
void MakeEmptyGraph (Graph * G) {
/* I.S. sembarang */
/* F.S. Terbentuk graph kosong */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  FirstG(*G) = Nil;
}

/****************** Manajemen Memori ******************/
addrGraph AlokasiGraph1 (urutan X) {
/* Mengirimkan addrGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrGraph tidak Nil, dan misalnya */
/* menghasilkan P, maka InfoG(P)=X, NextP(P)=Nil, FirstChild(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

  /* KAMUS LOKAL */
  addrGraph P;

  /* ALGORITMA */
  P = malloc (sizeof(addrGraph));
  if (P != NULL) {
    InfoG(P) = X;
    NextP(P) = Nil;
    FirstChild(P) = Nil;
  } else /* P == NULL */ {
    P = Nil;
  }
  return P;
}

addrGraph2 AlokasiGraph2 (urutan X) {
/* Mengirimkan addrGraph2 hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrGraph2 tidak Nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

  /* KAMUS LOKAL */
  addrGraph2 P;

  /* ALGORITMA */
  P = malloc (sizeof(addrGraph2));
  if (P != NULL) {
    InfoG2(P) = X;
    NextChild(P) = Nil;
  } else /* P == NULL */ {
    P = Nil;
  }
  return P;
}

void DealokasiGraph1 (addrGraph * P) {
/* I.S. P terdefinisi; */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrGraph P */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(*P);
}

void DealokasiGraph2 (addrGraph2 * P) {
/* I.S. P terdefinisi; */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrGraph2 P */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(*P);
}

/* ********** TEST GRAPH KOSONG ********** */
boolean IsEmptyGraph (Graph G) {
/* Mengirimkan true jika Graph G kosong, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (FirstG(G) == Nil);
}

boolean IsEmptyParent (addrGraph P) {
/* Mengirimkan true jika addrGraph P kosong, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (FirstChild(P) == Nil);
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaGraph (Graph * G);
// ! Ingat MakeEmptyGraph dulu
// TODO: Prosedur ini dimasukkan ke ADT Mesin Kata
/* I.S. Graph G terdefinisi */
/* F.S. Graph G berisi hubungan-hubungan antar bangunan */

void TulisGraph (Graph G) {
// ? Untuk debugging doang kayaknya
/* I.S. G terdefinisi */
/* F.S. Hubungan antar bangunan ditampilkan ke layar.
        Jika tidak ada hubungan maka muncul '0' di layar.
        Jika ada hubungan maka muncul '1' di layar.       */
/* Contoh: menulis matriks 3x3
0 1 1
1 0 0
1 0 0
*/

  /* KAMUS LOKAL */
  IdxType i, j;
  addrGraph P;
  addrGraph2 C;

  /* ALGORITMA */
  i = 1;

  while (i <= NbElmtGraph(G)) {
    P = SearchP(G, i);
    j = 1;

    while (j < NbElmtGraph(G)) {
      C = SearchChild(P, j);

      if (C != Nil) {
        printf("1 ");
      } else /* C == Nil */ {
        printf("0 ");
      }

      j++;
    }

    C = SearchChild(P, j);
    if (C != Nil) {
      printf("1\n");
    } else /* C == Nil */ {
      printf("0\n");
    }

    i++;
  }
}

/****************** PROSES SEMUA ELEMEN PARENT GRAPH ******************/
int NbElmtGraph (Graph G) {
/* Mengirimkan banyaknya elemen parent graph; mengirimkan 0 jika graph kosong */

  /* KAMUS LOKAL */
  addrGraph P;
  int total;

  /* ALGORITMA */
  if (IsEmptyGraph(G)) {
    return 0;
  } else /* !IsEmptyGraph(G) */ {
    P = FirstG(G);
    total = 0;
    while (P != Nil) {
      P = NextP(P);
      total++;
    }
    return total;
  }
}

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void AddParent (Graph * G, int N) {
/* I.S. Graph G terdefinisi */
/* F.S. Semua elemen parent dimasukkan ke graph secara berurut */

  /* KAMUS LOKAL */
  int i;
  addrGraph P, Q;

  /* ALGORITMA */
  for (i = 1; i <= N; i++) {
    Q = AlokasiGraph1(i);

    if (Q != Nil) {
      if (IsEmptyGraph(*G)) {
        FirstG(*G) = Q;
        P = FirstG(*G);
      } else /* !IsEmptyGraph(*G) */ {
        NextP(P) = Q;
        P = NextP(P);
      }
    }
  }
}

void AddRelation (Graph * G, urutan X, urutan Y) {
/* I.S. Graph G terdefinisi */
/* F.S. Bangunan ke-X dinyatakan memiliki hubungan dengan bangunan ke-Y */

  /* KAMUS LOKAL */
  addrGraph P;
  addrGraph2 C, Q;

  /* ALGORITMA */
  P = SearchP(*G, X);
  Q = AlokasiGraph2(Y);

  if (Q != Nil) {
    if (IsEmptyParent(P)) {
      FirstChild(P) = Q;

    } else /* !IsEmptyParent(P) */ {
      C = FirstChild(P);
      while (NextChild(C) != Nil) {
        C = NextChild(C);
      }
      NextChild(C) = Q;
    }
  }
}

/****************** PENCARIAN SEBUAH GRAPH ******************/
addrGraph SearchP (Graph G, urutan X) {
/* Mencari apakah ada elemen parent graph dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

  /* KAMUS LOKAL */
  addrGraph P;

  /* ALGORITMA */
  P = FirstG(G);
  while ((P != Nil) && (InfoG(P) != X)) {
    P = NextP(P);
  }

  return P;
}

addrGraph2 SearchChild (addrGraph P, urutan X) {
/* Mencari apakah ada elemen anak graph dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

  /* KAMUS LOKAL */
  addrGraph2 C;

  /* ALGORITMA */
  C = FirstChild(P);
  while ((C != Nil) && (InfoG2(C) != X)) {
    C = NextChild(C);
  }

  return C;
}

/******************* RELATION **********************/
boolean CheckRelation (Graph G, urutan X, urutan Y) {
/* Mengecek apakah bangunan ke-X memiliki hubungan dengan bangunan ke-Y
   atau tidak */
/* Jika iya maka True dan sebaliknya */

  /* KAMUS LOKAL */
  addrGraph P;

  /* ALGORITMA */
  P = SearchP(G, X);

  return (SearchChild(P, Y) != Nil);
}

/******************* ATTACK *********************/
boolean CheckAttack (Graph G, List L, urutan X) {
/* Mengecek apakah bangunan ke-X yang dimiliki oleh suatu pemain dapat
   menyerang bangunan yang tidak dimilikinya atau tidak */
/* Jika iya maka True dan sebaliknya */

  /* KAMUS LOKAL */
  address P;
  addrGraph Q;
  addrGraph2 C;
  boolean same;

  /* ALGORITMA */
  DelP(&L, X);
  P = First(L);
  Q = SearchP(G, X);
  C = FirstChild(Q);
  same = false;

  while ((C != Nil) && (P != Nil) && (!same)) {
    if (InfoG2(C) != Info(P)) {
      if (InfoG2(C) < Info(P)) {
        same = true;
      } else /* InfoG2(C) > Info(P) */ {
        if (Next(P) == Nil) {
          return true;
        } else /* Next(P) != Nil */ {
          P = Next(P);
        }
      }
    } else /* InfoG2(C) == Info(P) */ {
      P = Next(P);
      C = NextChild(C);
    }
  }

  P = Alokasi(X);
  InsertPrio(&L, P);
  return (same);
}

void PrintAttack (Graph G, List L, Bangunan B, urutan X) {
/* I.S. Graph G terdefinisi
        List L terdefinisi
        Bangunan B terdefinisi
        X pasti ada di dalam L */
/* F.S. Jika ada bangunan yang bisa diserang maka akan muncul pilihan-
        pilihan bangunan yang dapat diserang
        Jika tidak ada maka muncul "Tidak ada bangunan yang dapat
        diserang" di layar */

  /* KAMUS LOKAL */
  address P;
  addrGraph Q;
  addrGraph2 C;
  int i;

  /* ALGORITMA */
  DelP(&L, X);
  P = First(L);
  Q = SearchP(G, X);
  C = FirstChild(Q);
  i = 1;

  while ((C != Nil) && (P != Nil)) {
    if (InfoG2(C) != Info(P)) {
      if (InfoG2(C) < Info(P)) {
        printf("%d. ", i);

        if (Name(ElmtBan(B, InfoG2(C))) == 'C') {
          printf("Castle ");
        } else if (Name(ElmtBan(B, InfoG2(C))) == 'V') {
          printf("Village ");
        } else if (Name(ElmtBan(B, InfoG2(C))) == 'T') {
          printf("Tower ");
        } else /* (Name(ElmtBan(B, InfoG2(C))) == 'F') */ {
          printf("Fort ");
        }

        TulisPOINT(Posisi(ElmtBan(B, InfoG2(C))));
        printf(" %d ", Tentara(ElmtBan(B, InfoG2(C))));
        printf("lv. %d\n", Level(ElmtBan(B, InfoG2(C))));

        i++;
        C = NextChild(C);

      } else /* InfoG2(C) > Info(P) */ {
        P = Next(P);
      }

    } else /* InfoG2(C) == Info(P) */ {
      P = Next(P);
      C = NextChild(C);
    }
  }

  while (C != Nil) {
    printf("%d. ", i);

    if (Name(ElmtBan(B, InfoG2(C))) == 'C') {
      printf("Castle ");
    } else if (Name(ElmtBan(B, InfoG2(C))) == 'V') {
      printf("Village ");
    } else if (Name(ElmtBan(B, InfoG2(C))) == 'T') {
      printf("Tower ");
    } else /* (Name(ElmtBan(B, InfoG2(C))) == 'F') */ {
      printf("Fort ");
    }

    TulisPOINT(Posisi(ElmtBan(B, InfoG2(C))));
    printf(" %d ", Tentara(ElmtBan(B, InfoG2(C))));
    printf("lv. %d\n", Level(ElmtBan(B, InfoG2(C))));

    i++;
    C = NextChild(C);
  }

  P = Alokasi(X);
  InsertPrio(&L, P);
}

/************ MOVE TENTARA ******************/
boolean CheckMove (Graph G, List L, urutan X) {
/* Mengecek apakah bangunan ke-X yang dimiliki oleh suatu pemain dapat
   mengirimkan tentara bangunan lain yang dimilikinya atau tidak */
/* Jika iya maka True dan sebaliknya */

  /* KAMUS LOKAL */
  address P;
  addrGraph Q;
  addrGraph2 C;
  boolean same;

  /* ALGORITMA */
  P = First(L);
  Q = SearchP(G, X);
  C = FirstChild(Q);
  same = false;

  while ((C != Nil) && (P != Nil) && (!same)) {
    if (InfoG2(C) == Info(P)) {
      same = true;
    } else /* InfoG2(C) != Info(P) */ {
      if (InfoG2(C) < Info(P)) {
        C = NextChild(C);
      } else /* InfoG2(C) > Info(P) */ {
        P = Next(P);
      }
    }
  }

  return (same);
}

void PrintMove (Graph G, List L, Bangunan B, urutan X) {
/* I.S. Graph G terdefinisi
        List L terdefinisi
        Bangunan B terdefinisi
        X pasti ada di dalam L */
/* F.S. Jika ada bangunan yang memiliki hungan dengan bangunan ke-X
        yang dimiliki oleh pemain itu maka muncul pilihan-pilihan bangunan
        yang dapat ditambahkan jumlah tentaranya.
        Jika tidak ada maka muncul "Tidak ada bangunan terdekat" di
        layar */

  /* KAMUS LOKAL */
  address P;
  addrGraph Q;
  addrGraph2 C;
  int i;

  /* ALGORITMA */
  P = First(L);
  Q = SearchP(G, X);
  C = FirstChild(Q);
  i = 1;

  while ((C != Nil) && (P != Nil)) {
    if (InfoG2(C) == Info(P)) {
      printf("%d. ", i);

      if (Name(ElmtBan(B, InfoG2(C))) == 'C') {
        printf("Castle ");
      } else if (Name(ElmtBan(B, InfoG2(C))) == 'V') {
        printf("Village ");
      } else if (Name(ElmtBan(B, InfoG2(C))) == 'T') {
        printf("Tower ");
      } else /* (Name(ElmtBan(B, InfoG2(C))) == 'F') */ {
        printf("Fort ");
      }

      TulisPOINT(Posisi(ElmtBan(B, InfoG2(C))));
      printf(" %d ", Tentara(ElmtBan(B, InfoG2(C))));
      printf("lv. %d\n", Level(ElmtBan(B, InfoG2(C))));

      i++;
      C = NextChild(C);
      P = Next(P);

    } else /* InfoG2(C) != Info(P) */ {
      if (InfoG2(C) < Info(P)) {
        C = NextChild(C);
      } else /* InfoG2(C) > Info(P) */ {
        P = Next(P);
      }
    }
  }
}
