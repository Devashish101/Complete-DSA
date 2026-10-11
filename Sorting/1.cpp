// ##############********************************TODO: Sorting Algorithms ****************************************################

# include <iostream>
# include <algorithm>
using namespace std;

void printarr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
// *************************************************Bubble Sort**********************************************************

void bubblesort(int *arr, int n){
    bool isswap = false; // for avoid unnecessary swap
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                isswap = true;
            }
        }
        if(isswap!=true){ // exit from loop after 1complete iteration of inner loop if no swap is required
            return;
        }

    }
    printarr(arr, n);
}

// **********************************************************Selection sort**************************************

void selectionsort(int *arr, int n){
    for(int curridx=0; curridx<n-1; curridx++){
        int minidx = curridx;
        for(int i=curridx+1; i<n; i++){
            if(arr[i]<arr[minidx]){
               minidx = i; 
            }
        }
        swap(arr[curridx],arr[minidx]);
    }
    printarr(arr, n);
}

// ***************************************************************Insertion sort*******************************************
void insertionSort(int arr[], int n) {
    // Start from the second element (index 1)
    for(int i = 1; i < n; i++) {
        int current = arr[i];     // Element to be positioned
        int j = i - 1;

        // Shift elements greater than 'current' to the right
        while(j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];  // Move element one position ahead
            j--;
        }

        // Place 'current' at its correct position
        arr[j + 1] = current;
    }
    printarr(arr, n);
}

// ***********************************************Count sort**********************************************
void countsort(int arr[], int n){
    int freq[10000] = {0};
    int minVal = INT16_MAX;
    int maxVal = INT16_MIN ;

    for(int i = 0; i<n; i++){
        minVal = min(minVal,arr[i]);
        maxVal = max(maxVal,arr[i]);
        freq[arr[i]]++;
    }

    for(int i=minVal, j=0; i<=maxVal; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }

    }
    printarr(arr, n);
}


int main(){
    int arr[8]={1,4,1,3,2,4,3,7};
    int n = 8;
    // selectionsort(arr,n);
    // bubblesort(arr,n);
    // insertionSort(arr,n);
    // countsort(arr,n);

    // **********************************************************In-Built Sort Function ***********************************************
    // Sort full array in ascending order
    sort(arr, arr + 8);
    // printarr(arr, n);

    // Sort subarray from index 2 to 4 (3 elements)
    sort(arr + 2, arr + 5);
    // printarr(arr, n);

    // Sort full array in descending order
    sort(arr, arr + n, greater<int>());
    // printarr(arr, n);


    return 0;
}

// TODO: First complete Recursion
// ***************************************************** Merge Sort *************************************************
# include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, vector<int>& b, vector<int>& res) {
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }

    // Copy remaining elements of a
    while (i < a.size()) {
        res[k++] = a[i++];
    }

    // Copy remaining elements of b
    while (j < b.size()) {
        res[k++] = b[j++];
    }
}

void MergeSort(vector<int> &v){
    int n = v.size();
    if(n==1) return;
    int n1 = n/2;
    int n2 = n-n/2;
    vector<int> a(n1),b(n2);

    for(int i=0; i<n1; i++){ 
        a[i] = v[i];
    }
    for(int i=0; i<n2; i++){
        b[i] = v[i+n1];
    }

    MergeSort(a);
    MergeSort(b);
    //Merging the sorted Arrays.
    merge(a,b,v);
    //Now clearing the extra array space for improving the Space Complexity
    a.clear();
    b.clear(); 
}

int main(){
    int arr[] = {2,7,3,6,10,12,11};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n1); //copying the whole array inside the vector.
    MergeSort(v);
    for(int element:v){
        cout<<element<<" ";
    }
}

//******************************************************// Quick Sort*********************************
# include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int si,int ei){
    int pivotElement = arr[(si+ei)/2];
    int count = 0;
    for(int i=si; i<=ei;i++){
        if(arr[i]==(si+ei)/2) continue;
        if(arr[i]<=pivotElement) count++;
    }
    int pivotIdx = count + si;
    swap(arr[(si+ei)/2],arr[pivotIdx]);
    int i = si;
    int j = ei;
    while (i<pivotIdx && j>pivotIdx){
       if(arr[i]<=pivotElement) i++;
       if(arr[j]>pivotElement) j--;
       else if(arr[i]>pivotElement && arr[j]<=pivotElement){
           swap(arr[i],arr[j]);
           i++;
           j--;
       }
    }
    return pivotIdx;
    
}

void quicksort(int arr[],int si,int ei){
    if(si>=ei) return ;
    int pi = partition(arr,si,ei);
    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);
}

int main(){
    int arr[] = {2,7,3,6,10,12,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int element:arr){
        cout<<element<<" ";
    }
    cout<<endl;
    quicksort(arr,0,n-1);
    for(int element:arr){
        cout<<element<<" ";
    }
}

//**************************************************// Cyclic Sort*********************************************
# include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {4,1,6,2,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    int i = 0;
    while(i<n){
        int corridx = arr[i]-1;
        if(i==corridx) i++;
        else swap(arr[i],arr[corridx]);
    }
    for(int ele: arr){
        cout<<ele<<" ";
    }
}