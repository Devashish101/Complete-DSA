// ARRAYS
# include <iostream>
using namespace std;

int main (){

//    it will give garbage value since our size of arry is 5 but are asking 11th index 
    int array[5];
    cout <<"value at 11th index is :"<< array[11] << endl;

//  finding size of an array and address of an array
    int arr[5]={1,2,3,4};
    cout<<"size of arr is :"<<sizeof(arr)<<endl;/* 4*5=20 */
    cout<<"base address of arr is "<<&arr<<"\n";
    cout<<"address of element of arr at 2nd index is"<<&arr[2]<<endl;

//  it will  give correct value
    int brr[5]={2,4,6,8,10};
    cout<<"value at index 4 is :"<<brr[4]<< endl;

//  printing all  the elements of array using loop
    int third[15]={2,7};
    int n=15;
    for(int i=0; i<15; i++){
        cout<<third[i]<<" ";
    }
    cout<<endl;

// intializing  all location of the array with 0
    int fourth[10]={0};
    int x=10;
    for(int i=0; i<x; i++){
        cout<<fourth[i]<<" ";
    }
    cout<<endl;

    cout<< "everything is working fine";

return 0;
}

// Accesing the Array using pointers
# include <iostream>
using namespace std;
int main(){
    
    int arr[]= {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]); /*length of the array*/

    cout<<arr<<endl; // it will return the base add. of my arr

    cout<<arr[0]<<endl;
    cout<<*arr<<endl; // it will return value stored at 0th index in my arr using Derefencing
    cout<<*(arr+1)<<endl; // it will return value stored at 1st index in my arr using Derefencing

    return 0;
}


// printing the array using functions
# include <iostream>
using namespace std;

void printarray(char arr[] , int n){
    cout<<"printing the array"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    char arr[5]={'a','b','c','d','e'};
    printarray(arr, 5);
    return 0;
}

// printing and taking input in array using functions and pointers
# include <iostream>
using namespace std;

void input(int *arr, int n){  // making arr pointer as variable by doing *arr 
   for(int i=0; i<n; i++){
       cin>>arr[i];
    }
}

void printarray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"value of n is:";
    cin>>n;
    int arr[n];
    input(arr, n);
    printarray(arr, n); //arr itself stores base adds. of an array thats why we not need &arr
    return 0;
}

//finding the minimum and maximum element of an array
# include <iostream>
using namespace std;

//taking input in array
void input(int arr[], int size){
   for(int i=0; i<size; i++){
       cin>>arr[i];
    }
}

//printing the elements of array
void printarray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

//for max element of array
int maxelement(int arr[], int size){
    int maximum=INT8_MIN;
    for(int i=0; i<size; i++){
        maximum = max(maximum, arr[i]);//max is a pre defined function to find maximum 
        // if(arr[i] > maximum){
        //     maximum = arr[i];
        // }
    }
        return maximum;
}

//for min element of array
int minelement(int arr[], int size){
    int minimum=INT8_MAX;
    for(int i=0; i<size; i++){
        minimum=min(minimum, arr[i]);//min is also a pre defined function to find minimum
        // if(arr[i] < minimum){
        //     minimum = arr[i];
        // }
    }
        return minimum;
}

int main(){
    int size;
    cout<<"value of size is:";
    cin>>size;
    int arr[100];
    input(arr, size);
    printarray(arr , size);
    maxelement(arr , size);
    cout<<endl;
    cout<<"max element is" << maxelement(arr , size)<<endl;
    cout<<"min element is" << minelement(arr , size);
    return 0;
}

//program to printing the sum of elements of an array and
//program to printing the elements of an array after doubling up their each element
# include <iostream>
using namespace std;

int main(){
  int sum=0;
  int n=5;
  int arr[5];
  for (int i=0 ; i<n ; i++){
      cout<<"element at index "<<i<<":";
      cin>>arr[i];
      sum=sum+arr[i];
    }
   cout<<"sum of elements of an array is :"<< sum << endl;
   cout<<"printing the elements of an array after doing the double of each element :";
   for (int i=0 ; i<n ; i++){
    arr[i]=2*arr[i];
    cout<<arr[i]<<" ";
  }
  
    return 0;
}

//program to find total number of zeroes and ones in an array
# include <iostream>
using namespace std;

int main(){
  int arr[]={1,1,0,0,1,1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,1};
  int zero=0;
  int one=0;
  for (int i=0; i<21; i++){
      if(arr[i]==0){
        zero+=1;
      }
      else{
        one+=1;
      }
  }
  cout<<"total number of zeroes in array is :"<<zero<<endl;
  cout<<"total number of ones in array is :"<<one<<endl;
  cout<<"Thankyou";
  return 0;
}


