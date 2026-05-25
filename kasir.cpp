#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Struktur data untuk satu item belanja
struct Item {
    string namaBarang;
    int    jumlah;
    double hargaSatuan;
};

int main() {
    int n;
    cout << "=== KASIR KANTIN SEKOLAH ===" << endl;
    cout << "Masukkan jumlah jenis barang: ";
    cin  >> n;
    cin.ignore();

    Item barang[n];

    for (int i = 0; i < n; i++) {
        cout << "\nBarang ke-" << (i+1) << endl;
        cout << "  Nama barang  : ";
        getline(cin, barang[i].namaBarang);
        cout << "  Jumlah       : ";
        cin  >> barang[i].jumlah;
        cout << "  Harga satuan : Rp ";
        cin  >> barang[i].hargaSatuan;
        cin.ignore();
    }

    // Proses hitung total
    double totalBelanja = 0;

    cout << "\n--- STRUK BELANJA ---" << endl;
    cout << left << setw(18) << "Barang"
         << setw(5)  << "Qty"
         << setw(12) << "Harga"
         << "Subtotal" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < n; i++) {
        double subtotal = barang[i].jumlah * barang[i].hargaSatuan;
        totalBelanja   += subtotal;

        cout << left  << setw(18) << barang[i].namaBarang
             << setw(5)  << barang[i].jumlah
             << "Rp " << setw(8) << fixed
             << setprecision(0) << barang[i].hargaSatuan
             << "Rp " << subtotal << endl;
    }

    cout << string(45, '-') << endl;
    cout << "TOTAL BELANJA    : Rp "
         << fixed << setprecision(0) << totalBelanja << endl;

    // Input uang bayar & kembalian
    double uangBayar;
    cout << "Masukkan uang bayar : Rp ";
    cin  >> uangBayar;

    if (uangBayar < totalBelanja) {
        cout << "Uang tidak cukup!" << endl;
    } else {
        double kembalian = uangBayar - totalBelanja;
        cout << "Kembalian           : Rp " << kembalian << endl;
        cout << "Terima kasih!" << endl;
    }

    return 0;
}
