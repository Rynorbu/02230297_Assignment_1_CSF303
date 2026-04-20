#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;

void floydWarshall(int V, vector<vector<int>>& dist) {
    
    for (int k = 0; k < V; k++) {
        // i is the starting vertex
        for (int i = 0; i < V; i++) {
            // j is the ending vertex
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Error: Graph contains a negative weight cycle!" << endl;
            return; 
        }
    }

    cout << "\nShortest distance matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF / 2) 
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> matrix(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) {
        matrix[i][i] = 0;
    }

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w; 
    }

    floydWarshall(V, matrix);

    return 0;
}