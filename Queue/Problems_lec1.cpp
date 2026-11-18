// Ques: Remove the Ele Prsent at Even Idx.
# include <bits/stdc++.h>
using namespace std;

void RemoveEven(queue<int> &qu){
    int n = qu.size();
    for(int i=0; i<n; i++){
        if(i%2==0){
           qu.pop(); 
        }
        else{
            int x = qu.front();
            qu.pop();
            qu.push(x);
        }  
    }
    cout<<"\n";
}

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

  
int main(){
    queue<int>qu;
    qu.push(11);
    qu.push(12);
    qu.push(13);
    qu.push(14);
    qu.push(15); 
    qu.push(16); 
    display(qu);
    RemoveEven(qu);
    display(qu);

    return 0;
}