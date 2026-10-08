// Array level 2

// TODO:******************************BUY AND SELL STOCKS*************************************************************
# include <iostream>
using namespace std;

void maxprofit(int prices[], int n){
    int bestbuy[100000];
    bestbuy[0]=INT16_MAX;

    for(int i=1; i<n; i++){
        bestbuy[i]=min(bestbuy[i-1],prices[i-1]);
    }

    int maxprofit = 0;
    for(int i=0; i<n; i++){
        int currprofit = (prices[i]-bestbuy[i]);
        maxprofit = max(currprofit,maxprofit);
    }

    cout<<"Maximum profit will be :"<<maxprofit;
}

int main(){
    int prices[6]={7,1,5,3,6,4};
    int n = sizeof(prices)/sizeof(prices[0]);
    maxprofit(prices,n);
     
    return 0;
}

// *****************************************Trapped Rainwater*************************************************
# include <iostream> 
using namespace std;

void trapwater(int *height, int n){
    int leftmax[20000];
    int rightmax[20000];

    leftmax[0]=height[0];
    rightmax[n-1]=height[n-1];

    for(int i=1; i<n; i++){
        leftmax[i] = max(leftmax[i-1],height[i-1]);
    }

    for(int i=n-2; i>=1; i--){
        rightmax[i] = max(rightmax[i+1],height[i+1]);
    }

    int watertrap = 0;
    for(int i=0; i<n; i++){
        int currwater = min(leftmax[i],rightmax[i])-height[i];
        if(currwater > 0){
            watertrap += currwater;
        }
    }
    cout<<"Total amount of water traped :"<<watertrap;
}

int main(){
  int height[7] = {4,2,0,6,3,2,5};
  int n = sizeof(height)/sizeof(height[0]);
  trapwater(height,n);
}


//program to find unique element of an array =>
# include <iostream>
using namespace std;

int unique(int arr[], int n){
    int unique = 0;
    for(int i = 0; i<n ; i++){
      unique = unique^arr[i];
    }
    return unique;
}

int main(){
  int n=11;
  int arr[11]={11,12,10,11,12,15,18,13,10,13,18};
  int ans = unique(arr , n);
  cout<<" unique element of an array is :"<<ans<<endl;
  return 0;
}


//program to print doublet pairs of an elements of an array =>
# include <iostream>
using namespace std;

int doublet(int arr[], int n){
    for(int i=0; i<n; i++){
      for (int j=0; j<n ; j++){
        cout<<"("<<arr[i]<<" ,"<<arr[j]<<")"<<endl;
      }
    }
}

int main(){
  int n=5;
  int arr[5]={10, 20 ,30, 40, 50} ;
  doublet(arr , n);
  return 0;
}


//progrm to print triplet pairs of an array
# include <iostream>
using namespace std;
int main(){
    int n=3;
    int arr[]={1, 2, 3};
    for (int i=0 ; i<n; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<n; k++){
                cout<<"("<<arr[i]<<" ,"<<arr[j]<<", "<<arr[k]<<")"<<endl;
            }
        }
    }
    return 0;
}

//program to sort all zeroes and ones in an array of having elements 1 and 0.
# include <iostream>
using namespace std;

void sortZeroOne(int arr[] ,int n){
  //counting total no. of zeroes and one
    int countzero=0;
    int countone=0;
    for (int i=0; i<n ; i++){
        if(arr[i]==0){
          countzero++;
        }
        else
          countone++;
    }
    // placing all zeroes at first
     int j=0;
     while(countzero--){
        arr[j]=0;
        j++;
     }
    // placing  all ones after zero
    while(countone--){
      arr[j]=1;
      j++;
    }
}
    // printing array after sorting
void printarray(int arr[], int n){
  for (int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
    int n=6;
    int arr[6]={1,0,0,0,1,0};
    sortZeroOne(arr , n);
    printarray(arr ,n);
  return 0;
}

//program to shift an array by index 1 =>
# include <iostream>
using namespace std;

void shift(int arr[] ,int n){

    int temp=arr[n-1];
    for (int i=n-1; i>=1 ; i--){
        arr[i]=arr[i-1];
    } 
        arr[0]=temp;
}
    // printing array after shifting by index 1
void printarray(int arr[], int n) {
  for (int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
    int n=6;
    int arr[6]={10,20,30,40,50,60};
    shift(arr , n);
    printarray(arr ,n);
  return 0;
}
