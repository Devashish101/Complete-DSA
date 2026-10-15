// Maximum Sum SubArray of size k
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
   int arr[] = {7,1,2,5,8,4,9,3,6};
   int n = sizeof(arr)/sizeof(arr[0]);
   int k = 4;

   // Method 1 -> Brute Force
   // Time Complexity = O(k*n)
//    int maxSum = INT_MIN;
//    int maxIdx = -1;
//    for(int i=0; i<=n-k; i++){
//         int sum = 0;
//         for(int j=i; j<i+k; j++){
//             sum += arr[j];
//         }
//         if(maxSum<sum){
//             maxSum = sum;
//             maxIdx = i;
//         }
//    }
//    cout<<maxSum<<endl;
//    cout<<maxIdx<<endl;
   

   // Method 2 -> Sliding Window
   int maxSum = INT_MIN;
   int maxIdx = -1;
   int sum = 0;
   for(int i=0; i<k; i++){
      sum += arr[i];
   }
   maxSum = sum;

   int i=1 , j=k;
   while(j<n){
      sum = sum + arr[j] - arr[i-1];
      if(maxSum<sum){
        maxSum = sum;
        maxIdx = i;
      }
      i++;
      j++;
   }
   cout<<maxSum<<endl;
   cout<<maxIdx<<endl;
   
    return 0;
}

