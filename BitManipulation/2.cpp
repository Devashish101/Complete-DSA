# include <iostream>
using namespace std;

// Update the IthBit of a No. with given Value
int updateIthBit(int num, int i, int val){
    num = num & ~(1<<i);

    num = num | (val<<i);

    cout<<num<<"\n";
}

// Clear the Last i bits of a Number
void clearLastibits(int num, int i){
    int Bitmask = (~0)<<i;
    num = num & Bitmask;
    cout<<num;
}

// Count The No. of Set Bits in a binary form of a given decimal number
int countSetBits(int num){
    int count = 0;

    while(num > 0){
        int lastdigit = num & 1;
        count += lastdigit;

        num = num>>1;
    }
    return count;
}

int main(){
    
    // int num, i, val;
    // cin>>num>>i>>val;

    // updateIthBit(num,i,val);
    // clearLastibits(num, i);
    // cout<<countSetBits(7);

    return 0;
}

//                          Fast Exponentiation(or exponentiation by squaring Technique)
# include <iostream>
using namespace std;

int fastExpo(int x, int n){
    int ans = 1;

    while(n > 0){
        int lastBit = n & 1;
        if(lastBit == 1){
            ans = ans * x;
            x = x*x;
        }
        else{
            x = x*x;
        }
        n = n>>1;
    }
    
    return ans;
}

int main(){
    cout<<fastExpo(3,5); 
    return 0;
}