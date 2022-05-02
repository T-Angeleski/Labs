#include <iostream>
#include <string.h>
using namespace std;

class PlDrustvo {
    char * name;
    int tours;
    int members;

    void copy(const PlDrustvo & other) {
        this->name = new char [strlen(other.name)+1];
        strcpy(this->name, other.name);

        this->tours = other.tours;
        this->members = other.members;
    }

    public:
        
        PlDrustvo(char *name= "", int tours=0, int members=0) {
            this->name = new char [strlen(name)+1];
            strcpy(this->name, name);

            this->tours = tours;
            this->members = members;
        }

        PlDrustvo(const PlDrustvo & d) {
            copy(d);
        }

        PlDrustvo& operator= (const PlDrustvo & d) {
            if( this!=&d ) {
                delete [] name;
                copy(d);
            }
            return *this;
        }

        ~PlDrustvo() {
            delete [] name;
        }

        int getMembers() {
            return members;
        }

        PlDrustvo operator+ (PlDrustvo & d) {
            PlDrustvo tmp;
            if(members > d.members) {
                tmp = PlDrustvo(name, tours, members+ d.members);
            } else {
                tmp = PlDrustvo(d.name, d.tours, members + d.members);
            }
            return tmp;
        }

        bool operator > (PlDrustvo & d) {
            return members > d.members;
        }

        bool operator < (PlDrustvo & d) {
            return members < d.members;
        }

        friend ostream& operator<<(ostream & out, PlDrustvo & d) {
            out<<"Ime: "<<d.name<<" Turi: "<<d.tours<<" Clenovi: "<<d.members<<endl;
            return out;
        }
};

void najmnoguClenovi(PlDrustvo * groups, int n) {
    int max=0, maxIndex;
    for(int i = 0 ; i < n ; i++) {
        if(groups[i].getMembers() > max) {
            max = groups[i].getMembers();
            maxIndex = i;
        }
    }
    cout<<"Najmnogu clenovi ima planinarskoto drustvo: ";
    cout<<groups[maxIndex];
}


int main()
{        		
    return 0;
}
