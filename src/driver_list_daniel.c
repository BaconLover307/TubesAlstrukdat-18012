/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* Debugging Program "List Linier" */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "listlinier_daniel.h"

int main() {
  /* KAMUS */
  Bangunan B;
  List L1, L2;
  int X, Y;

  /* ALGORITMA */
  CreateEmptyList(&L1); CreateEmptyList(&L2);

  if (IsEmptyList(L1)) {
    printf("Bangunan pada pemain pertama kosong.\n");
  }

  Name(ElmtBan(B, 1)) = 'C';
  X = 10; Y = 1; MakePOINT(&Posisi(ElmtBan(B, 1)), X, Y);
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

  InsVPrio(&L1, 1); InsVPrio(&L1, 3);
  InsVPrio(&L2, 2); InsVPrio(&L2, 4);
  printf("Pemain ke-1\n");
  printf("Memiliki %d bangunan.\n", NbElmtList(L1));
  PrintInfo(L1, B);
  printf("\n");

  printf("Pemain ke-2 mau menyerang bangunan ke-3 yang dimiliki oleh Pemain 1.\n");
  printf("Tentara sebesar 30 orang dari Bangunan ke-4.\n");

  TentaraAttack(&B, 4, 30);
  TentaraInvaded(&B, 3, 30);
  if (CanCapture(B, 3)) {
    if (Search(L1, 3)) {
      printf("Bangunan ke-3 yang dimiliki oleh Pemain ke-1 telah dikuasai oleh Pemain ke-2.\n\n");
      DelP(&L1, 3);
    }
    InsVPrio(&L2, 3);
    TentaraAbsolute(&B, 3);
  }

  printf("Pemain ke-1\n");
  PrintInfo(L1, B);
  printf("\n");

  printf("Pemain ke-2\n");
  PrintInfo(L2, B);
  printf("\n");

  TambahAllTentara(L2, &B);
  printf("Setelah pemain ke-2 mengalami penaikan jumlah tentara.\n");
  PrintInfo(L2, B);
  printf("\n");

  printf("Pemain ke-1 mau melakukan Level Up pada bangunan ke-1.\n");
  LevelUp(&B, 1);
  PrintInfo(L1, B);

  return 0;
}