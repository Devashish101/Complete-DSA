//TODO: 1155. Number of Dice Rolls With Target Sum V.IMP
# include <bits/stdc++.h>
# define mod 1000000007
using namespace std;
vector<vector<int>>dp;
int solve(int n,int k,int t){
    if(n==0 && t==0)return 1;
    if(n==0)return 0;

    if(dp[n][t]!=-1)return dp[n][t];
    int ways = 0;
    for(int i=1; i<=k; i++){
        if(i>t)continue;
        ways = (ways + solve(n-1,k,t-i)) % mod;
    }
    return dp[n][t] = ways;
}
    
int main(){
    
    // int n = 2, k = 6, t = 7;
    int n = 30, k = 30, t = 500;
    dp.resize(n+1,vector<int>(t+1,-1));
    cout<<solve(n,k,t);
    
    return 0;
}


//TODO: MCOINS - Coins Game
// Asen and Boyan are playing a game, They choose two different positive integers K and L, and start the game with a tower of N coins.Asen always plays first, followed by Boyan,and so on in alternating turns.In a single turn, a player can remove exactly (1),(K),or(L)coins from the tower.The player who takes the very last coin (or coins) wins the game.The first line contains three integers: (K),(L),and (m) ((1 < K < L < 10) and (3 < m < 50)).The output must be a single string of length (m) composed of the letters A and B,A if Asen wins the (i)th game.B if Boyan wins the (i)th game.
#include <bits/stdc++.h>
using namespace std;

// FIXME: Top-Down (Memoization)
vector<int> tdp;

int solve1(int n, int k, int l) {

    // Base cases: winning and losing states
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == k || n == l) return 1;

    // Return already computed state
    if (tdp[n] != -1) return tdp[n];

    // Current state is winning if any move leads to a losing state
    tdp[n] = !(solve1(n - 1, k, l) &&
               ((n - k >= 0) ? solve1(n - k, k, l) : 1) &&
               ((n - l >= 0) ? solve1(n - l, k, l) : 1));

    return tdp[n];
}

// FIXME: Bottom-Up (Tabulation)
vector<int> solve(int K, int L) {

    // dp[i] = 1 => current player wins with i coins
    // dp[i] = 0 => current player loses with i coins
    vector<int> dp(1000005, 0); // Max N = 10^6

    // Direct winning states
    dp[1] = 1;
    dp[K] = 1;
    dp[L] = 1;

    // Precompute all game states once
    for (int i = 2; i <= 1000000; i++) {

        if (i == K || i == L) continue;

        // State is winning if at least one move reaches a losing state
        dp[i] = !(dp[i - 1] &&
                  ((i - K >= 0) ? dp[i - K] : 1) &&
                  ((i - L >= 0) ? dp[i - L] : 1));
    }

    return dp;
}

int main() {

    int K, L, M;
    cin >> K >> L >> M;

    // ---------- Top-Down ----------
    /*
    for(int i = 1; i <= M; i++) {
        int N;
        cin >> N;

        tdp.assign(N + 1, -1);

        int win = solve1(N, K, L);
        cout << (win ? 'A' : 'B');
    }
    */

    // ---------- Bottom-Up ----------
    vector<int> dp = solve(K, L);

    // Answer each game in O(1)
    for (int i = 1; i <= M; i++) {
        int n;
        cin >> n;

        cout << (dp[n] ? 'A' : 'B');
    }

    return 0;
}

//TODO: C- Vacation
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    // Bottom up Approach

    //Problem statement
    // 3 -> No of vacation days
    // 10 40 70 -> happiness point of each activity a, b, c on 0th day
    // 20 50 80 -> happiness point of each activity a, b, c on 1th day
    // 30 60 90 -> happiness point of each activity a, b, c on n-1th day
    // we can't choose the same activity for 2 consecutive days

    // Approach
    // f(i,act) = max { 
    //         a + max(f(n-1,b),f(n-1,c)), // if we choose act a
    //         b + max(f(n-1,a),f(n-1,c)), // if we choose act b
    //         c + max(f(n-1,a),f(n-1,b)), // if we choose act c
    // }

    
    int n;
    cin>>n;
    vector<vector<int>> dp(n, vector<int> (3,0));

    // Base case
    int a, b, c;
    cin>>a>>b>>c;
    dp[0][0] = a;
    dp[0][1] = b;   
    dp[0][2] = c;

    // if you do activity A on day i, then on day i-1 you must have done either B or C.
    for(int i=1; i<n; i++){
        // input of happiness for ith day
        cin>>a>>b>>c;

        // ith day -> a
        dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
        // ith day -> b
        dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
        // ith day -> c
        dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);

    }
    cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    return 0;
}