#include <stdio.h>
#include "save.h"

void saveData(Sinfotype state, Graph relasi, MATRIKS M) {

    /* Local Dictionary */
    int i, j, neff, maks1, maks2;
    char input[100];
    address P;

    /* Algorithm */
    /* Taking input of the desired name with "mesinkata" */
    /*
    printf("Enter the desired name of your save file : ");
    int i = 0;
    do {
        scanf("%c", input + i);
    } while (input[i++] == '\n');
    input[--i] = '\0';
    */

    FILE * fp = fopen("coba.txt", "w");


    /* Information about the buildings data */
    // The number of building there is on the map
    neff = Neff(DataB(state));
    fprintf(fp, "%d\n", Neff(DataB(state)));
    printf("number buildings : %d\n", Neff(DataB(state)));

    // Printing Name, Position, level, souldiers, hasMoved, hasAttacked, and defense of every building
    for (i = 1; i <= neff; i++) {
        printf("%d :\n", i);
        fprintf(fp, "%c\n", Name(ElmtBan(DataB(state), i)));
        printf("%c\n", Name(ElmtBan(DataB(state), i)));
        fprintf(fp, "%d %d\n", Posisi(ElmtBan(DataB(state), i)).X, Posisi(ElmtBan(DataB(state), i)).Y);
        printf("position : %d %d\n", Posisi(ElmtBan(DataB(state), i)).X, Posisi(ElmtBan(DataB(state), i)).Y);
        fprintf(fp, "%d\n", Level(ElmtBan(DataB(state), i)));
        printf("level : %d\n", Level(ElmtBan(DataB(state), i)));
        fprintf(fp, "%d\n", Moved(ElmtBan(DataB(state), i)));
        printf("moved : %d\n", Moved(ElmtBan(DataB(state), i)));
        fprintf(fp, "%d\n", Attacked(ElmtBan(DataB(state), i)));
        printf("attacked : %d\n", Attacked(ElmtBan(DataB(state), i)));
        fprintf(fp, "%d\n", Defensed(ElmtBan(DataB(state), i)));
        printf("defensed : %d\n", Defensed(ElmtBan(DataB(state), i)));
        printf("\n");
    }

    /* Information about player's turn */
    fprintf(fp, "%d\n", TurnInfo(state));
    printf("turn : %d\n", TurnInfo(state));

    /* Information about player's color */
    fprintf(fp, "%c\n", Color(P1Info(state)));
    printf("color 1 : %c\n", Color(P1Info(state)));
    fprintf(fp, "%c\n", Color(P2Info(state)));
    printf("color 2 : %c\n", Color(P2Info(state)));

    /* Information about player's status effect */
    /* Starting from player one */
    // attack up
    fprintf(fp, "%d\n", AU(FX(P1Info(state))));
    printf("attack 1 : %d\n", AU(FX(P1Info(state))));
    // critical hit
    fprintf(fp, "%d\n", CH(FX(P1Info(state))));
    printf("critical hit 1 : %d\n", CH(FX(P1Info(state))));
    // extra turn
    fprintf(fp, "%d\n", ET(FX(P1Info(state))));
    printf("extra turn 1 : %d\n", ET(FX(P1Info(state))));
    // shield
    // 1. active shield
    fprintf(fp, "%d\n", ActiveSH(SH(FX(P1Info(state)))));
    printf("active shield 1 : %d\n", ActiveSH(SH(FX(P1Info(state)))));
    // 2. duration shield
    fprintf(fp, "%d\n", Duration(SH(FX(P1Info(state)))));
    printf("duration shield 1 : %d\n", Duration(SH(FX(P1Info(state)))));

    /* Continuing with player two */
    // attack up
    fprintf(fp, "%d\n", AU(FX(P2Info(state))));
    printf("attack 2 : %d\n", AU(FX(P2Info(state))));
    // critical hit
    fprintf(fp, "%d\n", CH(FX(P2Info(state))));
    printf("critical hit 2 : %d\n", CH(FX(P2Info(state))));
    // extra turn
    fprintf(fp, "%d\n", ET(FX(P2Info(state))));
    printf("extra turn 2 : %d\n", ET(FX(P2Info(state))));
    // shield
    // 1. active shield
    fprintf(fp, "%d\n", ActiveSH(SH(FX(P2Info(state)))));
    printf("active shield 2 : %d\n", ActiveSH(SH(FX(P2Info(state)))));
    // 2. duration shield
    fprintf(fp, "%d\n", Duration(SH(FX(P2Info(state)))));
    printf("duration shield 2 : %d\n", Duration(SH(FX(P2Info(state)))));

    /* Information about player's skill */
    /* Starting from player one */
    // The amount of skill the player have
    maks1 = NBQElmt(Skill(P1Info(state)));
    fprintf(fp, "%d\n", maks1);
    printf("Maxelement skill 1 : %d\n", maks1);
    printf("List : ");
    for (i = 1; i <= maks1; i++) {
        fprintf(fp, "%s ", Skill(P1Info(state)).T[i]);
        printf("%s ", Skill(P1Info(state)).T[i]);
    }
    fprintf(fp, "\n");
    printf("\n");

    /* Continuing with player 2 */
    // The amount of skill the player have
    maks2 = NBQElmt(Skill(P2Info(state)));
    fprintf(fp, "%d\n", maks2);

    // The skills the player have
    printf("Maxelement skill 2 : %d\n", maks1);
    printf("List : ");
    for (i = 1; i <= maks2; i++) {
        fprintf(fp, "%s ", Skill(P2Info(state)).T[i]);
        printf("%s ", Skill(P2Info(state)).T[i]);
    }
    fprintf(fp, "\n");
    printf("\n");

    /* Information about the player's list building */
    // Starting from player one
    // The amount of building the player have
    maks1 = NbElmtList(ListBan(P1Info(state)));
    fprintf(fp, "%d\n", maks1);
    printf("Maxelement building 1 : %d\n", maks1);

    // The current player's type, number of soldiers, and coordinate of the building it has

    P = First(ListBan(P1Info(state)));
    i = 1;
    while (P != Nil) {
        printf("%d :\n", i);
        fprintf(fp, "%c\n", Name(ElmtBan(DataB(state), Info(P))));
        printf("tipe : %c\n", Name(ElmtBan(DataB(state), Info(P))));
        fprintf(fp, "%d\n", Tentara(ElmtBan(DataB(state), Info(P))));
        printf("soldiers : %d\n", Tentara(ElmtBan(DataB(state), Info(P))));
        fprintf(fp, "%d %d\n", Posisi(ElmtBan(DataB(state), Info(P))).X, Posisi(ElmtBan(DataB(state), Info(P))).Y);
        printf("coordinate : %d %d\n", Posisi(ElmtBan(DataB(state), Info(P))).X, Posisi(ElmtBan(DataB(state), Info(P))).Y);
        printf("\n");
        P = Next(P);
    }

    // Continuing with player two
    // The amount of building the player have
    maks2 = NbElmtList(ListBan(P2Info(state)));
    fprintf(fp, "%d\n", maks2);
    printf("Maxelement building 2 : %d\n", maks2);

    // The current player's type, number of soldiers, and coordinate of the building it has
    P = First(ListBan(P2Info(state)));
    i = 1;
    while (P != Nil) {
        printf("%d :\n", i);
        fprintf(fp, "%c\n", Name(ElmtBan(DataB(state), Info(P))));
        printf("tipe : %c\n", Name(ElmtBan(DataB(state), Info(P))));
        fprintf(fp, "%d\n", Tentara(ElmtBan(DataB(state), Info(P))));
        printf("soldiers : %d\n", Tentara(ElmtBan(DataB(state), Info(P))));
        fprintf(fp, "%d %d\n", Posisi(ElmtBan(DataB(state), Info(P))).X, Posisi(ElmtBan(DataB(state), Info(P))).Y);
        printf("coordinate : %d %d\n", Posisi(ElmtBan(DataB(state), Info(P))).X, Posisi(ElmtBan(DataB(state), Info(P))).Y);
        printf("\n");
        P = Next(P);
    }

    // Information about the connection between buildings
    addrGraph PG;
    addrGraph2 C;

    i = 1;

    while (i <= NbElmtGraph(relasi)) {
        PG = SearchP(relasi, i);
        j = 1;

        while (j < NbElmtGraph(relasi)) {
            C = SearchChild(PG, j);
            if (C != Nil) {
                fprintf(fp, "1 ");
                printf("1 ");
            } else /* C == Nil */ {
                fprintf(fp, "0 ");
                printf("0 ");
            }
            j++;
        }
        C = SearchChild(PG, j);
        if (C != Nil) {
            fprintf(fp, "1\n");
            printf("1\n");
        } else /* C == Nil */ {
            fprintf(fp, "0\n");
            printf("0\n");
        }
        i++;
    }

    /* Lastly, The Map :( */
    // MaxBrs Map
    fprintf(fp, "%d\n", MaxBrs(M));
    printf("Max Baris : %d\n", MaxBrs(M));
    fprintf(fp, "%d\n", MaxKol(M));
    printf("Max Kolom : %d\n", MaxKol(M));
    for (i = 1; i <= MaxBrs(M); i++) {
        for (j = 1; j <= MaxKol(M); j++) {
            fprintf(fp, "%d ", Elmt(M, i, j));
            printf("%d ", Elmt(M, i, j));
        }
        fprintf(fp, "\n");
        printf("\n");
    }

    fclose(fp);
}
