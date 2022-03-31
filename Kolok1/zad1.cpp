#include <iostream>
#include <cstring>
using namespace std;

enum tip {POP, RAP, ROCK};

class Pesna {
    char * ime;
    int vreme;
    tip tipPesna;

    void copy(const Pesna & other) {
        this->vreme = other.vreme;
        this->tipPesna = other.tipPesna;

        this->ime =  new char [strlen(other.ime)+1];
        strcpy(this->ime, other.ime);
    }

    public:
        Pesna(char * ime = " ", int vreme =0, tip tipPesna = (tip)0) {
            this->vreme = vreme;
            this->tipPesna = tipPesna;

            this->ime =  new char [strlen(ime)+1];
            strcpy(this->ime, ime);
        }

        Pesna(const Pesna & p) {
            copy(p);
        }

        Pesna & operator=(const Pesna & p) {
            if( this!= &p) {
                delete [] ime;
                copy(p);
            }
            return *this;
        }

        ~Pesna() {
            delete [] ime;
        }

        int getVreme() {
            return vreme;
        }

        tip getTip() {
            return tipPesna;
        }

        void pecati() {
            cout<<"\""<<ime<<"\"-"<<vreme<<"min"<<endl;
        }
};

class CD {
    Pesna pesni[10];
    int brPesni;
    int maxVreme;

    void copy(const CD & other) {
        this->maxVreme = other.maxVreme;
        this->brPesni = other.brPesni;

        for(int i=0; i< brPesni; i++) {
            this->pesni[i] = other.pesni[i];
        }
    }

    public:
        CD(int maxVreme = 0) {
            brPesni = 0;
            this->maxVreme = maxVreme;
        }

        CD(const CD & c) {
            copy(c);
        }

        CD & operator=(const CD & c) {
            if(this != &c) {
                copy(c);
            }
            return *this;
        }

        ~CD () {}

        Pesna& getPesna(int i) {
            return pesni[i];
        }

        int getBroj() {
            return brPesni;
        }

        void dodadiPesna(Pesna & p) {
            // ako ima pomalku od 10 pesni i ima ostanato vreme
            int vremeOdPesni = 0;
            for( int i = 0 ; i<brPesni; i++) {
                vremeOdPesni += pesni[i].getVreme();
            }

            int vremeP = p.getVreme();

            if((brPesni < 10) && (vremeP < (maxVreme - vremeOdPesni))) {
                pesni[brPesni++] = p;
            }
        }


        void pecatiPesniPoTip(tip t) {
            for(int i = 0; i < brPesni ; i++) {
                if(pesni[i].getTip() == t) {
                    pesni[i].pecati();
                }
            }
        }

};


int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;
	
	int n, minuti, kojtip;
	char ime[50];
	
	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } //else if(testCase == 2) {
    //     cout << "===== Testiranje na klasata CD ======" << endl;
	// 	CD omileno(20);
	// 	cin>>n;
	// 		for (int i=0;i<n;i++){
	// 			cin >> ime;
	// 			cin >> minuti;
	// 			cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
	// 			Pesna p(ime,minuti,(tip)kojtip);
	// 			omileno.dodadiPesna(p);
	// 		}
    //     	for (int i=0; i<n; i++)
	// 			(omileno.getPesna(i)).pecati();
	// }
    // else if(testCase == 3) {
    //     cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
	// 	CD omileno(20);
	// 	cin>>n;
	// 		for (int i=0;i<n;i++){
	// 			cin >> ime;
	// 			cin >> minuti;
	// 			cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
	// 			Pesna p(ime,minuti,(tip)kojtip);
	// 			omileno.dodadiPesna(p);
	// 		}
    //     	for (int i=0; i<omileno.getBroj(); i++)
	// 			(omileno.getPesna(i)).pecati();
    // }
    // else if(testCase == 4) {
    //     cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
	// 	CD omileno(20);
	// 	cin>>n;
	// 		for (int i=0;i<n;i++){
	// 			cin >> ime;
	// 			cin >> minuti;
	// 			cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
	// 			Pesna p(ime,minuti,(tip)kojtip);
	// 			omileno.dodadiPesna(p);
	// 		}
    //     cin>>kojtip;
    //     omileno.pecatiPesniPoTip((tip)kojtip);
    // }
    // else if(testCase == 5) {
    //     cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
	// 	CD omileno(20);
	// 	cin>>n;
	// 		for (int i=0;i<n;i++){
	// 			cin >> ime;
	// 			cin >> minuti;
	// 			cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
	// 			Pesna p(ime,minuti,(tip)kojtip);
	// 			omileno.dodadiPesna(p);
	// 		}
    //     cin>>kojtip;
    //     omileno.pecatiPesniPoTip((tip)kojtip);
    // }
    
return 0;
}