#include <iostream>
#include <cstring>
using namespace std;

class Vozac {
protected:
    char name [100];
    int age;
    int races;
    bool isVeteran;

    public:
        Vozac(){
            strcpy(name, " ");
            age = 0;
            races = 0;
            isVeteran = false;
        }

        Vozac(char *name, int age, int races, bool isVeteran){
            strcpy(this->name,name);
            this->age = age;
            this->races = races;
            this->isVeteran = isVeteran;
        }

        friend ostream& operator<<(ostream & out, Vozac & v) {
            out<<v.name<<endl<<v.age<<endl<<v.races<<endl;
            if(v.isVeteran) {
                out<<"VETERAN"<<endl;
            }
            return out;
        }

        virtual double profitRace() =0;
        virtual double danok() =0;

};

bool operator== (Vozac * v1, Vozac & v2){
    return v1->profitRace() == v2.profitRace();
}

class Avtomobilist : public Vozac{
    double price;

    public:
        Avtomobilist() : Vozac() {
            price = 0;
        }

        Avtomobilist(char *name, int age, int races, bool isVeteran, double price) : Vozac(name, age, races, isVeteran) {
            this->price = price;
        }

        double profitRace() {
            return price / 5;
        }

        double danok() {
            if(races > 10) {
                return profitRace() * 0.15f;
            } else {
                return profitRace() * 0.1f;
            }
        }
};

class Motociklist : public Vozac {
    int motorPower;
    public:
        Motociklist() : Vozac() {
            motorPower = 0;
        }

        Motociklist(char *name, int age, int races, bool isVeteran, int motorPower)
            : Vozac(name, age, races, isVeteran) {
                this->motorPower = motorPower;
        }

        double profitRace() {
            return motorPower * 20;
        }

        double danok() {
            if(isVeteran) {
                return profitRace() * 0.25f;
            } else {
                return profitRace() * 0.20f;
            }
        }
};

int soIstaZarabotuvachka(Vozac ** drivers, int n, Vozac * v) {
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        if(drivers[i]->profitRace() == v->profitRace()) {
            count++;
        }
    }
    return count;
}


int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->danok() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
	return 0;
}