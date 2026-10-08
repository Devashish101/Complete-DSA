//**************************************************SCOPE IN ARRAYS*********************************************************************
# include <iostream>
using namespace std;

void update( int arr[] , int size){
    cout<<"inside the update function"<<endl;
        //updating the array 1st element
        arr[0]=120;
        //printing the elements of array
      for(int i=0; i<size; i++){
        cout<<arr[i]<<" "<<endl;
      }
    cout<<"going back to the main function"<<endl;
}
int main(){
    int size;
    cout<<"value of size is:";
    cin>>size;
    int arr[100];
    update(arr, size);
    //printing the elements of array
        for(int i=0; i<size; i++){
        cout<<arr[i]<<" "<<endl;
    }
    return 0;
}//conclusion: if we update the element of array in another function then original array will also get updated because in case of array we send the address of the array to the function instead of sending copy of the array.

//******************************************************program on linear search*************************************
# include <iostream>
using namespace std;

bool search(int arr[], int n , int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            return 1;
        }
    }
            return 0;
}

int main(){
    int key;
    cout<<"the key you want to search  is :";
    cin>>key;
    int arr[10]={1,23,45,5,-9,4,2,11,6,7};
    search(arr , 10 ,key);
    int found = search(arr , 10 ,key);
    if(found==1){
        cout<<"key is founded";
    }
    else{
        cout<<"key is  not founded";
    }
    return 0;
}


//******************************************program to reverse an array**************************************
# include <iostream>
using namespace std;

void reverse( int arr[], int n){
    int start=0;
    int end=n-1;
    while(start<=end){
      swap(arr[start], arr[end]);
      start++;
      end--;
    }
     cout<<"the reverse of your array is"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
   int arr[5]={11,25,53,42,-15} ;
   reverse(arr, 5); 
   return 0;
}

// **************************************************program to extreme print in array is :- ************************************
# include <iostream>
using namespace std;

int main(){
  int right=5;
  int left=0;
  int arr[6]={10,20,30,40,50,60};
  cout<<"extreme print in an array is :"<<endl;  // 10,60,20,50,30,40
  while(left<=right){
    if(left==right){
      cout<<arr[left];
    }
    else{
      cout<<arr[left]<<" ";
      cout<<arr[right]<<" ";
    }
    left++;
    right--;
  }
  cout<<endl;
  cout<<"Thankyou";
  return 0;
}

//******************************************/ printing the all possible sub-arrays of an array*************************************
# include <iostream>
using namespace std;

void index_subarr(int *arr, int n);
void printsubarr1(int *arr, int n);

int main(){
  int arr[5] = {1,2,3,4,5};
  int n = 5;
  // index_subarr(arr,n);
  printsubarr1(arr,n);

}

void index_subarr(int arr[], int n){
  for(int i=0; i<n; i++){    // start  index
    for(int j=i; j<n; j++){ // ending index
      cout<<"("<<i<<","<<j<<")";
    }
    cout<<"\n";
  }
}

void printsubarr1(int *arr, int n){
  for(int i=0; i<n; i++){  // start  index
    for(int j=i; j<n; j++){ //ending index
      for(int k=i; k<=j; k++){
        cout<<arr[k];
      }
      cout<<",";
    }
    cout<<"\n";
  }
}


//*****************************/ printing the max sub-array sum of an given array************************************
# include <iostream> 
using namespace std;

void maxsubarrsum(int arr[], int n);

int main(){
  int arr1[6] = {2,-3,6,-5,4,2};
  int n1 = 6;
  maxsubarrsum(arr1,n1);
}

void maxsubarrsum(int *arr, int n){
  int maxsum = INT16_MIN;
  for(int i=0; i<n; i++){  // start  index
    for(int j=i; j<n; j++){ //ending index
      int sum = 0; // reset sum after each row of possible subarray
      for(int k=i; k<=j; k++){
        sum+=arr[k];
      }
      cout<<sum<<",";
      maxsum = max(maxsum,sum);
    }
    cout<<"\n";
  }
  cout<<"max sum of array will be :"<<maxsum;

}

// *************************************printing the max sub-array sum of an given array************************
# include <iostream> 
using namespace std;

void maxsubarrsum(int arr[], int n);
void maxsubarrsum1(int arr[], int n);
void maxsubarrsum2(int arr[], int n);

int main(){
  int arr[6] = {2,-3,6,-5,4,2};
  int n = 6;
  // maxsubarrsum(arr,n);
  // maxsubarrsum1(arr,n);
  maxsubarrsum2(arr,n);
}

void maxsubarrsum(int *arr, int n){
  int maxsum = INT16_MIN;
  for(int i=0; i<n; i++){  // start  index
    for(int j=i; j<n; j++){ //ending index
      int sum = 0; // reset sum after each row of possible subarray
      for(int k=i; k<=j; k++){
        sum+=arr[k];
      }
      cout<<sum<<",";
      maxsum = max(maxsum,sum);
    }
    cout<<"\n";
  }
  cout<<"max sub-arr sum  will be :"<<maxsum;

}

void maxsubarrsum1(int *arr, int n){
  int maxsum = INT16_MIN;
  for(int i=0; i<n; i++){  // start  index
    int currsum = 0;
    for(int j=i; j<n; j++){ //ending index
      currsum += arr[j];  // reset sum after each row of possible subarray
      maxsum = max(currsum , maxsum);
    }
    cout<<"\n";
  }
  cout<<"max sum of array will be :"<<maxsum;
}

void maxsubarrsum2(int arr[], int n){
  int maxsum = INT16_MIN;
  int currsum = 0;
  for(int i=0; i<n; i++){
    currsum += arr[i];
    maxsum = max(currsum,maxsum);
    if(currsum < 0){
      currsum = 0;
    }
  }
  cout<<"max sub-array sum will :"<<maxsum;
}