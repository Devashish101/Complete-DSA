// Leetcode 1402: Reducing Dishes
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int> satisfaction = {-1,-8,0,5,-9};
    int n = satisfaction.size();

    sort(satisfaction.begin(),satisfaction.end()); //-9,-8,-1,0,5 => -13,-4,4,5,5

    vector<int>suff(n);
    suff[n-1] = satisfaction[n-1];
    for(int i=n-2; i>=0; i--){
        suff[i]  = (suff[i+1] + satisfaction[i]);
    }

    // Finding the correct idx
    int idx = -1;
    for(int i=0; i<n; i++){
        if(suff[i]>=0){
            idx = i;
            break;
        }
    }
    if(idx == -1) return 0;

    // Max sum of like-time Coefficient
    int x = 1;
    int Maxsum = 0;
    for(int i=idx; i<n; i++){
        Maxsum += (satisfaction[i]*x);
        x++;
    }

    cout<<Maxsum;
    return 0;
}