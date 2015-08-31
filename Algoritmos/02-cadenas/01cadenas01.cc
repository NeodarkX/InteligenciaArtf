#include <iostream>
#include <string.h>

using namespace std;

int contarInocente(char* cadena, char caracter) {
  int cont = 0;
  bool encontrado = false;
  for (int i = 0; i < strlen(cadena); ++i) {
    if (cadena[i] == caracter) {
      encontrado = true;
      break;
    } else {
      ++cont;
    }
  }
  if (encontrado) {
    return cont;
  } else {
    return -1;
  }
}
int contarAstuto(char* cadena, char caracter) {
  int a = (int) cadena;
  int b = (int) strchr(cadena, caracter);
  int diff = b - a;
  return diff;
}
int main() {
  char cadenita[100]; char caracter;
  cout << "Ingrese una cadena: ";
  cin.getline(cadenita, 100);
  cout << "Cadenita: " << cadenita << endl;
  cout << "Ingrese un caracter a buscar: ";
  cin >> caracter;
  cout << "Total de caracteres antes de " << caracter
       //<< ": " << contarInocente(cadenita, caracter) << endl;
       << ": " << contarAstuto(cadenita, caracter) << endl;
  return 0;
}