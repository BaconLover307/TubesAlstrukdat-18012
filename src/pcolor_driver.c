/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include "pcolor.h"

int main() {
    print_warna('R','R');
    printf("\n");
    print_warna('G','G');
    printf("\n");
    print_warna('B','B');
    printf("\n");
    print_warna('C','C');
    printf("\n");
    print_warna('M','M');
    printf("\n");
    print_warna('Y','Y');
    printf("\n");
    return 0;
}
