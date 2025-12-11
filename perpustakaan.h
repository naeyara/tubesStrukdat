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
void insertFirstBuku(listBuku &LB, adrBuku B);
void insertLastBuku(listBuku &LB, adrBuku B);
void deleteBuku(listBuku &LP, listRelasi &LR, string idBuku);
void showAllBuku(listBuku LB);
adrBuku searchBuku(listBuku LB, string idBuku);

void createListPeminjam(listPeminjam &LP);
adrPeminjam createNodePeminjam(infotypePeminjam X);
void insertFirstPeminjam(listPeminjam &LP, adrPeminjam P);
void insertLastPeminjam(listPeminjam &LP, adrPeminjam P);
void deletePeminjam(listPeminjam &LP, listRelasi &LR, string idPeminjam);
void showAllPeminjam(listPeminjam LP);
adrPeminjam searchPeminjam(listPeminjam LP, string idPeminjam);

void createListRelasi(listRelasi &LR);
elemenRelasi* createNodeRelasi(adrBuku B, adrPeminjam P, float nilai);
void insertRelasi (listRelasi &LR, adrRelasi R);
void showAllRelasiBuku(listRelasi LR, listBuku LB, string idBuku);
int countRelasiBuku(listRelasi LR, string idBuku);
void deleteRelasiBuku(listRelasi &LR, string idBuku);
void deleteRelasiPeminjam(listRelasi &LR, string idPeminjam);
// void dataRelasiDummy(listRelasi &LR, listBuku LB, listPeminjam LP);

void inputNFirstBuku(listBuku &LB);
void inputNLastBuku(listBuku &LB);
void inputNFirstPeminjam(listPeminjam &LP);
void inputNLastPeminjam(listPeminjam &LP);
void aksiPinjamBuku(listRelasi &LR, listPeminjam &LP, listBuku &LB, string idPeminjam, string idBuku);
void rating(listRelasi &LR,listBuku LB, string idBuku);
adrBuku favoriteBuku(listBuku &LB);
void showFavoriteBuku(listBuku LB);
void showMenu(listBuku &LB, listPeminjam &LP, listRelasi &LR);

#endif