#include <iostream>
#include <cstring>
using namespace std;

class StockRecord {
    char ID [12];
    char name [50];
    double price;
    double currentPrice;
    int numBought;

    void copy(const StockRecord & other) {
        strcpy(this->ID, other.ID);
        strcpy(this->name, other.name);
        this->price = other.price;
        this->numBought = other.numBought;
        this->currentPrice = other.currentPrice;
    }

    public:
        StockRecord() = default;
        StockRecord(char ID[12], char name[50], double price, int numBought) {
            strcpy(this->ID, ID);
            strcpy(this->name, name);
            this->price = price;
            this->numBought = numBought;
        }

        StockRecord(const StockRecord & sr) {
            copy(sr);
        }

        StockRecord& operator= (const StockRecord &sr) {
            if( this!= &sr) {
                copy(sr);
            }
            return *this;
        }

        ~StockRecord() {}

        void setNewPrice(double c) {
            this->currentPrice = c;
        }

        double value() {
            return numBought * currentPrice;
        }

        double profit() const {
            return numBought * (currentPrice - price);
        }


        friend ostream & operator<< (ostream & out,StockRecord & sr) {
            out << sr.name << " " ;
            out << sr.numBought << " " ;
            out << sr.price << " " ;
            out << sr.currentPrice << " " ;
            out << sr.profit()<< endl;
            return out;
        }
};

class Client {
    char nameClient[60];
    int accID;
    StockRecord * records;
    int num;

    void copy(const Client & other) {
        strcpy(this->nameClient, other.nameClient);
        this->accID = other.accID;
        this->num = other.num;
        for(int i = 0 ; i < other.num ; i++) {
            records[i] = other.records[i];
        }
    }

    public:

    Client() {
        strcpy(nameClient, " ");
        accID = 0;
        records = new StockRecord[0];
        num = 0; //brb
    }

    Client(char *nameClient, int accID) {
        strcpy(this->nameClient, nameClient);
        this->accID = accID;
        num = 0;
        records = new StockRecord[0];
    }

    Client(const Client & c) {
        copy(c);
    }

    Client& operator = (const Client & c) {
        if( this != &c) {
            delete[] records;
            copy(c);
        }
        return *this;
    }

    ~Client() {
        delete [] records;
    }

    double totalValue() {
        double value = 0;
        for(int i = 0 ; i < num; i++) {
            value += records[i].value();
        }

        return value;
    }

    // << за печатење на информации за портфолиото на клиентот така што во првиот ред ќе бидат прикажани ID на сметката и моменталната вредност на портфолиото одделени со празно место, а во секој нареден ред ќе бидат прикажани компаниите од кои е составено портфолиото, секоја во посебен ред

    friend ostream & operator << (ostream & out,Client & c) {
        out << c.accID << " " << c.totalValue() <<endl;
        for(int i = 0 ; i < c.num ; i++) {
            out << c.records[i];
        }

        return out;
    }

    Client& operator += (StockRecord & c) {
        StockRecord * tmp = new StockRecord[num + 1];

        for(int i = 0 ; i < num ; i++) {
            tmp[i] = records[i];
        }

        tmp[num++] = c;

        delete [] records;

        records = tmp;
    }
};


int main() {


    return 0;
}