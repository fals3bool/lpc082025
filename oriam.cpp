/*
 * Ejercicio 2:
 * OIRAM
 *
 * -- RESUMEN --
 * Para que los alumnos no se copien en un examen. El profesor ordena a los
 * estudiantes de Calculo 1 en las filas impares, y a los de Calculo 2 en las
 * filas pares.
 *
 * Debes obtener en cuantos lugares posibles puede un estudiante sentarse según
 * la materia que va a rendir.
 *
 * -- INPUT --
 * Un caracter {C} con valor [D] o [I] si rinde Calculo 1 o 2 respectivamente.
 * Un entero {N}: cantidad de filas en el aula.
 * Un entero {L}: longitud de las filas.
 *
 *
 *
 * EJEMPLO:
 *
 * -- INPUT --
    D 5 4

 * -- OUTPUT --
    12
 *
 */

#include <iostream>

using namespace std;

int main(void) {

  char c;
  int n, l;
  cin >> c >> n >> l;

  if (c == 'D')
    cout << (n - n / 2) * l;
  else
    cout << n / 2 * l;

  return 0;
}
