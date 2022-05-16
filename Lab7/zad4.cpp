#include <iostream>
#include <cstring>
using namespace std;

class Vozilo {
protected:
    double mass;
    int width;
    int height;

    public:
        Vozilo(double mass = 0, int width =0, int height = 0) {
            this->mass = mass;
            this->width = width;
            this->height = height;
        }

        int getWidth() {
            return width;
        }

        int getHeight() {
            return height;
        }

        double getMass() {
            return mass;
        }

        virtual int vratiDnevnaCena() =0;
};

class Avtomobil : public Vozilo {
    int doors;

    public:
        Avtomobil() : Vozilo() {
            doors = 0;
        }

        Avtomobil(double mass, int width, int height, int doors) : Vozilo(mass, width, height) {
            this->doors = doors;
        }

        int vratiDnevnaCena() {
            if(doors < 5) {
                return 100;
            } else {
                return 130;
            }
        }
};

class Avtobus : public Vozilo {
    int capacity;

    public:
        Avtobus() : Vozilo() {
            capacity = 0;
        }

        Avtobus(double mass, int width, int height, int capacity) : Vozilo(mass, width, height) {
            this->capacity = capacity;
        }

        int vratiDnevnaCena() {
            return 5 * capacity;
        }
};

class Kamion : public Vozilo {
    double maxMass;

    public:
        Kamion() : Vozilo() {
            maxMass = 0;
        }

        Kamion(double mass, int width, int height, double maxMass) : Vozilo(mass, width, height) {
            this->maxMass = maxMass;
        }

        int vratiDnevnaCena() {
            return (mass + maxMass) * 0.02;
        }
};

class ParkingPlac {
    Vozilo ** vehicles;
    int num;

    public:
        ParkingPlac() {
            vehicles = new Vozilo * [0];
            num = 0;
        }

        ParkingPlac(const ParkingPlac & p) {
            num = p.num;
            vehicles = new Vozilo * [p.num];
            for(int i = 0 ; i < p.num ; i++) {
                vehicles[i] = p.vehicles[i];
            }
        }

        ParkingPlac& operator= (const ParkingPlac & p) {
            if(this != &p) {
                delete [] vehicles;
                num = p.num;
                vehicles = new Vozilo * [p.num];
                for(int i = 0 ; i < p.num ; i++) {
                    vehicles[i] = p.vehicles[i];
                }
            }
            return *this;
        }

        ~ParkingPlac() {
            delete [] vehicles;
        }

        ParkingPlac& operator+= (Vozilo * v) {
            Vozilo ** tmp = new Vozilo * [num+1];
            for(int i = 0 ; i < num ; i++) {
                tmp[i] = vehicles[i];
            }
            tmp[num++] = v;

            delete [] vehicles;
            vehicles = tmp;

            return *this;
        }

        float presmetajVkupnaMasa() {
            float sum = 0;
            for(int i = 0 ; i < num ; i++) {
                sum += vehicles[i]->getMass();
            }
            return sum;
        }

        int brojVozilaPoshirokiOd(int l) {
            int counter=0;
            for(int i = 0 ; i < num ; i++) {
                if(vehicles[i]->getWidth() > l) {
                    counter++;
                }
            }
            return counter;
        }

        void pecati() {
            int koli = 0;
            int kamioni = 0;
            int avtobusi = 0;

            for(int i = 0 ; i < num ; i++) {
                if(dynamic_cast<Avtomobil *>(vehicles[i])) {
                    koli++;
                } else if (dynamic_cast<Avtobus *>(vehicles[i])) {
                    avtobusi++;
                } else {
                    kamioni++;
                }
            }

            cout<<" Brojot na avtomobili e "<<koli<<", brojot na avtobusi e "<< avtobusi<<" i brojot na kamioni e "<<kamioni<<"."<<endl;
        }

        int pogolemaNosivostOd(Vozilo& v) {
            int counter=0;

            for(int i = 0 ; i < num ; i++) {
                if(dynamic_cast<Kamion *>(vehicles[i]) && vehicles[i]->getMass() > v.getMass()) {
                    counter++;
                }
            }

            return counter;
        }

        int vratiDnevnaZarabotka() {
            int zarabotka = 0;

            for(int i = 0 ; i < num ; i++) {
                zarabotka += vehicles[i]->vratiDnevnaCena();
            }
            return zarabotka;
        }
};