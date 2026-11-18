//-----------------------------------From Striver Greedy Playlist--------------------------------

// Leetcode 455 : Assign Cookies
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};
    sort (g.begin(),g.end());
    sort (s.begin(),s.end());

    int i=0, j=0;
    int count =0;

    while(i<g.size() && j<s.size()){
        if(s[j]>=g[i]){
            i++;
            j++;
            count++;
        }
        else{
            j++;
        }
    }
    cout<<count;
    return 0;
}

// Leetcode : 860. Lemonade Change
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> bills = {5,5,10,10,20}; // false

    int count5 = 0, count10 = 0;
    if(bills[0] != 5)return false;

    int i = 0;
    while(i < bills.size()){

        if(bills[i] == 5) count5++;

        else if(bills[i] == 10){
            if(count5 < 1)return false;
            else{
                count10++;
                count5--;
            }
        }

        else{ // bills[i] == 20
            if(count10 >= 1 && count5 >= 1){
                count10--;
                count5--;
            }
            else if(count5 >= 3){
                count5-=3;
            }else{
                return false;
            }
        }
        
        i++;
    } 
    return true;
}

// Shortest Job first - GFG (M.D)***
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int>bt = {4,3,7,1,2}; // 4
    int n = bt.size();
    sort(bt.begin(), bt.end());
    
    int wtTime = 0;
    int total = 0;
    int i = 0;
    while(i < n-1){
        wtTime += bt[i];
        total += wtTime;
        i++;
    }
    return (total/n);
}

// Leetcode 55: Jump game
// Note when there are all +ve integers then always true, 
// In some cases of Zero we will only get false.
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> nums = {3,2,1,0,4};
    int maxidx = 0;
    int idx = 0;
    while(idx < nums.size()){
        if(idx > maxidx)return false;
        maxidx = max(maxidx, idx+nums[idx]);
        idx++;
    }
    return true;
}

// 45. Jump Game II
# include <bits/stdc++.h>
using namespace std;

// Recursuion + Memoization Approach.(D.P) -> IT will give TLE
vector<vector<int>>dp;
int helper(int idx, int jumps, vector<int>& nums){
    if(idx >= nums.size()-1)return jumps;
    if(dp[idx][jumps] != -1)return dp[idx][jumps];

    int mini = INT_MAX;
    for(int i=1; i<=nums[idx]; i++){
        mini = min(mini,helper(idx+i,jumps+1,nums));
    }
    return dp[idx][jumps] = mini;
}
    
int main(){
    
    vector<int> nums = {2,3,1,1,4};
    int n = nums.size();
    dp.assign(n, vector<int>(n,-1));
    return helper(0,0,nums);

// Greedy Approach 
    int n =nums.size();
    int jumps = 0;
    int left = 0, right = 0;
    while(right < n-1){
        int farthest = 0;
        for(int i=left; i<=right; i++){
            farthest = max(farthest,i+nums[i]);
        }
        left = right+1;
        right = farthest;
        jumps++;
    }
    return jumps;
}

// Leetcode 57. Insert Interval
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}}; 
    vector<int> newInterval = {4,8};
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>ans;

    int i = 0;
    // Pushing the all non overlapping intervals before newInterval
    while(i < n && intervals[i][1] < newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }
    // merging the overlapping intervals with newIntervals
    while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    ans.push_back(newInterval); // Pushing the newinterval after merging

    // Pushing the remaning intervals.
    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }

    for(auto ele:ans){
        for(int x:ele){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

