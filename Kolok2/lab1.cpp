#include <iostream>
#include <cstring>
using namespace std;

class Book {
protected:
    char ISBN[21];
    char title[20];
    char author[30];
    float basePrice;

    public:
        Book(char * ISBN, char * title, char * author, float basePrice) {
            strcpy(this->ISBN, ISBN);
            strcpy(this->title, title);
            strcpy(this->author, author);
            this->basePrice = basePrice;
        }

        Book(const Book & b) {
            strcpy(this->ISBN, b.ISBN);
            strcpy(this->title, b.title);
            strcpy(this->author, b.author);
            this->basePrice = b.basePrice;
        }

        Book& operator= (const Book & b) {
            if(this != &b) {
                strcpy(this->ISBN, b.ISBN);
                strcpy(this->title, b.title);
                strcpy(this->author, b.author);
                this->basePrice = b.basePrice;
            }
            return *this;
        }

        virtual float bookPrice() =0;

        void setISBN(char * i) {
            strcpy(ISBN, i);
        }

        friend ostream & operator << (ostream & out, Book & ob) {
            return out << ob.ISBN <<": "<<ob.title<<", "<<ob.author<<" "<<ob.bookPrice()<<endl;
        }

        
};

class OnlineBook : public Book {
    char * url;
    int size;

    public:
        OnlineBook(char * ISBN, char * title, char * author, float basePrice, char * url, int size)
            : Book(ISBN, title, author, basePrice) {
            this->url = new char [50];
            strcpy(this->url, url);
            this->size = size;
        }

        OnlineBook(OnlineBook & ob) : Book(ob){
            this->url = new char [strlen(ob.url)+1];
            strcpy(this->url, ob.url);
            this->size = ob.size;
        }

        OnlineBook& operator= (OnlineBook & ob) {
            if(this != &ob) {
                delete [] url;
                strcpy(this->ISBN, ob.ISBN);
                strcpy(this->title, ob.title);
                strcpy(this->author, ob.author);
                this->basePrice = ob.basePrice;
                
                this->url = new char [strlen(ob.url)+1];
                strcpy(this->url, ob.url);
                this->size = ob.size;
            }
            return *this;
        }

        ~OnlineBook() {
            delete [] url;
        }

        float bookPrice()  {
            if(size > 20) {
                basePrice *= 1.2f;
            }
            return basePrice;
        }

        
};

class PrintBook : public Book {
    float mass;
    bool inStock;

    public:
        PrintBook(char * ISBN, char * title, char * author, float basePrice, float mass, bool inStock)
            : Book(ISBN, title, author, basePrice) {
            this->mass = mass;
            this->inStock = inStock;
        }

        PrintBook(PrintBook & pb) : Book(pb) {
            this->mass = pb.mass;
            this->inStock = pb.inStock;
        }

        PrintBook& operator= (PrintBook & pb) {
            if(this != &pb) {
                strcpy(this->ISBN, pb.ISBN);
                strcpy(this->title, pb.title);
                strcpy(this->author, pb.author);
                this->basePrice = pb.basePrice;
                
                this->mass = pb.mass;
                this->inStock = pb.inStock;
            }
        }

        float bookPrice()  {
            if(mass > 0.7) {
                basePrice *= 1.15f;
            }
            return basePrice;
        }

};

bool operator > (Book & b1, Book & b2) {
    return b1.bookPrice() > b2.bookPrice();
}

void mostExpensiveBook (Book** books, int n) {
    int ob = 0; //brojac online books
    int pb = 0;
    int maxIndex;
    float max = 0;

    for(int i = 0 ; i < n; i++) {
        if(dynamic_cast<OnlineBook *>(books[i]))
            ob++;
        
        if(dynamic_cast<PrintBook *>(books[i])) 
            pb++;

        if(books[i]->bookPrice() > max) {
            max = books[i]->bookPrice();
            maxIndex = i;
        }
    }
    cout << "FINKI-Education" << endl;
    cout<<"Total number of online books: "<<ob<<endl;
    cout<<"Total number of print books: "<<pb<<endl;
    cout<<"The most expensive book is:\n";
    cout<<*books[maxIndex]<<endl;
}

int main(){

	char isbn[20], title[50], author[30], url[100];
	int size, tip;
	float price, weight;
	bool inStock;
	Book  **books;
	int n;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing OnlineBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> url;
			cin >> size;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new OnlineBook(isbn, title, author, price, url, size);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 2){
		cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
		cin >> isbn;
		cin.get();
		cin.getline(title, 50);
		cin.getline(author, 30);
		cin >> price;
		cin >> url;
		cin >> size;
		cout << "CONSTRUCTOR" << endl;
		OnlineBook ob1(isbn, title, author, price, url, size);
		cout << ob1 << endl;
		cout << "COPY CONSTRUCTOR" << endl;
		OnlineBook ob2(ob1);
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
		cout << "OPERATOR =" << endl;
		ob1 = ob2;
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
	}
	if (testCase == 3){
		cout << "====== Testing PrintBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> weight;
			cin >> inStock;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 4){
		cout << "====== Testing method mostExpensiveBook() ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i<n; i++){

			cin >> tip >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			if (tip == 1) {

				cin >> url;
				cin >> size;

				books[i] = new OnlineBook(isbn, title, author, price, url, size);

			}
			else {
				cin >> weight;
				cin >> inStock;

				books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			}
		}

		mostExpensiveBook(books, n);
	}

	for (int i = 0; i<n; i++) delete books[i];
		delete[] books;
	return 0;
}