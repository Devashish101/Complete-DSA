//                   ******************problems on sorting************************
// TODO: 169. Majority Element
// Approach 1
# include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {2,2,2,1,1,2,1};
    int n = nums.size();

    for(int i=0; i<n; i++){
        int count = 1;
        for(int j=i+1; j<n; j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count > (n/2)){
            cout<<"Majority Element is :"<<nums[i];
        }
    }
}
// Approach 2:
# include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {2,2,2,1,1,2,1};
    int n = nums.size();
    sort(nums.begin(),nums.end());
    cout<<nums[(n/2)];
}

//QUES2:- (Sorting lec 3)given an array with N distinct elements,convert the given array to a form,
// where all elements are in the range from 0 to N-1.The order of elements is the Same.
# include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {19,12,23,8,16};
    int n = 5;
    vector<int> v(n,0);
    int x = 0;

    for(int i=0; i<n; i++){
        int min = INT_MAX;
        int minidx = -1;
        for(int j=0; j<n; j++){
            if(v[j]==1){
                continue;
            }
            else if(min>arr[j]){
                min = arr[j];
                minidx = j;
            }
        }
        arr[minidx]=x;
        v[minidx]=1;
        x++;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}

// 455. Assign Cookies
# include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> greed = {16,15,7,14};
    vector<int> cookie = {3,5,7,9,16,12,15,14};

    sort(greed.begin(), greed.end());
    sort(cookie.begin(), cookie.end());
    int i = 0;
    int j = 0;
    int count = 0;
        while(i<greed.size() && j<cookie.size()){
        if(cookie[j]>=greed[i]){
            count ++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    cout<<count;

}