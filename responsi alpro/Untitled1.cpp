#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Struktur data untuk buku
struct Buku {
    string judul;
    string penulis;
    int tahun;
    double harga;
};

const int MAX_BUKU = 100;
Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

// Fungsi baca dari file
void bacaData() {
    ifstream file("data_buku.txt");
    if (!file) {
        cout << "File belum ada. Data kosong.\n";
        return;
    }

    while (getline(file, daftarBuku[jumlahBuku].judul)) {
        getline(file, daftarBuku[jumlahBuku].penulis);
        file >> daftarBuku[jumlahBuku].tahun;
        file >> daftarBuku[jumlahBuku].harga;
        file.ignore(); // Bersihkan newline
        jumlahBuku++;
    }
    file.close();
}

// Fungsi simpan ke file
void simpanData() {
    ofstream file("data_buku.txt");
    for (int i = 0; i < jumlahBuku; i++) {
        cout << daftarBuku[i].judul << endl;
        cout << daftarBuku[i].penulis << endl;
        cout << daftarBuku[i].tahun << endl;
        cout << daftarBuku[i].harga << endl;
    }
    file.close();
}

// Tampilkan semua buku
void tampilBuku() {
    if (jumlahBuku == 0) {
        cout << "Belum ada data buku.\n";
        return;
    }

    for (int i = 0; i < jumlahBuku; i++) {
        cout << "Judul   : " << daftarBuku[i].judul << endl;
        cout << "Penulis : " << daftarBuku[i].penulis << endl;
        cout << "Tahun   : " << daftarBuku[i].tahun << endl;
        cout << "Harga   : Rp " << daftarBuku[i].harga << "\n\n";
    }
}

// Tambah buku baru
void tambahBuku() {
    if (jumlahBuku >= MAX_BUKU) {
        cout << "Kapasitas penuh.\n";
        return;
    }

    Buku b;
    cout << "Judul     : ";
    cin.ignore();
    getline(cin, b.judul);
    cout << "Penulis   : ";
    getline(cin, b.penulis);
    cout << "Tahun     : ";
    cin >> b.tahun;
    cout << "Harga     : Rp ";
    cin >> b.harga;

    daftarBuku[jumlahBuku++] = b;
    cout << "Data berhasil ditambahkan.\n";
}

// Cari buku berdasarkan judul
void cariBuku() {
    string keyword;
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, keyword);

    bool ketemu = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].judul.find(keyword) != string::npos) {
            cout << "Judul   : " << daftarBuku[i].judul << endl;
            cout << "Penulis : " << daftarBuku[i].penulis << endl;
            cout << "Tahun   : " << daftarBuku[i].tahun << endl;
            cout << "Harga   : Rp " << daftarBuku[i].harga << "\n\n";
            ketemu = true;
        }
    }

    if (!ketemu)
        cout << "Buku tidak ditemukan.\n";
}

// Hapus buku berdasarkan indeks
void hapusBuku() {
    int index;
    cout << "Nomor buku yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > jumlahBuku) {
        cout << "Nomor tidak valid.\n";
        return;
    }

    for (int i = index - 1; i < jumlahBuku - 1; i++) {
        daftarBuku[i] = daftarBuku[i + 1];
    }
    jumlahBuku--;
    cout << "Data berhasil dihapus.\n";
}

// Urutkan buku berdasarkan judul
void urutkanBuku() {
    for (int i = 0; i < jumlahBuku - 1; i++) {
        for (int j = i + 1; j < jumlahBuku; j++) {
            if (daftarBuku[i].judul > daftarBuku[j].judul) {
                swap(daftarBuku[i], daftarBuku[j]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan judul.\n";
}

// Menu utama
void menu() {
    cout << "=== PROGRAM INVESTASI PERPUSTAKAAN ===\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Tampilkan Semua Buku\n";
    cout << "3. Cari Buku\n";
    cout << "4. Hapus Buku\n";
    cout << "5. Urutkan Buku\n";
    cout << "6. Simpan dan Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    bacaData();

    int pilihan;
    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                tampilBuku();
                break;
            case 3:
                cariBuku();
                break;
            case 4:
                hapusBuku();
                break;
            case 5:
                urutkanBuku();
                break;
            case 6:
                simpanData();
                cout << "Data tersimpan. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan salah. Silakan coba lagi.\n";
        }
    } while (pilihan != 6);

    return 0;
}
