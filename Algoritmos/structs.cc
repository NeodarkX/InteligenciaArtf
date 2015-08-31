#include <iostream>

using namespace std;

struct Alumno {
  int edad;
  char tipo;
  double promedio;
};
struct B {
  double x;
  double y;
};
struct C {
  int x, p, q, r;
  double y;
  double z;
};
struct D {
  char x, p, q, r, a, b, c, d, e;
};

int main() {
  cout << "Tamaño de Alumno: " << sizeof(Alumno) << " bytes" << endl;
  cout << "Tamaño de B: " << sizeof(B) << " bytes" << endl;
  cout << "Tamaño de C: " << sizeof(C) << " bytes" << endl;
  cout << "Tamaño de D: " << sizeof(D) << " bytes" << endl;
  return 0;
}