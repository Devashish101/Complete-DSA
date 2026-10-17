// Leetcode 1480 :Prefix Sum or Running sum of a 2D Array
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    int arr[] = {1,4,5,3,2,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // M-1 (With using Extra Space)
    vector<int>vec;
    for(int i=0; i<n; i++){
        if(i==0) vec.push_back(arr[i]);
        else vec.push_back(arr[i]+vec[i-1]);
    }
    
    // M-2 (more Optimized Without using Extra Space)
    for(int i=1; i<n; i++){
        arr[i]+=arr[i-1];
    }

    // printing the Array after prefix sum
    for(int ele: arr){
        cout<<ele<<" ";
    }
    
    return 0;
}