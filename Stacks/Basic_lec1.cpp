# include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int>st;
    cout<<st.size()<<"\n";
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.size()<<"\n";
    st.pop();
    cout<<st.size()<<"\n";
    cout<<st.top()<<"\n";
    st.push(40);
    st.push(50);

    // Printing the elements & thereafter Losing all the elements
    // while(st.size()>0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    // Printing the elements without Losing all the elements(by using extra stack)
    stack<int>temp;
    while(st.size()>0){
        // cout<<st.top()<<" "; //Printing the elements in top->bottom order 
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    // Putting back all the elements in our original stack
    while(temp.size()>0){
        cout<<temp.top()<<" ";//Printing the elements in bottom->top order
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl<<st.size()<<"\n";


}