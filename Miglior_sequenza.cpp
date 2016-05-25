/*
 * Dato un vettore di interi (grande > 10000) trova la più grande sottosequenza 
 * del numero monotona consecutivo , ad esempio
 *  dato il vettore [ 1,2,4,0,1 , -1 , -2 , -3 , -4,1 , 2 ] la più grande
 *  sottosequenza è [ 1 , -1 , -2 , -3 , -4 ] 
 */

/*
 * File:   Miglior_sequenza.cpp
 * Author: Francesco
 *
 * Created on 9 marzo 2016, 21.11
 */

#define MAX_NUMBER 5000000 //dimensione massima del vettore

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    vector <int> best_sequenza, vettore;

    int base = 0, lunghezza_Max = 0, base_Max = 0;
    bool crescente = true;

    //Genero numero pseudo casuali e li aggiungo al vettore
    cout << "Creo il vettore con una sequenza casuale di numeri... ";
    srand(time(NULL));
    for (int i = 0; i < MAX_NUMBER; i++) {
        vettore.push_back((rand() % 500 - 100));
        //cout << vettore[i] << " ";   
    }

    for (int j = 1; j < MAX_NUMBER; j++) {
        // Elementi consecutivi crescenti
        if (vettore[j] < vettore[j + 1]) {
            if (crescente) continue;
            else crescente = true;
        }
        // Elementi consecutivi decrescenti
        if (vettore[j] > vettore[j + 1]) {
            if (!crescente) continue;
            else crescente = false;
        }
        if (j + 1 - base > lunghezza_Max) {
            base_Max = base;
            lunghezza_Max = j + 1 - base;
        }
        // Setto la base di partenza della successione
        base = j;
    }

    if (MAX_NUMBER - base > lunghezza_Max) {
        base_Max = base;
        lunghezza_Max = MAX_NUMBER - base;
    }
    //tramite il metodo push_back aggiungo un elemento alla fine del vettore
    for (int z = 0; z < lunghezza_Max; z++) {
        best_sequenza.push_back(vettore[base_Max + z]);
    }
    //stampo a schermo la miglior sequenza  
    //ricavo la lunghezza del vettore tramite il metodo size
    cout << "\n\nLa sequenza migliore:\n";
    int sum = 0;
    for (int z = 0; z < best_sequenza.size(); z++) {
        sum += best_sequenza[z];
        cout << best_sequenza[z] << " ";    
    }
    cout<<"\nLa somma degli elementi è: "<<sum;
    return 0;
}