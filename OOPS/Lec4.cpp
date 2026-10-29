//---------------------------------------------------- User Defined Data Structure(Vector) --------------------------------------------------------------
# include <bits/stdc++.h>
using namespace std;

class Vector{
public:
    int size;
    int capacity;
    int* arr; // arr will store the address of an integer in memory.

    Vector(){

        size = 0;
        capacity = 1;

        // new keyword asks the computer to allocate memory dynamically. 
        arr = new int[1]; // new int[1] means memory for 1 integer.
        
    }

    void add(int ele){
        if(size == capacity){
            capacity *= 2;
            int* arr2 = new int[capacity];
            for(int i=0; i<size; i++){
                arr2[i] = arr[i];
            }
            arr = arr2;
        }
        arr[size++] = ele; 
    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int get(int idx){
        if(size == 0){
            cout<<"Array is empty :("<<" ";
            return -1;
        }
        
        if(idx >= size || idx < 0){
            cout<<"Invalid Idx :|"<<" ";
            return -1;
        }
        return arr[idx];
    }

    void remove(){
        if(size == 0){
            cout<<"Array is empty :("<<" ";
            return;
        }
        size--;
    }
};
    
int main(){
    
    Vector v;
    cout<<v.size<<" "<<v.capacity<<endl;
    v.add(10);
    v.print();
    cout<<v.size<<" "<<v.capacity<<endl;
    v.add(15);
    v.print();
    cout<<v.size<<" "<<v.capacity<<endl;
    v.add(30);
    v.print();
    cout<<v.size<<" "<<v.capacity<<endl;
    v.add(50);
    
    cout<<v.get(3)<<endl;
    v.remove();
    cout<<v.get(3)<<endl;
    return 0;
}