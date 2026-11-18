//    Leetcode 39: Combination Sum 1
# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> FinalAns;
void combinations(vector<int>&cand,int idx,vector<int>&set,int target){
    if(target==0){
        FinalAns.push_back(set);
        return;
    }
    if(idx==cand.size()) return;

    if(cand[idx]<=target){
        set.push_back(cand[idx]);
        combinations(cand,idx,set,target-cand[idx]);
        set.pop_back();
    }
    combinations(cand,idx+1,set,target);

}
    
int main(){
    
    vector<int> candidates = {2,3,5};
    int target = 8;
    sort(candidates.begin(),candidates.end());
    vector<int>set;
    combinations(candidates,0,set,target);

    for(auto vec : FinalAns){

        cout << "[ ";

        for(auto ele : vec){
            cout << ele << " ";
        }

        cout << "]" << endl;
    }
    return 0;
}

// Leetcode 40: Combination sum 2.
# include <bits/stdc++.h>
using namespace std;

    vector<vector<int>>finalans;
    void helper(vector<int>&people,int tar,int idx,vector<int>&subset){
        // Base case
        if(tar==0){
            finalans.push_back(subset);
            return;
        }
        if(idx==people.size())return;


        if(people[idx]<=tar){ // pick
            subset.push_back(people[idx]);
            helper(people,tar-people[idx],idx+1,subset);
            subset.pop_back();
        }
        // Not Pick
        int j = idx+1;
        while(j<people.size() && people[j]==people[j-1]) j++; // For avoiding the duplicate values.
        helper(people,tar,j,subset);
        
        
    }
    
int main(){
    
    vector<int> candidates = {10,1,2,7,6,1,5};
        int target = 8;
        sort(candidates.begin(),candidates.end());
        vector<int>subset;
        helper(candidates,target,0,subset);

        for(auto vec : finalans){

            cout << "[ ";

            for(auto ele : vec){
                cout << ele << " ";
            }

            cout << "]" << endl;
        }
    
    
    return 0;
}

// Leetcode 41: Combination sum 3
    # include <bits/stdc++.h>
    using namespace std;

    vector<vector<int>>ans;
    void helper(int k, int n,int idx,int count,vector<int>&set){
        if(n==0 && count==k+1){
            ans.push_back(set);
            return;
        }
        if(n!=0 && count==k+1)return;
        
        for(int i=idx; i<=9; i++){
            if(i<=n && count<=k){
                set.push_back(i);
                helper(k,n-i,i+1,count+1,set);
                set.pop_back();
            }
        }

    }

    int main(){
        int k=3,n=9;
        vector<int>set;
        helper(k,n,1,1,set);
        for(auto ele: ans){
            for(auto set: ele){
                cout<<set<<" ";
            }
            cout<<endl;
        }
        
        return 0;
    }

