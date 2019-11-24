#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "load.h"
#include "string.h"

int main() {

    Sinfotype state;
    Graph relasi;
    MATRIKS M;
    LoadFile(&state, &relasi, &M);

    return 0;
}
