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
  char respuesta;
  do {
    cout << "Ingrese el nombre: ";
    cin >> empleados[numEmpleados].nombre;
    cout << "Ingrese la edad: ";
    cin >> empleados[numEmpleados].edad;
    cout << "Ingrese el salario";
    cin >> empleados[numEmpleados].salario;
    ++numEmpleados;
    if (numEmpleados < 100) {
      cout << "Desea ingresar otro? (y/n)";
      cin >> respuesta;
    } else {
      respuesta = 'n'; // ya se llenó el arreglo
    }
  } while (respuesta != 'n');

  ofstream archivoEmpleados("empleados.dat");
  if (!archivoEmpleados.is_open()) {
    cout << "No se pudo abrir el archivo!" << endl;
    return -1;
  }
  archivoEmpleados.write((char*)empleados, sizeof(Empleado) * numEmpleados);
  archivoEmpleados.close();
  cout << "empleados.dat guardado correctamente!" << endl;

  return 0;
}