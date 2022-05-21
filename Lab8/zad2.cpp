#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

class Igrachka {
public:
    virtual float getVolumen() = 0;
    virtual float getMasa() = 0;
    //дополнително барање 1
    virtual float getPlostina() =0;
};

class Forma {
protected:
    char boja[100];
    int gustina;
public:
    // да се имплементираат потребните методи
    Forma(char * boja = "", int gustina = 0) {
        strcpy(this->boja, boja);
        this->gustina = gustina;
    }
};

class Topka : public Forma, public Igrachka {
    int radius;

    public:
        Topka(char * boja = "", int gustina = 0, int radius = 0) : Forma(boja,gustina,radius),  Igrachka() {
            this->radius = radius;
        }

        float getVolumen() {
            return 4/3 * 3.14f * radius * radius * radius;
        }

        float getMasa() {
            return gustina * getVolumen();
        }

        float getPlostina() {
            return 4 * 3.14f * radius * radius;
        }
};

class Kocka : public Forma, public Igrachka {
    int height;
    int width;
    int depth;

    public:
        Kocka(char * boja = "", int gustina = 0, int height = 0, int width = 0, int depth = 0) : Forma(boja, gustina), Igrachka() {
            this->height = height;
            this->width = width;
            this->depth = depth;
        }

        float getVolumen() {
            return (float)height * width * depth;
        }

        float getMasa() {
            return gustina * getVolumen();
        }

        float getPlostina() {
            //SA=2lw+2lh+2hw
            return 2 * height * width + 2 * height * depth + 2 * width * depth;
        }
};



int main(){
	//vnesi informacii za kupche
    int n;
    int tip;
    char boja[100];
    int gustina;
    int radius;
    int visina;
    int sirina;
    int dlabocina;

    cin>>n;

	Igrachka ** kupche = new Igrachka * [n];

    for(int i = 0 ; i < n ; i++) {
        cin>>tip;

        if(tip==1) {
            cin>>boja>>gustina>>radius;
            kupche[i] = new Topka(boja,gustina,radius);
        } else {
            cin>>boja>>gustina>>visina>>sirina>>dlabocina;
            kupche[i] = new Kocka(boja, gustina, visina, sirina, dlabocina);
        }
    }
    
    //vnesi informacii za igrachkata na Petra
    cin>>boja>>gustina>>visina>>sirina>>dlabocina;
    Kocka petra(boja,gustina,visina,sirina,dlabocina);
    
	//baranje 1
    float masa = 0;
    for(int i = 0 ; i < n ; i++) {
        masa += kupche[i]->getMasa();
    }

    if(masa > petra.getMasa()) {
        cout<<"DA\n";
    } else {
        cout<<"NE\n";
    }

	//baranje 2
    //najdi max volumen
    float max = 0;
    float min = 9999999;
    for(int i = 0 ; i < n ; i++) {
        if(kupche[i]->getVolumen() > max) {
            max = kupche[i]->getVolumen();
        }

        if(kupche[i]->getPlostina() < min) {
            min = kupche[i]->getPlostina();
        }
    }

    cout<<"Razlikata e: "<<abs(max - petra.getVolumen())<<endl;
    //дополнително барање 2
    cout<<"Razlikata e: "<<abs(min - petra.getPlostina())<<endl;
	return 0;
}