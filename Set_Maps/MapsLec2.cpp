//Leetcode 1814: Count Nice pair in an Array
# include <bits/stdc++.h>
using namespace std;
    
int rev(int n){
    int r = 0;
    while(n>0){
        r = r*10;
        r += (n%10);
        n /= 10;
    }
    return r;
}

int main(){
    
    vector<int>nums = {13,10,35,24,76};
    int n = nums.size();
    int count = 0;

    unordered_map<int ,int> m;
    for(int i=0; i<n; i++){
        int reverse = rev(nums[i]);
        int diff = reverse-nums[i];
        if(m.find(diff)!= m.end()){
            count += m[diff];
            m[diff]++;
        }
        else{
            m[diff]++;
        }

    }
    
    cout<<count<<endl;

    return 0;
}