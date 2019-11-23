/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518012 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File header: graph.h */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "listlinier.h"

#define Nil NULL

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
#define InfoG2(P2)    (P2)->infoG2
#define NextChild(P2) (P2)->NextChild
#define FirstG(L)     ((L).FirstG)

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Graph kosong  */

/* I.S. sembarang */
/* F.S. Terbentuk graph kosong */
void MakeEmptyGraph (Graph * G);

/****************** Manajemen Memori ******************/

/* Mengirimkan addrGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrGraph tidak Nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil, FirstChild(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
addrGraph AlokasiGraph1 (urutan X);

/* Mengirimkan addrGraph2 hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrGraph2 tidak Nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
addrGraph2 AlokasiGraph2 (urutan X);

/* I.S. P terdefinisi; */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrGraph P */
void DealokasiGraph1 (addrGraph * G);

/* I.S. P terdefinisi; */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrGraph2 P */
void DealokasiGraph2 (addrGraph2 * G2);

/* ********** TEST GRAPH KOSONG ********** */

/* Mengirimkan true jika Graph G kosong, mengirimkan false jika tidak */
boolean IsEmptyGraph (Graph G);

/* *** Test tabel penuh *** */

/* Mengirimkan true jika Graph G penuh, mengirimkan false jika tidak */
boolean IsFullGraph (Graph G);
// ? Entah perlu fungsi ini gak ya?

/* Mengirimkan true jika addrGraph P kosong, mengirimkan false jika tidak */
boolean IsEmptyParent (addrGraph P);


/* ********** KELOMPOK BACA/TULIS ********** */

/* I.S. Graph G terdefinisi */
/* F.S. Graph G berisi hubungan-hubungan antar bangunan */
void BacaGraph (Graph * G);
// ! Ingat MakeEmptyGraph dan AddParent dulu
// TODO: Prosedur ini dimasukkan ke ADT Mesin Kata

/* I.S. G terdefinisi */
/* F.S. Hubungan antar bangunan ditampilkan ke layar.
        Jika tidak ada hubungan maka muncul '0' di layar.
        Jika ada hubungan maka muncul '1' di layar.       */
/* Contoh: menulis matriks 3x3
0 1 1
1 0 0
1 0 0
*/
void TulisGraph (Graph G);
// ? Untuk debugging doang kayaknya

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/

/* I.S. Graph G terdefinisi */
/* F.S. Semua elemen parent dimasukkan ke graph secara berurut */
void AddParent (Graph * G, int N);

/* I.S. Graph G terdefinisi */
/* F.S. Bangunan ke-X dinyatakan memiliki hubungan dengan bangunan ke-Y */
void AddRelation (Graph * G, urutan X, urutan Y);

/****************** PROSES SEMUA ELEMEN PARENT GRAPH ******************/

/* Mengirimkan banyaknya elemen parent graph; mengirimkan 0 jika graph kosong */
int NbElmtGraph (Graph G);

/****************** PENCARIAN SEBUAH GRAPH CHILD ******************/
/* Mencari apakah ada elemen parent graph dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
addrGraph SearchP (Graph G, urutan X);

/* Mencari apakah ada elemen anak graph dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
addrGraph2 SearchChild (addrGraph P, urutan X);

/******************* RELATION **********************/

/* Mengecek apakah bangunan ke-X memiliki hubungan dengan bangunan ke-Y
   atau tidak */
/* Jika iya maka True dan sebaliknya */
boolean CheckRelation (Graph G, urutan X, urutan Y);

/******************* ATTACK *********************/

/* Mengecek apakah bangunan ke-X yang dimiliki oleh suatu pemain dapat
   menyerang bangunan yang tidak dimilikinya atau tidak */
/* Jika iya maka True dan sebaliknya */
boolean CheckAttack (Graph G, List L, urutan X);

/* I.S. Graph G terdefinisi
        List L terdefinisi
        Bangunan B terdefinisi
        X pasti ada di dalam L */
/* F.S. Jika ada bangunan yang bisa diserang maka akan muncul pilihan-
        pilihan bangunan yang dapat diserang
        Jika tidak ada maka muncul "Tidak ada bangunan yang dapat
        diserang" di layar */
void PrintAttack (Graph G, List L, Bangunan B, urutan X, int * Count);

int GetIdxAttack (Graph G, List L, Bangunan B, urutan X, int pos);
/************ MOVE TENTARA ******************/

/* Mengecek apakah bangunan ke-X yang dimiliki oleh suatu pemain dapat
   mengirimkan tentara bangunan lain yang dimilikinya atau tidak */
/* Jika iya maka True dan sebaliknya */
boolean CheckMove (Graph G, List L, urutan X);

/* I.S. Graph G terdefinisi
        List L terdefinisi
        Bangunan B terdefinisi
        X pasti ada di dalam L */
/* F.S. Jika ada bangunan yang memiliki hungan dengan bangunan ke-X
        yang dimiliki oleh pemain itu maka muncul pilihan-pilihan bangunan
        yang dapat ditambahkan jumlah tentaranya.
        Jika tidak ada maka muncul "Tidak ada bangunan terdekat" di
        layar */
void PrintMove (Graph G, List L, Bangunan B, urutan X, int * Count);

int GetIdxMove (Graph G, List L, Bangunan B, urutan X, int pos);

#endif
