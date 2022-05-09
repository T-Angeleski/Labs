#include <iostream>
#include <cstring>
using namespace std;

class Kvadrat {
protected:
    double a;

    public:
        Kvadrat(double a = 0) {
            this->a= a;
        }

        Kvadrat(const Kvadrat & k) {
            this->a = k.a;
        }

        double perimetar() {
            return 4*a;
        }

        double plostina() {
            return a*a;
        }

        void pecati() {
            cout<<"Kvadrat so dolzina a="<<a<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;
        }
};

class Pravoagolnik : public Kvadrat { //da se vmetni nasleduvanjeto
    double x;
    double y;

    public:
        Pravoagolnik() : Kvadrat() {
            x = 0;
            y = 0;
        }

        Pravoagolnik(const Kvadrat &k, double x, double y) : Kvadrat(k) {
            this->x = x;
            this->y = y;
        }

        Pravoagolnik(const Pravoagolnik & p) : Kvadrat(p) {
            x = p.x;
            y = p.y;
        }

        double perimetar() {
            if(x==y) {
                return Kvadrat::perimetar();
            } else
                return (2 * (a+x)) + (2 * (a+y));
        }

        double plostina() {
            if(x==y) {
                a+=x;
                return Kvadrat::plostina();
            } else
            return (a+x) * (a+y);
        }

        void pecati() {
            if( a+x == a+y ) {
                a += x;
                Kvadrat::pecati();
            } else {
                cout<<"Pravoagolnik so strani: "<<a+x<<" i "<<a+y<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;
            }
        }
};