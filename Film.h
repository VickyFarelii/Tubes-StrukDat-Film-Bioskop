#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef struct elmFilm* adrFilm;
typedef struct elmJam* adrJam;

struct Film {
    int id;
    string judul;
    string genre;
    int durasi;
};

struct elmFilm {
    Film info;
    adrFilm next;
    adrJam firstJam;
};

struct elmJam {
    string jam;
    string studio;
    adrJam next;
};

struct ListFilm {
    adrFilm first;
};

void createListFilm_klp17(ListFilm &L);
adrFilm createElmFilm_klp17(Film x);
adrJam createElmJam_klp17(string jam, string studio);
void insertFilm_klp17(ListFilm &L, adrFilm p);
void insertJam_klp17(adrFilm pFilm, adrJam pJam);
adrFilm searchFilm_klp17(ListFilm L, int id);
void deleteFilm_klp17(ListFilm &L, int id);
void deleteJam_klp17(adrFilm pFilm, string jam);
void showJam_klp17(adrFilm pFilm);
void showAllFilm_klp17(ListFilm L);
int countFilm_klp17(ListFilm L);
int countJam_klp17(adrFilm pFilm);
void filmDurasiMax_klp17(ListFilm L, Film &maxF);
void filmDurasiMin_klp17(ListFilm L, Film &minF);
void searchByGenre_klp17(ListFilm L, string genre);
#endif // FILM_H_INCLUDED
