#include <stdio.h>
#include "load.h"

void LoadFile(Sinfotype * state, Graph * relasi, MATRIKS * map) {
    // Kamus Lokal
    char input[100] = "savefile/";

    printf("Enter the name of your load file : ");
    scanf("%s", input + 9);

    // Algoritma
    STARTKATA(input);
    Bangunan B;
    MakeEmptyBangunan(&B, 100);
    // Neff
    Neff(B) = KataToInt(CKata); ADVKATA();
    int makz = Neff(B);
    if (makz == 0) {
        printf("Load Failed! There seems to be no file named %s\n", (input + 9));
        TurnInfo(*state) = -1;
        return;
    }

    for (int i = 1; i <= Neff(B); i++) {
        Name(ElmtBan(B, i)) = KataToChar(CKata);
        ADVKATA();
        Posisi(ElmtBan(B, i)).X = KataToInt(CKata);
        ADVKATA();
        Posisi(ElmtBan(B, i)).Y = KataToInt(CKata);
        ADVKATA();
        Level(ElmtBan(B, i)) = KataToInt(CKata);
        ADVKATA();
        Moved(ElmtBan(B, i)) = KataToInt(CKata);
        ADVKATA();
        Attacked(ElmtBan(B, i)) = KataToInt(CKata);
        ADVKATA();
        Defensed(ElmtBan(B, i)) = KataToInt(CKata);
        ADVKATA();
    }

    DataB(*state) = CopyBangunan(B);

    Player P1, P2;
    CreatePlayer(&P1);
    CreatePlayer(&P2);

    // Color
    TurnInfo(*state) = KataToInt(CKata); ADVKATA();
    Color(P1) = KataToChar(CKata); ADVKATA();
    Color(P2) = KataToChar(CKata); ADVKATA();

    // Status Effect
    AU(FX(P1)) = KataToInt(CKata); ADVKATA();
    CH(FX(P1)) = KataToInt(CKata); ADVKATA();
    ET(FX(P1)) = KataToInt(CKata); ADVKATA();
    ActiveSH(SH(FX(P1))) = KataToInt(CKata); ADVKATA();
    Duration(SH(FX(P1))) = KataToInt(CKata); ADVKATA();

    AU(FX(P2)) = KataToInt(CKata); ADVKATA();
    CH(FX(P2)) = KataToInt(CKata); ADVKATA();
    ET(FX(P2)) = KataToInt(CKata); ADVKATA();
    ActiveSH(SH(FX(P2))) = KataToInt(CKata); ADVKATA();
    Duration(SH(FX(P2))) = KataToInt(CKata); ADVKATA();

    // skill
    Qinfotype temp;
    QDel(&Skill(P1), &temp);
    int q = KataToInt(CKata); ADVKATA();

    for (int i = 1; i <= q; i++) {
        char skl[10];
        for (int j = 1; j <= CKata.Length; j++) {
            skl[j - 1] = CKata.TabKata[j];
        }
        QAdd(&Skill(P1), skl); ADVKATA();
    }
    q = KataToInt(CKata); ADVKATA();
    QDel(&Skill(P2), &temp);
    for (int i = 1; i <= q; i++) {
        char skl[10];
        for (int j = 1; j <= CKata.Length; j++) {
            skl[j - 1] = CKata.TabKata[j];
        }
        QAdd(&Skill(P2), skl); ADVKATA();
    }

    // listbuildings
    q = KataToInt(CKata); ADVKATA();
    for (int i = 1; i <= q; i++) {
        int x = KataToInt(CKata); ADVKATA();
        InsVPrio(&ListBan(P1), x);
    }
    q = KataToInt(CKata); ADVKATA();
    for (int i = 1; i <= q; i++) {
        int x = KataToInt(CKata); ADVKATA();
        InsVPrio(&ListBan(P2), x);
    }
    P1Info(*state) = CopyPlayer(P1);
    P2Info(*state) = CopyPlayer(P2);

    MakeEmptyGraph(relasi);
    AddParent(relasi, makz);

    for (int i = 1; i <= makz; i++) {
        for (int j = 1; j <= makz; j++) {
            int x = KataToInt(CKata); ADVKATA();
            if (x == 1) {
                AddRelation(relasi, i, j);
            }
        }
    }

    int brs = KataToInt(CKata); ADVKATA();
    int kol = KataToInt(CKata); ADVKATA();
    // printf("brs = %d and kol = %d\n", brs, kol);
    MakeMATRIKS(brs, kol, map);
    for (int i = 1; i <= brs; i++) {
        for (int j = 1; j <= kol; j++) {
            Elmt(*map, i, j) = KataToInt(CKata); ADVKATA();
        }
    }
    puts("File loaded succesfully!");
    sleep(1);
}
