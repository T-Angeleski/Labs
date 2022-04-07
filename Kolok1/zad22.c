#include <stdio.h>
#include <string.h>

//место за вашиот код
typedef struct proizvod {
    char kodProizvod[20];
    int cena;
    int brojDostapni;
}Proizvod;


typedef struct naracka {
    char ime[15];
    Proizvod proizvodi[10];
    int naracani[10]; 
    int brProizvodi;
}Narachka;


void pecatiFaktura(Narachka n) {
    
}

int main() {

    Narachka narachka;

    // внеси го името лицето кое ја прави нарачката
    // внеси го бројот на порачани производи во нарачката
    
    int i;
    //за секој од нарачаните производи се внесуваат информации
    for (i = 0; i < narachka.n; ++i) {
        // внеси код
        // внеси единицчна цена
        // внеси број на производи во магацин
    }
    //за секој производ се внесува колку такви производи се порачани во нарачката
    int j;
    for (j = 0; j < narachka.n; ++j) {
       //се внесува број на производи во нарачката
    }


    // повик на функцијата pecatiFaktura


    return 0;
}