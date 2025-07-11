#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struktur data untuk Investasi Perpustakaan
struct Investasi {
    string judulBuku;
    double danaInvestasi;
    int tahun;
};

// Fungsi untuk input data investasi
void inputData(Investasi, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nData Investasi ke-" << i + 1 << endl;
        cout << "Judul Buku     : ";
        cin.ignore();  // Membersihkan buffer input
//        getline(cin, judulBuku);
        cout << "Jumlah Dana (Rp): ";
        cin >> danaInvestasi;
        cout << "Tahun          : ";
        cin >> tahun;
    }
}

// Fungsi untuk menyimpan data ke file
void simpanKeFile(Investasi, int n, const string) {
//    ofstream file(filename);  // Membuka file untuk ditulis

    if () {
        cerr << "Gagal membuka file untuk menulis!" << endl;
        return;
    }

    file << "=== Data Investasi Perpustakaan ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nInvestasi ke-" << i + 1 << endl;
        cout << "Judul Buku     : " << judulBuku << endl;
        cout << "Jumlah Dana    : Rp." << danaInvestasi << endl;
        cout << "Tahun          : " << tahun << endl;
        cout << "-------------------------------\n";
    }

    cin.close();
    cout << "\nData berhasil disimpan ke file: " << filename << endl;
}

int main() {
    int jumlah;

    cout << "=== Program Investasi Perpustakaan ===\n";
    cout << "Masukkan jumlah data investasi: ";
    cin >> jumlah;

    // Alokasi memori dinamis
    Investasi dataInvestasi = new Investasi[jumlah];

    // Input data
    inputData(dataInvestasi, jumlah);

    // Simpan ke file
    string filename = "investasi_perpustakaan.txt";
    simpanKeFile(dataInvestasi, jumlah, filename);

    cout << "\nSilakan buka file \"" << filename << "\" secara manual.\n";

    // Bebaskan memori
    delete[] dataInvestasi;

    return 0;
}
