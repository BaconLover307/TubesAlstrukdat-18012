#include "player.h"
#include <stdio.h>

// $ Kamus
Player P1,P2;
char color1,color2;
TabColor Pallete;
//Stack S;
//int T = 1;

 // $ Algo
int main() {
    printf("========Inisialisasi==============================================================\n");
    printf("Inisialisasi Player dengan CreatePlayer(P) \n");
    CreatePlayer(&P1);
    CreatePlayer(&P2);
    printf("========Color Handling============================================================\n");
    MakeBukuWarna(&Pallete);
    printf("Set color for Player 1\n");
    SetPlayerWarna(&P1,&Pallete);
    print_warna(Color(P1),'1');
    printf("\n"); printf("\n");

    printf("Set color for Player 2\n");
    SetPlayerWarna(&P2,&Pallete);
    print_warna(Color(P2),'2');
    printf("\n"); printf("\n");
    printf("Load color untuk Player 2, warna Hijau\n");
    LoadPlayerWarna(&P2, 'G');
    print_warna(Color(P2),'2');
    printf("\n"); printf("\n");
    printf("==================================================================================\n");


}
