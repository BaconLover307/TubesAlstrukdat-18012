/* Program      : array.c */
/* Deskripsi    : Definisi ADT Array */

#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T) {
    Neff(*T)=0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T) {
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T) {
    return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T) {
    return IdxMin;
}

IdxType GetLastIdx (TabInt T) {
    return (IdxMin + T.Neff-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i) {
    return ((i >= IdxMin) && (i<=IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i) {
    return ((i>=GetFirstIdx(T)) & (i<=GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T) {
    return (NbElmt(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T) {
    return (NbElmt(T)==MaxNbEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T) {
    // KAMUS LOKAL
    int n,i;
    boolean valid = false;
    // ALGORITMA
    do {
        scanf("%d",&n);
        if (n>=0 && n<=IdxMax) {valid = true;}
    } while (valid==false);

    if (n==0) {MakeEmpty(T);}
    else {
        (*T).Neff = n;
        for (i=1;i<=n;i++) {
            scanf("%d",&(*T).TI[i]);
        }
    }
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */

void BacaIsiTab (TabInt * T) {
    // KAMUS LOKAL
    int i = 0; // counter
    int isi;
    // ALGORITMA
        scanf("%d",&isi);
    while ((isi!=-9999) && (GetFirstIdx(*T)+i <= MaxNbEl(*T))) {
        (*T).TI[GetFirstIdx(*T)+i] = isi;
        i++;
        scanf("%d",&isi);
    }
    (*T).Neff = i;
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */

void TulisIsi (TabInt T) {
    // KAMUS LOKAL
    int i; //counter
    // ALGORITMA
    if (T.Neff == 0) {
        printf("Tabel kosong\n");
    } else {
        for (i = IdxMin; i <= NbElmt(T); i++)
        {printf("[%d]%d\n", i,T.TI[i]);}
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/

void TulisIsiTab (TabInt T) {
    // KAMUS LOKAL
    int i = 1; //counter
    // ALGORITMA
    printf("[");
    while (i<=T.Neff) {
        printf("%d",T.TI[i]);
        if (i!=T.Neff) {printf(",");}
        i+=1;
    }
    printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2) {
    // KAMUS LOKAL
    TabInt Thasil;
    int i; //counter
    // ALGORITMA
    for (i=1;i<=T1.Neff;i++) {
        Thasil.TI[i] = T1.TI[i] + T2.TI[i];
    }
    Thasil.Neff = T1.Neff;
    return Thasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */

TabInt MinusTab (TabInt T1, TabInt T2) {
    // KAMUS LOKAL
    TabInt Thasil;
    int i; //counter
    // ALGORITMA
    for (i=1;i<=T1.Neff;i++) {
        Thasil.TI[i] = T1.TI[i] - T2.TI[i];
    }
    Thasil.Neff = T1.Neff;
    return Thasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
TabInt KaliTab (TabInt T1, TabInt T2) {
    // KAMUS LOKAL
    TabInt Thasil;
    int i; //counter
    // ALGORITMA
    for (i = 1; i <= T1.Neff; i++) {
        Thasil.TI[i] = T1.TI[i] * T2.TI[i];
    }
    Thasil.Neff = T1.Neff;
    return Thasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c) {
    // KAMUS LOKAL
    TabInt Thasil;
    int i; //counter
    // ALGORITMA
    for (i = 1; i <= Tin.Neff; i++) {
        Thasil.TI[i] = Tin.TI[i] * c;
    }
    Thasil.Neff = Tin.Neff;
    return Thasil;
}
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2) {
    // KAMUS LOKAL
    IdxType FirstIdx = GetFirstIdx(T1);
    IdxType LastIdx = GetLastIdx(T1);
    int i; //counter
    boolean valid = false;
    // ALGORITMA
    if ((T1.Neff == T2.Neff) && (T1.Neff == 0)) {
        return true;
    } else if (T1.Neff == T2.Neff) {
        for (i=FirstIdx;i<=LastIdx;i++) {
            if (Elmt(T1,i) != Elmt(T2,i)) {
                return false;
                break;
            } else if (i==LastIdx) {
                return true;
            }
        }
    } else {return false;}
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */

boolean IsLess (TabInt T1, TabInt T2) {
    // KAMUS LOKAL
    IdxType MaxIdx, i, j;
    boolean less = true;
    i = 0;
    // ALGORITMA
    if (Neff(T1)<=Neff(T2)) {
        j = Neff(T1); 
    } else { j = Neff(T2); }
    while ((i<j) && (Elmt(T1,i) <=  Elmt(T2,i))) {
        i++;
        if (Elmt(T1,i) > Elmt(T2,i)) {
            less = false;
        }
        if ((i == j) && (less == true) && Elmt(T1, i) == Elmt(T2, i))
        {
            less = (Neff(T1)<Neff(T2));
        }
    }
    return less;
}
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X) {
    // KAMUS LOKAL
    IdxType i=GetFirstIdx(T);
    IdxType IdxFound;
    // ALGORITMA
    if (IsEmpty(T)) {IdxFound = IdxUndef;} else {
      for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++) {
            if (Elmt(T,i)==X) {
                IdxFound=i;
                break;
            } else if (i==GetLastIdx(T)) {
                IdxFound=IdxUndef;
            }
        }
    }
    return IdxFound;
}

/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */

IdxType Search2 (TabInt T, ElType X) {
    // KAMUS LOKAL
    boolean Found = false;
    IdxType i=GetFirstIdx(T);
    IdxType IdxFound;
    // ALGORITMA
    if (IsEmpty(T)) {IdxFound = IdxUndef;} else{
        while (!Found) {
            if (Elmt(T,i)==X) {
                Found = true;
                IdxFound = i;
            } else if (i==GetLastIdx(T)) {
                IdxFound = IdxUndef;
                break;
            } else {
                i++;
            }
        }
    }
    return IdxFound;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

boolean SearchB (TabInt T, ElType X) {
    // KAMUS LOKAL
    boolean Found;
    IdxType i=GetFirstIdx(T);
    // ALGORITMA
    if (IsEmpty(T)) {Found = false;} else {
        while (!Found) {
            if (Elmt(T, i) == X) {
                Found = true;
            }
            else if (i == GetLastIdx(T)) {
                break;
            }
            else {i++;}
        }
    }
    return Found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */

boolean SearchSentinel (TabInt T, ElType X) {
    // KAMUS LOKAL
    IdxType i = GetLastIdx(T); // Pencarian dimulai dari index terahir
    boolean Found = false;
    // ALGORITMA
    Elmt(T,0)=X;        // Inisialisasi
    if (!IsEmpty(T)) {
        while (Elmt(T,i)!=X) {
            i--;
        }
        if (i>0) {
            Found = true;
        }
    }
    return Found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T) {
    // KAMUS LOKAL
    ElType Max;
    IdxType i;
    // ALGORITMA
    Max = T.TI[1];
    if (NbElmt(T)>1) {
        for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++) {
            if (Max < Elmt(T,i)) {Max = Elmt(T,i);}
        }
    }
    return Max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabInt T) {
    // KAMUS LOKAL
    ElType Min;
    IdxType i;
    // ALGORITMA
    Min = T.TI[1];
    if (NbElmt(T)>1) {
        for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++) {
            if (Min > Elmt(T,i)) {Min = Elmt(T,i);}
        }
    }
    return Min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T) {
    // KAMUS LOKAL
    ElType Max;
    IdxType i,iMax;
    // ALGORITMA
    Max = T.TI[1];
    iMax = 1;
    if (NbElmt(T)>1) {
        for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++) {
            if (Max < Elmt(T,i)) {
                Max = Elmt(T,i);
                iMax = i;
            }
        }
    }
    return iMax;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */

IdxType IdxMinTab (TabInt T) {
    // KAMUS LOKAL
    ElType Min;
    IdxType i,iMin;
    // ALGORITMA
    Min = T.TI[1];
    iMin = 1;
    if (NbElmt(T)>1) {
        for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++) {
            if (Min > Elmt(T,i)) {
                Min = Elmt(T,i);
                iMin = i;
            }
        }
    }
    return iMin;
}
/* PrekonMini : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout) {
    // KAMUS LOKAL
    IdxType i;
    ElType isi;
    // ALGORITMA
    if(!IsEmpty(Tin)) {
        for (i=GetFirstIdx(Tin); i<=GetLastIdx(Tin); i++) {
            Elmt(*Tout,i) = Elmt(Tin,i);
        }
    }
    (*Tout).Neff = Tin.Neff;
}
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */

TabInt InverseTab (TabInt T) {
    // KAMUS LOKAL
    TabInt TInv;
    IdxType i;
    IdxType j = GetFirstIdx(T);
    // ALGORITMA
    if (!IsEmpty(T)) {
        for (i=GetLastIdx(T);i>=GetFirstIdx(T);i--) {
            Elmt(TInv,j) = Elmt(T,i);
            j++;
        }
    }
    TInv.Neff = T.Neff;
    return TInv;
}
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */

boolean IsSimetris (TabInt T) {
    // KAMUS LOKAL
    TabInt Temp = InverseTab(T); // Jika Tabel yang diinverse masih sama dengan tabel awal, maka simetris
    // ALGORITMA
    return IsEQ(T,Temp);
}
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T) {
    // KAMUS LOKAL
    IdxType i,IMax; // Index untuk transversal
    IdxType Pass;   // Tahapan pengurutan
    ElType Temp;    // Memorasi untu pertukaran harga
    IdxType FirstIdx = GetFirstIdx(*T);
    IdxType LastIdx = GetLastIdx(*T);

    // ALGORITMA
    if ((*T).Neff > 1) {
        for (Pass=FirstIdx;Pass<LastIdx;Pass++) {
            IMax = Pass;
            for (i = Pass+1; i<=LastIdx; i++) {
                if (Elmt(*T,IMax) < Elmt(*T,i)) {
                    IMax = i;
                }
            }
            Temp = Elmt(*T, Pass);
            Elmt(*T, Pass) = Elmt(*T, IMax);
            Elmt(*T, IMax) = Temp;
        }
    }    
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */

void InsSortAsc (TabInt * T) {
    // KAMUS LOKAL
    IdxType i;      // Index untuk transversal
    IdxType Pass;   // Tahapan pengurutuan
    ElType Temp;    // Penampung nilai sementara
    IdxType FirstIdx = GetFirstIdx(*T);
    IdxType LastIdx = GetLastIdx(*T);
    // ALGORITMA
    if ((*T).Neff > 1) {        // T[1] adalah terurut
        for (Pass=FirstIdx+1; Pass<=LastIdx; Pass++) {
            Temp = Elmt((*T),Pass);
            i = Pass-1;
            while ((Temp < Elmt((*T),i)) && (i>1)) {
                Elmt((*T),(i+1)) = Elmt((*T),i);
                i--;
            }
            if (Temp>Elmt((*T),i)) {
                Elmt((*T),(i+1)) = Temp;
            } else {
                Elmt((*T), (i + 1)) = Elmt((*T), i);
                Elmt((*T), i) = Temp;
            }
        }
    }
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X) {
    // ALGORITMA
    Elmt(*T,(*T).Neff+1) = X;
    (*T).Neff++;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void AddEli (TabInt * T, ElType X, IdxType i) {
    // KAMUS LOKAL
    ElType Temp;
    IdxType idxadd;
    // ALGORITMA
    for (idxadd=i;idxadd<=(*T).Neff;idxadd++) {
        Temp = Elmt(*T,idxadd);
        Elmt(*T,idxadd) = X;
        X = Temp;
    }
    AddAsLastEl(T,X);
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X) {
    // ALGORITMA
    (*X) = Elmt(*T,GetLastIdx(*T));
    (*T).Neff--;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

void DelEli (TabInt * T, IdxType i, ElType * X) {
    // KAMUS LOKAL
    IdxType idxdel, j;
    // ALGORITMA
    (*X) = Elmt(*T,i);
    if (GetFirstIdx(*T) < GetLastIdx(*T)) {
        for (j=i;j<GetLastIdx(*T);j++) {
            Elmt((*T),j) = Elmt((*T),j+1);
        }
    }
    (*T).Neff--;
}

/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X) {
    // ALGORITMA
    if (!IsFull(*T)) {
        if (SearchSentinel((*T),X)) {
            printf("nilai sudah ada\n");
        } else {
            AddAsLastEl(T,X);
        }
    }
}
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X) {
    // ALGORITMA
    return Search1(T,X);
}
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */

ElType MaxUrut (TabInt T) {
    // ALGORITMA
    return(Elmt(T,GetLastIdx(T)));
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */

ElType MinUrut (TabInt T) {
    // ALGORITMA
    return(Elmt(T,GetFirstIdx(T)));
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min) {
    // ALGORITMA
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

void Add1Urut (TabInt * T, ElType X) {
    // ALGORITMA
    AddAsLastEl(T,X);
    InsSortAsc(T);
}
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */

void Del1Urut (TabInt * T, ElType X) {
    // KAMUS LOKAL
    IdxType idx = Search1(*T,X);
    ElType val;
    // ALGORITMA
    if(idx!=IdxUndef){
        DelEli(T,idx,&val);
    }
}
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
