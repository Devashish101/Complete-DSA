# include <bits/stdc++.h>
using namespace std;

// print the nth Fibonacci term using Recursion
int fibo(int n){
    if(n==1 || n==2) return 1;
    return fibo(n-1)+fibo(n-2);
}

// print x to the power n in logarithmic time Complexity
int pow(int x,int n){
    if(n==1) return x;
    int ans;
    if(n%2==0){
        ans = pow(x,n/2);
        return ans*ans;
    }
    else{
        ans = pow(x,n/2);
        return ans*ans*x;
    }
}

int main(){
    // 1 1 2 3 5 8 13 21 34 55 ...
    cout<<fibo(8);
    cout<<pow(2,25);
}

// print No. of Ways in which we can climb n stairs if we can only take either 1 or 2 steps at a time
int stair(int n){
    // Base case
    if(n==1) return 1;
    if(n==2) return 2;

    // code + Recursive call
    int ans = stair(n-1)+stair(n-2);

    return ans;
}

int main(){
    cout<<stair(4);
}

// Find the no. of ways in which we can reach to the destination in a maze matrix by only going either right or down 
# include <bits/stdc++.h>
using namespace std;

int maze(int sr,int sc,int er, int ec){
    if(sr>er || sc>ec) return 0;
    if(sr==er && sc==ec) return 1;
    
    int rightwards = maze(sr,sc+1,er,ec);
    int downwards = maze(sr+1,sc,er,ec);

    int Totalways = rightwards+downwards;
    return Totalways;
}

int maze2(int sr,int sc){
    if(sr<1 || sc<1) return 0;
    if(sr==1 && sc==1) return 1;
    
    int rightwards = maze2(sr,sc-1);
    int downwards = maze2(sr-1,sc);

    int Totalways = rightwards+downwards;
    return Totalways;
}

void mazepath(int sr,int sc,int er, int ec,string S){
    if(sr>er || sc>ec) return;
    if(sr==er && sc==ec){
        cout<<S<<endl;
        return;
    }
    mazepath(sr,sc+1,er,ec,S+"R");
    mazepath(sr+1,sc,er,ec,S+"D");
}

int main(){
   cout<< maze(1,1,5,5);
   cout<< maze2(5,5);
   mazepath(1,1,5,5,"");
}

// print zig-zag of n or pre, in and post of n by using the concept of Recursion tree
# include <bits/stdc++.h>
using namespace std;

void pip(int n){
    if(n==0) return;
    cout<<"pre"<<n<<"\n";
    pip(n-1);
    cout<<"in"<<n<<"\n";
    pip(n-1);
    cout<<"post"<<n<<"\n";
}

void zigzag(int n){
    if(n==0) return;
    cout<<n;
    zigzag(n-1);
    cout<<n;
    zigzag(n-1);
    cout<<n;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    pip(n);
    zigzag(n); 
}
