#include<iostream>
using namespace std;

class Number {
    public:
    //TODO da se deklariraat trite cisto virtuelni metodi
    virtual double doubleValue() =0;
    virtual int intValue() =0;
    virtual void print() =0;
}; 

//ТODO preoptovaruvanje na operatorot == 

class Integer : public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
    private:
    //TODO da se deklariraat promenlivite
    int num;

    public:
    //TODO konstruktor so eden argument
    Integer(int num = 0) {
        this->num = num;
    }
    
    //TODO da se prepokrijat metodite od klasata Number
    double doubleValue() {
        return 
    }
};

class Double { //TODO da se dodadi izraz za nasleduvanje od Number
    private:
    //TODO da se deklariraat promenlivite
    
    public:
    //TODO konstruktor so eden argument
    
    //TODO da se prepokrijat metodite od klasata Number
};

class Numbers{
    private:
    //TODO deklariranje na promenlivite
    
    public:
    //TODO default konstruktor
    
    //TODO copy konstruktor
    
    //TODO operator =
    
    //TODO destruktor
    
    //TODO operator += (operatorot da prima pointer od objekt od Number, a ne referenca)
    
    //TODO void statistics()
    
    //TODO void integersLessThan (Integer n)
    
    //TODO void doublesBiggerThan (Double n)
};
