#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "string.h"

// Prosedur untuk melakukan ATTACK
void ATTACK(Stack *gamestate, Bangunan *databuild, Graph relasi) {
    // $ Kamus Lokal
    Player *CurrP;
    Player *EnemyP;
    List *Lcurr;
    List *Lenemy;
    if (TurnInfo(Curr(*gamestate)) == 1) {
        CurrP = &P1Info(Curr(*gamestate));
        EnemyP = &P2Info(Curr(*gamestate));
    }
    else {
        CurrP = &P2Info(Curr(*gamestate));
        EnemyP = &P1Info(Curr(*gamestate));
    }
    Lcurr = &ListBan(*CurrP);
    Lenemy = &ListBan(*EnemyP);

    // $ Algoritma

    // * Bangunan Pemain
    printf(" __\n[__] ==== List of Buildings  ==== [P%d]\n", TurnInfo(Curr(*gamestate)));
    PrintInfo(*Lcurr,*databuild);
    int giliran = TurnInfo(Curr(*gamestate));
    printf("Choose a building to attack : ");
    int nomorBangunan;
    do {
        scanf("%d", &nomorBangunan);
        if (nomorBangunan > NbElmtList(*Lcurr) || nomorBangunan < 1) {
            printf("Input is not valid! Silakan input index bangunan yang tersedia.\n");
            printf("Choose a building to attack : ");
        } else {printf("\n");}
    } while (nomorBangunan > NbElmtList(*Lcurr) || nomorBangunan < 1);

    // * Ambil Bangunan Pemain
    address Pcurr = Search(*Lcurr,nomorBangunan);
    int idxBangunanCurr = Info(Pcurr);

    PrintAttack(relasi, *Lcurr, *databuild, idxBangunanCurr);
    // * Bangunan Lawan
    // sleep(10);
    printf("pass\n");
    printf(" __\n[__] ==== List of Buildings  ==== [P%d]\n", TurnInfo(Curr(*gamestate))%2+1);
    PrintInfo(*Lenemy,*databuild);
    printf("Choose a building you want to attack : ");
    int nomorBangunanDiserang;
    do {
        scanf("%d", &nomorBangunanDiserang);
        if (nomorBangunanDiserang > NbElmtList(*Lcurr) || nomorBangunanDiserang < 1) {
            printf("Input is not valid! Please input given index of buildings.\n");
            printf("Choose a building you want to attack : ");
        } else {printf("\n");}
    } while (nomorBangunanDiserang > NbElmtList(*Lcurr) || nomorBangunanDiserang < 1);
    // * Jumlah Pasukan
    int jumlahPasukan;
    while (1) {
        printf("Amount of soldiers use for attack : ");
        scanf("%d", &jumlahPasukan);
        if (jumlahPasukan > 0 && jumlahPasukan < Tentara(ElmtBan(*databuild, idxBangunanCurr)))
            break;
        puts("Amount of soldiers is not valid!");
    }
    int idx = 1;
    TentaraAttack(databuild, idx, jumlahPasukan);
    /*
    -- A hint from driver_list.c
    TentaraInvaded(&B, false, false, 0, 3, 30);
    if (CanCapture(B, 3)) {
      if (Search(L1, 3)) {
        printf("Bangunan ke-3 yang dimiliki oleh Pemain ke-1 telah dikuasai oleh Pemain ke-2.\n\n");
        DelP(&L1, 3);
      }
      InsVPrio(&L2, 3);
      TentaraAbsolute(&B, 3);
    }
    */
    // cek apakah berhasil diambil atau tidak
    if (1) {
        printf("The building is yours now!\n");
    } else {
        printf("You failed to grab the building.\n");
    }
}

