#include<iostream>
#include<string.h>
using namespace std;

//место за вашиот код
class Delo {
    char name[50];
    int year;
    char origin[50];

    public:
        Delo(const char* name = "", int year = 0, char* origin = "") {
            strcpy(this->name, name);
            this->year = year;
            strcpy(this->origin, origin);
        }

        Delo(const Delo& d) {
            strcpy(this->name, d.name);
            this->year = d.year;
            strcpy(this->origin, d.origin);
        }

        bool operator== (Delo& d) const {
            return !strcmp(name, d.name);
        }

        const char* getIme()  const{
            return name;
        }

        const char* getOrigin() const {
            return origin;
        }

        int getGodina() const {
            return year;
        }
};

class Pretstava {
protected:
    Delo delo;
    int num;
    char date[15];

    public:
        Pretstava() {
            delo = nullptr;
            num = 0;
            strcpy(date, " ");
        }

        Pretstava(Delo delo, int num, char* date) {
            this->delo = delo;
            this->num = num;
            strcpy(this->date, date);
        }

        Pretstava(const Pretstava& p) {
            this->delo = p.delo;
            this->num = p.num;
            strcpy(this->date, p.date);
        }

        virtual int cena() {
            int N,M;
            int godina = delo.getGodina();

            if(godina>= 1901) 
                M = 50;
            else if(godina > 1801 && godina <= 1900)
                M = 75;
            else
                M = 100;

            if(!strcmp(delo.getOrigin(), "Italija"))
                N = 100;
            else if(!strcmp(delo.getOrigin(), "Rusija"))
                N = 150;
            else   
                N = 80;

            return N+M;
        }

        const Delo& getDelo() const {
            return delo;
        }

        int getNum() {
            return num;
        }

};

class Balet : public Pretstava {
private:
    static int BALET_PRICE;

    public:
        Balet(Delo delo= nullptr, int num = 0, char* date = " ")
         : Pretstava(delo, num, date) {
            //do nothing
        }

        int cena()  {
            return Pretstava::cena() + BALET_PRICE;
        }

        static void setCenaBalet(int c){
            BALET_PRICE = c;
        }
};

int Balet::BALET_PRICE = 150;

class Opera : public Pretstava {
    public:
        Opera(Delo delo= nullptr, int num = 0, char* date = "") : Pretstava(delo, num, date) {
            //do nothing
        }
};

int prihod(Pretstava ** shows, int n) {
    int pri = 0;
    for(int i = 0 ; i < n ; i++){
        pri += shows[i]->cena() * shows[i]->getNum();
    }
    return pri;
}

int brojPretstaviNaDelo(Pretstava ** shows, int n, Delo d) {
    int brojac=0;
    for(int i = 0 ; i < n ; i++){
        if(shows[i]->getDelo() == d)
            brojac++;
    }
    return brojac;
}

//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;
    
    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDelo().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDelo().getIme()<<endl;
    }break;
        
    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;
    
    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        Delo f1=readDelo();
        Delo f2=readDelo();
        Delo f3=readDelo();
        
        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
    
    }break;
    
    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        
        }
        cout<<prihod(pole,n);
    }break;
    
    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;
        
    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        
        Delo f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;
    
    };


return 0;
}
