//------------------ ----------- D.P part 1 from youtube By Raghav sir ---------------------------

//TODO: Friends Pairing Problem gfg
# include <bits/stdc++.h>
using namespace std;

int posspair(vector<int> &dp, int n){
    if(n<=2)return n; // since for n = 1 or 2 only 1 or 2 combination are possible

    // If value is already computed
    if(dp[n]!=-1)return dp[n]; 

    // In case of new value
    return dp[n] = posspair(dp,n-1)+(n-1)*posspair(dp,n-2); 
}
    
int main(){
    
    int n;
    cin>>n;

    vector<int>dp(n+1,-1);
    cout<<posspair(dp,n);
    
    return 0;
}

// TODO: Count Derangements - gfg
# include <bits/stdc++.h>
using namespace std;

int dearg(int n,vector<int> &dp){
    if(n<=3)return n-1;
    
    if(dp[n] != -1)return dp[n];
    return dp[n] = (n-1)*(dearg(n-2,dp) + dearg(n-1,dp));
}
    
int main(){
    int n;
    cin>>n;
    
    vector<int>dp(n+1,-1);
    cout<< dearg(n,dp);
    
    return 0;
}

//TODO: Leetcode:1277 -> Count Square Submatrices with All Ones
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
        vector<vector<int>> matrix = { {0,1,1,1},
                                       {1,1,1,1},
                                       {0,1,1,1}
                                                 };
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp(m, vector<int>(n, 0));
        int ans = 0;
        // Filling the first column of DP matrix
        // Each cell in first column can only form a 1x1 square if matrix[i][0] = 1
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];
        }

        // Filling the first row of DP matrix
        // Each cell in first row can only form a 1x1 square if matrix[i][0] = 1
        for (int i = 1; i < n; i++) {
            dp[0][i] = matrix[0][i];
            ans += dp[0][i];
        }

        // Now filling the remaining the cells of the dp matrix
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min ({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                ans += dp[i][j];
            }
        }

        cout<<ans;
    
    return 0;
}

//TODO: 0/1 Knapsack  and unbounded knapsack-> hackerrank => G.Q
# include <bits/stdc++.h> 
using namespace std;

// Recursive Solution -> T.C = O(2^n).
int maxProfit(int idx, vector<int> &val, vector<int> &wt, int C){
    if(idx==wt.size())return 0;

    int skip = maxProfit(idx+1,val,wt,C);
    if(wt[idx]>C)return skip;
    int take = val[idx] + maxProfit(idx+1,val,wt,C-wt[idx]);
    
    return max(skip,take);
}

// Recursive + Memoization  T.C = 0(n*C)
vector<vector<int> >dp;
int maxProfit1(int idx, vector<int> &val, vector<int> &wt, int C){
    if(idx==wt.size())return 0;
    if(dp[idx][C] != -1)return dp[idx][C];

    int skip = maxProfit1(idx+1,val,wt,C);
    if(wt[idx]>C)return dp[idx][C] = skip;
    int take = val[idx] + maxProfit1(idx+1,val,wt,C-wt[idx]); // This is for 0/1 knapsack
    // int take = val[idx] + maxProfit1(idx,val,wt,C-wt[idx]);  // This is for unbounded knapsack

    return dp[idx][C] = max(skip,take);
}
    
int main(){

    vector<int>val = {5,3,9,16};
    vector<int>wt = {1,2,8,10};
    int C = 11; // Capacity
    cout<<maxProfit(0,val,wt,C)<<endl;

    int n = val.size();
    dp.assign(n,vector<int>(C+1,-1));
    cout<<maxProfit1(0,val,wt,C);
    
    return 0;
}

//TODO:Leetcode 416. Partition Equal Subset Sum similar to below 
//TODO: Subset Sum Problem -> gfg => Good .Q  done below 1st do this then move to above
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
bool istrue(int idx,vector<int> &arr, int sum){
    if(idx==arr.size()){
        if(sum==0)return dp[idx][sum] = true;
        else return dp[idx][sum] = false;
    }
    if(dp[idx][sum]!=-1)return dp[idx][sum];

    bool skip = istrue(idx+1,arr,sum); 
    if(sum-arr[idx]<0)return dp[idx][sum] = skip;

    bool pick = istrue(idx+1,arr,sum-arr[idx]);
    return dp[idx][sum] = (pick || skip);
}
    
int main(){
    
    vector<int>arr = {3, 34, 4, 12, 5, 2};
    int sum = 19;
    dp.resize(arr.size() + 1, vector<int>(sum + 1, -1));
    cout<<istrue(0,arr,sum);

    return 0;
}

//TODO: Leetcode 494. Target Sum
# include <bits/stdc++.h>
using namespace std;

int sum = 0;
vector<vector<int>>dp;
int solve(int idx,int res,vector<int> &nums,int tar){
    if(idx==nums.size()){
        if(res==tar)return 1; // 1 valid ans.
        else return 0; // Not a valid ans.
    }

    if(dp[idx][res+sum] != -1)return dp[idx][res+sum];
    int add = solve(idx+1, res+nums[idx], nums, tar);
    int sub = solve(idx+1, res-nums[idx], nums, tar);

    return dp[idx][res+sum] = add+sub;
}
    
int main(){
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    int n = nums.size();
    for(auto ele:nums)sum += ele;

    // i -> 0 to n-1 and res -> -sum to sum = (2*sum+1).
    dp.assign(n+1,vector<int>(2*sum+1,-1));
    cout<< solve(0,0,nums,target);
    
    return 0;
}

// 2786 h.w

