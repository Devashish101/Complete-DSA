// **************************Pointer Arithmetic****************
# include <iostream>
using namespace std;

int main(){

    //TODO: 1. Increment and Decrement Operator ptr++ , ++ptr , ptr-- , --ptr
    int x = 5;
    int *ptr = &x; //integer pointer has size of 4 bytes
    
    cout<<ptr<<"\n";
    ptr++;
    // cout<<ptr<<"\n";

    ptr--;
    // cout<<ptr<<"\n";

    // TODO: 2. Addition and SUbtraction of Constants : ptr+3, ptr-3
    ptr =  ptr+3; // address of ptr + 3 * 4 : since integer pointer has a size of 4 bytes
    // cout<<ptr<<"\n"; // => address of ptr + 12 (in hexadecimal) 
    
    ptr = ptr-3;
    // cout<<ptr<<"\n";
      
     
    //TODO: 3. Addition And Subtraction Of Pointers
    // => ptr1 + ptr2 => Invalid OPeration
    // => ptr1 - ptr2 => valid only when Both are of same type

    int p = 10;

    int *ptr1  = &p;
    int *ptr2 = ptr1+3;

    // cout<<ptr1<<"\n";
    // cout<<ptr2<<"\n";
    // cout<<ptr2-ptr1<<"\n"; // 3 => means space between ptr1 and ptr2 is of 3integer bytes i.e 3*4 = 12 bytes

    // 4. Comparision OPerators in Pointers
    cout<<(ptr1==ptr2)<<"\n"; // false //0
    cout<<(ptr1<ptr2)<<"\n"; // true //1

    //TODO: => Applying POinter Arithmetic on the Elements of an Array 
    int arr [] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *ptr_1 = arr;
    int *ptr_2 = ptr_1+3;
    // cout<<ptr_2 - ptr_1<<"\n";

    cout<<(ptr_1 == arr)<<"\n"; // true // 1
    cout<<(ptr_2<ptr_1)<<"\n"; // false // 0

    for(int i=0; i<n; i++){
        // cout<<*(arr+i)<<","; // as *arr = 0 since arr points to the addrss of 1st element of an Array 
    } 
    
    
    return 0;
}