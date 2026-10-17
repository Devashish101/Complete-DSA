// Leetcode Minimum Penalty
# include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "YNYY";
    int n = str.length();

    // Finding the Penality due to N before Kth hour(Exclusive)
    vector<int> pre (n+1);
    int pen=0;
    pre[0] = 0;
    for(int i=0; i<n; i++){
        if(str[i]=='N'){
            pen += 1;
        }
        pre[i+1] = pen;
    }


    // Finding the Penality due to Y till kth hour(inclusive)
    vector<int> suff (n+1);
    pen=0;
    suff[n] = 0;
    for(int i=n-1; i>=0; i--){
        if(str[i]=='Y'){
            pen += 1;
        }
        suff[i] = pen;  
    }

    int min = INT_MAX;
    for(int i=0; i<=n; i++){
        pre[i] = pre[i]+suff[i];
        if(pre[i]<min)  min = pre[i];
    }

    for(int i=0; i<=n; i++){
        if(pre[i]==min){
            cout<<i;
            break;
        }
    }

}