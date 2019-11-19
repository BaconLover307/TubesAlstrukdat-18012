/* File: mesinkata.c */
/* Implementasi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkata_faris.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK1 atau CC ≠ BLANK2 */
{
  while ((CC == BLANK1)||(CC == BLANK2))
  {
    ADV();
  }
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  START();
  IgnoreBlank();
  SalinKata();
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  IgnoreBlank();
  SalinKata();
  IgnoreBlank();
}

void SalinKata() 
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 1;
    while ((CC != BLANK1) && (CC != BLANK2) && (i <= NMax)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i-1;
}

void PrintKata (Kata K)
/* I.S. Kata K terdefinisi */
/* F.S. K tercetak di layar tanpa karakter tambahan di awal maupun di akhir */
{
  int i = 0;
  while (i<K.Length)
  {
    printf("%c", K.TabKata[i]);
    i++;
  }
}

int KataToInt (Kata K)
/* Kata K berisi integer dalam bentuk kata, mengkonversinya ke int */
{
  int val = 0;
  int i = 0;
  while (i<K.Length)
  {
    val *= 10;
    val += (int) (CKata.TabKata[i] - '0');
    ADV();
    i++;
  }
  return val;
}

char KataToChar (Kata K)
/* K.Length = 1 , mengeluarkan konversi K ke char */
{
    return (K.TabKata[0]);
}

void CopyKata(Kata K1,Kata *K2)
/* I.S. K1 terdefinsi, K2 sembarang */
/* F.S. K2 merupakan copyan dari K1, berisi sama dengan K1 */
{
    (*K2).Length = K1.Length;
    int i,len = K1.Length;
    for (i = 0;i<len;++i)
    {
        (*K2).TabKata[i] = K1.TabKata[i];
    }
}

info_bangunan KataToInfo(Kata K1, Kata K2, Kata K3)
/* Membaca kata yang telah diberikan menjadi bagian info_bangunan dalam array. */
{
  info_bangunan info;
  Name(info) = KataToChar(K1);
  MakePOINT(&Posisi(info),KataToInt(K2), KataToInt(K3));
  Level(info) = 1;
  Tentara(info) = 0;
  return info;
}

Bangunan KataToBangunan(int MaxEl)
/* Membaca kata yang telah diberikan menjadi array bangunan. */
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
    return B;
  }
}

MATRIKS KataToMatriks(int MaxNB, int MaxNK, Bangunan B)
/* Membaca kata yang telah diberikan menjadi matriks. */
{
  MATRIKS M;
  int i;
  MakeMATRIKS(MaxNB, MaxNK, &M);
  BacaMATRIKS(&M, B);
  return M;
}

Graph KataToGraph(int NB, int NK, int MaxEl)
/* Membaca file yang telah diberikan menjadi graph. */
{
  Graph G;
  int i, j;
  MakeEmptyGraph(&G, MaxEl);
  for (i = 1; i <= NB; i++) {
    for (j = 1; j <= NK; j++) {
      if (KataToInt(CKata) == 1) {
        TambahRelation (&G, i, j);
      }
        ADVKATA(); 
    }
    ADVKATA();
  }
}