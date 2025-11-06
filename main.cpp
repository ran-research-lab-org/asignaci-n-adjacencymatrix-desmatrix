#include "Graph.hpp"

using namespace std;

int main()
{
  Graph G(5);
  G.addEdge(0, 2);
  G.addEdge(1, 1);
  G.addEdge(4, 3);
  G.addEdge(2, 3);
  G.addEdge(3, 1);
  G.print();

  cout << "numero de aristas: " << G.numEdges() << endl;

  cout << "cantidad de entradas en columna 1: " << G.inDegree(1) << endl;
  cout << "cantidad de entradas en columna 3: " << G.inDegree(3) << endl;

  cout << "nodo 1 influencer? " << G.isInfluencer(1) << endl;

  cout << "nodo 3 influencer? " << G.isInfluencer(3) << endl;

  cout << "nodo 0 influencer? " << G.isInfluencer(0) << endl;
  cout << "no, por que nodo 1 tiene mas entradas." << endl;
}
