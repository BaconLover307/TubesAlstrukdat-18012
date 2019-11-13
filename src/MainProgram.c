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
//#include "boolean.h"
#include "player.h"
#include "stackt.h"
#include "command.h"
//#include "array.h"
/*
#include "bangunan.h"
#include "skill.h"
#include "configure.h"
#include "peta.h"
#include "save.h"
#include "load.h"
*/
#include "string.h"
#include "assets.c"

// $ ***** Variables *****
char menu[100];
boolean Exit;
// = false;
boolean ExitMenu;
// = false;

// $ ******* MAIN PROGRAM ********
int main() {
while (!Exit) {
    // todo MainM();
    printf("#MAINMENU PLACEHOLDER#\n");
    // ASCII Art: MainMenu
    do {
        Exit = false;
        Menu();
        printf("Enter Menu:");
        scanf(" %s",&menu);
        printf("Your choice is %s\n",menu);
        //getchar();
        
        // $ ######### TUTORIAL ########
        if (strcmpi(menu,"TUTORIAL") == 0) {
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

            // $ ######### CREDITS ########
        } else if (strcmpi(menu, "CREDITS") == 0) {
            Credits();
            printf("\n");
            printf("Press enter to go back to main menu...");
            getchar();
            ExitMenu = true;

            // $ ######### QUIT ########
        } else if (strcmpi(menu, "QUIT") == 0) {
            // TODO Quit();
            printf("#QUIT PLACEHOLDER#\n");
            ExitMenu = true;
            Exit = true;

            // $ ######### PLAY GAME ########
        } else if (strcmpi(menu, "PLAY") == 0) {
            // todo Load Game
            
            // todo maen game
            // $ Kamus Lokal : Start Game
            Stack GameState;
            Player PlayerOne, PlayerTwo;
            CreatePlayer(&PlayerOne);
            CreatePlayer(&PlayerTwo);
            int Turn = 1;

            printf("#Ceritanya Maen#\n");
            //getchar(); 
            StartTurn(&GameState,PlayerOne,PlayerTwo,Turn);
            printf("Current turn : Player %d\n",TurnInfo(Curr(GameState)));
            do {
                COMMAND(&GameState);
            } while (!IsLose(PlayerOne) && !IsLose(PlayerTwo));
            if (IsLose(PlayerTwo)) {
                //
            }



        } else {
            Invalid();
            getchar();
        }
        
    } while (!ExitMenu);

}
return 0;
}