/* File : player.h */
/* Definisi ADT Player */

#ifndef player_H
#define player_H

#include "boolean.h"
#include "array.h"
#include "queue.h"
#include "pcolor.h"
#include "listlinier.h"

typedef struct {
    boolean attackUp;
    boolean criticalHit;
    boolean shield;
    boolean extraTurn;
} StatusEffect;

typedef struct {
    Queue queueSkill;       // queue penyimpan skill
    List listBangunan;      // list penyimpan kepemilikan listbangunan
    Warna color; 			// warna bangunan pemain
    StatusEffect FX;		// skill-skill pemain yang sedang aktif
} Player;

// ! ********* AKSES (Selektor) *********
// $ Jika P adalah Player, maka akses elemen :
#define Color(P) (P).color
#define Skill(P) (P).queueSkill
#define ListBan(P) (P).listBangunan
#define FX(P) (P).FX

// $ Jika F adalah FX, maka akses elemen :
#define AU(F) (F).attackUp
#define CH(F) (F).criticalHit
#define SH(F) (F).shield
#define ET(F) (F).extraTurn


// $ ********* Prototype *********

// $ *** Condition Check ***

// * Mengirim true jika list kepemilikan listbangunan kosong
boolean IsLose(Player P);

// $ ***** Creator *****

// * I.S. P terdefinisi
// * F.S. Sebuah P terbentuk dengan karakter listbangunan akan sesuai
// *      konfigurasi dan warna listbangunan sesuai yang dipilih
void CreatePlayer(Player *P);

// $ ***** Basic Operators *****

// $ *** Color Handling ***

// * I.S. Player terdefinisi
// * F.S. Warna listbangunan player akan menjadi C
void SetPlayerWarna(Player *P, TabColor * Palet);

// $ *** Skills ****

// * I.S. Player P terdefinisi dan Bangunan B terdefinisi, game sedang berjalan
// * F.S. Seluruh bangunan yang dimiliki pemain P akan naik 1 level secara instan tanpa perlu ada jumlah tentara M/2
// * 	  pada listbangunan itu dan tanpa pengurangan jumlah tentara sebanyak M/2 saat kenaikan level*/
// * Pemain mendapat skill ini hanya saat awal permainan
void InstantUpgrade(Player *P, Bangunan *B);

// * I.S Player P terdefinisi, game sedang berjalan
// * F.S. Setelah end_turn (giliran berkhir), pemain selanjutnya tetap pemain yang sama
// * Pemain mendapat skill ini jika Fort pemain direbut lawan
void ExtraTurn(Player *P);

/* PENDING DULU :(
void Shield(Player *P);


void AttackUp(Player *P);

void CriticalHit();

*/


// * I.S. Player P dan Bangunan B terdefinisi, game sedang berjalan
// * F.S. Seluruh listbangunan mendapat tambahan 5 pasukan jika jumlah tentara setelah ditambah tidak melebihi batas maksimum.
// * Pemain mendapat skill ini di akhir gilirannya bila semua listbangunan yang ia miliki memiliki level 4
void InstantReinforcement(Player *P, Bangunan *B);

void checkGetIR(Player *P, Bangunan *B);

// * I.S. Player P dan Bangunan B terdefinisi, game sedang berjalan
// * F.S. Jumlah pasukan pada seluruh listbangunan musuh akan berkurang sebanyak 10. 
// * 	  Jika jumlah pasukan >= 10, akan dilakukan pengurangan sebanyak 10, tapi jika jumlah pasukan <1,
// * 	  jumlah pasukan menjadi 0
// * Pemain mendapat skill ini jika lawan baru saja bertambah listbangunannya menjadi 10
void Barrage(Player *P, Bangunan *B);



#endif
