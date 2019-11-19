#include <stdio.h>
#include <stdlib.h>
#include "command.h"
#include "string.h"

// Prosedur untuk melakukan ATTACK
void ATTACK(Stack *gamestate)
{
    printf("Daftar bangunan:\n");
    // Mnampilkan Daftar Bangunan
    printf("Bangunan yang digunakan untuk menyerang : ");
    int nomorBangunan;
    scanf("%d", &nomorBangunan);
    // while () {
    //
    // }
    printf("Daftar bangunan yang dapat diserang\n");
    // Menampilkan daftar bangunan yang dapat diserang
    printf("Bangunan yang diserang : ");
    int nomorBangunanDiserang;
    scanf("%d", &nomorBangunanDiserang);
    // while () {
    //
    // }
    int jumlahPasukan;
    printf("Jumlah pasukan: ");
    scanf("%d", &jumlahPasukan);

    // cek apakah berhasil diambil atau tidak
    if (1) {
        printf("Bangunan menjadi milikmu!\n");
    } else {
        printf("Bangunan gagal direbut.\n");
    }
}

// Prosedur untuk Melakukan LEVEL UP
void LEVEL_UP(Stack *gamestate, Bangunan *databuild) {
    // $ Kamus Lokal
    Player CurrP = GetCurrPlayer(*gamestate);
    // $ Algoritma
    printf("Daftar bangunan\n");
    // Menampilkan daftar Bangunan
    printf("Bangunan yang akan di level up : ");
    int nomorBangunan;
    scanf("%d", &nomorBangunan);
    // lakukan pengecekan keberhasilan level up
    if (1) {
        printf("Level %s-mu meningkat menjadi %d\n");
    } else {
        printf("Jumlah pasukan %s kurang untuk level up\n");
    }
}

//void abcabc(Stack* gamestate) {
 //   printf("abcabc masuk\n");
   // fflush(stdout);
    //SKILL(*gamestate);
//}
// Prosedur untuk memakai skill yang sedang dimiliki pemain
void SKILL(Stack *gamestate, Bangunan *databuild) {
    // $ Kamus Lokal
    Qinfotype usedskill;
    Queue *Qtemp;
    Player *CurrP;

    if (TurnInfo(Curr(*gamestate)) == 1) {
        CurrP = &P1Info(Curr(*gamestate));
    } else {
        CurrP = &P2Info(Curr(*gamestate));
    }
    Qtemp = &Skill(*CurrP);
    //Btemp = &ListBan(*CurrP);

    // $ Algoritma
    if (IsQEmpty(*Qtemp)) {
        printf("You don't have any skills!\n");
    } else {
        // * Use Skill
        printf("You have used the skill : ");
        PrintInfoHead(*Qtemp); printf("\n");
        QDel(Qtemp, &usedskill);
        // * Switch
        if (strcmpi(usedskill,"IU") == 0) {
            printf("All your buildings have been Leveled Up!!\n");
            //InstantUpgrade(CurrP,databuild);

        } else if (strcmpi(usedskill,"SH") == 0) {

        } else if (strcmpi(usedskill,"ET") == 0) {
            printf("You have gained an Extra Turn!!\n");
            ExtraTurn(CurrP);

        } else if (strcmpi(usedskill,"AU") == 0) {
            
        } else if (strcmpi(usedskill,"CH") == 0) {

        } else if (strcmpi(usedskill,"IR") == 0) {
            printf("All your buildings have been added by 5 soldiers.\n");
            //InstantReinforcement(CurrP, databuild);
        } else if (strcmpi(usedskill,"BA") == 0) {
            printf("Soldiers in all your enemy's buildings have been decreased 10\n");
            //Barrage(CurrP, databuild);  
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
void MOVE(Stack *gamestate) { // todo
    printf("Daftar bangunan\n");
    // Menampilkan daftar Bangunan
    printf("Pilih bangunan : ");
    int nomorBangunan;
    scanf("%d", &nomorBangunan);
    // melakukan validasi input
    // while () {
    //
    // }

    printf("Daftar bangunan terdekat :\n");
    // Menampilkan daftar bangunan terdekat
    printf("Bangunan yang akan menerima : ");
    int nomorBangunanDiterima;
    scanf("%d", nomorBangunanDiterima);
    printf("Jumlah pasukan : ");
    int jumlahPasukan;
    scanf("%d", jumlahPasukan);
    // melakukan validasi input
    // while () {
    //
    // }
    printf("%d pasukan [...] telah berpindah ke [...]\n", jumlahPasukan);
}

// Prosedur untuk melakukan SAVE
void SAVE(Stack *gamestate) {
    printf("Lokasi save file: ");
    // todo SAVEFILE
}



// Prosedur untuk melakukan EXIT Game
boolean EXIT(Stack *gamestate) {
    char inp;
    printf("Apakah Anda ingin melakukan save terlebih dahulu? ");
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
