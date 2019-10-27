/* Program          : stackt.c */
/* Deskripsi        : Implementasi Stackt */
/* Definisi Queue   : Model Implementasi dengan tabel kontigu dan ukuran sama */

#include "stackt.h"
#include <stdio.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S) {
    Top(*S) = SNil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxSEl */
/* jadi indeksnya antara 1.. MaxSEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP berSnilai SNil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S) {
    return (Top(S) == SNil); 
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S) {
    return (Top(S) == MaxSEl);
}
/* Mengirim true jika tabel penampung Snilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Sinfotype X) {
    Top(*S) += 1;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, Sinfotype* X) {
    *X = InfoTop(*S);
    Top(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Snilai elemen TOP yang lama, TOP berkurang 1 */
