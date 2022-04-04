#include <iostream>
#include <cstring>

using namespace std;

enum Tip {LINUX, UNIX, WINDOWS};

class OperativenSistem {
    char * imeOS;
    float version;
    Tip typeOS;
    float size;

    void copy(const OperativenSistem & other) {
            this->version = other.version;
            this->size = other.size;
            this->typeOS = other.typeOS;

            this->imeOS = new char [strlen(other.imeOS)+1];
            strcpy(this->imeOS, other.imeOS);
    }

    public:
        OperativenSistem(char * imeOS = "", float version = 0, Tip typeOS = (Tip)0, float size = 0) {
            this->version = version;
            this->size = size;
            this->typeOS = typeOS;

            this->imeOS = new char [strlen(imeOS)+1];
            strcpy(this->imeOS, imeOS);
        }

        OperativenSistem(const OperativenSistem & os) {
            copy(os);
        }

        OperativenSistem& operator=(const OperativenSistem & os) {
            if(this != &os) {
                delete [] imeOS;
                copy(os);
            }
            return *this;
        }

        ~OperativenSistem () {
            delete [] imeOS;
        }

        void pecati() {
            cout<<"Ime: "<<imeOS<<" Verzija: "
            <<version<<" Tip: "<<typeOS<<" Golemina:"<<size<<"GB"<<endl;
        }

        bool ednakviSe(const OperativenSistem & os) {
            if( !strcmp(imeOS, os.imeOS)) 
                if(version == os.version) 
                    if( typeOS == os.typeOS) 
                        if(size == os.size) 
                            return true;
            return false;
        }

        int sporediVerzija(const OperativenSistem & other) {
            if(version == other.version) {
                return 0;
            } else if (version < other.version) {
                return -1;
            } else {
                return 1;
            }
        }

        bool istaFamiliija(const OperativenSistem & other) {
            return ( (!strcmp(imeOS, other.imeOS)) && (typeOS == other.typeOS) );
        }

        
};

class Repozitorium {
    char imeRepo[20];
    OperativenSistem * sistemi;
    int brSistemi;

    void copy(const Repozitorium & other) {
        strcpy(this->imeRepo, other.imeRepo);

        this->brSistemi = other.brSistemi;
        for(int i = 0 ; i < brSistemi ; i++) {
            sistemi[i] = other.sistemi[i];
        }
    }

    public:
        Repozitorium(char * imeRepo = "") {
            strcpy(this->imeRepo, imeRepo);

            brSistemi = 0;
            sistemi = new OperativenSistem [brSistemi];
        }

        Repozitorium(const Repozitorium & r) {
            copy(r);
        }

        Repozitorium& operator=(const Repozitorium & r) {
            if(this != &r) {
                delete [] sistemi;
                copy(r);
            }
            return *this;
        }

        ~Repozitorium () {
            delete [] sistemi;
        }

        void pecatiOperativniSistemi() {
            cout<<"Repozitorium: "<<imeRepo<<endl;

            for( int i = 0 ; i < brSistemi ; i++) {
                sistemi[i].pecati();
            }
        }


        void dodadi(const OperativenSistem & nov) {
            
            OperativenSistem * tmp = new OperativenSistem[brSistemi+1];

            for ( int i = 0 ; i < brSistemi ; i++) {
                if( sistemi[i].istaFamiliija(nov) && sistemi[i].sporediVerzija(nov)) {
                    sistemi[i] = nov;
                    return;
                }
                tmp[i] = sistemi[i];
            }

            tmp[brSistemi++] = nov;

            delete [] sistemi;

            sistemi = tmp;
        }

        void izbrishi(const OperativenSistem &os) {
            for (int i = 0; i < brSistemi; i++)
                if (this->sistemi[i].ednakviSe(os))
                {
                    for (int j = i; j < brSistemi - 1; j++)
                        this->sistemi[j] = sistemi[j + 1];

                    brSistemi--;
                    break;
                }
        }
};


int main() {
    char repoName[20];
        cin>>repoName;
        Repozitorium repozitorium=Repozitorium(repoName);
        int brojOperativniSistemi = 0;
        cin>>brojOperativniSistemi;
        char ime[20];
        float verzija;
        int tip;
        float golemina;
        for (int i = 0; i<brojOperativniSistemi; i++){
            cin>>ime;
            cin>>verzija;
            cin>>tip;
            cin>>golemina;
            OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
            repozitorium.dodadi(os);
        }

        repozitorium.pecatiOperativniSistemi();
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        cout<<"=====Brishenje na operativen sistem====="<<endl;
        repozitorium.izbrishi(os);
        repozitorium.pecatiOperativniSistemi();
    return 0;
}