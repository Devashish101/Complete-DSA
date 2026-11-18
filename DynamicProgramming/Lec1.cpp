// TODO: Dynamic programming is an optimizing technique.
// TODO: It mainly used to either do the combinatorics (i.e count the no. of steps or ways like that),or minimizing or maximizing the problem
// TODO: While using the Memoization always think for going from n to 0 via recursion.

// Leetcode 509: Fibonacci Number
# include <bits/stdc++.h>
using namespace std;

// Approach 1- simple recursion
int fib(int n){
    if(n<=1)return n;
    return fib(n-1)+fib(n-2);
}

// Approach 2- Recursion + Memoization (Top - Down Approach)
int fibo(int n,vector<int>& dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}

// Approach 3- Tabulation or Iterative Dp (Bottom - UP Approach)
int fiboo(int n, vector<int>& dp){
    if(n<=1)return n;
    for(int i=0; i<n+1; i++){
        if(i<=1)dp[i]=i;
        else{
            dp[i] = dp[i-1]+dp[i-2];
        }
    }
    return dp[n];
}
int main(){
    
    int n = 5;
    cout<<fib(n)<<"\n";

    vector<int>dp(n+1,-1);
    cout<<fibo(n,dp)<<endl;

    vector<int>dp2(n+1);
    cout<<fibo(n,dp)<<'\n';
    
    return 0;
}


// Leetcode 746: Min cost Climbing Stairs.
# include <bits/stdc++.h>
using namespace std;

// Using Recursion
int mincost(vector<int>&cost,int idx,int totalcost){
    if(idx>=cost.size())return totalcost;
    return min(mincost(cost,idx+1,totalcost+cost[idx]),mincost(cost,idx+2,totalcost+cost[idx]));
}
    
// Using D.P (Recursion + Memoization) 
int mincost1(vector<int>&cost,int idx,vector<int>&dp){
    if(idx==0 || idx==1)return cost[idx];
    if(dp[idx]!=-1)return dp[idx];
    return dp[idx] = cost[idx] + min(mincost1(cost,idx-1,dp),mincost1(cost,idx-2,dp));
}

// Using Tabulation Method of D.P - Easy
void mincost2(vector<int>&cost){
    int n = cost.size();
    for(int i=2; i<n; i++){
        cost[i] += min(cost[i-1],cost[i-2]);
    }
    cout<<min(cost[n-1],cost[n-2]);
}
int main(){
    
    // vector<int>cost = {1,100,1,1,1,100,1,1,100,1};
    vector<int>cost = {10,15,10};
    int n = cost.size();
    cout<<min(mincost(cost,0,0),mincost(cost,1,0))<<"\n";

    vector<int>dp(n+1,-1);
    cout<<min(mincost1(cost,n-1,dp),mincost1(cost,n-2,dp))<<"\n";

    mincost2(cost);
    
    return 0;
}


// Leetcode 62:- Unique paths
# include <bits/stdc++.h>
using namespace std;

// Recursive Approach T.C = O(2^(m+n)) exponential.
void helper(int strow, int stcol,int m, int n,int &count){
    if(strow==m-1 && stcol==n-1){
        count++;
        return;
    }
    if(strow==m || stcol==n)return;

    helper(strow,stcol+1,m,n,count);
    helper(strow+1,stcol,m,n,count);
}

int paths(int strow, int stcol,int m, int n,vector<vector<int>>&dp){
    if(strow==m-1 && stcol==n-1){
        return 1;
    }
    if(strow==m || stcol==n)return 0;

    // D.P Check i.e - “Have I already calculated the total no. of paths from this cell.
    if(dp[strow][stcol]!=-1)return dp[strow][stcol];

    //store the unique paths from this cell in D.P i.e paths from right + paths from down
    return dp[strow][stcol] = paths(strow,stcol+1,m,n,dp) + paths(strow+1,stcol,m,n,dp);
}
    
int main(){
    
    int m = 3, n = 7;
    int count = 0;
    helper(0,0,m,n,count);
    cout<<count<<"\n";


    vector<vector<int>> dp(m,vector<int>(n,-1)); //2D D.P Memoization
    cout<<paths(0,0,m,n,dp)<<'\n';


    // Using Tabulation of D.P
    vector<vector<int>> dp1(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j==0)dp1[i][j] = 1; //Base case 0th row and 0th col
            else dp1[i][j] = dp1[i-1][j]+dp1[i][j-1]; // up+left
        }
    }
    cout<<dp1[m-1][n-1];

    return 0;
}

// H.W Leetcode : 63 unique path 2
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int helper(int strow,int stcol,int endrow,int endcol,vector<vector<int>>& obstacle){
    // Base Case.
    if(strow==endrow || stcol==endcol) return 0;
    if(obstacle[strow][stcol]==1)return 0;
    if(strow==endrow-1 && stcol==endcol-1) return 1;

    // Total ways  = ways by going rgt + ways by going down.
    if(dp[strow][stcol]!=-1)return dp[strow][stcol];
    int rightways =  helper(strow,stcol+1,endrow,endcol,obstacle);
    int downways = helper(strow+1,stcol,endrow,endcol,obstacle);
    return dp[strow][stcol] = rightways+downways;
}


    
int main(){
    vector<vector<int>> obstacle = {{0,0,0},{0,1,0},{0,0,0}}; // 2
    // vector<vector<int>> obstacle = {{0,0},{0,1}}; // 0

    int m = obstacle.size();
    int n = obstacle[0].size();
    dp.clear();
    dp.resize(m,vector<int>(n,-1));
    cout<<helper(0,0,m,n,obstacle);
    
}


// H.w Leetcode :1137 Nth Tribonacci Number
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    int n = 35; // 615693474;
    if(n==0)return 0;
    if(n<=2)return 1;

    // Using Bottom Up Approach
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<dp[n];
    
    return 0;
}

// H.W Leetcode 64 : minimumm path sum
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int solve(int strow,int stcol,int m,int n,vector<vector<int>>& grid){
    if(strow==m-1 && stcol==n-1)return grid[m-1][n-1];
    if(strow==m || stcol==n)return INT_MAX; // This line is very IMP. becoz if we take 0 then min(x,0)give 0 but if we take INT_MAX then it will give x which is real minimum.

    if(dp[strow][stcol]!=-1)return dp[strow][stcol];
    return dp[strow][stcol] = grid[strow][stcol] + min(solve(strow,stcol+1,m,n,grid),solve(strow+1,stcol,m,n,grid));
}
    
int main(){
    
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int m = grid.size();
    int n = grid[0].size();
    dp.resize(m,vector<int>(n,-1));
    cout<<solve(0,0,m,n,grid);
    
    return 0;
}