#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Function to add an edge to the graph
void addEdge(vector<vector<pair<int, int>>>& graph, int source, int destination, int weight) {
    graph[source].push_back(make_pair(destination, weight));
    graph[destination].push_back(make_pair(source, weight));
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<pair<int, int>>>& graph, int vertices) {
    // Priority queue to store edges with minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int source = 0; // Starting vertex

    // Create a vector to track the visited vertices
    vector<bool> visited(vertices, false);

    // Create a vector to store the parent of each vertex
    vector<int> parent(vertices, -1);

    // Create a vector to store the weight of each vertex
    vector<int> weight(vertices, INT_MAX);

    // Add the source vertex to the priority queue and set its weight to 0
    pq.push(make_pair(0, source));
    weight[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        // Traverse all adjacent vertices of the current vertex
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (!visited[v] && w < weight[v]) {
                parent[v] = u;
                weight[v] = w;
                pq.push(make_pair(weight[v], v));
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < vertices; ++i)
        cout << parent[i] << " - " << i << "\n";
}

int main() {
    int vertices = 6; // Number of vertices in the graph
    vector<vector<pair<int, int>>> graph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0,5,1 );
    addEdge(graph, 4,5,4);
    addEdge(graph, 3,4,5);
    addEdge(graph, 2,3,3);
    addEdge(graph, 1,2,2);
    addEdge(graph, 1,4,10);
    addEdge(graph, 1,3,1);
    addEdge(graph, 2,5,5);

    primMST(graph, vertices);

    return 0;
}
