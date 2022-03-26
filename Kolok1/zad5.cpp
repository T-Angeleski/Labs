#include <iostream>
#include <cstring>
using namespace std;

class Gitara {
    char serialNumber[25];
    float price;
    int year;
    char type[40];

    public:
        //Argument default const
        Gitara(char *type=" ", char *serialNumber=" ",int year=2002, float price=0.0 ) {
            strcpy(this->serialNumber, serialNumber);
            strcpy(this->type, type);
            this->price = price;
            this->year = year;
        }

        //Copy const
        Gitara(const Gitara & other) {
            strcpy(this->serialNumber, other.serialNumber);
            strcpy(this->type, other.type);
            this->price = other.price;
            this->year = other.year;
        }

        //Operator=
        Gitara& operator=(const Gitara & other) {
            if(this != &other) {
                strcpy(this->serialNumber, other.serialNumber);
                strcpy(this->type, other.type);
                this->price = other.price;
                this->year = other.year;
            }
            return *this;
        }

        ~Gitara() {}



        char * getTip() {
            return type;
        }

        char * getSeriski() {
            return serialNumber;
        }

        int getGodina() {
            return year;
        }

        float getNabavna() {
            return price;
        }

        bool daliIsti(Gitara other) {
            return !strcmp(this->serialNumber, other.serialNumber);
        }

        void pecati() {
            cout<<serialNumber<<" "<<type<<" "<<price<<endl;
        }
};

class Magacin {
    Gitara * guitars;
    char name[30];
    char location[60];
    int numGuitars;
    int yearOpening;

    public:
        Magacin(char * name=" ", char* location=" ", int yearOpening=0) {
            strcpy(this->name, name);
            strcpy(this->location, location);

            this->yearOpening = yearOpening;
            numGuitars = 0;

            guitars = NULL; // ???
        }

        Magacin(const Magacin & other) {
            strcpy(this->name, other.name);
            strcpy(this->location, other.location);

            this->yearOpening = other.yearOpening;
            

            guitars = new Gitara [other.numGuitars];
            for (int i = 0; i < other.numGuitars; i++) {
                guitars[i] = other.guitars[i];
            }
            numGuitars = other.numGuitars;
        }

        Magacin& operator=(const Magacin & other) {
            if (this!= &other) {
                strcpy(this->name, other.name);
                strcpy(this->location, other.location);

                this->yearOpening = other.yearOpening;
                

                delete [] guitars;

                this->guitars = new Gitara [other.numGuitars];
                for (int i = 0; i < other.numGuitars; i++) {
                    guitars[i] = other.guitars[i];
                
                }
                numGuitars = other.numGuitars;
            }
            return *this;
        }

        ~Magacin() {
            delete [] guitars;
        }

        double vrednost() {
            double vrednost =0;

            for (int i = 0; i < numGuitars; i++) {
                vrednost += guitars[i].getNabavna();
            }

            return vrednost;
        }

        void dodadi(Gitara &other) {
            //Napolni nova privremena niza od gitari
            Gitara *tmp = new Gitara [numGuitars +1];
            for(int i=0;i<numGuitars;i++) {
                tmp[i] = guitars[i];
            }

            //Dodadi novata vo tmp
            tmp[numGuitars++] = other;

            delete [] guitars;
            //Stavi tmp vo main niza
            guitars = tmp;
        }



        void prodadi(Gitara &other) {
            int newCount =0;
            int j=0;

            for(int i=0; i<numGuitars; i++) {
                if(guitars[i].daliIsti(other)==0) {
                    newCount++;
                }
            }

            Gitara * tmp = new Gitara[newCount];

            for(int i=0; i<numGuitars; i++) {
                if(guitars[i].daliIsti(other)==0) {
                    tmp[j] = guitars[i];
                    j++;
                }
            }

            delete [] guitars;
            guitars = tmp;
        
            numGuitars = newCount;
        }

        void pecati(bool daliNovi) {
            cout<<name<<" "<<location<<endl;
            
            // samo gitari koi imaat god ponova od god na otvaranje magacin
    

            for(int i=0 ; i<numGuitars; i++) {
                
                if(daliNovi) {
                    // true
                    if(guitars[i].getGodina() > yearOpening) {
                        guitars[i].pecati();
                    }
                } else {
                    guitars[i].pecati();
                }
            }
        }
};

int main() {
    return 0;
}