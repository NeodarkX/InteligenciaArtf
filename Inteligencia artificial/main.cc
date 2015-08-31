#include "mapa.h"
#include <queue>

void buscarRuta(Grafo * g, int a, int b) {
  vector<bool> visitados(g->nodos.size());
  queue<vector<int> > rutas;
  visitados[a] = true;
  vector<int> ruta1;
  ruta1.push_back(a);
  rutas.push(ruta1);
  while (rutas.size() > 0) {
    ruta1 = rutas.front();
    int frente = ruta1[ruta1.size() - 1];
    rutas.pop();
    if (frente == b) {
      for (int i = 0; i < ruta1.size(); ++i) {
        cout << g->nodos[ruta1[i]]->nombre << " ";
      }
      cout << endl;
      return;
    }
    Nodo* estadoActual = g->nodos[frente];
    for (int i = 0; i < estadoActual->arcos.size(); ++i) {
      if (!visitados[estadoActual->arcos[i]]) {
        visitados[estadoActual->arcos[i]] = true;
        vector<int> ruta2 = ruta1;
        ruta2.push_back(estadoActual->arcos[i]);
        rutas.push(ruta2);
      }
    }
  }
}

int main() {
  Grafo* g = new Grafo();
  g->agregarNodo("Arad"); // 0
  g->agregarNodo("Zerind"); // 1
  g->agregarNodo("Oradea"); // 2
  g->agregarNodo("Sibiu"); // 3
  g->agregarNodo("Timisora"); // 4
  g->agregarNodo("Lugoj"); // 5
  g->agregarNodo("Mehadia"); // 6
  g->agregarNodo("Dobreta"); // 7
  g->agregarNodo("Craioba"); // 8
  g->agregarNodo("RImnicu Vilcea"); // 9
  g->agregarNodo("Fagaras"); // 10
  g->agregarNodo("Pitesti"); // 11
  g->agregarNodo("Bucharest"); // 12
  g->agregarNodo("Giurgiu"); // 13
  g->agregarNodo("Urziceni"); // 14
  g->agregarNodo("Hirsova"); // 15
  g->agregarArco(0, 1);  g->agregarArco(0, 4);  g->agregarArco(0, 3);  g->agregarArco(1, 2);
  g->agregarArco(2, 3);  g->agregarArco(4, 5);  g->agregarArco(5, 6);  g->agregarArco(6, 7);
  g->agregarArco(7, 8);  g->agregarArco(8, 9);  g->agregarArco(8, 11);  g->agregarArco(3, 9);
  g->agregarArco(3, 10);  g->agregarArco(9, 11);  g->agregarArco(11, 12);  g->agregarArco(10, 12);
  g->agregarArco(12, 13);  g->agregarArco(12, 14);  g->agregarArco(14, 15);  g->imprimir();
  buscarRuta(g, 0, 12);
  return 0;
}