#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

enum typeC {
    standard, loyal, VIP
};

class UserExistsException {
    public:
        void message() {
            cout<<"The user already exists in the list\n";
        }
};

class Customer {
    char name[50];
    char email[50];
    typeC tc;
    static int BASE_DISCOUNT;
    const static int ADDED_DISCOUNT;
    int num;

    public:

        Customer() {
            strcpy(this->name, "name");
            strcpy(this->email, "email");
            this->tc = standard;
            this->num = 0;
        }

        Customer(const char * name, const char * email, typeC tc, int num) {
            strcpy(this->name, name);
            strcpy(this->email, email);
            this->tc = tc;
            this->num = num;
        }

        Customer (const Customer & c) {
            strcpy(this->name, c.name);
            strcpy(this->email, c.email);
            this->tc = c.tc;
            this->num = c.num;
        }

        Customer& operator= (const Customer & c) {
            if(this != &c) {
                strcpy(this->name, c.name);
                strcpy(this->email, c.email);
                this->tc = c.tc;
                this->num = c.num;
            }
            return *this;
        }

        int discount() {
            if(tc == loyal) {
                return BASE_DISCOUNT;
            } else if(tc == VIP) {
                return ADDED_DISCOUNT;
            } else  
                return 0;
        }

        char * getEmail() {
            return email;
        }

        int getNum() {
            return num;
        }

        typeC getType() {
            return tc;
        }

        static void setDiscount1(int n) {
            BASE_DISCOUNT = n;
        }

        void setType(typeC t) {
            tc = t;
        }

        friend ostream& operator<< ( ostream& out, Customer & c) {
            out<<c.name<<endl;
            out<<c.email<<endl;
            out<<c.num<<endl;
            if(c.tc == standard) {
                out<<"standard ";
            } else if(c.tc == loyal) {
                out<<"loyal ";
            } else {
                out<<"vip ";
            }

            out<<c.discount()<<endl;
            return out;
        }

};
int Customer::BASE_DISCOUNT = 10;
const int Customer::ADDED_DISCOUNT = 30;

class FINKI_bookstore {
    Customer * customers;
    int n;

    public:
        FINKI_bookstore() {
            customers = new Customer [0];
            n = 0;
        }

        FINKI_bookstore(const FINKI_bookstore & f) {
            n = f.n;
            customers = new Customer [f.n];
            for(int i = 0 ; i < f.n ; i++) {
                customers[i] = f.customers[i];
            }
        }

        FINKI_bookstore& operator= (const FINKI_bookstore & f) {
            if(this != &f) {
                delete [] customers;
                n = f.n;
                customers = new Customer [f.n];
                for(int i = 0 ; i < f.n ; i++) {
                    customers[i] = f.customers[i];
                }
            }
            return *this;
        }

        ~FINKI_bookstore() {
            delete [] customers;
        }

       
        void setCustomers(Customer * cust, int n) {
            this->n = n;
            delete [] customers;
            customers = new Customer [n];
            for(int i = 0 ; i < n ; i++) {
                customers[i] = cust[i];
            }
        }

        FINKI_bookstore& operator+=(Customer & c) {
            //check if user already in
            for(int i = 0 ; i < n ; i++) {
                if(!strcmp(customers[i].getEmail(), c.getEmail()))
                    throw UserExistsException();
            }

            Customer *tmp = new Customer [n+1];
            for(int i = 0 ; i < n ; i++) {
                tmp[i] = customers[i];
            }
            tmp[n++] = c;
            delete [] customers;
            customers = tmp;
            return *this;
        }

        void update() {
            for(int i = 0 ; i < n ; i++) {
                if((customers[i].getType() == standard) && (customers[i].getNum() > 5)) {
                    customers[i].setType(loyal);
                }

                if((customers[i].getType() == loyal) && (customers[i].getNum() > 10)) {
                    customers[i].setType(VIP);
                }
            }
        }

        friend ostream& operator<< ( ostream& out, FINKI_bookstore& f) {
            for(int i = 0 ; i < f.n; i++) {
                out<<f.customers[i];
            }
            return out;
        }
};


int main(){
  int testCase;
  cin >> testCase;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setDiscount1(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;

    cout << fc;
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception!!!) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      try {
        Customer c(name, email, (typeC) tC, numProducts);
        customers[i] = c;
      }
      catch (UserExistsException & e) {
        e.message();
      }
      
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;
    
    cout << fc;
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;
   
}
