#include "perpustakaan.h"
#include <iostream>
#include <cstring>
using namespace std;

//=== FUNGSI & PROSEDUR (BUKU)
void createListBuku(listBuku &LB){
    LB.first = nullptr;
}

adrBuku createNodeBuku(infotypeBuku Z){
    adrBuku node = new elemenBuku;
    node->info = Z;
    node->next = nullptr;
    return node;
}

void insertFirstBuku(listBuku &LB, adrBuku P){
    if (P == nullptr){
        return;
    }

    P->next = LB.first;
    LB.first = P;
}

void insertLastBuku(listBuku &LB, adrBuku P){
    if (P == nullptr){
        return;
    }

    if(LB.first == nullptr){
        LB.first = P;
    } else {
        adrBuku R = LB.first;
        while (R->next != nullptr){
            R = R->next;
        }
        R->next = P;
    }
    P->next = nullptr;
}

void deleteBuku(listBuku &LB, string idBuku){
    if (LB.first == nullptr){
        return;
    }

    adrBuku B = LB.first;

    if(LB.first->info.idBuku == idBuku){
        LB.first = B->next;
        delete B;
    } else {
        adrBuku prev = nullptr;
        while (prev != nullptr && B->info.idBuku != idBuku){
            prev = B;
            B = B->next;
        }
    prev->next = nullptr;
    delete B;
    }
}

void showAllBuku(listBuku LB){
    cout << "=== Daftar Buku Perpustakaan ===\n";

    if (LB.first == nullptr){
        cout << "Daftar Buku Kosong." << endl;
    }

    adrBuku B = LB.first;
    int i = 1;
    while (B != nullptr){
        cout << ">> Data Buku ke- " << i << endl;
        cout << "ID             : " << B->info.idBuku << endl;
        cout << "Judul          : " << B->info.judulBuku << endl;
        cout << "Tahun Terbit   : " << B->info.tahunTerbit << endl;
        cout << "Rating         : " << B->info.rating << endl;
        cout << "\n";
        B = B->next;
        i++;

    }
    cout << endl;
}

adrBuku searchBuku(listBuku LB, string idBuku){
    adrBuku Q = LB.first;
    while(Q != nullptr){
        if(Q->info.idBuku == idBuku){
            return Q;
        }
        Q = Q->next;
    }
    return nullptr;
}


//=== FUNGSI & PROSEDUR (PEMINJAM)
void createListPeminjam(listPeminjam &LP){
    LP.first = nullptr;
}

adrPeminjam createNodePeminjam(infotypePeminjam X){
    //Membuat node kosong
    adrPeminjam node = new elemenPeminjam; 
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
        cout << "=== DAFTAR PEMINJAM ===\n";
        adrPeminjam node = LP.first;
        int i = 1;
        while(node != nullptr){
            cout << ">> Data Peminjam Ke- " << i << "\n";
            cout << "ID         : " << node->info.idPeminjam << "\n";
            cout << "Nama       : " << node->info.nama << "\n";
            cout << "Telpon     : " << node->info.telpon << "\n";
            cout << "Alamat     : " << node->info.alamat << "\n";
            cout << "Jumlah Buku: " << node->info.jumlahBukuYangDipinjam << "\n\n";
            node = node->next;
            i++;
            cout << "\n";
        }
    }
}

adrPeminjam searchPeminjam(listPeminjam LP, string idPeminjam){
    adrPeminjam Q = LP.first;
    while(Q != nullptr){
        if(Q->info.idPeminjam == idPeminjam){
            return Q;
        }
        Q = Q->next;
    }
    return nullptr;
}

//==== FUNGSI & PROSEDUR (RELASI)
void createListRelasi(listRelasi &LR){
    LR.first = nullptr;
}

elemenRelasi* createNodeRelasi(adrBuku B, adrPeminjam P){
    elemenRelasi* R = new elemenRelasi;
    R->buku = B;
    R->peminjam = P;
    R->next = nullptr;
    return R;
}

