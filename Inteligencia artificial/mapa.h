#ifndef __MAPA_H__
#define __MAPA_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Nodo {
  string nombre;
  vector<int> arcos;
};

class Grafo {
public:
  vector<Nodo*> nodos;
  Grafo() {
  }
  void agregarNodo(string nombre) {
    Nodo* nodo = new Nodo();
    nodo->nombre = nombre;
    nodos.push_back(nodo);
  }
  void agregarArco(int a, int b) {
    nodos[a]->arcos.push_back(b);
    nodos[b]->arcos.push_back(a);
  }
  void imprimir() {
    for (int i = 0; i < nodos.size(); ++i) {
      for (int j = 0; j < nodos[i]->arcos.size(); ++j) {
        cout << nodos[i]->nombre << " -> " << nodos[nodos[i]->arcos[j]]->nombre << endl;
      }
    }
  }
};

#endif