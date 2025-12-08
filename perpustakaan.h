#ifndef PERPUSTAKAAN_INCLUDED
#define PERPUSTAKAAN_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

typedef struct elemenPeminjam *adrPeminjam;
typedef struct peminjam infotypePeminjam;

struct peminjam{
    string idPeminjam;
    string nama;
    string alamat;
    string telpon;
    int jumlahBukuYangDipinjam;
};

struct elemenPeminjam{
    infotypePeminjam info;
    adrPeminjam next;

};

struct listPeminjam{
    adrPeminjam first;
};


// === DAFTAR PROSEDUR & FUNGSI ===
void createListPeminjam(listPeminjam &LP);
adrPeminjam createNodePeminjam(infotypePeminjam X);
void insertLastPeminjam(listPeminjam &LP, adrPeminjam P);
void insertFirstPeminjam(listPeminjam &LP, adrPeminjam P);
void deletePeminjam(listPeminjam &LP, string idPeminjam);
void showAllPeminjam(listPeminjam LP);


#endif
