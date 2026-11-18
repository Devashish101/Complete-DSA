//----------------------------------------------------------------Dijikstra's Algorithm Base Problem------------------------------------------
// Leetcode 1631. Path With Minimum Effort
# include <bits/stdc++.h>
# define pp pair<int,pair<int,int>>
using namespace std;
    
int main(){
    
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};

    int m = heights.size();
    int n = heights[0].size();

    // effort[i][j] = minimum effort required to reach (i,j)
    vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
    effort[0][0] = 0;

    // {effort, {row, col}}
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {

        auto curr = pq.top();
        pq.pop();

        int currEffort = curr.first;
        int currRow = curr.second.first;
        int currCol = curr.second.second;

        // If destination reached
        if (currRow == m - 1 && currCol == n - 1)
            return currEffort;

        // TOP
        if (currRow - 1 >= 0) {
            int diff = abs(heights[currRow][currCol] - heights[currRow - 1][currCol]);
            int newEffort = max(currEffort, diff);

            if (newEffort < effort[currRow - 1][currCol]) {
                effort[currRow - 1][currCol] = newEffort;
                pq.push({newEffort,{currRow - 1, currCol}});
            }
        }

        // RIGHT
        if (currCol + 1 < n) {
            int diff = abs(heights[currRow][currCol] - heights[currRow][currCol + 1]);
            int newEffort = max(currEffort, diff);

            if (newEffort < effort[currRow][currCol + 1]) {
                effort[currRow][currCol + 1] = newEffort;
                pq.push({newEffort,{currRow, currCol + 1}});
            }
        }

        // DOWN
        if (currRow + 1 < m) {
            int diff = abs(heights[currRow][currCol] - heights[currRow + 1][currCol]);
            int newEffort = max(currEffort, diff);

            if (newEffort < effort[currRow + 1][currCol]) {
                effort[currRow + 1][currCol] = newEffort;
                pq.push({newEffort,{currRow + 1, currCol}});
            }
        }

        // LEFT
        if (currCol - 1 >= 0) {
            int diff = abs(heights[currRow][currCol] - heights[currRow][currCol - 1]);
            int newEffort = max(currEffort, diff);

            if (newEffort < effort[currRow][currCol - 1]) {
                effort[currRow][currCol - 1] = newEffort;
                pq.push({newEffort,{currRow, currCol - 1}});
            }
        }
    }

    cout<<effort[m - 1][n - 1];
}

// Leetcode 787. Cheapest Flights Within K Stops -> Using Dijikstra's + priority_queue (checkout leetcode for queue only)
# include <bits/stdc++.h>
#define pp pair<int, pair<int,int>>
using namespace std;
    
int main(){
    
    vector<vector<int>>flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int n = 4, src = 0, dst = 3, k = 1;
    
    // Building the graph from given edge list
    vector<vector<pair<int,int>>> graph(n);
    for(int i = 0; i < flights.size(); i++) {
        int u = flights[i][0];
        int v = flights[i][1];
        int price = flights[i][2];

        graph[u].push_back({v, price});
    }

    // dist[node][stops]
    // Minimum price to reach 'node' using flights 'stops' 
    vector<vector<int>> dist(
        n, vector<int>(k + 2, INT_MAX)
    );
    dist[src][0] = 0;

    // {price, {node, stops}}
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    pq.push({0, {src, 0}});

    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int price = curr.first;
        int node = curr.second.first;
        int stops = curr.second.second;

        // Destination reached
        if(node == dst)return price;

        // We can take at most k+1 flights
        if(stops == k + 1) continue;

        for(auto neighbour : graph[node]) {

            int nextNode = neighbour.first;
            int flightPrice = neighbour.second;

            int newPrice = price + flightPrice;
            int newStops = stops + 1;

            // If this is cheaper for this number of stops
            if(newPrice < dist[nextNode][newStops]) {
                dist[nextNode][newStops] = newPrice;
                pq.push({newPrice,{nextNode, newStops}});
            }
        }
    }

    return -1;
}

//TODO: ------------------------------------------------------------------Prim's Algorithm-------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int prims(int V, vector<vector<pair<int, int>>>& graph) {

    // {weight, vertex}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> vis(V, 0);

    int mstWeight = 0;

    // Start from vertex 0
    pq.push({0, 0});

    while (!pq.empty()) {

        // Get minimum weight edge
        auto curr = pq.top();
        pq.pop();

        int weight = curr.first;
        int node = curr.second;

        // Already included in MST
        if (vis[node])continue;

        // Include this node
        vis[node] = 1;

        // Add edge weight
        mstWeight += weight;

        // Visit all adjacent vertices
        for (auto curr : graph[node]) {
            int neighbor = curr.first;
            int edgeWeight = curr.second;
            if (!vis[neighbor]) {
                pq.push({edgeWeight, neighbor});
            }
        }
    }

    return mstWeight;
}

