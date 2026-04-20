#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9 

void floydWarshall(int V, vector<vector<int>>& graph) {
    // Initialize the distance matrix with input graph values
    vector<vector<int>> dist = graph;

    // Core Algorithm: Try every vertex k as an intermediate point
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k provides a shorter path from i to j, update it
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Part B: Negative Cycle Detection
    // If distance from a vertex to itself becomes negative, a cycle exists
    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected in the graph!" << endl;
            return;
        }
    }

    // Part C: Print final distance matrix
    cout << "Shortest distance matrix between every pair of vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix (use " << INF << " for no edge, 0 for diagonal):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(V, graph);

    return 0;
}