/* Program          : driver_stackt.c */
/* Deskripsi        : Driver Stackt */

#include "stackt.h"
#include "graph.h"
#include "mesinkata_faris.h"
#include "includes.c"
#include <stdio.h>

// $ Kamus
boolean EndTurn;
boolean ExitMenu;
boolean AksiValid;

Stack S;
Player P1, P2;
int Turn;
Bangunan Build;
TabColor BukuWarna;

void PrintMap(MATRIKS M, Bangunan B, Player One, Player Two)
{
    int i, j;
    for (i = 1; i <= (MaxBrs(M) + 2); i++)
    {
        for (j = 1; j < (MaxKol(M) + 3); j++)
        {
            //printf("%d%d",i,j);
            if (i == 1)
            {
                printf("+");
                if (j == (MaxKol(M) + 2))
                {
                    printf("++\n");
                }
            }
            else if (i == (MaxBrs(M) + 2))
            {
                printf("+");
                if (j == (MaxKol(M) + 2))
                    printf("++\n");
            }
            else if (j == 1)
            {
                printf("+ ");
            }
            else if (j == (MaxKol(M) + 2))
            {
                printf(" +\n");
            }
            else if ((Elmt(M, (i - 1), (j - 1))) == 0)
            {
                printf(" ");
            }
            else
            {
                ElType Mem = Elmt(M, (i - 1), (j - 1));
                char C = Name(ElmtBan(B, Mem));
                if (Search(ListBan(One), Mem) != Nil)
                {
                    print_warna(Color(One), C);
                }
                else if (Search(ListBan(Two), Mem) != Nil)
                {
                    print_warna(Color(Two), C);
                }
                else
                {
                    printf("%c", C);
                }
            }
        }
    }
    printf("\n");
}

// $ Algo
// $ ************ Prototype ************
// $ *** Konstruktor/Kreator ***
int main() {
puts("#####################################Inisiasi Bangunan#####################################");
char load;
char command[100];
Sinfotype Current; // * Kondisi yg berlangsung (temp)
Sinfotype Buang;   // * Kondisi buangan
Player P1, P2;
Bangunan DataBangunan;
TabColor Pallete;
MATRIKS MapBlueprint;
Graph RelasiBan;
int Baris, Kolom, CountBan, Turn;
CreatePlayer(&P1);
CreatePlayer(&P2);
MakeBukuWarna(&Pallete);

MakeEmptyBangunan(&DataBangunan, 100);
printf("Choose building color for Player 1! \n");
SetPlayerWarna(&P1, &Pallete);
printf("Choose building color for Player 2! \n");
SetPlayerWarna(&P2, &Pallete);
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
InsVPrio(&ListBan(P1), 1);
InsVPrio(&ListBan(P1), 9);
InsVPrio(&ListBan(P1), 10);
InsVPrio(&ListBan(P1), 13);
InsVPrio(&ListBan(P2), 2);
InsVPrio(&ListBan(P2), 4);
InsVPrio(&ListBan(P2), 7);
InsVPrio(&ListBan(P2), 8);

// * AKHIRNYA MULAI
Turn = 1;
StartTurn(&S, P1, P2, Turn, DataBangunan);
PrintMap(MapBlueprint, DataB(InfoTop(S)), P1, P2);
    puts("#####################################Set Warna Player#####################################");
Current = CopyState(InfoTop(S));
getchar();
getchar();

if (IsFirstAct(S)) puts("Stack masih isi 1");
puts("Current:");
print_warna(Color(P1Info(Current)),'1');
printf("\n");
print_warna(Color(P2Info(Current)),'2');
printf("\n");
PrintCondition(Current);
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
PrintCondition(InfoTop(S));

puts("#####################################Push pertama#####################################");
getchar();
getchar();
Sinfotype temp = CopyState(Current);

//Push(&S, Current);
if (IsFirstAct(S)) puts("Stack masih kosong");
puts("Current:");
print_warna(Color(P1Info(Current)), '1');
printf("\n");
print_warna(Color(P2Info(Current)), '2');
printf("\n");
PrintCondition(Current);

puts("TEMP:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
print_warna(Color(P1Info(temp)), '1');
printf("\n");
print_warna(Color(P2Info(temp)), '2');
printf("\n");
PrintCondition(temp);

puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
PrintCondition(InfoTop(S));

getchar();
getchar();
puts("##################################### Update warna pertama #####################################");
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
// ! TEMP

// ! AKSI
Current = InfoTop(S);
puts("P1");
SetPlayerWarna(&P1Info(Current), &Pallete);
puts("P2");
SetPlayerWarna(&P2Info(Current), &Pallete);
print_warna(Color(P1Info(Current)), '1');
printf("\n");
print_warna(Color(P2Info(Current)), '2');
printf("\n");

puts("Current:");
print_warna(Color(P1Info(Current)), '1');
printf("\n");
print_warna(Color(P2Info(Current)), '2');
printf("\n");
PrintCondition(Current);

puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
PrintCondition(InfoTop(S));

puts("#####################################Push kedua#####################################");
// ! PUSH
Push(&S, Current);

puts("Current:");
print_warna(Color(P1Info(Current)), '1');
printf("\n");
print_warna(Color(P2Info(Current)), '2');
printf("\n");
PrintCondition(Current);

puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
PrintCondition(InfoTop(S));

//puts("Top:");
//PrintTop(InfoTop(S));
//puts("InfoTop:");
//PrintInfoTop((S));

puts("#####################################Pop pertama, harusnya kondisi sama seperti Push pertama#####################################");
Pop(&S, &Buang);
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
PrintCondition(InfoTop(S));

if (IsFirstAct(S)) puts("Stack isi 1");
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("InfoTop:");
//PrintInfoTop((S));

puts("#####################################Pop kedua, harusnya Top kosong, InfoTop sama seperti set awal#####################################");
Pop(&S, &Buang);
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
PrintCondition(InfoTop(S));

if (IsFirstAct(S))
    puts("Stack isi 1");
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("InfoTop:");
//PrintInfoTop((S));
}

