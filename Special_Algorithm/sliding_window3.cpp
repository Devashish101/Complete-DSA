// Leetcode 1004: Max Consequtive Ones ||| striver
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int n = nums.size();
        int k = 3; 
        int zeroes = 0;
        int len = 0;
        int maxLen = 0;
        int i=0,j=0;
        while(j<n){
            if(nums[j]==0) zeroes++;
            while(zeroes>k){ //  i ko 1st flipped/deleted 0 ke just aage le jao. 
                if(nums[i]==0){
                    zeroes--;
                    i++;
                }
                else{//nums[i]==1
                    i++;
                } 
            }
            if(zeroes<=k){
                len = j-i+1;
                maxLen = max(maxLen,len);
            }
            j++;
        }
        cout<<maxLen;
    
    return 0;
}

// Leetcode 1493: Longest Sub Array of 1's after deleting 1 element
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
        int n = nums.size();
        int i=0,j=0;
        int zeroes = 0;
        int k = 1;
        int len = 0;
        int maxLen = 0;
        while(j<n){
            if(nums[j]==0) zeroes++;
            while(zeroes>k){
                if(nums[i]==0){
                    zeroes--;
                    i++;
                }
                else{//nums[i]==1
                    i++;
                } 
            }
            if(zeroes<=k){
                len = j-i+1;
                maxLen = max(maxLen,len);
            }
            j++;
        }
        cout<<maxLen-1;
    
    return 0;
}