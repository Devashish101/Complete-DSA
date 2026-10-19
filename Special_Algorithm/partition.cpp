# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    int arr[] = {1,2,3,4,5,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Finding the Prefix sum
    for(int i=1; i<n; i++){
        arr[i] += arr[i-1];
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    // Finding the Partitioned Index
    int idx = -1;
    for(int i=1; i<n; i++){
        if(2*arr[i]==arr[n-1]){
            idx = i;
            break;
        }
    }
    if(idx!=-1) cout<<"Array can be partioned at idx :"<<idx;
    else cout<<"Array can't be partioned .";
    return 0;
}

// Leetcode : 238 Product of Array except Self
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int>nums = {4,2,5,3}; //{30,60,24,40}
    int n = nums.size();

    vector<int>prefix(n);
    vector<int>suffix(n);

    // prefix Product Array
    prefix[0] = 1;
    int prod = nums[0];
    for (int i = 1; i < n; i++){
        prefix[i] = prod;
        prod *= nums[i];
    }

    // suffix Product Array
    suffix[n-1] = 1;
    prod = nums[n-1];
    for (int i = n-2; i >= 0; i--){
        suffix[i] = prod;
        prod *= nums[i];
    }
    

    // Now finding the resultant product by making changes in our prefix Array
    for (int i = 0; i < n; i++){
        prefix[i] = prefix[i]*suffix[i];
    }
    
    for(int i=0; i<n; i++){
        cout<<prefix[i]<<" ";
    }
    return 0;
}