/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File header: graph.h */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "listlinier.h"

typedef struct {
  List *GI;  /* memori tempat penyimpan elemen (container) */
  int NeffG;   /* >=0, banyaknya elemen efektif */
  int MaxG;  /* ukuran elemen */
} Graph;

/* Indeks yang digunakan [IdxMin..MaxG] */
// * IdxMin sudah didefinisi pada ADT Array
/* Jika G adalah Graph, cara deklarasi dan akses: */
/* Deklarasi : G : Graph */
/* Maka cara akses:
   G.GI     untuk mengakses seluruh List pada Graph G
   G.GI[i]  untuk mengakses List ke-i 
   G.NeffG  untuk mengetahui banyaknya elemen
   G.MaxG   untuk mengetahui batas jumlah elemen Graph */    

/* Definisi :
  Graph kosong : G.NeffG = 0
  Definisi elemen pertama : G.GI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: G.GI[i] dengan i=G.NeffG */

/* ********** SELEKTOR ********** */
#define NeffG(G) (G).NeffG
#define GI(G) (G).GI
#define ElmtG(G, i) (G).GI[(i)]
#define MaxG(G) (G).MaxG

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Graph kosong  */
void MakeEmptyGraph (Graph * G, int maxel);
/* I.S. G sembarang, maxel > 0 */
/* F.S. Terbentuk tabel G kosong dengan kapasitas maxel + 1 */

void DealokasiGraph (Graph * G);
/* I.S. G terdefinisi; */
/* F.S. GI(G) dikembalikan ke system, MaxG(G)=0; NeffG(G)=0 */

/* *** Selektor INDEKS *** */
IdxType GetFirstGraph (Graph G);
/* Prekondisi : Graph G tidak kosong */
/* Mengirimkan indeks elemen G pertama */
IdxType GetLastGraph (Graph G);
/* Prekondisi : Graph G tidak kosong */
/* Mengirimkan indeks elemen G terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyGraph (Graph G);
/* Mengirimkan true jika Graph G kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullGraph (Graph G);
// ? Entah perlu fungsi ini gak ya?  
/* Mengirimkan true jika Graph G penuh, mengirimkan false jika tidak */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaGraph (Graph * G);
// ! Ingat MakeEmptyGraph dulu
// TODO: Prosedur ini dimasukkan ke ADT Mesin Kata
/* I.S. Graph G terdefinisi */
/* F.S. Graph G berisi hubungan-hubungan antar bangunan */

void TambahRelation (Graph * G, urutan X, urutan Y);
/* I.S. Graph G terdefinisi */
/* F.S. Bangunan ke-X dinyatakan memiliki hubungan dengan bangunan ke-Y */

void TulisGraph (Graph G);
// ? Untuk debugging doang kayaknya 
/* I.S. G terdefinisi */
/* F.S. Hubungan antar bangunan ditampilkan ke layar. 
        Jika tidak ada hubungan maka muncul '0' di layar.
        Jika ada hubungan maka muncul '1' di layar.       */
/* Contoh: menulis matriks 3x3 
0 1 1
1 0 0
1 0 0
*/

/******************* RELATION **********************/
boolean CheckRelation (Graph G, urutan X, urutan Y);
/* Mengecek apakah bangunan ke-X memiliki hubungan dengan bangunan ke-Y 
   atau tidak */
/* Jika iya maka True dan sebaliknya */

/******************* ATTACK *********************/
boolean CheckAttack (Graph G, List L, urutan X);
/* Mengecek apakah bangunan ke-X yang dimiliki oleh suatu pemain dapat
   menyerang bangunan yang tidak dimilikinya atau tidak */
/* Jika iya maka True dan sebaliknya */

void PrintAttack (Graph G, List L, urutan X);
/* I.S. Graph G terdefinisi
        List L terdefinisi 
        X pasti ada di dalam L */
/* F.S. Jika ada bangunan yang bisa diserang maka akan muncul pilihan-
        pilihan bangunan yang dapat diserang
        Jika tidak ada maka muncul "Tidak ada bangunan yang dapat 
        diserang" di layar */

/************ MOVE TENTARA ******************/
boolean CheckMove (Graph G, List L, urutan X);
/* Mengecek apakah bangunan ke-X yang dimiliki oleh suatu pemain dapat
   mengirimkan tentara bangunan lain yang dimilikinya atau tidak */
/* Jika iya maka True dan sebaliknya */

void PrintMove (Graph G, List L, urutan X);
/* I.S. Graph G terdefinisi
        List L terdefinisi 
        X pasti ada di dalam L */
/* F.S. Jika ada bangunan yang memiliki hungan dengan bangunan ke-X
        yang dimiliki oleh pemain itu maka muncul pilihan-pilihan bangunan
        yang dapat ditambahkan jumlah tentaranya.
        Jika tidak ada maka muncul "Tidak ada bangunan terdekat" di 
        layar */





#endif  