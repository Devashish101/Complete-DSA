// Count Inversion
# include <bits/stdc++.h>
using namespace std;
int c = 0;
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

int Inversion(vector<int> & a, vector<int>& b){
    int count = 0;
    int i = 0;
    int j = 0;
    while(i<a.size() && j<b.size()){
         if(a[i]>b[j]) {
            count += (a.size()-i);
            j++;
         }
         else { //a[i]<b[j]
            i++;
         }

    }
    return count;

}

void countInversion(vector<int> &v){
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

    countInversion(a);
    countInversion(b);
    c += Inversion(a,b);
    //Merging the sorted Arrays.
    merge(a,b,v);
    //Now clearing the extra array space for improving the Space Complexity
    a.clear();
    b.clear(); 
}

int main(){
    int arr[] = {5,1,3,0,4,9,6};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n1); //copying the whole array inside the vector.
    countInversion(v);
    cout<<c;
}

// Quick Select (Almost Quick Sort Algorithm)
// Find the kth minimum element in the Array
# include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int si,int ei){
    int pivotElement = arr[si];
    int count = 0;
    for(int i=si+1; i<=ei;i++){
        if(arr[i]<=pivotElement) count++;
    }
    int pivotIdx = count + si;
    swap(arr[si],arr[pivotIdx]);
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

int kthmin(int arr[],int si,int ei,int k){

    int pi = partition(arr,si,ei);
    if(pi+1==k) return arr[pi];
    else if(pi+1<k) return kthmin(arr,pi+1,ei,k);
    else return kthmin(arr,si,pi-1,k);
}

int main(){
    int arr[] = {2,7,3,6,10,12,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int element:arr){
        cout<<element<<" ";
    }
    int k = 5;
    cout<<endl;
    cout<<kthmin(arr,0,n-1,k);
    
}

// Leetcode 268: Missing Number using cyclic sort
# include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {8,6,4,2,3,5,7,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool flag = true;
    int i = 0;
    while(i<n){
        int correctidx = arr[i];
        if(i==correctidx || arr[i]==n) i++;
        else swap(arr[i],arr[correctidx]);
    }
    for(int i=0; i<n; i++){
        if(arr[i]!=i){
            cout<<i;
            flag = false;
            break;
        }
    }
    if(flag==true){
        cout<<n;
    }

}
