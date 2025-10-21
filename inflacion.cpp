/*
 * Ejercicio 9:
 * INFLACIÓN
 *
 * -- RESUMEN --
 * En una escula se paga una mensualidad. Debido a la inflación no se puede
 predecir como evolucionará dicho costo.
 * Se dispone un historial de los últimos N meses de actividad, donde cada mes
 está representado por un valor,
 * que puede ser negativo o positivo.
 *
 * El contador necesita analizar el historial y obtener:
 * + El periodo consecutivo de {M} meses con la mayor rentabilidad total.
 * + El mes más rentable dentro de ese periodo.
 * + La rentabilidad total obtenida en dicho intervalo.
 *
 * -- INPUT --
 * Un entero {N} (1 <= N <= 100000): la cantidad de meses a evaluar.
 * Un entero {M} (1 <= M <= N): el tamaño de los periodos a analizar.
 * N elementos {ni} (-32768 <= ni <= 32676): el balance de cada mes.
 *
 * -- OUTPUT --
 * El rango del periodo.
 * La rentabilidad del periodo.
 * El mes más rentable dentro del periodo.
 * (Todos en lineas distintas)
 *
 *
 *
 * EJEMPLO:
 *
 * -- INPUT --
    10 3
    11 -3 -5 2 20 -10 30 4 -100 22

 * -- OUTPUT --
    5 7
    40
    3
 *
 */

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

  int n, m;
  cin >> n >> m;

  vector<int16_t> meses;
  for (int i = 0; i < n; i++) {
    int16_t ni;
    cin >> ni;
    meses.push_back(ni);
  }

  vector<int16_t> sums;
  for (int i = 0; i <= n - m; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      sum += meses[i + j];
    }
    sums.push_back(sum);
  }

  int16_t max = -32768;
  int ri = 0, rj = 0;
  for (int i = 0; i < sums.size(); i++) {
    if (sums[i] > max) {
      max = sums[i];
      ri = i;
      rj = i + m;
    }
  }

  int rm = -1;
  max = -32768;
  for (int i = ri; i < rj; i++) {
    if (meses[i] > max) {
      max = meses[i];
      rm = i - ri;
    }
  }

  cout << ri + 1 << " " << rj << endl;
  cout << sums[ri] << endl;
  cout << rm + 1 << endl;

  return 0;
}
