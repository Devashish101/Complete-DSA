// Implement a Minheap using Array.(Visualize it as a complete binary Tree).
# include <bits/stdc++.h>
using namespace std;

class MinHeap{
public:
    int arr[50];
    int idx;

    MinHeap(){
        idx = 1;
    }

    // Functions of MinHeap 
    int top(){
        return arr[1];
    }

    void push(int x){
        arr[idx] = (x);
        int i = idx;
        idx++;

        // Swapping of ele at idx i with its parent,
        // if it is less than its parent.
        while(i != 1){
            int parent = i/2;
            if(arr[i] < arr[i/2]){
                swap(arr[i], arr[i/2]);
                i = parent;
            }
            else break;
        }
    }

    void pop(){
        idx--;
        arr[1] = arr[idx]; 
        // Rearrangement
        int i = 1;
        while(true){
            int lft = 2*i, rgt = 2*i+1;
            if(lft > idx-1)break;
            if(rgt > idx-1){
                if(arr[i] > arr[lft]){
                    swap(arr[i],arr[lft]);
                    i = lft;
                }
                break;
            }
            if(arr[lft] < arr[rgt]){
                if(arr[i] > arr[lft]){
                    swap(arr[i], arr[lft]);
                    i = lft;
                }
                else break;
            }
            else {
                if(arr[i] > arr[rgt]){
                    swap(arr[i],arr[rgt]);
                    i = rgt;
                }
                else break;
            }
        }
    }

    int size(){
        return idx-1;
    }
    
    void display(){
        for(int i=1; i<idx; i++){
            cout<<arr[i]<<" ";
        }
    }
};
     
int main(){
    
    MinHeap pq;
    pq.push(10);   
    pq.push(2);   
    pq.push(14);
    cout<<pq.size()<<"\n";  
    pq.push(11);   
    pq.push(1);   
    cout<<pq.top()<<"\n";  
    pq.display();
    pq.pop();
    cout<<pq.top()<<"\n";  
    pq.display();
    return 0;
}

// Heap Sort (Sort the ele using Min or Max heap) -> T.C = O (n*logn) & S.C = O(n).
# include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {10,1,2,20,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    priority_queue<int, vector<int>, greater<int> >pq; // using MinHeap

    int i = 0;
    while(i<n){
        pq.push(arr[i]);
        i++;
    }
    i = 0;
    while(pq.size() > 0){
        arr[i++] = pq.top();
        pq.pop();
    }
    for(auto ele: arr){
        cout<<ele<<" ";
    }
}

// Heapify algorithm (Converting a given array/vector into heap, it is basically pop's rearrangement)using MinHeap or MaxHeap
# include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapify(int i, int arr[], int n){
    while(true){
        int lft = 2*i, rgt = 2*i+1;
        if(lft >= n)break;
        if(rgt >= n){
            if(arr[i] > arr[lft]){
                swap(arr[i],arr[lft]);
                i = lft;
            }
            break;
        }
        if(arr[lft] < arr[rgt]){
            if(arr[i] > arr[lft]){
                swap(arr[i], arr[lft]);
                i = lft;
            }
            else break;
        }
        else {
            if(arr[i] > arr[rgt]){
                swap(arr[i],arr[rgt]);
                i = rgt;
            }
            else break;
        }
    }
}

int main(){
    int arr[] = {-1,10,2,14,11,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    for(int i = n/2; i >= 1; i--){
        heapify(i, arr, n);
    }
    print(arr,n);
}