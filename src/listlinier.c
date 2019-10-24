/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File body: listlinier.c */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L) {
/* Mengirim true jika list kosong */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List * L) {
// ! Ingat taruh di awal program (untuk 2 player)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (urutan X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  P = malloc (sizeof(address));
  if (P != NULL) {
    Info(P) = X;
    Next(P) = Nil;
  } else /* P == NULL */ {
    P = Nil;
  }
  return P;
}

void Dealokasi (address * P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, urutan X) {
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  if (IsEmptyList(L)) {
    return Nil;
  } else /* !IsEmpty(L) */ {
    P = First(L);
    while ((Next(P) != Nil) && (Info(P) != X)) {
      P = Next(P);
    }

    if (Info(P) == X) {
      return P;
    } else /* Info(P) != X */ {
      return Nil;
    }
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVPrio (List * L, urutan X) {
// ! Tambah bangunan selalu pakai prosedur ini    
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list sesuai urutan X menaik: elemen yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  P = Alokasi(X);
  if (P != Nil) {
    InsertPrio(L, P);
  }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertPrio (List * L, address P) {
/* I.S. P sudah dialokasi dan L mungkin kosong */
/* F.S. Insert P sebagai elemen yang tersusun berdasarkan urutan X */

  /* KAMUS LOKAL */
  address Last;

  /* ALGORITMA */
  if (IsEmptyList(*L)) {
    First(*L) = P;
    Next(P) = Nil;
  } else /* !IsEmpty(*L) */ {
    Last = First(*L);
    while ((Next(Last) != Nil) && (Info(P) >= Info(Last))) {
      Last = Next(Last);
    }
    InsertAfter(L, P, Last);
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelP (List * L, urutan X) {
/* I.S. L terdefinisi
        X pasti ada di dalam List */
/* F.S. X dihilangkan dari List dan didealokasi */
/* List mungkin menjadi kosong karena penghapusan */

  /* KAMUS LOKAL */
  address P, Prec, PDel;

  /* ALGORITMA */
  P = First(*L);
  Prec = Nil;

  while (Info(P) != X) {
    Prec = P;
    P = Next(P);
  }

  if (Prec == Nil) {
    First(*L) = Nil; 
  } else /* Prec != Nil */ {
    Next(Prec) = Next(P);
  }

  Next(P) = Nil;
  Dealokasi(&P); 
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L, Bangunan B) {
/* I.S. List tidak kosong */
/* F.S. Mencetak bangunan-bangunan yang dimiliki ke layar dengan 
        elemen-elemen tertentu (Nama, Posisi, Jumlah Tentara, Level) */
/* Contoh : 
    1. Castle (1,15) 20 lv. 3
    2. Tower (1,13) 50 lv. 1
    3. Castle (3,14) 30 lv. 2                                        */

  /* KAMUS LOKAL */
  address P;
  int i;

  /* ALGORITMA */
  i = 1; //inisialisasi

  while (P != Nil) {
    printf("%d. ", i);
    
    if (Name(ElmtBan(B, Info(P))) == 'C') {
      printf("Castle ");
    } else if (Name(ElmtBan(B, Info(P))) == 'V') {
      printf("Village ");
    } else if (Name(ElmtBan(B, Info(P))) == 'T') {
      printf("Tower ");
    } else /* (Name(ElmtBan(B, Info(P))) == 'F') */ {
      printf("Fort ");
    }

    printf("%d ", Tentara(ElmtBan(B, Info(P))));
    printf("lv. %d\n", Level(ElmtBan(B, Info(P))));

    i++;
    P = Next(P);
  }
}

int NbElmtList (List L) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

  /* KAMUS LOKAL */
  address P;
  int total;

  /* ALGORITMA */
  if (IsEmptyList(L)) {
    return 0;
  } else /* !IsEmpty(L) */ {
    P = First(L);
    total = 0;
    while (P != Nil) {
      P = Next(P);
      total++;
    }
    return total;
  }
}

/*************** PENAMBAHAN TENTARA TIAP RONDE *********************/
boolean CheckTambahTentara (List L, Bangunan B, urutan X) {
/* X pasti ada di dalam List */
/* Mengecek apakah bangunan ke-X yang dimiliki oleh pemain tertentu sudah 
   melewati maksimum penambahan pasukan atau belum */
/* Jika belum maka true dan sebaliknya */

  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  P = Search(L, X);
  if (Name(ElmtBan(B, Info(P))) == 'C') {
    if (Level(ElmtBan(B, Info(P))) == 1) {
      return (Tentara(ElmtBan(B, Info(P))) < 40);

    } else if (Level(ElmtBan(B, Info(P))) == 2) {
      return (Tentara(ElmtBan(B, Info(P))) < 60);

    } else if (Level(ElmtBan(B, Info(P))) == 3) {
      return (Tentara(ElmtBan(B, Info(P))) < 80);

    } else /* Level(ElmtBan(B, Info(P))) == 4 */ {
      return (Tentara(ElmtBan(B, Info(P))) < 100);

    }
  } else if (Name(ElmtBan(B, Info(P))) == 'T') {
    if (Level(ElmtBan(B, Info(P))) == 1) {
      return (Tentara(ElmtBan(B, Info(P))) < 20);

    } else if (Level(ElmtBan(B, Info(P))) == 2) {
      return (Tentara(ElmtBan(B, Info(P))) < 30);

    } else if (Level(ElmtBan(B, Info(P))) == 3) {
      return (Tentara(ElmtBan(B, Info(P))) < 40);

    } else /* Level(ElmtBan(B, Info(P))) == 4 */ {
      return (Tentara(ElmtBan(B, Info(P))) < 50);

    }
  } else if (Name(ElmtBan(B, Info(P))) == 'F') {
    if (Level(ElmtBan(B, Info(P))) == 1) {
      return (Tentara(ElmtBan(B, Info(P))) < 20);

    } else if (Level(ElmtBan(B, Info(P))) == 2) {
      return (Tentara(ElmtBan(B, Info(P))) < 40);

    } else if (Level(ElmtBan(B, Info(P))) == 3) {
      return (Tentara(ElmtBan(B, Info(P))) < 60);

    } else /* Level(ElmtBan(B, Info(P))) == 4 */ {
      return (Tentara(ElmtBan(B, Info(P))) < 80);

    }
  } else /* Name(ElmtBan(B, Info(P))) == 'V' */ {
    if (Level(ElmtBan(B, Info(P))) == 1) {
      return (Tentara(ElmtBan(B, Info(P))) < 20);

    } else if (Level(ElmtBan(B, Info(P))) == 2) {
      return (Tentara(ElmtBan(B, Info(P))) < 30);

    } else if (Level(ElmtBan(B, Info(P))) == 3) {
      return (Tentara(ElmtBan(B, Info(P))) < 40);

    } else /* Level(ElmtBan(B, Info(P))) == 4 */ {
      return (Tentara(ElmtBan(B, Info(P))) < 50);

    }
  }
}

void TambahTentara (List L, Bangunan * B, urutan X) {
/* I.S. List L terdefinisi
        Bangunan B terdefinisi
        X pasti ada di dalam List
        CheckTentara bernilai true */
/* F.S. Bangunan ke-X ditambah jumlah sesuai dengan tipe bangunan itu */

  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  P = Search(L, X);
  if (Name(ElmtBan(*B, Info(P))) == 'C') {
    if (Level(ElmtBan(*B, Info(P))) == 1) {
      Tentara(ElmtBan(*B, Info(P))) += 10;

    } else if (Level(ElmtBan(*B, Info(P))) == 2) {
      Tentara(ElmtBan(*B, Info(P))) += 15;

    } else if (Level(ElmtBan(*B, Info(P))) == 3) {
      Tentara(ElmtBan(*B, Info(P))) += 20;

    } else /* Level(ElmtBan(*B, Info(P))) == 4 */ {
      Tentara(ElmtBan(*B, Info(P))) += 25;

    }
  } else if (Name(ElmtBan(*B, Info(P))) == 'T') {
    if (Level(ElmtBan(*B, Info(P))) == 1) {
      Tentara(ElmtBan(*B, Info(P))) += 5;

    } else if (Level(ElmtBan(*B, Info(P))) == 2) {
      Tentara(ElmtBan(*B, Info(P))) += 10;

    } else if (Level(ElmtBan(*B, Info(P))) == 3) {
      Tentara(ElmtBan(*B, Info(P))) += 20;

    } else /* Level(ElmtBan(*B, Info(P))) == 4 */ {
      Tentara(ElmtBan(*B, Info(P))) += 30;

    }
  } else if (Name(ElmtBan(*B, Info(P))) == 'F') {
    if (Level(ElmtBan(*B, Info(P))) == 1) {
      Tentara(ElmtBan(*B, Info(P))) += 10;

    } else if (Level(ElmtBan(*B, Info(P))) == 2) {
      Tentara(ElmtBan(*B, Info(P))) += 20;

    } else if (Level(ElmtBan(*B, Info(P))) == 3) {
      Tentara(ElmtBan(*B, Info(P))) += 30;

    } else /* Level(ElmtBan(*B, Info(P))) == 4 */ {
      Tentara(ElmtBan(*B, Info(P))) += 40;

    }
  } else /* Name(ElmtBan(*B, Info(P))) == 'V' */ {
    if (Level(ElmtBan(*B, Info(P))) == 1) {
      Tentara(ElmtBan(*B, Info(P))) += 5;

    } else if (Level(ElmtBan(*B, Info(P))) == 2) {
      Tentara(ElmtBan(*B, Info(P))) += 10;

    } else if (Level(ElmtBan(*B, Info(P))) == 3) {
      Tentara(ElmtBan(*B, Info(P))) += 15;

    } else /* Level(ElmtBan(*B, Info(P))) == 4 */ {
      Tentara(ElmtBan(*B, Info(P))) += 20;

    }
  }

}

void TambahAllTentara (List L, Bangunan * B) {
/* I.S. List L terdefinisi
        Bangunan B terdefinisi */
/* F.S. Bangunan yang dimiliki oleh pemain mengalami jumlah tentaranya 
        bertambah */       

  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  P = First(L);

  while (P != Nil) {
    
  }
}        

/*********************** ATTACK ****************************/

boolean CheckAttackTentara (Bangunan B, urutan X, int N);
/* Mengecek apakah bangunan ke-X memiliki jumlah tentara yang >= N */
/* Jika iya maka True dan sebaliknya */

void TentaraAttack (List * L, Bangunan * B, urutan X, int N);
/* I.S. List L terdefinisi 
        Bangunan B terdefinisi
        X pasti ada di dalam List 
        Jumlah N pasti normal (sudah dicek pakai CheckAttackTentara) */
/* F.S. Bangunan ke-X mengalami pengurangan jumlah tentara sebesar N */        

void TentaraAbsolute (List * L, Bangunan * B, urutan X);
/* I.S. List L terdefinisi
        Bangunan B terdefinisi
        X pasti ada di dalam List */
/* F.S. Bangunan ke-X yang memiliki jumlah tentara <= 0 dimutlakkan
        nilai jumlahnya */         
