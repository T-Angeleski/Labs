
// Your Code goes here
#include <cstring>
#include <iostream>
using namespace std;

enum Size {small, large, family};

class Pizza {
protected:
    char name[20];
    char ingredients[100];
    double basePrice;

    public:
        Pizza() {
            strcpy(name,"");
            strcpy(ingredients, "");
            basePrice = 0;
        }
        Pizza(char *name, char * ingredients, double basePrice) {
            strcpy(this->name, name);
            strcpy(this->ingredients, ingredients);
            this->basePrice = basePrice;
        }

        virtual double price() =0;
        friend ostream &operator<<(ostream &out, Pizza &f);

        bool operator< (Pizza & f);
};

class FlatPizza : public Pizza {
    Size size;

    public:
        FlatPizza() : Pizza() {
            size = (Size)0;
        }

        FlatPizza(char *name, char * ingredients, double basePrice)
        : Pizza(name, ingredients, basePrice) {
            size = (Size)0;
        }

        FlatPizza(char *name, char * ingredients, double basePrice, int size)
        : Pizza(name, ingredients, basePrice) {
            this->size = (Size)size;
        }

        double price() {
            if(size == small) {
                return basePrice * 1.1f;
            } else if(size == large) {
                return basePrice * 1.3f;
            } else {
                return basePrice * 1.5f;
            }
        }

        Size getSize() const {
            return size;
        }
};

class FoldedPizza : public Pizza {
    bool isWhite;

    public:
        FoldedPizza() : Pizza() {
            isWhite = false;
        }
        FoldedPizza(char *name, char * ingredients, double basePrice)
        :Pizza(name,ingredients,basePrice) {
            this->isWhite = isWhite;
        }

        void setWhiteFlour(bool f) {
            this->isWhite = f;
        }

        bool getFlour() const{
            return isWhite;
        }

        double price() {
            if(isWhite) {
                return basePrice * 1.1f;
            } else {
                return basePrice * 1.3f;
            }
        }

};

bool Pizza::operator<(Pizza &p) {
    return price() < p.price();
}

ostream& operator<< (ostream& out, Pizza & f) {
    out<<f.name<<": "<<f.ingredients<<", ";

    if(dynamic_cast<FlatPizza*>(&f)) {
        if(dynamic_cast<FlatPizza*>(&f)->getSize() == small) {
            cout<<"small";
        } else if (dynamic_cast<FlatPizza*>(&f)->getSize() == large) {
            cout<<"large";
        } else {
            cout<<"family";
        }
    } else if (dynamic_cast<FoldedPizza*>(&f)) {
        if(dynamic_cast<FoldedPizza*>(&f)->getFlour()) {
            cout<<"wf";
        } else {
            cout<<"nwf";
        }
    }
    out<<" - "<<f.price()<<endl;
    return out;
}

void expensivePizza (Pizza ** pizzas, int n) {
    double max = pizzas[0]->price();
    int maxIndex;

    for(int i = 0 ; i < n ; i++) {
        if(pizzas[i]->price() > max) {
            max = pizzas[i]->price();
            maxIndex = i;
        }
    }

    cout<<*pizzas[maxIndex]<<endl;
}

// Testing

int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Size size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Size)s);
    cout << fp;
    
  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setWhiteFlour(false);
    cout << fp;

  } else if (test_case == 5) {
	// Test Cast - operator <, price
    int s;
    
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp1;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp2;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setWhiteFlour(false);
    cout << *fp4;
      
    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->price()<<endl;
    else cout<<fp2->price()<<endl;
        
    if(*fp1<*fp3)
        cout<<fp1->price()<<endl;
    else cout<<fp3->price()<<endl;    
        
    if(*fp4<*fp2)
        cout<<fp4->price()<<endl;
    else cout<<fp2->price()<<endl;
    
    if(*fp3<*fp4)
        cout<<fp3->price()<<endl;
    else cout<<fp4->price()<<endl;

  } else if (test_case == 6) {
	// Test Cast - expensivePizza
    int num_p;
    int pizza_type;

    cin >> num_p;
    Pizza **pi = new Pizza *[num_p];
    for (int j = 0; j < num_p; ++j) {

      cin >> pizza_type;
      if (pizza_type == 1) {
        cin.get();
        cin.getline(name,20);
          
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << (*fp);
        pi[j] = fp;
      }
      if (pizza_type == 2) {

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp =
            new FoldedPizza (name, ingredients, inPrice);
        if(j%2)
          (*fp).setWhiteFlour(false);
        cout << (*fp);
        pi[j] = fp;

      }
    }

    cout << endl;
    cout << "The most expensive pizza:\n";
    expensivePizza(pi,num_p);


  }
  return 0;
}
