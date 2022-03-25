#include<iostream>
#include<cstring>

using namespace std;

enum Extension {
    txt,
    pdf,
    exe
};


class File{
    char * ime;
    Extension extenzija;
    char * owner;
    int fileSize;

    public:
        File() {}
        File(char *ime, Extension extenzija, char * owner, int fileSize) {
            this->extenzija = extenzija;
            this->fileSize = fileSize;

            this->ime = new char [strlen(ime)+1];
            this->owner = new char [strlen(owner)+1];

            strcpy(this->ime, ime);
            strcpy(this->owner, owner);
        }

        File(const File & f) { //copy const
            extenzija = f.extenzija;
            fileSize = f.fileSize;

            ime = new char [strlen(f.ime)+1];
            owner = new char [strlen(f.owner)+1];

            strcpy(ime, f.ime);
            strcpy(owner, f.owner);
        }

        ~File() {
            delete [] ime;
            delete [] owner;
        }

        File& operator=(const File & f) {
            if(this==&f) {
                return *this;
            }

            extenzija = f.extenzija;
            fileSize = f.fileSize;

            delete [] ime;
            delete [] owner;

            ime = new char [strlen(f.ime)+1];
            owner = new char [strlen(f.owner)+1];

            strcpy(ime, f.ime);
            strcpy(owner, f.owner);

            return *this;
        }


        void print() {
            if (extenzija == 0) {
                cout<<"File name: "<<ime<<"."<<"txt"<<endl;
            }
            else if(extenzija == 1) {
                cout<<"File name: "<<ime<<"."<<"pdf"<<endl;
            }
            else {
                cout<<"File name: "<<ime<<"."<<"exe"<<endl;
            }
            cout<<"File owner: "<<owner<<endl;
            cout<<"File size: "<<fileSize<<endl<<endl;
        }

        bool equals(const File & f) {
            if(strcmp(ime, f.ime) || strcmp(owner, f.owner) || extenzija != f.extenzija) {
                return false;
            }

            return true;
        }

        bool equalsType(const File & f) {
            if(strcmp(ime, f.ime) || extenzija != f.extenzija) {
                return false;
            }

            return true;
        }
};

class Folder {
    char * folderIme;
    int brFiles;
    File * files;

    public:

        Folder() {
            brFiles = 0;
            files = nullptr;
        }

        Folder(char * folderIme) {
            this->folderIme = new char[strlen(folderIme)+1];
            strcpy(this->folderIme, folderIme);

            

        }

        ~Folder() {
            delete [] folderIme;
        }

        void print() {
            cout<<"h"<<endl;
        }

        void add(const File & file) {
            files[brFiles] = file;
            brFiles++;
        }

        void remove(const File & file) {
            for(int i=0;i<brFiles;i++) {
                if(files[i].equals(file)) {
                    delete files[i];
                }
            }
        }
};



int main() {
	
    File f;
    f.print();

    File f2("H", (Extension)1, "Ja", 100);
    File f3("Ivan", (Extension)2, "Trajkovski_GOOOOOL", 50);
    File f4(f2);

    f2.print();
    f3.print();
    f4.print();

    if(f2.equals(f4)) {
        cout<<"Isti se sefe";
    } else {
        cout<<"Greska si";
    }

    if(f2.equals(f)) {
        cout<<"Isti se sefe";
    } else {
        cout<<"Greska si";
    }
	return 0;
}