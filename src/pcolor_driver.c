/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include "pcolor.h"

int main() {
    print_red('Red');
    printf("\n");
    print_green('Green');
    printf("\n");
    print_magenta('Magenta');
    printf("\n");
    print_cyan('Cyan');
    printf("\n");
    print_yellow('Yellow');
    printf("\n");
    print_blue('Blue');
    printf("\n");
    return 0;
}
