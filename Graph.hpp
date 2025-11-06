// Desteny Hernandez De Juan
// 401-23-3159

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Graph // grafo
{
private:
    int numVertices;               // numero de vertices / nodos
    vector<vector<int>> adjMatrix; // vector de vectores de ints

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, vector<int>(n, 0)) {}

    // Add a vertex from node u (fila) to node Q (columna)
    // input: fila de adjMatrix, columna de adjMatrix

    /* ejemplo: int 0, int 1
    { [1,3,4],
      [5,6,7] }
    se le va a añadir un edge al elemento "3"
    */
    void addEdge(int u, int Q)
    {
        if (u >= 0 && u < numVertices && Q >= 0 && Q < numVertices)
            adjMatrix[u][Q] = 1;
        else
            throw out_of_range("Vertice fuera de rango");
    }

    // Imprime la matriz de adyacencias
    void print() const
    {
        for (int i = 0; i < numVertices; ++i)
        {
            for (int j = 0; j < numVertices; ++j)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }

    // Devuelve la cantidad de aristas
    int numEdges() const
    {
        int edges = 0;
        for (int fila_i = 0; fila_i < numVertices; fila_i++)
            for (int columna_i = 0; columna_i < numVertices; columna_i++)
                if (adjMatrix[fila_i][columna_i] == 1)
                    edges++;
        return edges;
    }

    // Devuelve el in-degree de un vertice
    // in-degree: grado de entrada / nodo <--
    int inDegree(int columna_u) const
    {
        int entradas = 0;
        if (columna_u < 0 || columna_u >= numVertices)
            throw out_of_range("Vertice fuera de rango");
        else
            for (int fila_i = 0; fila_i < numVertices; fila_i++)
                if (adjMatrix[fila_i][columna_u] == 1)
                    entradas++;
        return entradas;
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.

    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos

    bool isInfluencer(int u) const
    {
        int indegree_U = inDegree(u);

        // calcular entradas de cada columna u
        // y se compara con el argumento
        for (int i = 0; i < numVertices; i++)
            if (i != u) // para que no se compare a ella misma
                if (indegree_U < inDegree(i))
                    // retorna falso si encuentra a otro inDegree mayor que u
                    return false;
        // si se sale del for loop, entonces los otros nodos eran menor o iguales que u
        return true;
    }
};
