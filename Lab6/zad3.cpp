#include <iostream>
#include <cstring>
using namespace std;
class Lekar {
protected:
    int fax;
    char name[10];
    char surname[11];
    double salary;

    public:
        Lekar(int fax = 0, char * name = "", char * surname = " ", double salary = 0) {
            this->fax = fax;
            strcpy(this->name, name);
            strcpy(this->surname, surname);
            this->salary = salary;
        }

        Lekar(const Lekar & l) {
            this->fax = l.fax;
            strcpy(this->name, l.name);
            strcpy(this->surname, l.surname);
            this->salary = l.salary;
        }

        void pecati() {
            cout<<fax<<": "<<name<<" "<<surname<<endl;
        }

        double plata() {
            return salary;
        }
};

class MaticenLekar : public Lekar {
    int numPatients;
    double * fees;

    public:
    
        MaticenLekar() : Lekar() {
            numPatients = 0;
            fees = new double [100];
        }
    
        MaticenLekar(Lekar & doctor, int numPatients, double * fees) : Lekar(doctor) {
            this->numPatients = numPatients;
            this->fees = new double [numPatients];
            for(int i = 0 ; i < numPatients ; i++) {
                this->fees[i] = fees[i];
            }
        }

        MaticenLekar(const MaticenLekar & ml) : Lekar(ml) {
            this->numPatients = ml.numPatients;
            this->fees = new double [ml.numPatients];
            for(int i = 0 ; i < ml.numPatients ; i++) {
                this->fees[i] = ml.fees[i];
            }
        }

        MaticenLekar& operator= (const MaticenLekar & ml) {
            if(this != &ml) {
                delete [] fees;

                this->fax = ml.fax;
                strcpy(this->name, ml.name);
                strcpy(this->surname, ml.surname);
                this->salary = ml.salary;

                this->numPatients = ml.numPatients;
                this->fees = new double [ml.numPatients];
                for(int i = 0 ; i < ml.numPatients ; i++) {
                    this->fees[i] = ml.fees[i];
                }
            }
            return *this;
        }

        ~MaticenLekar() {
            delete [] fees;
        }

        double prosekKotizacija() {
            double avg = 0;

            for(int i = 0 ; i < numPatients ; i++) {
                avg += fees[i];
            }

            return avg/= numPatients;

            
        }

        double plata() {
            return Lekar::plata() + (0.3 * prosekKotizacija());
        }

        void pecati() {
            Lekar::pecati();
            cout<<"Prosek na kotizacii: "<<prosekKotizacija()<<endl;
        }
};


int main() {return 0;}