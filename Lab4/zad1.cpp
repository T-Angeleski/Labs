#include <iostream>
#include <cstring>

using namespace std;

class List{
    int * broevi;
    int brBroevi;

    public:
        List(int * broevi=nullptr, int brBroevi = 0) {
            
            this->brBroevi = 0;
            broevi = new int [brBroevi];
            for(int i = 0 ; i<brBroevi; i++) {
                this->broevi[i] =  broevi[i];
            }
        }

        List(const List & other) {
            this->brBroevi = other.brBroevi;

            this->broevi = new int [brBroevi];
            for(int i = 0 ; i < brBroevi ; i++) {
                broevi[i] = other.broevi[i];
            }
        }

        List & operator=(const List & other) {
            if ( this != &other) {
                this->brBroevi = other.brBroevi;

                delete [] broevi;

                this->broevi = new int [brBroevi];
                for(int i = 0 ; i < brBroevi ; i++) {
                    broevi[i] = other.broevi[i];
                }
            }
            return *this;
        }

        int getBroevi() {
            return brBroevi;
        }

        ~List() {
            delete [] broevi;
        }

        int sum() {
            int suma =0;

            for (int i = 0; i < brBroevi; i++) {
                suma += broevi[i];
            }
            
            return suma;
        }

        double average() {
            return sum()/(double)this->brBroevi;
        }

        void pecati() {
            int suma = sum();
            int avg = average();

            cout<<brBroevi<<": ";
            for(int i = 0 ; i < brBroevi ; i++) {
                cout<<broevi[i];
            }

            cout<<" sum: "<<suma<<" average: "<<avg<<endl;
        }
};

class ListContainer {
    List * listi;
    int brListi;
    int brObidi;

    public:
        ListContainer() {
            this->brListi = 0;
            this->brObidi = 0;
            listi = nullptr;
        }

        ListContainer(List * listi, int brListi, int brObidi) {
            this->brListi = brListi;
            this->brObidi = brObidi;
            listi = new List [brListi];

            for( int i = 0 ; i < brListi; i++) {
                this->listi[i] = listi[i];
            }
        }

        ListContainer(const ListContainer & other) {
            this->brListi = other.brListi;
            this->brObidi = other.brObidi;
            listi = new List [other.brListi];

            for( int i = 0 ; i < other.brListi; i++) {
                this->listi[i] = other.listi[i];
            }
        }

        ListContainer & operator=(const ListContainer & other) {
            if ( this != &other) {
                this->brListi = other.brListi;
                this->brObidi = other.brObidi;

                delete [] listi;

                listi = new List [other.brListi];
                
                for( int i = 0 ; i < other.brListi; i++) {
                    this->listi[i] = other.listi[i];
                }
            }
            return *this;
        }

        ~ListContainer() {
            delete [] listi;
        }

        void addNewList(List & l) {
            List * tmp = new List [brListi+1];

            for(int i=0;i<brListi;i++) {
                if(l.sum() == listi[i].sum()) {
                    brObidi++;
                    return;
                }

                tmp[i] = listi[i];
            }

            tmp[brListi++] = l;

            delete [] listi;

            listi = tmp;
        }

        int sum() {
            int suma=0;

            for(int i=0;i<brListi;i++) {
                suma += listi[i].sum();
            }

            return suma;
        }

        double average() {
            double suma=0;
            int brElementi = 0;

            for(int i=0;i<brListi;i++) {
                suma += listi[i].average();
                brElementi += listi[i].getBroevi();
            }

            

            return suma/brElementi;
        }

        void print() {
            for(int i = 0 ; i<brListi; i++) {
                cout<<"List number: "<<i+1<<" List info: ";
                listi[i].pecati();
            }

            cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
            cout<<"Successful attempts: "<<brListi<<" Failed attempts: "<<brObidi;
        }

};


int main() {

    

    return 0;
}