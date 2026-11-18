// Balanced Brackets
# include <bits/stdc++.h>
using namespace std;

bool BlcBrkts(string str){
    if(str.length()%2!=0) return false;
    stack<char>st;
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            if(st.size()==0) return false; 
            else st.pop(); //before using pop oprn make sure that there is an ele in stack otherwise it will give error that's why it should be in else case.
        }
    }
    if(st.size()==0) return true;
    else return false;
}
    
int main(){
    // string st = "()()()";
    string st = "())()(";
    cout<<BlcBrkts(st);
    return 0;
}

// Remove Consecutive Duplicates from a String
# include <bits/stdc++.h>
using namespace std;

string RemoveDup(string str){
    int n  = str.size();
    stack<char>st;
    st.push(str[0]);
    for(int i=1; i<str.size(); i++){
        char ch = str[i];
        if(st.top()==ch){
            st.pop();
            st.push(ch);
        }
        else{
            st.push(ch);
        }
    }
    string ans;
    while(st.size()!=0){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
    
int main(){
    string st = "aaabbcddaabffg";
    cout<<RemoveDup(st);
    return 0;
}

// Next Greater Element => Concept - pop , ans , Push and Reverse Traversal for Next Greater.
# include <bits/stdc++.h>
using namespace std;

vector<int> Nextgtr(vector<int>arr){
    int n = arr.size();
    stack<int> st;
    st.push(arr[n-1]);
    vector<int>ans(n,-1);
    for(int i=n-2; i>=0; i--){
        int ele = arr[i];
        // Pop all the Elements Smaller than arr[i]
        while(st.size()!=0 && ele>=st.top()){
            st.pop();
        }
        // Mark the ans in ans array
        if(st.size()!=0){
            ans[i] = st.top();
        }
        // Push the Element in Stack
        st.push(ele);   
    }
    return ans;
}
    
int main(){
   stack<int>st;
   vector<int> arr = {3,1,2,7,4,6,2,3};
   vector<int>ans = Nextgtr(arr);
   for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

// Previous Greater Element => Concept - pop , ans , Push and Normal Traversal for previous Greater.
# include <bits/stdc++.h>
using namespace std;

vector<int> prevgtr(vector<int>arr){
    int n = arr.size();
    stack<int> st;
    st.push(arr[0]);
    vector<int>ans(n,-1);
    for(int i=1; i<n; i++){
        int ele = arr[i];
        // Pop all the Elements Smaller than arr[i]
        while(st.size()!=0 && ele>=st.top()){
            st.pop();
        }
        // Mark the ans in ans array
        if(st.size()!=0){
            ans[i] = st.top();
        }
        // Push the Element in Stack
        st.push(ele);   
    }
    return ans;
}
    
int main(){
   stack<int>st;
   vector<int> arr = {3,1,2,7,4,6,2,3};
   vector<int>ans = prevgtr(arr);
   for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

//TODO: Stock Span Problem✅✅✅
# include <bits/stdc++.h>
using namespace std;

vector<int> prevgtr(vector<int>arr){
    int n = arr.size();
    stack<int> st;
    st.push(0);
    vector<int>ans(n,-1); 
    
    for(int i=1; i<n; i++){
        int ele = arr[i];
        // Pop all the idxes whose Elem is Smaller than arr[i]
        while(st.size()!=0 && ele>=arr[st.top()]){
            st.pop();
        }
        // Mark the idx in ans array
        if(st.size()!=0){
            ans[i] = st.top(); 
        } 
        // Push the idx in Stack
        st.push(i);   
    }
    for(int i=0; i<n; i++){
        ans[i] = i - ans[i];
    }
    return ans;
}
    
int main(){
   stack<int>st;
   vector<int> arr = {100,80,60,81,70,60,75,85};
   vector<int>ans = prevgtr(arr);
   for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}