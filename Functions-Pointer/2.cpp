# include <iostream>
using namespace std;

void changevar(int y);
void changevar2(int *ptr);
void changevar3(int &b);

int main(){

    // TODO: (&) Address of Operator
    int x = 45;
    // cout<<"address of x is :"<<&(x)<<"\n";

    // TODO: pointers
    int *ptr1;
    // cout<<ptr1<<"\n"; //gives an garbage value

    int a = 10;
    int *ptr = &a;
    // cout<<&a<<" = "<<ptr<<"\n";

    // float b = 4;
    // float *ptr = &b;
    // cout<<&b<<" = "<<ptr1<<"\n";
    
    int **pptr = &ptr; // address of pointer variable , it(**pptr) is "8" bytes in size
    // cout<<&ptr<<" = "<<pptr<<"\n";

    //TODO: Dereference Operator in pointers
    int z = 15;
    int *ptr2 = &z;

    // cout<<*(&z)<<"\n"; // value of variable stored at the given pointer address
    // cout<<*ptr2<<"\n";

    *ptr2 = 20;
    // cout<<z<<"\n";

    int *ptr3 = NULL;  // Initializing the pointer variable with null;
    // cout<<ptr3<<"\n"; 
    
    // TODO: passing Arguments
    // 1. Pass by value
    int var  = 20;
    cout<<"IN Pass by value"<<"\n";
    changevar(var);
    cout<<"Value of var Outside the functione is "<<var<<"\n";
    cout<<"\n";

    // 2. pass by Reference using pointers
    cout<<"In Pass by Reference using pointers"<<"\n";
    changevar2(&var);
    cout<<"Value of var Outside the functione is "<<var<<"\n";
    cout<<"\n";

    // 3. pass by Reference using Reference Variable
    cout<<"In Pass by Reference using Reference Variable "<<"\n";
    changevar3(var);
    cout<<"Value of var Outside the functione is "<<var<<"\n";
    cout<<"\n";

    ///**************************Practice time **************************************** */
    // 1. What will be ptr 2 point to the following code
        int p = 5;
        int q = 10;
        int *ptr_1 = &p;
        // cout<<ptr_1<<" "<<&p<<"\n";
        int *ptr_2 = &q;
        ptr_2 = ptr_1;
        // cout<<ptr2;

    return 0;

}

//  By call by value
void changevar(int y){
    y = 25;
    cout<<"value of var inside fun "<<y<<"\n";
}

// By call by reference using Pointers
void changevar2(int *ptr){
    *ptr = 25;
    cout<<"value of var inside fun "<<*ptr<<"\n";
}

// By call by reference using Reference Variable
void changevar3(int &b){
    b = 25;
    cout<<"value of var inside fun "<<b<<"\n";
}


