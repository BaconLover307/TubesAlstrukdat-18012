#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mesinkata_faris.h"

int main() {
	MATRIKS M;
	STARTKATA();
	int NB = KataToInt(CKata);
	ADVKATA();
	int NK = KataToInt(CKata);
	ADVKATA();
	int MaxEl = KataToInt(CKata);
	ADVKATA();
 	PrintKata(CKata); Bangunan B = KataToBangunan(MaxEl);
	M = KataToMatriks(NB, NK, B);
	printf("You're entering this stage!\n");
	TulisMATRIKS(M);
	printf("You have written the Matrix!\n");
	printf("Here's the element count of your matrix: %d\n", NBElmtMatriks(M));
	printf("You're going to write the graph!\n");
	printf("Here's the value of MaxEl: %d\n", MaxEl);
	Graph G = KataToGraph(MaxEl);
	printf("Here's the element count of your graph: %d\n", NbElmtGraph(G));
	TulisGraph(G);
}