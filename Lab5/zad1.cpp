#include <iostream>
#include <cstring>
using namespace std;

class Automobile {
    char * marka;
    int * registracija;
    int brzina;

    void copy(const Automobile & other) {
        this->marka = new char [strlen(other.marka)+1];
        strcpy(this->marka, other.marka);

        this->registracija = new int [5];
        for(int i = 0 ; i < 5 ; i++) {
                this->registracija[i] = other.registracija[i];
            }
        this->brzina = other.brzina;
    }

    public:
        Automobile() =default;
        Automobile(char * marka, int * registracija, int brzina) {
            this->marka = new char [strlen(marka)+1];
            strcpy(this->marka, marka);

            this->registracija = new int [5];
            for(int i = 0 ; i < 5 ; i++) {
                this->registracija[i] = registracija[i];
            }
            this->brzina = brzina;
        }

        Automobile(const Automobile & a) {
            copy(a);
        }

        Automobile& operator= (const Automobile & a) {
            if( this != &a) {
                delete [] marka;
                delete [] registracija;
                copy(a);
            }
            return *this;
        }

        ~Automobile() {
            delete [] marka;
            delete [] registracija;
        }

        int getBrzina() {
            return brzina;
        }

        bool operator== (Automobile & a) {
            for(int i = 0 ; i < 5 ; i++) {
                if(registracija[i] != a.registracija[i]) {
                    return false;
                }
            }
            return true;
        }

        // Marka:име Registracija:[x y z k l]
        friend ostream & operator<<(ostream & out, Automobile & a) {
            out<<"Marka\t"<<a.marka<<"\tRegistracija[ ";
            for(int i = 0 ; i < 5 ; i++) {
                out<<a.registracija[i]<<" ";
            }
            out<<"]"<<endl;
            return out;
        }
};

class RentACar {
    char ime[100];
    Automobile * koli;
    int num;

    void copy(const RentACar & other) {
        strcpy(this->ime, other.ime);
        this->num = other.num;
        for( int i = 0 ; i < other.num ; i++) {
            koli[i] = other.koli[i];
        }
    }

    public:
        RentACar(char *ime= "") {
            strcpy(this->ime, ime);
            koli = new Automobile [0];
            num = 0;
        }

        RentACar(const RentACar & r) {
            copy(r);
        }

        RentACar& operator=(const RentACar & r) {
            if( this!= &r) {
                delete [] koli;
                copy(r);
            }
            return *this;
        }

        ~RentACar() {
            delete [] koli;
        }


        RentACar& operator+=(const Automobile & r) {
            Automobile * tmp = new Automobile[num+1];

            for(int i = 0 ;i < num ; i++) {
                tmp[i] = koli[i];
            }

            tmp[num++] = r;

            delete [] koli;

            koli = tmp;

            return *this; // novoto
        }


        //-= за отстранување на даден автомобил од агенцијата (оној со иста регистрација). 
        RentACar& operator -= (Automobile & a) {
            Automobile * tmp = new Automobile[num];

            int brojac=0; 

            for(int i = 0 ; i < num ; i++) {
                if(!(koli[i] == a)) {
                    tmp[brojac++] = koli[i];
                }
            }

            num = brojac;
            delete [] koli;
            koli = tmp;

            return *this;
        }


        void pecatiNadBrzina(int max) {
            cout<<ime<<endl;
            for(int i = 0 ; i < num ; i++) {
                if(koli[i].getBrzina() > max) {
                    cout<<koli[i];
                }
            }
        }
};

int main()
{
   RentACar agencija("FINKI-Car");
   int n;
   cin>>n;
    
   for (int i=0;i<n;i++)
   {
    	char marka[100];
    	int regisracija[5];
    	int maximumBrzina;
    
       	cin>>marka;
    
       	for (int i=0;i<5;i++)
    		cin>>regisracija[i];
    
    	cin>>maximumBrzina;
    
       	Automobile nov=Automobile(marka,regisracija,maximumBrzina);
       
    	//dodavanje na avtomobil
       	agencija+=nov;   
       
   }
    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin>>marka;
    for (int i=0;i<5;i++)
    cin>>regisracija[i];
    cin>>maximumBrzina;
    
    Automobile greshka=Automobile(marka,regisracija,maximumBrzina);
    
    //brishenje na avtomobil
    agencija-=greshka;
    
    agencija.pecatiNadBrzina(150);
    
    return 0;
}