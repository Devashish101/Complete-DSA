// FIXME: This is UNORDERED MAP.
// TODO: Time complexity of insertion,deletion and finding of an element in the unordered set is 0(1)

# include<bits/stdc++.h>
using namespace std;

int main(){
    // Creation
    unordered_map<string,int> m; //map<key,value>

    pair<string,int> p1; //method 1 -> For insertion into map 
    p1.first = "Bhargav";
    p1.second = 64;
    m.insert(p1); 
    pair<string,int> p2;
    p2.first = "Bansal";
    p2.second = 27;
    m.insert(p2);

    // Method 2 -> Insertion into map
    m["Devashish"] = 72; // m[key] = value
    m["Devendra"] = 73;

   cout<<m["Devashish"]<<endl;// it will print the value of key (Devashish).

    // Iteration over the map
    for(pair<string,int> p: m){ // insted of writing "pair<string,int>" we can simply write "auto"
        cout<<p.first<<" "<<p.second<<"\n";
    }
    cout<<endl;

    // Erase or Deletion of an element from the map
    m.erase("Devendra");
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;

    // Size of map
    cout<<m.size()<<endl;

    //TODO: Finding the key in the map
    // s.find()!=s.end(); => It searches in the map and 
    // if target key is not found then it returns the map last element
    string target_key = "bansl";
    if(m.find(target_key)!= m.end()){
        cout<<"exists";
    }
    else cout<<"does not exist";
    cout<<endl;

}



// FIXME: This is ORDERED MAP.
// TODO: Time complexity of insertion,deletion and finding of an element in the ordered map is 0(logn)
# include<bits/stdc++.h>
using namespace std;

int main(){
    // Creation
    map<string,int> m; //map<key,value>

    pair<string,int> p1; //method 1 -> For insertion into map 
    p1.first = "Bholu";
    p1.second = 64;
    m.insert(p1); 
    pair<string,int> p2;
    p2.first = "Baby";
    p2.second = 27;
    m.insert(p2);

    // Method 2 -> Insertion into map
    m["Ashish"] = 72; // m[key] = value
    m["Dhruv"] = 73;

   cout<<m["Ashish"]<<endl;// it will print the value of key (Devashish).

    // Iteration over the map 
    //TODO: As ordered map or map keep the keys in the sorted order. values depends on the order of keys.
    for(pair<string,int> p: m){ // insted of writing "pair<string,int>" we can simply write "auto"
        cout<<p.first<<" "<<p.second<<"\n";
    }
    cout<<endl;

    // Erase or Deletion of an element from the map
    m.erase("Dhruv");
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;

    // Size of map
    cout<<m.size()<<endl;

    //TODO: Finding the key in the map
    // s.find()!=s.end(); => It searches in the map and 
    // if target key is not found then it returns the map last element
    string target_key = "Baby";
    if(m.find(target_key)!= m.end()){
        cout<<"exists";
    }
    else cout<<"does not exist";
    cout<<endl;

}