# 🎬 Cinema Management System (Multi-Linked List)
**Tugas Besar Struktur Data - Kelompok 17**

Sistem manajemen data film bioskop berbasis terminal yang diimplementasikan menggunakan struktur data **Multi-Linked List (MLL)** dengan relasi **1-N (One-to-Many)**. Program ini memungkinkan pengelolaan data film sebagai *Parent* dan jadwal tayang sebagai *Child*.

---

## 🚀 Fitur Utama

- **Manajemen Film (Parent):** Tambah data film baru (Insert Last), hapus data film beserta seluruh jadwal tayangnya (Cascading Delete), dan tampilkan seluruh koleksi film.
- **Manajemen Jadwal (Child):** Menambahkan jam tayang dan studio ke film spesifik menggunakan ID, serta menghapus jadwal tertentu tanpa menghapus data film.
- **Pencarian Pintar (Smart Search):** Cari film berdasarkan **Genre** dengan fitur *substring search* (mencari potongan kata).
- **Analisis Data:** Menemukan film dengan durasi terpanjang dan terpendek secara otomatis.

---

## 🛠️ Struktur Data

Program ini menggunakan konsep **Multi-Linked List** dengan variasi Parent-Child:
1. **Parent (`elmFilm`):** Menyimpan atribut ID, Judul, Genre, dan Durasi.
2. **Child (`elmJam`):** Menyimpan atribut Jam Tayang dan Nama Studio.
3. **Pointer Relasi:** Setiap node Film memiliki pointer `firstJam` yang menghubungkannya ke daftar jam tayang yang dimiliki film tersebut.

---

## 📁 Struktur File

- `Film.h`: Header file yang berisi deklarasi struct dan prototipe fungsi.
- `Film.cpp`: Implementasi dari seluruh fungsi dan prosedur (Logic).
- `main.cpp`: Menu utama dan interaksi pengguna.

---

## 💻 Cara Menjalankan

1. **Clone Repositori:**
   ```bash
   git clone [https://github.com/username-kamu/nama-repo.git](https://github.com/username-kamu/nama-repo.git)
   cd nama-repo
