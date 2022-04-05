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
				}
			}

			brDatoteki = j;
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
	return 0;
}