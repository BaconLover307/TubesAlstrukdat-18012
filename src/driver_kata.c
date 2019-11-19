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
	M = KataToMatriks(NB, NK, B);
	printf("You're entering this stage!\n");
	TulisMATRIKS(M);
	printf("You have written the Matrix!\n");
	printf("Here's the element count of your matrix: %d\n", NBElmtMatriks(M));
	printf("You're going to write the graph!\n");
	Graph G = KataToGraph(MaxEl);
	printf("Here's the element count of your graph: %d\n", NeffG(G));
	TulisGraph(G);
}