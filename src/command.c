#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "string.h"

// Prosedur untuk melakukan ATTACK
void ATTACK(Sinfotype *state, Bangunan *databuild, Graph relasi) {
    // $ Kamus Lokal
    Player *TopP;
    Player *EnemyP;
    List *Ltop;
    List *Lenemy;
    if (TurnInfo(*state) == 1) {
        *TopP = P1Info(*state);
        *EnemyP = P2Info(*state);
    }
    else {
        TopP = &P2Info(*state);
        EnemyP = &P1Info(*state);
    }
    Ltop = &ListBan(*TopP);
    Lenemy = &ListBan(*EnemyP);

    int idxCurr, nomorBangunan;
    address Pcurr;
    int giliran = TurnInfo(*state);
    // $ Algoritma

    // * Bangunan Pemain
    printf(" __\n[__] ====  List of Buildings  ==== [P%d]\n", giliran);
    PrintInfo(*Ltop,*databuild);
    do {
        printf("\nChoose a building to attack from : ");
        scanf("%d", &nomorBangunan);
        if (1 < nomorBangunan || NbElmtList(*Ltop) < nomorBangunan) {
            printf("Input is not valid! Please input from the available index.\n");
        } else {
                // * Ambil Bangunan Pemain
                Pcurr = First(*Ltop);
                for (int i = 1; i< nomorBangunan; i++) {
                    Pcurr = Next(Pcurr); }
                idxCurr = Info(Pcurr);
                    // * Jika sudah pernah Attack
                if (Attacked(ElmtBan(*databuild,idxCurr))) {
                    printf("This building has attacked before!\n");
                    AksiValid = false;
                    return;
                } else { // * Jika isinya kosong
                    if (Tentara(ElmtBan(*databuild,idxCurr)) = 0) {
                        puts("You cannot attack with an empty building!");
                        AksiValid = false;
                        return;
                    } else { printf("\n"); } 
                }

        }
    } while (1 < nomorBangunan || NbElmtList(*Ltop) < nomorBangunan );

    
    printf(" Anda akan menyerang dengan %c yang mempunyai %d tentara", Name(ElmtBan(*databuild,idxCurr)), Tentara(ElmtBan(*databuild,idxCurr)));

    // * Menampilkan daftar bangunan yang dapat diserang
    int jumlahBangunanTerdekat;
    printf(" __\n[__] ====  List of Buildings  ==== [P%d]\n", TurnInfo(*state)%2+1);
    PrintAttack(relasi, *Ltop, *databuild, idxCurr, &jumlahBangunanTerdekat);
    
    // * Jika tidak ada yang bisa diserang
    if (jumlahBangunanTerdekat == 0) {
        puts("....");
        sleep(1);
        puts("It seems that this building does not have any other connected buildings to attack.");
        puts("Press enter to go back to the main menu.");
        getchar();
        AksiValid = false;
        return;
    }
    
    int nomorBangunanDiserang;
    do { // * Memilih bangunan yang akan diserang
        printf("\nChoose a building you want to attack : ");
        scanf("%d", &nomorBangunanDiserang);
        if (0 < nomorBangunanDiserang && nomorBangunanDiserang <= jumlahBangunanTerdekat)
            break;
        puts("Index input is invalid!");
        printf("Choose a building you want to attack : ");
    } while (nomorBangunanDiserang > NbElmtList(*Ltop) || nomorBangunanDiserang < 1);
   
    int idxEnemy = GetIdxAttack(relasi, *Ltop, *databuild, idxCurr, nomorBangunanDiserang);

    // * Jumlah Pasukan
    int jumlahPasukan;
    while (1) {
        printf("Enter your desired amount of soldiers used to attack : ");
        scanf("%d", &jumlahPasukan);
        //if (CheckAttackTentara(*databuild,idxCurr,jumlahPasukan)) {
        if (jumlahPasukan > 0 && CheckAttackTentara(*databuild, idxCurr, jumlahPasukan)) {
            break;
        }
        puts("Amount of soldiers is not valid!");
    }

    boolean criticalHit = CH(FX(*EnemyP));
    boolean attackUp = AU(FX(*EnemyP));
    boolean shield = ActiveSH(SH(FX(*EnemyP)));
    
    TentaraInvaded(databuild, criticalHit, attackUp, shield, idxCurr, idxEnemy, jumlahPasukan);
    // ! Reset Status Critical Hit
    CH(FX(*TopP)) = false;

    if (CanCapture(*databuild, idxEnemy)) {
        printf("The building is yours now!\n");
        CaptureAttack(TopP, EnemyP, idxEnemy, databuild);
    } else {
        printf("You failed to grab the building.\n");
    }
    Attacked(ElmtBan(*databuild, idxCurr)) = true;
}

