/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File body : graph.h */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graph.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Graph kosong  */
void MakeEmptyGraph (Graph * G, int maxel) {
/* I.S. G sembarang, maxel > 0 */
/* F.S. Terbentuk tabel G kosong dengan kapasitas maxel + 1 */

  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  GI(*G) = (List *) malloc ((maxel + 1)* sizeof(List));
  MaxG(*G) = maxel;
  NeffG(*G) = 0;

  for (i = IdxMin; i <= maxel; i++) {
    CreateEmptyList(&ElmtG(*G, i));
  }
}

void DealokasiGraph (Graph * G) {
/* I.S. G terdefinisi; */
/* F.S. GI(G) dikembalikan ke system, MaxG(G)=0; NeffG(G)=0 */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(GI(*G));
  MaxG(*G) = 0;
  NeffG(*G) = 0;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstGraph (Graph G) {
/* Prekondisi : Graph G tidak kosong */
/* Mengirimkan indeks elemen G pertama */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return IdxMin;
}

IdxType GetLastGraph (Graph G) {
/* Prekondisi : Graph G tidak kosong */
/* Mengirimkan indeks elemen G terakhir */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return NeffG(G);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyGraph (Graph G) {
/* Mengirimkan true jika Graph G kosong, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (NeffG(G) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFullGraph (Graph G) {
// ? Entah perlu fungsi ini gak ya?  
/* Mengirimkan true jika Graph G penuh, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (NeffG(G) == MaxG(G));
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaGraph (Graph * G);
// ! Ingat MakeEmptyGraph dulu
// TODO: Prosedur ini dimasukkan ke ADT Mesin Kata
/* I.S. Graph G terdefinisi */
/* F.S. Graph G berisi hubungan-hubungan antar bangunan */

void TambahRelation (Graph * G, urutan X, urutan Y) {
/* I.S. Graph G terdefinisi */
/* F.S. Bangunan ke-X dinyatakan memiliki hubungan dengan bangunan ke-Y */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  InsVPrio(&ElmtG(*G, X), Y);
}

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

  /* ALGORITMA */
  for (i = IdxMin; i <= NeffG(G); i++) {
    for (j = IdxMin; j < NeffG(G); j++) {
      if (CheckRelation(G, i, j)) {
        printf("1 ");
      } else /* !CheckRelation(G, i, j) */ {
        printf("0 ");  
      }
    }

    if (CheckRelation(G, i, NeffG(G))) {
      printf("1\n");
    } else /* !CheckRelation(G, i, NeffG(G)) */ {
      printf("0\n");  
    }
  }
}

/******************* RELATION **********************/
boolean CheckRelation (Graph G, urutan X, urutan Y) {
/* Mengecek apakah bangunan ke-X memiliki hubungan dengan bangunan ke-Y 
   atau tidak */
/* Jika iya maka True dan sebaliknya */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  if ((Search(ElmtG(G, X), Y)) != Nil) {
    return true;
  } else /* Search(ElmtG(G, X), Y)) == Nil */ {
    return false;
  }
}

/******************* ATTACK *********************/
boolean CheckAttack (Graph G, List L, urutan X) {
/* Mengecek apakah bangunan ke-X yang dimiliki oleh suatu pemain dapat
   menyerang bangunan yang tidak dimilikinya atau tidak */
/* Jika iya maka True dan sebaliknya */

  /* KAMUS LOKAL */
  address PList, PGraph;
  boolean same;

  /* ALGORITMA */
  PList = First(L);
  PGraph = First(ElmtG(G, X));
  same = false;

  while ((PGraph != Nil) && (PList != Nil) && (!same)) {
    if (Info(PGraph) != Info(PList)) {

      if (Info(PGraph) < Info(PList)) {
        same = true;
      } else /* Info(PGraph) > Info(PList) */ {
        if (Next(PList) == Nil) {
          same = true;
        } else /* Next(PList) != Nil */ {
          PList = Next(PList);  
        }

      }
    } else /* Info(PGraph) == Info(PList) */ {
      PList = Next(PList);
      PGraph = Next(PGraph);
    }
  }

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
  address PList, PGraph;
  int i;

  /* ALGORITMA */
  PList = First(L);
  PGraph = First(ElmtG(G, X));
  i = 1;

  while ((PGraph != Nil) && (PList != Nil)) {
    if (Info(PGraph) != Info(PList)) {

      if (Info(PGraph) < Info(PList)) {
        printf("%d. ", i);
    
        if (Name(ElmtBan(B, Info(PGraph))) == 'C') {
          printf("Castle ");
        } else if (Name(ElmtBan(B, Info(PGraph))) == 'V') {
          printf("Village ");
        } else if (Name(ElmtBan(B, Info(PGraph))) == 'T') {
          printf("Tower ");
        } else /* (Name(ElmtBan(B, Info(PGraph))) == 'F') */ {
          printf("Fort ");
        }

        TulisPOINT(Posisi(ElmtBan(B, Info(PGraph))));
        printf(" %d ", Tentara(ElmtBan(B, Info(PGraph))));
        printf("lv. %d\n", Level(ElmtBan(B, Info(PGraph))));

        i++;
        PGraph = Next(PGraph);

      } else /* Info(PGraph) > Info(PList) */ {
        PList = Next(PList);
        
      }
    } else /* Info(PGraph) == Info(PList) */ {
      PList = Next(PList);
      PGraph = Next(PGraph);
    }
  }

  while (PGraph != Nil) {
    printf("%d. ", i);
    
    if (Name(ElmtBan(B, Info(PGraph))) == 'C') {
      printf("Castle ");
    } else if (Name(ElmtBan(B, Info(PGraph))) == 'V') {
      printf("Village ");
    } else if (Name(ElmtBan(B, Info(PGraph))) == 'T') {
      printf("Tower ");
    } else /* (Name(ElmtBan(B, Info(PGraph))) == 'F') */ {
      printf("Fort ");
    }

    TulisPOINT(Posisi(ElmtBan(B, Info(PGraph))));
    printf(" %d ", Tentara(ElmtBan(B, Info(PGraph))));
    printf("lv. %d\n", Level(ElmtBan(B, Info(PGraph))));

    i++;
    PGraph = Next(PGraph);
  }
}        

/************ MOVE TENTARA ******************/
boolean CheckMove (Graph G, List L, urutan X) {
/* Mengecek apakah bangunan ke-X yang dimiliki oleh suatu pemain dapat
   mengirimkan tentara bangunan lain yang dimilikinya atau tidak */
/* Jika iya maka True dan sebaliknya */

  /* KAMUS LOKAL */
  address PList, PGraph;
  boolean same;

  /* ALGORITMA */
  PList = First(L);
  PGraph = First(ElmtG(G, X));
  same = false;

  while ((PGraph != Nil) && (PList != Nil) && (!same)) {
    if (Info(PGraph) != Info(PList)) {

      if (Info(PList) < Info(PGraph)) {
        same = true;
      } else /* Info(PList) > Info(PGraph) */ {
        if (Next(PGraph) == Nil) {
          same = true;
        } else /* Next(PGraph) != Nil */ {
          PGraph = Next(PGraph);  
        }

      }
    } else /* Info(PGraph) == Info(PList) */ {
      PList = Next(PList);
      PGraph = Next(PGraph);
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
  address PList, PGraph;
  int i;

  /* ALGORITMA */
  PList = First(L);
  PGraph = First(ElmtG(G, X));
  i = 1;

  while ((PGraph != Nil) && (PList != Nil)) {
    if (Info(PGraph) != Info(PList)) {

      if (Info(PList) < Info(PGraph)) {
        printf("%d. ", i);
    
        if (Name(ElmtBan(B, Info(PList))) == 'C') {
          printf("Castle ");
        } else if (Name(ElmtBan(B, Info(PList))) == 'V') {
          printf("Village ");
        } else if (Name(ElmtBan(B, Info(PList))) == 'T') {
          printf("Tower ");
        } else /* (Name(ElmtBan(B, Info(PList))) == 'F') */ {
          printf("Fort ");
        }

        TulisPOINT(Posisi(ElmtBan(B, Info(PList))));
        printf(" %d ", Tentara(ElmtBan(B, Info(PList))));
        printf("lv. %d\n", Level(ElmtBan(B, Info(PList))));

        i++;
        PList = Next(PList);

      } else /* Info(PList) > Info(PGraph) */ {
        PGraph = Next(PGraph);
        
      }
    } else /* Info(PGraph) == Info(PList) */ {
      PList = Next(PList);
      PGraph = Next(PGraph);
    }
  }

  while (PList != Nil) {
    printf("%d. ", i);
    
    if (Name(ElmtBan(B, Info(PList))) == 'C') {
      printf("Castle ");
    } else if (Name(ElmtBan(B, Info(PList))) == 'V') {
      printf("Village ");
    } else if (Name(ElmtBan(B, Info(PList))) == 'T') {
      printf("Tower ");
    } else /* (Name(ElmtBan(B, Info(PList))) == 'F') */ {
      printf("Fort ");
    }

    TulisPOINT(Posisi(ElmtBan(B, Info(PList))));
    printf(" %d ", Tentara(ElmtBan(B, Info(PList))));
    printf("lv. %d\n", Level(ElmtBan(B, Info(PList))));

    i++;
    PList = Next(PList);
  }
}        