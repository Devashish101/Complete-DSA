// Leetcode 547: Number of Provinces. -> T.C 0(n2)
# include <bits/stdc++.h>
using namespace std;

void bfs(int curr, vector<vector<int>>& adj, vector<bool>& vis){
    int n = adj.size();
    vis[curr] = true;

    queue<int>qu;
    qu.push(curr);
    while(!qu.empty()){
        int ele = qu.front();
        qu.pop();
        for(int j=0; j<n; j++){
            if(adj[ele][j] == 1 && vis[j] != true){
                vis[j] = true;
                qu.push(j);
            }
        }
    }
}

int main(){
    vector<vector<int>> adj = {{1,1,0},{1,1,0},{0,0,1}};
    int n = adj.size();
    vector<bool>vis(n, false);
    int count = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            count++;
            bfs(i,adj,vis);
        }
    }
    cout<< count;
}

//Leetcode 841. Keys and Rooms

// Leetcode 1971. Find if Path Exists in Graph
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;
void add_edge(int sr, int dt){
    graph[sr].push_back(dt);
    graph[dt].push_back(sr);
}
    
int main(){
    
    int vrtx = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int src = 0, dst = 2;
    
    if(vrtx==1)cout<<true;
        
    graph.assign(vrtx, vector<int>());
    for(int i=0; i<edges.size(); i++){
        auto curredge = edges[i];
        int sr = curredge[0];
        int dt = curredge[1];
        add_edge(sr,dt);
    }

    unordered_set<int>vis;
    vis.insert(src);

    bool flag = true;
    queue<int>qu;
    qu.push(src);
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        for(auto neighbour: graph[node]){
            if(neighbour == dst){
                cout<<true;
                flag = false;
            }
            else if(!vis.count(neighbour)){
                qu.push(neighbour);
                vis.insert(neighbour);
            }
        }
    }
    if(flag)cout<<false;

}

// Leetcode 200 : No. of islands

// TODO: Cycle Detection in Undirected Graph.
// Using BFS & DFS:-
// -> If neighbour node of curr node is not it's parent and it is still visited then there is a cycle.

// Bipartite graph
// => A graph is an Bipartite if we can color the whole graph with only 2 diff colors and adjacent nodes have diff colors. 
// => Any acyclic graph or graph having even cyclic len is always a bipartite graph.

//  Leetcode 785 : Bipartite graph
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    int n = graph.size();
    vector<int>vis(n,-1);

    bool flag = true;
    queue<int>qu;
    for(int i=0; i<n; i++){
        if(vis[i] != -1)continue;
        else{
            qu.push(i);
            vis[i] = 0;
            while(!qu.empty()){
                int node = qu.front();
                qu.pop();
                for(auto neighbour: graph[node]){
                    if(vis[neighbour] != -1){ // If Neighbour is already visited.
                        // Same color -> can't be bipartite
                        if(vis[node] == vis[neighbour]){
                            cout<<false;
                            flag = false;
                        }  
                    }
                    else if(vis[neighbour] == -1){ // If Neighbour is not visited.
                        qu.push(neighbour);
                        // Give opposite color
                        if(vis[node] == 0) vis[neighbour] = 1; 
                        else if(vis[node] == 1) vis[neighbour] = 0;
                    }
                }
            }              
        }
    }
    if(flag)cout<<true;
}

// TODO: Topological Sorting -> Topological sorting is applied on a DAG(Directed Ayclic graph).
// It is impossible to perform on graphs with cycles or undirected edges because circular dependencies prevent a valid starting point.
// a single graph can have multiple valid topological sequences. 
// For every edge u–>v in a graph u must comes before v in the ordering of the graph edges.

// Common Algorithms:-
// Kahn's Algorithm (BFS-based): Repeatedly finds nodes with an in-degree (incoming edges) of zero, adds them to the result, and removes their outgoing edges until all nodes are processed.

// Depth-First Search (DFS): Explores graph vertices recursively and pushes a node onto a stack only after visiting all its adjacent descendants, then reverses the stack to get the final order.

// TODO: Cycle Detection in Directed Graph using BFS(Topological sort)
// => Apply the simple kahn's algo of topological sort 
// And if at end count == n then there is no cycle else in case of count < n there is cycle.
// Wherr count = no. of visited nodes and n = total no. of nodes.

