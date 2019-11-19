/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
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

  /* ALGORITMA */
  MakeEmptyGraph(&G);
  AddParent(&G, 5);
  AddRelation(&G, 1, 3);
  AddRelation(&G, 3, 1);
  AddRelation(&G, 2, 5);
  AddRelation(&G, 5, 2);
  TulisGraph(G);

  return 0;
}