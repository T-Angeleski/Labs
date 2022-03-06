#include <iostream>
using namespace std;

class Agol {
    private:
        int stepeni, minuti, sekundi;
    
    public:
        //-Constructor-
        Agol() {};
        
        ~Agol() {};

        // --SETTERI --
        void set_stepeni(int s) {
            stepeni = s;
        }

        void set_minuti(int m) {
            minuti = m;
        }

        void set_sekundi(int s) {
            sekundi = s;
        }

        //-------------GETTERI-----------
        int getStepeni() {
            return stepeni;
        }

        int getMinuti() {
            return minuti;
        }

        int getSekundi() {
            return sekundi;
        }

        //-----------Metodi---------
        int to_sekundi() {
            int totalSekundi = sekundi + (minuti*60) + (stepeni * 3600);
            return totalSekundi;
        }

};



int proveri(int stepeni, int minuti, int sekundi) {
        if(stepeni > 360 || stepeni < 0) {
            cout<<"Nevalidni vrednosti za agol";
            return 0;
        }
        if(minuti >= 60 || minuti < 0) {
            cout<<"Nevalidni vrednosti za agol";
            return 0;
        }
        if(sekundi >= 60 || sekundi < 0) {
            cout<<"Nevalidni vrednosti za agol";
            return 0;
        }
        return 1;
    }

bool changeOfSeconds(Agol a, int sec){
	return a.getSekundi()!=sec;
}

int main() {
    // Да се дефинира класа Agol, во која се чуваат информации за:

    // степени, минути и секунди (int)

    // Во класата да се реализираат:

    //     конструктор по потреба
    //     методи за поставување на вредности на атрибутите на класата (set методи)
    //     метод за пресметување на вредноста на аголот во секунди

    // Да се дефинира и метод за проверување на тоа дали внесениот агол е валиден, односно дали се внесени соодветни вредности за атрибутите (во границите кои ги дозволуваат).
    


    //da se instancira objekt od klasata Agol
    Agol a1;
    int deg, min, sec;
    cin >> deg >> min >> sec;
    
    if (proveri(deg, min, sec)) {
    
    	a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1,sec))
			cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;
        
    }
    
    return 0;
}
