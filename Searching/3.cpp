//                                           =>Searching  level 3
// program to find the quotient of division of 2 numbers
# include <iostream>
using namespace std;

int binarysearch(int dividend , int divisor){
    int s=0;
    int e=dividend;
    int ans=-1;
    if(dividend==0){
        cout<<"final_ans is : infinity i.e ";
        return ans = INT16_MAX;
    }
    else if(divisor==0){
        return 0;
    }
    while(s<=e){
        int mid = s + (e-s)/2; //basically quotient is mid
        //divisor*quotient+remainder = dividend
        //=> divisor*quotient<=dividend 
        if( divisor*mid == dividend){
            return mid;
        }
        // right me jao for more accuracy
        else if(divisor*mid<dividend){
            ans = mid;
            s=mid+1;
        }
        else{ //(divisor*mid > dividend)
            //left me jao
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    int dividend;
    int divisor;
    cout<<"enter dividend :";
    cin>>dividend;
    cout<<"enter divisor :";
    cin>>divisor;
    //  (abs)  is a "absolute" function which act as a modulus i.e |x| = +ve 
    
    int final_ans = binarysearch(abs(dividend) , abs(divisor));
    //now handling the negative cases:
    if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
        final_ans= 0 - final_ans;
    }
    cout<<"qoutient will be : "<<final_ans<<endl;
    return 0;
} 

//Searching for a target element in a nearly sorted array
# include <iostream>
using namespace std;

int search(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if( mid+1<n && arr[mid+1]==target){
            return mid+1;
        }
        else if( mid-1>0 && arr[mid-1]==target){
            return mid-1;
        }
        else if(target>arr[mid]){
            // right me jao
            s=mid+2; // note :- here to we are doing +2 to avoid extra comparision while going right
        }
        else{
            e=mid-2; // note :- here to we are doing -2 to avoid extra comparision while going left
        }
    }
    return -1;
}

int main(){
int n = 7;
int arr[] = {20,10,30,50,40,70,60}; //nearly sorted array
int target=60;
int ans=search(arr,n,target);
if(ans == -1) {
   cout << "Element Not found" << endl;
  }
  else {
   cout << "Element Found at Index: " << ans << endl;
  }
return 0;
}


// To find the element in a sorted array that appears an odd number of times using a binary search approach
#include <iostream>
using namespace std;

int oddOccurringElement(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;

        // For single element
        if (s == e) {
            return arr[s]; // Return the element itself
        }

        // Checking if mid is at an even index
        if ((mid & 1) == 0) { // mid % 2 == 0
            if (mid + 1 < n && arr[mid] == arr[mid + 1]) {
                // Move to the right
                s = mid + 2;
            } else {
                // Move to the left
                e = mid;
            }
        } else { // mid is at an odd index
            if (mid - 1 >= 0 && arr[mid] == arr[mid - 1]) {
                // Move to the right
                s = mid + 1;
            } else {
                // Move to the left
                e = mid;
            }
        }
    }
    return -1; // Return -1 if no such element is found
}

int main() {
    int n = 11;
    int arr[] = {2, 2, 4, 4, 6, 6, 5, 5, 8, 7, 7};
    int finalAns = oddOccurringElement(arr, n);
    if (finalAns != -1) {
        cout << "The element that appears an odd number of times is: " << finalAns << endl;
    } else {
        cout << "No element appears an odd number of times." << endl;
    }
    return 0;
}


// smallest missing number in a sorted array of distinct integers starting from 0.
// Time Complexity = 0(logn)
# include <bits/stdc++.h>
using namespace std;

int main(){
int n = 11;
int arr[] = {0,1,2,3,4,5,6,7,8,9,11}; 

int s = 0;
int e = n-1;

while(s<e){

    int mid = s+(e-s)/2;
    if(arr[mid]==mid){
        s = mid+1;
    }
    else if(arr[mid]!=mid){
        e = mid;
    }
}
cout<<s;

}

//                                    =>Pair Sum
#include <iostream>
#include <vector>
using namespace std;

vector<int>  pairSum(vector<int> arr, int m) {
    int s = 0;
    int e = arr.size() - 1;

    vector<int> res;

    while (s < e) {
        int currsum = arr[s] + arr[e];

        if (currsum == m) {
            res.push_back(s);
            res.push_back(e);
            return res;
        } 
        
        else if (currsum < m) {
            s++;
        }

        else {
            e--;
        }
    }
    res.push_back(-1);
    return res; // no such pair found
}

int main() {
    vector<int> arr = {2, 7, 11, 15};  
    int sum = 19;

    vector<int>result = pairSum(arr,sum);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}
