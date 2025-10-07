/*
 * Ejercicio 6:
 * MANU AND CAFES
 *
 * -- RESUMEN --
 * Manu visitó cafeterías N veces. Estaba al pedo e hizo lo siguiente:
 *
 * Asignó un id individual a todas las cafeterías. Después escribió el orden en
 que las fue visitando.
 * Ahora Manu quiere saber cuál fue la que menos visitó.
 * Los ids van desde 0 a M-1.
 *
 * -- INPUT --
 * Un entero {M} (1 <= M <= 100): cantidad de cafeterías.
 * Un entero {N} (1 <= N <= 100): cantidad de visitas a cafeterías.
 * Un arreglo de tamaño N {a1, a2, a3, ..., an}: donde {ai} es el id de la
 cafetería visitada.
 *
 * -- OUTPUT --
 * El id de la cafetería menos visitada.
 *
 *
 *
 * EJEMPLO:
 *
 * -- INPUT --
    3 5
    0 2 1 0 1
 *
 * -- OUTPUT --
    2
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void) {

  int m, n;
  cin >> m >> n;

  vector<int> visitas(m);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    visitas[v]++;
  }

  int min = 200;
  int indexmin = -1;
  for (int i = 0; i < m; i++) {
    if (visitas[i] < min) {
      min = visitas[i];
      indexmin = i;
    }
  }

  cout << indexmin << endl;

  return 0;
}
