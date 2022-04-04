#include <iostream>
#include <cstring>
using namespace std;


struct Voz {
    char relacija[50];
    double km;
    int patnici;
};

struct ZeleznickaStanica {
    char grad[20];
    Voz vozovi[30];
    int brVozovi;
};

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad) {
    int najmala = 999999, indexNajmalVoz, zelez;
    for(int i = 0 ; i < n; i++) {
        if(!strcmp(zs[i].grad, grad)) {
            for(int j = 0 ; j < zs[i].brVozovi; j++) {
                if(najmala >= zs[i].vozovi[j].km) {
                    najmala = zs[i].vozovi[j].km;
                    indexNajmalVoz = j;
                    zelez = i;
                }
            }
        }
        
    }
    cout<<"Najkratka relacija: "<<zs[zelez].vozovi[indexNajmalVoz].relacija<<" ("<<
    zs[zelez].vozovi[indexNajmalVoz].km<<" km)";
}

int main() {
    int n;
	cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
        cin>>zStanica[i].grad;
        cin>>zStanica[i].brVozovi;
        for(int j = 0 ; j < zStanica[i].brVozovi ; j++) {
            cin>>zStanica[i].vozovi[j].relacija>>zStanica[i].vozovi[j].km>>zStanica[i].vozovi[j].patnici;
        }
    }
    
    char grad[25];
    cin>>grad;

	najkratkaRelacija(zStanica,n,grad);


    return 0;
}
