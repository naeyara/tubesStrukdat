#include "perpustakaan.cpp"
#include <iostream>
using namespace std;

int main(){
    listPeminjam LP;
    createListPeminjam(LP);

    listBuku LB;
    createListBuku(LB);

    listRelasi LR;
    createListRelasi(LR);


    dataBukuDummy(LB);
    dataPeminjamDummy(LP);
    showMenu(LB, LP, LR);

    //=== TESTING DG DATA DUMMY ===
    // dataBukuDummy(LB);
    // dataPeminjamDummy(LP);

    // showAllPeminjam(LP);
    // showAllBuku(LB);

    // dataRelasiDummy(LR, LB, LP);
    // showAllRelasiBuku(LR, "1");
    // showAllRelasiBuku(LR, "2");
    // showAllRelasiBuku(LR, "3");
    // showAllRelasiBuku(LR, "4");
    // showAllRelasiBuku(LR, "5");

    // inputNBuku(LB);
    // inputNPeminjam(LP);

    // string inputIdBuku, inputIdPeminjam;
    // cout << "Input ID Buku: ";
    // cin >> inputIdBuku;
    // cout << "Input ID Peminjam: ";
    // cin >> inputIdPeminjam;

    // aksiPinjamBuku(LR,LP,LB, inputIdPeminjam, inputIdBuku);
    // showAllRelasiBuku(LR, LB, inputIdBuku);



    return 0;
}
