//  -------------------------------------------------------- Probability Based D.P -----------------------------------------------------------------
// TODO: I-Coins -> At coders educational D.P
// f(p,i,x) = f(p,i-1,x-1)*p[i] + f(p,i-1,x)*(1-p[i]). 
// where f(p,i,x) -> probability arr and probability of getting atleast x heads from coins 0 to i.
//       f(p,i-1,x-1) -> if by tossing the ith coin we get "head". p[i] -> probability of ith coin
//       f(p,i-1,x)   -> if by tossing the ith coin we get "Tail". 1-p[i] -> probability of tail

# include <bits/stdc++.h>
using namespace std;
    
vector<vector<double> >dp;
double f(vector<double> &p,int i,int x){
    if(x == 0)return 1;
    if(i == -1)return 0;
    if(dp[i][x] > -1) return dp[i][x]; // In case of decimal values we use > instead of != while comparing
    return dp[i][x] = f(p,i-1,x-1)*p[i] + f(p,i-1,x)*(1-p[i]);

}
int main(){
    int n = 3;
    vector<double> prob = {0.3,0.6,0.8}; // 0.612 ans
    dp.assign(3005,vector<double>(3005,-1));

    int x = (n+1) / 2; // At least x heads
    cout<<fixed<<setprecision(9)<<f(prob,n-1,x);
    
    return 0;
}

// FIXME: ------------------------------------------- 3-D D.P ----------------------------------------

// TODO: Leetcode 688. Knight Probability in Chessboard
# include <bits/stdc++.h>
using namespace std;

double dp1[30][30][105]; // 3D D.p

// 8 possible moves of a knight.
vector<int>dx = {-2,-2,-1,1,2,2,-1,1};
vector<int>dy = {-1,1,2,2,1,-1,-2,-2};

double f(int n, int k,int i,int j){
    if(i<0 || j<0 || i>=n || j>=n)return 0;
    if(k==0)return 1;
    if(dp1[i][j][k] > -1)return dp1[i][j][k];

    double ans = 0.0;
    // Try all 8 possible knight moves
    //  As Prob. of each move is 0.125.   
    ans += 0.125 * f(n, k-1, i+dx[0], j+dy[0]);
    ans += 0.125 * f(n, k-1, i+dx[1], j+dy[1]);
    ans += 0.125 * f(n, k-1, i+dx[2], j+dy[2]);
    ans += 0.125 * f(n, k-1, i+dx[3], j+dy[3]);
    ans += 0.125 * f(n, k-1, i+dx[4], j+dy[4]);
    ans += 0.125 * f(n, k-1, i+dx[5], j+dy[5]);
    ans += 0.125 * f(n, k-1, i+dx[6], j+dy[6]);
    ans += 0.125 * f(n, k-1, i+dx[7], j+dy[7]);

    return dp1[i][j][k] = ans;
}
    
int main(){
    int n = 3, k = 2, row = 0, column = 0;

    memset(dp1,-1,sizeof dp1);
    cout<<f(n,k,row,column);
    return 0;
}

// TODO: CodeForces Bad Luck Island 
# include <bits/stdc++.h>
# define ld long double
using namespace std;

ld dp2[105][105][105];

// Probability of survival of Rock
ld fr(int r,int s,int p){
    if(r == 0 || s == 0)return 0;
    if(p == 0)return 1;

    if(dp2[r][s][p] > -1)return dp2[r][s][p];
    ld total = r*s + s*p + p*r; // Total possibilities of fight combination.
    ld result = 0.0;
    result += fr(r,s-1,p)*((r*s)/total); // In case of fight b/w rock and Scissor
    result += fr(r-1,s,p)*((r*p)/total); // In case of fight b/w rock and paper
    result += fr(r,s,p-1)*((s*p)/total); // In case of fight b/w Scisssor and paper
    return dp2[r][s][p] = result;
}

// Probability of survival of Scissor
ld fs(int r,int s,int p){
    if(p == 0 || s == 0)return 0;
    if(r == 0)return 1;

    if(dp2[r][s][p] > -1)return dp2[r][s][p];
    ld total = r*s + s*p + p*r; // Total possibilities of fight combination.
    ld result = 0.0;
    result += fs(r,s-1,p)*((r*s)/total); // In case of fight b/w rock and Scissor
    result += fs(r-1,s,p)*((r*p)/total); // In case of fight b/w rock and paper
    result += fs(r,s,p-1)*((s*p)/total); // In case of fight b/w Scisssor and paper
    return dp2[r][s][p] = result;
}

// Probability of survival of Paper
ld fp(int r,int s,int p){
    if(r == 0 || p == 0)return 0;
    if(s == 0)return 1;

    if(dp2[r][s][p] > -1)return dp2[r][s][p];
    ld total = r*s + s*p + p*r; // Total possibilities of fight combination.
    ld result = 0.0;
    result += fp(r,s-1,p)*((r*s)/total); // In case of fight b/w rock and Scissor
    result += fp(r-1,s,p)*((r*p)/total); // In case of fight b/w rock and paper
    result += fp(r,s,p-1)*((s*p)/total); // In case of fight b/w Scisssor and paper
    return dp2[r][s][p] = result;
}
    
int main(){
    
    int rock = 2, scissor = 2, paper = 2;

    memset(dp2,-1,sizeof dp2);
    cout<<fixed<<setprecision(9)<<fr(rock,scissor,paper)<<endl;

    memset(dp2,-1,sizeof dp2);
    cout<<fixed<<setprecision(9)<<fs(rock,scissor,paper)<<endl;

    memset(dp2,-1,sizeof dp2);
    cout<<fixed<<setprecision(9)<<fp(rock,scissor,paper)<<endl;

    
    return 0;
}

// TODO: Mpilots - SPOJ. -> It can be Converted in 2D D.P, but here i have done it in a 3D D.P
# include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> Captain = {5000,6000,8000,9000};
vector<int> assist  = {3000,2000,1000,6000};

int n = 4;

ll dp3[105][105][105];

// cost of Pilot as a captain(Cc) and assistant(Ca).
ll calc(int i, int Ca, int Cc)
{
    if(i == n){
        if(Ca == Cc) return 0;
        return LLONG_MAX;
    }

    if(dp3[i][Ca][Cc] != -1)
        return dp3[i][Ca][Cc];

    // Must take assistant
    if(Ca - Cc == 0){
        return dp3[i][Ca][Cc] =
            assist[i] + calc(i + 1, Ca + 1, Cc);
    }

    // Must take captain
    else if(Ca - Cc == n - i){
        return dp3[i][Ca][Cc] =
            Captain[i] + calc(i + 1, Ca, Cc + 1);
    }

    // Both choices possible
    else{
        return dp3[i][Ca][Cc] = min(
            assist[i] + calc(i + 1, Ca + 1, Cc),
            Captain[i] + calc(i + 1, Ca, Cc + 1)
        );
    }
}

int main()
{
    memset(dp3, -1, sizeof(dp3));
    cout << assist[0] + calc(1, 1, 0); // 19000

    return 0;
}