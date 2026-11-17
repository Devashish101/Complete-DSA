// FIXME: This is UNORDERED SET.
// TODO: Time complexity of insertion,deletion and finding of an element in the unordered set is 0(1)

# include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> s;

    //TODO: Insertion of elements in the set
    s.insert(1);
    s.insert(2);
    s.insert(5);
    s.insert(8);
    s.insert(2);//duplicate element

    cout<<s.size()<<endl;//duplicate element will not be inciuded in the size of the set

    //TODO: Traversing the element of set using for-each loop
    for(int ele:s){
        cout<<ele<<" ";
    }
    cout<<"\n";

    //TODO:To erase the elements from the set
    s.erase(2); 
    for(int ele:s){
        cout<<ele<<" ";
    }
    cout<<endl;

    //TODO: Finding the element in the set
    // s.find()!=s.end(); => It searches in the set and 
    // if target ele is not found then it returns the set last element
    int target = 15;
    if(s.find(target)!=s.end()){
        cout<<"exists";
    }
    else cout<<"does not exist";
    cout<<endl;

}


// FIXME: This is ORDERED SET.
// TODO: Time complexity of insertion,deletion and finding of an element in the ordered set is 0(logn)
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    set<int> s;
    //TODO: Insertion of elements in the set
    s.insert(1);
    s.insert(2);
    s.insert(5);
    s.insert(8);
    s.insert(2);//duplicate element

    cout<<s.size()<<endl;// set consist of only unique elements

    //TODO: Traversing the element of set using for-each loop
    //TODO: As ordered set or set keep the elements in the sorted order.
    for(int ele:s){
        cout<<ele<<" ";
    }
    cout<<"\n";

    //TODO:To erase the elements from the set
    s.erase(2); 
    for(int ele:s){
        cout<<ele<<" ";
    }
    cout<<endl;

    //TODO: Finding the element in the set
    // s.find()!=s.end(); => It searches in the set and 
    // if target ele is not found then it returns the set last element
    int target = 5;
    if(s.find(target)!=s.end()){
        cout<<"exists";
    }
    else cout<<"does not exist";
    cout<<endl;

    
    return 0;
}