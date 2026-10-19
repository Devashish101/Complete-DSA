//leetcode :2389 Longest Sub Sequence with Limited Sum
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int> nums = {4,5,2,1}; 
    vector<int> queries = {3,10,21};

    int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);

        // Sort the Nums
        sort(nums.begin(),nums.end());

        // making the nums prefix sum
        for(int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }

        // Finding the ans elements
        for(int i=0; i<m; i++){
            int len = 0;
            for(int j=0; j<n; j++){
                if(nums[j] > queries[i]) break;
                else len++;
            }
            ans[i] = len;
        }

        // printing the ans
        for(int ele:ans){
            cout<<ele<<" ";
        }
    
    return 0;
}