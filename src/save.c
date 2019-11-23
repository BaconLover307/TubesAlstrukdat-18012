#include <stdio.h>
#include "save.h"

void saveData() {
    char input[100];
    printf("Enter the desired name of your save file : ");
    int i = 0;
    do {
        scanf("%c", input + i);
    } while (input[i++] == '\n');
    input[--i] = '\0';
    
}
