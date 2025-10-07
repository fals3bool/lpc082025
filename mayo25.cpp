/*
 * Ejercicio 1:
 * 25 DE MAYO
 *
 * -- RESUMEN --
 * La nona quiere hacer un guiso y para ello tenemos una lista de ingredientes
 * constituídos por un string (nombre) y un real (cantidad).
 *
 * Dado un un número k de invitados y la cantidad de ingredientes que tiene la
 * nona en su casa, determina si puede o no hacer el guiso.
 *
 * -- INPUT --
 * {n}          cantidad de ingredientes para la receta
 * {n strings}  nombre del ingrediente
 * {n reales}   cantidad del ingrediente
 *
 * {m}          cantidad de ingredientes en casa de la nona
 * {k}          cantidad de invitados
 * {m strings}  nombre del ingrediente
 * {m reales}   cantidad del ingrediente
 *
 * -- OUTPUT --
 * "Un guiso muy rico!": En caso de ser posible hacer guiso para todos
 * {Ingrediente + cantidad faltante}: Para todos los ingredientes faltantes para
 * el guiso
 *
 * ¡¡Cuidado!! Tener en cuenta los decimales
 * cout << fixed << setprecision(1) << {var} << endl;
 *
 *
 *
 * EJEMPLO:
 * 
 * -- INPUT --
    3
    Cebolla 0.5
    Fideos 0.5
    Tomate 0.5
    2 2
    Cebolla 1
    Tomate 0.5
    
 * -- OUTPUT --
    Fideos 1.0
    Tomate 0.5
 *
 */

#include <iomanip>
#include <iostream>
#include <map>
using namespace std;

int main() {

  map<string, double> ingredientes;
  map<string, bool> comprado;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    double d;
    cin >> s >> d;
    ingredientes[s] = d;
    comprado[s] = false;
  }

  int m, k;
  cin >> m >> k;

  for (int i = 0; i < m; i++) {
    string s;
    double d;
    cin >> s >> d;
    comprado[s] = true;
    if (ingredientes[s] * k < d) {
      ingredientes[s] = 0;
    } else {
      ingredientes[s] = ingredientes[s] * k - d;
    }
  }

  bool guiso = true;
  for (auto it = ingredientes.begin(); it != ingredientes.end(); it++) {
    if (it->second > 0) {
      double necesario = comprado[it->first] ? it->second : it->second * k;
      cout << it->first << " " << fixed << setprecision(1) << necesario << endl;
      guiso = false;
    }
  }

  if (guiso)
    cout << "Un guiso muy rico!";

  return 0;
}
