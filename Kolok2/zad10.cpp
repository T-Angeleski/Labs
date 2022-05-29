#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

//место за вашиот код

class NegativnaVrednost{
    public:
        void message() {
            cout<<"Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!\n";
        }
};

class Oglas {
    char title[50];
    char category[30];
    char desc[100];
    double price;

    public:
        Oglas() {
            strcpy(title, "");
            strcpy(category, "");
            strcpy(desc, "");
            price = 0;
        }

        Oglas(const char * title,const char * category,const char * desc,double price) {
            strcpy(this->title, title);
            strcpy(this->category, category);
            strcpy(this->desc, desc);
            this->price = price;
        }

        Oglas(const Oglas& o) {
            strcpy(this->title, o.title);
            strcpy(this->category, o.category);
            strcpy(this->desc, o.desc);
            this->price = o.price;
        }

        double getPrice() {
            return price;
        }

        char* getCategory() {
            return category;
        }

        bool operator> (Oglas & o) {
            return price > o.price;
        }

        // bool operator< (Oglas & o) {
        //     return price < o.price;
        // }

        friend ostream& operator<<(ostream& out, Oglas& o) {
            return out<<o.title<<endl<<o.desc<<endl<<o.price<<" evra\n";
        }
};

class Oglasnik {
    char name[20];
    Oglas * oglasi;
    int num;

    void copy(const Oglasnik& o) {
        strcpy(this->name, o.name);
        num = o.num;
        oglasi = new Oglas [o.num];
        for(int i = 0 ; i < o.num ; i++) {
            oglasi[i] = o.oglasi[i];
        }
    }

    public:
        Oglasnik(const char * name = "") {
            strcpy(this->name, name);
            oglasi = new Oglas [0];
            num = 0;
        }

        Oglasnik(const Oglasnik& o) {
            copy(o);
        }

        Oglasnik& operator= (const Oglasnik& o) {
            if(this != &o) {
                delete [] oglasi;
                copy(o);
            }
            return *this;
        }

        ~Oglasnik() {
            delete [] oglasi;
        }

        Oglasnik& operator+=(Oglas & o) {
            if(o.getPrice() < 0)
                throw NegativnaVrednost();
            
            Oglas * tmp = new Oglas [num+1];
            for(int i = 0 ; i < num ; i++) {
                tmp[i] = oglasi[i];
            }
            tmp[num++] = o;
            delete [] oglasi;
            oglasi = tmp;
            return *this;
        }

        friend ostream& operator<<(ostream& out, Oglasnik& o) {
            out<<o.name<<endl;
            for(int i = 0 ; i < o.num ; i++) {
                out<<o.oglasi[i]<<endl;
            }
            return out;
        }

        void oglasiOdKategorija(const char *k) {
            for(int i = 0 ; i < num ; i++) {
                if(!strcmp(oglasi[i].getCategory(), k)) {
                    cout<<oglasi[i]<<endl;
                }
            }
        }

        void najniskaCena() {
            double min = 9999999;
            int minIndex;
            for(int i = 0 ; i < num ; i++) {
                if(oglasi[i].getPrice() < min) {
                    min = oglasi[i].getPrice();
                    minIndex = i;
                }
            }

            cout<<oglasi[minIndex]<<endl;
        }
};


int main(){
    
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;
    
    int tip;
    cin>>tip;
    
    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
    	cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;    
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cout<<ogl;
    }
    else if (tip==4){
      	cout<<"-----Test oglasOdKategorija -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);
    
    }
    else if (tip==5){
    	cout<<"-----Test Exception -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            try {
                Oglas o(naslov, kategorija, opis, cena);            
                ogl+=o;
            }
            catch (NegativnaVrednost & e) {
                e.message();
            }
        	
        }
        cout<<ogl;
    
    }
    else if (tip==6){
    	cout<<"-----Test najniskaCena -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);            
            ogl+=o;            
        }
        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();
    
    }
    else if (tip==7){
    	cout<<"-----Test All -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            try {
                Oglas o(naslov, kategorija, opis, cena);            
                ogl+=o;
            }
            catch(NegativnaVrednost e) {
                e.message();
            }
        	
        }
        cout<<ogl;
        
        cin.get();
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);
        
        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();
    
    }
    
	return 0;
}
