//                                                      Binary search level 2

// Leetcode 852 : peak index in an mountain array 
# include <iostream>
using namespace std;

int peakelement(int arr[], int n){
    int s=0;
    int e=n-1;

    while(s<e){
        int mid=s+(e-s)/2;

        if(arr[mid] < arr[mid+1]){
            //mai left slope par hu
            //peak aage ya right slope pe exist karegi 
            s=mid+1;
        }

        else{
            // iska matlab ya to mai right slope pe hu
            //ya peak par hu
            //agar mid-1 kiya to sayad mai peak element ko lost kardunga
            //isliye e=mid isse mai left me bhi aa jaunga aur peak lost hone ka chance bhi nahi hoga
            e=mid;
        }
    }
    return s;//peak index
}

int main(){
    
    int n=6;
    int arr2[]={1,2,3,7,5,4};
    int ans=peakelement(arr2, n);
    cout<<"peak element of an array is :"<<arr2[ans];
    return 0;
}


// Leetcode 33: search for a target in a rotated sorted array
class Solution {
public:
    // Function to find the pivot (smallest element in rotated sorted array)
    int findPivot( vector<int>& arr) {
        int s = 0, e = arr.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] > arr[e]) {
                // Pivot is in the right part
                s = mid + 1;
            } else {
                // Pivot is in the left part
                e = mid;
            }
        }
        return s; // Index of the smallest element (pivot)
    }

    // Standard binary search
    int binarySearch( vector<int>& arr, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return mid; // Target found
            } else if (arr[mid] < target) {
                s = mid + 1; // Search right
            } else {
                e = mid - 1; // Search left
            }
        }
        return -1; // Target not found
    }

    int search(vector<int>& arr, int target) {
        int n = arr.size();
        if (n == 0) return -1; // Edge case: empty array

        // Find the pivot index (smallest element)
        int pivot = findPivot(arr);

        // Check which part of the array to search
        if (target >= arr[pivot] && target <= arr[n - 1]) {
            // Search in the right sorted half
            return binarySearch(arr, pivot, n - 1, target);
        } else {
            // Search in the left sorted half
            return binarySearch(arr, 0, pivot - 1, target);
        }
    }
};


// Leetcode 658 : Find K Closest Elements
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    int k = 4, x = 3;

    vector<int> ans(k);
    int t = 0;

    // Case 1: x smaller than all elements
    if (x < nums[0]) {
        for (int i = 0; i < k; i++)
            ans[i] = nums[i];
    }

    // Case 2: x larger than all elements
    if (x > nums[n - 1]) {
        for (int i = n - k, j = 0; i < n; i++, j++)
            ans[j] = nums[i];
    }

    // Case 3: x lies within the array range
        int lo = 0, hi = n - 1, mid = -1;
        bool flag = false;

        // Binary Search
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == x) {
                flag = true;
                ans[t++] = nums[mid];
                break;
            } else if (nums[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        int lb = hi;
        int ub = lo;
        if (flag) {
            lb = mid - 1;
            ub = mid + 1;
        }

        // Expand from middle
        while (t < k && lb >= 0 && ub <= n - 1) {
            int d1 = abs(x - nums[lb]);
            int d2 = abs(x - nums[ub]);
            if (d1 <= d2) {
                ans[t++] = nums[lb--];
            } else {
                ans[t++] = nums[ub++];
            }
        }

        // If left boundary exhausted
        if (lb < 0) {
            while (t < k && ub <= n - 1)
                ans[t++] = nums[ub++];
        }

        // If right boundary exhausted
        if (ub > n - 1) {
            while (t < k && lb >= 0)
                ans[t++] = nums[lb--];
        }

    sort(ans.begin(), ans.end());
    for (auto ele : ans)
        cout << ele << " ";
}

// Leetcode 633 : Sum of Sqr Numbers
# include <bits/stdC++.h>
using namespace std;

bool isperfectSquare(int n){
    int root = sqrt(n);
    if(root*root==n) return true;
    else return false;
}

int main(){
    int num = 40;
    // cin>>num;
    
    int x = 0, y = num;
    bool flag = false;
    while(x<=y){
        if(isperfectSquare(x) && isperfectSquare(y)){
            flag = true;
            break;
        }
        else if(!isperfectSquare(y)){ //y is not a perfect sqr
            y = (int)sqrt(y) * (int)sqrt(y); //decresing the y in terms of perfect sqr
            x = num-y;
        }
        else{ //x is not perfect sqr
            x = ((int)sqrt(x)+1) * ((int)sqrt(x)+1); //increasing the value of x in terms of perfect sqr
            y = num-x;
        }
    }
    if(flag) {
        cout<<x<<" "<<y<<" "<<"\n";
        cout<<true;
    }
    else cout<<false;

}



