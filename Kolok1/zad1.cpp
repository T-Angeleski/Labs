#include <iostream>
#include <cstring>
using namespace std;

enum tip {pop, rap, rock};

class Pesna {
    char *imePesna;
    int vremetraenje;
    tip tipNaPesna;

    public:
        Pesna() {
            imePesna = nullptr;
        }
        // song_name = new char[(size_t)(strlen(s_n)+1)]; strcpy(song_name,s_n);
        Pesna(char * _imePesna, int _vremetraenje, tip _tip) {
            imePesna = new char[(size_t) (strlen(_imePesna)+1)];
            strcpy(imePesna, _imePesna);

            vremetraenje = _vremetraenje;
            tipNaPesna = _tip;
        }

        ~Pesna() {}

        int getVreme() {
            return vremetraenje;
        }

        tip getTip() {
            return tipNaPesna;
        }


        void pecati() {
            cout<<"\""<<imePesna<<"-"<<vremetraenje<<"min"<<endl;
        }
};

class CD {
    private:
        Pesna pesni[10];
        int brPesni;
        int maxVreme;
    public:
        CD() =default;

        CD(int _maxVreme) {
            maxVreme = _maxVreme;
            brPesni = 0;
        }

        Pesna getPesna(int i) {
            return pesni[i];
        }

        ~CD() {}

        void dodadiPesna(Pesna p) {
            
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
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
        	
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
        	
    }
    
return 0;
}