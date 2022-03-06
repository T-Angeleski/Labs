#include <iostream>
#include <cstring>
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


class Krug {
    private:
        float radius;
        const float pi = 3.14;

    public:
        //Default
        Krug() {
            radius = 5;
        }
        //So argumenti
        Krug(float r) {
            radius = r;
        }

        ~Krug() {};

        void setRadius(float r) {
            radius = r;
        }

        //Metodi
        float plostina() {
            return radius * radius * pi;
        }
        float perimetar() {
            return 2 * radius * pi;
        }

        float ednakvi() {
            if(plostina() == perimetar()) {
                return 1;
            } else {
                return 0;
            }
        }
};


class Film {
    private:
        char ime[100];
        char reziser[50];
        char zanr[50];
        int godina;
    public:
        Film() {
            ime = "Spider Man - Far From Home";
            reziser = "Jon Watts";
            zanr = "Action";
            godina = 2022;
        }

        Film(char *i, char *r, char *z, int g) {
            strcpy(ime, i);
            strcpy(reziser, r);
            strcpy(zanr, z);
            godina = g;
        }

        void setIme(char *i) {
            strcpy(ime,i);
        }
        void setReziser(char *r) {
            strcpy(reziser,r);
        }
        void setZanr(char *z) {
            strcpy(zanr,z);
        }
        void setGodina(int g) {
            godina = g;
        }


        int getGodina() {
            return godina;
        }

        void pecati() {
            cout<<"Ime: "<<ime<<endl;
            cout<<"Reziser: "<<reziser<<endl;
            cout<<"Zanr: "<<zanr<<endl;
            cout<<"Godina: "<<godina<<endl;
        }
};



// -------FUNKCII------


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

void pecati_po_godina(Film *f, int n, int godina) {
    for(int i=0;i<n;i++) {
        int currGod = f[i].getGodina();
        if(currGod == godina) {
            f[i].pecati();
        }
    }
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

//     Да се дефинира класа Krug, во која се чуваат информации за:

//     радиус float
//     бројот π const float.

// Во класата да се реализираат:

//     default конструктор и конструктор со аргументи
//     метод за пресметување плоштина
//     метод за пресметување периметар
//     метод кој кажува дали плоштината и периметарот на даден круг се еднакви

    float r;
	cin >> r;
	//instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura
    Krug k;
    k.setRadius(r);


	cout << k.perimetar() << endl;
	cout << k.plostina() << endl;
	cout << k.ednakvi() <<endl;
    //instanciraj objekt od klasata Krug cij radius ne e definiran
	Krug k2;



//     Да се дефинира класа Film, во која ќе се чуваат информации за:

//     име низа од 100 знаци
//     режисер низа од 50 знаци
//     жанр низа од 50 знаци
//     година цел број

// Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:

//     default конструктор и конструктор со аргументи
//     метод за печатење на информациите за филмот

// Дополнително да се реализира надворешна функција:

//     void pecati_po_godina(Film *f, int n, int godina) која ќе 
// прима аргумент низа од филмови, вкупниот број на филмови и година, 
// а треба да ги отпечати само филмовите кои се направени во дадената година.

    int n;
 	cin >> n;
 	//da se inicijalizira niza od objekti od klasata Film
    Film f1[n];
 	for(int i = 0; i < n; ++i) {
        char ime[100];
        char reziser[50];
        char zanr[50];
        int godina;
        cin >> ime;
        cin >> reziser;
        cin >> zanr;
        cin >> godina;
 		//da se kreira soodveten objekt
        f1[i].setIme(ime);
        f1[i].setReziser(reziser);
        f1[i].setZanr(zanr);
        f1[i].setGodina(godina);
 	}
 	int godina;
 	cin >> godina;
 	//da se povika funkcijata pecati_po_godina
    pecati_po_godina(f1, n, godina);
    return 0;
}
