#include <stdio.h>

char c[100];

int main() {

    int i = 0;
    do {
        scanf("%c", c + i);
        printf("%c\n", c[i]);
    } while (c[i++] != '\n');
    c[--i] = '\0';
    printf("%s\n", c);
    return 0;
}
