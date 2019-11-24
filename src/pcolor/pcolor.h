/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/
/* *
* Catatan Asisten
print_xxx(c) will print c with xxx color. Import this header to use the declared functions.
We only provide 8 colors. Feel free to modify/add colors if you want to.
**/

#ifndef PCOLOR_H
#define PCOLOR_H

// ?  Definisi elemen dan koleksi objek
typedef char Warna; // * tipe warna
typedef int IdxType;  // * tipe indeks
#define TotalColor 6

// ? Array untuk menampung warna yang ada
typedef struct {
    Warna TW[TotalColor+1]; // * memori tempat penyimpan elemen (container)
    int ColNeff;      // * >=0, banyaknya elemen efektif
} TabColor;

#define ColNeff(T) (T).ColNeff
#define TW(T) (T).TW
#define ColElmt(T, i) (T).TW[(i)]


#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"

// * Inisialisasi Palet Warna
void MakeBukuWarna(TabColor * ArrWarna);

// * Ngeprint palet warna yang tersedia
void PrintBukuWarna(TabColor ArrWarna);

// * Print karakter c dengan warna Col
void print_warna(Warna Col, char c);

#endif
