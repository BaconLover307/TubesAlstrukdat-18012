/* Program          : queue.c */
/* Deskripsi        : Implementasi ADT Queue */
/* Definisi Queue   : Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsQEmpty (Queue Q) {
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsQFull (Queue Q) {
    return ((Head(Q) == 1) && (Tail(Q) == MaxEl(Q))) || ((Tail(Q) == Head(Q)-1));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBQElmt (Queue Q) {
    if (IsEmpty(Q)) {
        return 0;
    } else if (Tail(Q) < Head(Q)) {
        return (Tail(Q) - Head(Q) + MaxEl(Q) + 1);
    } else {return (Tail(Q) - Head(Q) + 1);}
    
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateQueue (Queue * Q, int Max) {
    (*Q).T = (infotype *)malloc((Max + 1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else { //  ! alokasigagal
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void QDeAlokasi(Queue * Q) {
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void QAdd (Queue * Q, infotype X) {
    // $ Kamus Lokal
    address i, j;
    // $ Algoritma
    if (IsEmpty(*Q)) {
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
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

void QDel (Queue * Q, infotype * X) {
    strcpy(*X,InfoHead(*Q));
    if (Head(*Q) == Tail(*Q)) { // * Set menjadi queue kosong
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q)++;
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
