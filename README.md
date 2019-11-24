# Tugas Besar Alstrukdat - Avatar World War
## Kelas K3 Kelompok 8

Program ini adalah contoh penerapan ADT dalam pembuatan sebuah text based-game.

## Derivables
* src: folder-folder modul berisi script C, file konfigurasi, program utama, dan assets
* README.MD

## Instalasi Program

Program ini dibuat menggunakan bahasa pemrograman C oleh karena itu dibutuhkan C compiler GCC versi 5.4.0 atau lebih tinggi. Compiler dapat diunduh melalui https://sourceforge.net/projects/tdm-gcc/files/
Setelah compiler GCC diinstall, lakukan clone pada repository ini, atau download dalam file .zip dan extract ke folder yang diinginkan.

### Cara Kompilasi Program

Sebelum dijalankan, program harus di-compile terlebih dahulu. Untuk meng-compiler, buka terminal dari directory src dan ketik instruksi di bawah ini.

```
gcc -o main MainProgram.c array//array.c command//command.c graph//graph.c listlinier//listlinier.c load//load.c matriks//matriks.c pcolor//pcolor.c player//player.c point//point.c queue//queue.c save//save.c stackt//stackt.c mesinkar_config//mesinkar_config.c mesinkata_config//mesinkata_config.c
```
Instruksi di atas akan membuat sebuah file executable bernama "main", jika namanya ingin diganti, kata "main" di sebelah kanan "-o" pada instruksi di atas dapat diubah sesuai dengan keinginan. 

## Cara Menjalankan Program

Setelah file MainProgram berhasil dicompile, maka program dapat dijalankan. Untuk menjalankan programnya, bukalah terminal dari directory src dan silakan jalankan programnya. Berikut adalah instruksi untuk menjalankan programnya :

```
./main
```
Mengacu pada subjudul sebelumnya, nama "main" dapat disesuaikan dengan nama file executable hasil compiler.

Catatan: Program ini akan berjalan lebih optimal dalam terminal bash atau powershell, tidak dalam terminal cmd

### Cara Memainkan Game

Setelah program dijalankan, akan muncul sebuah tampilan menu utama. Untuk memahami cara bermain, ketik "TUTORIAL" untuk membuka tampilan cara bermain. Untuk langsung bermain, ketik "PLAY", dan pilih apakah ingin me-load file yang pernah disimpan atau tidak.

## Kontributor
Program ini dibuat untuk memenuhi salah satu Tugas Besar IF2110 Algoritma dan Struktur Data Teknik Informatika ITB. Adapun pembuat dari program ini adalah :
[ Kelas K3, Kelompok 08 ]
* Muhammad Hasan           - 13518012
* Anna Elvira Hartoyo      - 13518045
* Daniel Riyanto           - 13518075
* Faris Muhammad Kautsar   - 13518105
* Gregorius Jovan Kresnadi - 13518135

NOTE : Program stable in Windows and Linux, best used bash terminal

https://github.com/BaconLover307/TubesAlstrukdat-18012