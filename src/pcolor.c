/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include "pcolor.h"

//void MakeBukuWarna(TabColor * ArrWarna) {
//    Neff(ArrWarna) = 0;
//}

void print_warna(Warna Col, char c) {
    switch (Col)
    {
    case 'R':
        printf("%s%c", RED, c);
        break;
    
    case 'G':
        printf("%s%c", GREEN, c);
        break;
    
    case 'B':
        printf("%s%c", BLUE, c);
        break;
    
    case 'C':
        printf("%s%c", CYAN, c);
        break;
    
    case 'M':
        printf("%s%c", MAGENTA, c);
        break;
    
    case 'Y':
        printf("%s%c", YELLOW, c);
        break;
    
    default:
        printf("%s%c", NORMAL, c);
        break;
    }
    printf("%s", NORMAL);
}
