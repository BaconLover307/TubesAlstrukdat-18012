/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include "player.h"

TabColor Pallete;
Player P1,P2;

int main() {
    MakeBukuWarna(&Pallete);
    printf("Set color for Player 1\n");
    SetPlayerWarna(&P1,&Pallete);
    print_warna(Color(P1),'1');
    printf("\n"); printf("\n");

    printf("Set color for Player 2\n");
    SetPlayerWarna(&P2,&Pallete);
    print_warna(Color(P2),'2');
    printf("\n"); printf("\n");
    
    PrintBukuWarna(Pallete);
    printf("\n"); printf("\n");
    return 0;
}
