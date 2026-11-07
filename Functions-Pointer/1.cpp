//  Functions

//program 1 power function:
// # include <iostream>
// using namespace std;

// int power(int a, int b){
//     int ans = 1;
//     for( int i=0 ;i<b ; i++){
//         ans = ans*a;
//     }
//     return ans;
// }

// int main(){
//     int a, b;
//     cin>> a >> b;
//     int answer = power(a,b);
//     cout<< "answer is :"<<answer;
//     return 0;
// }

// program 2 even or odd
// # include <iostream>
// using namespace std;

// bool numberchecker(int num){
//        int res;
//         if(num%2==0){
//          res=1;
//         }
//         else{
//          res=0;
//         }
//         return res ;
// }

// int main(){
//     int num;
//     cout<<"The value of num is:";
//     cin>>num;
//     int result;
//     result= numberchecker(num);
//     if(result==1){
//         cout<<"The no. is even:";
//     } 
//     else{
//         cout<<"The no. is odd";
//     }
//     return 0;
// }

// program 3 To calculate nCr = n!/(r!*(n-r)!)
// # include <iostream>
// using namespace std;

// int factorial(int num){
//     int fact = 1;
//     for (int i=1; i<=num; i++){
//         fact = fact*i;
//     }
//     return fact;
// }

// int nCr(int n, int r){
//     int numerator = factorial(n);//numerator = n!
//     int denomenator =factorial(r) * factorial(n-r);//denominator = (r!*(n-r)!)
//     // int result = num/denom;
//     return numerator/denomenator;
// }

// int main(){
//      int n, r;
//      cin>> n >> r ;
//      cout<<"The answer is :"<< nCr(n,r);
//     return 0;
// }

// program 4 To print counting
// # include <iostream>
// using namespace std;

// void printcounting(int n){
//         for(int i=1; i<=n; i++){
//           cout<<i<<" ";  
//         }
// }

// int main(){
//     int n ;
//     cin>>n;
//     printcounting(n); 
//     return 0;
// }

// program 5 To check wheather given no. is prime or not
# include <iostream>
using namespace std;

bool isprime(int n){
      for(int i=2; i<n; i++){
        if(n%i==0){
        return 0;
        }
      }
        return 1;
    }

int main(){
    int n;
    cin>>n;
    isprime(n);
    if(isprime(n)==1){
    cout<<"It is a prime number ";
    }
    else{
    cout<<"It is not a prime number ";
    }
    return 0;
}