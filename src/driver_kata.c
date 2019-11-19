#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mesinkata_faris.h"

int main() {
	MATRIKS M;
	STARTKATA();
	PrintKata(CKata); int NB = KataToInt(CKata);
	ADVKATA();
	PrintKata(CKata); int NK = KataToInt(CKata);
	ADVKATA();
	PrintKata(CKata); int MaxEl = KataToInt(CKata);
	ADVKATA();
 	PrintKata(CKata); Bangunan B = KataToBangunan(MaxEl);
    TulisPOINT(Posisi(ElmtBan(B,7)));
    printf("%c\n",Name(ElmtBan(B,7)));
	M = KataToMatriks(NB, NK, B);
	printf("You're entering this stage!\n");
	TulisMATRIKS(M);
	printf("You have written the Matrix!\n");
	printf("%d", NBElmtMatriks(M));
	Graph G = KataToGraph(NB, NK, MaxEl);
}