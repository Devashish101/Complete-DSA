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


void reverse(queue<int> &qu){
    stack<int>st;
    // Empty the Queue in Stack
    while(qu.size()>0){
        int x = qu.front();
        st.push(x);
        qu.pop();
    }
    // Empty the Stack in Queue 
    while(st.size()>0){
        int x = st.top();
        qu.push(x);
        st.pop();
    }
    display(qu);

}
    
int main(){
    // Oprtns:
    // 1. Push  - Only happens at back.
    // 2. Pop   - Only happens at front.
    // 3. front - For accesing the ele at front.
    // 3. back  - For accesing the ele at back.
    // 4. Size , 5. empty.
    queue<int>qu;
    qu.push(11);
    qu.push(12);
    qu.push(13);
    qu.push(14);
    qu.push(15); 
    display(qu);
    // cout<<qu.size()<<"\n";
    // cout<<qu.front()<<endl;
    qu.pop();
    // cout<<qu.size()<<"\n";
    // cout<<qu.back()<<"\n";
    // cout<<qu.empty()<<"\n";
    display(qu);
    reverse(qu);
    reverse(qu);
    return 0;
}