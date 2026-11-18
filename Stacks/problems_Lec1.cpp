# include <bits/stdc++.h>
using namespace std;

/// Stack is pass by reference Data Structure✅
void printstack(stack<int> &st){ 
    stack<int>temp;
    while(st.size()>0){
        cout<<st.top()<<" ";//Printing the elements in top->bottom order
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    while(temp.size()>0){
        // cout<<temp.top()<<" ";//Printing the elements in bottom->top order
        st.push(temp.top());
        temp.pop();
    }
}

// Push the element at the bottom of stack 
void pushatBottom(stack<int> &st,int ele){
    stack<int> extra;
    while(st.size()>0){
        extra.push(st.top());
        st.pop();
    }
    st.push(ele);
    while(extra.size()>0){
        st.push(extra.top());
        extra.pop();
    }
    printstack(st);
}

// Push the element at a given idx of stack from bottom
void pushatidx(stack<int> &st,int idx ,int ele){
    stack<int> extra;
    while(st.size()>idx){
        extra.push(st.top());
        st.pop();
    }
    st.push(ele);
    while(extra.size()>0){
        st.push(extra.top());
        extra.pop();
    }
    printstack(st);
}

// Reverese the stack using 3 stacks(st,rt and gt) Iterative Method
void reversest(stack<int> &st){
    stack<int>gt;
    stack<int>rt;

    while(st.size()>0){
        gt.push(st.top());
        st.pop();
    }

    while(gt.size()>0){
        rt.push(gt.top());
        gt.pop();
    }

    while(rt.size()>0){
        st.push(rt.top());
        rt.pop();
    }
    printstack(st);
}

void displayrec(stack<int> &st){
    if(st.size()==0) return;
    // cout<<st.top()<<" ";// this is for simple display
    int x = st.top();
    st.pop();
    displayrec(st);
    st.push(x);
    cout<<st.top()<<" ";// this is for reverse display
}

void pushatBottomRec(stack<int> &st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushatBottomRec(st,val);
    st.push(x);
}

void ReverseStRec(stack<int> &st){
    if(st.size()==1)return ;
    int x = st.top();
    st.pop();
    ReverseStRec(st);
    pushatBottomRec(st,x);
}

int main(){
    stack<int>st;
    cout<<st.size()<<"\n";
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    printstack(st);               // printing the stack iteratively
    displayrec(st);              // Displaying the Stack Recursively
    cout<<"\n";    

    pushatBottom(st,-10);      // Inserting new element at the bottom of stack
    pushatBottomRec(st,-11);  // Inserting new element at the bottom of stack using recursion
    printstack(st);

    pushatidx(st,2,15);  //Inserting new element at the given idx of the stack
    reversest(st);      // Reversing the Stack iteratively
    ReverseStRec(st);  // Reversing the Stack Recursively
    printstack(st);
}


