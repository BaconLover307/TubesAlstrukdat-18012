/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518012 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* Debugging Program "Graph" */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graph.h"

int main() {
  /* KAMUS */
  Graph G;
  List L1, L2;
  Bangunan B;
  int N, X, Y;

  /* ALGORITMA */
  MakeEmptyGraph(&G);

  N = 5;
  AddParent(&G, N);

  X = 1; Y = 3;
  AddRelation(&G, X, Y);
  X = 3; Y = 1;
  AddRelation(&G, X, Y);
  X = 2; Y = 5;
  AddRelation(&G, X, Y);
  X = 5; Y = 2;
  AddRelation(&G, X, Y);
  X = 1; Y = 5;
  AddRelation(&G, X, Y);
  X = 5; Y = 1;
  AddRelation(&G, X, Y);
  X = 2; Y = 4;
  AddRelation(&G, X, Y);
  X = 4; Y = 2;
  AddRelation(&G, X, Y);

  TulisGraph(G);

  CreateEmptyList(&L1); CreateEmptyList(&L2);
  MakeEmptyBangunan(&B, 5);
  Neff(B) = 5;

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

  X = 1;
  if (CheckAttack(G, L1, X)) {
    printf("Bangunan ke-1 dapat menyerang lawan.\n");
  }

  printf("Daftar bangunan yang dapat diserang oleh bangunan ke-1:\n");
  PrintAttack(G, L1, B, X);

  printf("Daftar bangunan terdekat dengan bangunan ke-1:\n");
  PrintMove(G, L1, B, X);

  return 0;
}
