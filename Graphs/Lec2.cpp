// ------------------------------------------ DFS traversal of a graph----------------------------------------
// Test Case :-
// 1 2
// 1 4
// 2 3
// 3 4
// 4 5
// 5 6
// 5 7
// 6 7

# include <bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;
void add_edge(int src, int dst, bool bi_dir = true){
    graph[src].push_back(dst);
    if(bi_dir){
        graph[dst].push_back(src);
    }
}

// Check if there is a path b/w given src to dst.
unordered_set<int>visited;
bool dfs(int curr, int dst){
    if(curr == dst)return true;
    visited.insert(curr);
    for(auto neighbour: graph[curr]){
        if(!visited.count(neighbour)){
            bool result = dfs(neighbour,dst);
            if(result) return true;
        }
    }
    return false;
}
    

// Print all the paths between src to dst.
vector<vector<int>>allPaths;
unordered_set<int>isvisited;
void print_path(int curr, int end, vector<int>&paths){
    if(curr == end){
        paths.push_back(curr);
        allPaths.push_back(paths);
        paths.pop_back();
        return;
    }
    isvisited.insert(curr);
    paths.push_back(curr);
    for(auto neighbour: graph[curr]){
        if(!isvisited.count(neighbour)){
            print_path(neighbour,end,paths);
        }
    }
    paths.pop_back();
    isvisited.erase(curr);
}


int main(){
    int vrtx = 7;
    graph.assign(vrtx+1, vector<int>());

    int edge = 8;
    while(edge -- ){
        int src, dst;
        cin>>src>>dst;
        add_edge(src,dst);
    }
    int st, end;
    cin>>st>>end;
    cout<<dfs(st,end)<<endl;

    vector<int>arr;
    print_path(st,end,arr);
    for(auto ele:allPaths){
        for(auto x:ele){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

// ----------------------------------------------BFS traversal of a graph--------------------------------------------
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;
void add_edge(int src, int dst, bool bi_dir = true){
    graph[src].push_back(dst);
    if(bi_dir){
        graph[dst].push_back(src);
    }
}

unordered_set<int>visited;
void bfs(int src){
    visited.clear();
    queue<int>qu;

    visited.insert(src);
    qu.push(src);
    while(!qu.empty()){
        int curr = qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbour: graph[curr]){
            if(!visited.count(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    cout<<endl;
}
    
int main(){
    int vrtx = 7;
    graph.assign(vrtx+1, vector<int>());

    int edge = 8;
    while(edge -- ){
        int src, dst;
        cin>>src>>dst;
        add_edge(src,dst);
    }

    int st;
    cin>>st;
    bfs(st);
}