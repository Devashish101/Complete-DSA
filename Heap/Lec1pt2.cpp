// TODO: Leetcode 347. Top K Frequent Elements
# include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
    
int main(){
    
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    int n = nums.size();

    // Storing the ele with their freq in a map.
    unordered_map<int, int> mp; //<ele,freq>
    for (auto ele : nums) {
        mp[ele]++;
    }

    // Now finding the K largest ele having greater freq using heap
    priority_queue<pi, vector<pi>, greater<pi> > pq; // Min Heap of pair<freq,ele>
    for (auto x : mp){
        int ele = x.first, freq = x.second;
        pair<int,int> p = {freq,ele};
        pq.push(p);

        // pq.push({freq,ele}); // we can avoid line no. 14 & 15.
        if(pq.size() > k) pq.pop();
    }

    // Pushing the K remaining "ele" in ans arr
    vector<int> ans;
    while(pq.size() != 0){ 
        ans.push_back(pq.top().second);
        pq.pop();
    }

    for (auto ele : ans) {
        cout<<ele<<" ";
    }
    return 0;
}
// H.W Leetcode 1636

// TODO: Leetcode 658 : Find K Closest Elements.
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 4, x = 3;
    int n = arr.size();
    priority_queue<pair<int,int>>pq;

    for(int i=0; i<n; i++){
        int dis = abs(arr[i]-x);
        pair<int,int> p = {dis,arr[i]};
        pq.push(p);
        if(pq.size() > k)pq.pop();
    }
    vector<int>ans;
    while(pq.size() != 0){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    
    return 0;
}

// TODO: Leetcode 973 : K Closest points to origin
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;
    int m = points.size();
    priority_queue<pair<int, vector<int>> >pq;// Max Heap of pair having int, vector<int>
    for(int j=0; j<m; j++){
        int x = points[j][0];
        int y = points[j][1];
        int dist = x*x + y*y;
        pq.push({dist,points[j]});
        if(pq.size() > k)pq.pop();
    }

    vector<vector<int>> ans;
    while(pq.size() != 0){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    for(auto ele: ans){
        for(auto x: ele){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// TODO: Leetcode 1046 : Last Stone Weight
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> stones = {2,7,4,1,8,1};
     int n = stones.size();

    priority_queue<int>pq;
    for(int i=0; i<n; i++){
        pq.push(stones[i]);
    }

    while(pq.size() > 1 ){
        int s1 = pq.top(); // 1st largest Stone
        pq.pop();
        int s2 = pq.top(); // 2nd largest Stone
        pq.pop();
        int s3 = s1 - s2; // New stone Formed
        if(s3 != 0) pq.push(s3);
    }
    cout<<(pq.size() == 1 ? pq.top() : 0);
    return 0;
}

// Minimum Cost to Connect all Ropes -> GfG
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int> ropes = {2,7,4,1,8};
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> cost;

    for(int i=0; i<ropes.size(); i++){
        pq.push(ropes[i]);
    }
    while(pq.size() > 1){
        int r1 = pq.top();
        pq.pop();
        int r2 = pq.top();
        pq.pop();
        cost.push_back(r1+r2);
        pq.push(r1+r2);
    }
    int ans = 0;
    for(auto ele: cost){
        ans+=ele;
    }
    cout<<ans;
    return 0;
}