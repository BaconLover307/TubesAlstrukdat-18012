/* Tubes AlStrukDat */
/* Kelompok 8 */
/* Anggota: 
/* - Muhammad Hasan           - 13518012 */
/* - Anna Elvira Hartoyo      - 13518045 */
/* - Daniel Riyanto           - 13518075 */
/* - Faris Muhammad Kautsar   - 13518105 */
/* - Gregorius Jovan Kresnadi - 13518135 */
/* File : main.c */
/* Program Utama */
/* *
* Nama Program: Avatar World War

* Game Avatar World War adalah game​ turn-based strategy yang
* mensimulasikan perang dunia. Game ini dimainkan dengan cara 
* memasukkan perintah melalui command line interface. 
 */
// $ ******* INCLUDE FILES ********
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
/*
#include "player.h"
#include "bangunan.h"
#include "skill.h"
#include "peta.h"
#include "configure.h"
#include "command.h"
#include "save.h"
#include "load.h"
#include "display.h"
*/
#include "string.h"
#include "assets.c"

// $ ***** Variables *****
char menu[100];
boolean Exit = false;
boolean ExitMenu = false;

// $ ******* MAIN PROGRAM ********
int main() {
while (!Exit) {
    // todo MainM();
    printf("#MAINMENU PLACEHOLDER#\n");
    // ASCII Art: MainMenu
    do {
        Exit = false;
        //Menu();
        printf("# MENU PLACEHOLDER #\n");
        //printf("Enter Menu:")
        scanf("%s",&menu);
        getchar();
        if (strcmp(menu,"TUTORIAL") == 0) {
            printf("\n");
            // todo Tutorial1();
            clrscrn();
            printf("#TUT1 PLACEHOLDER#\n");
            getchar(); 
            clrscrn();
            // todo Tutorial2();
            printf("#TUT2 PLACEHOLDER#\n");
            getchar();
            clrscrn();
            ExitMenu = true;
        } else if (menu == "CREDITS") {
            // TODO Credits();
            printf("#CREDITS PLACEHOLDER#\n");
            printf("\n");
            printf("Press enter to go back to main menu...");
            getchar();
        } else if (menu == "QUIT") {
            // TODO Quit();
            printf("#QUIT PLACEHOLDER#\n");
            ExitMenu = true;
            Exit = true;
        } else if (menu == "PLAY") {
            // todo maen game
            printf("#Ceritanya Maen#\n");
            //getchar(); 
            



        } else {
            Invalid();
            getchar();
        }
        
    } while (!ExitMenu);

}
return 0;
}