/*
 * Ejercicio 3:
 * PALINDROMO
 *
 * -- RESUMEN --
 * Dada un palabra, determinar si es palindroma en todas sus posibles
 permutaciones.
 *
 * -- INPUT --
 * Un {string} de longitud N. Solo estará compuesto por letras del alfabeto
 inglés, sin espacios ni simbolos.
 *
 * -- OUTPUT --
 * El número total de combinaciones que hagan palindroma a la palabra o "No es
 posible!" en caso de que no se pueda.
 *
 *
 *
 * EJEMPLO:
 *
 * -- INPUT --
    abcabc

 * -- OUTPUT --
    6
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;

bool ispali(string s) {
  int n = s.length() - 1;
  for (int i = 0; i <= n; i++) {
    if (s[i] != s[n - i])
      return false;
  }
  return true;
}

int main(void) {

  string s;
  cin >> s;

  sort(s.begin(), s.end());
  int c = 0;
  do {
    if (ispali(s))
      c++;
  } while (next_permutation(s.begin(), s.end()));

  if (c == 0)
    cout << "No es posible!" << endl;
  else
    cout << c << endl;

  return 0;
}
