#include "perpustakaan.h"
#include <iostream>
#include <cstring>
using namespace std;

//=== FUNGSI & PROSEDUR PADA MAIN
void showMenu(listBuku &LB, listPeminjam &LP, listRelasi &LR){
    int inputUser;
    string idBuku, idPeminjam;
    string inputIdBuku, inputIdPeminjam;
    adrBuku B;
    adrPeminjam P;

    do{
        cout << "\n=== MENU PERPUSTAKAAN ===\n";
        cout << "[1] Insert Last Buku\n";
        cout << "[2] Insert First Buku\n";
        cout << "[3] Insert Last Peminjam\n";
        cout << "[4] Insert First Peminjam\n";
        cout << "[5] Show All Peminjam\n";
        cout << "[6] Show All Buku\n";
        cout << "[7] Aksi Peminjaman\n";
        cout << "[8] Delete Peminjam\n";
        cout << "[9] Delete Buku\n";
        cout << "[10] Tampilkan Semua Data Peminjaman\n";
        cout << "[11] Tampilkan Daftar Buku Favorit dan Tidak\n";
        cout << "[12] Tampilkan Peminjam Buku Bedasarkan ID Buku\n";
        cout << "[13] Tampilkan Buku yang Dipinjam Bedasarkan ID Peminjam\n";
        cout << "[14] Keluar\n\n";
        cout << "Masukkan pilihan anda : ";
        cin >> inputUser; cin.ignore();
        
        switch(inputUser){
            case 1:
                inputNLastBuku(LB);
                break;
            case 2:
                inputNFirstBuku(LB);
                break;
            case 3:
                inputNLastPeminjam(LP);
                break;
            case 4:
                inputNFirstPeminjam(LP);
                break;
            case 5:
                showAllPeminjam(LP);
                break;
            case 6:
                showAllBuku(LB);
                break;
            case 7:
                cout << "Input ID Buku: ";
                cin >> inputIdBuku; cin.ignore();
                cout << "Input ID Peminjam: ";
                cin >> inputIdPeminjam; cin.ignore();
                aksiPinjamBuku(LR, LP, LB, inputIdPeminjam, inputIdBuku);
                showAllRelasiBuku(LR, LB, inputIdBuku);
                break;
            case 8:
                cout << "Input ID Peminjam: ";
                cin >> idPeminjam; cin.ignore();
                deletePeminjam(LP, LR, idPeminjam);
                break;
            case 9:
                cout << "Input ID Buku: ";
                cin >> idBuku; cin.ignore();
                deleteBuku(LB, LR, idBuku);
                break;
            case 10:
                showAllData(LB, LR);
                break;
            case 11:
                favoriteBuku(LB);
                break;
            case 12:
                cout << "Input ID Buku: ";
                cin >> idBuku; cin.ignore();
                showPeminjamBasedBuku(LR, idBuku);
                break;
            case 13:
                cout << "Input ID Peminjam: ";
                cin >> idPeminjam; cin.ignore();
                showBukuBasedPeminjam(LR, idPeminjam);
                break;
            case 14:
                cout << "Terimakasih telah menggunakan aplikasi kami! :)\n";
                cout << "Made with Love Nayya & Jingga <3\n";
                break;
            default:
                cout << "Terimakasih telah menggunakan aplikasi kami! :)\n";
                cout << "Made with Love Nayya & Jingga <3\n";
                break;
        }
    } while (inputUser != 0);
}

//=== FUNGSI & PROSEDUR (BUKU)
void createListBuku(listBuku &LB){
    LB.first = nullptr;
}

adrBuku createNodeBuku(infotypeBuku Z){
    // membuat node kosong
    adrBuku node = new elemenBuku;
    node->info = Z;
    node->next = nullptr;
    return node;
}

void insertFirstBuku(listBuku &LB, adrBuku B){
    if (B == nullptr){
        return;
    }

    B->next = LB.first;
    LB.first = B;
}

