#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // pair of node and distance

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(const vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF); // distances from source
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap of nodes with their distances
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Ignore outdated pairs
        if (d > dist[u])
            continue;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    int n = 6; // number of nodes
    vector<vector<pii>> graph(n); // adjacency list representation

    // Define the graph edges and weights
    graph[0].push_back(make_pair(1, 10));
    graph[0].push_back(make_pair(4, 15));
    graph[0].push_back(make_pair(5, 5));
    graph[1].push_back(make_pair(2, 10));
    graph[1].push_back(make_pair(3, 30));
    graph[2].push_back(make_pair(3, 12));
    graph[2].push_back(make_pair(4, 5));
    graph[3].push_back(make_pair(5, 6));

    graph[1].push_back(make_pair(0, 10));
    graph[4].push_back(make_pair(0, 15));
    graph[5].push_back(make_pair(0, 5));
    graph[2].push_back(make_pair(1, 10));
    graph[3].push_back(make_pair(1, 30));
    graph[3].push_back(make_pair(2, 12));
    graph[4].push_back(make_pair(2, 5));
    graph[5].push_back(make_pair(3, 6));

    int source = 5; // source node

    vector<int> shortestDistances = dijkstra(graph, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        if (shortestDistances[i] == INF)
            cout << "Node " << i << ": Infinity \n";
        else
            cout << "Node " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}