// Prosedur untuk Melakukan LEVEL UP
void LEVEL_UP(Stack *gamestate, Bangunan *databuild) {
    // $ Kamus Lokal
    Player *CurrP;
    Player *EnemyP;
    List *Lcurr;
    List *Lenemy;
    if (TurnInfo(Curr(*gamestate)) == 1) {
        CurrP = &P1Info(Curr(*gamestate));
        EnemyP = &P2Info(Curr(*gamestate));
    } else {
        CurrP = &P2Info(Curr(*gamestate));
        EnemyP = &P1Info(Curr(*gamestate));
    }
    Lcurr = &ListBan(*CurrP);
    Lenemy = &ListBan(*EnemyP);

    // $ Algoritma
    // * Menampilkan daftar Bangunan
    printf(" __\n[__] ==== List of Buildings ==== [P%d]\n",TurnInfo(Curr(*gamestate)));
    PrintInfo(*Lcurr, *databuild);
    printf("\n");
    // * User Input
    int nomorBangunan;
    printf("Choose the building you want to level-up : ");
    scanf("%d", &nomorBangunan);
    // * Melakukan pengecekan keberhasilan level up
    if (CheckLevelUp(*databuild,nomorBangunan)) {
        LevelUp(databuild,nomorBangunan);
        printf("Your %c has been leveled up to level %d\n",  Name(ElmtBan(*databuild,nomorBangunan)), Level(ElmtBan(*databuild,nomorBangunan)));
    } else {
        printf("You don't have enough soldiers at %c to Level Up the building!\n", Name(ElmtBan(*databuild,nomorBangunan)));
    }
}

// Prosedur untuk memakai skill yang sedang dimiliki pemain
void SKILL(Stack *gamestate, Bangunan *databuild) {
    // $ Kamus Lokal
    Qinfotype usedskill;
    Player *CurrP;
    Player *EnemyP;
    Queue *Qcurr;
    Queue *Qenemy;

    if (TurnInfo(Curr(*gamestate)) == 1) {
        CurrP = &P1Info(Curr(*gamestate));
        EnemyP = &P2Info(Curr(*gamestate));
    } else {
        CurrP = &P2Info(Curr(*gamestate));
        EnemyP = &P1Info(Curr(*gamestate));
    }
    Qcurr = &Skill(*CurrP);
    Qenemy = &Skill(*EnemyP);
    //Btemp = &ListBan(*CurrP);

    // $ Algoritma
    if (IsQEmpty(*Qcurr)) {
        printf("Oh no! You don't have any skills!\n");
    } else {
        // * Use Skill
        printf("You have used the skill : ");
        PrintInfoHead(*Qcurr); printf("\n");
        QDel(Qcurr, &usedskill);
        // * Switch
        if (strcmpi(usedskill,"IU") == 0) {
            printf("All your buildings have been Leveled Up!!\n");
            InstantUpgrade(CurrP,databuild);

        } else if (strcmpi(usedskill,"SH") == 0) {
            Shield(CurrP);
            printf("All your buildings have been Shielded for 2 turns!!\n");

        } else if (strcmpi(usedskill,"ET") == 0) {
            printf("You have gained an Extra Turn!!\n");
            ExtraTurn(CurrP);
            // ! Detector Skill Critical Hit
            GetCH(Qenemy);

        } else if (strcmpi(usedskill,"AU") == 0) {

        } else if (strcmpi(usedskill,"CH") == 0) {

        } else if (strcmpi(usedskill,"IR") == 0) {
            InstantReinforcement(CurrP, databuild);
            printf("All your buildings have been added by 5 soldiers.\n");

        } else if (strcmpi(usedskill,"BA") == 0) {
            Barrage(CurrP, EnemyP, databuild);
            printf("Soldiers in all your enemy's buildings have been decreased by 10\n");
        }
        ClearStack(gamestate);

    }
}

// Prosedur untuk melakukan UNDO
void UNDO(Stack *gamestate) {
    // $ Kamus Lokal
    if (IsFirstAct(*gamestate)) {
        printf("You cannot undo at the moment!\n");
    } else {
        printf("You have undone your past action!\n");
        Pop(gamestate, &Curr(*gamestate));
    }
}

