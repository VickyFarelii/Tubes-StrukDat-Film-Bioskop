#include <iostream>
#include "Film.h"

using namespace std;

int main() {
    ListFilm L;
    createListFilm_klp17(L);

    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n=====================================\n";
        cout << "        SISTEM FILM BIOSKOP\n";
        cout << "=====================================\n";
        cout << "1. Tambah Data Film\n";
        cout << "2. Tambah Jam Tayang Film\n";
        cout << "3. Tampilkan Semua Film\n";
        cout << "4. Cari Film\n";
        cout << "5. Hapus Film\n";
        cout << "6. Film dengan Durasi Terpendek\n";
        cout << "7. Film dengan Durasi Terpanjang\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            Film f;
            cout << "ID Film       : ";
            cin >> f.id;
            cout << "Judul         : ";
            cin >> f.judul;
            cout << "Genre         : ";
            cin >> f.genre;
            cout << "Durasi(menit) : ";
            cin >> f.durasi;

            adrFilm p = createElmFilm_klp17(f);
            insertFilm_klp17(L, p);
        }
        else if (pilihan == 2) {
            int id;
            cout << "ID Film: ";
            cin >> id;

            adrFilm pFilm = searchFilm_klp17(L, id);
            if (pFilm != nullptr) {
                string jam, studio;
                cout << "Jam Tayang: ";
                cin >> jam;
                cout << "Studio    : ";
                cin >> studio;

                adrJam pJam = createElmJam_klp17(jam, studio);
                insertJam_klp17(pFilm, pJam);
            } else {
                cout << "Film tidak ditemukan.\n";
            }
        }
        else if (pilihan == 3) {
            showAllFilm_klp17(L);
        }
        else if (pilihan == 4) {
            string g;
            cout << "Masukkan Genre yang dicari: ";
            cin >> g;
            searchByGenre_klp17(L, g);
        }
        else if (pilihan == 5) {
            int id;
            cout << "ID Film yang dihapus: ";
            cin >> id;
            deleteFilm_klp17(L, id);
        }
        else if (pilihan == 6) {
            if (L.first == nullptr) {
                cout << "Data film masih kosong.\n";
            } else {
                Film minF;
                filmDurasiMin_klp17(L, minF);

                cout << "=== FILM DURASI TERPENDEK ===\n";
                cout << "ID     : " << minF.id << endl;
                cout << "Judul  : " << minF.judul << endl;
                cout << "Genre  : " << minF.genre << endl;
                int jam = minF.durasi / 60;
                int menit = minF.durasi % 60;
                cout << "Durasi : " << jam << " jam " << menit << " menit\n";
            }
        }
        else if (pilihan == 7) {
            if (L.first == nullptr) {
                cout << "Data film masih kosong.\n";
            } else {
                Film maxF;
                filmDurasiMax_klp17(L, maxF);

                cout << "=== FILM DURASI TERPANJANG ===\n";
                cout << "ID     : " << maxF.id << endl;
                cout << "Judul  : " << maxF.judul << endl;
                cout << "Genre  : " << maxF.genre << endl;
                int jam = maxF.durasi / 60;
                int menit = maxF.durasi % 60;
                cout << "Durasi : " << jam << " jam " << menit << " menit\n";
            }
        }
    }

    cout << "Program selesai.\n";
    return 0;
}