void insertLastBuku(listBuku &LB, adrBuku B){
    // jika node b kosong maka return (gagal)
    if (B == nullptr){
        return;
    }

    // jika List kosong maka menjadikan B elemen pertama 
    if(LB.first == nullptr){
        LB.first = B;
    } else {
        // membuat node pembantu
        adrBuku R = LB.first;
        // perulangan jika setelah R tidak kosong akan berpindah ke sebelah
        while (R->next != nullptr){
            R = R->next;
        }
        // sampai pada akhir setelah R adalah kosong, menjadikan setelah R adalah B
        R->next = B;
    }
    //karena B merupakan node terakhir, maka nextnya null
    B->next = nullptr;
}

void deleteBuku(listBuku &LB, listRelasi &LR, string idBuku){
    //Cek apakah list kosong
    if(LB.first == nullptr) {
     cout << "List Buku Kosong!\n";
     return;
    }

    deleteRelasiBuku(LR, idBuku);
    //Membuat node pembantu
    adrBuku B = LB.first;

    //Jika node yang akan dihapus merupakan first
    if(LB.first->info.idBuku == idBuku){
        LB.first = B->next;
        delete B;
        return;
    }

    //Jika node yang akan dihapus berada ditengah
    adrBuku Prev = nullptr;
    while (B != nullptr && B->info.idBuku != idBuku){
        Prev = B;
        B = B->next;
    }

    //Cek apakah B memiliki nilai
    if (B == nullptr){
        cout << "Buku dengan ID " << idBuku << " Tidak Ditemukan!\n";
        return;
    }else{
        Prev->next = B->next;
        delete B;
    }
}

void showAllBuku(listBuku LB){
    cout << "\n=== Daftar Buku Perpustakaan ===\n";

    if (LB.first == nullptr){
        cout << "Daftar Buku Kosong." << endl;
    }

    adrBuku B = LB.first;
    int i = 1;
    while (B != nullptr){
        cout << ">> Data Buku ke- " << i << endl;
        cout << "ID Buku        : " << B->info.idBuku << endl;
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

void dataBukuDummy(listBuku &LB){
    buku input;
    input = {"1", "Laut Berteriak", 2005};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"2", "Bumi Manusia", 1980};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"3", "Negeri Para Bedebah", 2012};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"4", "Laskar Pelangi", 2005};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"5", "Ayat-Ayat Cinta", 2004};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"6", "Pulang", 2015};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"7", "Hujan", 2016};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"8", "Mariposa", 2018};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"9", "Dilan 1990", 2014};
    insertLastBuku(LB, createNodeBuku(input));

    input = {"10", "Critical Eleven", 2015};
    insertLastBuku(LB, createNodeBuku(input));

    cout << "Data Buku Dummy Berhasil Diinputkan\n";
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

