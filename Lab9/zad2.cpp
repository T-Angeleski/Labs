#include <iostream>
#include <cstring>
using namespace std;

class ArithmeticException {
    public:
        void message() {
            cout<<"Division by zero is not allowed\n";
        }
};

class NumbersNotDivisibleException {
    int num;
    public:
        NumbersNotDivisibleException(int num) {
            this->num = num;
        }

        void message() {
            cout<<"Division by number "<<num<<" is not supported\n";
        }
};

class ArrayFullException {
    public:
        void message() {
            cout<<"The array is full. Increase the capacity\n";
        }
};

class IndexOutOfBoundsException {
    int index;

    public:
        IndexOutOfBoundsException(int index) {
            this->index = index;
        }

        void message() {
            cout<<"Index "<<index<<" is out of bounds\n";
        }
};

class NumberIsNotPositiveException {
    int num;
    public:
        NumberIsNotPositiveException(int num) {
            this->num = num;
        }

        void message() {
            cout<<"Number "<<num<<" is not positive integer\n";
        }
};

class PositiveIntegers {
    int * numbers;
    int n;
    int capacity;

    public:
        PositiveIntegers(int capacity = 0) {
            this->n = 0;
            this->numbers = new int [0];
            this->capacity = capacity;
        }

        PositiveIntegers(PositiveIntegers & p) {
            this->n = p.n;
            this->capacity = p.capacity;
            this->numbers = new int [p.n];

            for(int i = 0 ; i < p.n ; i++) {
                this->numbers[i] = p.numbers[i];
            }
        }

        PositiveIntegers& operator= (const PositiveIntegers & p) {
            if(this != &p) {
                delete [] numbers;
                this->n = p.n;
            this->capacity = p.capacity;
            this->numbers = new int [p.n];

            for(int i = 0 ; i < p.n ; i++) {
                this->numbers[i] = p.numbers[i];
            }
            }
            return *this;
        }

        ~PositiveIntegers() {
            delete [] numbers;
        }

        void increaseCapacity(int c) {
            int * tmp = new int [n + c];
            for(int i = 0 ; i < n ; i++) {
                tmp[i] = numbers[i];
            }
            delete [] numbers;
            numbers = tmp;
            capacity += c;
        }

        PositiveIntegers& operator+=(int num) {
            if(n == capacity) {
                throw ArrayFullException();
            }
            if(num <= 0) {
                throw NumberIsNotPositiveException(num);
            }

            numbers[n++] = num;
            return *this;
        }

        PositiveIntegers operator* (int num) {
            PositiveIntegers nov(*this);

            for(int i = 0 ; i < nov.n ; i++) {
                nov.numbers[i] *= num;
            }

            return nov;
        }

        PositiveIntegers operator/ (int num) {
            if(num == 0) {
                throw ArithmeticException();
            }
            
            for(int i = 0 ; i < n ; i++) {
                if(numbers[i] % num != 0) {
                    throw NumberIsNotPositiveException(num);
                }
            }

            PositiveIntegers nov(*this);

            for(int i = 0 ; i < nov.n; i++) {
                nov.numbers[i] /= num;
            }

            return nov;
        }

        int& operator[] (int index) {
            if(index < 0 || index >= n)
                throw IndexOutOfBoundsException(index);
            return numbers[index];
        }

        void print() {
            cout<<"Size: "<<n<<" Capacity: "<<capacity<<" Numbers: ";
            for(int i = 0 ; i < n ; i++) {
                cout<<numbers[i]<<" ";
            }
            cout<<endl;
        }
};


int main() {
	
	int n,capacity;
	cin >> n >> capacity;
	PositiveIntegers pi (capacity);
	for (int i=0;i<n;i++){
		int number;
		cin>>number;
        try {
            pi+=number; 
        }
		catch(ArrayFullException &e) {
            e.message();
        }
        catch(NumberIsNotPositiveException &e) {
            e.message();
        }
	}
	cout<<"===FIRST ATTEMPT TO ADD NUMBERS==="<<endl;
	pi.print();
	int incCapacity;
	cin>>incCapacity;
	pi.increaseCapacity(incCapacity);
	cout<<"===INCREASING CAPACITY==="<<endl;
	pi.print();
	
	int n1;
	cin>>n1;
	for (int i=0;i<n1;i++){
		int number;
		cin>>number;
		try {
            pi+=number; 
        }
		catch(ArrayFullException &e) {
            e.message();
        }
        catch(NumberIsNotPositiveException &e) {
            e.message();
        }       
	}
	cout<<"===SECOND ATTEMPT TO ADD NUMBERS==="<<endl;
	
    pi.print();	
	PositiveIntegers pi1;
	
	cout<<"===TESTING DIVISION==="<<endl;	
	
    try {
        pi1 = pi/0;
	    pi1.print();
    }
    catch(ArithmeticException &e) {
        e.message();
    }
    catch(NumbersNotDivisibleException &e) {
        e.message();
    }
    
	
	
	try {
        pi1 = pi/1;
	    pi1.print();
    }
    catch(ArithmeticException &e) {
        e.message();
    }
    catch(NumbersNotDivisibleException &e) {
        e.message();
    }
    

	try {
        pi1 = pi/2;
	    pi1.print();
    }
    catch(ArithmeticException &e) {
        e.message();
    }
    catch(NumbersNotDivisibleException &e) {
        e.message();
    }
    
    
	cout<<"===TESTING MULTIPLICATION==="<<endl;
	pi1 = pi*3;
	pi1.print();
	
	
	cout<<"===TESTING [] ==="<<endl;
    try {
	    cout<<"PositiveIntegers[-1] = "<<pi[-1]<<endl;	
    }
    catch(IndexOutOfBoundsException &e) {
        e.message();
    }

    try {
	    cout<<"PositiveIntegers[2] = "<<pi[2]<<endl;	
    }
    catch(IndexOutOfBoundsException &e) {
        e.message();
    }

    try {
	    cout<<"PositiveIntegers[3] = "<<pi[3]<<endl;	
    }
    catch(IndexOutOfBoundsException &e) {
        e.message();
    }

    try {
	    cout<<"PositiveIntegers[12] = "<<pi[12]<<endl;	
    }
    catch(IndexOutOfBoundsException &e) {
        e.message();
    }	
	
	return 0;
}
