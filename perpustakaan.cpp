#include "perpustakaan.h"
#include <iostream>
#include <cstring>
using namespace std;


void createListPeminjam(listPeminjam &LP){
    LP.first = nullptr;
}

adrPeminjam createNodePeminjam(infotypePeminjam X){
    adrPeminjam node = new elemenPeminjam; //Membuat node kosong
    node->info = X;
    node->next = nullptr;
    return node;
}

void insertLastPeminjam(listPeminjam &LP, adrPeminjam P){
    //Jika node P berisi kosong maka akan return 0 "Gagal"
    if(P == nullptr) return;

    //Jika List kosong maka menjadikan P elemen pertama
    if(LP.first == nullptr){
        LP.first = P;
    }else{
       
        //Membuat node pembantu
        adrPeminjam Q = LP.first;
        //Perulangan jika setelah Q tidak kosong akan berpindah ke sebelah
        while(Q->next != nullptr){
            Q = Q->next;
        }
        //Sampai pada akhir setelah Q adalah kosong, menjadikan setelah Q adalah P
        Q->next = P;
        //P adalah node terakhir maka setelahnya null
        P->next = nullptr;
    }


}
void insertFirstPeminjam(listPeminjam &LP, adrPeminjam P){
    if(P == nullptr) return;
    P->next = LP.first;
    LP.first = P;
}
void deletePeminjam(listPeminjam &LP, string idPeminjam){
    //Cek apakah list kosong
    if(LP.first == nullptr) {
     cout << "List Peminjam Kosong!\n";
     return;
    }
    //Membuat node pembantu
    adrPeminjam P = LP.first;

    //Jika node yang akan dihapus merupakan first
    if(LP.first->info.idPeminjam == idPeminjam){
        LP.first = P->next;
        delete P;
        return;
    }

    //Jika node yang akan dihapus berada ditengah
    adrPeminjam Prev = nullptr;
    while (P != nullptr && P->info.idPeminjam != idPeminjam){
        Prev = P;
        P = P->next;
    }

    //Cek apakah P memiliki nilai
    if (P == nullptr){
        cout << "Peminjam dengan ID " << idPeminjam << " Tidak Ditemukan!\n";
        return;
    }else{
        Prev->next = P->next;
        delete P;
    }
}

void showAllPeminjam(listPeminjam LP){
    if(LP.first == nullptr){
        cout << "Daftar Peminjam Kosong\n";
    }else{
        adrPeminjam node = LP.first;
        int i = 1;
        while(node != nullptr){
            cout << "=== Data Peminjam Ke- " << i << " ===\n";
            cout << "ID         : " << node->info.idPeminjam << "\n";
            cout << "Nama       : " << node->info.nama << "\n";
            cout << "Telpon     : " << node->info.telpon << "\n";
            cout << "Alamat     : " << node->info.alamat << "\n";
            cout << "Jumlah Buku: " << node->info.jumlahBukuYangDipinjam << "\n";
            node = node->next;
            i++;
            cout << "\n";
        }
    }
}

int main(){
    listPeminjam LP;
    createListPeminjam(LP);

    peminjam input;
    string idPeminjam, nama, alamat, telpon;
    int jumlahBukuYangDipinjam;
    
    input = {"1", "Jingga Jil", "Jl. Kenangan", "0812-XXXX-XXX", 4};
    insertLastPeminjam(LP, createNodePeminjam(input));
    input = {"2", "Bambang", "Jl. Jambu", "0812-XXXX-XXX", 1};
    insertLastPeminjam(LP, createNodePeminjam(input));
    input = {"3", "Sendy", "Jl. Nanas", "0812-XXXX-XXX", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));
    input = {"4", "Jil", "Jl. Apel", "0812-XXXX-XXX", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));
    input = {"5", "Ridwan Kamil", "Jl. Koperasi", "0812-XXXX-XXX", 1};
    insertLastPeminjam(LP, createNodePeminjam(input));
    input = {"6", "Langgachan", "Jl. Papaya", "0812-XXXX-XXX", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    showAllPeminjam(LP);


}