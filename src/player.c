/* File : player.c */
/* Implementasi ADT Player */

#include "player.h"
#include "string.h"
#include <stdio.h>

/*
? typedef struct {
*    int duration;       Durasi (turn) efektif Shield, max 2 turn lawan
*    boolean activeSH;   True jika durasi > 0
? } ShieldFX;

? typedef struct {
*    boolean attackUp;
*    boolean criticalHit;
*    ShieldFX shield;
*    boolean extraTurn;
? } StatusEffect;

? typedef struct {
*    Queue queueSkill;      queue penyimpan skill
*    List listBangunan;     list penyimpan kepemilikan listbangunan
*    Warna color;           warna bangunan pemain
*    StatusEffect FX;       skill-skill pemain yang sedang aktif
? } Player;

! ********* AKSES (Selektor) *********
? Jika P adalah Player, maka akses elemen :
* #define Color(P) (P).color
* #define Skill(P) (P).queueSkill
* #define ListBan(P) (P).listBangunan
* #define ET(P) (P).extraTurn

? Jika F adalah FX, maka akses elemen :
* #define AU(F) (F).attackUp
* #define CH(F) (F).criticalHit
* #define SH(F) (F).shield
* #define ET(F) (F).extraTurn

? Jika SH adalah shield, maka akses elemen :
* #define ActiveSH(SH) (SH).activeSH
* #define Duration(SH) (SH).duration
*/


// $ ******************* Prototype *******************

// $ ************* Condition Check *************

boolean IsLose(Player P) {
    return IsEmptyList(ListBan(P));
}

// $ *************** Creator ***************
void CreatePlayer(Player *P) {
    // * Handling Queue Skill
    CreateQueue(&Skill(*P),10);
    CheckGetIU(&Skill(*P));
    // * Handling Status Effect
    AU(FX(*P)) = false;
    CH(FX(*P)) = false;
    Duration(SH(FX(*P))) = 0;
    ActiveSH(SH(FX(*P))) = false;
    ET(FX(*P)) = false;
    // * Handling List Bangunan
    CreateEmptyList(&ListBan(*P));
    // * Handling Warna Default, Normal
    LoadPlayerWarna(P,'X');
}

// $ ************* Fungsi Untuk FX Shield *************
boolean IsSHWornOut(Player P) {
    return Duration(SH(FX(P))) == 0;
}

boolean IsSHMax(Player P) {
    return Duration(SH(FX(P))) == 2;
}
void CheckActive(Player *P) {
    ActiveSH(SH(FX(*P))) = (Duration(SH(FX(*P))) > 0);
}

void ReduceDurationSH(Player *P) {
    if (!IsSHWornOut(*P)) {
        Duration(SH(FX(*P))) -= 1;
    }
    CheckActive(P);
}

// $ *************** Basic Operators ***************

// $ ************* Color Handling *************
void LoadPlayerWarna(Player *P, Warna C) {
    Color(*P) = C;
}

void SetPlayerWarna(Player *P, TabColor * Palet) {
    // $ Kamus Lokal
    boolean Found = false;
    int i;

    // $ Algoritma
    PrintBukuWarna(*Palet);
    printf("\n");
    printf("Choose your color: ");
    do {
        scanf(" %c", &Color(*P));
        i = 1;
        while (i<=ColNeff(*Palet) && !Found) {
            if (ColElmt(*Palet,i) == Color(*P) && Color(*P)!='_') Found = true;
            i++;
        }
        if (!Found) {
            printf("Please choose an available color from the pallete!\n");
            PrintBukuWarna(*Palet);
            printf("\n");
            printf("Choose your color: ");
        }
    } while (!Found);
    ColElmt(*Palet,i-1) = '_';
}

// $ ************* Special Function: Capture *************
void CaptureBarrage(Player *P, Player *E, address A, Bangunan *B) {
	// $ Kamus Lokal
	List *LP, *LE;
	LP = &ListBan(*P);
	LE = &ListBan(*E);
	Queue *QP, *QE;
	QP = &Skill(*P);
	QE = &Skill(*E);
  	// $ Algoritma
	TentaraAbsolute(B, Info(A));
	DelP(LE, Info(A));
  	InsVPrio(LP, Info(A));
    ResetLevel(B, Info(A));
    
	// ! Deteksi Skill SH
	CheckGetSH(*E, QE);
	// ! Deteksi Skill ET
	if (Name(ElmtBan(*B,Info(A))) == 'F') {
		CheckGetET(QE);
	}
	// ! Deteksi Skill AU
	if (Name(ElmtBan(*B,Info(A))) == 'T') {
		CheckGetAU(*P, QP, *B);
	}
	// ! Deteksi Skill BA
	CheckGetBA(*P, QE);
}

void CaptureAttack(Player *P, Player *E, IdxType A, Bangunan *B) {
	// $ Kamus Lokal
	List *LP, *LE;
	LP = &ListBan(*P);
	LE = &ListBan(*E);
	Queue *QP, *QE;
	QP = &Skill(*P);
	QE = &Skill(*E);

  	// $ Algoritma
	TentaraAbsolute(B, A);
	if (Search(*LE,A) != Nil) {
        DelP(LE, A);
	    // ! Deteksi Skill SH
        CheckGetSH(*E, QE);
        // ! Deteksi Skill ET
        if (Name(ElmtBan(*B,A)) == 'F') {
            CheckGetET(QE);
        }
        // ! Deteksi Skill AU
        if (Name(ElmtBan(*B,A)) == 'T') {
            CheckGetAU(*P, QP, *B);
        }
    }
  	InsVPrio(LP, A);
    ResetLevel(B, A);
    
	// ! Deteksi Skill BA
	CheckGetBA(*P, QE);
}


