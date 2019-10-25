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
/* yaitu mengandung elemen sebanyak MaxEl */
    return ((Head(Q) == 1) && (Tail(Q) == MaxEl(Q))) || ((Tail(Q) == Head(Q)-1));
}


int NBQElmt (Queue Q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsQEmpty(Q)) {
        return 0;
    } else if (Tail(Q) < Head(Q)) {
        return (Tail(Q) - Head(Q) + MaxEl(Q) + 1);
    } else {return (Tail(Q) - Head(Q) + 1);}
    
}


/* *** Kreator *** */
void CreateQueue (Queue * Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotype *)malloc((Max + 1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = QNil;
        Tail(*Q) = QNil;
    } else { //  ! alokasigagal
        MaxEl(*Q) = 0;
    }
}


/* *** Destruktor *** */
void QDeAlokasi(Queue * Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    MaxEl(*Q) = 0;
    free((*Q).T);
}


/* *** Primitif Add/Delete *** */
void QAdd (Queue * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

    // $ Kamus Lokal
    Qaddress i, j;
    // $ Algoritma

    if (IsQEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
    } else { // * Q tidakkosong
        if (Tail(*Q) == MaxEl(*Q)) { // * Geser elemen smp Head(Q)=1
            Tail(*Q) = 1;
        } else {
            Tail(*Q)++;
        }
    }
    strcpy(InfoTail(*Q), X);
}


void QDel (Queue * Q, infotype * X) {
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

