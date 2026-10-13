//                                   question practice on ARRAYS
// program on arranging the -ve and +ve element of an array => 
# include <bits/stdc++.h>
// # include<algorithm>//to use reverse function in an array
using namespace std;

void ArrangingElements( int arr[] , int n){
        int j=0;
        for(int index=0; index<n; index++){
            if(arr[index]<0){
            swap(arr[index], arr[j]);
            j++;
        }

    }
}

void printarray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int n=6;
    int arr[6]={0,-12,5,-8,4,-10};
    ArrangingElements(arr , n);
    reverse(arr,arr+n);
    printarray(arr , n);
    return 0;
}


//Sort COlors:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int left = 0;
        int right = n-1;

        while(index <= right) {

            if(nums[index] == 0) {
                swap(nums[index], nums[left]);
                left++;
                index++;
            }
            else if(nums[index] == 2) {
                swap(nums[index], nums[right]);
                right--;
                //catch -> no need of index++
                //index++
            }
            else {
                index++;
            }


        }

    }
};

//Rotate Array:

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        
        for(int index=0; index<n; index++) {
            int newIndex = (index + k ) % n;
            ans[newIndex] = nums[index];
        }

        nums = ans;        
    }
};

//Missing Number

# include <iostream>
using namespace std;

int missingNumber(int arr[], int size) {
        int sum = 0;
        for(int index=0; index<size-1; index++) { //The loop iterates from 0 to n - 1 because the array has n - 1 elements (one number is missing).
            sum = sum + arr[index];
        }

        int totalSum = (size*(size+1))/2;
        int ans = totalSum - sum;
        return ans;
    }

int main(){
    int size=7; // Total number of elements including the missing one
    int num[]={1,2,3,4,5,7};
    int finalans = missingNumber(num,size);
    cout<<"missing no. is :"<<finalans;
    return 0;
}

//ReArrange Array: 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int evenIndex = 0;
        int oddIndex = 1;
        vector<int> ans(n);

       while(index < n ) {
           if(nums[index] > 0) {
            ans[evenIndex] = nums[index];
            evenIndex += 2;
           }
           index++;
       }

       index = 0;
        while(index < n ) {
           if(nums[index] < 0) {
            ans[oddIndex] = nums[index];
            oddIndex += 2;
           }
           index++;
       }
       return ans;
    }
};

//Row with Maximum Ones:

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        //oneCOunt -> will store max number of 1's in a row
        int oneCount = INT_MIN;
        //rowNo -> will store index of max no. of 1's wali row
        int rowNo ;

        for(int i=0; i<n; i++) {
            //hr row start hone se phle initialise count with 0
            int count = 0;
            for(int j=0; j< mat[i].size(); j++) {
                //if 1 found, then increment count
                if(mat[i][j] == 1) {
                    count++;
                }
            }
            //after row completion, compare count with oneCount
            if(count > oneCount) {
                oneCount = count;
                rowNo = i;
            }

        }

        ans.push_back(rowNo);
        ans.push_back(oneCount);
        return ans;
        
    }
};

// given an array/vector of size n+1 consisting of elements from 1 to n find duplicate element

// Approach 2 (OPtimized but taking extra space).
# include <bits/stdc++.h>
using namespace std;

int main (){
    int n = 7;
    vector<int> arr = {6,3,5,4,2,7,1,5};
    vector<int> myarr(n+1,0);

    for(int i=0; i<arr.size(); i++){
        if(myarr[arr[i]]==0){
            myarr[arr[i]] = 1;
        }
        else if(myarr[arr[i]]==1){
            cout<<"duplicate number is :"<<arr[i];
            break;
        }
    }
}



// Approach 3 (OPtimized)
# include <bits/stdc++.h>
using namespace std;

void find_duplicate(vector<int> arr, int n){
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    int original_sum = (n*(n+1))/2;

    int duplicate = sum - original_sum;
    cout<<"Duplicate Number is"<<duplicate;
}

int main (){
    int n = 7;
    vector<int> arr = {6,3,7,4,2,7,1,5};
    find_duplicate(arr,n);
}


