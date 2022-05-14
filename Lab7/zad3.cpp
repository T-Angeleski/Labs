#include <iostream>
#include <cmath>
using namespace std;


//TODO: konstruiraj ja abstraknata klasa Shape
class Shape {
protected:
    int side;

    public:
        Shape() {
            side = 0;
        }

        Shape(int side) {
            this->side = side;
        }

        virtual double plostina() =0;
        virtual void pecati() =0;
        virtual int getType() =0;
};

//TODO: konstruiraj ja klasata Kvadrat
class Square : public Shape {
    public:
        Square(int side = 0) : Shape(side) {}

        double plostina() {
            return side * side;
        }

        int getType() {
            return 1;
        }

        void pecati() {
            cout<<"Kvadrat so plostina = "<<plostina()<<endl;
        }
};

//TODO: konstruiraj ja klasata Krug
class Circle : public Shape {
    public:
        Circle(int side = 0) : Shape(side) {}

        double plostina() {
            return 3.14 * side * side;
        }

        int getType() {
            return 2;
        }

        void pecati() {
            cout<<"Krug so plostina = "<<plostina()<<endl;
        }
};

//TODO: konstruiraj ja klasata Triagolnik
class Triangle : public Shape {
    public:
        Triangle(int side = 0) : Shape(side) {}

        double plostina() {
            return (sqrt(3)/4) * side * side;
        }

        int getType() {
            return 3;
        }

        void pecati() {
            cout<<"Triagolnik so plostina = "<<plostina()<<endl;
        }
};

//TODO: definiraj go metodot void checkNumTypes(Shape** niza, int n)
void checkNumTypes(Shape** niza, int n) {
    int kvadrati = 0;
    int krugovi = 0;
    int triagolnici = 0;

    for(int i = 0 ; i < n ; i++) {
        if(niza[i]->getType() == 1) {
            kvadrati++;
        } else if (niza[i]->getType() == 2) {
            krugovi++;
        } else {
            triagolnici++;
        }
    }

    cout<<"Broj na kvadrati vo nizata = "<<kvadrati<<endl;
    cout<<"Broj na krugovi vo nizata = "<<krugovi<<endl;
    cout<<"Broj na triagolnici vo nizata = "<<triagolnici<<endl;
}


int main(){


	int n;
	cin >> n;

	//TODO: inicijaliziraj niza od pokazuvachi kon klasata Shape

	Shape ** niza;

	//TODO: alociraj memorija so golemina n za prethodno navedenata niza
	niza = new Shape * [n];

	int classType;
	int side;

	//TODO: konstruiraj for ciklus so chija pomosh ke ja popolnish nizata
	for(int i = 0; i < n; ++i){

		cin >> classType;
		cin >> side;
		
        if(classType == 1) {
            niza[i] = new Square(side);
        } else if (classType == 2) {
            niza[i] = new Circle(side);
        } else {
            niza[i] = new Triangle(side);
        }
	}
    
    
	for(int i = 0; i < n; ++i){

		niza[i]->pecati();
	}

	checkNumTypes(niza, n);


	return 0;
}