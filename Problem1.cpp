#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    // Buat array astronot berisi 1..N (dialokasikan manual, bukan library container)
    int* astronaut = new int[N];
    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }

    int ukuran = N;
    int indexSekarang = 0;

    int* urutanEliminasi = new int[N];
    int jumlahEliminasi = 0;

    while (ukuran > 1) {
        // Tentukan siapa yang tereliminasi (hitungan ke-K dari posisi sekarang, melingkar)
        int indexEliminasi = (indexSekarang + K - 1) % ukuran;
        int astronotTereliminasi = astronaut[indexEliminasi];

        urutanEliminasi[jumlahEliminasi] = astronotTereliminasi;
        jumlahEliminasi++;

        // Hapus elemen di indexEliminasi: geser semua elemen setelahnya ke kiri
        for (int i = indexEliminasi; i < ukuran - 1; i++) {
            astronaut[i] = astronaut[i + 1];
        }
        ukuran--;

        // Update nilai K sesuai aturan genap/ganjil
        if (astronotTereliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        // Nilai K tidak boleh kurang dari 2
        if (K < 2) {
            K = 2;
        }

        // Tentukan titik awal hitungan berikutnya
        if (ukuran > 0) {
            indexSekarang = indexEliminasi % ukuran;
        }
    }

    cout << "\nUrutan eliminasi: ";
    for (int i = 0; i < jumlahEliminasi; i++) {
        cout << urutanEliminasi[i];
        if (i < jumlahEliminasi - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Astronot terakhir yang bertahan: " << astronaut[0] << endl;

    delete[] astronaut;
    delete[] urutanEliminasi;

    return 0;
}