void insertRelasi (listRelasi &LR, adrRelasi R){
    if(LR.first == nullptr){
        LR.first = R;   
    }else{
        adrRelasi Q = LR.first;
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = R;
        R->next = nullptr;
    }
}

//=== FUNGSI & PROSEDUR (TAMBAHAN) ===
void aksiPinjamBuku(listRelasi &LR, listPeminjam &LP, listBuku &LB, string idPeminjam, string idBuku){
    //Mencari subjek peminjam
    adrPeminjam P = searchPeminjam(LP, idPeminjam);
    if(P == nullptr){
        cout << "Peminjam dengan ID " << idPeminjam << " tidak ditemukan!\n";
        return;
    }

    //Mencari buku
    adrBuku B = searchBuku(LB, idBuku);
    if(B == nullptr){
        cout << "Buku dengan ID " << idBuku << " tidak ditemukan!\n";
        return;
    }

    //Cek jumlah peminjaman yang telah dilakukan
    if(P->info.jumlahBukuYangDipinjam > 5){
        cout << "Tidak bisa melakukan peminjaman, anda melewati batas aturan\n";
        return;
    }

    //Hubungkan dengan node relasi
    adrRelasi R = createNodeRelasi(B, P);
    insertRelasi(LR, R);
    P->info.jumlahBukuYangDipinjam++;
    
    //Input Rating
    int jumlahPeminjam = countRelasiBuku(LR, idBuku);
}

void showAllRelasiBuku(listRelasi LR, string idBuku){
    adrRelasi R = LR.first;
    bool ketemu = false;
    int i  = 1;
    cout << "\n=== DAFTAR PEMINJAM BUKU " << idBuku << " ===\n";
    while(R != nullptr){
        if(R->buku->info.idBuku == idBuku){
            cout << i << ". ID: " << R->peminjam->info.idPeminjam << " | Nama: " << R->peminjam->info.nama << endl;
            ketemu = true;
            i++;
        }
        R = R->next;
    }
    if(!ketemu){
        cout << "Tidak ada peminjam buku ID " << idBuku << endl;
    }
}

int countRelasiBuku(listRelasi LR, string idBuku){
    int count = 0;
    adrRelasi R = LR.first;

    while(R != nullptr){
        if(R->buku->info.idBuku == idBuku){
            count++;
        }
        R = R->next;
    }
    return count;
}

void inputNPeminjam(listPeminjam &LP){
    // === INPUT ITERASI SEBANYAK n KALI ===
    peminjam input;
    string idPeminjam, nama, alamat, telpon;
    int jumlahBukuYangDipinjam;
    int banyakPeminjam;
    cout << "Masukkan banyak peminjam : ";
    cin >> banyakPeminjam;

    for (int i = 1; i <= banyakPeminjam; i++){
        cout << ">> DATA PEMINJAM KE-" << i << "\n";
        cout << "ID                         : "; cin >> idPeminjam;
        cout << "Nama                       : "; cin >> nama;
        cout << "Alamat                     : "; cin >> alamat;
        cout << "Telpon                     : "; cin >> telpon;
        cout << "Jumlah Buku Yg Dipinjam    : "; cin >> jumlahBukuYangDipinjam; 
        cin.ignore(); //Membersihkan input numerik
        cout << "\n";
        input = {idPeminjam, nama, alamat, telpon, jumlahBukuYangDipinjam};
        insertLastPeminjam(LP, createNodePeminjam(input));

    };
}

