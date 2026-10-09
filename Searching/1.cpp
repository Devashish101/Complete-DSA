//                                       Binary search level 1
# include <iostream>
using namespace std;

int Binarysearch(int arr[], int n, int target){
    int start=0;
    int end=n-1;
    while(start<=end){
        // creating mid
        // int mid = ( start + end )/2;//it can cause overflow
        int mid = start + (end-start)/2;//best practice

        // checking if element is found or not
        if(arr[mid]==target){
            return mid;
        }

        // going to right
        else if(target>arr[mid]){
            start=mid+1;
        }

        // going to left 
        else if(target<arr[mid]){
            end=mid-1;
        }
    }

    return -1;
}

int main(){
    int n=9;
    int arr[]={10,20,30,40,50,60,70,80,90};
    int target=190;
    int ans = Binarysearch(arr , n , target);
    if (ans == -1){
        cout<<"element not found";
     }
    else{
        cout<<"element found at index :"<<ans;
     }
    return 0;
}

// Lower Bound of an Element X in an Given Array
# include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]  = {1,2,4,5,9,15,18,21,24};
    int n = 9;
    int x = 12;

    int st = 0;
    int end = n-1;
    while(st<=end){
        int mid = st+(end-st)/2;

        if(arr[mid] == x){
            cout<< arr[mid-1];
            break;
        }
        else if(arr[mid]<x){
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<arr[end];

}

// program to find the  lastoccurence , firstoccurence and total occurence of the element also find the smallest missing non negative element 
# include <iostream>
using namespace std;

    int lastoccurence(int arr[], int n , int target){
    int start=0;
    int end=n-1;
    int ans=-1;
        while (start<=end){
            // int mid = (start+end)/2;//it can cause overflow
            int mid = start + (end-start)/2;//best practice

            if(arr[mid]==target){
                ans = mid;
                start = mid+1;//moving to right
            }

            // left side of mid
            else if (arr[mid]>target) {
                end = mid-1;
            }

            // right side of mid
            else if(arr[mid]<target){
                start = mid+1;
            }

        }

        return ans;       
}

    int firstoccurence(int arr[], int n , int target){
    int start=0;
    int end=n-1;
    int ans=-1;
        while (start<=end){
            // int mid = (start+end)/2;//it can cause overflow
            int mid = start + (end-start)/2;//best practice

            if(arr[mid]==target){
                ans = mid;
                end = mid-1;//moving to left
            }

            // left side of mid
            else if (arr[mid]>target) {
                end = mid-1;
            }

            // right side of mid
            else if(arr[mid]<target){
                start = mid+1;
            }

        }

        return ans;   
}

    int totaloccurence( int arr[], int n , int target){
    int last = lastoccurence(arr , n , target);
    int first= firstoccurence( arr, n , target);
    int total = (last-first)+1;
    return total;
}

    int missingelement(int arr[],int n){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
      int mid = s+(e-s)/2;
      int diff=arr[mid]-mid;

      if(diff==1){
        //right me jao
        s=mid+1;
      }

        else{
            ans=mid;
            //left me jao
            e=mid-1;
        }
    }
    return ans+1;
}


int main(){
    int n=8;
    int target=40;
    int arr[]={10,20,40,40,40,40,50,60};
    int arr1[]={1,2,4,5,6,7,8};
    
    int ans1 = firstoccurence(arr , n , target);
    if(ans1==-1){
        cout<<" element is not found";
    }
    else{
        cout<<"first occurence of an element is at index :"<<ans1;
    }

    int ans2 = lastoccurence(arr , n , target);
    if(ans2==-1){
        cout<<" element is not found";
    }
    else{
        cout<<"last occurence of an element is at index :"<<ans2;
    }

    int ans3 = totaloccurence(arr, n ,target);
    cout<<"total occurence of the element is :"<<ans3;

    int ans4 = missingelement(arr1,n);
    cout<<"missing element is"<<ans4;

    return 0;
}

//square  root  of given number using binary search
# include <iostream>
using namespace std;

    long long int squareroot(int n){
        //for integer part of the square root of the number
        int s=0;
        int e=n;
        long long int ans =-1;

        while(s<=e){
          int mid=s+(e-s)/2;

         long long int square=1LL*mid*mid;//1LL to avoid integer overflow

          if(square == n)
            return mid;

          else if (square<n){
            ans = mid;
            s=mid+1;
          }
          else{
            //when mid > square
            e=mid-1;
          }

        }
        return ans;
    }

    double decimalpart(int n, int upto_decimalplace ,int tempsol){
        //for decimal part of the square root of the number upto given decimalplace/precision
        double factor =1;
        double ans = tempsol;

        for(int i=0; i<upto_decimalplace; i++){
            factor = factor / 10;

            for(double j=ans; j*j<n; j=j+factor){
                ans = j;
            }
        }
        return ans;
    }

    int main(){
        int n;
        cout<<"enter the number :"<<endl;
        cin>>n;
        int tempsol=squareroot(n);//it gives the integer  part of the square root
        cout<<"answer is :"<<decimalpart(n,3,tempsol)<<endl;//3 means upto 3 decimal place
    return 0;
}


// Finding the pivot element in an array
# include <iostream>
using namespace std;

int pivotelementtype1(int arr[], int n){ // pivot(means smallest)
    int s=0;
    int e=n-1;

    while(s<e){
        int mid=s+(e-s)/2;

        if(arr[mid] >= arr[0]){
        //mai left line par hu
        //pivot aage ya right line pe exist karegi 
        s=mid+1;
    }

    else{
        //iska matlab ya to mai right line pe hu
        //ya pivot par hu
        //agar mid-1 kiya to sayad mai pivot element ko lost kardunga
        //isliye (e = mid) isse mai left me bhi aa jaunga aur pivot lost hone ka chance bhi nahi hoga
        e=mid;
    }
  }
  return s;// index of pivot element 
}

int pivotelementtype2(int arr[],int n){     // pivot(means largest)
    int s=0;
    int e=n-1;

    while(s<e){
        int mid=s+(e-s)/2;

        if(arr[mid] >= arr[0]){
        //mai left line par hu
        //pivot aage ya right line pe exist karegi 
        s=mid;
    }

    else{
        // iska matlab  mai right line pe hu
        //isliye e=mid-1 karke left me  jaunga aur pivot lost hone ka chance bhi nahi hoga
        e=mid-1;
    }
  }
  return s;// index of pivot element 
}


int main(){
    
    int n=7;
    int arr2[]={4,5,6,7,0,1,2};//sorted and rotated array
    int ans=pivotelementtype1(arr2, n);
    cout<<"pivot element of an array is :"<<arr2[ans];
    int ans2=pivotelementtype2(arr2, n);
    cout<<"pivot element of an array is :"<<arr2[ans2];
    return 0;
}