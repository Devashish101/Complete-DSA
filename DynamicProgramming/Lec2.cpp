//TODO: Leetcode 198: House Robber
# include <bits/stdc++.h>
using namespace std;

// Recursive solution
int helper1(vector<int>&nums,int idx){
    int n = nums.size();
    if(idx==n-1)return nums[idx];
    if(idx==n-2)return max(nums[idx],nums[idx+1]);
    
    // if we rob the current house then move to idx+2th house with loot of curr house, otherwise move to idx+1th house with 0 loot money of curr house.
    return max(nums[idx]+helper1(nums,idx+2),0+helper1(nums,idx+1));
}

// Top Down approach Memoization
int helper(vector<int>&nums,int idx,vector<int>&dp){
    int n = nums.size();
    if(idx==n-1)return nums[idx];
    if(idx==n-2)return max(nums[idx],nums[idx+1]);
    
    if(dp[idx]!=-1)return dp[idx];
    return dp[idx] = max(nums[idx] + helper(nums,idx+2,dp), 0 + helper(nums,idx+1,dp));
}
    
int main(){
    vector<int>nums = {2,7,9,3,1};
    int n = nums.size();
    cout<<helper1(nums,0)<<endl;

    vector<int>dp(n+1,-1);
    cout<<helper(nums,0,dp)<<endl;
    
    // Bottom up Approach
    vector<int>dp1(n+1, 0);
    dp1[0] = nums[0];
    dp1[1] = max(nums[0],nums[1]);
    
    for(int i=2; i<n; i++){
        dp1[i] = max((nums[i]+dp1[i-2]),dp1[i-1]);
    }
    cout<<dp1[n-1];
    
    return 0;
}


//TODO: Min Steps to one -> Coding ninja
#include <bits/stdc++.h>
# define Infy INT_MAX
using namespace std;

// Recursive Solution.
int helper(int num) {
    // Base case
    if (num == 1) return 0;

    // Here it is finding the min of n-1 to 1, n/2 to 1 and n/3 to 1.
    // But to reach to n-1 or n/2 or n/3 from n we also need 1 step 
    // that's why add +1 in min of these 3 possiblities.
    return 1 + min({
        helper(num - 1),
        (num % 2 == 0 ? helper(num / 2) : Infy),
        (num % 3 == 0 ? helper(num / 3) : Infy)
    });
}

// Memoization - Top Down Approach
int helper1(int num,vector<int>&dp) {
    // Base case
    if (num == 1) return 0;

    if(dp[num]!=-1)return dp[num]; //nth state is precomputed
    return dp[num] = 1 + min({ //here we need to compute the nth state for the 1st time.
        helper1(num - 1,dp),
        (num % 2 == 0 ? helper1(num / 2,dp) : Infy),
        (num % 3 == 0 ? helper1(num / 3,dp) : Infy)
    });
}
 

int main() {

    int num = 101;
    cout << helper(num)<<endl;

    vector<int>dp(num+1,-1);
    cout << helper1(num,dp)<<endl;

    // Tabulation - Bottom up D.P
    vector<int>dp1(num+1,-1);
    dp1[1] = 0;
    dp1[2] = dp1[3] = 1;
    for(int i=4; i<=num; i++){
        dp1[i] = 1 + min({ 
        dp1[i - 1],   
        (i % 2 == 0 ? (dp1[i / 2]) : Infy),
        (i % 3 == 0 ? (dp1[i / 3]) : Infy)
      });
    }
    cout<<dp1[num];
    return 0;
}