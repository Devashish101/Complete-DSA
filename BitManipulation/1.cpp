# include <iostream>
using namespace std;

int main(){
    //=>  BItwise Operator

    // 1. Bitwise AND &
    cout<<(3 & 5)<<"\n";
    // 2. Bitwise OR |
    cout<<(3 | 5)<<"\n";
    // 3. Bitwise XOR ^
    cout<<(3 ^ 5)<<"\n";
     
    // 4.Bitwise NOT ~ (1's Complement) 
    cout<<(~6)<<"\n"; //-7
    cout<<(~0)<<"\n"; //-1

    // => Binary Shift Operator 

    // 1. Left Shift << (a<<b = a*2^b)
    cout<<(7<<2)<<"\n";

    // 2.Right Shift >> (a>>b = a/2^b)
    cout<<(7>>2)<<"\n";

    return 0;
}

// Code to swap two numbers
# include<iostream>
using namespace std;

int main(){
    int a = 5, b = 7;

    cout<<"Numbers Before swap are :"<<a<<" "<<b<<"\n";
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<"Numbers After swap are :"<<a<<" "<<b<<"\n";
}

// TODO:Check if Odd or Even
# include <iostream>
using namespace std;

int main(){
    
    int num;
    cout<<"Enter the number \n";
    cin>>num;

    if((num & 1) == 1){
        cout<<"Given No. is  Odd \n";
    }
    else{
        cout<<"Given No. is  Even  \n";
    }

    return 0;
}

#include <iostream>
using namespace std;

//                                   (Get ith Bit)Creating a bitmask for finding a specific bit in a number 

int getithBit(int num, int i) {
    int bitMask = 1 << i;

    if ((num & bitMask) == 0) {  // i-th bit of num (0-indexed from right)
        return 0;
    } else {
        return 1;
    }
} 

//                                   (Set ith Bit)Creating a bitmask to setting (0=>1 , 1=>1) a specific bit in a number 
int SetithBit(int num, int i) {

    int bitMask = 1 << i;
    return (num | bitMask);
    
} 

//                                   (Clear ith Bit)Creating a bitmask for Clearing i.e(0=>0 , 1=>0) a specific bit in a number 
int ClearithBit(int num, int i){
    int bitmask = ~(1<<i);
    return(num & bitmask);
}

int main() {
    int num, bit;
    cout << "Enter the number and the bit position:\n";
    cin >> num >> bit;

    // cout << getithBit(num, bit);
    // cout << SetithBit(num, bit);
    cout << ClearithBit(num, bit);
    return 0;
}

//                                                               Check for Power of 2
# include <iostream>
using namespace std;

bool isPowerof2(int num){
    if(num & (num-1) == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
    int num;
    cout<<"Enter your number \n";
    cin>>num;

    bool res = isPowerof2(num);
    if(res == true){
        cout<<num <<" is a power of 2 \n";
    }
    else{
        cout<<num <<" is not a power of 2 \n";
    }
    return 0;
}