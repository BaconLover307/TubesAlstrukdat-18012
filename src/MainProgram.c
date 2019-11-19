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
#include "includes.c"
/*
#include "configure.h"
*/
#include "string.h"

// $ ***** Variables *****
char menu[100];
boolean Exit;
// = false;
boolean ExitMenu;
// = false;
boolean EndTurn;

// $ ******* MAIN PROGRAM ********
int main() {
do {
    Exit = false;
    // todo MainM();
    printf("#TAMPILAN MAIN#\n");
    // ASCII Art: MainMenu
    do {
        Menu();
        printf("Enter Menu : ");
        scanf(" %s",&menu);
        //printf("Your choice is %s\n",menu);
        //getchar();

            // $ ######### TUTORIAL ########
        if (strcmpi(menu,"TUTORIAL") == 0) {
            printf("\n");
            // todo Tutorial1();
            clrscrn();
            printf("#TUT1 PLACEHOLDER#\n");
            getchar();
            getchar();
            clrscrn();
            // todo Tutorial2();
            printf("#TUT2 PLACEHOLDER#\n");
            getchar();
            clrscrn();
            ExitMenu = true;

        }   // $ ######### CREDITS ########
        else if (strcmpi(menu, "CREDITS") == 0) {
            Credits();
            printf("\n");
            printf("Press enter to go back to main menu...");
            getchar();
            getchar();
            ExitMenu = true;

        }   // $ ######### QUIT ########
        else if (strcmpi(menu, "QUIT") == 0) {
            // TODO Quit();
            printf("#QUIT PLACEHOLDER#\n");
            ExitMenu = true;
            Exit = true;

        } // $ ######### PLAY GAME ########
        else if (strcmpi(menu, "PLAY") == 0) {
            // $ Kamus Lokal : Start Game
            char load;
            char command[100];
            Stack GameState;
            Player PlayerOne, PlayerTwo;
			Bangunan DataBangunan;
            CreatePlayer(&PlayerOne);
            CreatePlayer(&PlayerTwo);
            int Turn = 1;

            // todo Load Game
            printf("Do you want to load a previous game? ");
            do {
                printf("Y/N\n");
                scanf(" %c", &load);
                if (load == 'Y') {
                    LoadFile(GameState);
                } else if (load == 'N') {
                    //LoadData();
                    
                    printf("Choose building color for Player 1! \n");
                    printf("Available colors : ");
                    

                    StartTurn(&GameState,PlayerOne,PlayerTwo,Turn);

                }
            } while (load != 'Y' && load != 'N');

            // todo maen game

            printf("#Ceritanya Maen#\n");
            //getchar();
            //Player TestP = GetCurrPlayer(GameState);
            //Player TestP = P1Info(Curr(GameState));
            //printf("pass\n");
            //PrintInfoHead(Skill(TestP));
            do {
            	printf("Current turn : Player %d\n",TurnInfo(Curr(GameState)));
                do {
                    EndTurn = false;

                    printf("List Command :\n");
                    printf(">> ATTACK\n");
                    printf(">> LEVEL_UP\n");
                    printf(">> SKILL\n");
                    printf(">> MOVE\n");
                    printf(">> UNDO\n");
                    printf(">> END_TURN\n");
                    printf(">> SAVE\n");
                    printf(">> EXIT\n");
                    printf("Enter Command : ");
                    scanf(" %s",&command);
					printf("\n");


                        // $ ######### ATTACK ########
                    if (strcmpi(command,"ATTACK") == 0) {
                        ATTACK(&GameState);

                    }   // $ ######### LEVEL_UP ########
                    else if (strcmpi(command, "LEVEL_UP") == 0) {
                    	LEVEL_UP(&GameState,&DataBangunan);

                    }   // $ ######### SKILL ########
                    else if (strcmpi(command, "SKILL") == 0) {
                    	SKILL(&GameState,&DataBangunan);

                    }   // $ ######### MOVE ########
                    else if (strcmpi(command, "MOVE") == 0) {
						MOVE(&GameState);

                    }   // $ ######### UNDO ########
                    else if (strcmpi(command, "UNDO") == 0) {
                        //fflush(stdout);
						UNDO(&GameState);

                    }   // $ ######### END_TURN ########
                    else if (strcmpi(command, "END_TURN") == 0) {
						EndTurn = true;

                    }   // $ ######### SAVE ########
                    else if (strcmpi(command, "SAVE") == 0) {
						SAVE(&GameState);

                    }   // $ ######### EXIT ########
                    else if (strcmpi(command, "EXIT") == 0) {
						ExitMenu = EXIT(&GameState);
						EndTurn = ExitMenu;

					}
					else Invalid();
					printf("\n");

            	} while (!EndTurn);
                if (!ExitMenu) {
					ChangeTurn(&GameState);
					EndTurn = false;
				}

            } while (!IsLose(PlayerOne) && !IsLose(PlayerTwo) && !ExitMenu);
            if (IsLose(PlayerTwo)) {
                printf("pesan menang P1\n");
            } else if (IsLose(PlayerOne)) {
                printf("pesan menang P2\n");
			}

        } else {
            Invalid();
            getchar();
        }

    } while (!ExitMenu);
    ExitMenu = false;
} while (!Exit);
return 0;
}