int main() {

    int V = 5;

    vector<vector<pair<int, int>>> graph(V);

    // Undirected graph
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});

    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    graph[3].push_back({4, 9});
    graph[4].push_back({3, 9});

    cout << "MST Weight = " << prims(V, graph);

    return 0;
}

//Leetcode 1584. Min Cost to Connect All Points ***
# include <bits/stdc++.h>
# define pp pair<int,pair<int,int>>
using namespace std;
    
int main(){
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int n = points.size();
    vector<bool>vis(n,false);

    priority_queue<pp, vector<pp>, greater<pp>>pq;
    pq.push({0,{0,0}});
    int sum = 0;

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();

        int cost = curr.first;
        int currNode = curr.second.first;
        int prtNode = curr.second.second;

        if(vis[currNode])continue;
        
        vis[currNode] = true;
        sum += cost;

        for(int i=0; i<n; i++){
            if(i == currNode)continue;

            int x1 = points[currNode][0], y1 = points[currNode][1];
            int x2 = points[i][0], y2 = points[i][1];

            if(!vis[i]){
                int newCost = abs(x1-x2)+abs(y1-y2);
                pq.push({newCost,{i,currNode}});
            }
        }
    }
    cout<< sum;
}

//TODO: Bellman–Ford Aakgorithm 
// Bellman–Ford works by relaxing every edge V-1 times.
// For Practice try Network Delay Time 
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++) {
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative cycle
    for(auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Negative cycle exists";
            return {};
        }
    }

    return dist;
}

//TODO: Floyd–Warshall -> 
// It is used to find the shortest distance between every pair of vertices.
#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist) {

    int n = dist.size();

    // k = intermediate vertex
    for(int k = 0; k < n; k++) {

        // i = source
        for(int i = 0; i < n; i++) {

            // j = destination
            for(int j = 0; j < n; j++) {

                if(dist[i][k] != INT_MAX &&
                   dist[k][j] != INT_MAX) {

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }
    }
}

int main() {

    int n = 4;

    const int INF = INT_MAX;

    vector<vector<int>> dist = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(dist);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Leetcode 1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    int n = 5,  dstThreshold = 2;
    vector<vector<int>> edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int m = edges.size();

    vector<vector<int>>wtMatrix(n, vector<int>(n,INT_MAX));

    // Distance from a city to itself = 0
    for(int i = 0; i < n; i++) { 
        wtMatrix[i][i] = 0;
    }

    // Building the Distance Matrix
    for(int i=0; i<m; i++){
        int src = edges[i][0];
        int dst = edges[i][1];
        int wt  = edges[i][2];

        wtMatrix[src][dst] = wt;
        wtMatrix[dst][src] = wt;
    }

    // Floyd–Warshal
    for(int k=0; k<n; k++){ // via K routes

        for(int i=0; i<n; i++){
            if(i==k)continue;

            for(int j=0; j<n; j++){
                if(j==k)continue;

                if(wtMatrix[i][k] != INT_MAX && wtMatrix[k][j] != INT_MAX){

                    wtMatrix[i][j] = min(wtMatrix[i][j],wtMatrix[i][k] + wtMatrix[k][j]);
                }
            }
        }
    }

    int city = -1;
    int cityCount = INT_MAX;

    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(wtMatrix[i][j] <= dstThreshold)count++;    
        }
        if(count <= cityCount){
            city = i;
            cityCount = count;
        }
    }
    return city;
}

//TODO: DSU-> Disjoint Set Union by Size array And Path Compression
// Leetcode 684: Redundant Connection
# include <bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>size;
int find(int a){
    if(parent[a] == a)return a;
    return parent[a] = find(parent[a]);
}

void Union(int u, int v){
    int a = find(u);
    int b = find(v);

    if(a!=b){
        if(size[a] > size[b]){
            parent[b] = a;
            size[a]+=size[b];
        }else{
            parent[a] = b;
            size[b]+=size[a];
        }
    }
}

int main(){
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    int n = edges.size();
    size.assign(n+1,1);
    
    parent.resize(n+1);
    for(int i=0; i<=n; i++) parent[i] = i;
    
    for(int i=0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        if(find(u)==find(v)){// cycle Detected
            cout<<u<<v;
        }else{
            Union(u,v);
        }
    }
    // return {-1,-1};
}

// Leetcode 785. Is Graph Bipartite? -> Checkout leetcode


//TODO: Kruskal's Algorithm
// Sort all edges by increasing weight.
// Pick the smallest edge.
// Add it to the MST only if it doesn't form a cycle.
// Repeat until we have V − 1 edges.
