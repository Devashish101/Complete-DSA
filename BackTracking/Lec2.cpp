//Leetcode 36: - Valid soduko 

# include <bits/stdc++.h>
using namespace std;

bool isvalid(char board[][9],int rw,int col,char ch){

    // Checking the whole Row
    for(int i=0; i<9; i++){
        if(board[rw][i]==ch)return false;
    }

    // Checking the whole column
    for(int i=0; i<9; i++){
        if(board[i][col]==ch)return false;
    }

    // Checking the 3*3 grid
    int bigrw = rw/3*3;
    int bigcol = col/3*3;
    for(int i=bigrw; i<bigrw+3; i++){
        for(int j=bigcol; j<bigcol+3; j++){
            if(board[i][j]==ch)return false;
        }
    }
    return true;
}
    
int main(){
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };
    
    bool flag = 0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]!='.'){
                char ch = board[i][j];
                board[i][j] = '.';
                if(!isvalid(board,i,j,ch)){
                    flag = 1;
                }
                board[i][j] = ch;
            }
            else continue;
        }
        if(flag==1)break;
    }
    if(flag==0)cout<<true;
    else cout<<false;
}


//Leetcode 37: - soduko solver
# include <bits/stdc++.h>
using namespace std;

bool check = 0;//For avoiding the backtracking in case of valid complete ans.
bool isvalid(char board[][9],int rw,int col,char ch){

    // Checking the whole Row
    for(int i=0; i<9; i++){
        if(board[rw][i]==ch)return false;
    }

    // Checking the whole column
    for(int i=0; i<9; i++){
        if(board[i][col]==ch)return false;
    }

    // Checking the 3*3 grid
    int bigrw = rw/3*3;
    int bigcol = col/3*3;
    for(int i=bigrw; i<bigrw+3; i++){
        for(int j=bigcol; j<bigcol+3; j++){
            if(board[i][j]==ch)return false;
        }
    }
    return true;
}

void helper(char board[][9],int rw,int col){
        if(rw==9){ //Base condition.
            check = 1;
            return;
        }

        if(board[rw][col]!='.'){
            if(col!=8) helper(board,rw,col+1);
            else helper(board,rw+1,0);
        } 
        else{
            for(int i=1; i<10; i++){
                char ch = '0'+i;
                if(isvalid(board,rw,col,ch)){
                    board[rw][col] = ch;
                    if(col!=8)helper(board,rw,col+1);
                    else helper(board,rw+1,0);
                }
                if(check==1)return;//Return without backtracking
                board[rw][col] = '.';
            }
        }
        
    }
    
int main(){
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };
    helper(board,0,0); 
    for(int i=0; i<9; i++){
        cout<<"[ ";
        for(int j=0; j<9; j++){
            cout<<board[i][j]<<"\t";
        }
        cout<<" ]";
        cout<<"\n";
    }
}

    // Leetcode 2596: Check Knight tour configuration.
    # include <bits/stdc++.h>
    using namespace std;

    bool check = 0;
    vector<int> isvalid(int grid[][5],int strow,int stcol,int val){
        int n = 5;
        vector<int> rowcol;
        // Top Right
        int currrw = strow-2;
        int currcol = stcol+1;
        if(currrw >= 0  && currcol < n){
            if(grid[currrw][currcol]==val+1){
                rowcol.push_back(currrw);
                rowcol.push_back(currcol);
                return rowcol;
            }
        }

        // Top Left
        currrw = strow-2;
        currcol = stcol-1;
        if(currrw >= 0 &&  currcol >= 0){
            if(grid[currrw][currcol]==val+1){
                rowcol.push_back(currrw);
                rowcol.push_back(currcol);
                return rowcol;
            }
        }

        // Right Up
        currrw = strow-1;
        currcol = stcol+2;
        if(currrw >= 0 && currcol < n){
            if(grid[currrw][currcol]==val+1){
                rowcol.push_back(currrw);
                rowcol.push_back(currcol);
                return rowcol;
            }
        }

        // Right Down
        currrw = strow+1;
        currcol = stcol+2;
        if( currrw < n && currcol < n){
            if(grid[currrw][currcol]==val+1){
                rowcol.push_back(currrw);
                rowcol.push_back(currcol);
                return rowcol;
            }
        }

        // Down Right
        currrw = strow+2;
        currcol = stcol+1;
        if(currrw < n && currcol < n){
            if(grid[currrw][currcol]==val+1){
                rowcol.push_back(currrw);
                rowcol.push_back(currcol);
                return rowcol;
            }
        }

        // Down Left
        currrw = strow+2;
        currcol = stcol-1;
        if( currrw < n && currcol >= 0 ){
            if(grid[currrw][currcol]==val+1){
                rowcol.push_back(currrw);
                rowcol.push_back(currcol);
                return rowcol;
            }
        }

        // Left Down
        currrw = strow+1;
        currcol = stcol-2;
        if(currrw < n && currcol >= 0 ){
            if(grid[currrw][currcol]==val+1){
                rowcol.push_back(currrw);
                rowcol.push_back(currcol);
                return rowcol;
            }
        }

        // Left Up
        currrw = strow-1;
        currcol = stcol-2;
        if(currrw >= 0  && currcol >= 0){
            if(grid[currrw][currcol]==val+1){
                rowcol.push_back(currrw);
                rowcol.push_back(currcol);
                return rowcol;
            }
        }

        return rowcol;
    }

    void helper(int grid[][5],int rw,int col,int count){
        if(grid[rw][col]==5*5-1){
            check = 1;
            return;
        }

        vector<int>rwcol;
        rwcol = isvalid(grid,rw,col,count);
        if(rwcol.size()==2){
            int nextrw = rwcol[0];
            int nextcol = rwcol[1];
            helper(grid,nextrw,nextcol,count+1);
        }
        else return;

    }

    int main(){
        int grid[][5] = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
        bool flag = 0;
        if(grid[0][0]!=0){
            cout<<"Not a valid configuration of the knight's movements";
            flag = 1;
        }
        int count = 0;
        if(flag==0)helper(grid,0,0,count);
        if(check==1)cout<<"A valid configuration of the knight's movements.";
        else cout<<"Not valid configuration of the knight's movements.";
    }

