#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct proizvod{
    char ime[50];
    float cena;
    float kolicina;
}proizvod;





int main() {


    int n;
    scanf("%d",&n);
    proizvod listaProizvodi[50];
    // Flips    10.00 x 3 = 30.00

    float total=0,vkCena;

    for(int i=0;i<n;i++) {
        scanf("%s%f%f",listaProizvodi[i].ime, &listaProizvodi[i].cena, &listaProizvodi[i].kolicina);
        vkCena = listaProizvodi[i].cena *  listaProizvodi[i].kolicina;
        printf("%d. %s    %.2f x %.1f = %.2f\n",i+1, listaProizvodi[i].ime, listaProizvodi[i].cena, listaProizvodi[i].kolicina,vkCena);
        total+= vkCena;
    }
    printf("Total: %.2f",total);
    return 0;
}