// Prosedur untuk Melakukan LEVEL UP
void LEVEL_UP(Sinfotype *state) {
    // $ Kamus Lokal
    Player *TopP;
    Player *EnemyP;
    List *Ltop;
    List *Lenemy;
    Bangunan *databuild;
    if (TurnInfo(*state) == 1) {
        TopP = &P1Info(*state);
        EnemyP = &P2Info(*state);
    } else {
        TopP = &P2Info(*state);
        EnemyP = &P1Info(*state);
    }
    printf("+++++ Turn %d +++++", TurnInfo(*state));
    Ltop = &ListBan(*TopP);
    Lenemy = &ListBan(*EnemyP);
    databuild = &DataB(*state);

    // $ Algoritma
    // * Menampilkan daftar Bangunan
    printf(" __\n[__] ==== List of Buildings ==== [P%d]\n",TurnInfo(*state));
    PrintInfo(*Ltop, *databuild);
    printf("\n");

    // * User Input
    int nomorBangunan;
    printf("Choose the building you want to level-up : ");
    scanf("%d", &nomorBangunan);

    urutan nopilihan = GetInfo(*Ltop, nomorBangunan);

    // * Melakukan pengecekan keberhasilan level up
    char namaBuilding = Name(ElmtBan(*databuild, nopilihan));
    if (CheckLevelUp(*databuild,nopilihan)) {
        LevelUp(databuild,nopilihan);
        if (namaBuilding == 'C') { printf("Your Castle ");
        } else if (namaBuilding == 'V') { printf("Your Village ");
        } else if (namaBuilding == 'T') { printf("Your Tower ");
        } else /*(namaBuilding == 'T')*/ {printf("Your Fort ");}
        printf("has been leveled up to level %d!\n", Level(ElmtBan(*databuild,nopilihan)));
    } else {
        printf("You don't have enough soldiers at ");
        if (namaBuilding == 'C') { printf("your Castle ");
        } else if (namaBuilding == 'V') { printf("your Village ");
        } else if (namaBuilding == 'T') { printf("your Tower ");
        } else /*(namaBuilding == 'T')*/ {printf("your Fort ");}
        printf("to Level Up the building!\n", Name(ElmtBan(*databuild,nopilihan)));
    }
}

// Prosedur untuk memakai skill yang sedang dimiliki pemain
void SKILL(Stack *gamestate, Bangunan *databuild) {
    // $ Kamus Lokal
    Qinfotype usedskill;
    Player *TopP;
    Player *EnemyP;
    Queue *Qtop;
    Queue *Qenemy;
    List *Lenemy;

    if (TurnInfo(InfoTop(*gamestate)) == 1) {
        TopP = &P1Info(InfoTop(*gamestate));
        EnemyP = &P2Info(InfoTop(*gamestate));
    } else {
        TopP = &P2Info(InfoTop(*gamestate));
        EnemyP = &P1Info(InfoTop(*gamestate));
    }
    Qtop = &Skill(*TopP);
    Qenemy = &Skill(*EnemyP);
    Lenemy = &ListBan(*EnemyP);

    // $ Algoritma
    if (IsQEmpty(*Qtop)) {
        printf("Oh no! You don't have any skills!\n");
    } else {
        // * Use Skill
        QDel(Qtop, &usedskill);
        // * Switch
        if (strcmpi(usedskill,"IU") == 0) {
            printf("!!! INSTANT UPGRADE !!!\n");
            InstantUpgrade(TopP,databuild);
            printf("All your buildings have been Leveled Up!!\n");

        } else if (strcmpi(usedskill,"SH") == 0) {
            printf("!!! SHIELD UP !!!\n");
            Shield(TopP);
            printf("All your buildings have been Shielded for 2 turns!!\n");

        } else if (strcmpi(usedskill,"ET") == 0) {
            printf("You have gained an Extra Turn!!\n");
            ExtraTurn(TopP);
            // ! Detector Skill Critical Hit
            CheckGetCH(Qenemy);

        } else if (strcmpi(usedskill,"AU") == 0) {
            printf("!!! ATTACK UP !!!\n");
            AttackUp(TopP);
            printf("Your attacks for this turn ignore building defenses!!\n");

        } else if (strcmpi(usedskill,"CH") == 0) {
            printf("!!! CRITICAL HIT IMMINENT !!!\n");
            CriticalHit(TopP);
            printf("Your next attack will be twice as effective!!\n");


        } else if (strcmpi(usedskill,"IR") == 0) {
            printf("!!! INSTANT REINFORCEMENT !!!\n");
            InstantReinforcement(TopP, databuild);
            printf("All your buildings have been added by 5 soldiers!!\n");

        } else if (strcmpi(usedskill,"BA") == 0) {
            int bangunanmusuh1 = NbElmtList(*Lenemy);
            printf("!!! BARRAGE !!!\n");
            Barrage(TopP, EnemyP, databuild);
            int bangunanmusuh2 = NbElmtList(*Lenemy);
            printf("Soldiers in all your enemy's buildings have been decreased by 10!!\n");
            if (bangunanmusuh1 > bangunanmusuh2)
                printf("You've managed to snag a few buildings as well, impressive...\n");
        }
        ClearStack(gamestate);

    }
}

