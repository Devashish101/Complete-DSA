# include <iostream>
# include <cmath> // for using sqrt fun  # include <cmath> // for using sqrt fun
using namespace std;

//int main(){
// bitwise operator :
// operator works according to their truth table of binary no.s.

    // int a=4;
    // int b=6;
    // cout<<"a&b:"<<(a&b) <<endl;//and operator
    // cout<<"a|b:"<<(a|b)<<endl;//or operator
    // cout<<"~a:"<<(~a)<<endl;//not operator
    // cout<<"a^b:"<<(a^b)<<endl;//xor operator

// right shift operator">>" , and left shift operator "<<"
// for smaller numbers right shift operator divides the number by 2 ,and left shift operator multiply the number by 2

    // cout<<(17>>1)<<endl;//read as apply right shift operator 1 time on 17.
    // cout<<(17>>2)<<endl;//read as apply right shift operator 2 time on 17.
    // cout<<(19<<1)<<endl;//read as apply left shift operator 1 time on 19.
    // cout<<(19<<2)<<endl;//read as apply left shift operator 2 time on 19.

// pre and post increment(++) and decrement(--) operator

    // int i=5;
    // cout<<"value of i:"<<++i<<endl;//6
    // cout<<"value of i:"<<i++<<endl;//6,7
    // cout<<"value of i:"<<i--<<endl;//7,6f
    // cout<<"value of i:"<<--i<<endl;//5

// fibonnaci series 01123581321
//     int a=0;
//    int b=1;
//    int n, sum;
//    cout<<"enter N:";
//    cin>>n;
//     cout<<a<<" "<<b<<" ";
//    for(int i=1;i<=n;i++){
//     sum=a+b;
//     cout<<sum<<" ";
//     a=b;
//     b=sum;
//    }

// prime numbers
    // int n;
    // cout<<"n:";
    // cin>>n;
    // bool isprime=1;
    // for(int i=2; i<n; i++){
    //    if(n%i==0){
    //     isprime=0;
    //     break;
    //    }
    // }
    // if(isprime==0){
    //     cout<<"it is not a prime number";
    // }
    // else{
    //     cout<<"it is a prime number";
    // }

    
     bool isprime(int num, bool flag){
      for(int i = 2; i<sqrt(num); i++){ // much optimized than previous one
        if(num%i == 0){
          flag = false;
        }
      }
      return flag;
     }
    
    int main(){
      
      int num;
      int flag = true;
    
      cout<<"Enter your No. :";
      cin>>num;
    
      bool result = isprime(num,flag);
      if(result == true){
        cout<<"prime";
      }
      else{
        cout<<"Not prime";
      }
    }
    
   