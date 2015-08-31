#include <iostream>
#include <string.h>

using namespace std;

char* invertir(char* cadena) {
  int size = strlen(cadena);
  char* resultado = new char[size + 1];
  resultado[size] = 0;
  int c = 0;
  for(int i = size - 1; i >= 0; --i) {
    resultado[c++] = cadena[i];
  }
  return resultado;
}

int main() {
  char cadena[] = "Mi peru es bonito!";
  cout << invertir(cadena) << endl;
  return 0;
}