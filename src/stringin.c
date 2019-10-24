#include <stdio.h>
int main() {
    char big[25];
    printf("Input string up to 25 chars");
    do {
        scanf("%s",big);
        printf("The string is -> %s\n",big);
    } while (big[0] != 'X');
    printf("\nEnd of program\n");
    return 0;
}