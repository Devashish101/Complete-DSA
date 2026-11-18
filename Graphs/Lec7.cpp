// MST using Kruskal's Algorithm -> It is being preferred when no. of edges < no. of vertices
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Find the representative of a set
// Path compression is used
int find(vector<int>& parent, int x) {

    if(parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
}

// Union two sets using rank
void unionSet(vector<int>& parent, vector<int>& rank, int a, int b) {

    a = find(parent, a);
    b = find(parent, b);

    if(a == b)
        return;

    if(rank[a] >= rank[b]) {
        parent[b] = a;
        rank[a]++;
    }
    else {
        parent[a] = b;
        rank[b]++;
    }
}

struct Edge {
    int src;
    int dst;
    int wt;
};

// Sort edges according to weight
bool cmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

ll kruskals(vector<Edge>& input, int n, int e) {

    // Step 1: Sort all edges by weight
    sort(input.begin(), input.end(), cmp);

    // Step 2: Initialize DSU
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 1);

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    ll ans = 0;              // IMPORTANT: initialize to 0
    int edgeCount = 0;       // MST needs n-1 edges
    int i = 0;

    // Step 3: Pick smallest edges
    while(edgeCount < n - 1 && i < input.size()) {

        Edge curr = input[i];

        int srcparent = find(parent, curr.src);
        int dstparent = find(parent, curr.dst);

        // If they belong to different sets,
        // adding this edge won't create a cycle
        if(srcparent != dstparent) {

            unionSet(parent, rank, srcparent, dstparent);

            ans += curr.wt;
            edgeCount++;
        }

        // Move to next edge
        i++;
    }

    return ans;
}

int main() {

    int v, e;
    cin >> v >> e;

    vector<Edge> input;
    for(int i = 0; i < e; i++) {

        int src, dst, wt;
        cin >> src >> dst >> wt;

        input.push_back({src, dst, wt});
    }

    cout << kruskals(input, v, e);

    return 0;
}

// Test case
// 5 7
// 1 2 2
// 1 4 6
// 2 3 3
// 2 4 8
// 2 5 5
// 3 5 7
// 4 5 9

// 16 -> output

// Leetcode 1135
// Leetcode 1584