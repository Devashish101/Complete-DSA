// CSES Problem set
//TODO: Minm steps to make a no. zero by subtracting one of its digits from the no.
# include <bits/stdc++.h>
using namespace std;
vector<int> digits(int num){
    vector<int>results;
    while(num > 0){
        if(num % 10 != 0){
            results.push_back(num % 10);//push the last digit
        }
        num = num / 10;
    }
    return results;
}

// Recursive Solution.
int solve(int num){
    // Base case
    if(num==0)return 0;
    if(num<=9)return 1;

    vector<int>d = digits(num);
    int steps = INT_MAX;
    for(int i=0; i<d.size(); i++){
        steps = min(steps,solve(num-d[i]));
    }
    return 1 + steps;
}   

// Top Down Approach
vector<int>dp;
int memoization(int num){
    if(num==0)return 0;
    if(num<=9)return 1;

    if(dp[num]!=-1)return dp[num];
    
    vector<int>d = digits(num); //Find all digits of the num
    int steps = INT_MAX;
    for(int i=0; i<d.size(); i++){
        steps = min(steps,memoization(num-d[i]));
    }
    return dp[num] = 1 + steps;
}

int main(){
    
    int num = 27; //27-7 -> 20-2 -> 18-8 -> 10-1 -> 9-9 = 0 => 5 steps
    cout<<solve(num)<<endl;
    
    dp.resize(num+1,-1);
    cout<<memoization(num)<<endl;

    // Bottom up solution.
    dp[0] = 0;
    for(int i=1; i<=9; i++)dp[i] = 1;

    for(int j=10; j<=num; j++){
        vector<int>d = digits(j); //Find all digits of the num
        int steps = INT_MAX;
        for(int i=0; i<d.size(); i++){
            steps = min(steps,dp[j-d[i]]);
        }
        dp[j] = 1 + steps;
    }
    cout<<dp[num];

    return 0;
}

//TODO: Leetcode 322: Coin Change
# include <bits/stdc++.h>
using namespace std;

// Top Down Approach.
vector<int> dp;
// Returns the minimum number of coins needed to make 'amount'.
// Returns INT_MAX if it is impossible.
int solve(vector<int>& coins, int amount) {
    if (amount == 0) // If amount is 0 then it requires 0 coins.
        return 0;

    if (dp[amount] != -2) // If already computed, return stored answer.
        return dp[amount];

    int res = INT_MAX;  // Stores the minimum answer among all choices.
    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] > amount) continue;
        res = min(res, solve(coins, amount - coins[i]));
    }

    if (res == INT_MAX)return dp[amount] = INT_MAX;  // no valid coin combination was found.
    return dp[amount] = 1 + res;// Add 1 for the coin chosen at the current level.
}

int main(){
    
    vector<int> coins = {1,2,5}; 
    int amount = 11;
    dp.resize(amount + 1, -2);
    int ans = solve(coins, amount);
    if (ans == INT_MAX)
        cout<<"-1";
    else
        cout<<ans;
    
    return 0;
}

//TODO: CSES Dice Combination , also do the modulo of ans with 10^9 + 7.
# include <bits/stdc++.h>
# define mod 1000000007
# define ll long long
using namespace std;

ll solve(int n, vector<ll>& dp){
    if(n==0)return 1;// One valid soln. 

    if(dp[n]!=-1)return dp[n];
    ll ways = 0;
    for(int i=1; i<=6; i++){
        if(i > n)break;
        ways = (ways + solve(n-i, dp)) % mod;
    }
    return dp[n] = ways;
}
    
int main(){
    int n = 3; // 4 ways

    vector<ll>dp(n+1,-1);
    cout<<solve(n,dp)<<endl;
    
    // Bottom Up solution
    vector<ll>bdp(n+1);
    bdp[0] = 1;
    for(int k=1; k<=n; k++){
        ll ways = 0;
        for(int i=1; i<=6; i++){
            if(i > k)break;
            ways = (ways + bdp[k-i]) % mod;
        }
        bdp[k] = ways;
    }
    cout<<bdp[n];


    return 0;
}
