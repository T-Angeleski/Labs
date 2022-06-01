#include <iostream>
#include <cstring>

using namespace std;

enum tip {smartphone, laptop};

class InvalidProductionDate {
    public:
        void message() {
            cout<<"Невалидна година на производство\n";
        }
};

class Device {
    char model [100];
    tip deviceType;
    static double HOURS;
    int yearProduced;

    public:
        Device(const char * model = " ",tip deviceType = smartphone, int yearProduced=0) {
            strcpy(this->model, model);
            this->deviceType = deviceType;
            this->yearProduced = yearProduced;
        }

        friend ostream& operator<<(ostream& out, Device& d){
            out<<d.model<<endl;
            
            if(d.deviceType == smartphone)
                out<<"Mobilen ";
            if(d.deviceType == laptop)
                out<<"Laptop ";
            return out<<d.proverka()<<endl;
        }

        double proverka() const{
            double s = 0;

            if(yearProduced > 2015)
                s+= 2;
            if(deviceType == laptop)
                s+= 2;
            return s + HOURS;
        }

        static void setPocetniCasovi(double n) {
            HOURS = n;
        }

        int getGodina() {
            return yearProduced;
        }
};

double Device::HOURS = 1;

class MobileServis {
    char adress[100];
    Device * devices;
    int num;

    void copy(const MobileServis& ms){
        strcpy(this->adress, ms.adress); 
        num = ms.num;
        devices = new Device [ms.num];
        for(int i = 0 ; i< ms.num ; i++)
            devices[i] = ms.devices[i];
    }

    public:
        MobileServis(const char * adress = " "){
            strcpy(this->adress, adress);
            devices = new Device [0];
            num = 0;
        }

        MobileServis(const MobileServis& ms) {
            copy(ms);
        }

        MobileServis& operator= (const MobileServis& ms) {
            if(this != &ms) {
                delete [] devices;
                copy(ms);
            }
            return *this;
        }

        ~MobileServis() {
            delete [] devices;
        }

        MobileServis& operator+= (Device & d) {
            try {
                if(d.getGodina() > 2019 || d.getGodina() < 2000)
                    throw InvalidProductionDate();
            }
            catch (InvalidProductionDate) {
                InvalidProductionDate::message();
                return *this;
            }
            

            Device * nov = new Device [num+1];
            for(int i = 0 ; i < num ; i++)
                nov[i] = devices[i];
            nov[num++] = d;
            delete [] devices;
            devices = nov;
            return *this;
        }

        void pecatiCasovi() {
            cout<<"Ime: "<<adress<<endl;
            for(int i = 0 ; i < num ; i++)
                cout<<devices[i];
        }
};

int main()
{
	int testCase;
	cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> tipDevice;
		cin >> godina;
		Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
		MobileServis t(ime);
        cout<<ig;
		}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        t.pecatiCasovi();
	}
	if (testCase == 3){
		cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        t.pecatiCasovi();
	}
	if (testCase == 4){
		cout <<"===== Testiranje na konstruktori ======"<<endl;
		 cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}
	if (testCase == 5){
		cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

            t+=tmp;
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
		Device::setPocetniCasovi(2);
        t.pecatiCasovi();
	}

		if (testCase == 6){
		cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
		cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
		Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}

	return 0;

}

