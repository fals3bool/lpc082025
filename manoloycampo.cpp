/*
 * Ejercicio 10:
 * MANOLO Y EL CAMPO
 *
 * La abuela de Manolo tiene un jardín que puede representarse en un rectangulo
 de tamaño 1xN.
 * El rectangulo está dividido en N secciones cuadradas con alturas diferentes.
 * El jardín tiene un sistema de riego que puede crear lluvia artificial.
 * Solo se puede crear por un sector a la vez.
 *
 * El agua de cada sección fluirá a las secciones vecinas si estas no superan su
 altura.
 *
 * Buscar la sección donde se maximiza el número de secciones regadas.
 *
 * -- INPUT --
 * un entero positivo {N} (1 <= N <= 1000).
 * N enteros positivos: la altura de las distintas secciones.
 *
 * -- OUTPUT --
 * un entero: el máximo número de secciones regadas si creamos una lluvia
 artificial en algún sector.
 *
 *
 *
 * EJEMPLO:
 *
 * -- INPUT --
    5
    1 2 1 2 1

 * -- OUTPUT --
    3
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int maxrain(const vector<int> &v, int i) {
  int l, r;
  l = r = 0;
  if (i - 1 >= 0 && v[i - 1] <= v[i])
    l = maxrain(v, i - 1);
  if (i + 1 < v.size() && v[i + 1] <= v[i])
    r = maxrain(v, i + 1);
  return l + r + 1;
}

int main(void) {

  int n;
  cin >> n;

  vector<int> v;
  for (int i = 0; i < n; i++) {
    int ni;
    cin >> ni;
    v.push_back(ni);
  }

  int max = 0;
  for (int i = 0; i < n; i++) {
    int mr = maxrain(v, i);
    if (mr > max)
      max = mr;
  }

  cout << max << endl;

  return 0;
}
