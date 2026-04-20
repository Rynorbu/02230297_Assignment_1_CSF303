#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, int source, vector<Edge>& edges) {
    // Step 1: Initialize distances
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Step 2: Relax edges V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    bool hasCycle = false;
    for (int j = 0; j < E; ++j) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasCycle = true;
            break;
        }
    }

    // Output results
    if (hasCycle) {
        cout << "Graph contains a negative weight cycle." << endl;
    } else {
        cout << "Vertex Distance from Source (" << source << "):" << endl;
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX)
                cout << i << " : INF" << endl;
            else
                cout << i << " : " << dist[i] << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter V and E: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    bellmanFord(V, E, source, edges);

    return 0;
}