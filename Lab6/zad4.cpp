#include <iostream>
#include <cstring>
using namespace std;

class Nedviznina {
protected:
    char * adress;
    int squares;
    int price;

    void copy (const Nedviznina & other) {
        this->adress = new char [strlen(other.adress)+1];
        strcpy(this->adress, other.adress);

        this->squares = other.squares;
        this->price = other.price;
    }

    public:
        Nedviznina(char * adress = "", int squares = 0, int price = 0) {
            this->adress = new char [strlen(adress)+1];
            strcpy(this->adress, adress);

            this->squares = squares;
            this->price = price;
        }

        Nedviznina(const Nedviznina & n) {
            copy(n);
        }

        Nedviznina& operator= (const Nedviznina & n) {
            if(this != &n ){
                delete [] adress;
                copy(n);
            }
            return *this;
        }

        ~Nedviznina() {
            delete [] adress;
        }

        char* getAdresa() {
            return adress;
        }

        int cena() {
            return squares * price;
        }

        double danokNaImot() {
            return cena() * 0.05; 
        }

        void pecati() {
            cout<<adress<<", Kvadratura: "<<squares<<", Cena po Kvadrat: "<<price<<endl;
        }

        friend istream& operator>> (istream & in, Nedviznina & n) {
            in>>n.adress>>n.squares>>n.price;
            return in;
        }
};

class Vila : public Nedviznina {
    int tax;

    public:
        Vila() : Nedviznina() {
            tax = 0;
        }

        friend istream& operator>> (istream & in, Vila & v){
            in>>v.adress>>v.squares>>v.price>>v.tax;
            return in;
        }

        double danokNaImot() {
            return cena() * (tax + 5) / 100.0;
        }

        void pecati() {
            cout<<adress<<", Kvadratura: "<<squares<<", Cena po Kvadrat: "<<price<<", Danok na luksuz: "<<tax<<endl;
        }
};