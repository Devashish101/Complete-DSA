// -------------------------------------------- D.P part 2 from youtube by raghav Sir ----------------------------------------
// TODO: Leetcode 1143 : Longest Common Subsequence, TODO:Leetcode 516 :Longest Palindromic Subsequence.
# include <bits/stdc++.h>
using namespace std;

// Using Recursion + Memoization.
vector<vector<int> >dp;
int lcs(int i, int j, string &a, string &b){
    if(i<0 || j<0)return 0;

    if(dp[i][j] != -1)return dp[i][j]; 
    if(a[i]==b[j]){ // shift both idx 1 step left
        return dp[i][j] = 1 + lcs(i-1,j-1,a,b);
    }
    else{
        // Here keep 1 idx at same position and move other idx 1 step left.
        // Do this for both strings.
        return dp[i][j] = max(lcs(i-1,j,a,b), lcs(i,j-1,a,b));
    }
}
        

int main(){
    
    string a = "abcde", b = "ace" ;
    int m = a.length(), n = b.length();
    dp.assign(m+1,vector<int>(n+1,-1));
    cout<<lcs(m-1,n-1,a,b)<<endl;

    // Using Tabulation + printing the ans string
    dp.assign(m+1,vector<int>(n+1,0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==b[j-1]){ // shift both idx 1 step left
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[m][n];

    string str = "";
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(a[i-1]==b[j-1]){
            str+=a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(str.begin(),str.end());
    cout<<str;

    // Using Tabulation + Space Optimization.
    dp.assign(2,vector<int>(n+1,0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==b[j-1]){ // shift both idx 1 step left
                dp[1][j] = 1 + dp[0][j-1];
            }
            else{
                dp[1][j] = max(dp[0][j], dp[1][j-1]);
            }
        }
        // Copy the 1st row to 0th row for next iteration.
        for(int k=0; k<=n; k++) dp[0][k] = dp[1][k];
        
    }
    cout<<max(dp[0][n],dp[1][n]);
    return 0;
}

// TODO:Leetcode 1312. Minimum Insertion Steps to Make a String Palindrome (same as LCS). 
// Approach 1 - s.length()-LPS(516).
// Approach 2 - My Approach
# include <bits/stdc++.h>
using namespace std;

vector<vector<int> >dp;
int minSteps(int i, int j, string &s){
    if(i>=j)return 0;
    if(dp[i][j] != -1)return dp[i][j];

    if(s[i]==s[j])return dp[i][j] = minSteps(i+1,j-1,s);
    else return dp[i][j] = 1+min(minSteps(i+1,j,s),minSteps(i,j-1,s));
}
    
int main(){
    string s = "mbadm";
    int n = s.length();
    dp.assign(n+1,vector<int>(n+1,-1));
    cout<<minSteps(0,n-1,s);
    
    return 0;
}

// TODO: Leetcode 72 -> Edit Distance
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int minSteps(int i, int j,string a, string b){
    // Base Case
    if(i<0)return j+1;
    if(j<0)return i+1;

    if(dp[i][j] != -1)return dp[i][j];
    if(a[i]==b[j])return dp[i][j] = minSteps(i-1,j-1,a,b);
    else{
        int ins = minSteps(i,j-1,a,b);
        int del = minSteps(i-1,j,a,b);
        int rep = minSteps(i-1,j-1,a,b);
        return dp[i][j] = 1 + min({ins,del,rep});
    }
}
    
int main(){
    string word1 = "horse", word2 = "ros";
    int m = word1.length();
    int n = word2.length();
    dp.assign(m+1,vector<int>(n+1,-1));
    return minSteps(m-1,n-1,word1,word2);
    
    return 0;
}

// TODO:Leetcode 1092. Shortest Common Supersequence 
// -> Step1 calculate the LCS string and length of both string
// -> Step2 If we have asked to find the length then do (len s1 - lcs) + (len s2 - lcs) + lcs.
// -> Step3 For generating the final SCS string use 3 pointers (i,j and k) and take 1 empty str.

// TODO: Leetcode 647. Palindromic Substrings -> Good Question
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    string s = "aaa";
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int count = 0;

    // Process substrings by increasing length (diagonal traversal)
    for(int k = 0; k < n; k++) {
        int i = 0, j = k;

        while(j < n) {

            // Length 1: every single character is a palindrome
            if(i == j) {
                dp[i][j] = 1;
                count++;
            }

            // Length 2: palindrome if both characters are equal
            else if(j == i + 1) {
                if(s[i] == s[j]) {
                    dp[i][j] = 1;
                    count++;
                }
            }

            // Length >= 3:
            // Ends must match and inner substring must be a palindrome
            else {
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    count++;
                }
            }

            i++;
            j++;
        }
    }
    cout<<count;
    return 0;
}

