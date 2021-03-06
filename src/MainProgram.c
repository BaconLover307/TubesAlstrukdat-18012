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
#include <unistd.h>

#include "command/command.h"
#include "load/load.h"
#include "save/save.h"
#include "assets/assets.c"
#include "string.h"

// $ ***** Variables *****
char menu[100];
boolean Exit;       // = false;
boolean ExitMenu;   // = false;
boolean EndTurn;    // = false;
boolean AksiValid;	// = true

// $ ******* MAIN PROGRAM ********
int main() {
do {
    Exit = false;
    puts("");
    MainM();
    do {
        ExitMenu = false;
        Menu();
        // * Lakukan Input dengan 'mesinkata'
        int idxMenu = 0;
        do {
            scanf("%c", menu + idxMenu);
        } while (menu[idxMenu++] != '\n');
        menu[--idxMenu] = '\0';

            // $ ######### TUTORIAL ########
        if (strcmp(menu,"TUTORIAL") == 0) {
            printf("\n");
            // todo Tutorial1();
            puts("");
            printf("#TUT1 PLACEHOLDER#\n");
            getchar();
            puts("");
            // todo Tutorial2();
            printf("#TUT2 PLACEHOLDER#\n");
            getchar();
            puts("");
            ExitMenu = true;

        }   // $ ######### CREDITS ########
        else if (strcmp(menu, "CREDITS") == 0) {
            puts("");
            Credits();
            printf("\n");
            printf("Press enter to go back to the main menu...");
            getchar();
            ExitMenu = true;

        }   // $ ######### QUIT ########
        else if (strcmp(menu, "QUIT") == 0) {
            QuitImg();
            ExitMenu = true;
            Exit = true;

        } // $ ######### PLAY GAME ########
        else if (strcmp(menu, "PLAY") == 0) {
            // $ Kamus Lokal : Start Game
            puts("");
            char load;
            char command[100];
            Stack GameState;
            Sinfotype Current; // * Kondisi yg berlangsung (temp)
            Sinfotype Buang;   // * Kondisi buangan
            Player PlayerOne, PlayerTwo;
			Bangunan DataBangunan;
            TabColor Pallete;
            MATRIKS MapBlueprint;
            Graph RelasiBan;
            int Baris, Kolom, CountBan, Turn;
            CreatePlayer(&PlayerOne);
            CreatePlayer(&PlayerTwo);
            MakeBukuWarna(&Pallete);

            // todo Load Game
            printf("Do you want to load a previous game?\n");
            do {
                printf("Enter your input (Y/N) : ");
                scanf(" %c", &load);
                if (load == 'Y') {
                    LoadFile(&Current, &RelasiBan, &MapBlueprint);
                    while (TurnInfo(Current) == -1) {
                        LoadFile(&Current, &RelasiBan, &MapBlueprint);
                    }
                    PlayerOne = P1Info(Current);
                    PlayerTwo = P2Info(Current);
                    Turn = TurnInfo(Current);
                    DataBangunan = CopyBangunan(DataB(Current));
                    StartTurn(&GameState,PlayerOne,PlayerTwo,Turn,DataBangunan);
                } else if (load == 'N') {
                    printf("\n[#]---- Starting A New Game ----[#]\n\n");
                    MakeEmptyBangunan(&DataBangunan, 100);
                    printf("\nChoose building color for Player 1! \n");
                    SetPlayerWarna(&PlayerOne,&Pallete);
                    printf("\nChoose building color for Player 2! \n");
                    SetPlayerWarna(&PlayerTwo,&Pallete);
                    // * CONFIGURE
                    char konf[20] = "config.txt";
                    STARTKATA(konf);
                    Baris = KataToInt(CKata);
                    ADVKATA();
                    Kolom = KataToInt(CKata);
                    ADVKATA();
                    CountBan = KataToInt(CKata);
                    ADVKATA();
                    DataBangunan = KataToBangunan(CountBan);
                    MapBlueprint = KataToMatriks(Baris, Kolom, DataBangunan);
                    RelasiBan = KataToGraph(CountBan);

                    // * Bangunan pertama pemain
                    InsVPrio(&ListBan(PlayerOne),1);
                    InsVPrio(&ListBan(PlayerTwo),2);

                    // * AKHIRNYA MULAI
                    Turn = 1;
                    StartTurn(&GameState,PlayerOne,PlayerTwo,Turn,DataBangunan);
                } else {
                    puts("Input is invalid!");
                }
            } while (load != 'Y' && load != 'N');

            // * Countdown
            puts("");
            printf("\n              Starting game in...\n\n");
            sleep(1);
            printf("              3...\n\n");
            sleep(1);
            printf("                     2...\n\n");
            sleep(1);
            printf("                             1...\n");
            sleep(1);
            puts("");
            getchar();

            do {
                // ** Inisiasi Turn
                // * Kamus Turn
                EndTurn = false;
                Player *TopP;
                List *Ltop;
                if (TurnInfo(InfoTop(GameState)) == 1) {
                    TopP = &P1Info(InfoTop(GameState));
                } else {
                    TopP = &P2Info(InfoTop(GameState));
                }
                Ltop = &ListBan(*TopP);
                TambahAllTentara(*Ltop, &DataB(InfoTop(GameState)));

                do {
                    // * Inisiasi Command Center
                    AksiValid = true;

                    // * Display Status
                    puts("[#]---- MAP ----[#]");
                    PrintMap(MapBlueprint, DataB(InfoTop(GameState)), P1Info(InfoTop(GameState)), P2Info(InfoTop(GameState)));
                    PrintCondition(InfoTop(GameState));


                    // * Menerima Input
                    Command();
                    int idxCommand = 0;
                    do {
                        scanf("%c", command + idxCommand);
                    } while (command[idxCommand++] != '\n');
                    command[--idxCommand] = '\0';
					printf("\n");

                    // * Proses Input
                    switch (Color(*TopP)) {
                    case 'R': printf("%s", RED); break;
                    case 'G': printf("%s", GREEN); break;
                    case 'B': printf("%s", BLUE); break;
                    case 'C': printf("%s", CYAN); break;
                    case 'M': printf("%s", MAGENTA); break;
                    default: printf("%s", NORMAL); break;
                    }
                    printf("[] V ===== V ===== V ===== V ===== V ===== V []\n\n"),
                    printf("%s", NORMAL);

                        // $ ######### ATTACK ########
                    if (strcmp(command,"ATTACK") == 0) {
                        Push(&GameState,InfoTop(GameState));
                        Pop(&GameState,&Current);
                        ATTACK(&Current, RelasiBan);
                        if (AksiValid)
                            Push(&GameState, Current);
                        getchar();

                    }   // $ ######### LEVEL_UP ########
                    else if (strcmp(command, "LEVEL_UP") == 0) {
                        Push(&GameState,InfoTop(GameState));
                        Pop(&GameState,&Current);
                    	LEVEL_UP(&Current);
                        if (AksiValid)
                            Push(&GameState,Current);
                        getchar();
                        getchar();

                    }   // $ ######### SKILL ########
                    else if (strcmp(command, "SKILL") == 0) {
                    	SKILL(&GameState,&DataB(InfoTop(GameState)));
                        getchar();
                        getchar();

                    }   // $ ######### MOVE ########
                    else if (strcmp(command, "MOVE") == 0) {
                        Push(&GameState,InfoTop(GameState));
                        Pop(&GameState,&Current);
						MOVE(&Current, RelasiBan);
                        if (AksiValid)
                            Push(&GameState, Current);
                        getchar();

                    }   // $ ######### UNDO ########
                    else if (strcmp(command, "UNDO") == 0) {
						UNDO(&GameState);
                        getchar();

                    }   // $ ######### END_TURN ########
                    else if (strcmp(command, "END_TURN") == 0) {
						END_TURN(&GameState);

                    }   // $ ######### SAVE ########
                    else if (strcmp(command, "SAVE") == 0) {
						SAVE(&InfoTop(GameState), RelasiBan, MapBlueprint);
                        getchar();

                    }   // $ ######### EXIT ########
                    else if (strcmp(command, "EXIT") == 0) {
						EXIT(&InfoTop(GameState), RelasiBan, MapBlueprint);
                        getchar();

					}
					else { Invalid(); getchar(); }
                    switch (Color(*TopP)) {
                        case 'R': printf("%s", RED); break;
                        case 'G': printf("%s", GREEN); break;
                        case 'B': printf("%s", BLUE); break;
                        case 'C': printf("%s", CYAN); break;
                        case 'M': printf("%s", MAGENTA); break;
                        default : printf("%s", NORMAL); break;
                    }
                    printf("[] ^ ===== ^ ===== ^ ===== ^ ===== ^ ===== ^ []\n\n"),
                    printf("%s", NORMAL);

            	} while (!EndTurn);

            } while (!IsLose(P1Info(InfoTop(GameState))) && !IsLose(P2Info(InfoTop(GameState))) && !ExitMenu);
            if (IsLose(P2Info(InfoTop(GameState)))) {
                P1Wins();
                getchar();
                ExitMenu = true;
            } else if (IsLose(P1Info(InfoTop(GameState)))) {
                P2Wins();
                getchar();
                ExitMenu = true;
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
