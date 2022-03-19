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
            strncpy(ime, _ime, 19);
            ime[19] = 0;
            strncpy(prezime, _prezime,19);
            prezime[19] = 0;
            strncpy(EMBG, _embg,13);
            EMBG[13] = 0;
        }

        Potpisuvac(const Potpisuvac & p) {
            strcpy(ime, p.ime);
            strcpy(prezime, p.prezime);
            strcpy(EMBG, p.EMBG);
        }

        const char* getEMBG() {
            return EMBG;
        }
};
class Masa {
    int width, length;

    public:
        Masa() {
            length = 10;
            width = 8;
        }

        Masa(int width, int length) {
            this->length = length;
            this->width = width;
        }

        void pecati() {
            cout<<"Masa: "<<width<<" "<<length;
        }
};

class Soba{
    Masa masa;
    int roomWidth, roomLength;

    public:
        Soba() {}

        Soba(int rw, int rl, Masa m) {
            masa = m;
            roomWidth = rw;
            roomLength = rl;
        }

        void pecati() {
            cout<<"Soba: "<<roomWidth<<" "<<roomLength<<" ";
            masa.pecati();
        }

};

class Kukja{
    Soba soba;
    char adress[50];

    public:
        Kukja() {}

        Kukja(Soba _soba, char *_adress) {
            strncpy(adress,  _adress, 49);
            adress[49] = 0;

            soba = _soba;
        }

        ~Kukja() {}

        void pecati() {
            cout<<"Adresa: "<<adress<<" ";
            soba.pecati();
            cout<<endl;
        }
};

class Kukja{
    Soba soba;
    char adress[50];

    public:
        Kukja() {}

        Kukja(Soba _soba, char *_adress) {
            strncpy(adress,  _adress, 49);
            adress[49] = 0;

            soba = _soba;
        }

        ~Kukja() {}

        void pecati() {
            cout<<"Adresa: "<<adress<<" ";
            soba.pecati();
            cout<<endl;
        }
};



//--------------FUNKCII----------------

Car cheaperThan(Car* cars, int numCars, float price) {
    for (int i = 0; i < numCars; i++)
        {
            if(cars[i].getPrice() < price) {
                cars[i].print();
            }
        }
}

int main() {

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

    // char embg[13], ime[20], prezime[20], kategorija[20];
    // int broj, n;
    // cin >> n;
    // for(int i = 0; i < n; i++){
    // 	cin >> embg >> ime >> prezime;
    // 	Potpisuvac p1(ime, prezime, embg);
    // 	cin >> embg >> ime >> prezime;
    // 	Potpisuvac p2(ime, prezime, embg);
    // 	cin >> embg >> ime >> prezime;
    // 	Potpisuvac p3(ime, prezime, embg);
    // 	cin >> broj >> kategorija;
    // 	Potpisuvac p[3];
    // 	p[0] = p1; p[1] = p2; p[2] = p3;
    // 	Dogovor d(broj, kategorija, p);
    //     cout << "Dogovor " << broj << ":" << endl; 
    // 	if(d.proverka() == true)
    // 	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    // 	else
    // 	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    // }
    
    // ZADACA 4

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
        Masa m(masaSirina,masaDolzina);
        int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
        Soba s(sobaSirina,sobaDolzina,m);
        char adresa[30];
        cin>>adresa;
        Kukja k(s,adresa);
        k.pecati();
	}
    

	return 0;
}