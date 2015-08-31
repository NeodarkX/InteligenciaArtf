#include <iostream>
#include <string.h>

using namespace std;

int contarPalabras(char* cadena) {
  int cont = 0;
  char* aux = cadena;
  do {
    aux = strchr(aux, ' ');
    if (aux) {
      ++cont;
      aux += 1;
    }
  } while (aux);
  return cont + 1;
}

int main() {
  char cadena[] = "mi peru es bonito!";
  cout << "Total palabras:" << contarPalabras(cadena) << endl;
  return 0;
}