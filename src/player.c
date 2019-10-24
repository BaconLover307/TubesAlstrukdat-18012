/* File : player.c */
/* Implementasi ADT Player */

#include "player.h"
#include <stdio.h>

// $ ********* Prototype *********
boolean IsLose(listBangunan B) {
    return NBBangunan(B) == 0;
}
/* *** Kreator *** */
void CreatePlayer(Player *P, warna C) {
    
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

// $ *** Primitif ***
