//                                          Binary Search on Answers.
// TODO: GFG: Allocate Minimum number of pages
# include <bits/stdc++.h>
using namespace std;

bool isValidAns(vector<int> arr, int k, long long mid){
    int student = 1;
    int i = 0;
    long long sum = 0;

    while(i < arr.size()){

        sum += arr[i];

        if(sum <= mid){
            i++;
        }else{
            student++;
            if(arr[i] > mid)return false; // v.imp
            sum = arr[i];
            i++;
        }
    }
    return student <= k;
}

int main(){
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    int n = arr.size();
    if(n < k)return -1;

    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    long long ans = sum;
    long long s = 1, e = sum;

    while(s <= e){
        long long mid = s + (e-s)/2;

        if(isValidAns(arr,k,mid)){
            ans = min(mid,ans);
            e = mid-1;
        }else{
            s = mid+1;
        }
    }

    cout<<(int)ans;
}

// TODO: GFG: Aggresive Cows
# include <bits/stdc++.h>
using namespace std;

bool isValid(int mindistance, vector<int> arr, int k){
    int cowCount = 1;
    int lastPosition = 0;
    
    for(int i=1; i<arr.size(); i++){
        if(arr[i] - arr[lastPosition] >= mindistance){
            cowCount ++;
            lastPosition = i;
        }
        if(cowCount == k){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {10, 1, 2, 7, 5};
    int k = 3;

    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    int ans = -1;
    int st = 0;
    int end = arr[n-1] - arr[0];
    while(st <= end){
        int mid = st+(end-st)/2;
        
        if(isValid(mid,arr,k)){
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    cout<<ans;
}

//TODO: GFG: Maximum height for given total Reduction or EKO from SPOJ.
# include <bits/stdc++.h>
using namespace std;

bool isValid(int maxHeight,vector<int> arr, int m ){
    long long total_wood = 0;
    
    for(int i=0; i<arr.size(); i++){
        long long current_wood = 0;
        if(arr[i] >= maxHeight){
            current_wood = arr[i] - maxHeight;
        }
        total_wood += current_wood;
    }
    if(total_wood >= m)return true;
    else return false;
}

int main(){
    vector<int> arr = {4, 42, 40, 26, 46};
    int m = 20;

    int n = arr.size();
        
    int st = 0;
    int end = -1;
    for(int i=0; i<n; i++){
        if(arr[i] > end){
            end = arr[i];
        }
    }
    
    int ans = -1;
    while(st <= end){
        int mid = st + (end - st)/2;
        
        if(isValid(mid,arr,m)){
            ans = max(ans,mid);
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<ans;
}
