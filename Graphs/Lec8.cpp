// ---------------------------------------------------------Dijkstra's Algorithm------------------------------------------------------------------- 
#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>

using namespace std;

vector<vector<pp>> graph;
void add_edge(int src, int dst, int wt, bool bi_dir = true) {
    graph[src].push_back({dst, wt});

    if (bi_dir) {
        graph[dst].push_back({src, wt});
    }
}

unordered_map<int, int> dijkstra(int src, int n) {

    vector<int> via(n + 1, -1);
    unordered_set<int> vis;

    // mp[v] = shortest distance from src to v
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        mp[i] = INT_MAX;
    }

    // {distance, vertex}
    priority_queue<pp, vector<pp>, greater<pp>> pq;

    pq.push({0, src});
    mp[src] = 0;

    while (!pq.empty()) {

        pp curr = pq.top();
        pq.pop();

        int dist = curr.first;
        int vertex = curr.second;

        if (vis.count(vertex)) {
            continue;
        }

        vis.insert(vertex);

        // Visit all neighbours
        for (auto neighbour : graph[vertex]) {

            int neighbourVertex = neighbour.first;
            int neighbourWeight = neighbour.second;

            // Relaxation
            if (!vis.count(neighbourVertex) &&
                mp[vertex] + neighbourWeight < mp[neighbourVertex]) {

                // Update shortest distance
                mp[neighbourVertex] =
                    mp[vertex] + neighbourWeight;

                // Store parent
                via[neighbourVertex] = vertex;

                // Push {distance, vertex}
                pq.push({
                    mp[neighbourVertex],
                    neighbourVertex
                });
            }
        }
    }

    return mp;
}

int main() {

    int v, e;
    cin >> v >> e;
    graph.resize(v + 1);

    while (e--) {
        int src, dst, wt;
        cin >> src >> dst >> wt;
        add_edge(src, dst, wt);
    }

    int st;
    cin >> st;
    unordered_map<int, int> shortest_path = dijkstra(st, v);

    int dst;
    cin >> dst;
    cout << shortest_path[dst] << "\n";
}

// Test case
// 5 6 -> vrtx, edges
// 0 1 2
// 0 2 4
// 1 2 1
// 1 3 7
// 2 3 3
// 3 4 2
// 0 -> src vrtx
// 4 -> dst vrtx dis to be calc from src 
// 8 -> output