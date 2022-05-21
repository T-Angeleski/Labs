#include<cstring>
#include<iostream>
using namespace std;

class Secret{
    public:
    //deklariranje na chisto virtuelnite metodi
    virtual double simpleEntropy() =0;
    virtual int total() =0;
};

//preoptovaruvanje na operator ==

//preoptovaruvanje na operator !=

class DigitSecret : public Secret{ //da se dopolni so izraz za nasleduvanje
    private:
    // da se deklariraat potrebnite promenlivi
    int digits[100];
    public:
    //default konstruktor
    DigitSecret() {
        for(int i = 0 ; i < 100 ; i++) {
            digits[i] = 0;
        }
    }
    //konstruktor so argumenti
    DigitSecret(int * digits) {
        for(int i = 0 ; i < 100 ; i++) {
            this->digits[i] = digits[i];
        }
    }
    //prepokrivanje na dvata chisto virtuelni metodi od Secret
    double simpleEntropy() {
        // brojot na unikatni cifri / br na vk znaci
    }
    //preoptovaruvanje na operatorot za pechatenje <<
    
    
};

class CharSecret { //da se dopolni so izraz za nasleduvanje
    private:
    // da se deklariraat potrebnite promenlivi
    
    public:
    //default konstruktor
    
    //konstruktor so argumenti
    
    //prepokrivanje na dvata chisto virtuelni metodi od Secret
    
    //preoptovaruvanje na operatorot za pechatenje <<
    
    
};

//void process(Secret ** secrets, int n){}

//void printAll (Secret ** secrets, int n) {}
