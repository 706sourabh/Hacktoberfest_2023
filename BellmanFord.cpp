#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void BellmanFord(vector<Edge> &edges, int vertices, int source) {
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    for (int i = 1; i < vertices; i++) {
        for (const Edge &edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (const Edge &edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

int main() {
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -2},
        {1, 3, 6},
        {2, 3, 1},
    };

    int vertices = 4; // Number of vertices in the graph
    int source = 0;   // Source vertex

    BellmanFord(edges, vertices, source);

    return 0;
}
