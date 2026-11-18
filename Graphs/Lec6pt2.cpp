// Cycle Detection in undirected graph using Disjoint Set Union and edge list
#include <bits/stdc++.h>
using namespace std;

// Find the representative of x
int find(vector<int>& parent, int x) {

    // If x is its own parent, it is the representative
    if(parent[x] == x)
        return x;

    // Path Compression
    return parent[x] = find(parent, parent[x]);
}

// Union two sets using Size
bool unionSet(vector<int>& parent, vector<int>& size, int a, int b) {

    // Find the representatives
    a = find(parent, a);
    b = find(parent, b);

    // Already in the same set
    if(a == b)return true; // Cycle detected

    // Attach smaller set to larger set
    if(size[a] >= size[b]) {
        parent[b] = a;
        size[a] += size[b];

    } else {
        parent[a] = b;
        size[b] += size[a];
    }

    return false; // No Cycle
}

int main() {

    int n;
    cin >> n;
    vector<int> parent(n + 1);

    // Initially, every set has size 1
    vector<int> size(n + 1, 1);

    // Initially, every element is its own parent
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int m; // Number of queries
    cin >> m;
    while(m--) {

        string str;
        cin >> str;
        if(str == "union") {
            int x, y;
            cin >> x >> y;
            bool b = unionSet(parent, size, x, y);
            if(b == true)cout<<"Cycle Detected"<<endl;

        } else { // find
            int x;
            cin >> x;
            cout << find(parent, x) << "\n";
        }
    }
}

// TODO:Cycle Detection in undirected graph using BFS and DFS.
// => If a node is already visited and not a parent of a curr node then you have a cycle.

// Detect cycle in undirected graph using DFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
void add_edge(int src, int dst, bool bi_dir = true) {
    graph[src].push_back(dst);
    if (bi_dir) {
        graph[dst].push_back(src);
    }
}

bool dfs(int src, int parent, unordered_set<int>& vis) {

    vis.insert(src);
    for (auto neighbour : graph[src]) {

        // Already visited and not the parent
        // means cycle exists
        if (vis.count(neighbour) && neighbour != parent) {
            return true;
        }

        // If not visited, explore it
        else if (!vis.count(neighbour)) {

            // If cycle found in recursive call
            if (dfs(neighbour, src, vis)) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    int vrtx = 8;
    graph.resize(vrtx + 1);

    int edge;
    cin >> edge;

    while (edge--) {
        int src, dst;
        cin >> src >> dst;
        add_edge(src, dst);
    }

    bool flag = true;
    unordered_set<int> vis;
    for (int i = 0; i <= vrtx; i++) {

        // Handle disconnected graph
        if (!vis.count(i)) {
            if (dfs(i, -1, vis)) {
                cout << "Cycle detected";
                flag = false;
                break;
            }
        }
    }
    if(flag) cout << "No cycle";
}

// Detect cycle in undirected graph using BFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
void add_edge(int src, int dst, bool bi_dir = true) {
    graph[src].push_back(dst);
    if (bi_dir) {
        graph[dst].push_back(src);
    }
}

bool bfs(int src, vector<int>& par, unordered_set<int>& vis) {
    queue<int>qu;
    qu.push(src);
    vis.insert(src);
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neibour: graph[curr]){
            if(vis.count(neibour) && par[curr] != neibour)return true; // we have detected a cycle.
            else if(!vis.count(neibour)){
                vis.insert(neibour);
                par[neibour] = curr;
                qu.push(neibour);
            }
        }
    }
}

int main() {

    int vrtx = 8;
    graph.resize(vrtx + 1);

    int edge;
    cin >> edge;

    while (edge--) {
        int src, dst;
        cin >> src >> dst;
        add_edge(src, dst);
    }

    bool flag = true;
    vector<int> parent(vrtx+1, -1);
    unordered_set<int>vis;
    for (int i = 0; i <= vrtx; i++) {

        if(!vis.count(i)){
            if (bfs(i,parent,vis)) {
                cout << "Cycle detected";
                flag = false;
                break;
            }
        }
    }
    if(flag)cout << "No cycle";
}

// Leetcode 947 
// -> Total Nodes - Connected Components.

// Leetcode 2316
// Leetcode 1559

// TODO: Cycle Detection in Directed Graph.
// => Apply the simple kahn's algo of topological sort 
// And if at end count == n then there is no cycle else in case of count < n there is cycle.
// Wherr count = no. of visited nodes and n = total no. of nodes.
