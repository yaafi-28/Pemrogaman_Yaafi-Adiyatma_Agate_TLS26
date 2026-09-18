# Tugas Pemrograman Dasar

Repository ini berisi penyelesaian tugas pemrograman dasar yang terdiri dari 2 fase: perancangan logika (pseudocode & flowchart) dan implementasi program dalam bahasa C++.

## Daftar Isi
- [Problem 1: The Last Astronaut](#problem-1-the-last-astronaut)
- [Problem 2: Alien-In-The-Middle](#problem-2-alien-in-the-middle)
- [Struktur Repository](#struktur-repository)
- [Cara Menjalankan Program](#cara-menjalankan-program)

---

## Fase 1: Pseudocode & Flowchart

Fase ini berisi rancangan logika penyelesaian masalah dari kedua problem dalam bentuk pseudocode dan flowchart, dikumpulkan dalam satu file PDF (`Fase1_Pseudocode_Flowchart.pdf`).

### Problem 1: The Last Astronaut

**Deskripsi Masalah:**
Sejumlah N astronot berdiri melingkar dan diberi nomor 1 hingga N. Dimulai dari astronot nomor 1, dilakukan penghitungan sebanyak K langkah secara melingkar; astronot yang terkena hitungan ke-K akan dieliminasi. Proses hitungan berikutnya dimulai dari astronot yang berada tepat setelah astronot yang baru saja dieliminasi.

Nilai K bersifat dinamis dan berubah setiap kali terjadi eliminasi, dengan aturan:
1. Jika nomor astronot yang dieliminasi genap → K bertambah 2.
2. Jika nomor astronot yang dieliminasi ganjil → K berkurang 1.
3. Nilai K tidak boleh kurang dari 2 (jika hasil perubahan < 2, maka K = 2).

Proses berulang hingga tersisa satu astronot, yang dinyatakan sebagai pemenang.

**Pendekatan Penyelesaian:**
- Astronot direpresentasikan sebagai array/list berisi nomor 1 sampai N.
- Posisi astronot yang dieliminasi pada tiap putaran dihitung dengan rumus melingkar: `(posisiSekarang + K - 1) mod ukuranSekarang`.
- Setelah astronot dieliminasi (dihapus dari list), posisi awal hitungan berikutnya otomatis menjadi posisi tempat astronot yang dieliminasi tadi berada (karena elemen setelahnya bergeser mengisi posisi tersebut).
- Nilai K diperbarui sesuai aturan genap/ganjil dan dibatasi minimum 2 setiap selesai satu putaran eliminasi.

### Problem 2: Alien-In-The-Middle

**Deskripsi Masalah:**
Sebuah alien menyamar sebagai astronot dan berkomunikasi menggunakan sistem sandi rahasia. Setiap huruf pesan diubah menjadi huruf baru berdasarkan posisinya di alfabet (A=1, B=2, ..., Z=26). Huruf pertama pada pesan tidak mengalami perubahan. Untuk huruf berikutnya, nilai barunya dihasilkan dari **penjumlahan nilai posisi huruf tersebut dengan nilai posisi huruf asli sebelumnya** dalam pesan. Jika hasil penjumlahan melebihi 26, maka nilai tersebut dikurangi 26 (berputar kembali mulai dari A).

Contoh: pesan `ALIENS` akan disandikan menjadi `AMUNSG`.

**Pendekatan Penyelesaian:**
- Huruf pertama pesan disalin langsung ke huruf hasil sandi.
- Untuk setiap huruf berikutnya, nilai posisinya dijumlahkan dengan nilai posisi huruf **asli** (bukan huruf hasil sandi) yang berada tepat sebelumnya dalam pesan.
- Jika hasil penjumlahan lebih dari 26, dilakukan pengurangan 26 secara berulang hingga nilainya berada pada rentang 1–26.
- Nilai hasil dikonversi kembali menjadi huruf sesuai posisinya di alfabet.

---

## Fase 2: Implementasi C++

Fase ini berisi implementasi solusi kedua problem dalam bahasa C++, dengan ketentuan:
- Hanya menggunakan library `iostream`.
- Tidak menggunakan function bawaan dari library lain — seluruh fungsi/logika (perhitungan panjang string, konversi huruf ke angka, dan sebagainya) dibuat secara manual (*user-defined*).

| File | Deskripsi |
|---|---|
| `problem1_last_astronaut.cpp` | Implementasi simulasi eliminasi astronot dengan nilai K dinamis |
| `problem2_alien_cipher.cpp` | Implementasi sistem penyandian pesan alien |

---

## Struktur Repository

```
├── Fase1_Pseudocode_Flowchart.pdf
├── problem1_last_astronaut.cpp
├── problem2_alien_cipher.cpp
└── README.md
```

---

## Cara Menjalankan Program

1. Compile program menggunakan compiler C++ (contoh menggunakan g++):
   ```
   g++ problem1_last_astronaut.cpp -o problem1
   g++ problem2_alien_cipher.cpp -o problem2
   ```

2. Jalankan program:
   ```
   ./problem1
   ./problem2
   ```

3. Masukkan input sesuai permintaan program:
   - **Problem 1:** jumlah astronot (N) dan nilai awal K.
   - **Problem 2:** pesan asli dalam huruf kapital tanpa spasi (contoh: `ALIENS`).



Input  : ALIENS
Output : AMUNSG
```
