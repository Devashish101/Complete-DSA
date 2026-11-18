// Heaps are also called priority queues
// In C++ Max heap is the default heap using stl
// When to use Heap :- 
// If we always have to keep track of the max or min ele.
// To find kth smallest or largest elemets, Top k frequent or closest k ele. 
# include <iostream>
# include <queue>
using namespace std;

int main(){
    // priority_queue<int>pq; // Max Heap (It is By Default in C++)
    // pq.push(8);  // Top ele is 8
    // pq.push(12); // Top ele is 12
    // pq.push(-1); // Top ele is 12
    // pq.push(55); // Top ele is 55
    // cout<<pq.top()<<endl; // 55
    // pq.pop();
    // cout<<pq.top()<<endl; // 12
    // cout<<pq.size();

    priority_queue< int, vector<int >, greater<int > > pq; // Syntax for Min Heap (It is by default in java)
    pq.push(8);  // Top ele is 8
    pq.push(12); // Top ele is 8
    pq.push(-1); // Top ele is -1
    pq.push(55); // Top ele is -1
    cout<<pq.top()<<endl; // -1
    pq.pop();
    cout<<pq.top()<<endl; // 8
    cout<<pq.size();

}


// TODO: Find the kth smallest element in the given array
// FIXME: In case of Kth smallest ele use maxheap and for Kyh Largest use minheap.
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> arr = {10,20,-4,6,18,24,105,121};

    //FIXME: Approach 1 - Using Min heap, T.C = ~= n(logn) & S.C = 0(n).
    // priority_queue<int, vector<int>, greater<int> > pq;
    // int k = 3; // 3rd smallest ele

    // for(int i=0; i<arr.size(); i++){
    //     pq.push(arr[i]);
    // }

    // int n = 1;
    // while(n != k){
    //     pq.pop();
    //     n++;
    // }
    // cout<<pq.top();

    //FIXME: Approach 2 - Using Max heap T.C = n*(logk) & S.C = 0(K) As here pq is of size k only.
    priority_queue<int> pq;
    int k = 3; // 3rd smallest ele

    for(int i=0; i<arr.size(); i++){
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    cout<<pq.top();

    return 0;
}

// TODO: Leetcode 215 : Find the kth Largest element in the given array
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    int arr [] = {12,31,5,-18,82,64};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    priority_queue<int, vector<int>, greater<int> >minpq;

    for(int i=0; i<n; i++){
        minpq.push(arr[i]);
        if(minpq.size() > k)minpq.pop();
    }
    cout<<minpq.top();
    
    return 0;
}

// TODO: Nearly sorted -> GfG
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> arr = {2, 3, 1, 4};
    int k = 2;
    int n = arr.size();
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> >pq; // Min Heap
    
    int idx = 0;
    int i=0;
    while(i<n){
        pq.push(arr[i]);
        
        if(pq.size() > k){
        
            // arr[idx++] = pq.top(); // -> Without using the extra array
            // pq.pop();

            ans.push_back(pq.top());
            pq.pop();
        }
        i++;
    }
       
    while(pq.size() != 0){
        // arr[idx++] = pq.top(); // -> Without using the extra array.
        // pq.pop();

        ans.push_back(pq.top());
        pq.pop();
    }
    
    for(int i=0; i<n; i++){
        // cout<<arr[i]<<" "; // In case of without using the extra array.

        cout<<ans[i]<<" ";
    }
    return 0;
}
// Leetcode 378 - H.W
