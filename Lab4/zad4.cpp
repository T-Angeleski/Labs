#include <iostream>
#include <cstring>

using namespace std;

enum zanr {akcija, komedija, drama};

class Film {
    char * ime;
    int size;
    zanr zanrFilm;

    public:
        Film(char * ime = " ", int size = 0, zanr zanrFilm = (zanr)0) {
            this->size = size;
            this->zanrFilm = zanrFilm;

            this->ime = new char [strlen(ime)+1];
            strcpy(this->ime, ime);
        }

        Film(const Film & other) {
            this->size = other.size;
            this->zanrFilm = other.zanrFilm;

            this->ime = new char [strlen(other.ime)+1];
            strcpy(this->ime, other.ime);
        }

        Film & operator=(const Film & other) {
            if( this != &other) {
                this->size = other.size;
                this->zanrFilm = other.zanrFilm;

                delete [] ime;

                this->ime = new char [strlen(other.ime)+1];
                strcpy(this->ime, other.ime);
            }
            return *this;
        }

        int getSize() {
            return size;
        }

        zanr getZanr() {
            return zanrFilm;
        }

        ~Film() {
            delete [] ime;
        }


        void pecati() {
            cout<<size<<"MB-\""<<ime<<"\""<<endl;
        }
};


class DVD {
    Film filmovi[5];
    int brFilmovi;
    int cap;

    public:
        DVD(int cap =0) {
            this->brFilmovi = 0;
            
            this->cap = cap;
        }

        DVD(const DVD & other) {
            this->brFilmovi = other.brFilmovi;
            this->cap = other.cap;

            for(int i = 0; i<brFilmovi; i++) {
                filmovi[i] = other.filmovi[i];
            }
        }

        DVD & operator=(const DVD & other) {
            if( this != &other) {
                this->brFilmovi = other.brFilmovi;
                this->cap = other.cap;

                for(int i = 0; i<brFilmovi; i++) {
                    filmovi[i] = other.filmovi[i];
                }
            }
            return *this;
        }

        ~DVD () {}

        Film getFilm(int i) {
            return filmovi[i];
        }

        int getBroj() {
            return brFilmovi;
        }

        void dodadiFilm(Film & f) {

            // nov < vkupno-zbir && pomalce od 5 filmovi
            int zbirSize = 0;
            for(int i = 0; i<brFilmovi; i++) {
                zbirSize += filmovi[i].getSize();
            }

            if( brFilmovi < 5 && (f.getSize() < cap - zbirSize)) {
                filmovi[brFilmovi++] = f;
            }
        }

        void pecatiFilmoviDrugZanr(zanr  z) {
            // koi ne se od toj zanr
            for(int i = 0; i< brFilmovi ;i++) {
                if(filmovi[i].getZanr() != z) {
                    filmovi[i].pecati();
                }
            }
        }

        float procentNaMemorijaOdZanr(zanr  z) {
            //zbir / vkupno * 100 // samo od toj zanr
            float procent = 0;
            for(int i = 0 ; i<brFilmovi; i++) {
                zanr filmZanr = filmovi[i].getZanr();
                if( filmZanr = z) {
                    procent += filmovi[i].getSize();
                }
            }

            procent = procent / this->cap * 100;

            return procent;

        }
};

int main() {

    Film f1;

    
    Film f2("Terminator", 20, (zanr)0);
    Film f3("Batman", 50, (zanr)1);

    Film f4(f3);
    Film f5;
    f5=f2;

    f1.pecati();
    f2.pecati();
    f3.pecati();
    f4.pecati();
    f5.pecati();
    
    return 0;
}