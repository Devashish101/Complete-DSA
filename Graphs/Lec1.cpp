// Start from Lec2 of Graphs
// Test Case :-
// 1 2
// 1 4
// 2 3
// 3 4
// 4 5
// 5 6
// 5 7
// 6 7

// Graph Implementation Using Adjacency List using Linked-List
# include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
void add_edge(int src, int dst, bool bi_dir = true){
    graph[src].push_back(dst);
    if(bi_dir){
        graph[dst].push_back(src);
    }
}

void display(){
    for(int i=0; i<graph.size(); i++){
        for(auto ele:graph[i]){
            cout<<ele<<"->";
        }
        cout<<endl;
    }
}

// Graph Implementation Using Adjacency List using vector<vector<int>>
vector<vector<int>> graph1;
void add_edge1(int src, int dst, bool bi_dir = true){
    graph1[src].push_back(dst);
    if(bi_dir){
        graph1[dst].push_back(src);
    }
}

void display1(){
    for(int i=0; i<graph1.size(); i++){
        cout<<"{";
        for(auto ele:graph1[i]){
            cout<<ele<<" ";
        }
        cout<<"}"<<endl;
    }
}
    
int main(){
    
    int vertex = 7;
    graph.resize(vertex+1, list<int>());
    // graph1.resize(vertex+1, vector<int>());
    int edge;
    cin>>edge; // 8
    while(edge--){
        int src, dst;
        cin>>src>>dst;
        add_edge(src,dst); // add_edge(src,dst,false) ->it will make an directed graph
        // add_edge1(src,dst); // add_edge1(src,dst,false) ->it will make an directed graph
    }   
    display();
    // display1();
    return 0;
}


// Graph Implementation Using Adjacency List using vector<vector<pair<int,int>>> src dst and wt
# include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph3;
void add_edge(int src, int dst, int wt,bool bi_dir = true){
    graph3[src].push_back({dst,wt});
    if(bi_dir){
        graph3[dst].push_back({src, wt});
    }
}

void display(){
    for(int i=0; i<graph3.size(); i++){
        cout<<"{";
        for(auto ele:graph3[i]){
                    //  dst and wt
            cout<<"{"<<ele.first<<" "<<ele.second<<"}"<<" ";
        }
        cout<<"}"<<endl;
    }
}
    
int main(){
    
    int vertex = 7;
    graph3.resize(vertex+1, vector<pair<int,int>>());
    int edge;
    cin>>edge; // 8
    while(edge--){
        int src, dst, wt;
        cin>>src>>dst>>wt;
        add_edge(src,dst,wt);
    }   
    display();
    return 0;
}


// Graph Implementation Using Adjacency Matrix vector<vector<int>>;
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph4;
void add_edge(int src, int dst, bool bi_dir = true) {
    graph4[src][dst] = 1;

    if (bi_dir) {
        graph4[dst][src] = 1;
    }
}

void display() {
    for (int i = 0; i < graph4.size(); i++) {
        for (int j = 0; j < graph4[i].size(); j++) {
            cout << graph4[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertex = 8;
    graph4.resize(vertex+1, vector<int>(vertex+1, 0));

    int edge;
    cin >> edge;

    while (edge--) {
        int src, dst;
        cin >> src >> dst;

        add_edge(src, dst);
    }
    display();
}

// Undirected weighted graph Implementation using Edge List
#include <bits/stdc++.h>
using namespace std;

#define pp pair<int, pair<int,int>>

int main() {

    int v, e;
    cin >> v >> e;

    vector<pp> edges;

    while(e--) {

        int src, dst, wt;
        cin >> src >> dst >> wt;

        edges.push_back({wt, {src, dst}});
    }

    // Display edge list
    for(auto edge : edges) {

        int wt = edge.first;
        int src = edge.second.first;
        int dst = edge.second.second;

        cout << src << " -- " << dst
             << " : " << wt << endl;
    }
}
    
