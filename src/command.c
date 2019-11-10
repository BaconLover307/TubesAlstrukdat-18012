#include <stdio.h>
#include "command.h"

// Main Prosedur untuk command
void COMMAND(Stack *gamestate) {
    int input = 0;
    while (1) {
        printf("List command :\n");
        printf("1. Attack\n");
        printf("2. Level Up\n");
        printf("3. Skill\n");
        printf("4. Undo\n");
        printf("5. End Turn\n");
        printf("6. Move\n");
        printf("7. Save\n");
        printf("8. Exit\n");
        printf("ENTER COMMAND : ");
        scanf("%d", &input);
        printf("Your choice is : %d\n",input);

        switch(input) {
            case 1 :
                ATTACK(gamestate);
                break;
            case 2 :
                LEVEL_UP(gamestate);
                break;
            case 3 :
                SKILL(gamestate);
                break;
            case 4 :
                UNDO(gamestate);
                break;
            case 5 :
                END_TURN(gamestate);
                break;
            case 6 :
                MOVE(gamestate);
                break;
            case 7 :
                SAVE(gamestate);
                break;
            case 8 :
                EXIT(gamestate);
                break;
        }
    }
}

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
void LEVEL_UP(Stack *gamestate) {
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

// Prosedur untuk memakai skill yang sedang dimiliki pemain
void SKILL(Stack *gamestate) {
    printf("Pass\n");
    // $ Kamus Lokal
    Player CurrP;
    CurrP = GetCurrPlayer(*gamestate);
    // $ Algoritma
    printf("You have used the skill : ");
    //PrintInfoHead(Skill(P1Info(Curr(*gamestate))));
    PrintInfoHead(Skill(CurrP));
    printf("\n");
    printf("All your buildings have been Leveled Up!!\n");
}

// Prosedur untuk melakukan UNDO
void UNDO(Stack *gamestate) {
    // $ Kamus Lokal
    Sinfotype Buang;
    /*
    if (UsedSkill(InfoSkill(gamestate))) {
        printf("You cannot Undo past the Skill command!");
    } else if (IsFirstAct(*gamestate)) {
        printf("You cannot Undo when you haven't done anything!"); 
    } else {
    */
        Pop(gamestate,&Buang);
    //}
}

// Prosedur untuk melakukan END_TURN
void END_TURN(Stack *gamestate) {
    ChangeTurn(gamestate);
}

// Prosedur untuk melakukan SAVE
void SAVE(Stack *gamestate)
{
    printf("Lokasi save file: ");
}


// Prosedur untuk melakukan MOVE
void MOVE(Stack *gamestate)
{
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

// Prosedur untuk melakukan EXIT Game
void EXIT(Stack *gamestate)
{
    char inp;
    printf("Apakah Anda ingin melakukan save terlebih dahulu? Y/N\n");
    scanf(" %c", &inp);
    if (inp == 'Y') {
        SAVE(gamestate);
    } else if (inp == 'N') {
        //ExitMenu = true;
    }
    // keluar
}
