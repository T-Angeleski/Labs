#include<stdio.h>

typedef struct Pacient{
    char ime[100];
    int zdrastveno;
    int pregledi;
}Pacient;

typedef struct MaticenDoktor{
    char ime[100];
    int br_pac;
    Pacient niza[200];
    float cena;
}doktor;

void najuspesen_doktor(doktor *md, int n) {
    float suma, max=0;
    int indeksNajgolem, brPregledi, brPreglediNajgolem;

    for( int i=0; i<n; i++) {
        suma = 0;
        brPregledi = 0;
        for( int j=0;j < md[i].br_pac; j++) {
            //ako ne se osigurani
            if(md[i].niza[j].zdrastveno == 0) {
                suma += md[i].cena;
                brPregledi += md[i].niza[j].pregledi;
            }

        }

        if(suma > max) {
            max = suma;
            indeksNajgolem = i; // segasniot doktor
            brPreglediNajgolem = brPregledi;
        }
    }

    printf("%s %.2f %d", md[indeksNajgolem].ime, max, brPreglediNajgolem);
}

int main()
{
	int i, j, n, broj;
	doktor md[200];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		//ime na doktor
		scanf("%s", &md[i].ime);
		//broj na pacienti
		scanf("%d", &md[i].br_pac);
		//cena na pregled
		scanf("%f", &md[i].cena);

		for (j = 0; j < md[i].br_pac; j++){
			scanf("%s", &md[i].niza[j].ime);
			scanf("%d", &md[i].niza[j].zdrastveno);
			scanf("%d", &md[i].niza[j].pregledi);
		}
	}
	najuspesen_doktor(md, n);

	return 0;
}
