// Leetcode 622:Design a circular Queue.
// Leetcode 1700:No. of Students unable to eat Lunch.
// Leetcode 232:Implement Queue using Stacks

// Reverse the 1st K Elements of the Queue.
# include <bits/stdc++.h>
using namespace std;

void display(queue<int> &qu){
    int n = qu.size();
    while(n>0){
        int x = qu.front();
        cout<<x<<" ";
        qu.pop();
        qu.push(x);
        n--;
    }
    cout<<"\n";
}

void reverse_ele(queue<int> &qu, int k){
    int s = qu.size();
    int n = k;
    stack<int>st;
    while(k!=0){
        int x = qu.front();
        st.push(x);
        qu.pop();
        k--;
    }
    while(st.size()>0){
        int x = st.top();
        qu.push(x);
        st.pop();
    }
    for(int i=0; i<s-n; i++){
        int x = qu.front();
        qu.pop();
        qu.push(x);
    }
}
    
int main(){
    queue<int>qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.push(6);
    display(qu);
    int k = 3;
    reverse_ele(qu,k);
    display(qu);
    return 0;
}


// 1st -ve in each window of size K.
# include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr = {3,-4,-7,10,8,-9,2,1,6,-5};
    int k = 3; // {-4,-4,-7,-9,-9,-9,0,-5} ans Array.

    int n = arr.size();
    vector<int>ans;
    queue<int>q;
    for(int i=0; i<n; i++){
        if(arr[i]<0) q.push(i);
    }

    for(int i=0; i<n-k+1; i++){
        while(q.size()>0 && q.front()<i) q.pop();
        if(q.size()==0 || q.front()>=i+k) ans.push_back(0);
        else ans.push_back(arr[q.front()]);
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}

// Reorder queue
# include <bits/stdc++.h>
using namespace std;

void display(queue<int> &qu){
    int n = qu.size();
    while(n>0){
        int x = qu.front();
        cout<<x<<" ";
        qu.pop();
        qu.push(x);
        n--;
    }
    cout<<"\n";
}

void reorder_ele(queue<int> &qu){
    int n = qu.size();
    stack<int>st;
    // 1. pop the 1st half ele of qu in stack.
    for(int i=0; i<n/2; i++){
        st.push(qu.front());
        qu.pop();
    }
    // 2. Empty the st and put the ele in qu agin.
    while(st.size()>0){
        qu.push(st.top());
        st.pop();
    }
    // 3. Again pop the new 1st half(which is basically the 2nd half of original qu) ele of qu in stack.
    for(int i=0; i<n/2; i++){
        st.push(qu.front());
        qu.pop();
    }
    // 4. Most Imp Interleaf the ele one by one from st and qu.
    while(st.size()>0){
        qu.push(st.top());
        st.pop();
        qu.push(qu.front());
        qu.pop();
    }
    // 5. Reverse the qu using our empty st.
    while(qu.size()>0){
        st.push(qu.front());
        qu.pop();
    }
    while(st.size()>0){
        qu.push(st.top());
        st.pop();
    }

}
    
int main(){
    queue<int>qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.push(6);
    qu.push(7);
    qu.push(8);
    display(qu);
    reorder_ele(qu);
    display(qu);
    return 0;
}
