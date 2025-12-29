#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// typedef pointer
typedef struct elmGenre* adrGenre;
typedef struct elmFilm* adrFilm;

// ================= DATA =================
struct Film {
    int id;
    string judul;
    int durasi; // menit
};

// ================= NODE PARENT =================
struct elmGenre {
    string namaGenre;
    adrGenre next;
    adrFilm firstFilm;
};

// ================= NODE CHILD =================
struct elmFilm {
    Film info;
    adrFilm next;
};

// ================= LIST =================
struct ListGenre {
    adrGenre first;
};


void createListGenre(ListGenre &L);
adrGenre createElmGenre(string genre);
adrFilm createElmFilm(Film f);
void insertGenre(ListGenre &L, adrGenre p);
void insertFilm(adrGenre pGenre, adrFilm pFilm);
adrGenre searchGenre(ListGenre L, string genre);
void deleteFilm(adrGenre pGenre, int idFilm);
void showAll(ListGenre L);
void filmDurasiMax(ListGenre L, Film &maxF);
void filmDurasiMin(ListGenre L, Film &minF);

#endif // FILM_H_INCLUDED
