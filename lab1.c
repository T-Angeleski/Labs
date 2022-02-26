#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct proizvod{
    char ime[50];
    float cena; 
    int kolicina;
}proizvod;





int main() {

    /* Да се напише програма во која од стандарден влез се 
    вчитува N (бројот на производи), 
    а потоа се вчитуваат податоците за N производи (име, цена, количина). 
    Програмата треба на стандарден излез да ја отпечати листата на купени производи и 
    вкупната сума која треба да се плати во следниот облик (пример):

    1. Flips    10.00 x 3 = 30.00
    2. CocaCola 75.00 x 2 = 150.00
    3. ChokoBanana  5.00 x 10 = 50.00
    Total: 230.00 */

    int n;
    scanf("%d",&n);
    proizvod listaProizvodi[50];

    for(int i=0;i<n;i++) {
        scanf("%s%f%d",listaProizvodi[i].ime, &listaProizvodi[i].cena, &listaProizvodi[i].kolicina);
        float vkCena = listaProizvodi[i].cena *  (float)listaProizvodi[i].kolicina;
        printf("%d. %s  %.2f x %d = %.2f\n", i+1, listaProizvodi[i].ime, listaProizvodi[i].cena, listaProizvodi[i].kolicina, vkCena);
    }

    return 0;
}