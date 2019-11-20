/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518012 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File header: matriks.h */

/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "array.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define KolMin 1

#define ValUndef 0
/* Nilai elemen tak terdefinisi */

typedef int indeks; /* indeks baris, kolom */
typedef int ElType;
typedef struct {
    ElType **Mem; /* memori tempat penyimpan elemen (container) */
    int MaxBrs; /* ukuran elemen baris */
    int MaxKol; /* ukuran elemen kolom */
} MATRIKS;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M);
// ! NB dan NK didapat dari Configure */
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK dengan
   elemen yang tidak terdefinisi */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxBrs + 1 dan MaxKol + 1 */

void DealokasiMatriks (MATRIKS * M);
/* I.S. M terdefinisi; */
/* F.S. Mem(M) dikembalikan ke system, MaxBrs(M)=0; MaxKol(M)=0 */

/* *** Selektor *** */
#define MaxBrs(M)   (M).MaxBrs
#define MaxKol(M)   (M).MaxKol
#define Mem(M)      (M).Mem
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, Bangunan B);
/* I.S. Matriks M terdefinisi
        Bangunan B terdefinisi */
/* F.S. Indeks Bangunan dimasukkan ke dalam Matriks */
void TulisMATRIKS (MATRIKS M);
// ? Untuk debugging doang kayaknya
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** Operasi lain ********** */
int NBElmtMatriks (MATRIKS M);
// ? Untuk debugging doang
/* Mengirimkan banyaknya elemen M */

#endif
