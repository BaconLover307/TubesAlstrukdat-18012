#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mesinkata_faris.h"

int main() {
	int NB, NK, MaxEl;
 	MATRIKS M;
 	STARTKATA();
	ADVKATA();
	NB = KataToInt(CKata);
	ADVKATA();
	NK = KataToInt(CKata);
	ADVKATA();
	MaxEl = KataToInt(CKata);
	ADVKATA();
	Bangunan B = KataToBangunan(MaxEl);  
	M = KataToMatriks(NB, NK, B);
	TulisMATRIKS(M);
	Graph G = KataToGraph(NB, NK, MaxEl);
}
