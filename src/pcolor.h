/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

/**
Details

print_xxx(c) will print c with xxx color. Import this header to use the declared functions.
We only provide 8 colors. Feel free to modify/add colors if you want to.
**/

/* Definisi elemen dan koleksi objek */
typedef char Warna;
/*
#include "player.h"
typedef int IdxType;  // type indeks
typedef Warna ElType; // type elemen tabel

typedef struct {
    ElType TW[6]; // memori tempat penyimpan elemen (container)
    int Neff      // >=0, banyaknya elemen efektif
} TabColor;

#define Neff(T) (T).Neff
#define TW(T) (T).TW
#define Elmt(T, i) (T).TW[(i)]
*/
#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"

//void MakeBukuWarna(TabColor * ArrWarna);

//void printBukuWarna(TabColor ArrWarna);

void print_warna(Warna Col, char c);

