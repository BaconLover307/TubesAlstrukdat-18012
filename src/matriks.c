/* Program      : matriks.c */
/* Deskripsi    : Definisi ADT Matriks */

/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) {
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j) {
    return((i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M) {
    return(BrsMin);
}
/* Mengirimkan indeks baris terkecil M */

indeks GetFirstIdxKol (MATRIKS M) {
    return(KolMin);
}
/* Mengirimkan indeks kolom terkecil M */

indeks GetLastIdxBrs (MATRIKS M) {
    return(NBrsEff(M));
}
/* Mengirimkan indeks baris terbesar M */

indeks GetLastIdxKol (MATRIKS M) {
    return(NKolEff(M));
}
/* Mengirimkan indeks kolom terbesar M */

boolean IsIdxEff (MATRIKS M, indeks i, indeks j) {
    return((i>=BrsMin) && (i<=GetLastIdxBrs(M)) && (j>=KolMin) && (j<=GetLastIdxKol(M)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

ElType GetElmtDiagonal (MATRIKS M, indeks i) {
    return(Elmt(M,i,i));
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl) {
    // KAMUS LOKAL
    int iIn = GetLastIdxBrs(MIn);
    int jIn = GetLastIdxKol(MIn);
    int i,j;
    // ALGORITMA
    MakeMATRIKS(iIn,jIn,&(*MHsl));
    for (i=1;i<=iIn;i++) {
        for (j=1;j<=jIn;j++) {
            Elmt(*MHsl, i, j) = Elmt(MIn,i,j);
        }
    }
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK) {
     // KAMUS LOKAL
    int i,j;
    // ALGORITMA
    MakeMATRIKS(NB,NK,&(*M));
    if (NB>1) {
        for (i=1;i<NB;i++) {
            if (NK>1) {
                for (j=1;j<NK;j++) {
                    scanf("%d ",&Elmt(*M,i,j));
                }
            }
            scanf("%d",&Elmt(*M,i,NK));
            }
    }
    if (NK>1) {
        for (j=1;j<NK;j++) {
            scanf("%d ",&Elmt(*M,NB,j));
        }
    }
    scanf("%d",&Elmt(*M,NB,NK));
}
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/

void TulisMATRIKS (MATRIKS M) {
    // KAMUS LOKAL
    int i,j;
    int LastBrs = GetLastIdxBrs(M);
    int LastKol = GetLastIdxKol(M);
    // ALGORITMA
    for (i=1;i<LastBrs;i++) {
        if (LastKol>1) {
            for (j=1;j<LastKol;j++) {
                printf("%d ",Elmt(M,i,j));
            }
        }
        printf("%d",Elmt(M,i,LastKol));
        printf("\n");
        }
    if (LastKol>1) {
        for (j=1;j<LastKol;j++) {
            printf("%d ",Elmt(M,LastBrs,j));
        }
    }
    printf("%d",Elmt(M,LastBrs,LastKol));
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2) {
    // KAMUS LOKAL
    MATRIKS MHsl;
    int i,j;
    int LastBrs = GetLastIdxBrs(M1);
    int LastKol = GetLastIdxKol(M1);
    // ALGORITMA
    MakeMATRIKS(LastBrs,LastKol,&MHsl);
    for (i=1;i<=LastBrs;i++) {
        for (j=1;j<=LastKol;j++) {
            Elmt(MHsl,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }
    return(MHsl);
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2) {
// KAMUS LOKAL
    MATRIKS MHsl;
    int i,j;
    int LastBrs = GetLastIdxBrs(M1);
    int LastKol = GetLastIdxKol(M1);
    // ALGORITMA
    MakeMATRIKS(LastBrs,LastKol,&MHsl);
    for (i=1;i<=LastBrs;i++) {
        for (j=1;j<=LastKol;j++) {
            Elmt(MHsl,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }
    return(MHsl);
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2) {
// KAMUS LOKAL
    MATRIKS MHsl;
    int i,j,k;
    int LastBrs = GetLastIdxBrs(M1);
    int LastKol = GetLastIdxKol(M2);
    int Mid = GetLastIdxKol(M1);
    int temp = 0;
// ALGORITMA
    MakeMATRIKS(LastBrs,LastKol,&MHsl);
    for (i=1;i<=LastBrs;i++) {
        for (j=1;j<=LastKol;j++) {
            for (k=1;k<=Mid;k++) {temp += Elmt(M1,i,k) * Elmt(M2,k,j);}
            Elmt(MHsl,i,j) = temp;
            temp = 0;
        }
    }
    return(MHsl);
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */

MATRIKS KaliKons (MATRIKS M, ElType X) {
// KAMUS LOKAL
    MATRIKS MHsl;
    int i,j;
    int LastBrs = GetLastIdxBrs(M);
    int LastKol = GetLastIdxKol(M);
// ALGORITMA
    MakeMATRIKS(LastBrs,LastKol,&MHsl);
    for (i=1;i<=LastBrs;i++) {
        for (j=1;j<=LastKol;j++) {
            Elmt(MHsl,i,j) = Elmt(M,i,j) * X;
        }
    }
    return(MHsl);
}
/* Mengirim hasil perkalian setiap elemen M dengan X */

void PKaliKons (MATRIKS * M, ElType K) {
// KAMUS LOKAL
    int i, j;
    int LastBrs = GetLastIdxBrs(*M);
    int LastKol = GetLastIdxKol(*M);
// ALGORITMA
    for (i = 1; i <= LastBrs; i++)
    {
        for (j = 1; j <= LastKol; j++)
        {
            Elmt(*M, i, j) = Elmt(*M, i, j) * K;
        }
    }
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2) {
    // KAMUS LOKAL
    int i = GetFirstIdxBrs(M1);
    int j = GetFirstIdxKol(M1);
    int LastBrs = GetLastIdxBrs(M1);
    int LastKol = GetLastIdxKol(M1);
    boolean eq = true;
    // ALGORITMA
    if (EQSize(M1,M2)) {
        while ((i<=LastBrs) && (eq == true)) {
            while ((j<=LastKol) && (eq == true)) {
                if (Elmt(M1,i,j) != Elmt(M2,i,j)) {eq = false;}
                j++;
            }
            i++;
            j = GetFirstIdxBrs(M1);
        }
    } else {eq = false;}
    return(eq);
}

/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2) {
    // KAMUS LOKAL
    int i = GetFirstIdxBrs(M1);
    int j = GetFirstIdxKol(M1);
    int LastBrs = GetLastIdxBrs(M1);
    int LastKol = GetLastIdxKol(M1);
    boolean neq = false;
    // ALGORITMA
    if (EQSize(M1,M2)) {
        while ((i<=LastBrs) && (neq == false)) {
            while ((j<=LastKol) && (neq == false)) {
                if (Elmt(M1,i,j) != Elmt(M2,i,j)) {neq = true;}
                j++;
            }
            i++;
            j = GetFirstIdxBrs(M1);
        }
    } else {neq = true;}
    return(neq);
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2) {
    return((GetLastIdxKol(M1)==GetLastIdxKol(M2)) && (GetLastIdxBrs(M1)==GetLastIdxBrs(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M) {
    return(GetLastIdxBrs(M)*GetLastIdxKol(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M) {
    return(GetLastIdxBrs(M) == GetLastIdxKol(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */

boolean IsSimetri (MATRIKS M) {
// KAMUS LOKAL
    int i = GetFirstIdxBrs(M);
    int j = GetFirstIdxKol(M);
    int LastBrs = GetLastIdxBrs(M);
    int LastKol = GetLastIdxKol(M);
    boolean sym = true;
// ALGORITMA
    if (IsBujurSangkar(M)) {
        while ((i<=LastBrs) && (sym == true)) {
            while ((j<=LastKol) && (sym == true)) {
                if (Elmt(M,i,j) != Elmt(M,j,i)) {sym = false;}
                j++;
            }
            i++;
            j = GetFirstIdxBrs(M);
        }
    } else {sym = false;}
    return(sym);
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */

boolean IsSatuan (MATRIKS M) {
// KAMUS LOKAL
    int i = GetFirstIdxBrs(M);
    int j = GetFirstIdxKol(M);
    int LastBrs = GetLastIdxBrs(M);
    int LastKol = GetLastIdxKol(M);
    boolean id = true;
// ALGORITMA
    if (IsBujurSangkar(M)) {
        for (i=GetFirstIdxBrs(M);i<=LastBrs;i++) {
            for (j=GetFirstIdxKol(M);j<=LastKol;j++) {
                if (i==j) {
                    if (Elmt(M,i,j) != 1) {id = false;}
                } else {
                    if (Elmt(M,i,j) != 0) {id = false;}
                }
            }
        }
    } else {id = false;}
    return(id);
}

/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean IsSparse (MATRIKS M) {
// KAMUS LOKAL
    int i,j;
    int LastBrs = GetLastIdxBrs(M);
    int LastKol = GetLastIdxKol(M);
    int count = 0;
// ALGORITMA
    for (i=GetFirstIdxBrs(M);i<=LastBrs;i++) {
        for (j=GetFirstIdxKol(M);j<=LastKol;j++) {
            if (Elmt(M,i,j) != 0) {count += 1;}
        }
    }
    return((20*count <= NBElmt(M)));
}
/* Mengirimkan true jika M adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */

MATRIKS Inverse1 (MATRIKS M) {
// KAMUS LOKAL
    int i,j;
    int LastBrs = GetLastIdxBrs(M);
    int LastKol = GetLastIdxKol(M);
// ALGORITMA
    for (i=GetFirstIdxBrs(M);i<=LastBrs;i++) {
        for (j=GetFirstIdxKol(M);j<=LastKol;j++) {
            Elmt(M,i,j) *= -1;
        }
    }
    return(M);
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */

/* ********** FUNGSI ANTARA DETERMINAN ********** */
MATRIKS DelBrsKol(MATRIKS M, indeks Brs, indeks Kol) {
// KAMUS LOKAL
    MATRIKS MHsl;
    indeks i,j;
    indeks iHsl = 0;
    indeks jHsl = 0;
// ALGORITMA
    MakeMATRIKS((GetLastIdxBrs(M)-1),(GetLastIdxKol(M)-1),&MHsl);
    // Isi Matriks
    for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++) {
        if (i != Brs) {
            iHsl++;
            for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++) {
                if (j != Kol) {
                    jHsl++;
                    Elmt(MHsl,iHsl,jHsl) = Elmt(M,i,j);
                }
            }
            jHsl = 0;
        }
    }
    return MHsl;
}
/* I.S. M terdefinisi */
/* F.S. M berkurang 1 baris dan 1 kolom, sesuai baris dan kolom yang dipilih untuk dibuang */

float Determinan (MATRIKS M) {
// KAMUS LOKAL
    float det = 0;
    indeks j;
// ALGORITMA
    if (NBElmt(M)==1) {
        det = NBElmt(M);
    } else if (NBElmt(M)==4) {
        det = ((Elmt(M, 1, 1) * Elmt(M, 2, 2)) - (Elmt(M, 1, 2)*Elmt(M,2,1)));
    } else {
        for (j=(GetFirstIdxKol(M)); j<=GetLastIdxKol(M); j++) {
            if (j%2 == 1) {
                det += Elmt(M,1,j) * Determinan(DelBrsKol(M,1,j));
            } else {
                det += Elmt(M,1,j) * (-1) * Determinan(DelBrsKol(M,1,j));
            }
        }
    }
    return(det);
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */

void PInverse1 (MATRIKS * M) {
// KAMUS LOKAL
    int i,j;
    int LastBrs = GetLastIdxBrs(*M);
    int LastKol = GetLastIdxKol(*M);
// ALGORITMA
    for (i=GetFirstIdxBrs(*M);i<=LastBrs;i++) {
        for (j=GetFirstIdxKol(*M);j<=LastKol;j++) {
            Elmt(*M,i,j) *= -1;
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

void Transpose (MATRIKS * M) {
// KAMUS LOKAL
    int i,j;
    int LastBrs = GetLastIdxBrs(*M);
    int LastKol = GetLastIdxKol(*M);
    MATRIKS tempM;
// ALGORITMA
    CopyMATRIKS(*M,&tempM);
    for (i=GetFirstIdxBrs(*M);i<=LastBrs;i++) {
        for (j=GetFirstIdxKol(*M);j<=LastKol;j++) {
            Elmt(*M,j,i) = Elmt(tempM,i,j);
        }
    }
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
