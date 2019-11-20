/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518012 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* Debugging Program "Point" */

#include <stdio.h>
#include "point.h"

int main() {
  /* KAMUS */
  POINT P;
  int X, Y;

  /* ALGORITMA */
  scanf("%d %d", &X, &Y);
  MakePOINT(&P, X, Y);
  TulisPOINT(P);

  return 0;
}
