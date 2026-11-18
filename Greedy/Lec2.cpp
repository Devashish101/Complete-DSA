// Leetcode 781 : Rabbits in Forest
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int>ans = {2,2,3,3,0,2,2,2,2};
    sort(ans.begin(), ans.end());
        unordered_map<int,int>mp;
        int count = 0;

        // Inserting and counting the rabits
        for(int ele:ans){
            if(ele == 0) count += 1;
            else{
                mp[ele]++;
                if(mp[ele] == ele+1){
                    count += ele+1;
                    mp[ele] = 0;
                }
            }
        }

        // Adding the remaning ele from the map
        for(auto x: mp){
            if(x.second > 0){
                count += x.first+1;
            }
        }
        cout<<count;
    
    return 0;
}

// Meeting Rooms II -> Leetcode(Lintcode), GFG
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> start = {10,22,11,4,11};
    vector<int> end = {14,29,30,12,29};
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int rooms = 0;
    int count = 0;
    int i = 0, j = 0;
    while(i < start.size()){
        if(start[i] < end[j]){
            count++;
            i++;
            
        }else{
            j++;
            rooms = max(count,rooms);
            count--;
        }
    }
    rooms = max(count,rooms);
    cout<<rooms;
    
    return 0;
}

// Meeting Rooms -> Leetcode(Lintcode), GFG
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<vector<int>> arr = {{1, 4}, {10, 15}, {7, 10}};
    sort(arr.begin(), arr.end());
        
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i][1] > arr[i+1][0]) cout<<false;
    }
    cout<<true;
    
    return 0;
}