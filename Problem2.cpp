#include <iostream>
using namespace std;

int main() {
    char pesanAsli[100];
    cout << "Masukkan pesan asli (huruf kapital, tanpa spasi): ";
    cin >> pesanAsli;

    // Hitung panjang pesan secara manual (tanpa strlen dari library)
    int n = 0;
    while (pesanAsli[n] != '\0') {
        n++;
    }

    char hurufBaru[100];

    // Huruf pertama tidak mengalami perubahan
    hurufBaru[0] = pesanAsli[0];

    for (int i = 1; i < n; i++) {
        int nilaiAsliSekarang = pesanAsli[i] - 'A' + 1;       // A=1, ..., Z=26
        int nilaiAsliSebelumnya = pesanAsli[i - 1] - 'A' + 1; // PENTING: pakai huruf ASLI sebelumnya, bukan hasil sandi sebelumnya
        int nilaiBaru = nilaiAsliSekarang + nilaiAsliSebelumnya;

        // Jika hasil pergeseran melewati Z (26), putar kembali mulai dari A
        while (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }

        hurufBaru[i] = (char)('A' + nilaiBaru - 1);
    }

    hurufBaru[n] = '\0';

    cout << "Pesan tersandi: " << hurufBaru << endl;

    return 0;
}
