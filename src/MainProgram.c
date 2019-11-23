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
#include <unistd.h>

#include "includes.c"
#include "string.h"

// $ ***** Variables *****
char menu[100];
boolean Exit;       // = false;
boolean ExitMenu;   // = false;
boolean EndTurn;    // = false;
boolean AksiValid; 

// $ ******* MAIN PROGRAM ********
int main() {
do {
    Exit = false;
    MainM();
    // ASCII Art: MainMenu
    do {
        ExitMenu = false;
        Menu();
        // Lakukan Input dengan 'mesinkata'
        int idxMenu = 0;
        do {
            scanf("%c", menu + idxMenu);
        } while (menu[idxMenu++] != '\n');
        menu[--idxMenu] = '\0';
        //printf("Your choice is %s\n",menu);
        //getchar();

            // $ ######### TUTORIAL ########
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

        }   // $ ######### CREDITS ########
        else if (strcmp(menu, "CREDITS") == 0) {
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
            printf("Do you want to load a previous game? ");
            do {
                printf("Y/N\n");
                scanf(" %c", &load);
                if (load == 'Y') {
                    LoadFile(GameState);

                } else if (load == 'N') {
                    MakeEmptyBangunan(&DataBangunan, 100);
                    printf("Choose building color for Player 1! \n");
                    SetPlayerWarna(&PlayerOne,&Pallete);
                    printf("Choose building color for Player 2! \n");
                    SetPlayerWarna(&PlayerTwo,&Pallete);
                    // * CONFIGURE
                    STARTKATA();
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
                    // ! DEBUG
                    InsVPrio(&ListBan(PlayerOne),17);
                    InsVPrio(&ListBan(PlayerOne),13);

                    InsVPrio(&ListBan(PlayerTwo),4);
                    InsVPrio(&ListBan(PlayerTwo),5);
                    InsVPrio(&ListBan(PlayerTwo),6);
                    InsVPrio(&ListBan(PlayerTwo),7);
                    InsVPrio(&ListBan(PlayerTwo),8);
                    InsVPrio(&ListBan(PlayerTwo),9);
                    InsVPrio(&ListBan(PlayerTwo),10);

                    QAdd(&Skill(PlayerOne),"BA");

                    // * AKHIRNYA MULAI
                    Turn = 1;
                    StartTurn(&GameState,PlayerOne,PlayerTwo,Turn,DataBangunan);
                }
            } while (load != 'Y' && load != 'N');

            // todo maen game
            // * Countdown
            /*
            clrscrn();
            printf("              Starting game in...\n\n");
            sleep(0.5);
            printf("              3...\n\n");
            sleep(0.5);
            printf("                     2...\n\n");
            sleep(0.5);
            printf("                             1...\n");
            sleep(0.5);
            */
            clrscrn();
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
                    PrintMap(MapBlueprint, DataB(InfoTop(GameState)), P1Info(InfoTop(GameState)), P2Info(InfoTop(GameState)));
                    PrintCondition(InfoTop(GameState));
                    

                    // * Nerima Input
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
                    printf("[] V ===== V ===== V ===== V ===== V ===== V []\n\n", TurnInfo(InfoTop(GameState))),
                        printf("%s", NORMAL);

                        // $ ######### ATTACK ########
                    if (strcmp(command,"ATTACK") == 0) {
                        Push(&GameState,InfoTop(GameState));
                        Pop(&GameState,&Current);
                        ATTACK(&Current, RelasiBan);
                        if (AksiValid)
                            Push(&GameState, Current);
                        getchar();
                        puts("");

                    }   // $ ######### LEVEL_UP ########
                    else if (strcmp(command, "LEVEL_UP") == 0) {
                        Push(&GameState,InfoTop(GameState));
                        Pop(&GameState,&Current);
                    	LEVEL_UP(&Current);
                        if (AksiValid)
                            Push(&GameState,Current);
                        getchar();
                        puts("");

                    }   // $ ######### SKILL ########
                    else if (strcmp(command, "SKILL") == 0) {
                    	SKILL(&GameState,&DataB(InfoTop(GameState)));
                        puts("");

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
                        puts("");

                    }   // $ ######### END_TURN ########
                    else if (strcmp(command, "END_TURN") == 0) {
						END_TURN(&GameState);

                    }   // $ ######### SAVE ########
                    else if (strcmp(command, "SAVE") == 0) {
						SAVE(&InfoTop(GameState));
                        getchar();

                    }   // $ ######### EXIT ########
                    else if (strcmp(command, "EXIT") == 0) {
						EXIT(&InfoTop(GameState));
                        getchar();

					}
					else { Invalid(); getchar(); }
                    switch (Color(*TopP)) {
                    case 'R': printf("%s", RED); break;
                    case 'G': printf("%s", GREEN); break;
                    case 'B': printf("%s", BLUE); break;
                    case 'C': printf("%s", CYAN); break;
                    case 'M': printf("%s", MAGENTA); break;
                    default: printf("%s", NORMAL); break;
                    }
                    printf("[] ^ ===== ^ ===== ^ ===== ^ ===== ^ ===== ^ []\n\n", TurnInfo(InfoTop(GameState))),
                    printf("%s", NORMAL);

            	} while (!EndTurn);
                address A = First(ListBan(P2Info(InfoTop(GameState))));
                while (A != Nil)
                {
                    Tentara(ElmtBan(DataB(InfoTop(GameState)), Info(A))) = 10;
                    A = Next(A);
                }

            } while (!IsLose(PlayerOne) && !IsLose(PlayerTwo) && !ExitMenu);
            if (IsLose(PlayerTwo)) {
                P1Wins();
            } else if (IsLose(PlayerOne)) {
                P2Wins();
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
