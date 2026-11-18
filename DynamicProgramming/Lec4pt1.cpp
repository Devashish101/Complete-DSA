//TODO: Roy and Coin Boxes -> HackerEarth
# include <bits/stdc++.h>
using namespace std;
// Input = n=7, m=4, m val of L,R = (1,3),(2,5),(1,2),(5,6) , query =  4, q1,q2,q3,q4 = 1,7,4,2 
// output = 6 0 0 4. -> Ans of query
int main(){
    
    int n;
    cin>>n;
    int m;
    cin>>m;
    
//FIXME: Approach 1
    // vector<int> f(n+1,0);

    // vector<int> l(n+1,0);
    // vector<int> r(n+1,0);
    // for(int i=0; i<m; i++){
    //     int L,R;
    //     cin>>L>>R;
    //     l[L]++;
    //     r[R]++;
    // }

    // f[1] = l[1];
    // for(int i=2; i<=n; i++){
    //     f[i] = l[i] - r[i-1] + f[i-1];
    // }

    // vector<int> c(10000005,0);
    // for(int i=0; i<=n; i++){
    //     int coins = f[i];
    //     c[coins]++;
    // }

    // for(int i=c.size()-2; i>=0;  i--){ // suffix sum
    //     c[i] = c[i] + c[i+1];
    // }

    // int q;
    // cin>>q;
    // while(q--){
    //     int num;
    //     cin>>num;
    //     cout<<c[num]<<"\n";
    // }

//FIXME: Approach 2 
    vector<int> f1(n+1,0);
    for(int i=0; i<m; i++){
        int L,R;
        cin>>L>>R;
        f1[L]++;
        f1[R+1]--;
    }
    for(int i=1; i<f1.size(); i++){ // Prefix Sum
        f1[i] = f1[i] + f1[i-1];
    }
    vector<int> c1(10000005,0);
    for(int i=0; i<=n; i++){
        int coins = f1[i];
        c1[coins]++;
    }

    for(int i=c1.size()-2; i>=0;  i--){ // suffix sum
        c1[i] = c1[i] + c1[i+1];
    }

    int q1;
    cin>>q1;
    while(q1--){
        int num;
        cin>>num;
        cout<<c1[num]<<"\n";
    }

    
    return 0;
}


//TODO: Matrix Chain Multiplication -> GFG
# include <bits/stdc++.h>
using namespace std;

// Top Down Solun
vector<vector<int> >dp;
int solve(int i,int j,vector<int>&arr){
    if(i==j || i+1==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = INT_MAX;
    for(int k=i+1; k<j; k++){
        ans = min(ans, solve(i,k,arr)+solve(k,j,arr)+arr[i]*arr[k]*arr[j]);
    }
    return dp[i][j] = ans;
}
    
int main(){
    // Input - n = 5 , 40 20 30 10 30
    // Output 26000
    int n;
    cin>>n;

    vector<int>v(n); // It contains the dimensions of n-1 matrix starting from 0 to n-1.
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    dp.clear();
    dp.resize(1001, vector<int>(1001,-1));
    cout<<solve(0,n-1,v)<<"\n";

    // Bottom Up solun
    vector<vector<int> >bdp(1001, vector<int>(1001,0));
    for(int len=3; len<=n; len++){ // As for len <=2 cost = 0( As single matrix has no multiplication cost).
        for(int i=0; i+len-1<n; i++){
            int j=i+len-1;
            bdp[i][j] = INT_MAX;
            for(int k=i+1; k<j; k++){
                bdp[i][j] = min(bdp[i][j], bdp[i][k] + bdp[k][j] + v[i]*v[k]*v[j]);
            }
        }
    }
    cout<<bdp[0][n-1];
    return 0;
}