// Prosedur untuk melakukan MOVE
void MOVE(Stack *gamestate, Bangunan *databuild, Graph relasi) { // todo
    // $ Kamus Lokal
    Player *CurrP;
    List *Lcurr;
    if (TurnInfo(Curr(*gamestate)) == 1) {
        CurrP = &P1Info(Curr(*gamestate));
    } else {
        CurrP = &P2Info(Curr(*gamestate));
    }
    Lcurr = &ListBan(*CurrP);
    // $ Algoritma
    // * Bangunan Pemain
    printf(" __\n[__] ==== List of Buildings  ==== [P%d]\n", TurnInfo(Curr(*gamestate)));
    PrintInfo(*Lcurr,*databuild);
    int giliran = TurnInfo(Curr(*gamestate));
    int nomorBangunan;
    do {
        printf("Choose a building to move : ");
        scanf("%d", &nomorBangunan);
        if (nomorBangunan > NbElmtList(*Lcurr) || nomorBangunan < 1) {
            printf("Input is not valid! Please input given index of buildings.\n");
        } else {printf("\n");}
    } while (nomorBangunan > NbElmtList(*Lcurr) || nomorBangunan < 1);
    // * Ambil Bangunan Pemain
    address Pcurr = Search(*Lcurr,nomorBangunan);
    int idxBangunanCurr = Info(Pcurr);

    // Menampilkan daftar bangunan terdekat
    int jumlahBangunanTerdekat;
    printf("List of Nearest Buildings :\n");
    PrintMove(relasi, *Lcurr, *databuild, idxBangunanCurr, &jumlahBangunanTerdekat);
    if (jumlahBangunanTerdekat == 0) {
        puts("....");
        sleep(1);
        puts("It seems that this building does not have any other connected building.");
        puts("press enter to go back to the main menu.");
        getchar();
        return;
    }
    int nomorBangunanDiterima;
    while (1) {
        printf("Choose a building which will receive the soldiers : ");
        scanf("%d", nomorBangunanDiterima);
        if (0 < nomorBangunanDiterima && nomorBangunanDiterima <= jumlahBangunanTerdekat)
            break;
        puts("Index input is invalid!");
    }
    int idxBangunanAcc = GetIdxMove(relasi, *Lcurr, *databuild, idxBangunanCurr, nomorBangunanDiterima);
    int jumlahPasukan;
    while (1) {
        printf("Enter your desired amount of soldiers : ");
        scanf("%d", jumlahPasukan);
        if (0 < jumlahPasukan && jumlahPasukan <= Tentara(ElmtBan(*databuild, idxBangunanCurr)))
            break;
        puts("Input of amount soldiers is invalid!");
    }
    Tentara(ElmtBan(*databuild, idxBangunanCurr)) -= jumlahPasukan;
    Tentara(ElmtBan(*databuild, idxBangunanAcc)) += jumlahPasukan;
    printf("%d soldier(s) from ", jumlahPasukan);
    char namaBuilding = Name(ElmtBan(*databuild, idxBangunanCurr));
    if (namaBuilding == 'C') {
      printf("Castle ");
    } else if (namaBuilding == 'V') {
      printf("Village ");
    } else if (namaBuilding == 'T') {
      printf("Tower ");
    } else /* (Name(ElmtBan(B, InfoG2(C))) == 'F') */ {
      printf("Fort ");
    }

    TulisPOINT(Posisi(ElmtBan(*databuild, idxBangunanCurr)));

    printf("has been moved to ");

    namaBuilding = Name(ElmtBan(*databuild, idxBangunanAcc));
    if (namaBuilding == 'C') {
      printf("Castle ");
    } else if (namaBuilding == 'V') {
      printf("Village ");
    } else if (namaBuilding == 'T') {
      printf("Tower ");
    } else /* (Name(ElmtBan(B, InfoG2(C))) == 'F') */ {
      printf("Fort ");
    }

    TulisPOINT(Posisi(ElmtBan(*databuild, idxBangunanAcc)));

    puts("");

}

// Prosedur untuk melakukan SAVE
void SAVE(Stack *gamestate) {
    printf("Lokasi save file: ");
    // todo SAVEFILE
}



// Prosedur untuk melakukan EXIT Game
boolean EXIT(Stack *gamestate) {
    char inp;
    printf("Do you want to save the game before exit?");
    do {
        printf("Y/N/C\n");
        scanf(" %c", &inp);
        if (inp == 'Y') {
            SAVE(gamestate);
            return true;
        } else if (inp == 'N') {
            return true;
        } else if (inp == 'C') {
            return false;
        }
    } while (inp != 'Y' && inp != 'N' && inp != 'C');
}