// Leetcode 210: Course Schedule II
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    int n = 3;
    vector<vector<int>> order = {{1,0},{1,2},{0,1}};
    int m = order.size();
        
    // Forming the adjacency List and calculating the indegree of each node.
    vector<int>indegree(n,0);
    vector<vector<int>>adj(n); 
    for(int i=0; i<m; i++){
        int pre = order[i][1];
        int post = order[i][0];
        
        adj[pre].push_back(post);
        indegree[post]++;
    }

    // Applying Topological Sort BFS(Kahn's algo).
    unordered_set<int>vis;
    queue<int>qu;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            qu.push(i);
            vis.insert(i);
        }
    }

    while(!qu.empty()){
        int ele = qu.front();
        qu.pop();
        for(auto neighbour: adj[ele]){
            if(!vis.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
    }

    return(vis.size() == n)?true:false;
}
// Leetcode 210. Course Schedule II -> same as above


//Leetcode  802. Find Eventual Safe States
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    int n = graph.size();

    // Making an reverse edge list of graph(i.e making an edge from j to i)
    vector<int>indegree(n,0);
    vector<vector<int>>graphrev(n);
    for(int i=0; i<n; i++){
        for(auto ele:graph[i]){
            graphrev[ele].push_back(i);
            indegree[i]++;
        }
    }

    vector<int>ans;
    unordered_set<int>vis;
    queue<int>qu;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            qu.push(i);
            vis.insert(i);
            ans.push_back(i);
        }
    }
    
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();

        for(auto neighbour:graphrev[node]){
            indegree[neighbour]--;

            if(indegree[neighbour] == 0){
                qu.push(neighbour);
                ans.push_back(neighbour);
            }
        }
    }
    sort(ans.begin(), ans.end());
    // return ans;
}

// TODO: Cycle detection in a directed graph using DFS,
// standard approach uses two arrays:
// vis[node] → node has been visited before.
// path[node] → node is currently in the recursion path.
class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj,
             vector<bool>& vis, vector<bool>& path) {

        vis[node] = true;
        path[node] = true;

        for(auto neighbour : adj[node]) {

            // Neighbour is in the current DFS path
            // => cycle exists
            if(path[neighbour])
                return true;

            // Visit unvisited neighbour
            if(!vis[neighbour]) {
                if(dfs(neighbour, adj, vis, path))
                    return true;
            }
        }

        // DFS for this node is complete
        path[node] = false;

        return false;
    }

    bool hasCycle(int n, vector<vector<int>>& adj) {

        vector<bool> vis(n, false);
        vector<bool> path(n, false);

        // Graph may be disconnected
        for(int i = 0; i < n; i++) {

            if(!vis[i]) {
                if(dfs(i, adj, vis, path))
                    return true;
            }
        }

        return false;
    }
};

//TODO: Dijkstra's Algorithm
// Dijkstra's algorithm is used to find the shortest distance from one source node to all other nodes in a weighted graph.

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {

    // dist[i] = shortest distance from src to i
    vector<int> dist(n, INT_MAX);

    // {distance, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // Distance of source from itself = 0
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto curr = pq.top();
        int currDist = curr.first;
        int node = curr.second;
        
        pq.pop();

        // Ignore outdated entry
        if(currDist > dist[node])
            continue;

        // Explore neighbours
        for(auto neighbour : adj[node]) {

            // Relaxation
            if(currDist + neighbour.first < dist[neighbour.first]) {

                dist[neighbour.first] = currDist + neighbour.first;

                pq.push({dist[neighbour.first], neighbour.second});
            }
        }
    }

    return dist;
}

// Leetcode 743. Network Delay Time -> Pure Dijikstra's Algorithm
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, src = 2;
    vector<vector<pair<int,int>> > graph(n+1);
    for(int i=0; i<times.size(); i++){
        int src = times[i][0];
        int dst = times[i][1];
        int wt = times[i][2];

        graph[src].push_back({wt,dst});
    }

    vector<int>wt(n+1,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    pq.push({0,src});
    wt[src] = 0;
    while(!pq.empty()){
        auto curr = pq.top();
        int currWt = curr.first;
        int currNode = curr.second;
        
        pq.pop();
        for(auto neighbour:graph[currNode]){
            if(currWt + neighbour.first < wt[neighbour.second]){
                wt[neighbour.second] = currWt + neighbour.first;
                pq.push({currWt+neighbour.first, neighbour.second});
            }
        }
    }
    int ans = *max_element(wt.begin()+1, wt.end());
    return (ans==INT_MAX?-1:ans);
    
}

//Leetcode 1514: Path with Maximum Probability
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    int vrtx = 3;
    vector<vector<int>> edges = {{0,1},{0,1},{0,2}}; 
    vector<double> Prob = {0.5,0.5,0.3};
    int st = 0, end = 2;

    int n = edges.size();
    vector<vector<pair<double,int>> >graph(vrtx);

    for(int i=0; i<n; i++){
        int src = edges[i][0];
        int dst = edges[i][1];

        double prob = Prob[i];
        graph[src].push_back({prob,dst});
        graph[dst].push_back({prob,src});
    }

    vector<double>wt(vrtx,0);
    wt[st] = 1;

    priority_queue<pair<double,int>>pq;
    pq.push({1,st});
    while(!pq.empty()){
        auto current = pq.top();
        double prob = current.first;
        int node = current.second;
        pq.pop();

        for(auto neighbour:graph[node]){
            if(prob * neighbour.first > wt[neighbour.second]){
                wt[neighbour.second] = prob * neighbour.first;
                pq.push({wt[neighbour.second],neighbour.second});
            }
        }
    }
    return wt[end];
}