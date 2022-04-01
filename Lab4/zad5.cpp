#include <iostream>
#include <cstring>

using namespace std;

//Vasiot kod tuka
class Pica{
    char ime[15];
    int cena;
    char * sostojki;
    int namaluvanje;


    public:

        Pica(char* ime = "", int cena = 0, char * sostojki="", int namaluvanje=0) {

            strcpy(this->ime, ime);
            this->cena = cena;
            this->namaluvanje = namaluvanje;

            this->sostojki = new char [strlen(sostojki)+1];
            strcpy(this->sostojki, sostojki);
        }

        Pica(const Pica & other) {
            strcpy(this->ime, other.ime);
            this->cena = other.cena;
            this->namaluvanje = other.namaluvanje;

            this->sostojki = new char [strlen(other.sostojki)+1];
            strcpy(this->sostojki, other.sostojki);
        }

        Pica & operator=(const Pica & other) {
            if (this != &other) {
                strcpy(this->ime, other.ime);
                this->cena = other.cena;
                this->namaluvanje = other.namaluvanje;

                delete [] sostojki;

                this->sostojki = new char [strlen(other.sostojki)+1];
                strcpy(this->sostojki, other.sostojki);
            }
            return *this;
        }

        ~Pica() {
            delete [] sostojki;
        }

        int getCena() {
            return cena;
        }

        int getPopust() {
            return namaluvanje;
        }

        void pecati() {
            cout<<ime<<" - "<<sostojki<<", "<<cena;
        }

        bool istiSe(Pica & p) {
            return !strcmp(this->sostojki, p.sostojki);
        }

};


class Picerija{
    char imePicerija[15];
    Pica * pici;
    int brPici;

    public:
        Picerija(char * imePicerija = "") {
            
            strcpy(this->imePicerija, imePicerija);

            brPici = 0;
            pici = NULL;
        }

        Picerija(const Picerija & other) {
            strcpy(this->imePicerija, other.imePicerija);

            this->brPici = other.brPici;
            
            this->pici = new Pica[brPici];
            for (int i = 0; i < brPici; i++) {
                pici[i] = other.pici[i];
            }
            
        }

        Picerija & operator=(const Picerija & other) {
            if(this != &other) {
                strcpy(this->imePicerija, other.imePicerija);

                this->brPici = other.brPici;
                
                delete [] pici;

                this->pici = new Pica[brPici];
                for (int i = 0; i < brPici; i++) {
                    pici[i] = other.pici[i];
                }
            }
            return *this;
        }

        ~Picerija() {
            delete [] pici;
        }

        char * getIme() {
            return imePicerija;
        }
        void setIme(char * ime) {
            strcpy(imePicerija, ime);
        }

        void dodadi(Pica & other) {
            Pica * tmp = new Pica[brPici + 1];

            for(int i=0;i<brPici;i++) {
                if(pici[i].istiSe(other)) {
                    return;
                }
                tmp[i] = pici[i];
            }

            tmp[brPici++] = other;

            delete [] pici;

            pici = tmp;
        }

        void piciNaPromocija() {

             for(int i=0; i<brPici; i++) {
                if(pici[i].getPopust() != 0) {
                    int cenaPica = pici[i].getCena();
                    int popust = pici[i].getPopust();
                    int cenaPopust = cenaPica - (cenaPica * popust/100);

                    pici[i].pecati();
                    cout<<" "<<cenaPopust<<endl;
                }
                
            }
        }
};

int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();

	return 0;
}
