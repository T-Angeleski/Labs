#include <iostream>
#include <cstring>

using namespace std;

class Avtomobil {
    char color[20];
    char brand[20];
    char model[20];

    public:
        Avtomobil() {
            strcpy(color, " ");
            strcpy(brand, " ");
            strcpy(model, " ");
        }

        Avtomobil(char color[20],char brand[20],char model[20]) {
            strcpy(this->color,color);
            strcpy(this->brand,brand);
            strcpy(this->model,model);
        }

        Avtomobil& operator=(const Avtomobil & other) {
            if(this!= &other) {
                strcpy(this->color,other.color);
                strcpy(this->brand,other.brand);
                strcpy(this->model,other.model);
            }
            return *this;
        }

        void print() {
            cout<<color<<" "<<brand<<" "<<model<<endl;
        }
};



class ParkingPlac {
    char adress[20];
    char * ID;
    int price;
    int profit;
    Avtomobil * cars;
    int numCars;

    void copy(const ParkingPlac & other) {
        strcpy(this->adress, other.adress);

        this->ID = new char [strlen(other.ID)+1];
        strcpy(this->ID, other.ID);

        this->price = other.price;
        this->profit = other.profit;

        this->numCars = other.numCars;
        this->cars = new Avtomobil[other.numCars];
    }

    public:
        ParkingPlac() {
            strcpy(adress, " ");
            ID = new char [0];
            cars = new Avtomobil [0];
            price = 0;
            profit = 0;
            numCars = 0;
        }

        ParkingPlac(char adress[20], char *ID, int price) {
            strcpy(this->adress, adress);

            this->ID = new char [strlen(ID)+1];
            strcpy(this->ID, ID);

            this->price = price;
            profit = 0;

            this->numCars = 0;
            this->cars = new Avtomobil[numCars];
        }

        ParkingPlac(const ParkingPlac & p) {
            copy(p);
        }

        ParkingPlac& operator= (const ParkingPlac & p) {
            if( this!= &p) {
                delete [] ID;
                delete [] cars;
                copy(p);
            }
            return *this;
        }

        ~ParkingPlac() {
            delete [] ID;
            delete [] cars;
        }

        const char * getId() {
            return ID;
        }


        void platiCasovi(int hours) {
            profit += hours * price;
        }

        bool daliIstaAdresa(ParkingPlac & p) {
            return !strcmp(adress, p.adress);
        }

        void pecati() {
            if(profit==0) {
                cout<<ID<<" "<<adress<<endl;
            } else {
                cout<<ID<<" "<<adress<<" - "<<profit<<" denari"<<endl;
            }
        }

        void parkirajVozilo(Avtomobil & newCar) {
            Avtomobil * tmp = new Avtomobil[numCars+1];

            for(int i = 0 ; i < numCars ; i++) {
                tmp[i] = cars[i];
            }

            tmp[numCars++] = newCar;

            delete [] cars;

            cars = tmp;
        }

        void pecatiParkiraniVozila() {
            cout<<"Vo parkingot se parkirani slednite vozila:"<<endl;
            for(int i = 0 ; i < numCars ; i++) {
                cout<<i+1<<".";
                cars[i].print();
            }
        }
};

int main() {
    return 0;
}