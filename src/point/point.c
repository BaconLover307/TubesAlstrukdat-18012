/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518012 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File body: point.c */

#include <stdio.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void MakePOINT (POINT * P, int X, int Y) {
/* Membentuk sebuah POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* I.S. P sembarang   */
/* F.S. P terdefinisi */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  Absis(*P) = X;
  Ordinat(*P) = Y;
}

/* TULIS dengan Output Device */
void TulisPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  printf("(%d, %d)", Absis(P), Ordinat(P));
}

POINT CopyPOINT (POINT P) {
  POINT ret;
  MakePOINT(&ret,Absis(P),Ordinat(P));
  return ret;
}
