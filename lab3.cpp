#include<iostream>
#include<cstring>
using namespace std;

class Person{
    char ime[20], prezime[20];

    public:
        Person() {
            strcpy(ime, "not specified");
            strcpy(prezime, "not specified");
        }

        Person(char * _ime, char * _prezime) {
            strcpy(ime, _ime);
            strcpy(prezime, _prezime);
        }

        void print() {
            cout<<ime<<" "<<prezime<<endl;
        }
};

class Date{
    int year,month,day;

    public:
        Date() {
            year = 2002;
            month = 10;
            day = 14;
        }

        Date(int year, int month, int day){
            this->year = year;
            this->month = month;
            this->day = day;
        }

        Date(const Date & d) {
            year = d.year;
            month = d.month;
            day = d.day;
        }

        void print() {
            cout<<year<<"."<<month<<"."<<day<<endl;
        }
};

class Car{
    Person owner;
    Date dateOfPurchase;
    float price=0;

    public:
        Car() {
            price = 0;
        }

        Car(Person owner, Date dop, float price) {
            this->owner= owner;
            this->dateOfPurchase = dop;
            this->price = price;
        }

        float getPrice() {
            return price;
        }

        void print() {
            owner.print();
            dateOfPurchase.print();
            cout<<"Price: "<<price;
        }

    
};

class Potpisuvac
{
	//vasiot kod ovde
    char ime[20], prezime[20], EMBG[14];

    public:
        Potpisuvac() {
            strcpy(ime, "Teodor");
            strcpy(prezime, "Angeleski");
            strcpy(EMBG, "1234567891234");
        }

        Potpisuvac(char * _ime, char* _prezime, char * _embg) {
            strcpy(ime, _ime);
            strcpy(prezime, _prezime);
            strcpy(EMBG, _embg);
        }

        Potpisuvac(const Potpisuvac & p) {
            strcpy(ime, p.ime);
            strcpy(prezime, p.prezime);
            strcpy(EMBG, p.EMBG);
        }

        char* getEMBG() {
            return EMBG;
        }
};
class Dogovor
{
    //vasiot kod ovde
    int brDogovor;
    char katDogovor[50];
    Potpisuvac pot[3];

    public:
        Dogovor(int br, char *kat, Potpisuvac *pot) {
            brDogovor = br;
            strcpy(katDogovor, kat);
            this->pot[0] = pot[0];
            this->pot[1] = pot[1];
            this->pot[2] = pot[2];
        }


        bool proverka() {
            char * p0 = pot[0].getEMBG();
            char * p1 = pot[1].getEMBG();
            char * p2 = pot[2].getEMBG();
            
            for(int i=0; i<13; i++) {
                if(p0[i] != p1[i]) {
                    return false;
                }

                if(p1[i] != p2[i]) {
                    return false;
                }

                if(p0[i] != p2[i]) {
                    return false;
                }
            }
            return true;
        }
};


Car cheaperThan(Car* cars, int numCars, float price) {
    for (int i = 0; i < numCars; i++)
        {
            if(cars[i].getPrice() < price) {
                cars[i].print();
            }
        }
}

int main() {
    //     Во оваа задача треба да се внесат и испечатат податоци за автомобили.

    // За еден автомобил (објект од класата Car) се чуваат следниве податоци:

    //     сопственик (објект од класата Person)
    //     датум на купување (објект од класата Date)
    //     цена (float price), предодредена вредност 0

    // За класата Car потребно е да се напише метод за печатење print() и метод за добивање на цената getPrice().

    // Класата Date содржи три цели броеви (int year, month, day) кои претставуваат датум. За неа треба да се напише метод за печатење print(), предодреден (default) конструктор, конструктор со параметри и конструктор за копирање.

    // Класата Person содржи име и презиме (низи од максимум 20 знаци, со предодредени вредности not specified), предодреден конструктор, конструктор со параметри и метод за печатење print().

    // Методот за печатење кај класата Person изгледа вака: [name] [lastName].

    // Методот за печатење кај класата Date изгледа вака: [year].[month].[day].

    // Методот за печатење кај класата Car изгледа вака:

    // owner.print()

    // date.print()

    // Price: [price]

    // Покрај тоа, потребно е да се напише метод cheaperThan(Car* cars, int numCars, float price) кој ќе ги испечати сите објекти Car од низата cars со големина numCars чија цена е помала од price.



	// char name[20];
	// char lastName[20];
	// int year;
	// int month;
	// int day;
	// float price;

	// int testCase;
	// cin >> testCase;

	// if (testCase == 1) {
	// 	cin >> name;
	// 	cin >> lastName;
	// 	Person lik(name, lastName);

	// 	cin >> year;
	// 	cin >> month;
	// 	cin >> day;
	// 	Date date(year, month, day);

	// 	cin >> price;
	// 	Car car(lik, date,  price);

	// 	car.print();
	// }
	// else if (testCase == 2) {
	// 	cin >> name;
	// 	cin >> lastName;
	// 	Person lik(name, lastName);

	// 	cin >> year;
	// 	cin >> month;
	// 	cin >> day;
	// 	Date date(Date(year, month, day));

	// 	cin >> price;
	// 	Car car(lik, date,  price);
	// 	car.print();
	// }
	// else {
	// 	int numCars;
	// 	cin >> numCars;

	// 	Car cars[10];
	// 	for (int i = 0; i < numCars; i++) {
	// 		cin >> name;
	// 		cin >> lastName;
	// 		Person lik(name, lastName);

	// 		cin >> year;
	// 		cin >> month;
	// 		cin >> day;
	// 		Date date(year, month, day);

	// 		cin >> price;
	// 		cars[i] = Car(lik, date,  price);
	// 	}
    //     float priceLimit;
    //     cin >> priceLimit;
	// 	cheaperThan(cars, numCars, priceLimit);
	// }

    // ZADACA 2

    char embg[13], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl; 
    	if(d.proverka() == true)
    	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
    	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    
    

	return 0;
}