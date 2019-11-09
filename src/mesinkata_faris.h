/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkar_faris.h"
#include "matriks_daniel.h"

#define NMax 50
#define BLANK1 ' '
#define BLANK2 '\n'

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

/* File: mesinkata.c */
/* Implementasi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include "matriks.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK1 atau CC ≠ BLANK2 */

void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void PrintKata (Kata K);
/* I.S. Kata K terdefinisi */
/* F.S. K tercetak di layar tanpa karakter tambahan di awal maupun di akhir */

int KataToInt (Kata K);
/* Kata K berisi integer dalam bentuk kata, mengkonversinya ke int */

char KataToChar (Kata K);
/* K.Length = 1 , mengeluarkan konversi K ke char */

void CopyKata(Kata K1,Kata *K2);
/* I.S. K1 terdefinsi, K2 sembarang */
/* F.S. K2 merupakan copyan dari K1, berisi sama dengan K1 */

info_bangunan KataToInfo(Kata K1, Kata K2, Kata K3);
/* Membaca kata yang telah diberikan menjadi bagian info_bangunan dalam array. */

Bangunan KataToBangunan(int MaxEl);
/* Membaca kata yang telah diberikan menjadi array bangunan. */

MATRIKS KataToMatriks(int MaxNB, int MaxNK, Bangunan B);
/* Membaca kata yang telah diberikan menjadi matriks. */

void KonfigKata();
/* Proses penuh konfigurasi file config.txt melalui mesinkata */

#endif
