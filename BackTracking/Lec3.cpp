// The Knight's Tour - GFG
    # include <bits/stdc++.h>
    using namespace std;

    bool flag = 0;
    void helper(int strow,int stcol,int val,int n,vector<vector<int>>&board){
        if(val==n*n){
            flag = 1;
            return;
        }
        
        // Top Right
        if(strow-2>=0 && stcol+1<n && board[strow-2][stcol+1]==-1){
            board[strow-2][stcol+1]=val;
            helper(strow-2,stcol+1,val+1,n,board);
            if(flag==1)return;
            board[strow-2][stcol+1]=-1;
        }
        
        // Top Left
        if(strow-2>=0 && stcol-1>=0 && board[strow-2][stcol-1]==-1){
            board[strow-2][stcol-1]=val;
            helper(strow-2,stcol-1,val+1,n,board);
            if(flag==1)return;
            board[strow-2][stcol-1]=-1;
        }
        
        // Right up
        if(strow-1>=0 && stcol+2<n && board[strow-1][stcol+2]==-1){
            board[strow-1][stcol+2]=val;
            helper(strow-1,stcol+2,val+1,n,board);
            if(flag==1)return;
            board[strow-1][stcol+2]=-1;
        }
        
        // Right down
        if(strow+1<n && stcol+2<n && board[strow+1][stcol+2]==-1){
            board[strow+1][stcol+2]=val;
            helper(strow+1,stcol+2,val+1,n,board);
            if(flag==1)return;
            board[strow+1][stcol+2]=-1;
        }
        
        // Bottom Right
        if(strow+2<n && stcol+1<n && board[strow+2][stcol+1]==-1){
            board[strow+2][stcol+1]=val;
            helper(strow+2,stcol+1,val+1,n,board);
            if(flag==1)return;
            board[strow+2][stcol+1]=-1;
        }
        
        // Bottom Left
        if(strow+2<n && stcol-1>=0 && board[strow+2][stcol-1]==-1){
            board[strow+2][stcol-1]=val;
            helper(strow+2,stcol-1,val+1,n,board);
            if(flag==1)return;
            board[strow+2][stcol-1]=-1;
        }
        
        // Left up
        if(strow-1>=0 && stcol-2>=0 && board[strow-1][stcol-2]==-1){
            board[strow-1][stcol-2]=val;
            helper(strow-1,stcol-2,val+1,n,board);
            if(flag==1)return;
            board[strow-1][stcol-2]=-1;
        }
        
        // Left down
        if(strow+1<n && stcol-2>=0 && board[strow+1][stcol-2]==-1){
            board[strow+1][stcol-2]=val;
            helper(strow+1,stcol-2,val+1,n,board);
            if(flag==1)return;
            board[strow+1][stcol-2]=-1;
        }
        
    }
    
    int main(){
        int n = 5;
        // if(n == 2 || n == 3 || n == 4){
        //     return vector<vector<int>>(); // we can also return {};
        // }
        vector<vector<int>>board(n,vector<int>(n,-1));
        board[0][0] = 0;
        helper(0,0,1,n,board);
        for(auto ele: board){
            for(auto rw: ele){
                cout<<rw<<" ";
            }
            cout<<endl;
        }
    }

 // Leetcode 17: Letter combination of a phone no.
    # include <bits/stdc++.h>
    using namespace std;
        
    vector<string>ans;
    void solve(string digits,string curr_str,int idx,unordered_map<char,string>&mp){
        if(idx==digits.length()){
            ans.push_back(curr_str);
            return;
        }

        string str = mp[digits[idx]];
        for(int i=0; i<str.length(); i++){ 
            curr_str.push_back(str[i]);
            solve(digits,curr_str,idx+1,mp);
            curr_str.pop_back();
        }
    }

    int main(){
        string digits = "234";
        
        if(digits.empty()) return {};
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string curr_str;
        solve(digits,curr_str,0,mp);

        for(string st:ans){
            cout<<st<<" ";
        }
        
        return 0;
    }
