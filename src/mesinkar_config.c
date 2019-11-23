/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar_config.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * config;
static int retval;

void START(char * C) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita.*/
    /* ALGORITMA */
    config = fopen(C,"r");
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC
   F.S. : CC adalah karakter berikutnya dari CC yang lama. */

    /* Algoritma */
    retval = fscanf(config,"%c",&CC);
    EOP = (CC == EOF);
    if (EOP) {
       fclose(config);
    }
  }
