/* Deskripsi        : Implementasi List Linier */
/* Representasi Laddress dengan pointer */
/* Linfotype adalah integer */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* * 
* typedef int Linfotype;
* typedef struct tElmtlist *Laddress;
* typedef struct tElmtlist {
? 	Linfotype info;
? 	Laddress next;
*  } ElmtList;
* typedef struct {
?	Laddress First;
* } List;
*/

// ! Definisi list
// ? List kosong : First(L) = Nil
// ? Setiap elemen dengan Laddress P dapat diacu Info(P), Next(P)
// ? Elemen terakhir list : jika Laddressnya Last, maka Next(Last)=Nil

// ? #define Info(P) (P)->info
// ? #define Next(P) (P)->next
// ? #define First(L) ((L).First)


// $ PROTOTYPE
// $ ****************** TEST LIST KOSONG ******************
boolean IsEmpty (List L) {
    return First(L) == Nil;
}
/* Mengirim true jika list kosong */

// $ ****************** PEMBUATAN LIST KOSONG ******************
void CreateEmpty (List *L) {
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

// $ ****************** Manajemen Memori ******************
Laddress Alokasi (Linfotype X) {
    // $ Kamus Lokal
    Laddress P;
    // $ Algoritma
    P = (Laddress) malloc (sizeof (ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } else {
        return Nil;
    }
}
/* Mengirimkan Laddress hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Laddress tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (Laddress *P) {
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Laddress P */

// $ ****************** PENCARIAN SEBUAH ELEMEN LIST ******************
Laddress Search (List L, Linfotype X) {
    // $ Kamus Lokal
    Laddress P;
    boolean Found = false;
    // $ Algoritma
    if (!IsEmpty(L)) {
        P = First(L);
        while (P != Nil && !Found) {
            if (X == Info(P)) {
                Found = true;   // Jika Found maka P = Laddress dari harga yang dicari
            } else {
                P = Next(P);    // Jika not Found maka P = Nil   
            }
        }
    } else {
        P = Nil;
    }
    return P;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan Laddress elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

// $ ****************** PRIMITIF BERDASARKAN NILAI ******************
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, Linfotype X) {
    // $ Kamus Lokal
    Laddress P = Alokasi(X);
    // $ Algoritma
    if (P != Nil) {
        InsertFirst(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, Linfotype X) {
    // $ Kamus Lokal
    Laddress P = Alokasi(X);
    // $ Algoritma
    if (P != Nil) {
        InsertLast(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

// $ *** PENGHAPUSAN ELEMEN ***
void DelVFirst (List *L, Linfotype *X) {
    // $ Kamus Lokal
    Laddress P = Alokasi(*X);
    // $ Algoritma
    DelFirst(L,&P);
    *X = Info(P);
    Dealokasi(&P); 
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, Linfotype *X) {
    // $ Kamus Lokal
    Laddress P = Alokasi(*X);
    // $ Algoritma
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

// $ ****************** PRIMITIF BERDASARKAN ALAMAT ******************
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, Laddress P) {
    // $ Algoritma
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-Laddress P sebagai elemen pertama */

void InsertAfter (List *L, Laddress P, Laddress Prec) {
    // $ Algoritma
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, Laddress P) {
    // $ Kamus Lokal
    Laddress Last; // Laddress untuk transversal, menjadi Laddress element terakhir
    // $ Algoritma
    if (IsEmpty(*L)) {
        InsertFirst(L,P);
    } else {
        Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        // Next(Last) = Nil, element terakhir
        InsertAfter(L,P,Last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

// $ *** PENGHAPUSAN SEBUAH ELEMEN ***
void DelFirst (List *L, Laddress *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelP (List *L, Linfotype X) {
    // $ Kamus Lokal
    Laddress P,Prec,Phead;
    // $ Algoritma
    P = Search(*L,X);
    if (P == First(*L)) {
        DelFirst(L,&P);
        Dealokasi(&P);
    } else if (P != Nil) {
        Prec = First(*L);
        Phead = Next(First(*L));
        while (P != Phead) {
            Phead = Next(Phead); // Jika not Found maka P = Nil
            Prec = Next(Prec); // Jika not Found maka P = Nil
            }
        DelAfter(L,&P,Prec);
        }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list berLaddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, Laddress *P) {
    // $ Kamus Lokal
    Laddress Last, PrecLast;
    // $ Algoritma
    Last = First(*L);
    PrecLast = Nil;
    while (Next(Last) != Nil) {
        PrecLast = Last;
        Last = Next(Last);
    } // Next(Last) = Nil, Last element terakhir
      // PrecLast = sebelum Last
    *P = Last;
    if (PrecLast == Nil) {
        First(*L) = Nil;
    } else {
        Next(PrecLast) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, Laddress *Pdel, Laddress Prec) {
    // $ Algoritma
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

// $ ****************** PROSES SEMUA ELEMEN LIST ******************
void PrintInfo (List L) {
    // $ Kamus Lokal
    Laddress P = First(L);
    // $ Algoritma
    printf("[");
    if (P != Nil) {
        printf("%d",Info(P));
        P = Next(P);
        while (P != Nil) {
            printf(",%d",Info(P));
            P = Next(P);
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int NbElmt (List L) {
    // $ Kamus Lokal
    Laddress P = First(L);
    int count = 0;
    // $ Algoritma
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
Linfotype Max (List L) {
    // $ Kamus Lokal
    Laddress P = First(L);
    Linfotype maks = Info(P);
    // $ Algoritma
    P = Next(P);
    while (P != Nil) {
        if (maks < Info(P)) {
            maks = Info(P);
        }
        P = Next(P);
    }
    return maks;
}
/* Mengirimkan nilai Info(P) yang maksimum */

// $ ****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3) {
    // $ Kamus Lokal
    Laddress Last1;
    // $ Algoritma
    CreateEmpty(L3);
    if (IsEmpty(*L1)) {
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        Last1 = First(*L1);
        while (Next(Last1) != Nil) { // traversal Last1 sampai akhir List1
            Last1 = Next(Last1);
        }
        Next(Last1) = First(*L2);  // hubungkan Last1 dengan First(L2)
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
