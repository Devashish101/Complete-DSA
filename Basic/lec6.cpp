// leetcode problem 1 : to find product - sum of a given no.
        // # include <iostream>
        // using namespace std;
        
        // int main(){
        // int n;
        // cin>>n;
        // int prod=1;
        // int sum=0;
        // int result;
        // while(n!=0){
        // int digit=n%10;
        // prod =prod*digit;
        // sum =sum+digit;
        // n=n/10;
        // }
        // result=prod-sum;
        // cout<<"result will be:" <<result;
        // return 0;
        // }

//leet code problem 2: =>decimal to binary conversion
      # include <iostream>
      # include <math.h>
      using namespace std;

      int main (){
        int n;
        cout<<"Enter the value of n:";
        cin>>n;
        int ans = 0;
        int i = 0;

        while(n != 0){
            int bit = n & 1;
            ans = (bit * pow(10, i))+ans;
            n = n >> 1;
            i++;
        }
        cout<<"answer is "<<ans;
        return 0;
      } 

// problem 3 => binary to decimal conversion
  # include <iostream>
  # include <math.h>
  using namespace std;

    int main(){
        int n;
        cin>>n;
        //1010 input
       int i = 0;//1//2//3
       int ans = 0;
        while(n!=0){//n=101//10//1
           int digit = n % 10;
             if(digit == 1){
              ans = (ans +  pow(2, i));//2+8
            }
            n = n/10;//101//10//1
            i++;
        }
        cout<<ans<<endl;
        return 0;
   }
// program to find the first And Last digit of a number
# include <iostream>
using namespace std;
int main(){
    
    int n;
    cout<<"Enter the Number :";
    cin>>n;

    int lastDigit = n%10;
    while (n>9){
        n = n/10;
    }
    int firstDigit = n;

    cout<<"First digit of n is :"<<firstDigit<<"\n";
    cout<<"Last digit of n is :"<<lastDigit<<"\n";
    
    return 0;
}