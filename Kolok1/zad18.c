#include<stdio.h>
#include<string.h>

typedef struct SkiLift{
    char ime[15];
    int brojKorisnici;
    int status;
}skiLift;

typedef struct SkiCenter{
    char ime[20];
    char drzava[20];
    skiLift liftovi[20];
    int brojLiftovi;
}skiCenter;

int kapacitet(skiCenter sc) {
    // вкупниот број на скијачи кои може да се опслужуваат во еден момент вкупно на сите ски лифтови во центарот

    int vkupno =0;

    for( int i = 0 ; i< sc.brojLiftovi; i++) {
        if(sc.liftovi[i].status == 1) {
            vkupno += sc.liftovi[i].brojKorisnici;
        }
    }

    return vkupno;
}

void najgolemKapacitet(skiCenter *sc, int n) {
    int max=0, maxIndeks;
    int segasenKapacitet;
    for(int i = 0; i < n; i++) {
        segasenKapacitet = kapacitet(sc[i]);
        if(segasenKapacitet > max) {
            max = segasenKapacitet;
            maxIndeks = i;
        }
    }

    //Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови. 
    printf("%s\n%s\n%d", sc[maxIndeks].ime, sc[maxIndeks].drzava, max);
}


int main()
{
    int n;
	scanf("%d", &n);
    skiCenter sc[20];
	for (int i = 0; i < n; i++){
		//vnesi ime
        scanf("%s", &sc[i].ime);
		//vnesi drzava
        scanf("%s", &sc[i].drzava);

		//vnesi broj na liftovi
        scanf("%d", &sc[i].brojLiftovi);
		
        //za sekoj ski lift vnesi:
        for(int j = 0; j < sc[i].brojLiftovi; j++) {
            scanf("%s", &sc[i].liftovi[j].ime);

            scanf("%d", &sc[i].liftovi[j].brojKorisnici);

            scanf("%d", &sc[i].liftovi[j].status);
        }

	}
	
    //povik na funkcijata najgolemKapacitet
	najgolemKapacitet(sc, n);
	return 0;
}