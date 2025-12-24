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

    return 0;
}
