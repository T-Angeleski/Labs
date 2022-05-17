#include<iostream>
#include<cstring>
using namespace std;

class Task{
    protected:
    //deklariranje na promenlivite
    char ID[5];
    public:
    //konstruktor
    Task(char * ID = "") {
        strcpy(this->ID, ID);
    }
    //destruktor
    ~Task(){}
    //2 chisto virtuelni metodi (print i getOrder)
    virtual int getOrder() =0;
    virtual void print() =0;

    char * getID() {
        return ID;
    }
};

//Preoptovaruvanje na operatorot za sporedba == (prima 2 argumenti bidejki se definira nadvor od klasata Task)
bool operator== (Task  *t1, Task & t2) {
    return !strcmp(t1->getID(), t2.getID()) && t1->getOrder() == t2.getOrder();
}

class TimedTask : public Task {//izraz za nasleduvanje od Task
    private:
    //deklariranje na dopolnitelni promenlivi
    int time;
    public:
    //konstruktor
    TimedTask(char * ID = "", int time = 0) : Task(ID) {
        this->time = time;
    }
    //prepokrivanje na 2ta metodi shto se nasleduvaat od Task    
    int getOrder() {
        return time;
    }

    void print() {
        cout<<"TT->"<<ID<<":"<<time<<endl;
    }
};

class PriorityTask : public Task {
    private:
    //deklariranje na dopolnitelni promenlivi
    int priority;
    public:
    //konstruktor
    PriorityTask(char * ID = "", int priority = 0) : Task(ID) {
        this->priority = priority;
    }
    //prepokrivanje na 2ta metodi shto se nasleduvaat od Task 
    int getOrder() {
        return priority;
    }

    void print() {
        cout<<"PT->"<<ID<<":"<<priority<<endl;
    }
};

//void scheduleTimedTasks(Task ** tasks, int n, int t) {}
void scheduleTimedTasks (Task ** tasks, int n, int t) {
    //sort first print later
    for(int i = 0 ; i < n ; i++) {
        for(int j = i + 1 ; j < n ; j++) {
            if(tasks[i]->getOrder() > tasks[j]->getOrder()) {
                Task * tmp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = tmp;
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        if(dynamic_cast<TimedTask *>(tasks[i])) {
            if(tasks[i]->getOrder() < t) {
                tasks[i]->print();
            }
        }
    }
}

//void schedulePriorityTasks(Task ** tasks, int n, int p) {}
void schedulePriorityTasks (Task ** tasks, int n, int t) {
    //sort first print later
    for(int i = 0 ; i < n ; i++) {
        for(int j = i + 1 ; j < n ; j++) {
            if(tasks[i]->getOrder() > tasks[j]->getOrder()) {
                Task * tmp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = tmp;
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        if(dynamic_cast<PriorityTask *>(tasks[i])) {
            if(tasks[i]->getOrder() < t) {
                tasks[i]->print();
            }
        }
    }
}