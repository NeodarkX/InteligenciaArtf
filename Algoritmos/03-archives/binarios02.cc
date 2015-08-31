#include <fstream>
#include <iostream>

using namespace std;

struct Punto {
  long x, y;
};

int main() {
  Punto puntos[2];
  ifstream archivo("archivo.dat");
  if (!archivo.is_open()) return -1;
  archivo.read((char*)puntos, sizeof(Punto) * 2);
  for (int i = 0; i < 2; ++i) {
    cout << puntos[i].x << ", " << puntos[i].y << endl;
  }
  archivo.close();
  return 0;
}