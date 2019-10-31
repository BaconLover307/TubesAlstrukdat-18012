#include <stdio.h>
#include "player.h"
#include "command.h"

// Main Prosedur untuk command
void COMMAND() {
    int input;
    while (1) {
        printf("List command :\n");
        printf("1. Attack\n");
        printf("2. Level Up\n");
        printf("3. Skill\n");
        printf("4. Undo\n");
        printf("5. End Turn\n");
        printf("6. Save\n");
        printf("7. Move\n");
        printf("8. Exit\n");
        printf("ENTER COMMAND : ");
        scanf("%d", input);
        switch(input) {
            case 1 :
                ATTACK();
                break;
            case 2 :
                LEVEL_UP();
                break;
            case 3 :
                SKILL();
                break;
            case 4 :
                UNDO();
                break;
            case 5 :
                END_TURN();
                break;
            case 6 :
                SAVE();
                break;
            case 7 :
                MOVE();
                break;
            case 8 :
                EXIT();
                break;
        }
    }
}

// Prosedur untuk melakukan ATTACK
void ATTACK() {
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
void LEVEL_UP() {
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

// Prosedur untuk mamakai skill yang sedang dimiliki pemain
void SKILL() {

}

// Prosedur untuk melakukan UNDO
void UNDO() {

}

// Prosedur untuk melakukan END_TURN
void END_TURN() {

}

// Prosedur untuk melakukan SAVE
void SAVE() {
    printf("Lokasi save file: ");
}


// Prosedur untuk melakukan MOVE
void MOVE() {
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
void EXIT() {
    char inp;
    printf("Apakah Anda ingin melakukan save terlebih dahulu? Y/N\n");
    if (inp == 'Y') {
        SAVE();
    }
    // keluar
}
