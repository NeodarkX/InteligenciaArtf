#include <fstream>
#include <iostream>

using namespace std;

struct Punto {
  long x, y;
};

int main() {
  ofstream archivo("archivo.dat");
  if (!archivo.is_open()) return -1;
  Punto puntos[2];
  puntos[0].x = 20;
  puntos[0].y = 120;
  puntos[1].x = 2;
  puntos[1].y = 500;
  archivo.write((char*)puntos, sizeof(Punto) * 2);
  archivo.close();
  return 0;
}