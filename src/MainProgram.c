/* Tubes AlStrukDat */
/* Kelompok 8 */
/* Anggota:
/* - Muhammad Hasan           - 13518012 */
/* - Anna Elvira Hartoyo      - 13518045 */
/* - Daniel Riyanto           - 13518075 */
/* - Faris Muhammad Kautsar   - 13518105 */
/* - Gregorius Jovan Kresnadi - 13518135 */
/* File : MainProgram.c */
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
#include "string.h"
/*
#include "configure.h"
*/

// $ ***** Variables *****
char menu[100];
boolean Exit; // = false;
boolean ExitMenu; // = false;
boolean EndTurn; // = false;

// $ ******* MAIN PROGRAM ********
int main() {
do {
    Exit = false;
    // todo MainM();
    printf(LAN MAIN#\n");
    // ASCII Art: MainMenu
    do {
        ExitMenu = false;
        Menu();
        printf("Enter Menu : ");
        // Lakukan Input dengan 'mesinkata'
        int idxMenu = 0;
        do {
            scanf("%c", menu + idxMenu);
        } while (menu[idxMenu++] != '\n');
        menu[--idxMenu] = '\0';
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
			Bangunan *DataBangunan;
            TabColor Pallete;
            int config; // todo MASUKIN CONFIGURASI
            CreatePlayer(&PlayerOne);
            CreatePlayer(&PlayerTwo);
            MakeBukuWarna(&Pallete);
            MakeEmptyBangunan(DataBangunan,config);
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
                    SetPlayerWarna(&PlayerOne,&Pallete);
                    printf("Choose building color for Player 2! \n");
                    SetPlayerWarna(&PlayerTwo,&Pallete);

                    StartTurn(&GameState,PlayerOne,PlayerTwo,Turn);
                    // * Countdown
                    clrscrn();
                    printf("              Starting game in...\n\n");
                    sleep(1);
                    printf("              3...\n\n");
                    sleep(1);
                    printf("                     2...\n\n");
                    sleep(1);
                    printf("                             1...\n");
                    sleep(1);
                    clrscrn();
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
                do {
                    // $$ Inisiasi Turn
                    // $ Kamus Turn
                    EndTurn = false;
                    Player *CurrP;
                    Player *EnemyP;
                    Queue *Qcurr;
                    Queue *Qenemy;
                    if (TurnInfo(Curr(GameState)) == 1) {
                        CurrP = &P1Info(Curr(GameState));
                        EnemyP = &P2Info(Curr(GameState));
                    } else {
                        CurrP = &P2Info(Curr(GameState));
                        EnemyP = &P1Info(Curr(GameState));
                    }
                    Qcurr = &Skill(*CurrP);
                    Qenemy = &Skill(*EnemyP);

                    // $ Display Status
                    PrintCurr(GameState);
                    Command();
                    int idxCommand = 0;
                    do {
                        scanf("%c", command + idxCommand);
                    } while (command[idxCommand++] != '\n');
                    command[--idxCommand] = '\0';
					printf("\n");


                        // $ ######### ATTACK ########
                    if (strcmpi(command,"ATTACK") == 0) {
                        Push(&GameState,Curr(GameState));
                        ATTACK(&GameState, DataBangunan);

                    }   // $ ######### LEVEL_UP ########
                    else if (strcmpi(command, "LEVEL_UP") == 0) {
                        Push(&GameState,Curr(GameState));
                    	LEVEL_UP(&GameState, DataBangunan);

                    }   // $ ######### SKILL ########
                    else if (strcmpi(command, "SKILL") == 0) {
                        Push(&GameState,Curr(GameState));
                    	SKILL(&GameState, DataBangunan);

                    }   // $ ######### MOVE ########
                    else if (strcmpi(command, "MOVE") == 0) {
                        Push(&GameState,Curr(GameState));
						MOVE(&GameState);


                    }   // $ ######### UNDO ########
                    else if (strcmpi(command, "UNDO") == 0) {
						UNDO(&GameState);

                    }   // $ ######### END_TURN ########
                    else if (strcmpi(command, "END_TURN") == 0) {
						EndTurn = true;
                        // ! Detector Skill Instant Reinforcement
                        CheckGetIR(CurrP,DataBangunan);

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
            } while (/*!IsLose(PlayerOne) && !IsLose(PlayerTwo) && */!ExitMenu);
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
