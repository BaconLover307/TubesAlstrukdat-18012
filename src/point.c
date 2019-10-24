/* Program      : point.c */
/* Deskripsi    : Definisi ADT Point */

#include "point.h"
#include <stdio.h>
#include <math.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
    // KAMUS LOKAL
    POINT P;
    // ALGORITMA
    P.X = X;
    P.Y = Y;
    return(P);
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    // KAMUS LOKAL
    float x1, y1;
    // ALGORITMA
    scanf("%f %f", &x1, &y1);
    *P = MakePOINT(x1,y1);
}

void TulisPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    // ALGORITMA
    printf("(%.2f, %.2f)",P.X,P.Y);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    // ALGORITMA
    if(P1.X == P2.X && P1.Y == P2.Y)
    {return(true);} else {return(false);}
}

boolean NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    // ALGORITMA
    if(P1.X != P2.X || P1.Y != P2.Y)
    {return(true);} else {return(false);}
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
    // ALGORITMA
    if(P.X == 0 && P.Y == 0)
    {return(true);} else {return(false);}
}

boolean IsOnSbX (POINT P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    // ALGORITMA
    if(P.Y == 0)
    {return(true);} else {return(false);}
}

boolean IsOnSbY (POINT P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    // ALGORITMA
    if(P.X == 0)
    {return(true);} else {return(false);}
}

int Kuadran (POINT P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    // KAMUS LOKAL
    int kuad;
    // ALGORITMA
    if(P.X > 0 && P.Y > 0) {kuad = 1;}
    else if(P.X < 0 && P.Y > 0) {kuad = 2;}
    else if(P.X < 0 && P.Y < 0) {kuad = 3;}
    else if(P.X > 0 && P.Y < 0) {kuad = 4;}
    return(kuad);
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P) {
/* Mengirim salinan P dengan absis ditambah satu */
    // ALGORITMA
    P.X += 1;
    return(P);
}

POINT NextY (POINT P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
    // ALGORITMA
    P.Y += 1;
    return(P);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    // ALGORITMA
    P.X += deltaX;
    P.Y += deltaY;
    return(P);
}

POINT MirrorOf (POINT P, boolean SbX) {
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    // ALGORITMA
    if (SbX) {
        P.Y *= -1;
    } else { // SbX == false
        P.X *= -1;
    }
    return(P);
}

float Jarak0 (POINT P) {
/* Menghitung jarak P ke (0,0) */
    // ALGORITMA
    return(sqrt(P.X*P.X + P.Y*P.Y));
}

float Panjang (POINT P1, POINT P2) {
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
    // ALGORITMA
    return(sqrt((P1.X-P2.X)*(P1.X-P2.X) + (P1.Y-P2.Y)*(P1.Y-P2.Y)));
}

void Geser (POINT *P, float deltaX, float deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    // ALGORITMA
    PlusDelta(*P,deltaX,deltaY);
}

void GeserKeSbX (POINT *P) {
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    // ALGORITMA
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P) {
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    // ALGORITMA
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX) {
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    // ALGORITMA
    *P=MirrorOf(*P,SbX);
}

void Putar (POINT *P, float Sudut) {
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
    // KAMUS LOKAL
    float x3 = Absis((*P));
    float y3 = Ordinat((*P));
    const float pi = 3.1415926535897932384626433832795028841971693993751058209;
    float radian = pi*Sudut/ 180;
    // ALGORITMA
    (*P).X = cos(radian)*x3 + sin(radian)*y3; 
    (*P).Y = -sin(radian)*x3 + cos(radian)*y3; 
}