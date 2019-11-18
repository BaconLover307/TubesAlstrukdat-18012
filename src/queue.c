/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* Program          : queue.c */
/* Deskripsi        : Implementasi ADT Queue */
/* Definisi Queue   : Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsQEmpty (Queue Q) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == QNil) && (Tail(Q) == QNil);
}


boolean IsQFull (Queue Q) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxQEl */
    return ((Head(Q) == 1) && (Tail(Q) == MaxQEl(Q))) || ((Tail(Q) == Head(Q)-1));
}


int NBQElmt (Queue Q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsQEmpty(Q)) {
        return 0;
    } else if (Tail(Q) < Head(Q)) {
        return (Tail(Q) - Head(Q) + MaxQEl(Q) + 1);
    } else {return (Tail(Q) - Head(Q) + 1);}
    
}


/* *** Kreator *** */
void CreateQueue (Queue * Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxQEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (Qinfotype *)malloc((Max + 1) * sizeof(Qinfotype));
    if ((*Q).T != NULL) {
        MaxQEl(*Q) = Max;
        Head(*Q) = QNil;
        Tail(*Q) = QNil;
    } else { //  ! alokasigagal
        MaxQEl(*Q) = 0;
    }
}


/* *** Destruktor *** */
void QDeAlokasi(Queue * Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxQEl(Q) diset 0 */
    MaxQEl(*Q) = 0;
    free((*Q).T);
}


/* *** Primitif Add/Delete *** */
void QAdd (Queue * Q, Qinfotype X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q mungkin penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

    // $ Kamus Lokal
    Qaddress i, j;
    // $ Algoritma

    if (IsQEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        strcpy(InfoTail(*Q), X);
    } 
    
    else if (!(IsQFull(*Q))) { // * Q tidakkosong
        if (Tail(*Q) == MaxQEl(*Q)) { // * Geser elemen smp Head(Q)=1
            Tail(*Q) = 1;
        } else {
            Tail(*Q)++;
        }
        strcpy(InfoTail(*Q), X);
    }
    
    else { // * Q full
        printf("Anda telah memiliki 10 skill. Tidak bisa menambah skill lagi.\n");
    }
}


void QDel (Queue * Q, Qinfotype * X) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = QNilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
    Q mungkin kosong */
    strcpy(*X,InfoHead(*Q));
    if (Head(*Q) == Tail(*Q)) { // * Set menjadi queue kosong
        Head(*Q) = QNil;
        Tail(*Q) = QNil;
    } else {
        Head(*Q)++;
    }
}

void PrintInfoHead (Queue Q){
/* I.S. Q mungkin kosong */
/* F.S. Jika Q kosong, menuliskan none ke layar, jika Q tidak kosong menuliskan elemen head ke layar */

    // $ Kamus Lokal
    char skil [10];

    // $ Algoritma
    if (IsQEmpty(Q)){
        printf("none");
    }

    else{
        strcpy(skil, InfoHead(Q));
        printf("%s", skil);
    }
}

void PrintQueue(Queue Q) {
    /* I.S. Q mungkin kosong */
    /* F.S. Jika Q kosong, menuliskan none ke layar, jika Q tidak kosong menuliskan elemen head ke layar */

    // $ Kamus Lokal
    Qinfotype skil;

    // $ Algoritma
    if (IsQEmpty(Q)){
        printf("[ none ]");
    } else {
        printf("[ ");
        PrintInfoHead(Q);
        if (NBQElmt(Q) > 1) {
            for (int i = Head(Q)+1; i <= Tail(Q); i++) {
                printf(" | ");
                strcpy(skil, Q.T[i]);
                printf("%s", skil);
            }
        }
        printf(" ]\n");
    }
}
