#include<iostream>
#include <cstring>
#include<cmath>
using namespace std;

class ComplexNumber {
    double real;
    double imaginary;

    public:
        ComplexNumber(double real=0, double imaginary=0) {
            this->real = real;
            this->imaginary = imaginary;
        }

        ComplexNumber(const ComplexNumber & n) {
            this->real = n.real;
            this->imaginary = n.imaginary;
        }

        double module() {
            return sqrt(pow(real,2) + pow(imaginary,2));
        }

        ComplexNumber& operator= (const ComplexNumber & n) {
            if( this!=&n ) {
                this->real = n.real;
                this->imaginary = n.imaginary;
            }
            return *this;
        }

        friend ostream& operator<<(ostream & out, const ComplexNumber & n) {
            if(n.imaginary == 0) {
                out << n.real;
            } else if (n.real == 0) {
                out << n.imaginary<<"i";
            } else {
                out << n.real<<"+"<< n.imaginary<<"i";
            }
            out<<endl;
            return out;
        }

        ComplexNumber operator+(ComplexNumber & n) {
            ComplexNumber tmp(real+n.real, imaginary+n.imaginary);
            return tmp;
        }

        ComplexNumber operator-(ComplexNumber & n) {
            ComplexNumber tmp(real-n.real, imaginary-n.imaginary);
            return tmp;
        }

        ComplexNumber operator*(ComplexNumber & n) {
            ComplexNumber tmp(real * n.real, imaginary * n.imaginary);
            return tmp;
        }

        ComplexNumber operator/(ComplexNumber & n) {
            ComplexNumber tmp(real / n.real, imaginary / n.imaginary);
            return tmp;
        }

        bool operator==(ComplexNumber & n) {
            return ( (real == n.real) && (imaginary == n.imaginary) );
        }

        bool operator>(ComplexNumber & n) {
            if( real == n.real ) {
                return imaginary > n.imaginary;
            } else {
                return real > n.real;
            }
        }

        bool operator<(ComplexNumber & n) {
            if( real == n.real ) {
                return imaginary < n.imaginary;
            } else {
                return real < n.real;
            }
        }

};

class Equation {
    ComplexNumber * numbers;
    char * operators;
    int n;

    public:
        Equation(int n = 0) {
            numbers = new ComplexNumber [100];
            operators = new char [100];
            this->n = n;
        }

        Equation(const Equation & e) {
            strcpy(operators, e.operators);

            n = e.n;

            for(int i = 0 ; i < e.n ; i++) {
                numbers[i] = e.numbers[i];
            }
        }

        Equation& operator= (const Equation & e) {
            if(this != &e) {
                delete [] numbers;
                delete [] operators;

                strcpy(operators, e.operators);

                n = e.n;

                for(int i = 0 ; i < e.n ; i++) {
                    numbers[i] = e.numbers[i];
                }
            }
            return *this;
        }

        ~Equation() {
            delete [] numbers;
            delete [] operators;
        }

        friend istream& operator>> (istream & in, Equation & e) {
            int i=0;
            double broevi[2];
            while(true) {
                in >> broevi[0] >> broevi[1];
                in >> e.operators[i];
                e.numbers[i] = ComplexNumber(broevi[0], broevi[1]);
                i++;
                
                if(e.operators[i] == '=') {
                    break;
                }
            }
            e.n = i;
            return in;
        }

        ComplexNumber result() {
            ComplexNumber tmp = numbers[0];

            for(int i = 0 ; i < n ; i++) {

                switch (operators[i]) {
                    case '+':
                        tmp = tmp + numbers[i+1];
                        break;
                    case '-':
                        tmp = tmp - numbers[i+1];
                        break;
                    case '*':
                        tmp = tmp * numbers[i+1];
                        break;
                    case '/':
                        tmp = tmp / numbers[i+1];
                        break;
                    default:
                        break;
                }
            }

            return tmp;
        }

        double sumModules() {
            double sum=0;

            for(int i = 0 ; i < n ; i++) {
                sum += numbers[i].module();
            }

            return sum;
        }
};

int main() {return 0;}