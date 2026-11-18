// Basic permutation code of string using recursion.
# include <bits/stdc++.h>
using namespace std;

void permutation(string curr,string str,vector<string>&ans){
    if(str=="") {
        ans.push_back(curr);
        curr = "";
        return;
    }
    for(int i=0; i<str.length(); i++){
        string lftstr = str.substr(0,i);
        string rgtstr = str.substr(i+1);
        permutation(curr+str[i],(lftstr+rgtstr),ans);    
        
    }
}
    
int main(){
    
    string str = "abc";
    vector<string>ansStr;
    string curr = "";
    permutation(curr,str,ansStr);
    for(string str:ansStr){
        cout<<str<<" ";
    }
    return 0;
}

// More optimised than previous one
# include <bits/stdc++.h>
using namespace std;

void permutation2(string inputstr,string outputstr){
    if(inputstr == ""){
        cout<<outputstr<<"\n";
        return;
    }
    unordered_set<char>st;
    for(int i=0; i<inputstr.length(); i++){
        if(st.find(inputstr[i])!=st.end()) continue;

        else{
            st.insert(inputstr[i]);
            string lftstr = inputstr.substr(0,i);
            string rgtstr = inputstr.substr(i+1);
            string finalInpstr = lftstr+rgtstr;
            permutation2(finalInpstr,outputstr+inputstr[i]);
        }
        
    }
}
    
int main(){
    
    string str = "aba";
    permutation2(str,"");
    
    return 0;
}

// Using Backtracking
# include <bits/stdc++.h>
using namespace std;

void permutation3(string &Str,int idx){
    if(idx == Str.length()-1){
        cout<<Str<<"\n";
        return;
    }
    
    unordered_set<char>st; 
    for(int i=idx; i<Str.length(); i++){
        if(st.count(Str[i]))continue; // Pruning step -It is the act of "cutting off" branches of your recursion tree
                                     // that you already know won't lead to a unique or valid solution.

        st.insert(Str[i]);
        swap(Str[i],Str[idx]);         // Do: Swap to fix a character at 'idx'
        permutation3(Str, idx + 1);   // Recurse: Move to next position
        swap(Str[i], Str[idx]);      // Undo: Backtrack to original state
    }
}
    
int main(){
    
    string str = "aba";
    int idx = 0;
    permutation3(str,idx);
    
    return 0;
}

// H.W leetcode 3483
// Permutations : Leetcode 46,47
# include <bits/stdc++.h>
using namespace std;

void permut(vector<int>nums,int idx){

    if(idx==nums.size()-1){
        for(auto ele:nums){
            cout<<ele<<" ";
        }
        cout<<"\n";
        return;
    }

    unordered_set<int>st;
    for(int i=idx; i<nums.size(); i++){
        if(st.find(nums[i])!=st.end())continue;

        else{
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            permut(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
        
    }

}
    
int main(){
    
    vector<int>nums = {1,2,1};
    int idx = 0;
    permut(nums,idx);
    return 0;
}

