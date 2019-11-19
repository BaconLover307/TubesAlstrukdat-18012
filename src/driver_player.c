#include "player.h"
#include <stdio.h>

// $ Kamus
Player P1,P2;
char color1,color2;
//Stack S;
//int T = 1;

 // $ Algo
int main() {
    printf("================================================================================\n");
    printf("Inisialisasi Player dengan CreatePlayer(P) \n");
    CreatePlayer(&P1);
    CreatePlayer(&P2);
    StartTurn(&S,P1,P2,T);
    printf("================================================================================\n");
    printf("Tuliskan warnamu: ");
    scanf("%c",&color1);
    SetPlayerWarna(&P1,color1);
    print_warna(Color(P1),'M');
    printf("\n");
}
