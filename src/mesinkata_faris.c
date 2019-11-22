/* File: mesinkata.c */
/* Implementasi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkata_faris.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank()
{
  while ((CC == BLANK1)||(CC == BLANK2)) {
    ADV();
  }
}

void STARTKATA()
{
  START();
  IgnoreBlank();
  SalinKata();
}

void ADVKATA()
{
  IgnoreBlank();
  SalinKata();
  IgnoreBlank();
}

void SalinKata()
{
    int i = 1;
    while ((CC != BLANK1) && (CC != BLANK2) && (i <= NMax)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i;
}

void PrintKata (Kata K)
{
  int i = 1;
  while (i<K.Length)
  {
    printf("%c", K.TabKata[i]);
    i++;
  }
}

int KataToInt (Kata K)
{
  int val = 0;
  int i = 0;
  while (i<K.Length)
  {
    val = val * 10;
    switch (K.TabKata[i]){
      case '0' : val += 0; break;
      case '1' : val += 1; break;
      case '2' : val += 2; break;
      case '3' : val += 3; break;
      case '4' : val += 4; break;
      case '5' : val += 5; break;
      case '6' : val += 6; break;
      case '7' : val += 7; break;
      case '8' : val += 8; break;
      case '9' : val += 9; break;
    };
    i++;
  }
  return val;
}

char KataToChar (Kata K)
{
    return (K.TabKata[1]);
}

void CopyKata(Kata K1,Kata *K2)
{
    (*K2).Length = K1.Length;
    int i,len = K1.Length;
    for (i = 0;i<len;++i)
    {
        (*K2).TabKata[i] = K1.TabKata[i];
    }
}

info_bangunan KataToInfo(Kata K1, Kata K2, Kata K3)
{
  info_bangunan info;
  Name(info) = KataToChar(K1);
  MakePOINT(&Posisi(info),KataToInt(K2), KataToInt(K3));
  Level(info) = 1;
  if (Name(info) == 'C') {
    Tentara(info) = 40;
  }
  else if (Name(info) == 'T') {
    Tentara(info) = 30;
  }
  else if (Name(info) == 'F') {
    Tentara(info) = 80;
  }
  else if (Name(info) == 'V') {
    Tentara(info) = 20;
  }
  Moved(info) = false;
  Attacked(info) = false;
  return info;
}

Bangunan KataToBangunan(int MaxEl)
{
  Bangunan B;
  int i;
  Kata Ka, Kb, Kc;
  MakeEmptyBangunan(&B, MaxEl);
  for (i = 1; i <= MaxEl; i++) {
    Ka = CKata;
    ADVKATA();
    Kb = CKata;
    ADVKATA();
    Kc = CKata;
    ElmtBan(B, i) = KataToInfo(Ka, Kb, Kc);
    ADVKATA();
  }
    Neff(B) = MaxEl;
    return B;
  }


MATRIKS KataToMatriks(int MaxNB, int MaxNK, Bangunan B)
{
  MATRIKS M;
  int i;
  MakeMATRIKS(MaxNB, MaxNK, &M);
  BacaMATRIKS(&M, B);
  return M;
}

Graph KataToGraph(int MaxEl)
{
  Graph G;
  int i, j;
  MakeEmptyGraph(&G);
  AddParent(&G,MaxEl);
  for (i = 1; i <= MaxEl; i++) {
    for (j = 1; j <= MaxEl; j++) {
      if (KataToInt(CKata) == 1) {
        AddRelation(&G, i, j);
      }
        ADVKATA();
    }
  }
  return G;
}