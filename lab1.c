#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// -------STRUKTURI---------

typedef struct proizvod{
    char ime[50];
    float cena;
    float kolicina;
}proizvod;

typedef struct tocka {
    float x1,y1;
}tocka;

typedef struct otsecka {
    tocka t1, t2;
}otsecka;

typedef struct tocka2D {
    float x,y;
}tocka2D;

typedef struct tocka3D {
    float x,y,z;
}tocka3D;

// --------FUNKCII--------
// int se_secat(otsecka o1, otsecka o2) {
    

// }

float rastojanie3D(tocka3D t1, tocka3D t2) {
    return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y)+(t1.z-t2.z)*(t1.z-t2.z));
}

float rastojanie(tocka2D t1, tocka2D t2) {
	return sqrt ((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}

int ista_prava(tocka2D t1, tocka2D t2, tocka2D t3) {
	if((t2.y-t1.y)/(t2.x-t1.x)==(t3.y-t2.y)/(t3.x-t2.x))
        return 1;
    else 
        return 0;
}

int main() {

    /* Да се напише програма во која од стандарден влез се вчитува N (бројот на производи), а потоа се вчитуваат податоците за N производи (име, цена, количина). Програмата треба на стандарден излез да ја отпечати листата на купени производи и вкупната сума која треба да се плати во следниот облик (пример):

    1. Flips    10.00 x 3 = 30.00
    2. CocaCola 75.00 x 2 = 150.00
    3. ChokoBanana  5.00 x 10 = 50.00
    Total: 230.00 


    int n;
    scanf("%d",&n);
    proizvod listaProizvodi[50];
    // Flips    10.00 x 3 = 30.00

    float total=0,vkCena;

    for(int i=0;i<n;i++) {
        scanf("%s%f%f",listaProizvodi[i].ime, &listaProizvodi[i].cena, &listaProizvodi[i].kolicina);
        vkCena = listaProizvodi[i].cena *  listaProizvodi[i].kolicina;
        printf("%d. %s\t%.2f x %.1f = %.2f\n",i+1, listaProizvodi[i].ime, listaProizvodi[i].cena, listaProizvodi[i].kolicina,vkCena);
        total+= vkCena;
    }
    printf("Total: %.2f",total); */

    /* Да се напише структура која ќе опишува отсечка во дводимензионален простор (две точки).
    Потоа да се напише функција која ќе проверува дали две отсечки се сечат.

    double x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    tocka t1 = { x1, y1 };
    tocka t2 = { x2, y2 };
    otsecka o1 = { t1, t2 };
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    tocka t3 = { x1, y1 };
    tocka t4 = { x2, y2 };
    otsecka o2 = { t3, t4 };
    printf("%d\n", se_secat(o1, o2));

    Да се надополни програмата со следните барања:

    да се креира структура на точка во тродимензионален простор и да се напише функција која ќе го пресметува растојанието помеѓу две такви точки.
    да се напише функција која како аргумент прима три точки во дводимензионален простор и ќе проверува дали тие точки лежат на иста права.*/

    float x1, y1, x2, y2;
    scanf("%f %f", &x1, &y1);
	scanf("%f %f", &x2, &y2);
	tocka2D t1 = { x1, y1 };
	tocka2D t2 = { x2, y2 };
	printf("%.2f\n", rastojanie(t1, t2));
    float z1, z2;
    scanf("%f %f", &z1, &z2);
    tocka3D t3 = {x1, y1, z1};
    tocka3D t4 = {x2, y2, z2};
    printf("%.2f\n", rastojanie3D(t3, t4));
    tocka2D t5 = {z1, z2};
    printf("%d\n", ista_prava(t1, t2, t5));



    return 0;
}