// Prosedur untuk melakukan UNDO
void UNDO(Stack *gamestate) {
    // $ Kamus Lokal
    Sinfotype buang;
    // $ Algoritma
    if (IsFirstAct(*gamestate)) {
        printf("You cannot Undo at the moment!\n");
    } else {
        printf("You have undone your past action!\n");
        Pop(gamestate, &buang);
    }
}

// Prosedur untuk melakukan MOVE
void MOVE(Sinfotype *state, Bangunan *databuild, Graph relasi) { // todo
    // $ Kamus Lokal
    Player *CurrP;
    List *Ltop;
    if (TurnInfo(*state) == 1) {
        CurrP = &P1Info(*state);
    } else {
        CurrP = &P2Info(*state);
    }
    Ltop = &ListBan(*CurrP);

    int giliran = TurnInfo(*state);
    int nomorBangunan, idxBangunanCurr;
    address Pcurr;
    // $ Algoritma
    // * Bangunan Pemain
    printf(" __\n[__] ==== List of Buildings ==== [P%d]\n", TurnInfo(*state));
    PrintInfo(*Ltop,*databuild);
    printf("\n");

    do {
        printf("Choose a building to move soldiers from: ");
        scanf("%d", &nomorBangunan);
        if (nomorBangunan < 1 || NbElmtList(*Ltop) < nomorBangunan ) {
            printf("Input is not valid! Please input given index of buildings.\n");
        } else {
            // * Ambil Bangunan Pemain
            Pcurr = First(*Ltop);
            for (int i = 1; i< nomorBangunan; i++) {
                Pcurr = Next(Pcurr); }
            idxBangunanCurr = Info(Pcurr);
                // * Jika sudah pernah Move
            if (Moved(ElmtBan(*databuild, idxBangunanCurr))) {
                printf("This building has moved soldiers before!\n");
                AksiValid = false;
                return;
            } else { // * Jika bangunan kosong
                if (Tentara(ElmtBan(*databuild,idxBangunanCurr)) = 0) {
                    puts("You cannot move soldiers from an empty building!");
                    AksiValid = false;
                    return;
                } else { printf("\n"); } 
            }
        }
    } while (nomorBangunan < 1 || NbElmtList(*Ltop) < nomorBangunan );
    

    // *Menampilkan daftar bangunan terdekat
    int jumlahBangunanTerdekat;
    printf(" __\n[__] == List of Nearest Buildings == [P%d]\n", TurnInfo(*state));
    PrintMove(relasi, *Ltop, *databuild, idxBangunanCurr, &jumlahBangunanTerdekat);
    
    // * Jika tidak ada yang adjacent
    if (jumlahBangunanTerdekat == 0) {
        puts("....");
        sleep(1);
        puts("It seems that this building does not have any other connected building.");
        puts("Press enter to go back to the main menu.");
        getchar();
        AksiValid = false;
        return;
    }

    int nomorBangunanDiterima;
    while (1) {
        printf("\n");
        printf("Choose a building which will receive the soldiers : ");
        scanf("%d", &nomorBangunanDiterima);
        if (0 < nomorBangunanDiterima && nomorBangunanDiterima <= jumlahBangunanTerdekat)
            break;
        puts("Index input is invalid!");
    }
    int idxBangunanAcc = GetIdxMove(relasi, *Ltop, *databuild, idxBangunanCurr, nomorBangunanDiterima);
    int jumlahPasukan;
    while (1) {
        printf("Enter your desired amount of soldiers to move : ");
        scanf("%d", &jumlahPasukan);
        if (0 <= jumlahPasukan && jumlahPasukan <= Tentara(ElmtBan(*databuild, idxBangunanCurr)))
            break;
        puts("Soldier amount is invalid!");
    }
    Tentara(ElmtBan(*databuild, idxBangunanCurr)) -= jumlahPasukan;
    Tentara(ElmtBan(*databuild, idxBangunanAcc)) += jumlahPasukan;
    if (jumlahPasukan != 0) {
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

        printf(" has been moved to ");

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
        puts("!");
        Moved(ElmtBan(*databuild, idxBangunanCurr)) = true;
    } else {
        puts("....");
        sleep(1);
        printf("You didn't move anyone... Oh well.\n");
        puts("Press enter to go back to the main menu.");
        getchar();
    }
}

// Prosedur untuk melakukan SAVE
void SAVE(Sinfotype *state) {
    printf("Lokasi save file: ");
    // todo SAVEFILE
}


// Prosedur untuk melakukan EXIT Game
void EXIT(Sinfotype *state) {
    char inp;
    printf("Do you want to save the game before exiting the game? ");
    do {
        printf("Y/N/C\n");
        scanf(" %c", &inp);
        if (inp == 'Y') {
            SAVE(state);
            ExitMenu = true;
            EndTurn = true;
        } else if (inp == 'N') {
            ExitMenu = true;
            EndTurn = true;
        } else if (inp == 'C') {
            ExitMenu = false;
        }
    } while (inp != 'Y' && inp != 'N' && inp != 'C');
}
