/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* Debugging Program "Matrix" */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "matriks.h"

int main() {
  /* KAMUS */
  MATRIKS M;
  Bangunan B;
  int X, Y;

  /* ALGORITMA */
  MakeMATRIKS(10, 20, &M);
  MakeEmptyBangunan(&B, 5);

  Name(ElmtBan(B, 1)) = 'C';
  X = 5; Y = 1; MakePOINT(&Posisi(ElmtBan(B, 1)), X, Y);
  Level(ElmtBan(B, 1)) = 1;
  Tentara(ElmtBan(B, 1)) = 40;

  Name(ElmtBan(B, 2)) = 'C';
  X = 1; Y = 15; MakePOINT(&Posisi(ElmtBan(B, 2)), X, Y);
  Level(ElmtBan(B, 2)) = 1;
  Tentara(ElmtBan(B, 2)) = 40;

  Name(ElmtBan(B, 3)) = 'V';
  X = 1; Y = 9; MakePOINT(&Posisi(ElmtBan(B, 3)), X, Y);
  Level(ElmtBan(B, 3)) = 1;
  Tentara(ElmtBan(B, 3)) = 20;

  Name(ElmtBan(B, 4)) = 'T';
  X = 1; Y = 13; MakePOINT(&Posisi(ElmtBan(B, 4)), X, Y);
  Level(ElmtBan(B, 4)) = 1;
  Tentara(ElmtBan(B, 4)) = 30;

  Name(ElmtBan(B, 5)) = 'C';
  X = 2; Y = 3; MakePOINT(&Posisi(ElmtBan(B, 5)), X, Y);
  Level(ElmtBan(B, 5)) = 1;
  Tentara(ElmtBan(B, 5)) = 40;
  
  Neff(B) = 5;

  BacaMATRIKS(&M, B);
  TulisMATRIKS(M);

  printf("\n");
  printf("Banyak elemen matriks = %d\n", NBElmtMatriks(M));

  return 0;
}