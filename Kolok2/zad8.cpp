#include <iostream>
#include <cstring>
using namespace std;

class Koncert {
    char naziv[20];
    char lokacija[20];
    static double SEZONSKI_POPUST;
    double cenaBilet;

    public:
        Koncert(const char* naziv = "", const char* lokacija = "",double cenaBilet = 0) {
            strcpy(this->naziv, naziv);
            strcpy(this->lokacija, lokacija);
            this->cenaBilet = cenaBilet;
        }

        static void setSezonskiPopust(double a) {
            SEZONSKI_POPUST = a;
        }
        static double getSezonskiPopust() {
            return SEZONSKI_POPUST;
        }

        virtual double cena() {
            return cenaBilet * (1 - SEZONSKI_POPUST);
        }

        char* getNaziv() {
            return naziv;
        }
};
double Koncert::SEZONSKI_POPUST = 0.20;

class ElektronskiKoncert : public Koncert {
    char* DJ;
    double casovi;
    bool dnevna;

    public:
        ElektronskiKoncert(const char* naziv = "", const char* lokacija = "",double cenaBilet = 0,
        const char* DJ = "", double casovi = 0, bool dnevna = true)
        : Koncert(naziv, lokacija, cenaBilet) {
            this->DJ = new char [strlen(DJ)+1];
            strcpy(this->DJ, DJ);

            this->casovi = casovi;
            this->dnevna = dnevna;
        }

        double cena() {
            double c = Koncert::cena();
            bool flag = false;
            if (casovi > 7) {
                c += 360;
                flag = true;
            }
            else if(casovi>5 && !flag)
                c += 150;
            if(dnevna)
                c-=50;
            else
                c+= 100;
            return c;
        }

        ~ElektronskiKoncert() {
            delete [] DJ;
        }

        
};

void najskapKoncert(Koncert ** koncerti, int n) {
    double max=0;
    int maxIndex;
    int brD=0;

    for(int i = 0 ; i < n ; i++) {
        if(koncerti[i]->cena() > max) {
            max = koncerti[i]->cena();
            maxIndex = i;
        }
        if(dynamic_cast<ElektronskiKoncert*>(koncerti[i]))
            brD++;
    }
    cout<<"Najskap koncert: "<<koncerti[maxIndex]->getNaziv()<<" "<<koncerti[maxIndex]->cena()<<endl;
    cout<<"Elektronski koncerti: "<<brD<<" od vkupno "<<n<<endl;
}

bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski) {
    bool flag = false;
    if(elektronski) {
        for(int i = 0 ; i < n ; i++) {
            if(dynamic_cast<ElektronskiKoncert*>(koncerti[i]))
                if(!strcmp(koncerti[i]->getNaziv(), naziv)) {
                    cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                    flag = true;
                }

        }
    } else {
        for(int i = 0 ; i < n ; i++) {
            if(!strcmp(koncerti[i]->getNaziv(), naziv)) {
                cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                flag = true;
            }
        }
    }
    return flag;
}

int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

        cin>>tip;
        if (tip==1){//Koncert
        	cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
        }
        else if (tip==2){//cena - Koncert
            cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
        }
        else if (tip==3){//ElektronskiKoncert
            cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
            ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
            cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
        }
        else if (tip==4){//cena - ElektronskiKoncert
             cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
             ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
             cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
        }
        else if (tip==5) {//najskapKoncert

        }
        else if (tip==6) {//prebarajKoncert
            Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
        	najskapKoncert(koncerti,5);
        }
        else if (tip==7){//prebaraj
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
            bool elektronski;
        	cin>>elektronski;
        	if(prebarajKoncert(koncerti,5, "Area",elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

            if(prebarajKoncert(koncerti,5, "Area",!elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

        }
        else if (tip==8){//smeni cena
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[2] -> setSezonskiPopust(0.9);
        	najskapKoncert(koncerti,4);
        }

    return 0;
}
