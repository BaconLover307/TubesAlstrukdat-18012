#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mesinkata_faris.h"

int main() {
	int NB, NK, MaxEl;
 	MATRIKS M;
 	STARTKATA();
	NB = KataToInt(CKata);
	ADVKATA();
	NK = KataToInt(CKata);
	ADVKATA();
	MaxEl = KataToInt(CKata);
	ADVKATA();
	Bangunan B = KataToBangunan(MaxEl);  
	M = KataToMatriks(NB, NK, B);
	ADVKATA();
	Graph G = KataToGraph(NB, NK, MaxEl);
	TulisMATRIKS(M);
}
