#include <iostream>
#include <cstring>
using namespace std;

struct Igrac {
    char imeIgrac[15];
    int level; // 
    int poeni;
};

struct KompjuterskaIgra {
    char imeIgra[20];
    Igrac players[30];
    int numPlayers;
};

KompjuterskaIgra najdobraIgra(KompjuterskaIgra *lista, int n) {
    int best, bestID;
    for(int i = 0; i<n ; i++) {
        best = 0;
        if(lista[i].numPlayers > best) {
            best = lista[i].numPlayers;
            bestID = i;
        }
    }

    return lista[bestID];
}

void najdobarIgrac(KompjuterskaIgra *lista, int n) {
    //da se najde igra so najgolema popularnost
    KompjuterskaIgra najdobra = najdobraIgra(lista, n);

    //najdobar igrac e so najmnogu poeni, ako isti, najgolemo nivo
    int maxPoeni, maxID, maxLevel;
    maxPoeni = 0;
    maxLevel = 0;
    for( int i = 0 ; i < najdobra.numPlayers; i++){
        
        if (najdobra.players[i].poeni == maxPoeni) {
            if(najdobra.players[i].level > maxLevel) {
                maxLevel = najdobra.players[i].level;
                maxPoeni = najdobra.players[i].poeni;
                maxID = i;
            }
        } else if(najdobra.players[i].poeni > maxPoeni) {
            maxPoeni = najdobra.players[i].poeni;
            maxID = i;
            maxLevel = najdobra.players[i].level;
        } 
        
        
    }

    cout<<"Najdobar igrac e igracot so korisnicko ime "<<najdobra.players[maxID].imeIgrac<<" koj ja igra igrata "
    <<najdobra.imeIgra;
}


int main() {

    int n;
    cin>>n;

    KompjuterskaIgra igra[100];

    for(int i = 0 ; i < n ; i++) {
        cin>>igra[i].imeIgra>>igra[i].numPlayers;

        for(int j = 0 ; j < igra[i].numPlayers ; j++) {
            cin>>igra[i].players[j].imeIgrac>>igra[i].players[j].level>>igra[i].players[j].poeni;
        }
    }

    najdobarIgrac(igra, n);

    return 0;
}