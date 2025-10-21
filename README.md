# LPC UNL

Liga de Programación Competitiva realizada el 03/Octubre en la UNL.

[Enunciados](https://github.com/fals3bool/lpc25oct/blob/master/enunciados-nivel2.pdf)

## Testing

Una vez creas que haz resuelto el ejercicio puedes ejecutar los diferentes casos de prueba con un juez sencillo escrito en `test/test.cpp`.
```shell
g++ test/test.cpp -o judge
g++ -std=c++11 -O2 -Wall {archivo.cpp} -o {archivo}
./judge {archivo} {carpeta con los casos de prueba}
```

Por ejemplo el ejercicio `25 de mayo`
```shell
g++ -std=c++11 -O2 -Wall mayo25.cpp -o mayo25
./judge mayo25 test/25demayo
```

Debería mostrar la salida:
```shell
Test [1] Pasado!
Test [2] Pasado!
Test [3] Pasado!
Test [4] Pasado!
Test [5] Pasado!
Test [6] Pasado!
Test [7] Pasado!
Test [8] Pasado!
```

## Posibles errores con el Juez:

Al ejecutar el juez es posible obtener algunos errores comunes.

### 1 - Error en tiempo de ejecución
```shell
Test [i] Error en tiempo de ejecución.
```

Significa que, al ejecutar el i'esimo caso de prueba, el programa ha dado error debido que el código no estaba preparado para ese caso en especifico.

### 2 - Salida incompleta
```shell
Test [i] Salida incompleta!
```

Significa que, al ejecutar el i'esimo caso de prueba, el programa no ha dado la respuesta completa esperada. Usualmente suele ser un salto de linea o algún dato faltante.

### 3 - endl

Algunos casos de prueba suelen fallar por no usar saltos de linea luego de imprimir la respuesta. Asegurate de añadir siempre un salto de linea.
```c++
std::cout << respuesta << std::endl;
printf("%format\n", respuesta);
```

