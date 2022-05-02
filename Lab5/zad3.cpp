//vashiot kod ovde
#include <iostream>
#include <string.h>
using namespace std;

class Matrica {
    float elements[10][10] = {0};
    int rows;
    int columns;

    public:
        Matrica(int rows = 0, int colums = 0) {
            this->rows = rows;
            this->columns = colums;
            
        }

        Matrica operator+ (float n) {
            Matrica tmp;
            tmp.rows = rows;
            tmp.columns = columns;
            //Prazno e tmp od pocetok
            for(int i = 0 ; i < rows; i++) {
                for(int j = 0 ; j < columns; j++) {
                    tmp.elements[i][j] += elements[i][j] + n;
                }
            }

            return tmp;
        }

        Matrica operator- (const Matrica & m) {
            Matrica tmp;
            tmp.rows = rows;
            tmp.columns = columns;
            for(int i = 0 ; i < rows; i++) {
                for(int j = 0 ; j < columns; j++) {
                    tmp.elements[i][j] += elements[i][j] - m.elements[i][j];
                }
            }
            
            return tmp;
        }

        Matrica operator* (Matrica & m) { // ??????
            Matrica tmp;
            tmp.rows = rows;
            tmp.columns = columns;

            for(int i = 0 ; i < rows; i++) {
                for(int j = 0 ; j < columns; j++) {
                    for(int k = 0 ; k < columns ; k++) {
                        tmp.elements[i][j] += elements[i][k] * m.elements[k][j];
                    }
                }
            }
            
            return tmp;
        }

        friend istream& operator>> (istream & in, Matrica & m) {
            in>>m.rows>>m.columns;
            for(int i = 0 ; i < m.rows; i++) {
                for(int j = 0 ; j < m.columns; j++) {
                    in >> m.elements[i][j];
                }
            }
            return in;
        }

        friend ostream& operator<< (ostream & out, const Matrica & m) {
            for(int i = 0 ; i < m.rows; i++) {
                for(int j = 0 ; j < m.columns; j++) {
                    out << m.elements[i][j] << " ";
                }
                out << endl;
            }
            return out;
        }
};

int main()
{
    Matrica A,B,C;
    cin>>A>>B>>C;
    Matrica D=B*C;
    Matrica R=A-D+2;
    cout<<R;
}