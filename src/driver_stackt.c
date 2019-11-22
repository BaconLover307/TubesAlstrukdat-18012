/* Program          : driver_stackt.c */
/* Deskripsi        : Driver Stackt */

//#include "stackt.h"
//#include "graph.h"
//#include "mesinkata_faris.h"
#include "includes.c"
#include <stdio.h>

// $ Kamus
Stack S;
Player P1, P2;
int Turn;
Bangunan Build;
TabColor BukuWarna;

// $ Algo
// $ ************ Prototype ************
// $ *** Konstruktor/Kreator ***
int main() {
puts("======Inisiasi Bangunan======");
char load;
char command[100];
Stack GameState;
Player PlayerOne, PlayerTwo;
Bangunan DataBangunan;
TabColor Pallete;
MATRIKS MapBlueprint;
Graph RelasiBan;
int Baris, Kolom, CountBan;

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
InsVPrio(&ListBan(PlayerOne), 1);
InsVPrio(&ListBan(PlayerTwo), 2);
puts("======Inisiasi Stack======");
MakeBukuWarna(&BukuWarna);
CreatePlayer(&P1);
CreatePlayer(&P2);
P1Info(Curr(S)) = P1;
P2Info(Curr(S)) = P2;
Turn = 1;

StartTurn(&S, P1, P2,Turn, Build);


puts("======Set Warna Player======");
if (IsFirstAct(S)) puts("Stack masih kosong");
puts("P1");
SetPlayerWarna(&P1Info(Curr(S)), &BukuWarna);
puts("P2");
SetPlayerWarna(&P2Info(Curr(S)), &BukuWarna);
puts("Curr:");
print_warna(Color(P1Info(Curr(S))),'1');
printf("\n");
print_warna(Color(P2Info(Curr(S))),'2');
printf("\n");

puts("======Push pertama======");
Push(&S, Curr(S));
if (IsFirstAct(S)) puts("Stack masih kosong");
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("Curr:");
//PrintCurr((S));

puts("======Update warna pertama======");
puts("Top:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
puts("Curr:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

puts("P1");
SetPlayerWarna(&P1Info(Curr(S)), &BukuWarna);
puts("P2");
SetPlayerWarna(&P2Info(Curr(S)), &BukuWarna);
print_warna(Color(P1Info(Curr(S))), '1');
printf("\n");
print_warna(Color(P2Info(Curr(S))), '2');
printf("\n");

puts("Top:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
puts("Curr:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
puts("======Push kedua======");
puts("Top:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
puts("Curr:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

Push(&S, Curr(S));
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("Curr:");
//PrintCurr((S));

puts("Top:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
puts("Curr:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

puts("======Pop pertama, harusnya kondisi sama seperti Push pertama======");
puts("Top:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
puts("Curr:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

Pop(&S, &Curr(S));
if (IsFirstAct(S)) puts("Stack masih kosong");
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("Curr:");
//PrintCurr((S));
puts("Top:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
puts("Curr:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

puts("======Pop kedua, harusnya Top kosong, Curr sama seperti set awal======");
puts("Top:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
puts("Curr:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

Pop(&S, &Curr(S));
if (IsFirstAct(S)) {
    puts("Stack masih kosong");
    puts("Top:");
    print_warna(Color(P1Info(InfoTop(S))), '1');
    printf("\n");
    print_warna(Color(P2Info(InfoTop(S))), '2');
    printf("\n");
}
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("Curr:");
//PrintCurr((S));
puts("Curr:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

}