// $ *************** Skills ***************

// $ ************* Use Skill *************

void InstantUpgrade(Player *P, Bangunan *B) {
    // $ Kamus Lokal
    address A;
    
    // $ Algoritma
    A = First(ListBan(*P));
    while (A != Nil) {
        if (Level(ElmtBan(*B, Info(A))) < 4)
            Level(ElmtBan(*B, Info(A)))++;
        A = Next(A);
    }
}

void Shield(Player *P) {
    Duration(SH(FX(*P))) = 2;
    ActiveSH(SH(FX(*P))) = true;
}

void ExtraTurn(Player *P) {
    ET(FX(*P)) = true;
}

void AttackUp(Player *P) {
    AU(FX(*P)) = true;
}

void CriticalHit(Player *P) {
    CH(FX(*P)) = true;
}

void InstantReinforcement(Player *P, Bangunan *B) {
    // $ Kamus Lokal    
    address A;
    // $ Algoritma
    A = First(ListBan(*P));
    while (Next(A) != Nil){
        Tentara(ElmtBan(*B, Info(A))) += 5;
        A = Next(A);
    }
    Tentara(ElmtBan(*B, Info(A))) += 5;
}

void Barrage(Player *P, Player *E, Bangunan *B) {
    // $ Kamus Lokal
    address A, temp;
    // $ Algoritma
    A = First(ListBan(*E));
    while (A != Nil) {
        Tentara(ElmtBan(*B, Info(A))) -= 10;
        
        if (CanCapture(*B, Info(A))) {
            CaptureBarrage(P, E, A, B);
        }
        A = Next(A);
    }
}

// $ ************* Detect Skill *************

void CheckGetIU(Queue *Q) {
    QAdd(Q, "IU");
}

void CheckGetSH(Player P, Queue *Q) {
    if (NbElmtList(ListBan(P)) == 2) {
        QAdd(Q, "SH");
        printf("\n > The enemy has gained the skill: SH!! < \n\n");
    }
}

void CheckGetET(Queue *Q) {
    QAdd(Q, "ET");
    printf("\n > The enemy has gained the skill: ET!! < \n");
}

void CheckGetAU(Player P, Queue *Q, Bangunan databuild) {
    // $ KAMUS LOKAL
    address Adr;
    int totalT;
    List L = ListBan(P);

    // $ ALGORITMA
    if (!IsEmptyList(L)) {
        Adr = First(L);
        totalT = 0;
        while (Adr != Nil) {
            if (Name(ElmtBan(databuild,Info(Adr))) == 'T')
            totalT++;
            Adr = Next(Adr);
        }
    }
    if (totalT == 3) {
        QAdd(Q, "AU");
        printf("\n > You have gained the skill: AU!! < \n\n");
    }
}


void CheckGetCH(Queue *Q) {
    QAdd(Q, "CH");
    printf("\n > You have gained the skill : CH!! < \n\n");
}

void CheckGetIR(Player *P, Bangunan *B) {
    // Kamus Lokal
    boolean get;
    address A;
    // Algoritma
    get = true;
    A = First(ListBan(*P));
    while (Next(A) != Nil && get) {
        if (Level(ElmtBan(*B, Info(A))) != 4){
            get = false;
        }
        A = Next(A);
    }
    if (Level(ElmtBan(*B, Info(A))) != 4){
        get = false;
    }

    if (get == true){
        QAdd(&Skill(*P), "IR");
        printf("\n > You have gained the skill : IR!! < \n\n");
    }
}

void CheckGetBA(Player P, Queue *Q) {
    if (NbElmtList(ListBan(P)) == 10) {
        QAdd(Q, "BA");
        printf("\n > The enemy has gained the skill: BA!! < \n");
    }
}

// $ ******* COPY FUNCTION *******
Player CopyPlayer(Player P) {
    Player ret;
    CreatePlayer(&ret);
    ListBan(ret) = CopyList(ListBan(P));
    Skill(ret) = CopyQueue(Skill(P));
    Color(ret) = Color(P);
    AU(FX(ret)) = AU(FX(P));
    CH(FX(ret)) = CH(FX(P));
    ActiveSH(SH(FX(ret))) = ActiveSH(SH(FX(P)));
    Duration(SH(FX(ret))) = Duration(SH(FX(P)));
    ET(FX(ret)) = ET(FX(P));
    return ret;
}

// $ ******* MAP PRINTING FUNCTION ********
void PrintMap(MATRIKS M, Bangunan B, Player One, Player Two) {
    int i, j;
    for (i = 1; i <= (MaxBrs(M) + 2); i++) {
        for (j = 1; j < (MaxKol(M) + 3); j++) {
            //printf("%d%d",i,j);
            if (i == 1) {
                printf("+");
                if(j == (MaxKol(M) + 2)) {
                    printf("++\n");
                }
            }
            else if (i == (MaxBrs(M) + 2)) {
                printf("+");
                if(j == (MaxKol(M) + 2)) printf("++\n");
            }
            else if (j == 1) {
                printf("+ ");
            }
            else if (j == (MaxKol(M) + 2)) {
                printf(" +\n");
            }
            else if ((Elmt(M,(i-1),(j-1))) == 0) {
                printf(" ");
            }
            else {
                ElType Mem = Elmt(M,(i-1),(j-1));
                char C = Name(ElmtBan(B,Mem));
                if (Search(ListBan(One), Mem) != Nil) {
                    print_warna(Color(One), C);
                }
                else if (Search(ListBan(Two), Mem) != Nil) {
                    print_warna(Color(Two), C);
                }
                else {
                    print_warna('Y', C);
                }
            }
        }
    }
    printf("\n");
}
