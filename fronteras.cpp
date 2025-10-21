/*
 * Ejercicio 5:
 * FRONTERAS
 *
 * -- RESUMEN --
 * Se tiene una lista de de países y sus ciudades.
 * A su vez, se tiene otra lista que indica para cada ciudad, sus ciudades
 vecinas.
 * Se deben obtener los países limítrofes
 *
 * -- INPUT --
 * Un entero {N} (1 <= N <= 100): el número de países.
 * N entradas {C P}: siendo C una ciudad y P a que país pertenece.
 * Un entero {M}: el número de vecinidades.
 * M entradas {A B}: los pares de ciudades vecinas.
 * Una cadena de caracteres {X}: el país el cual debe ser analizado.
 *
 * -- OUTPUT --
 * Nombres de los países vecinos a X, separados por una linea en blanco y
 ordenados en forma alfabética ascendente.
 * En caso de no tener poner "NO".
 *
 *
 *
 * EJEMPLO:
 *
 * -- INPUT --
    6
    BuenosAires Argentina
    Cordoba Argentina
    Santiago Chile
    Valparaiso Chile
    Asuncion Paraguay
    CiudadDelEste Paraguay
    5
    BuenosAires Santiago
    Cordoba Santiago
    Cordoba Asuncion
    Asuncion CiudadDelEste
    Valparaiso Santiago
    Argentina

 * -- OUTPUT --
    Chile
    Paraguay
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(void) {

  map<string, vector<string>> paises;
  map<string, string> ciudad_pais;
  map<string, vector<string>> ciudades;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string c, p;
    cin >> c >> p;
    paises[p].push_back(c);
    ciudad_pais[c] = p;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    ciudades[a].push_back(b);
    ciudades[b].push_back(a);
  }

  string x;
  cin >> x;

  set<string> lim;
  for (string c : paises[x]) {
    for (string l : ciudades[c]) {
      string f = ciudad_pais[l];
      if (x != f)
        lim.insert(f);
    }
  }

  for (string p : lim)
    cout << p << endl;
  if(lim.size()==0)
    cout << "NO" << endl;

  return 0;
}