void insertFirstPeminjam(listPeminjam &LP, adrPeminjam P){
    if(P == nullptr) return;
    P->next = LP.first;
    LP.first = P;
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

void deletePeminjam(listPeminjam &LP, listRelasi &LR, string idPeminjam){
    //Cek apakah list kosong
    if(LP.first == nullptr) {
     cout << "List Peminjam Kosong!\n";
     return;
    }

    deleteRelasiPeminjam(LR, idPeminjam);
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
            cout << "ID Peminjam    : " << node->info.idPeminjam << "\n";
            cout << "Nama           : " << node->info.nama << "\n";
            cout << "Telpon         : " << node->info.telpon << "\n";
            cout << "Alamat         : " << node->info.alamat << "\n";
            cout << "Jumlah Buku    : " << node->info.jumlahBukuYangDipinjam << "\n";
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

elemenRelasi* createNodeRelasi(adrBuku B, adrPeminjam P, float nilai){
    elemenRelasi* R = new elemenRelasi;
    R->buku = B;
    R->peminjam = P;
    R->nilai = nilai;
    R->next = nullptr;
    return R;
}

void insertRelasi(listRelasi &LR, adrRelasi R){
    if(LR.first == nullptr){
        LR.first = R;   
    }else{
        adrRelasi Q = LR.first;
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = R;
        // R->next = nullptr;
    }
}

void showAllRelasiBuku(listRelasi LR, listBuku LB, string idBuku){
    adrRelasi R = LR.first;
    bool ketemu = false;
    int i  = 1;
    cout << "\n=== DAFTAR PEMINJAM BUKU " << idBuku << " ===\n";
    while(R != nullptr){
        if(R->buku->info.idBuku == idBuku){
            cout << i << ". ID: " << R->peminjam->info.idPeminjam << " | Nama: " << R->peminjam->info.nama << " | Nilai : " << R->nilai << endl;
            ketemu = true;
            i++;
        }
        R = R->next;
    }
    adrBuku B = searchBuku(LB, idBuku);
    cout << "Rating Buku: " << B->info.rating << endl;

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

void deleteRelasiBuku(listRelasi &LR, string idBuku){
    adrRelasi R = LR.first;
    adrRelasi prev = nullptr;

    while(R != nullptr){
        if(R->buku->info.idBuku == idBuku){
            // jika node pertama maka first bergeser ke next
            if(prev == nullptr){
                LR.first = R->next;
            }else{
                prev->next = R->next;
            }
            adrRelasi temp = R;
            R = R->next;
            delete temp;
        } else{
            prev = R;
            R = R->next;
        }
    } 
}

void deleteRelasiPeminjam(listRelasi &LR, string idPeminjam){
    adrRelasi R = LR.first;
    adrRelasi prev = nullptr;

    while(R != nullptr){
        if(R->peminjam->info.idPeminjam == idPeminjam){

            //Jika node pertama maka first bergeser ke next
            if(prev == nullptr){
                LR.first = R->next;
            }else{
                prev->next = R->next;
            }
            adrRelasi temp = R;
            R = R->next;
            delete temp;
        }else{
            prev = R;
            R = R->next;
        }
    }
}

void dataPeminjamDummy(listPeminjam &LP){
    peminjam input;
    
    input = {"1", "Jingga Jil", "Jl. Kenangan", "0812-1111-1111", 0};
    insertLastPeminjam(LP, createNodePeminjam(input));

    input = {"2", "Nayya", "Jl. Jambu", "0812-2222-2222", 0};
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

    cout <<"Data Peminjam Dummy Berhasil Diinputkan\n";
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
    adrRelasi R1 = createNodeRelasi(B1, P1, 0);
    insertRelasi(LR, R1);
    adrRelasi R2 = createNodeRelasi(B1, P2, 0);
    insertRelasi(LR, R2);

    //Pinjam B2
    adrRelasi R3 = createNodeRelasi(B2, P1, 0);
    insertRelasi(LR, R3);

    //Pinjam B3
    adrRelasi R4 = createNodeRelasi(B3, P3, 0);
    insertRelasi(LR, R4);
    adrRelasi R5 = createNodeRelasi(B3, P4, 0);
    insertRelasi(LR, R5);

    //Pinjam B4
    adrRelasi R6 = createNodeRelasi(B4, P3, 0);
    insertRelasi(LR, R6);
    adrRelasi R7 = createNodeRelasi(B4, P4, 0);
    insertRelasi(LR, R7);
}

//=== FUNGSI & PROSEDUR INPUT ===
void inputNFirstBuku(listBuku &LB){
    buku input;
    string idBuku, judulBuku;
    int tahunTerbit;
    float rating;
    int banyakBuku;

    cout << "Masukkan banyak buku : ";
    cin >> banyakBuku; cin.ignore();

    for (int i = 1; i <= banyakBuku; i++){
        cout << ">> DATA BUKU KE-" << i << "\n";
        cout << "ID Buku        : "; cin >> idBuku; cin.ignore();
        cout << "Judul Buku     : "; getline(cin, judulBuku); 
        cout << "Tahun Terbit   : "; cin >> tahunTerbit; cin.ignore(); //Membersihkan input numerik
        cout << "\n";
        input.idBuku = idBuku;
        input.judulBuku = judulBuku;
        input.tahunTerbit = tahunTerbit;
        input.rating = 0;
        insertFirstBuku(LB, createNodeBuku(input));

    };
}

void inputNLastBuku(listBuku &LB){
    buku input;
    string idBuku, judulBuku;
    int tahunTerbit;
    float rating;
    int banyakBuku;

    cout << "Masukkan banyak buku : ";
    cin >> banyakBuku; cin.ignore();

    for (int i = 1; i <= banyakBuku; i++){
        cout << ">> DATA BUKU KE-" << i << "\n";
        cout << "ID Buku        : "; cin >> idBuku; cin.ignore();
        cout << "Judul Buku     : "; getline(cin, judulBuku); 
        cout << "Tahun Terbit   : "; cin >> tahunTerbit; cin.ignore(); //Membersihkan input numerik
        cout << "\n";
        input.idBuku = idBuku;
        input.judulBuku = judulBuku;
        input.tahunTerbit = tahunTerbit;
        input.rating = 0;
        insertLastBuku(LB, createNodeBuku(input));

    };
}

void inputNFirstPeminjam(listPeminjam &LP){
    peminjam input;
    string idPeminjam, nama, alamat, telpon;
    int jumlahBukuYangDipinjam;
    int banyakPeminjam;

    cout << "Masukkan banyak peminjam : ";
    cin >> banyakPeminjam; cin.ignore();

    for (int i = 1; i <= banyakPeminjam; i++){
        cout << ">> DATA PEMINJAM KE-" << i << "\n";
        cout << "ID Peminjam                : "; cin >> idPeminjam; cin.ignore();
        cout << "Nama                       : "; getline(cin, nama);
        cout << "Alamat                     : "; getline(cin, alamat);
        cout << "Telpon                     : "; cin >> telpon; cin.ignore(); //Membersihkan input numerik
        cout << "\n";
        input.idPeminjam = idPeminjam; 
        input.nama = nama;
        input.alamat = alamat;
        input.telpon = telpon;
        input.jumlahBukuYangDipinjam = 0;
        insertFirstPeminjam(LP, createNodePeminjam(input));
    };
}

void inputNLastPeminjam(listPeminjam &LP){
    peminjam input;
    string idPeminjam, nama, alamat, telpon;
    int jumlahBukuYangDipinjam;
    int banyakPeminjam;

    cout << "Masukkan banyak peminjam : ";
    cin >> banyakPeminjam; cin.ignore();

    for (int i = 1; i <= banyakPeminjam; i++){
        cout << ">> DATA PEMINJAM KE-" << i << "\n";
        cout << "ID Peminjam                : "; cin >> idPeminjam; cin.ignore();
        cout << "Nama                       : "; getline(cin, nama);
        cout << "Alamat                     : "; getline(cin, alamat);
        cout << "Telpon                     : "; cin >> telpon; cin.ignore(); //Membersihkan input numerik
        cout << "\n";
        input.idPeminjam = idPeminjam; 
        input.nama = nama;
        input.alamat = alamat;
        input.telpon = telpon;
        input.jumlahBukuYangDipinjam = 0;
        insertLastPeminjam(LP, createNodePeminjam(input));
    };
}

// === FUNGSI & PROSEDUR AKSI 
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
    if(P->info.jumlahBukuYangDipinjam >= 5){
        cout << "Tidak bisa melakukan peminjaman, anda melewati batas aturan\n";
        return;
    } else {
        //Menerima input nilai rating
        float inputNilai;
        cout << "Masukkan rating buku: ";
        cin >> inputNilai; cin.ignore();
        
        //Hubungkan dengan node relasi
        adrRelasi R = createNodeRelasi(B, P, inputNilai);
        insertRelasi(LR, R);

        rating(LR, LB, idBuku);
        P->info.jumlahBukuYangDipinjam++;
    }
}

void rating (listRelasi &LR, listBuku LB, string idBuku){
    adrRelasi R = LR.first;

    // Cari alamat buku
    adrBuku buku = searchBuku(LB, idBuku);

    // Jika buku tidak ada
    if(buku == nullptr){
        cout << "Buku tidak ditemukan.\n";
        return;
    }

    // Hitung total jumlah nilai
    float totalNilai = 0;
    int jumlah = countRelasiBuku(LR, idBuku);
    while (R != nullptr){
        if (R->buku->info.idBuku == idBuku){
            
            totalNilai += R->nilai;
        }
        R = R->next;
    }

    //Perhitung nilai rata-rata
    float finalRating = totalNilai/jumlah;
    
    //Update nilai rating pada list Buku
    buku->info.rating = finalRating;
}

void favoriteBuku(listBuku LB){
    // Pengecekan list kosong
    if(LB.first == nullptr){
        return;
    }

    adrBuku favorite = LB.first;

    while(favorite != nullptr){
        if(favorite->info.rating == 5){
            cout << "=== BUKU FAVORITE ===\n";
            cout << "ID Buku      : " << favorite->info.idBuku << endl;
            cout << "Judul        : " << favorite->info.judulBuku << endl;
            cout << "Tahun Terbit : " << favorite->info.tahunTerbit << endl;
            cout << "Rating       : " << favorite->info.rating << endl;
        } else if(favorite->info.rating == 0){
            cout << "=== BUKU TIDAK FAVORITE ===\n";
            cout << "ID Buku      : " << favorite->info.idBuku << endl;
            cout << "Judul        : " << favorite->info.judulBuku << endl;
            cout << "Tahun Terbit : " << favorite->info.tahunTerbit << endl;
            cout << "Rating       : " << favorite->info.rating << endl;
        }
        favorite = favorite->next;
    }
    return;
}


void showAllData(listBuku LB, listRelasi LR){
    int NBuku = 1;
    adrBuku B = LB.first;
    
    NBuku = 1;
    while(B != nullptr){
        bool adaPeminjam = false;
        int NPeminjam = 1;
        adrRelasi R = LR.first;
        // Cetak Buku
        cout << NBuku << ". ID Buku     :" << B->info.idBuku << "\n";
        cout << "Judul Buku     :" << B->info.judulBuku << "\n";
        cout << "Tahun Terbit   :" << B->info.tahunTerbit << "\n";
        cout << "Rating         :" << B->info.rating << "\n";
        cout << "Dipinjam oleh  :\n";
        
        while(R != nullptr){
            //Cetak isi Peminjam
            // adaPeminjam = false;
            if(R->buku == B){
                if(R->peminjam != nullptr){
                    adaPeminjam = true;
                    cout << NPeminjam << "." <<  R->peminjam->info.nama << "\n";
                    NPeminjam++;
                }
            }
            R = R->next;
        }
        if(!adaPeminjam){
            cout << "-> Tidak ada aksi peminjaman\n";
        }
        NBuku++;
        cout << "\n";
        B = B->next;
    }

}

void showBukuBasedPeminjam(listRelasi LR, string idPeminjam){
    bool adaBuku = false;
    int NBuku = 1;
    adrRelasi R = LR.first;

    while(R != nullptr){
        if(R->peminjam != nullptr && R->peminjam->info.idPeminjam == idPeminjam){
            adaBuku = true;
            cout << NBuku << ". " << R->buku->info.judulBuku << endl;
            NBuku++;
        }
        R = R->next;
    }
    if(!adaBuku){
        cout << "Tidak ada buku yang dipinjam\n";
    }
}
void showPeminjamBasedBuku(listRelasi LR, string idBuku){
    bool adaPeminjam = false;
    int NPeminjam = 1;
    adrRelasi R = LR.first;

    while(R != nullptr){
        if(R->buku != nullptr && R->buku->info.idBuku == idBuku){
            adaPeminjam= true;
            cout << NPeminjam << ". " << R->peminjam->info.nama << endl;
            NPeminjam++;
        }
        R = R->next;
    }
    if(!adaPeminjam){
        cout << "Tidak ada buku yang dipinjam\n";
    }
}
