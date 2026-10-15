// Leetcode 1052: Grumpy Bookstore Owner
# include <bits/stdc++.h>
using namespace std;
   
int main(){
        vector<int> customers = {1,0,1,2,1,1,7,5};
        vector<int> grumpy = {0,1,0,1,0,1,0,1};
        int  minutes = 3;
        int n = customers.size();
        int prevloss = 0;
        for(int i=0; i<minutes; i++){
            if(grumpy[i]==1) prevloss += customers[i];
        }
      //   Sliding Window
        int maxloss = prevloss;
        int maxidx = 0;
        int i=1,j=minutes;
        while(j<n){
            int currloss = prevloss;
            if(grumpy[j]==1) currloss += customers[j];
            if(grumpy[i-1]==1) currloss -= customers[i-1];
            if(maxloss<currloss){
                maxloss = currloss;
                maxidx = i;
            }
            prevloss = currloss;
            i++;
            j++;
        }
      //   Filling 0's in the grumpy Array
        for(int i=maxidx; i<maxidx+minutes; i++){
            grumpy[i]=0;
        }
      //   Finding the maximum satisfaction
        int sum = 0;
        for(int i=0; i<n; i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        cout<<sum;
   
   return 0;
}

// Printing the First Negative NUmber of Each Window of the given Array
# include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2,-3,4,-5,-7,8,4,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int fstnegtve;
    vector<int>ans;
    for(int i=0; i<k; i++){
        if(arr[i]<0){
            ans.push_back(arr[i]);
            fstnegtve = i;
            break;
        }
    }

    // Sliding Window
    int i=1,j=k;
    while(j<n){
        if(fstnegtve >= i) ans.push_back(arr[fstnegtve]);
        else { 
            fstnegtve = -1;
            for(int x=i; x<=j; x++){
                if(arr[x]<0){
                    fstnegtve = x;
                    break;
                }
            }
            if(fstnegtve != -1) ans.push_back(arr[fstnegtve]);
            else ans.push_back(1); // it denotes no -ve no. is present in that window.
        }
        i++;
        j++;
    }
    
    // Printing the final ans array
    for(int ele: ans){
        cout<<ele<<" ";
    }
}

// Leetcode 209 : Minimum Size Sub Array Sum
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int n = nums.size();
        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        int len;
        int sum = 0;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                len = j-i+1;
                minLen = min(minLen,len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(minLen == INT_MAX) cout<<0;
        else cout<<minLen;
    
    return 0;
}