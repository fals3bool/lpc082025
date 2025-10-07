/*
 * Ejercicio 4:
 * THE RANK
 *
 * -- RESUMEN --
 *
 * Hay N estudiantes, donde cada uno tiene un único id (de 1 a N). El id de
 Tomás es el 1.
 * Cada estudiante tiene 4 puntajes de exámenes.
 *
 * Los estudiantes son dados en orden creciente según sus ids.
 *
 * Los estudiantes serán ordenados de forma decreciente por la suma de sus
 puntajes.
 * Si dos o más estudiantes tienen la misma suma de puntajes, son ordenados de
 forma creciente según sus ids.
 *
 * -- INPUT --
 * Un entero {N} (1 <= N <= 1000): la cantidad de estudiantes
 * N lineas con {4 enteros} (0 <= a,b,c,d <= 100): los 4 puntajes del i-esimo
 estudiante.
 *
 * -- OUTPUT --
 * La posición de Tomás luego de haber reodenado la lista.
 *
 *
 *
 * EJEMPLO:
 *
 * -- INPUT --
    5
    100 98 100 100
    100 100 100 100
    100 100 99 99
    90 99 90 100
    100 98 60 99

 * -- OUTPUT --
    2
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(pair<int, int> p, pair<int, int> q) {
  if (p.second == q.second)
    return p.first < q.first;
  return p.second > q.second;
}

int main(void) {

  vector<pair<int, int>> notas;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      int ni;
      cin >> ni;
      sum += ni;
    }
    notas.push_back(make_pair(i+1, sum));
  }

  sort(notas.begin(), notas.end(), comp);

  int tomas = -1;
  for(int i=0; i<n; i++){
    if(notas[i].first == 1){
      tomas = i+1;
      break;
    }
  }

  cout << tomas << endl;

  return 0;
}
