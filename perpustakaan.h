#ifndef PERPUSTAKAAN_INCLUDED
#define PERPUSTAKAAN_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

typedef struct elemenBuku *adrBuku;
typedef struct buku infotypeBuku;

struct buku{
    string idBuku;
    string judulBuku;
    string tahunTerbit;
    float rating;
};

struct elemenBuku{
    infotypeBuku info;
    adrBuku next;
};

struct listBuku{
    adrBuku first;
};

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
void createListBuku(listBuku &LB);
adrBuku createNodeBuku(infotypeBuku Z);
void insertFirstBuku(listBuku &LB, adrBuku P);
void insertLastBuku(listBuku &LB, adrBuku P);
void deleteBuku(listBuku &LP, string idBuku);
void showAllBuku(listBuku LB);

void createListPeminjam(listPeminjam &LP);
adrPeminjam createNodePeminjam(infotypePeminjam X);
void insertLastPeminjam(listPeminjam &LP, adrPeminjam P);
void insertFirstPeminjam(listPeminjam &LP, adrPeminjam P);
void deletePeminjam(listPeminjam &LP, string idPeminjam);
void showAllPeminjam(listPeminjam LP);


#endif
