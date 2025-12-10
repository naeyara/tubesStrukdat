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
    int tahunTerbit;
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

typedef struct elemenRelasi *adrRelasi;

struct elemenRelasi{
    elemenBuku *buku; //Menyimpan pointer ke buku
    elemenPeminjam *peminjam; //Menyimpan pointer ke buku
    elemenRelasi *next;
    float nilai = 0;
};

struct listRelasi{
    elemenRelasi *first;
};


// === DAFTAR PROSEDUR & FUNGSI ===
void createListBuku(listBuku &LB);
adrBuku createNodeBuku(infotypeBuku Z);
void insertFirstBuku(listBuku &LB, adrBuku P);
void insertLastBuku(listBuku &LB, adrBuku P);
void deleteBuku(listBuku &LP, string idBuku);
void showAllBuku(listBuku LB);
adrBuku searchBuku(listBuku LB, string idBuku);


void createListPeminjam(listPeminjam &LP);
adrPeminjam createNodePeminjam(infotypePeminjam X);
void insertLastPeminjam(listPeminjam &LP, adrPeminjam P);
void insertFirstPeminjam(listPeminjam &LP, adrPeminjam P);
void deletePeminjam(listPeminjam &LP, string idPeminjam);
void showAllPeminjam(listPeminjam LP);
adrPeminjam searchPeminjam(listPeminjam LP, string idPeminjam);
void inputNPeminjam(listPeminjam &LP);

void createListRelasi(listRelasi &LR);
elemenRelasi* createNodeRelasi(adrBuku B, adrPeminjam P);
void insertRelasi (listRelasi &LR, adrRelasi R);
void showAllRelasiBuku(listRelasi LR, string idBuku);
void dataRelasiDummy(listRelasi &LR, listBuku LB, listPeminjam LP);

int countRelasiBuku(listRelasi LR, string idBuku);
void inputNPeminjam(listPeminjam &LP);
void inputNBuku(listBuku &LB);
void aksiPinjamBuku(listRelasi &LR, listPeminjam &LP, listBuku &LB, string idPeminjam, string idBuku);
int showMenu();
void rating(listRelasi &LR,listBuku LB, string idBuku);

#endif