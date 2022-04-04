#include <stdio.h>
#include <string.h>

typedef struct laptop {
    char firma[100];
    float sizeMonitor;
    int isTouch;
    int cena;
}Laptop;

typedef struct itstore {
    char imeProdavnica[100];
    char lokacija[100];
    Laptop laptopi[100];
    int n;
}ITStore;

void print(ITStore store) {
    printf("%s %s\n",store.imeProdavnica, store.lokacija);
    for(int i = 0; i<store.n; i++) {
        if (store.laptopi[i].sizeMonitor == (int) store.laptopi[i].sizeMonitor) {
            printf("%s %d %d\n", store.laptopi[i].firma,(int)store.laptopi[i].sizeMonitor, store.laptopi[i].cena);
        } else 
            printf("%s %.1f %d\n", store.laptopi[i].firma,store.laptopi[i].sizeMonitor, store.laptopi[i].cena);
    }
}

void najeftina_ponuda(ITStore * stores, int n) {
    int minCena = 9999999, indexProd;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < stores[i].n; j++) {
            if(stores[i].laptopi[j].isTouch) {
                if(stores[i].laptopi[j].cena < minCena) {
                    minCena = stores[i].laptopi[j].cena;
                    indexProd = i;
                }
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n", stores[indexProd].imeProdavnica, stores[indexProd].lokacija);
    printf("Najniskata cena iznesuva: %d", minCena);
}


int main() {

    int n;
    scanf("%d",&n);
    ITStore prodavnici[100];
    for(int i = 0 ; i < n ; i++) {
        scanf("%s %s %d", &prodavnici[i].imeProdavnica, &prodavnici[i].lokacija,&prodavnici[i].n);
        for(int j = 0 ; j < prodavnici[i].n; j++) {
            scanf("%s %f %d %d", &prodavnici[i].laptopi[j].firma, &prodavnici[i].laptopi[j].sizeMonitor, &prodavnici[i].laptopi[j].isTouch, &prodavnici[i].laptopi[j].cena);
        }
    }

    //pecatenje
    for(int i = 0 ; i < n ; i++) {
        print(prodavnici[i]);
    }
    najeftina_ponuda(prodavnici, n);
    return 0;
}