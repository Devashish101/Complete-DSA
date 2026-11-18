// TODO: MIXTURES - SPOJ
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> dp;

// Returns color obtained after mixing colors[i...j]
ll g(vector<int>& colors, int i, int j) {
    ll sum = 0;

    for(int k = i; k <= j; k++) {
        sum += colors[k];
    }

    return sum % 100;
}

ll f(vector<int>& colors, int i, int j) {

    // Single mixture produces no smoke
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    ll ans = LLONG_MAX;

    // Try every partition point
    for(int k = i; k < j; k++) {

        ll leftSmoke = f(colors, i, k);
        ll rightSmoke = f(colors, k + 1, j);

        ll currSmoke =
            leftSmoke +
            rightSmoke +
            g(colors, i, k) * g(colors, k + 1, j);

        ans = min(ans, currSmoke);
    }

    return dp[i][j] = ans;
}

int main() {

    vector<int> colors = {40, 60, 20};
    int n = colors.size();

    dp.assign(n, vector<ll>(n, -1));

    cout << f(colors, 0, n - 1);

    return 0;
}

//TODO: Leetcode 96. Unique Binary Search Trees
# include <bits/stdc++.h>
using namespace std;

vector<int>dp2;
// Solving Using Memoization (Top Down Dp)
int solve(int n){
    if(n==0 or n==1)return 1;
    if(n==2)return 2;

    if(dp2[n]!=0)return dp2[n];
    int sum = 0;
    for(int i=1; i<=n; i++){ // All i's are root node from 1 to n.
        sum += solve(i-1)*solve(n-i);
    }
    return dp2[n] = sum;
}

// Solving Using Tabulation (Bottom Up Dp)
int solveTab(int n){
    dp2[0] = dp2[1] = 1;
    for(int i=2; i<=n; i++){ // i-> represent no. of nodes from 2 to n.
        for(int j=1; j<=i; j++){ // j-> represent root nodes
            dp2[i] += dp2[j-1]*dp2[i-j];
        }
    }
    return dp2[n];
}

// Solving Using Catalyn Number.
int solveCat(int n){ 
    long long ans = 1;
    for(int i = 0; i < n; i++){
        ans = ans * (2*n - i) / (i + 1);
    }
    return ans / (n + 1);
}
    
int main(){
    
    int n = 9;
    dp2.assign(n+1,0);
    cout<<solve(n)<<"\n";

    dp2.assign(n+1,0);
    cout<<solveTab(n)<<"\n";

    cout<<solveCat(n)<<"\n";

    return 0;
}


//TODO: L-Deque -> Atcoders
# include <bits/stdc++.h>
# define ll long long int
using namespace std;

vector<vector<ll>>dp1;
ll solve(vector<ll> &arr,int i,int j){
    if(i==j)return arr[i];

    if(dp1[i][j]!=-1)return dp1[i][j];
    return dp1[i][j] = max(arr[i]-solve(arr,i+1,j),arr[j]-solve(arr,i,j-1));
}

int solvebu(vector<ll> &arr){
    int n = arr.size();
    dp1.clear();
    dp1.resize(n+1,vector<ll>(n+1,0));

    for(int i=0; i<n; i++){
        dp1[i][i] = arr[i];
    }

    for(int len = 2; len <= n; len++){
        for(int i=0; i+len-1<n; i++){
            int j = i+len-1;
            dp1[i][j] = max(arr[i] - dp1[i+1][j], arr[j] - dp1[i][j-1]);
        }
    }
    return dp1[0][n-1];
}

int main(){
    
    int n; // 6
    cin>>n;

    vector<ll>arr; // 4 2 9 7 1 5
    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        arr.push_back(x);
    }

    dp1.clear();
    dp1.resize(n+1,vector<ll>(n+1,-1));
    cout<<solve(arr,0,n-1); // 2
    
    return 0;
}