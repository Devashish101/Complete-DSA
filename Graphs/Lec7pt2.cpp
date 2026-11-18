// Prim's Algorithm. -> It is being preferred when no. of edges > no. of vertices
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

ll prims(int src, int n) {
    vector<int>parent(n+1,-1);
    unordered_set<int> vis;
    unordered_map<int, int> mp; // mp[v] = minimum weight edge through which vertex v can be added to MST
    for (int i = 0; i < n; i++) {
        mp[i] = INT_MAX;
    }

    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0, src}); // {weight, vertex}
    mp[src] = 0;

    ll sum = 0;
    int total_edges = 0;

    while (total_edges < n) {
        pp curr = pq.top();
        pq.pop();

        int wt = curr.first;
        int vertex = curr.second;

        // Already included in MST
        if (vis.count(vertex)) {
            continue;
        }

        // Include vertex in MST
        vis.insert(vertex);
        total_edges++;
        sum += wt;

        // Visit all neighbours
        for (auto neighbour : graph[vertex]) {

            int neighbourVertex = neighbour.first;
            int neighbourWeight = neighbour.second;

            if (!vis.count(neighbourVertex) &&
                mp[neighbourVertex] > neighbourWeight) {

                // Update minimum edge weight
                mp[neighbourVertex] = neighbourWeight;

                // Store parent
                parent[neighbourVertex] = vertex;

                // Push {weight, vertex}
                pq.push({neighbourWeight, neighbourVertex});
            }
        }
    }

    return sum;
}

int main() {
    int v, e;
    cin >> v >> e;

    graph.resize(v+1);
    while (e--) {
        int src, dst, wt;
        cin >> src >> dst >> wt;

        add_edge(src, dst, wt);
    }

    int st;
    cin >> st;
    cout << prims(st, v);
}

// Test Case
// 7 9 -> vrtx, edges
// 0 1 2
// 0 3 1
// 1 2 3
// 1 3 3
// 2 4 5
// 3 4 4
// 3 5 6
// 4 5 7
// 5 6 8
// 0 -> st vrtx
// 24 -> output