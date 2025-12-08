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

void dataPeminjamDummy(listPeminjam &LP){
    peminjam input;
    input = {"1", "Jingga Jil", "Jl. Kenangan", "0812-1111-1111", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"2", "Bambang", "Jl. Jambu", "0812-2222-2222", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"3", "Sendy", "Jl. Nanas", "0812-3333-3333", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"4", "Rizki", "Jl. Melon", "0812-4444-4444", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"5", "Sari Putri", "Jl. Stroberi", "0812-5555-5555", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"6", "Langgachan", "Jl. Papaya", "0812-6666-6666", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"7", "Gilbert", "Jl. Durian", "0812-7777-7777", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"8", "Anastasya", "Jl. Lemon", "0812-8888-8888", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"9", "Putra Perdana", "Jl. Sawo", "0812-9999-9999", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"10", "Caca Afriani", "Jl. Anggur", "0812-0000-0000", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

}

int main(){
    listPeminjam LP;
    createListPeminjam(LP);

    peminjam input;
    string idPeminjam, nama, alamat, telpon;
    int jumlahBukuYangDipinjam;
    
    dataPeminjamDummy(LP);

    // === INPUT ITERASI SEBANYAK n KALI ===
    // int banyakPeminjam;
    // cout << "Masukkan banyak peminjam : ";
    // cin >> banyakPeminjam;

    // for (int i = 1; i <= banyakPeminjam; i++){
    //     cout << "DATA PEMINJAM KE-" << i << "\n";
    //     cout << "ID                         : "; cin >> idPeminjam;
    //     cout << "Nama                       : "; cin >> nama;
    //     cout << "Alamat                     : "; cin >> alamat;
    //     cout << "Telpon                     : "; cin >> telpon;
    //     cout << "Jumlah Buku Yg Dipinjam    : "; cin >> jumlahBukuYangDipinjam; 
    //     cin.ignore(); //Membersihkan input numerik
    //     cout << "\n";
    //     input = {idPeminjam, nama, alamat, telpon, jumlahBukuYangDipinjam};
    //     insertLastPeminjam(LP, createNodePeminjam(input));

    // };


    showAllPeminjam(LP);
}