#include <iostream>
#include <cstring>

using namespace std;

enum zanr {
    akcija,
    komedija,
    drama
};

class Film {
    char * ime;
    int size;
    zanr tipZanr;

    public:
        Film() {
            strcpy(ime, " ");
            size=0;
            tipZanr = (zanr)0;
        }

        Film(char * ime, int size, zanr tipZanr) {
            this->size = size;
            this->tipZanr = tipZanr;

            this->ime = new char[strlen(ime)+ 1];
            strcpy(this->ime, ime);
        }

        Film(const Film & other) {
            this->size = other.size;
            this->tipZanr = other.tipZanr;

            this->ime = new char[strlen(other.ime)+ 1];
            strcpy(this->ime, other.ime);
        }

        Film& operator=(const Film & other) {
            if (this != &other) {
                this->size = other.size;
                this->tipZanr = other.tipZanr;

                delete [] ime;
                this->ime = new char[strlen(other.ime)+ 1];
                strcpy(this->ime, other.ime);
            }
            return *this;
        }

        ~Film() {
            delete [] ime;
        }

        void pecati() {
            cout<<size<<"MB-"<<"\""<<ime<<"\""<<endl;
        }

        int getCapacity() {
            return size;
        }

        zanr getZanr() {
            return tipZanr;
        }

        friend class DVD;
};

class DVD {
    Film filmovi[5];
    int brFilmovi;
    int capacity; //vo MB

    public:
        DVD() {
            brFilmovi = 0;
            capacity = 0;
        }

        DVD(int brFilmovi):DVD() {
            this->brFilmovi = brFilmovi;
        }

        DVD(const DVD & other) {
            this->brFilmovi = other.brFilmovi;
            this->capacity = other.capacity;

            
            for (int i = 0; i < 5; i++) {
                this->filmovi[i] = other.filmovi[i];
            }
        }

        DVD& operator=(const DVD & other) {
            if(this!= &other) {
                this->brFilmovi = other.brFilmovi;
                this->capacity = other.capacity;

                
                for (int i = 0; i < 5; i++) {
                    this->filmovi[i] = other.filmovi[i];
                }
            }
            return *this;
        }
        

        Film& getFilm(int n) {
            return filmovi[n];
        }

        
        int getBroj() {
            return brFilmovi;
        }
        

        void dodadiFilm(Film f) {
            int memorija =0;
            for(int i=0;i<brFilmovi;i++) {
                memorija += filmovi[i].getCapacity();
            }

            int preostanatoMem = capacity - memorija;

            if((brFilmovi < 5) && (f.size < preostanatoMem)) {
                filmovi[brFilmovi] = f;
                brFilmovi++;
            }
        }

        void pecatiFilmoviDrugZanr(zanr r) {
            for(int i=0; i<brFilmovi; i++) {
                if(filmovi[i].getZanr() != r) {
                    filmovi[i].pecati();
                }
            }
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