#include <iostream>
#include <cstring>

using namespace std;

class List {
    int * broevi;
    int n;

    void copy(const List & other) {
        this->n = other.n;
        broevi = new int[n];
        for(int i = 0 ; i < n ; i++) {
            this->broevi[i] = other.broevi[i];
        }
    }

    public:
        List()
        {
            broevi = new int[0];
            n = 0;
        }
        List(int * broevi, int ) {
            this->n = n;
            broevi = new int[n];
            for(int i = 0 ; i < n ; i++) {
                this->broevi[i] = broevi[i];
            }
        }

        List(const List & l) {
            copy(l);
        }

        List& operator=(const List & l) {
            if(this != &l) {
                delete [] broevi;
                copy(l);
            }
            return *this;
        }

        ~List () {
            delete [] broevi;
        }


        int sum() {
            int suma = 0;

            for (int i = 0; i < n; i++) {
                suma += broevi[i];
            }
            
            return suma;
        }

        int average() {
            double avg = sum();
            return (double) sum() / n;
        }

        void pecati() {
            cout<<n<<": ";
            for (int i = 0; i < n; i++){
                cout<<broevi[i]<<" ";
            }
            cout<<"sum:" << sum()<<" average: "<< average()<<endl;
        }

        int getN() {
            return n;
        }
};


class ListContainer {
    List * listi;
    int n;
    int attempts;

    void copy(const ListContainer & other) {
        this->attempts = other.attempts;
        this->n = other.n;
        listi = new List[n];
        for (int i = 0; i < n; i++){
            this->listi[i] = other.listi[i];
        }
    }

    public:
        ListContainer() {
            attempts = 0;
            n = 0;
            listi = new List[50];
        }

        ListContainer(const ListContainer & lc) {
            copy(lc);
        }

        ListContainer& operator=(const ListContainer & lc) {
            if(this != &lc) {
                delete [] listi;
                copy(lc);
            }
            return *this;
        }

        ~ListContainer() {
            delete [] listi;
        }

        int sum() {
            int suma = 0;
            for (int i = 0; i < n; i++){
                suma += listi[i].sum();
            }
            return suma;
        }

        double average() {
            double avg = sum();
            int s=0;
            for(int i = 0 ; i<n;i++) {
                s += listi[i].getN();
            }

            return (double) avg/s;
        }

        void addNewList(List & l) {
            attempts++;
            
            for (int i = 0; i < n; i++){
                if(listi[i].sum() == l.sum() ) {
                    return;
                }
                
            }
            listi[n++] = l;

        }

        void print() {
            if(n == 0) {
                cout<<"The list is empty"<<endl;
            } else {
                for (int i = 0; i < n; i++){
                    cout<<"List number: "<<i+1<<" List info : ";
                    listi[i].pecati();
                }
                cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
                cout<<"Successful attempts: "<<n<<" Failed attempts: "<<attempts - n<<endl;
            }


            
        }
};




int main() {
	
	return 0;
}