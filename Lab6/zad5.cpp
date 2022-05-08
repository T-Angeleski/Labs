
#include <iostream>
#include <cstring>
using namespace std;

class Ekipa {
protected:
    char name[15];
    int wins;
    int losses;

    public:
        Ekipa() {
            strcpy(name, " ");
            wins = 0;
            losses = 0;
        }

        Ekipa(char * name, int wins, int losses) {
            strcpy(this->name, name);
            this->wins = wins;
            this->losses = losses;
        }

        Ekipa(const Ekipa & e) {
            strcpy(this->name, e.name);
            this->wins = e.wins;
            this->losses = e.losses;
        }

        void pecati() {
            cout<<"Ime: "<<name<<" Pobedi: "<<wins<<" Porazi: "<<losses<<" ";
        }

};

class FudbalskaEkipa : public Ekipa {
    int redCards;
    int yellowCards;
    int ties;

    public:
        FudbalskaEkipa() : Ekipa() {
            redCards = 0;
            yellowCards = 0;
            ties = 0;
        }

        FudbalskaEkipa(char * name, int wins, int losses, int yellowCards, int redCards, int ties) : Ekipa(name,wins, losses) {
            this->redCards = redCards;
            this->yellowCards = yellowCards;
            this->ties = ties;
        }

        FudbalskaEkipa(const FudbalskaEkipa & e) : Ekipa(e) {
            this->redCards = e.redCards;
            this->yellowCards = e.yellowCards;
            this->ties = e.ties;
        }

        int getPoints() {
            return wins*3 + ties;
        }

        void pecati() {
            Ekipa::pecati();
            cout<<"Nereseni: "<<ties<<" Poeni: ";
            cout<<getPoints()<<endl;
        }
};


int main () {return 0;}