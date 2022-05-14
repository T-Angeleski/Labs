#include <iostream>
#include <cstring>
using namespace std;


class ZicanInstrument {
protected:
    char name[20];
    int numStrings;
    double price;

    public:
        ZicanInstrument(char *name = "", int numStrings = 0, double price = 0) {
            strcpy(this->name, name);
            this->numStrings = numStrings;
            this->price = price;
        }

        virtual double cena() =0;

        bool operator== (ZicanInstrument & z) {
            return numStrings == z.numStrings;
        }

        friend ostream& operator<< (ostream & out, ZicanInstrument & z) {
            out<<"test "<<z.name<<endl;
            return out;
        }
};

class Mandolina : public ZicanInstrument {
    char form[20];

    public:
        Mandolina(char *name = "", int numStrings = 0, double price = 0, char * form = "") : ZicanInstrument(name, numStrings, price) {
            strcpy(this->form, form);
        }

        double cena() {
            if (!strcmp(form, "Neapolitan")) {
                return price *1.15;
            }
            return price;
        }

        
};

class Violina : public ZicanInstrument {
    double size;

    public:
        Violina(char *name = "", int numStrings = 0, double price = 0, double size = 0) : ZicanInstrument(name, numStrings, price) {
            this->size = size;
        }

        double cena() {
            if(size == 0.25) {
                return price * 1.1;
            } else if(size == 1) {
                return price * 1.2;
            } else {
                return price;
            }
        }
};

void pecatiInstrumenti(ZicanInstrument &zi, ZicanInstrument **inst, int n) {
    
    for(int i = 0 ; i < n ; i++) {
        if(*inst[i] == zi) {
            cout<<inst[i];
        }
    }
}