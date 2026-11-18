// Leetcode 200. Number of Islands
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

    int m = grid.size();
    int n = grid[0].size();

    int cc = 0; // Conected Components
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '0')continue;
            else{
                cc++;
                grid[i][j] = '0'; // Mark as visited
                queue<pair<int,int>>qu;
                qu.push({i,j});
                while(!qu.empty()){
                    auto curr = qu.front();
                    qu.pop();
                    // Visit all the neighbours of curr Node.
                    int currRow = curr.first;
                    int currCol = curr.second;
                    // Check Up
                    if(currRow - 1 >= 0 && grid[currRow-1][currCol] == '1'){
                        qu.push({currRow-1,currCol});
                        grid[currRow-1][currCol] = '0'; 
                    }
                    // Check Right
                    if(currCol + 1 < n && grid[currRow][currCol+1] == '1'){
                        qu.push({currRow,currCol+1});
                        grid[currRow][currCol+1] = '0'; 
                    }
                    // Check Down
                    if(currRow + 1 < m && grid[currRow+1][currCol] == '1'){
                        qu.push({currRow+1,currCol});
                        grid[currRow+1][currCol] = '0'; 
                    } 
                    // Check Left
                    if(currCol - 1 >= 0 && grid[currRow][currCol-1] == '1'){
                        qu.push({currRow,currCol-1});
                        grid[currRow][currCol-1l] = '0'; 
                    }

                }
            }
        }
    }
    return cc;
}

// 417. Pacific Atlantic Water Flow
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{1, 0},{-1, 0},{0, 1},{0, -1}};
vector<vector<bool>> bfs(queue<pair<int, int>>& q, int rows, int cols,vector<vector<int>>& h) {
    vector<vector<bool>> visited(rows,vector<bool>(cols, false));

    while (!q.empty()) {
        auto cell = q.front();
        q.pop();

        int i = cell.first;
        int j = cell.second;

        visited[i][j] = true;

        for (int d = 0; d < 4; d++) {
            int newRow = i + dir[d][0];
            int newCol = j + dir[d][1];

            // Out of bounds
            if (newRow < 0 || newCol < 0 ||
                newRow >= rows || newCol >= cols)
                continue;

            // Already visited
            if (visited[newRow][newCol])
                continue;

            // Reverse flow:
            // We can move to the neighbour only if
            // its height is >= current cell's height.
            if (h[newRow][newCol] < h[i][j])
                continue;

            q.push({newRow, newCol});
        }
    }

    return visited;
}
    
int main(){
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    int rows = heights.size();
    int cols = heights[0].size();

    queue<pair<int, int>> pacificbfs;
    queue<pair<int, int>> atlanticbfs;

    // Multi-source BFS
    // Pacific Ocean: left column
    // Atlantic Ocean: right column
    for (int i = 0; i < rows; i++) {
        pacificbfs.push({i, 0});
        atlanticbfs.push({i, cols - 1});
    }

    // Pacific Ocean: top row
    for (int j = 1; j < cols; j++) {
        pacificbfs.push({0, j});
    }

    // Atlantic Ocean: bottom row
    for (int j = 0; j < cols - 1; j++) {
        atlanticbfs.push({rows - 1, j});
    }

    // Find cells reachable from both oceans
    vector<vector<bool>> pacific = bfs(pacificbfs,rows,cols,heights);
    vector<vector<bool>> atlantic = bfs(atlanticbfs,rows,cols,heights);

    vector<vector<int>> result;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }

    // return result
}

// Leetcode 994. Rotting Oranges.
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}}; 
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int,int>>qu;
    int frsh_org = 0;

    // Multi Source BFS Step.(Pushing all the rotten oranges).
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1)frsh_org++;
            else if(grid[i][j] == 2)qu.push({i,j});
        }
    }

    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int mins = 0;
    qu.push({-1,-1}); // For Representing a end of level.
    while(!qu.empty()){
        auto cell = qu.front();
        qu.pop();

        if(cell.first == -1 && cell.second == -1){
            mins++;
            if(!qu.empty()){
                qu.push({-1,-1});
            }else break;
        }
        else{
            int i = cell.first;
            int j = cell.second;
            for(int d = 0; d < 4; d++){
                int newRow = i + dir[d][0];
                int newCol = j + dir[d][1];

                if(newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)continue;
                else if(grid[newRow][newCol] == 2 || grid[newRow][newCol] == 0)continue;
                else{
                    frsh_org--;
                    grid[newRow][newCol] = 2;
                    qu.push({newRow, newCol});
                }
            }
        }
    }
    return (frsh_org == 0) ? mins-1 : -1;
}