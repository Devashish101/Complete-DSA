// Codeforces Disjoint Set Union 2.
// Implement dsu data structure and perform 2 types of queries:-
// 1. "union" u, v -> unite/merge 2 sets that contain u and v.
// 2. get v -> find the set to which v belongs to, find minimal and maximal ele of the set and the total no. of ele in it.

// Test case & outputs
// n = 5, m = 11
// union 1 2
// get 3 -> 3 3 1
// get 2 -> 1 2 2
// union 2 3
// get 2 -> 1 3 3
// union 1 3
// get 5 -> 5 5 1
// union 4 5 
// get 5 -> 4 5 2
// union 4 1
// get 5 -> 1 5 5

#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int x) {
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
}

// Union two sets using Size
void unionSet(vector<int>& parent, vector<int>& size, vector<int>& minimal, vector<int>& maximal, int a, int b) {

    // Find the representatives
    a = find(parent, a);
    b = find(parent, b);

    // Already in the same set
    if(a == b)return;

    // Attach smaller set to larger set
    if(size[a] >= size[b]) {
        parent[b] = a;
        size[a] += size[b];
        maximal[a] = max(maximal[a],maximal[b]);
        minimal[a] = min(minimal[a],minimal[b]);
    } else {
        parent[a] = b;
        size[b] += size[a];
        maximal[b] = max(maximal[a],maximal[b]);
        minimal[b] = min(minimal[a],minimal[b]);
    }
}

    
int main(){

   int n;
   cin>>n;

   vector<int> parent(n+1);
   for(int i=0; i<=n; i++) parent[i] = i;

   vector<int>size(n+1,1);

   vector<int>minimal(n+1); 
   vector<int>maximal(n+1); 

    int m;
    cin>>m;
    while(m--){

        string str;
        cin >> str;

        if(str == "union") {
            int x, y;
            cin >> x >> y;
            unionSet(parent, size, minimal, maximal, x, y);

        } else { // find
            int x;
            cin >> x;
            x = find(parent, x);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<size[x]<<"\n";
        }
    }     
    
}

//TODO: TOPOLOGICAL SORTING USING BFS (KAHN'S ALGORITHM)
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
void add_edge(int src, int dst, bool bi_dir = true){
    graph[src].push_back(dst);
    if(bi_dir){
        graph[dst].push_back(src);
    }
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<"{";
        for(auto ele:graph[i]){
            cout<<ele<<" ";
        }
        cout<<"}"<<endl;
    }
}

void topoBFS(vector<int>& indegree){
    for(int i=0; i<graph.size(); i++){
        for(auto neibour: graph[i]){
            indegree[neibour]++;
        }
    }

    unordered_set<int>visited;
    queue<int>qu;
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i] == 0){
            qu.push(i);
            visited.insert(i);
        }
    }

    cout<<"Starting Topological BFS"<<"\n";
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        cout<<node<<" ";

        for(auto neibour: graph[node]){
            if(!visited.count(neibour)){
                indegree[neibour]--;

                if(indegree[neibour] == 0){
                    qu.push(neibour);
                    visited.insert(neibour);
                }
            }
        }

    }
}
    
int main(){
    
    int vrtx = 8;
    graph.resize(vrtx+1, vector<int>());
    int edge;
    cin>>edge; // 11
    while(edge--){
        int src, dst;
        cin>>src>>dst;
        add_edge(src,dst,false); // add_edge1(src,dst,false) ->it will make an directed graph
    }   
    display();
    vector<int>indegree(vrtx+1,0);
    topoBFS(indegree);
}

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> ans;

void add_edge1(int src, int dst) {
    graph[src].push_back(dst);
}

void dfs(int node) {
    visited[node] = 1;

    for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }

    // Add after visiting all neighbours
    ans.push_back(node);
}

int main() {
    int n = 6;

    graph.resize(n);
    visited.assign(n, 0);

    add_edge1(5, 2);
    add_edge1(5, 0);
    add_edge1(4, 0);
    add_edge1(4, 1);
    add_edge1(2, 3);
    add_edge1(3, 1);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto x : ans) {
        cout << x << " ";
    }
}

// Test Case
// 11
// 0 2
// 1 2
// 2 4
// 2 3
// 1 3
// 2 5 
// 2 6
// 4 6
// 6 7
// 3 5
// 5 6

// TODO: Leetcode 207, 210
