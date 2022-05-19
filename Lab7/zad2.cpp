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
bool operator== (Number * n1, Number & n2) {
    return n1->doubleValue() == n2.doubleValue();
}

class Integer : public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
    private:
    //TODO da se deklariraat promenlivite
    int number;
    public:
    //TODO konstruktor so eden argument
    Integer(int number = 0) {
        this->number = number;
    }
    //TODO da se prepokrijat metodite od klasata Number
    int intValue() {
        return number;
    }

    double doubleValue() {
        return number;
    }

    void print() {
        cout<<"Integer: "<<number<<endl;
    }
};

class Double : public Number { //TODO da se dodadi izraz za nasleduvanje od Number
    private:
    //TODO da se deklariraat promenlivite
    double number;
    public:
    //TODO konstruktor so eden argument
    Double(double number = 0) {
        this->number = number;
    }
    //TODO da se prepokrijat metodite od klasata Number
    double doubleValue() {
        return number;
    }

    int intValue() {
        return number;
    }

    void print() {
        cout<<"Double: "<<number<<endl;
    }
};

class Numbers{
    private:
    //TODO deklariranje na promenlivite
    void freeMem() {
        delete [] nums;
    }
    Number ** nums;
    int n;
public:
    //TODO default konstruktor
    Numbers() {
        n = 0;
        nums = new Number * [0];
    }
    //TODO copy konstruktor
    Numbers(const Numbers & nm) {
        n = nm.n;
        nums = new Number * [nm.n];
        for(int i = 0 ; i < nm.n ; i++) {
            nums[i] = nm.nums[i];

        }
    }
    //TODO operator =
    Numbers& operator= (const Numbers & nm) {
        if (this != &nm) {
            freeMem();
            Numbers(nm);
        }
        return *this;
    }
    //TODO destruktor
    ~Numbers() {
        freeMem();
    }
    //TODO operator += (operatorot da prima pointer od objekt od Number, a ne referenca)
    Numbers& operator+= (Number * nov) {
        Number ** tmp = new Number * [n+1];
        for(int i = 0 ; i < n ; i++) {
            if(nums[i]->doubleValue() == nov->doubleValue()) {
                return *this;
            } else {
                tmp[i] = nums[i];
            }
        }
        tmp[n++] = nov;

        freeMem();

        nums = tmp;

        return *this;
    }
    //TODO void statistics()
    
    //TODO void integersLessThan (Integer n)
    void integersLessThan (Integer n1) {
        bool flag = false;
        for(int i = 0 ; i < n ; i++) {
            if(dynamic_cast<Integer *>(nums[i])) {
                if(nums[i]->intValue() < n1.intValue()) {
                    nums[i]->print();
                    flag = true;
                }
            }
        }
        if(!flag) {
            cout<<"None"<<endl;
        }
    }
    //TODO void doublesBiggerThan (Double n)
    void doublesBiggerThan (Double n1) {
        bool flag = false;
        for(int i = 0 ; i < n ; i++) {
            if(dynamic_cast<Double *>(nums[i])) {
                if(nums[i]->doubleValue() > n1.doubleValue()) {
                    nums[i]->print();
                    flag = true;
                }
            }
        }
        if(!flag) {
            cout<<"None"<<endl;
        }
    }

    void statistics() {
        cout<<"Count of numbers: "<<n<<endl;

        int brInt= 0 , brDouble = 0;
        int sumaInt = 0;
        double sumaSite= 0, sumaDouble = 0;

        for(int i = 0 ; i < n ; i++) {
            sumaSite += nums[i]->doubleValue();
            //dali e integer
            if(dynamic_cast<Integer *>(nums[i])) {
                brInt++;
                sumaInt += nums[i]->intValue();
            } else {
                brDouble++;
                sumaDouble += nums[i]->doubleValue();
            }
        }

        cout<<"Sum of all numbers: "<<sumaSite<<endl;
        cout<<"Count of integer numbers: "<<brInt<<endl;
        cout<<"Sum of integer numbers: "<<sumaInt<<endl;
        cout<<"Count of double numbers: "<<brDouble<<endl;
        cout<<"Sum of double numbers: "<<sumaDouble<<endl;
    }
};
