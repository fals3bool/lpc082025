/*
 * Cómo realizar los tests:
 *
 * $ g++ test.cpp -o test
 * ./test {compiled file} {carpeta con casos de prueba}
 *
 */

#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace fs = std::filesystem;

bool check_input_integrity(const char *cfile, const char *test_folder);
bool check_answer(std::string out, std::string mout, int n);

int main(int argc, char **argv) {

  if (argc < 3) {
    std::cout
        << "Argumentos insuficientes. \n $ ./test {archivo.cpp} {carpeta con "
           "los casos de prueba} \n\n ej: \n $ g++ mayo25.cpp -std=c++11 -O2 "
           "-Wall -o mayo25 \n $ ./test mayo25 25demayo \n\n";
    return 1;
  }

  if (!check_input_integrity(argv[1], argv[2])) {
    std::cout << "La carpeta especificada no existe \n $ ./test {archivo.cpp} "
                 "{carpeta con los casos de prueba} \n\n";
    return 1;
  }

  std::vector<std::string> files;
  for (const auto &file : fs::directory_iterator(argv[2])) {
    files.push_back(file.path());
  }
  std::sort(files.begin(), files.end());

  for (int i = 0; i < files.size(); i += 2) {

    std::stringstream ss;
    ss << "./" << argv[1] << " < " << files[i] << " > ans.out";
    int n = i / 2 + 1;

    if (system(ss.str().c_str())) {
      std::cout << "Test [" << n << "] Error en tiempo de ejecución.\n\n";
      return 1;
    }

    if (check_answer(files[i + 1], "ans.out", n)) {
      std::cout << "Test [" << n << "] Pasado!\n";
    }
  }

  return 0;
}

bool check_input_integrity(const char *cfile, const char *test_folder) {
  fs::directory_entry file(cfile);
  if (!file.exists())
    return false;

  fs::directory_entry folder(test_folder);
  if (!folder.exists())
    return false;

  return true;
}

bool check_answer(std::string out, std::string mout, int n) {
  std::ifstream f1(out), f2(mout);
  if (!f1 || !f2) {
    std::cout << "Error al leer archivos de salida. Test [" << n << "].\n\n";
    return 1;
  }
  std::string a, b;
  while (true) {
    bool eof1 = !getline(f1, a);
    bool eof2 = !getline(f2, b);
    if (eof1 && eof2)
      return true;
    if (eof1 || eof2) {
      std::cerr << "Test [" << n << "] Salida incompleta!\n";
      return false;
    }

    if (a != b) {
      std::cerr << "Test [" << n
                << "]\n Diferencia encontrada. \n Esperado:  " << a
                << "\n Respuesta: " << b << "\n\n";
      return false;
    }
  }
}
