/*
Programam que solicita empleado y los graba en un archivo
llamado empeados.dat
*/

#include <iostream>
#include <fstream>
#include "empleado.h"

using namespace std;

int main() {
  Empleado empleados[100];
  int numEmpleados = 0;

  ifstream archivoEmpleados("empleados.dat");
  if (!archivoEmpleados.is_open()) {
    cout << "No se pudo abrir el archivo!" << endl;
    return -1;
  }
  streampos inicio = archivoEmpleados.tellg();
  archivoEmpleados.seekg(0, ios::end);
  streampos final = archivoEmpleados.tellg();
  int tamanio = (int)(final - inicio);
  cout << "Tamaño del archivo: " << tamanio << " bytes\n";
  numEmpleados = tamanio / sizeof(Empleado);

  archivoEmpleados.seekg(0, ios::beg);
  archivoEmpleados.read((char*)empleados, tamanio);
  for (int i = 0; i < numEmpleados; i++) {
    cout << "Empleado " << (i + 1) << endl
        << "Nombre: " << empleados[i].nombre << endl
        << "Edad: " << empleados[i].edad << endl
        << "Salario: " << empleados[i].salario << endl;
  }

  return 0;
}