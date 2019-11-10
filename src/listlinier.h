/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File header: listlinier.h */

/* urutan adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"
#include "array.h"

#define Nil NULL

typedef int urutan;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	urutan info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (urutan X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, urutan X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVPrio (List * L, urutan X);
// ! Tambah bangunan selalu pakai prosedur ini    
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list sesuai urutan X menaik: elemen yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertAfter (List *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertPrio (List * L, address P);
/* I.S. P sudah dialokasi */
/* F.S. Insert P sebagai elemen yang tersusun berdasarkan urutan X */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelP (List * L, urutan X);
/* I.S. L terdefinisi
        X pasti ada di dalam List */
/* F.S. X dihilangkan dari List  */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L, Bangunan B);
/* I.S. List tidak kosong */
/* F.S. Mencetak bangunan-bangunan yang dimiliki ke layar dengan 
        elemen-elemen tertentu (Nama, Posisi, Jumlah Tentara, Level) */
/* Contoh : 
    1. Castle (1,15) 20 lv. 3
    2. Tower (1,13) 50 lv. 1
    3. Castle (3,14) 30 lv. 2                                        */
int NbElmtList (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*************** PENAMBAHAN TENTARA TIAP RONDE *********************/
boolean CheckTambahTentara (Bangunan B, urutan X);
/* X pasti ada di dalam List */
/* Mengecek apakah bangunan ke-X yang dimiliki oleh pemain tertentu sudah 
   melewati maksimum penambahan pasukan atau belum */
/* Jika belum maka true dan sebaliknya */

void TambahTentara (Bangunan * B, urutan X);
/* I.S. List L terdefinisi
        Bangunan B terdefinisi
        X pasti ada di dalam List
        CheckTentara bernilai true */
/* F.S. Bangunan ke-X ditambah jumlah sesuai dengan tipe bangunan itu */

void TambahAllTentara (List L, Bangunan * B);
/* I.S. List L terdefinisi
        Bangunan B terdefinisi */
/* F.S. Bangunan yang dimiliki oleh pemain mengalami jumlah tentaranya 
        bertambah */       
         
#endif
