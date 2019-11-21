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
    int duration;       // Durasi (turn) efektif Shield
    boolean activeSH;   // True jika durasi > 0
} ShieldFX;

typedef struct {
    boolean attackUp;
    boolean criticalHit;
    ShieldFX  shield;
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

// $ Jika SH adalah shield, maka akses elemen :
#define ActiveSH(SH) (SH).activeSH
#define Duration(SH) (SH).duration


// $ ********* Prototype *********

// $ ************* Condition Check *************

// * Mengirim true jika list kepemilikan listbangunan kosong
boolean IsLose(Player P);

// $ *************** Creator ***************

// * I.S. P terdefinisi
// * F.S. Sebuah P terbentuk dengan karakter listbangunan akan sesuai
// *      konfigurasi dan warna listbangunan sesuai yang dipilih
void CreatePlayer(Player *P);

// $ ************* Fungsi Untuk FX Shield *************

// * Mengecek bila durasi shield = 0, jika iya maka True
boolean IsSHWornOut(Player P);

// * Mengecek bila durasi shield = 2, jika iya maka True
boolean IsSHMax(Player P);

// * Mengecek durasi shield, jika >0 maka ActiveSH menjadi True
void CheckActive(Player *P);

// * Mengurangi durasi shield, sekaligus mengupdate ActiveSH
void ReduceDurationSH(Player *P);

// $ *************** Basic Operators ***************

// $ ************* Color Handling *************

// * I.S. Player terdefinisi
// * F.S. Warna listbangunan player akan menjadi C
void LoadPlayerWarna(Player *P, Warna C);


// * I.S. Player terdefinisi, TabColor terdefinisi dan tidak kosong
// * F.S. Warna bangunan player saat didisplay akan sesuai dengan yang dipilih pengguna
void SetPlayerWarna(Player *P, TabColor * Palet);

// $ ***** Skills ******

// $ *** Use Skill ***

// * I.S. Player P terdefinisi dan Bangunan B terdefinisi, game sedang berjalan
// * F.S. Seluruh bangunan yang dimiliki pemain P akan naik 1 level secara instan tanpa perlu ada jumlah tentara M/2
// * 	  pada listbangunan itu dan tanpa pengurangan jumlah tentara sebanyak M/2 saat kenaikan level*/
// * Pemain mendapat skill ini hanya saat awal permainan
void InstantUpgrade(Player *P, Bangunan *B);

// * I.S Player P terdefinisi, game sedang berjalan
// * F.S. Setelah end_turn (giliran berkhir), pemain selanjutnya tetap pemain yang sama
// * Pemain mendapat skill ini jika Fort pemain direbut lawan
void ExtraTurn(Player *P);

// * I.S. Terdapat SH di Head Skill(*P)
// * F.S. Seluruh bangunan yang dimiliki pemain akan memiliki pertahanan selama 2 turn
// * Pemain mendapat skill ini jika lawan menyerang, bangunan pemain berkurang 1, menjadi sisa 2
// * Menyalakan Status Effect Shield
void Shield(Player *P);

//* I.S. Terdapat AU di Head Skill(*P)
//* F.S. Pada giliran ini, pertahanan bangunan musuh tidak akan mempengaruhi penyerangan */
//* Pemain mendapat skill ini jika pemain baru saja menyerang tower lawan dan jumlah towernya menjadi 3 */
// * Menyalakan Status Effect AU
void AttackUp(Player *P);

// * I.S. Terdapat CH di Head Skill(*P)
// * F.S. Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan 
// *      serangan tepat selanjutnya hanya berkurang 1/2 dari jumlah seharusnya
// * Pemain mendapat skill ini jika lawan baru saja mengaktifkan extra turn
// * Menyalakan Status Effect CH
void CriticalHit();

// * I.S. Player P dan Bangunan B terdefinisi, game sedang berjalan
// * F.S. Seluruh listbangunan mendapat tambahan 5 pasukan jika jumlah tentara setelah ditambah tidak melebihi batas maksimum.
// * Pemain mendapat skill ini di akhir gilirannya bila semua listbangunan yang ia miliki memiliki level 4
void InstantReinforcement(Player *P, Bangunan *B);

// * I.S. Player P dan Bangunan B terdefinisi, game sedang berjalan
// * F.S. Jumlah pasukan pada seluruh listbangunan musuh akan berkurang sebanyak 10. 
// * 	  Jika jumlah pasukan >= 10, akan dilakukan pengurangan sebanyak 10, tapi jika jumlah pasukan <1,
// * 	  jumlah pasukan menjadi 0
// * Pemain mendapat skill ini jika lawan baru saja bertambah listbangunannya menjadi 10
void Barrage(Player *P, Player *E, Bangunan *B);

// $ *** Detect Skill ***

// * Pemain tidak akan mendapat skill ini selain dari daftar skill awal.
// * Tinggal selipin di CreatePlayer, masukin Q sendiri, dah...
void CheckGetIU(Queue *Q);

// * Pemain mendapat skill ini jika setelah sebuah lawan menyerang, bangunan pemain berkurang 1 menjadi sisa 2
// * Selipin di Capture, masukinnya P lawan dan Q lawan juga
void CheckGetSH(Player P, Queue *Q);

// * Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan.
// * Selipin di Capture, kalo yang direbut Fort. Masukin Q lawan.
void CheckGetET(Queue *Q);

// * Pemain mendapat skill ini jika pemain baru saja menyerang Tower lawan dan jumlah towernya menjadi 3.
// * Selipin di Capture, kalo yang direbut Tower. Masukin Q sendiri.
void CheckGetAU(Player P, Queue *Q, Banguan databuild);

// * Pemain mendapat skill ini jika lawan baru saja mengaktifkan skill Extra Turn.
// * Selipin di Skill bagian Extra Turn, di command.c. Masukin Q lawan
void CheckGetCH(Queue *Q);

// * Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki memiliki level 4
// * Selipin di END_TURN di MainProgram
void CheckGetIR(Player *P, Bangunan *B);

<<<<<<< HEAD
void CheckGetSH(Player P, Queue *Q);

void GetCH(Queue *Q);
=======
// * Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi 10 bangunan.
// * Selipin di Capture. Masukin P sendiri, Q lawan
void CheckGetBA(Player P, Queue *Q);
>>>>>>> 943afc102f34e7cf3606dfeafff5672ec3f2b284

#endif
