// вашиот код треба да биде тука
#include <iostream>
#include <cstring>
using namespace std;

class Transport {
protected:
    char destinacija[21];
    int cena;
    int rastojanie;

    public:
        Transport(const char* destinacija = "",int cena = 0, int rastojanie = 0) {
            strcpy(this->destinacija, destinacija);
            this->cena = cena;
            this->rastojanie = rastojanie;
        }

        virtual double cenaTransport() =0;

        bool operator< (Transport& t) {
            return rastojanie < t.rastojanie;
        }

        int getRastojanie() const {
            return rastojanie;
        }

        void setRastojanie(int i) {
            Transport::rastojanie = i;
        }

        const char* getDestinacija() const{
            return destinacija;
        }
};

class AvtomobilTransport : public Transport {
    bool shofer;

    public:
        AvtomobilTransport(const char* destinacija = "",int cena = 0, int rastojanie = 0, bool shofer = false)
        : Transport(destinacija, cena, rastojanie) {
            this->shofer = shofer;
        }

        double cenaTransport() {
            if(shofer)
                return cena * 1.2f;
            else
                return cena;
        }
  
};

class KombeTransport : public Transport {
    int lugje;

    public:
        KombeTransport(const char* destinacija = "",int cena = 0, int rastojanie = 0, int lugje = 0)
        : Transport(destinacija, cena, rastojanie) {
            this->lugje = lugje;
        }

        double cenaTransport() {
            return cena - (lugje * 200);
        }
};

void pecatiPoloshiPonudi(Transport ** ponudi, int n, Transport& t) {
    //Функцијата ја печати дестинацијата, растојанието до дестинацијата и цената за понудите од низата кои се поскапи од понудата T сортирани во растечки редослед по растојанието до дестинацијата (погледни го повикот на функцијата)
    Transport ** tmp = new Transport* [n];
    int k=0;
    //napravi temp za tie so pogolema cena
    for(int i = 0 ; i < n ; i++) {
        if(ponudi[i]->cenaTransport() > t.cenaTransport()) {
            tmp[k] = ponudi[i];
            k++;
        }
    }

    //sortiraj
    for(int i = 0 ; i < k-1 ; i++) {
        for(int j = 0; j<k-1-i ; j++) {
            if(tmp[j]->getRastojanie() > tmp[j+1]->getRastojanie()) {
                Transport *t = tmp[j];
                tmp[j] = tmp[j+1];
                tmp[j+1] = t;
            }
        }
    }

    for(int i = 0 ; i < k ; i++) {
        cout<<tmp[i]->getDestinacija()<<" "<<tmp[i]->getRastojanie()<<" "<<tmp[i]->cenaTransport()<<endl;
    }
    delete []tmp;
}


int main(){

char destinacija[20];
int tip,cena,rastojanie,lugje;
bool shofer;
int n;
cin>>n;
Transport  **ponudi;
ponudi=new Transport *[n];

for (int i=0;i<n;i++){

    cin>>tip>>destinacija>>cena>>rastojanie;
    if (tip==1) {
        cin>>shofer;
        ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

    }
    else {
        cin>>lugje;
        ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
    }


}

AvtomobilTransport nov("Ohrid",2000,600,false);
pecatiPoloshiPonudi(ponudi,n,nov);

for (int i=0;i<n;i++) delete ponudi[i];
delete [] ponudi;
return 0;
}