void inputNBuku(listBuku &LB){
    // === INPUT ITERASI SEBANYAK n KALI ===
    buku inputBuku;
    string idBuku, judulBuku;
    int tahunTerbit;
    float rating;
    int banyakBuku;

    cout << "Masukkan banyak buku : ";
    cin >> banyakBuku;

    for (int i = 1; i <= banyakBuku; i++){
        cout << ">> DATA BUKU KE-" << i << "\n";
        cout << "ID Buku        : "; cin >> idBuku;
        cout << "Judul Buku     : "; cin >> judulBuku;
        cout << "Tahun Terbit   : "; cin >> tahunTerbit;
        cin.ignore(); //Membersihkan input numerik
        cout << "Rating         : "; cin >> rating;
        cin.ignore(); //Membersihkan input numerik
        cout << "\n";
        //BUTUH FUNGSI HITUNG RATING
        // inputBuku ={idBuku, judulBuku, tahunTerbit, rating};

        // insertLastBuku(LB, createNodeBuku(inputBuku));

    };
}
int showMenu(){
    int inputUser;
    cout << "\n=== MENU PERPUSTAKAAN ===\n";
    cout << "[1] Insert Last Buku\n";
    cout << "[2] Insert First Buku\n";
    cout << "[3] Insert Last Peminjam\n";
    cout << "[4] Insert First Peminjam\n";
    cout << "[5] Show All Peminjam\n";
    cout << "[6] Show All Buku\n";
    cout << "[7] Aksi Peminjaman\n";
    cout << "[8] Delete Peminjam\n";
    cout << "[9] Delete Buku\n\n";
    cout << "Masukkan pilihan anda : ";
    cin >> inputUser;

    return inputUser;
}


void dataBukuDummy(listBuku &LB){
    buku input;
    input = {"1", "Laut Berteriak", 2005, 5};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"2", "Bumi Manusia", 1980, 4.8};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"3", "Negeri Para Bedebah", 2012, 4.5};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"4", "Laskar Pelangi", 2005, 4.7};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"5", "Ayat-Ayat Cinta", 2004, 4.6};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"6", "Pulang", 2015, 4.9};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"7", "Hujan", 2016, 4.8};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"8", "Mariposa", 2018, 4.4};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"9", "Dilan 1990", 2014, 4.5};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"10", "Critical Eleven", 2015, 4.3};
    insertLastBuku(LB, createNodeBuku(input));

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

void dataRelasiDummy(listRelasi &LR, listBuku LB, listPeminjam LP){
    // Ambil address buku
    adrBuku B1 = searchBuku(LB, "1");
    adrBuku B2 = searchBuku(LB, "2");
    adrBuku B3 = searchBuku(LB, "3");
    adrBuku B4 = searchBuku(LB, "4");

    // Ambil address peminjam
    adrPeminjam P1 = searchPeminjam(LP, "1");
    adrPeminjam P2 = searchPeminjam(LP, "2");
    adrPeminjam P3 = searchPeminjam(LP, "3");
    adrPeminjam P4 = searchPeminjam(LP, "4");

    //Pinjam B1
    adrRelasi R1 = createNodeRelasi(B1, P1);
    insertRelasi(LR, R1);
    adrRelasi R2 = createNodeRelasi(B1, P2);
    insertRelasi(LR, R2);

    //Pinjam B2
    adrRelasi R3 = createNodeRelasi(B2, P1);
    insertRelasi(LR, R3);

    //Pinjam B3
    adrRelasi R4 = createNodeRelasi(B3, P3);
    insertRelasi(LR, R4);
    adrRelasi R5 = createNodeRelasi(B3, P4);
    insertRelasi(LR, R5);

    //Pinjam B4
    adrRelasi R6 = createNodeRelasi(B4, P3);
    insertRelasi(LR, R6);
    adrRelasi R7 = createNodeRelasi(B4, P4);
    insertRelasi(LR, R7);
}

int main(){
    listPeminjam LP;
    createListPeminjam(LP);

    listBuku LB;
    createListBuku(LB);

    listRelasi LR;
    createListRelasi(LR);

    dataBukuDummy(LB);
    dataPeminjamDummy(LP);

    showAllPeminjam(LP);
    showAllBuku(LB);

    dataRelasiDummy(LR, LB, LP);
    showAllRelasiBuku(LR, "1");
    showAllRelasiBuku(LR, "2");
    showAllRelasiBuku(LR, "3");
    showAllRelasiBuku(LR, "4");
    showAllRelasiBuku(LR, "5");


    // cout << showMenu();
}