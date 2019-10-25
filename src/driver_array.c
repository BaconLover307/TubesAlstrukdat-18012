/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* Debugging Program "Array" */

#include <stdio.h>
#include "array.h"

int main() {
  /* KAMUS */
  Bangunan B;
  ElType X, Y;

  /* ALGORITMA */
  MakeEmptyBangunan(&B);

  if (IsEmptyBan(B)) {
    printf("Bangunan masih kosong\n");
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

  printf("Jumlah bangunan = %d\n", NbElmtBan(B));

  if (CheckAttackTentara(B, 1, 30)) {
    printf("Bangunan ke-1 bisa menyerang dengan 30 orang.\n");
  }

  if (!CheckAttackTentara(B, 1, 50)) {
    printf("Bangunan ke-1 tidak bisa menyerang dengan 50 orang.\n");
  }

  TentaraAttack(&B, 1, 30);
  printf("Jumlah tentara pada bangunan ke-1 sekarang adalah %d.\n\n", Tentara(ElmtBan(B, 1)));

  TentaraInvaded(&B, 3, 30);
  printf("Setelah diserang oleh bangunan ke-1,\n");
  printf("Jumlah tentara pada bangunan ke-3 sekarang adalah %d.\n\n", Tentara(ElmtBan(B, 3)));
  
  if (CanCapture(B, 3)) {
    printf("Bangunan ke-3 berhasil dikuasai.\n");
    TentaraAbsolute(&B, 3);
    printf("Jumlah tentara pada bangunan ke-3 sekarang adalah %d.\n\n", Tentara(ElmtBan(B, 3)));
  }

  if (CheckLevelUp(B, 4)) {
    printf("Bangunan ke-4 dapat Level Up.\n");
    LevelUp(&B, 4);
    printf("Setelah Level Up,\n");
    printf("Jumlah tentara Bangunan ke-4 sekarang adalah %d.\n", Tentara(ElmtBan(B, 4)));
    printf("Level Bangunan ke-4 sekarang adalah %d.\n", Level(ElmtBan(B, 4)));
  }
}