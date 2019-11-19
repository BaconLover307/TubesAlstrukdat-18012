#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mesinkata_faris.h"

int main() {
	STARTKATA();
	printf("Let's start here!");
	PrintKata(CKata);
	printf(" You have printed CKata!");
}
/*	printf("Start here!");
	int NB, NK, MaxEl;
 	MATRIKS M;
 	STARTKATA();
 	printf("Test here 1");
 	PrintKata(CKata);
	NB = KataToInt(CKata);
	ADVKATA();
	printf("Test here 2");
 	PrintKata(CKata);
	NK = KataToInt(CKata);
	ADVKATA();
	printf("Test here 3");
 	PrintKata(CKata);
	MaxEl = KataToInt(CKata);
	ADVKATA();
 	PrintKata(CKata);
	Bangunan B = KataToBangunan(MaxEl);
	printf("Test here 4");
	M = KataToMatriks(NB, NK, B);
	ADVKATA();
	Graph G = KataToGraph(NB, NK, MaxEl);
	TulisMATRIKS(M);
	CLOSE();
} */