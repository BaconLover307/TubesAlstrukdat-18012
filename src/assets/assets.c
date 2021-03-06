/* File : assets.h */
/* Definisi Modul print aset-aset ASCII Art */
#include <stdio.h>
#include <stdlib.h>
#include "../pcolor/pcolor.h"
#define MAX_LEN 128

// $ ********** IMPLEMENTASI **********

void print_image(char *filename) {
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "error opening %s\n", filename);
    }
    char read_string[MAX_LEN];
    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
    fclose(fptr);
}

void MainM() {
    printf("%s",YELLOW);
    print_image("assets//img_mainmenu.txt");
    printf("%s",NORMAL);
}
void Menu() {
    print_image("assets//img_menu.txt");
}
void Credits() {
    print_image("assets//img_credits.txt");
}
void Command() {
    print_image("assets//img_command.txt");
}
void Invalid() {
    print_image("assets//img_invalid.txt");
}
void Quit() {
    print_image("assets//img_quit.txt");
}
void P1Wins() {
    print_image("assets//img_p1wins.txt");
}
void P2Wins() {
    print_image("assets//img_p2wins.txt");
}
void QuitImg(){
    print_image("assets//img_quit.txt");
}