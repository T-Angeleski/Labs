#include <iostream>
#include <cstring>
using namespace std;

// vashiot kod ovde
class FudbalskaEkipa {
protected:
    char coach[100];
    int goals[10];

    public:
        FudbalskaEkipa( char* coach,int * goals) {
            strcpy(this->coach, coach);
            for(int i = 0 ; i < 10 ; i++) {
                this->goals[i] = goals[i];
            }
        }

        virtual int uspeh() =0;
        
        FudbalskaEkipa& operator+= (int novGol) {
            
            for(int i = 0 ; i < 9 ; i++) {
                goals[i] = goals[i+1];
            }
            goals[9] = novGol;
            return *this;
        }

        bool operator> (FudbalskaEkipa& fe) {
            return uspeh() > fe.uspeh();
        }

        const char* getCoach() const{
            return coach;
        }
};

class Klub : public FudbalskaEkipa {
    char name[100];
    int titles;

    public:
        Klub( char* coach = "",int * goals = NULL, const char* name = "",
            int titles = 0) : FudbalskaEkipa(coach, goals) {
                strcpy(this->name, name);
                this->titles = titles;
        }

        int uspeh() {
            int zbir=0;
            for(int i = 0 ; i < 10 ; i++) {
                zbir += goals[i];
            }
            zbir *=3;
            zbir += 1000*titles;
            return zbir;
        }

        const char* getName() const{
            return name;
        }

};

class Reprezentacija : public FudbalskaEkipa {
    char country[50];
    int international;

    public:
        Reprezentacija( char* coach = "",int * goals = NULL, const char* country = "", int international = 0)
            :FudbalskaEkipa(coach, goals) {
            strcpy(this->country,country);
            this->international = international;
        }

        int uspeh() {
            int zbir=0;
            for(int i = 0 ; i < 10 ; i++) {
                zbir +=goals[i];
            }
            zbir *= 3;
            zbir += 50*international;
            return zbir;
        }

        const char* getCountry() const{
            return country;
        }
};

ostream& operator<<(ostream& out, FudbalskaEkipa& f) {
        if(dynamic_cast<Klub *>(&f)) {
             out<< dynamic_cast<Klub*>(&f)->getName()<<endl;
        } else {
             out<<dynamic_cast<Reprezentacija*>(&f)->getCountry()<<endl;
        }
        return out<<f.getCoach()<<endl<<f.uspeh()<<endl;
}

void najdobarTrener(FudbalskaEkipa ** teams, int n) {
    int max = 0;
    int maxIndex;

    for(int i = 0 ; i < n ; i++) {
        if(teams[i]->uspeh() > max) {
            max = teams[i]->uspeh();
            maxIndex = i;
        }
    }

    cout<<*teams[maxIndex];
}

int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}