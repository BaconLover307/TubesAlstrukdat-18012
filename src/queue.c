/* NAMA / NIM :                           */
/* 1. Muhammad Hasan           / 13518012 */
/* 2. Anna Elvira Hartoyo      / 13518045 */
/* 3. Daniel Riyanto           / 13518075 */
/* 4. Faris Muhammad Kautsar   / 13518105 */
/* 5. Gregorius Jovan Kresnadi / 13518135 */

/* Program          : queue.c */
/* Deskripsi        : Implementasi ADT Queue */
/* Definisi Queue   : Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

// $ ********* Prototype *********
boolean IsQEmpty (Queue Q) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == QNil) && (Tail(Q) == QNil);
}


boolean IsQFull (Queue Q) {
    return ((Head(Q) == 1) && (Tail(Q) == MaxQEl(Q))) || ((Tail(Q) == Head(Q)-1));
}


int NBQElmt (Queue Q) {
    if (IsQEmpty(Q)) {
        return 0;
    } else if (Tail(Q) < Head(Q)) {
        return (Tail(Q) - Head(Q) + MaxQEl(Q) + 1);
    } else {return (Tail(Q) - Head(Q) + 1);}

}


// $ *** Kreator ***
void CreateQueue (Queue * Q, int Max) {
    (*Q).T = (Qinfotype *)malloc((Max + 1) * sizeof(Qinfotype));
    if ((*Q).T != NULL) {
        MaxQEl(*Q) = Max;
        Head(*Q) = QNil;
        Tail(*Q) = QNil;
    } else { //  ! alokasigagal
        MaxQEl(*Q) = 0;
    }
}


// $ *** Destruktor ***
void QDeAlokasi(Queue * Q) {
    MaxQEl(*Q) = 0;
    free((*Q).T);
}


// $ *** Primitif Add/Delete ***
void QAdd (Queue * Q, Qinfotype X){
    // $ Kamus Lokal
    Qaddress i, j;
    // $ Algoritma

    if (IsQEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        strcpy(InfoTail(*Q), X);
    }

    else if (!(IsQFull(*Q))) { // * Q tidakkosong
        if (Tail(*Q) == MaxQEl(*Q)) { // * Geser elemen smp Head(Q)=1
            Tail(*Q) = 1;
        } else {
            Tail(*Q)++;
        }
        strcpy(InfoTail(*Q), X);
    }

    else { // * Q full
        printf("Your Skill queue is Full!\n");
    }
}


void QDel (Queue * Q, Qinfotype * X) {
    strcpy(*X,InfoHead(*Q));
    if (!(IsQEmpty(*Q))){
        if (Head(*Q) == Tail(*Q)) { // * Set menjadi queue kosong
            Head(*Q) = QNil;
            Tail(*Q) = QNil;
        }
        else {
            Head(*Q)++;
        }
    }

    else{
        printf("Your Skill queue is empty...\n");
    }

}

// $ *** Fungsi Lain ***
void PrintInfoHead (Queue Q){
    // $ Kamus Lokal
    char skil [10];
    // $ Algoritma
    if (IsQEmpty(Q)){
        printf("none");
    } else {
        strcpy(skil, InfoHead(Q));
        printf("%s", skil);
    }
}

void PrintQueue(Queue Q) {
    // $ Kamus Lokal
    Qinfotype skil;
    int i;

    // $ Algoritma
    if (IsQEmpty(Q)){
        printf("|| -- ||");
    } else {
        printf("|| ");
        PrintInfoHead(Q);
        printf(" ||");
        if (NBQElmt(Q) > 1) {
            for (i = Head(Q)+1; i <= Tail(Q); i++) {
                printf(" <- ");
                strcpy(skil, Q.T[i]);
                printf("%s", skil);
            }
        }
    }
}

Queue CopyQueue(Queue Q) {

    /* KAMUS LOKAL */
    Queue ret;
    int i;

    /* ALGORITMA */
    CreateQueue(&ret, MaxQEl(Q));
    if (IsQEmpty(Q)) return ret;
    for (i = Head(Q); i<= NBQElmt(Q); i++) {
            QAdd(&ret, Q.T[i]);
    }
    return ret;
}