/* Program          : driver_stackt.c */
/* Deskripsi        : Driver Stackt */

#include "stackt.h"
#include "graph.h"
#include "mesinkata_faris.h"
//#include "includes.c"
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
Sinfotype Current; // ! BUAT TEMP
Sinfotype Buang; // ! BUANGAN
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
P1Info(InfoTop(S)) = P1;
P2Info(InfoTop(S)) = P2;
Turn = 1;

StartTurn(&S, P1, P2,Turn, Build);


puts("======Set Warna Player======");
Current = InfoTop(S);

if (IsFirstAct(S)) puts("Stack masih isi 1");
puts("P1");
SetPlayerWarna(&P1Info(Current), &BukuWarna);
puts("P2");
SetPlayerWarna(&P2Info(Current), &BukuWarna);
puts("Current:");
print_warna(Color(P1Info(Current)),'1');
printf("\n");
print_warna(Color(P2Info(Current)),'2');
printf("\n");
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

puts("======Push pertama======");
Push(&S, Current);
if (IsFirstAct(S)) puts("Stack masih kosong");
puts("Current:");
print_warna(Color(P1Info(Current)), '1');
printf("\n");
print_warna(Color(P2Info(Current)), '2');
printf("\n");
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("InfoTop:");
//PrintInfoTop((S));

puts("======Update warna pertama======");
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");
// ! TEMP

// ! AKSI
Current = InfoTop(S);
puts("P1");
SetPlayerWarna(&P1Info(Current), &BukuWarna);
puts("P2");
SetPlayerWarna(&P2Info(Current), &BukuWarna);
print_warna(Color(P1Info(Current)), '1');
printf("\n");
print_warna(Color(P2Info(Current)), '2');
printf("\n");

puts("Current:");
print_warna(Color(P1Info(Current)), '1');
printf("\n");
print_warna(Color(P2Info(Current)), '2');
printf("\n");
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

puts("======Push kedua======");
// ! PUSH
Push(&S, Current);

puts("Current:");
print_warna(Color(P1Info(Current)), '1');
printf("\n");
print_warna(Color(P2Info(Current)), '2');
printf("\n");
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");


//puts("Top:");
//PrintTop(InfoTop(S));
//puts("InfoTop:");
//PrintInfoTop((S));

puts("======Pop pertama, harusnya kondisi sama seperti Push pertama======");
Pop(&S, &Buang);
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

if (IsFirstAct(S)) puts("Stack isi 1");
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("InfoTop:");
//PrintInfoTop((S));

puts("======Pop kedua, harusnya Top kosong, InfoTop sama seperti set awal======");
Pop(&S, &Buang);
puts("InfoTop:");
print_warna(Color(P1Info(InfoTop(S))), '1');
printf("\n");
print_warna(Color(P2Info(InfoTop(S))), '2');
printf("\n");

if (IsFirstAct(S))
    puts("Stack isi 1");
//puts("Top:");
//PrintTop(InfoTop(S));
//puts("InfoTop:");
//PrintInfoTop((S));
}

