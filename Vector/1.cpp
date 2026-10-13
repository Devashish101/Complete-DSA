//                                       VECTOR STL
# include <iostream>
# include <vector>
# include<algorithm>
using namespace std;

void print(vector<int>v){
    cout<<"printing the vector by method 1 :";
    int size=v.size(); // it gives the size of vector on the basis of no. of elmements present in it.
    for(int i=0; i<size; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void print2(vector<int>v){
    cout<<"printing the vector by method 2"<<endl;
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}


int main(){

//here we dont have to declare the size or anything just keep inserting or deleting the elements from it.
//vector Initialisation => [vector <data type> name of vector we want]

    vector<int>v;//default way with no data and 0 size.

    vector<int>arr(5,1);//another way of initialization => initialized with n-size(5) with fixed data(1)
    // arr.push_back(10);
    // print(arr);

    vector<int>arr2={1,2,3,4,5};//another way of initialization
    print2(arr2);                  

    vector<int>arr3{5,6,7,8,9};//another way of initialization
    // print(arr3);

//how to copy vector elements in another vector
    vector<int>arr4={10,20,30,40,50};
    vector<int>arr5(arr4);
    // print(arr5);

//how to acess first and last element of vector 
    vector<char>ch;
    ch.push_back('a');
    ch.push_back('b');
    ch.push_back('c');
    // cout<<"first element of vector is :"<<ch[0]<<endl;
    // cout<<"first element of vector is :"<<ch.front()<<endl;
    // cout<<"last element of vector is :"<<ch.back()<<endl;
    // cout<<"last element of vector is :"<<ch[ch.size() - 1];

// inserting the elements 

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // cout<<"elements before pop :"<<" ";
    //     print(v);


// pop -> Deletion from vector =>pop always work from end.

    // v.pop_back();
    // cout<<"elements after 1st pop :"<<" ";
    //     print(v);

    // v.pop_back();
    // cout<<"elements after 2nd pop :"<<" ";
    //     print(v);

    // v.pop_back();
    // cout<<"elements after 3rd pop :"<<" ";
    //     print(v);

    // v.pop_back();
    // cout<<"elements after 4th pop :"<<" ";
    //     print(v);


//taking input in a vector
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int d;
        cin>>d;
        v.push_back(d);
    }
    cout<<" After taking input our vector is :"<<endl;
        // print(v);

//inserting more element in a existing  full vecrtor without worring about it's size
    for (int i=6; i<10; i++){
            v.push_back(i);
    }
    cout<<"After inserting more element in existing vector our vector is :"<<endl;
        print(v);

//if we want to clear all elements of a vector 
    cout<<"clearing all the elements of a vector"<<endl;
    v.clear();
     print(v);

// reverse of an elements of a vector
    reverse(arr4.begin(), arr4.end());
    print(arr4);
    return 0;
}