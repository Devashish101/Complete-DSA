//                                 Merge two sorted Arrays 
# include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
     vector<int> v3;
     int i=0;
     int j=0;

     while(i<m && j<n){
          if(nums1[i] < nums2[j]){
               v3.push_back(nums1[i]);
               i++;
          }
          else{ //(nums1[i] > nums2[j])
               v3.push_back(nums2[j]);
               j++;
          } 
     }
     
     // For Remaning Elements
     if(i==m){
          while(j<=n-1){
               v3.push_back(nums2[j]);
               j++;
          }
     }
     if(j==n){
          while(i<=m-1){
               v3.push_back(nums1[i]);
               i++;
          }
     }

   for(int i=0; i<v3.size(); i++){
     cout<<v3[i]<<" ";
   }
}

int main(){
    
   vector<int> v1 = {1,4,5,8};
   vector<int> v2 = {2,3,6,7,10,12};

   int m = v1.size();
   int n = v2.size();

   merge(v1,m,v2,n);
   return 0;
}
  
//                            31. Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // 1. finding the pivot index
        int idx = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){ // i.e array is already greatest
            reverse(nums.begin(), nums.end());
            return;
        }
        // 2.reverse the element from pivotindex+1 to end
        reverse(nums.begin()+idx+1 , nums.end());
        // 3. finding the just greater element than pivot element
        int j = -1;
        for(int i = idx+1; i<n; i++){
            if(nums[i]>nums[idx]){
                j = i;
                break;
            }
        }
        // 3. swapping idx and j
        swap(nums[idx],nums[j]);
    }
};

//                                         Pascal's Triangle 1
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> PascalTriangle(int n){
    vector<vector<int>> res ;

    for(int i=1; i<=n; i++){
        vector<int> a(i);
        res.push_back(a);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i){
                res[i][j] = 1;
            }
            else{
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
            
        }
    }
    return res;
}

int main(){
    int rowNum;
    cout<<"Enter the RowNumber :";
    cin>>rowNum;
    vector<vector<int>> V = PascalTriangle(rowNum); 
    for(int i=0; i<V.size(); i++){
        for(int j=0 ;j<V[i].size(); j++){
            cout<<V[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

// Score After Flipping Matrix 861.
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int cols = grid[0].size();

        // Making the First column all 1's
        for(int i=0; i<row; i++){
            if(grid[i][0] == 0){ // flip 
                for(int j=0; j<cols; j++){
                    if(grid[i][j] == 0){ //flipping the whole row
                        grid[i][j] = 1;
                    }
                    else{
                        grid[i][j] = 0;
                    }
                }
            }
        }

        // flip the columns if no0 > no1
        for(int j=0; j<cols; j++){
            int noz = 0;
            int noo = 0;
            for(int i=0; i<row; i++){
                if(grid[i][j] == 0){
                    noz++;
                }
                else{
                    noo++;
                }
            }
            if(noz>noo){ //flip
                for(int i=0; i<row; i++){
                    if(grid[i][j] == 0){ //flipping the whole col
                        grid[i][j] = 1;
                    }
                    else{
                        grid[i][j] = 0;
                    }
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < row; i++) {
            int x = 1;
            for(int j = cols - 1; j >= 0; j--) {
                sum += grid[i][j] * x;
                x *= 2;
            }
        }
        return sum;
    }
};

// Search a 2D Matrix 240.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int cols = matrix[0].size();

        int i =0;
        int j = cols-1;

        while(i<row && j>=0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};