//TODO: Leetcode 300. Longest Increasing Subsequence
# include <bits/stdc++.h>
using namespace std;
    
int main(){

    vector<int> nums = {10,9,2,5,3,7,101,18};
    int n = nums.size();
    vector<int>dp(n+1,0);
    // dp[i] = length of the LIS ending at index i starting from 0th ele.
    dp[0] = 1; // As for 1st ele len will be 1.
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[j] < nums[i]) dp[i] = max(dp[i],dp[j]);
        }
        dp[i] += 1;
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans;
    
    return 0;
}

//TODO: Leetcode 1671 : Minimum Number of Removals to Make Mountain Array
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int>nums = {2,1,1,5,6,2,3,1}; // 3
    int n = nums.size();
    // Filling the Dp in normal LIS Order.
    vector<int>dp(n+1,0);
    dp[0] = 1; 
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[j] < nums[i]) dp[i] = max(dp[i],dp[j]);
        }
        dp[i] += 1;
    }
    // Filling the another Dp in Reverse LIS Order.
    vector<int>dp1(n+1,0);
    dp1[n-1] = 1; 
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(nums[j] < nums[i]) dp1[i] = max(dp1[i],dp1[j]);
        }
        dp1[i] += 1;
    }
    // Combining the LIS and Reverse LIS to find the peak ele
    // Subtract 1 because the peak element is counted in both.
    // 1st, last and ele of len 2 can't be peak ele 
    // Since it must be an increasing sequence ending at i & decreasing sequence starting from i
    int maxLen = 0;
    for(int i=0; i<n; i++){
        if(dp[i] > 1 && dp1[i] > 1){
            int len = dp[i] + dp1[i] - 1;
            maxLen = max(maxLen,len);
        }
    }
    if(maxLen < 3) return 0;
    return n-maxLen;
    
    return 0;
}


// TODO:Leetcode 1547. Minimum Cost to Cut a Stick
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

// Returns minimum cost to perform all cuts between indices i and j (inclusive).
int cost(int i, int j, vector<int>& arr) {

    // No cuts left to perform.
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    // Try making every cut k as the first cut.
    for (int k = i; k <= j; k++) {

        // Length of the current stick segment.
        // arr[i-1] and arr[j+1] are the boundaries.
        int len = arr[j + 1] - arr[i - 1];

        int totalCost =
            cost(i, k - 1, arr) +   // Left segment
            cost(k + 1, j, arr) +   // Right segment
            len;                    // Cost of current cut

        mini = min(mini, totalCost);
    }
    return dp[i][j] = mini;
}
    
int main(){
    
    vector<int> cuts = {1,3,4,5};
    int n = 7;
    // Add stick boundaries.
    vector<int> arr(cuts.size() + 2);
    int m = arr.size();

    // Copy cuts.
    for (int i = 0; i < cuts.size(); i++) {
        arr[i] = cuts[i];
    }

    arr[m - 2] = 0; // Left boundary
    arr[m - 1] = n; // Right boundary

    sort(arr.begin(), arr.end());

    // dp[i][j] stores minimum cost for cuts in range [i, j]
    dp.assign(m, vector<int>(m, -1));
    cout<<cost(1, m - 2, arr);
    
    return 0;
}

//TODO: Leetcode 96. Unique Binary Search Trees
# include <bits/stdc++.h>
using namespace std;

vector<int>dp3;

// Solving Using Memoization (Top Down Dp)
int solve(int n){
    if(n==0 or n==1)return 1;
    if(n==2)return 2;

    if(dp3[n]!=0)return dp3[n];
    int sum = 0;
    for(int i=1; i<=n; i++){ // All i's are root node from 1 to n.
        sum += solve(i-1)*solve(n-i);
    }
    return dp3[n] = sum;
}

// Solving Using Tabulation (Bottom Up Dp)
int solveTab(int n){
    dp3[0] = dp3[1] = 1;
    for(int i=2; i<=n; i++){ // i-> represent no. of nodes from 2 to n.
        for(int j=1; j<=i; j++){ // j-> represent root nodes
            dp3[i] += dp3[j-1]*dp3[i-j];
        }
    }
    return dp3[n];
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
    dp3.assign(n+1,0);
    cout<<solve(n)<<"\n";

    dp3.assign(n+1,0);
    cout<<solveTab(n)<<"\n";

    cout<<solveCat(n)<<"\n";

    return 0;
}

// Diameter of a Binary Tree
// Binary Tree Maximum Path Sum.
// FIXME: Leetcode 354 Russian Doll Envelopes H.W.