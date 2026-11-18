// 4 Way Maze Path.
# include <bits/stdc++.h>
using namespace std;

void mazePath(int arr[][3],int strw,int stcol,int rw,int col,string ans,bool copyarr[][3]){
    if(strw>rw-1 || stcol>col-1){
        return;
    }
    if(strw<0 || stcol<0){
        return;
    }
    if(copyarr[strw][stcol]==1) return;
    if(strw==rw-1 && stcol==col-1){
        cout<<ans<<"\n";
        return;
    }

    copyarr[strw][stcol] = 1;
    // For right
    mazePath(arr,strw,stcol+1,rw,col,ans+'R',copyarr);
    // For Left
    mazePath(arr,strw,stcol-1,rw,col,ans+'L',copyarr);
    // For UP
    mazePath(arr,strw-1,stcol,rw,col,ans+'U',copyarr);
    // For Down
    mazePath(arr,strw+1,stcol,rw,col,ans+'D',copyarr);
    copyarr[strw][stcol] = 0;

}
    
int main(){
    
    int arr[3][3];
    bool copyarr[3][3] = {}; 
    int rw = 3;
    int col = 3;
    string ans = "";
    mazePath(arr,0,0,rw,col,ans,copyarr);
    return 0;
}


// Rat in a maze in 4 direction with open and blocked cells.
# include <bits/stdc++.h>
using namespace std;
    
int ans;

bool isvalid(int grid[][7],int rw,int col,int n){
    return rw >= 0 && col >=0 && rw < n && col < n && grid[rw][col] == 0; 
}

void RatinMaze(int grid[][7],int rw,int col,int n){
    if(rw==n-1 && col==n-1){
        ans++;
        return;
    }

    grid[rw][col] = 2;//marking the node as visited

    // left
    if(isvalid(grid,rw,col-1,n)){
        RatinMaze(grid,rw,col-1,n);
    }

    // Up
    if(isvalid(grid,rw-1,col,n)){
        RatinMaze(grid,rw-1,col,n);
    }

    // Right
    if(isvalid(grid,rw,col+1,n)){
        RatinMaze(grid,rw,col+1,n);
    }

    // Down
    if(isvalid(grid,rw+1,col,n)){
        RatinMaze(grid,rw+1,col,n);
    }
    
    grid[rw][col] = 0;//unmarking the node after doing all calls
}

int main(){
    
    int grid[7][7] = {
                     {0,0,1,0,0,1,0},
                     {1,0,1,1,0,0,0},
                     {0,0,0,0,1,0,1},
                     {1,0,1,0,0,0,0},
                     {1,0,1,1,0,1,0},
                     {1,0,0,0,0,1,0},
                     {1,1,1,1,0,0,0}
                    };
    int n = 7;
    RatinMaze(grid,0,0,n);
    cout<<"Total Possible ways are = "<<ans;
    return 0;
}

// N-Queen problem 
# include <bits/stdc++.h>
using namespace std;
bool isSafe(char arr[][5],int currrow,int currcol,int n){
    // For Column
    for(int i=0; i<currrow; i++){
        if(arr[i][currcol]=='Q')return false;
    }
    // For Left diagonals
    int lftrw=currrow-1;
    int lftcol=currcol-1;
    while(lftrw>=0 && lftcol>=0){
        if(arr[lftrw][lftcol]=='Q')return false;
        lftrw--;
        lftcol--;
    }
    // For Right diagonals
    int rgtrw=currrow-1;
    int rgtcol=currcol+1;
    while(rgtrw>=0 && rgtcol<n){
        if(arr[rgtrw][rgtcol]=='Q')return false;
        rgtrw--;
        rgtcol++;
    }
    
    return true;
}

void nqueen(char arr[][5],int strow,int n){
    if(strow==n){//Base case
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }

    for(int i=0; i<n; i++){//Looping on each col of the curr row
        if(isSafe(arr,strow,i,n)){
            arr[strow][i] = 'Q';
            nqueen(arr,strow+1,n);
            arr[strow][i] = '.';
        }
    }
}
    
int main(){
    int n = 5;
    char arr[][5] = {{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'}};
    int strow = 0;
    nqueen(arr,strow,n);

    return 0;
}