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

constexpr unsigned long MAX_NUMBER = 5000000;  // dimensione massima del vettore

#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
  std::vector<long> best_sequenza;
  std::vector<long> vettore;
  unsigned long base = 0;
  unsigned long lunghezza_Max = 0;
  unsigned long base_Max = 0;
  bool crescente = true;

  // Genero numero pseudo casuali e li aggiungo al vettore
  std::cout << "Creo il vettore con una sequenza casuale di numeri... ";
  srand(static_cast<unsigned int>(time(NULL)));
  for (unsigned long i = 0; i < MAX_NUMBER; i++) {
    vettore.push_back((rand() % 500 - 100));
    // cout << vettore[i] << " ";
  }

  for (unsigned long j = 1; j < MAX_NUMBER; j++) {
    // Elementi consecutivi crescenti
    if (vettore[j] < vettore[j + 1]) {
      if (crescente)
        continue;
      else
        crescente = true;
    }
    // Elementi consecutivi decrescenti
    if (vettore[j] > vettore[j + 1]) {
      if (!crescente)
        continue;
      else
        crescente = false;
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
  // tramite il metodo push_back aggiungo un elemento alla fine del vettore
  for (unsigned long z = 0; z < lunghezza_Max; z++) {
    best_sequenza.push_back(vettore[base_Max + z]);
  }
  // stampo a schermo la miglior sequenza
  // ricavo la lunghezza del vettore tramite il metodo size
  std::cout << "\nLa sequenza migliore:" << "\n";
  int sum = 0;
  for (auto const& value : best_sequenza) {
    sum += value;
    std::cout <<" " << value << " ";
  }

  std::cout << "\nLa somma degli elementi è: " << sum << "\n";
  return 0;
}
