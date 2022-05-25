#include<iostream>
#include<cstring>
using namespace std;

class ImaMasa {
    public:
        virtual double vratiMasa() =0;
        virtual void pecati() =0;
};

class PaketPijalok : virtual public ImaMasa {
protected:
    double volumenEden;
    int kolicina;
    static double GUSTINA_AMBALAZA;
    static double MASA_AMBALAZA;

    public:
        PaketPijalok(double volumenEden = 0, int kolicina = 0) {
            this->volumenEden = volumenEden;
            this->kolicina = kolicina;
        }

        double vratiMasa() {
            return (volumenEden * GUSTINA_AMBALAZA + MASA_AMBALAZA) * kolicina;
        }

        int getKolicina() {
            return kolicina;
        }
};

double PaketPijalok::GUSTINA_AMBALAZA = 0.8;
double PaketPijalok::MASA_AMBALAZA = 0.2;

class PaketSok : public PaketPijalok{
    bool daliGaziran;
    static double DOPOLNITELNA_MASA;

    public:
        PaketSok(double volumenEden = 0, int kolicina = 0, bool daliGaziran = false) : PaketPijalok(volumenEden, kolicina) {
            this->daliGaziran = daliGaziran;
        }

        double vratiMasa() {
            if(!daliGaziran) 
                return PaketPijalok::vratiMasa() + DOPOLNITELNA_MASA * getKolicina();
            return PaketPijalok::vratiMasa();
        }

        void pecati() {
            cout<<"Paket sok"<<endl;
            cout<<"kolicina "<<kolicina<<", so po"<<volumenEden * GUSTINA_AMBALAZA << " l(dm3)\n";
        }
};

double PaketSok::DOPOLNITELNA_MASA = 0.1;

class PaketVino : public PaketPijalok {
    double procentAlkohol;
    static double KOEF_ALKOHOL;

    public:
        PaketVino(double volumenEden = 0, int kolicina = 0, double procentAlkohol = 0) : PaketPijalok(volumenEden, kolicina) {
            this->procentAlkohol = procentAlkohol;
        }

        double getProcentAlkohol() {
            return procentAlkohol;
        }

        double vratiMasa() {
            return PaketPijalok::vratiMasa() * (KOEF_ALKOHOL + procentAlkohol);
        }

        void pecati() {
            cout<<"Paket vino\n";
            cout<<"kolicina "<<kolicina<<", "<<procentAlkohol*100<<"% alkohol od po"<<volumenEden * GUSTINA_AMBALAZA<<" l(dm3)\n";
        }
};

double PaketVino::KOEF_ALKOHOL = 0.9;

class Kamion {
    char * registration;
    char * driver;
    ImaMasa ** products;
    int n;

    public:
        Kamion(char * registration = "", char * driver = "") {
            strcpy(this->registration, registration);
            strcpy(this->driver, driver);
        }
};

int main()
{
    char ime[20], reg[9];
    double vol;
    int kol;
    bool g;
    double proc;
    
            cin>>reg;
            cin>>ime;
            Kamion A(reg, ime);
            ImaMasa **d = new ImaMasa*[5];
            cin>>vol>>kol;
            cin>>g;
            d[0] = new PaketSok(vol, kol, g);
            cin>>vol>>kol;
            cin>>proc;
            d[1] = new PaketVino(vol, kol, proc);
            cin>>vol>>kol;
            cin>>proc;
            d[2] = new PaketVino(vol, kol, proc);
            cin>>vol>>kol;
            cin>>g;
            d[3] = new PaketSok(vol, kol, g);
            cin>>vol>>kol;
            cin>>proc;
            d[4] = new PaketVino(vol, kol, proc);

            A.dodadiElement(d[0]);
            A.dodadiElement(d[1]);
            A.dodadiElement(d[2]);
            A.dodadiElement(d[3]);
            A.dodadiElement(d[4]);
            A.pecati();
            cout<<"Vkupna masa: "<<A.vratiVkupnaMasa()<<endl;
            cin>>reg;
            cin>>ime;
            Kamion B = A.pretovar(reg, ime);
            B.pecati();
            cout<<"Vkupna masa: "<<B.vratiVkupnaMasa()<<endl;

}
