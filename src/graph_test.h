/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File header: graph_test.h */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "listlinier.h"

typedef struct tElmtGraph *addrGraph;
typedef struct tElmtGraph2 *addrGraph2;

typedef struct tElmtGraph {
  int infoG;
  addrGraph NextParent;
  addrGraph2 FirstChild;
} ElmtGraph;

typedef struct tElmtGraph2 {
  int infoG2;
  addrGraph2 NextChild;
} ElmtGraph2;

typedef struct {
  addrGraph FirstG;
} Graph;

/* Definisi Graph :
  Graph utama (G) kosong : FirstG(G) = Nil
  Graph anak (G2) kosong : FirstChild(G2) = Nil
/* Setiap elemen dengan addrGraph P dapat diacu InfoG(P), NextP(P), FirstChild(P) */
/* Setiap elemen dengan addrGraph2 P2 dapat diacu InfoG2(P2), NextChild(P2) */
/* Elemen terakhir graph utama : jika addressnya Last, maka Next(Last)=Nil */
/* Elemen terakhir graph anak  : jika addressnya Last2, maka Next(Last2)=Nil */

/* ********** SELEKTOR ********** */
#define InfoG(P)      (P)->infoG
#define NextP(P)      (P)->NextParent
#define FirstChild(P) (P)->FirstChild
#define FirstG(L) ((L).First)

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

void PrintAttack (Graph G, List L, Bangunan B, urutan X);
/* I.S. Graph G terdefinisi
        List L terdefinisi 
        Bangunan B terdefinisi
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

void PrintMove (Graph G, List L, Bangunan B, urutan X);
/* I.S. Graph G terdefinisi
        List L terdefinisi 
        Bangunan B terdefinisi 
        X pasti ada di dalam L */
/* F.S. Jika ada bangunan yang memiliki hungan dengan bangunan ke-X
        yang dimiliki oleh pemain itu maka muncul pilihan-pilihan bangunan
        yang dapat ditambahkan jumlah tentaranya.
        Jika tidak ada maka muncul "Tidak ada bangunan terdekat" di 
        layar */

#endif  