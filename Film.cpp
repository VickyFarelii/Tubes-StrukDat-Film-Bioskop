#include "Film.h"
void createListFilm_klp17(ListFilm &L) {
    L.first = nullptr;
}

adrFilm createElmFilm_klp17(Film x) {
    adrFilm p = new elmFilm;
    p->info = x;
    p->next = nullptr;
    p->firstJam = nullptr;
    return p;
}

adrJam createElmJam_klp17(string jam, string studio) {
    adrJam p = new elmJam;
    p->jam = jam;
    p->studio = studio;
    p->next = nullptr;
    return p;
}

void insertFilm_klp17(ListFilm &L, adrFilm p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        adrFilm q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

void insertJam_klp17(adrFilm pFilm, adrJam pJam) {
    if (pFilm->firstJam == nullptr) {
        pFilm->firstJam = pJam;
    } else {
        adrJam q = pFilm->firstJam;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = pJam;
    }
}

adrFilm searchFilm_klp17(ListFilm L, int id) {
    adrFilm p = L.first;
    while (p != nullptr) {
        if (p->info.id == id) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void searchByGenre_klp17(ListFilm L, string genre) {
    adrFilm p = L.first;
    bool found = false;

    cout << "\n--- Hasil Pencarian Genre: " << genre << " ---\n";
    while (p != nullptr) {
        if (p->info.genre.find(genre) != -1) {
            found = true;
            cout << "====================================" << endl;
            cout << "ID Film    : " << p->info.id << endl;
            cout << "Judul      : " << p->info.judul << endl;
            cout << "Genre      : " << p->info.genre << endl;

            int jam = p->info.durasi / 60;
            int menit = p->info.durasi % 60;
            cout << "Durasi     : " << jam << " jam " << menit << " menit" << endl;

            cout << "Jadwal Tayang:" << endl;
            showJam_klp17(p);
        }
        p = p->next;
    }

    if (!found) {
        cout << "Tidak ada film dengan genre '" << genre << "'." << endl;
    }
    cout << "====================================" << endl;
}

void deleteFilm_klp17(ListFilm &L, int id) {
    adrFilm p = L.first;
    adrFilm prev = nullptr;

    while (p != nullptr) {
        if (p->info.id == id) {
            if (prev == nullptr) {
                L.first = p->next;
            } else {
                prev->next = p->next;
            }

            adrJam c = p->firstJam;
            while (c != nullptr) {
                adrJam temp = c;
                c = c->next;
                delete temp;
            }

            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}

void deleteJam_klp17(adrFilm pFilm, string jam) {
    adrJam p = pFilm->firstJam;
    adrJam prev = nullptr;

    while (p != nullptr) {
        if (p->jam == jam) {
            if (prev == nullptr) {
                pFilm->firstJam = p->next;
            } else {
                prev->next = p->next;
            }
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}

void showJam_klp17(adrFilm pFilm) {
    adrJam p = pFilm->firstJam;
    if (p == nullptr) {
        cout << "   (Tidak ada jadwal tayang)" << endl;
    } else {
        while (p != nullptr) {
            cout << "   - Jam: " << p->jam
                 << " | Studio: " << p->studio << endl;
            p = p->next;
        }
    }
}

void showAllFilm_klp17(ListFilm L) {
    adrFilm p = L.first;
    if (p == nullptr) {
        cout << "List film kosong." << endl;
        return;
    }

    while (p != nullptr) {
        cout << "====================================" << endl;
        cout << "ID Film   : " << p->info.id << endl;
        cout << "Judul     : " << p->info.judul << endl;
        cout << "Genre     : " << p->info.genre << endl;

        int jam = p->info.durasi / 60;
        int menit = p->info.durasi % 60;
        cout << "Durasi    : " << jam << " jam " << menit << " menit" << endl;

        cout << "Jadwal Tayang:" << endl;
        showJam_klp17(p);
        p = p->next;
    }
    cout << "====================================" << endl;
}


int countFilm_klp17(ListFilm L) {
    int count = 0;
    adrFilm p = L.first;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

int countJam_klp17(adrFilm pFilm) {
    int count = 0;
    adrJam p = pFilm->firstJam;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void filmDurasiMax_klp17(ListFilm L, Film &maxF) {
    if (L.first == nullptr){
        return;
    }

    adrFilm p = L.first;
    maxF = p->info;

    while (p != nullptr) {
        if (p->info.durasi > maxF.durasi) {
            maxF = p->info;
        }
        p = p->next;
    }
}

void filmDurasiMin_klp17(ListFilm L, Film &minF) {
    if (L.first == nullptr){
        return;
    }

    adrFilm p = L.first;
    minF = p->info;

    while (p != nullptr) {
        if (p->info.durasi < minF.durasi) {
            minF = p->info;
        }
        p = p->next;
    }
}
