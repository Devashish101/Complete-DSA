// Leetcode 56: Merge Intervals
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int> > intervals = {{1,3},{2,6},{8,10},{15,18}};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]); // Put the first interval initially

    int i = 1;
    while(i < intervals.size()) {
        vector<int>& last = ans.back(); // Get reference to the last interval of ans

        if(last[1] >= intervals[i][0]) { // End becomes the maximum of both intervals end time. 
            last[1] = max(last[1], intervals[i][1]);
        }
        else { // No overlap, so current interval becomes a new interval in ans
            ans.push_back(intervals[i]);
        }
        i++;
    }
    for(auto ele: ans){
        for(auto x: ele){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

// Leetcode 435 : Non-overlapping Intervals
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int>> intervals = {{1,10},{2,3},{4,5}};
    sort(intervals.begin(), intervals.end());
    vector<vector<int> >arr;
    arr.push_back(intervals[0]);
    int count = 0;
    int i = 1;
    while(i < intervals.size()){
        vector<int>& temp = arr.back();
        if(temp[1] > intervals[i][0]){
            count++;
            temp[1] = min(temp[1], intervals[i][1]); // we will keep the interval having end times.
        }
        else{
            arr.push_back(intervals[i]);
        }
        i++;
    }
    cout<<count;
    return 0;
}

//Leetcode 452. Minimum Number of Arrows to Burst Balloons
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int> > points = {{1,2},{2,3},{3,4},{4,5}};
    sort(points.begin(), points.end());

    vector<vector<int> > arr;
    arr.push_back(points[0]);
    int count = 0;
    int i = 1;
    while(i < points.size()){
        vector<int>& temp = arr.back();
        if(temp[1] >= points[i][0]){ // Overlapping intervals
            temp[1] = min(temp[1], points[i][1]);
        } 
        else{ // Non Overlapping intervals
            count++;
            arr.push_back(points[i]);
        }
        i++;
    }
    count++;
    cout<<count;
    
    return 0;
}

// Activity Selection problem GFG.
# include <bits/stdc++.h>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int activitySelection(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    
    // Making the pair of st and end time of activities.
    vector<vector<int>> arr;
    for(int i=0; i<n; i++){
        arr.push_back({start[i],finish[i]});
    }
    sort(arr.begin(),arr.end(),cmp); // sorting the pairs based on their end time in increasing order
    
    vector<vector<int>>ans;
    ans.push_back(arr[0]);
    int i=1;
    while(i < arr.size()){
        vector<int>&temp = ans.back();
        if(temp[1] < arr[i][0]){
            ans.push_back(arr[i]);
        }
        i++;
    }
    return ans.size();
    
}
    
int main(){
    
    vector<int>st = {3,1,8,9,6,2,4,1,2,4}; // 1,1,2,2,3,4,4,6,8,9  -> ans = 2;
    vector<int>end = {8,6,16,12,6,10,9,10,8,7}; // 6,6,7,8,8,9,10,10,12,16

    cout<<activitySelection(st,end);
    return 0;
}