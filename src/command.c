#include <stdio.h>
#include <command.h>

// Main Prosedur untuk command
void COMMAND() {
    char input[100];
    while (1) {
        printf("ENTER COMMAND : ");
        scanf("%s", input);
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

}

// Prosedur untuk Melakukan LEVEL UP
void LEVEL_UP() {

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

}


// Prosedur untuk melakukan MOVE
void MOVE() {

}

// Prosedur untuk melakukan EXIT Game
void EXIT() {
    printf("Apakah Anda ingin melakukan save terlebih dahulu ?");
}
