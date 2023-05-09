/*
 * Algoritmo de Dijkstra para calcular los caminos mínimos en un grafo.
 *
 * Código basado en implementación de Shubham Agrawal disponible
 * en:
 *
 *   https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
 */

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <climits>

const int infinity = INT_MAX; //Valor maximo de un entero, representa el infinito en este algoritmo.

struct Edge { //Arista
    std::string destination; //String al que se quiere llegar, vertice al que se conecta
    int weight; //Peso de esa conexion
};

using Graph =
    std::map<std::string, std::vector<Edge>>; //Mapa que tiene como llave el nombre del vertice y tiene un vector de Aristas.
using GraphKeyValuePair =
    std::pair<std::string, std::vector<Edge>>; //Se usa para iterar sobre el grafo. Para simplificar los ciclos for.

void add_edge( //Agrega los pesos para hacer las conexiones entre aristas.
    Graph& connections,
    std::string vertex_1,
    std::string vertex_2,
    int weight)
{
    connections[vertex_1].push_back(Edge {vertex_2, weight});
    connections[vertex_2].push_back(Edge {vertex_1, weight});
}


// Complejidad: O(V^2)
void dijkstra(Graph& connections, std::string start)
{
    std::queue<std::string> queue;
    queue.push(start);

    std::map<std::string, int> distance;
    for (GraphKeyValuePair pair : connections) { //Inicia la tabla con todos los valores en infinito
        distance[pair.first] = infinity;
    }
    distance[start] = 0; //Reemplaza la distancia del nodo del que se inicia por un 0.

    while (not queue.empty()) {
        std::string current_vertex = queue.front();
        int current_weight = distance[current_vertex];
        queue.pop();
        for (Edge edge : connections[current_vertex]) { //Revisa las distancias y las va actualizando.
            if (distance[edge.destination] > current_weight + edge.weight) {
                distance[edge.destination] = current_weight + edge.weight;
                queue.push(edge.destination);
            }
        }
    }

    std::cout << "Distance from " << start << '\n'; //Imprime las distancias
    for (GraphKeyValuePair pair : connections) {
        std::string vertex = pair.first;
        std::cout << vertex << ": " << distance[vertex] << '\n';
    }
}

int main()
{
    Graph connections;
    add_edge(connections, "A", "B", 7);
    add_edge(connections, "A", "C", 2);
    add_edge(connections, "B", "C", 3);
    add_edge(connections, "B", "D", 1);
    add_edge(connections, "C", "D", 10);
    dijkstra(connections, "A");
    return 0;
}