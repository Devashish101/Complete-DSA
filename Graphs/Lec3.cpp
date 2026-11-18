// Leetcode 733: Flood Fill
# include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& image, int currRow, int currCol, int initial_color, int color){
    int m = image.size();
    int n = image[0].size();
    if(currRow < 0 || currCol < 0 || currRow >= m || currCol >= n)return;
    if(image[currRow][currCol] != initial_color)return;

    image[currRow][currCol] = color;
    dfs(image, currRow+1, currCol, initial_color, color); // Down
    dfs(image, currRow, currCol-1, initial_color, color); // Left
    dfs(image, currRow-1, currCol, initial_color, color); // Up
    dfs(image, currRow, currCol+1, initial_color, color); // Right
}
    
int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    // if(color == image[sr][sc])return image;
    dfs(image,sr,sc,image[sr][sc],color);
    for(auto ele: image){
        for(auto x: ele){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 1791. Find Center of Star Graph
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<vector<int>> edges = {{1,2},{5,1},{1,3},{1,4}};
    int a = edges[0][0], b = edges[0][1];
    int c = edges[1][0], d = edges[1][1];
    return((a==c || b==c)?c:d);
    
}

// 841. Keys and Rooms
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{2,3}};
    unordered_set<int>visited;
    queue<int>qu;

    qu.push(0);
    visited.insert(0);
    while(qu.size() > 0){
        int curr = qu.front();
        qu.pop();
        for(auto neighbour : rooms[curr]){
            if(visited.count(neighbour) == 0){ // This room is not visited yet
                qu.push(neighbour);
                visited.insert(neighbour);   
            }
        }
    }
    return (visited.size()==rooms.size()?true:false);
}

// Leetcode 133. Clone Graph -> Checkout Leetcode

// Program to find the No. of Connected Components in a graph.
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph1;
void add_edge1(int src, int dst, bool bi_dir = true){
    graph1[src].push_back(dst);
    if(bi_dir){
        graph1[dst].push_back(src);
    }
}

unordered_set<int>visited;
void dfs(int i){
    visited.insert(i);
    for(auto neibours: graph1[i]){
        if(!visited.count(neibours)){
            dfs(neibours);
        }
    }
}

int main(){
    
    int vertex = 7;
    graph1.resize(vertex+1, vector<int>());
    int edge = 8;
    while(edge--){
        int src, dst;
        cin>>src>>dst;
        add_edge1(src,dst);
    }   

    int n = graph1.size();
    int conted_compnts = 0; // No. Of Connected Components in a graph.
    for(int i=1; i<n; i++){
        if(!visited.count(i)){
            conted_compnts++;
            dfs(i);
        }
    }
    cout<<conted_compnts;
}

// Leetcode 1034. Coloring A Border. ***
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> internalCells;
void dfs(vector<vector<int>>& grid, int r, int c,
         int newColor, int originalColor) {

    // Out of bounds or not part of the original component
    if (r < 0 || c < 0 ||
        r >= grid.size() || c >= grid[0].size() ||
        grid[r][c] != originalColor) {
        return;
    }

    // Mark as visited
    grid[r][c] = -newColor;

    // DFS in 4 directions
    dfs(grid, r + 1, c, newColor, originalColor);
    dfs(grid, r - 1, c, newColor, originalColor);
    dfs(grid, r, c + 1, newColor, originalColor);
    dfs(grid, r, c - 1, newColor, originalColor);

    // Coming back from recursion:
    // Check whether current cell is internalcell.
    //
    // A cell is internal if:
    // 1. It is not on the boundary
    // 2. All 4 neighbors are part of the component
    if (r != 0 &&
        c != 0 &&
        r != grid.size() - 1 &&
        c != grid[0].size() - 1 &&
        grid[r + 1][c] == -newColor &&
        grid[r - 1][c] == -newColor &&
        grid[r][c + 1] == -newColor &&
        grid[r][c - 1] == -newColor) {

        internalCells.push_back({r, c});
    }
}

int main() {

    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    int row = 1;
    int col = 1;
    int color = 2;

    int originalColor = grid[row][col];

    dfs(grid, row, col, color, originalColor);

    // Restore internal cells to original color
    for (auto p : internalCells) {
        int i = p.first;
        int j = p.second;

        grid[i][j] = originalColor;
    }

    // Convert negative values back to positive
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {

            if (grid[i][j] < 0) {
                grid[i][j] *= -1;
            }
        }
    }

    // Print answer
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}