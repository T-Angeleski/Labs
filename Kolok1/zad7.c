#include <string.h>
#include <stdio.h>

typedef struct vozenje {
    char imeVozenje[100];
    int vremetraenje;
    float cena;
    int imaPopust; //1 da 0 ne
}Vozenje;

typedef struct park{
    char imePark[100];
    char lokacija[100];
    Vozenje vozenja[100];
    int brVozenja;
}ZabavenPark;


void print(ZabavenPark z) {
    printf("%s %s\n", z.imePark, z.lokacija);
    for(int i = 0 ; i < z.brVozenja ; i++) {
        printf("%s %d %.2f\n", z.vozenja[i].imeVozenje, z.vozenja[i].vremetraenje, z.vozenja[i].cena);
    }
}

void najdobar_park(ZabavenPark * z, int n) {
    //onoj koj ima najgolem broj vozenja so popust
    //ako povekje delat, toj so najgolemo vremetraenje na site vozenja
    int maxVozenja = 0, tmpVozenja, indexMax;
    int maxVreme, tmpVreme;
    for(int i = 0; i< n ; i++) {
        tmpVozenja = 0;
        tmpVreme = 0;
        for(int j = 0 ; j < z[i].brVozenja; j++) {
            if(z[i].vozenja[j].imaPopust==1) {
                tmpVozenja++;
                
            }
            tmpVreme += z[i].vozenja[j].vremetraenje;
        }

        if(tmpVozenja > maxVozenja) {
            maxVozenja = tmpVozenja;
            indexMax = i;
            maxVreme = tmpVreme;
        } else if(tmpVozenja == maxVozenja && tmpVreme > maxVreme) {
            indexMax = i;
            maxVreme = tmpVreme;
        }
    }


    printf("Najdobar park: %s %s\n", z[indexMax].imePark, z[indexMax].lokacija);
}



int main() {
    int n;
    scanf("%d", &n);

    ZabavenPark park[100];

    for(int i = 0 ; i < n; i++) {
        scanf("%s", &park[i].imePark);
        scanf("%s", &park[i].lokacija);
        scanf("%d", &park[i].brVozenja);

        for(int j= 0 ; j < park[i].brVozenja; j++) {
            scanf("%s", &park[i].vozenja[j].imeVozenje);
            scanf("%d", &park[i].vozenja[j].vremetraenje);
            scanf("%f", &park[i].vozenja[j].cena);
            scanf("%d", &park[i].vozenja[j].imaPopust);
        }
    }

    for(int i = 0; i<n; i++) {
        print(park[i]);
    }

    najdobar_park(park, n);

    return 0;
}