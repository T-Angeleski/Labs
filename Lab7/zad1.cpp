#include<iostream>
#include<cstring>
using namespace std;

class Employee {
protected:
    char name[50];
    int age;
    int experience;

    public:

        Employee(char * name = "", int age = 0, int experience = 0) {
            strcpy(this->name, name);
            this->age = age;
            this->experience = experience;
        }

        Employee(const Employee & e) {
            strcpy(this->name, e.name);
            this->age = e.age;
            this->experience = e.experience;
        }

        virtual double plata() =0;
        virtual double bonus() =0;
};

class SalaryEmployee : public Employee {
    int wage;

    public:

        SalaryEmployee() : Employee() {
            wage = 0;
        }

        SalaryEmployee(char * name, int age, int experience, int wage) : Employee(name, age, experience) {
            this->wage = wage;
        }

        SalaryEmployee(const SalaryEmployee & se) : Employee(se) {
            this->wage = se.wage;
        }

        double bonus() {
            return wage + (experience /100 * wage);
        }

        double plata() {
            return wage + bonus();
        }
};

class HourlyEmployee  : public Employee {
    int hours;
    int payPerHour;

    public:
        HourlyEmployee() : Employee() {
            hours = 0;
            payPerHour = 0;
        }

        HourlyEmployee(char * name, int age, int experience, int hours, int payPerHour) : Employee(name, age, experience) {
            this->hours = hours;
            this->payPerHour = payPerHour;
        }

        HourlyEmployee(const HourlyEmployee & he) : Employee(he) {
            this->hours = he.hours;
            this->payPerHour = he.payPerHour;
        }

        double bonus() {
            // бонусот се пресметува на следниот начин: За секој час над 320-тиот се добива 50 проценти од платата по час.
            if(hours > 320) {
                return (hours - 320) * (payPerHour * 0.5);
            }
            return 0;
        }

        double plata() {
            // Вкупната плата се пресметува како бројот на часови помножен со платата по час плус бонусот
            return (hours * payPerHour) + bonus();
        }
};

class Freelancer : public Employee {
    int numProjects;
    double projects[100];

    public:
        Freelancer() :Employee() {
            numProjects = 0;
            for(int i = 0 ; i < 100 ; i++) {
                projects[i] = 0;
            }
        }

        Freelancer(char * name, int age, int experience, int numProjects, double * projects) : Employee(name, age, experience) {
            this->numProjects = numProjects;
            for(int i = 0 ; i < numProjects; i++) {
                this->projects[i] = projects[i];
            }
        }

        Freelancer(const Freelancer & f) : Employee(f) {
            this->numProjects = f.numProjects;
            for(int i = 0 ; i < f.numProjects; i++) {
                this->projects[i] = f.projects[i];
            }
        }

        double bonus() {
            if(numProjects > 5) {
                return 1000 * (numProjects - 5);
            }
            return 0;
        }

        double plata() {
            double sum = 0;
            for(int i = 0 ; i < numProjects ; i++) {
                sum += projects[i];
            }
            return sum + bonus();
        }

        bool operator== (Freelancer & f) {
            return (age == f.age) && (bonus() == f.bonus());
        }
};

class Company {
    char companyName[50];
    int numEmployees;
    Employee ** employees;

    public:
        Company(char * companyName = "") {
            strcpy(this->companyName, companyName);
            numEmployees = 0;
            employees = new Employee *[0];
        }

        ~Company() {
            delete [] employees;
        }

        Company& operator+= (Employee & e) {
            Employee ** tmp = new Employee *[numEmployees+1];
            for(int i = 0 ; i < numEmployees ; i++) {
                tmp[i] = employees[i];
            }

            tmp[numEmployees++] = e;

            delete [] employees;

            employees = tmp;

            return *this;
        }

        double vkupnaPlata() {
            double sum = 0;
            for(int i = 0 ; i < numEmployees ; i++) {
                sum += employees[i]->plata();
            }
            return sum;
        }

        double filtriranaPlata(Employee * emp) {
            double sum=0;
            for(int i = 0 ; i < numEmployees ; i++) {
                if(*employees[i] == *emp) {
                    sum+= employees[i]->plata();
                }
            }
            return sum;
        }

        void pecatiRabotnici() {
            cout<<"Vo kompanijata "<<companyName<<" rabotat: "<<endl;
        }
};