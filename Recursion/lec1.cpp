// Function Calling Itself
# include <bits/stdc++.h>
using namespace std;

void greet(int n){
    if(n==0) return;
    cout<<"Good Morning\n";
    greet(n-1);

}

// Factorial of n using recursion
int  Factorial(int n){
    // Base Case
    if(n==1 || n==0) return 1 ;
    // code and Recursive Call
    int ans = n*Factorial(n-1);
    // Return
    return ans;
}

// print No. from n to 1 using recursion 
void  print(int n){
    // Base Case
    if(n==0) return;
    //code
    cout<<n<<"\n";
    //Recursive call
    print(n-1);
}

// print No. from 1 to n using recursion and Extra Parameter
void  print(int i,int n){
    //Base Case
    if(i>n) return;
    //code
    cout<<i<<"\n";
    //Recursive call
    print(i+1,n);
}

// print No. from 1 to n only using recursion
void  print(int n){
    //Base Case
    if(n==0) return;
    // Recursive Call
    print(n-1);
    // code
    cout<<n<<endl;
}

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    greet(n);
    cout<<Factorial(n);
    print(n);
    print(1,n);
}

// print sum from 1 to n using recursion with and Without 2 Parameter
# include <bits/stdc++.h>
using namespace std;

void Sum1toN(int sum,int n){
    if(n==0){
        cout<<sum;
        return;
    } 
    Sum1toN(sum+n,n-1);
}

int Sum1toN(int n){
    if(n==0) return 0;
    int ans = n+Sum1toN(n-1);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    // Sum1toN(0,n);
    cout<<Sum1toN(n);
}

// print a raised to the power b using recursion
# include <bits/stdc++.h>
using namespace std;

int power(int x,int y){
    if(y==0) return 1;
    return x*power(x,y-1);
}

int main(){
    int a;
    cout<<"Enter the value of base : ";
    cin>>a;
    int b;
    cout<<"Enter the value of power : ";
    cin>>b;
    cout<<power(a,b);
}

