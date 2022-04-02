#include<iostream>
#include<cstring>

using namespace std;

enum Extension {TXT, PDF, EXE};

class File {
    char * imeDatoteka;
    Extension ext;
    char * imeSopstvenik;
    int golemina;

    void copy(const File & other) {
        this->imeDatoteka = new char [strlen(other.imeDatoteka)+1];
        this->imeSopstvenik = new char [strlen(other.imeSopstvenik)+1];

        this->golemina = other.golemina;
        this->ext = other.ext;

        strcpy(this->imeDatoteka, other.imeDatoteka);
        strcpy(this->imeSopstvenik, other.imeSopstvenik);
    }

    public:
        File(char * imeDatoteka= " ", char * imeSopstvenik= " ",int golemina=0, Extension ext = (Extension)0) {
            this->imeDatoteka = new char [strlen(imeDatoteka)+1];
            this->imeSopstvenik = new char [strlen(imeSopstvenik)+1];

            this->golemina = golemina;
            this->ext = ext;

            strcpy(this->imeDatoteka, imeDatoteka);
            strcpy(this->imeSopstvenik, imeSopstvenik);
        }

        File(const File & f) {
            copy(f);
        }

        File& operator=(const File & f) {
            if( this != &f) {
                delete [] imeDatoteka;
                delete [] imeSopstvenik;

                copy(f);
            }
            return *this;
        }

        ~File() {
            delete [] imeDatoteka;
            delete [] imeSopstvenik;
        }

        bool equals(const File & that) {
            if( !strcmp(this->imeDatoteka, that.imeDatoteka)) {
                if(this->ext == that.ext) {
                    if(!strcmp(this->imeSopstvenik, that.imeSopstvenik)) {
                        return true;
                    }
                }
            }

            return false;
        }


        bool equalsType(const File & that) {
            if(!strcmp(this->imeDatoteka, that.imeDatoteka)) {
                if(this->ext == that.ext) {
                    return true;
                }
            }

            return false;
        }

        void print() {
            // cout<<"File name: "<<imeDatoteka<<endl;
            switch (ext) {
            case 0: 
                cout<<"File name: "<<imeDatoteka<<".pdf"<<endl;
                break;
            
            case 1:
                cout<<"File name: "<<imeDatoteka<<".txt"<<endl;
                break;

            default:
                cout<<"File name: "<<imeDatoteka<<".exe"<<endl;
                break;
            }
            cout<<"File owner: "<<imeSopstvenik<<endl;
            cout<<"File size: "<<golemina<<endl;
        }
};



class Folder {
	char * imeFolder;
	int brDatoteki;
	File * files;

	void copy(const Folder & other) {
		this->brDatoteki = other.brDatoteki;
		this->imeFolder = new char [strlen(other.imeFolder)+1];
		strcpy(this->imeFolder, other.imeFolder);

		for(int i = 0; i < brDatoteki; i++) {
			this->files[i] = other.files[i];
		}
	}

	public:
		Folder() {
			imeFolder = " ";
			brDatoteki = 0;
			files = new File [brDatoteki];
		}

		Folder(char * imeFolder) {
			brDatoteki = 0;
			this->imeFolder = new char [strlen(imeFolder)+1];
			strcpy(this->imeFolder, imeFolder);

			files = new File [brDatoteki];
		}

		Folder(const Folder & f) {
			copy(f);
		}

		Folder& operator=(const Folder & f) {
			if( this != &f) {
				delete [] imeFolder;
				delete [] files;
				copy(f);
			}
			return *this;
		}

		~Folder() {
			delete [] imeFolder;
			delete [] files;
		}



		void add(const File & file) {
			File * tmp = new File [brDatoteki+1];

			for(int i = 0 ; i < brDatoteki ; i++) {
				tmp[i] = files[i];
			}

			tmp[brDatoteki++] = file;

			delete [] files;

			files  = tmp;
		}

	
		void remove(const File & file) {
			// brisi prva koja e ista so file
			File * tmp = new File[brDatoteki];
			int j = 0;
			for(int i = 0 ; i<brDatoteki; i++) {
				if(!files[i].equals(file)) {
					tmp[j++] = files[i];
					break;
				}
			}

			brDatoteki -= j;
			delete [] files;
			files = tmp;
		}

		void print() {
			cout<<"Folder name: "<<imeFolder<<endl;

			for( int i = 0 ; i < brDatoteki; i++) {
				files[i].print();
			}
		}
};






int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;

		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
        cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
        cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;	

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}