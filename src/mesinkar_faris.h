/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518015 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* File: mesinkar.h */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"
/* State Mesin */
extern char CC;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != EOF
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = EOF
          Jika  CC = EOF maka config akan menutup */

#endif
