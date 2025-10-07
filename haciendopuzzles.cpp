/*
 * Ejercicio 7:
 * HACIENDO PUZZLES
 *
 * Un puzzle donde se debe completar un tablero de NxN casillas con N diferentes
 letras,
 * de modo que cada casilla tiene escrita exactamente una letra, y cumpliendo
 que no haya letras repetidas
 * en una misma fila ni columna.
 *
 * Javiera y Federico hicieron intentaron resolver uno pero se equivocaron en
 exactamente una casilla.
 * Ayudalos indicando la fila y columna correspondiente a la casilla erronea y
 la letra que debería ir en su lugar.
 *
 * -- INPUT --
 * La primera linea de cada caso tiene un entero {N} (3 <= N <= 26): indicando
 las dimensiones del tablero NxN.
 * Luego N líneas con N letras mayúsculas del alfabeto inglés.
 *
 * -- OUTPUT --
 * Dos enteros {F C}: la fila y columna donde está el error.
 * Una letra {X}: la letra correcta.
 *
 *
 *
 * EJEMPLO:
 *
 * -- INPUT --
    6
    OEYCDK
    EYOKCD
    KDCEOY
    CKHOYE
    YOEDKC
    DCKYEO

 * -- OUTPUT --
    4 3 D
 */

#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(void) {

  int n;
  cin >> n;

  map<char, int> count;
  map<char, pair<int, int>> pos;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      count[c]++;
      pos[c] = make_pair(i, j);
    }
  }

  char fix = 0;
  int f = 0, c = 0;
  for (auto it = count.begin(); it != count.end(); it++) {
    if (it->second == 1) {
      f = pos[it->first].first + 1;
      c = pos[it->first].second + 1;
    }
    if (it->second == n - 1)
      fix = it->first;
  }

  cout << f << " " << c << " " << fix << endl;

  return 0;
}
