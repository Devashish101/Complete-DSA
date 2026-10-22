// Tower of Hanoi
# include <bits/stdc++.h>
using namespace std;

void Hanoi(int n,char a,char b,char c){
    // base case
    if(n==0) return;
    
    // moving n-1 disc from a to b using c
    Hanoi(n-1,a,c,b);

    // moving nth disc directly from a to c 
    cout<<a<<"=>"<<c<<"\n";

    // now again moving the n-1 disc from b to c using a
    Hanoi(n-1,b,a,c);
}

//Coding Ninjas
vector<vector<int>>ans;
void hanoi(int n, int rodA, int rodB, int rodC){
    // rodA -> source, rodB -> helper, rodc-> dest
    if(n==0)return;

    hanoi(n-1, rodA, rodC, rodB); 
    ans.push_back({rodA, rodC});
    hanoi(n-1, rodB, rodA, rodC);

}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    Hanoi(n,'S','H','D'); //here S -> source ,H -> Helper, D -> Destination

    ans.clear();
    hanoi(n,1,2,3);
    for(auto ele: ans){
        for(auto x: ele){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

// Traversing the array using Recursion
void Traverse(int arr[],int i,int n){
    if(i==n) return;
    cout<<arr[i]<<" ";
    Traverse(arr,i+1,n);
}

void Traverse2(vector<int> v,int idx){
    if(idx==v.size()) return;
    cout<<v[idx]<<" ";
    Traverse2(v,idx+1);
}

int main(){
    int arr[] = {12,15,62,76,98};
    vector<int> v= {10,12,15,18};
    Traverse(arr,0,5);
    Traverse2(v,0);
}

// Finding the Max in an array using Recursion
void printmax(int arr[],int n,int idx,int max){
    if(idx==n) {
        cout<<max<<endl;
        return;
    }
    if(arr[idx]>max) max = arr[idx];
    printmax(arr,n,idx+1,max);
}

int MaxInArray(int arr[],int n,int idx){
    if(idx==n) return INT_MIN;
    return max(arr[idx],MaxInArray(arr,n,idx+1));
}

int main(){
    int n = 4;
    int arr[n] = {10,120,15,18};
    printmax(arr,n,0,INT_MIN);
    cout<<MaxInArray(arr,n,0);
}

// Skip a Charaacter
// Remove all Occurences of 'h' from the String
# include <bits/stdc++.h>
using namespace std;

void removeChar(string ans,string original){
    if(original.length()==0){
        cout<<ans;
        return;
    }
    char ch = original[0];
    if(ch=='h') removeChar(ans,original.substr(1));
    else removeChar(ans+ch,original.substr(1));
}

void removeChar1(string ans,string original,int idx){
    if(idx==original.length()){
        cout<<ans;
        return;
    }
    char ch = original[idx];
    if(ch=='h') removeChar1(ans,original,idx+1);
    else removeChar1(ans+ch,original,idx+1);
}

int main(){
    
    string str = "hello hi";
    removeChar("",str);
    cout<<endl;
    removeChar1("",str,0);
}

// Print and Store all the subsets of a given string
void Subset(string ans, string original){
    if(original==""){
        cout<<"["<<ans<<"]"<<endl;
        return;
    }
    char ch = original[0];
    Subset(ans,original.substr(1));
    Subset(ans+ch,original.substr(1));
}

void Subset2(string ans, string original,int idx){
    if(idx==original.length()){
        cout<<"["<<ans<<"]"<<endl;
        return;
    }
    char ch = original[idx];
    Subset2(ans+ch,original,idx+1);
    Subset2(ans,original,idx+1);
}

void storesubset(string ans,string str,vector<string>& v){
    if(str==""){
       v.push_back(ans);
       return;
    }
    char ch = str[0];
    storesubset(ans+ch,str.substr(1),v);
    storesubset(ans,str.substr(1),v);
}

int main(){
    string str = "abc"; 
    vector<string> v;
    // Subset("",str);
    // Subset2("",str,0);
    storesubset("",str,v);
    for(int i=0; i<v.size(); i++){
        cout<<"["<<v[i]<<"]"<<" ";
        }
}

// Print all the subsets of a given Array
void subsetArray(int arr[], int n, int idx, vector<int> ans){
    if(idx==n){
        for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    subsetArray(arr,n,idx+1,ans);
    ans.push_back(arr[idx]);
    subsetArray(arr,n,idx+1,ans);
} 

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    subsetArray(arr,n,0,v);
}

//***** Print all the subsets of a string Containing Duplicate Elements
//Leetcode 90. Print all the subsets of a Array Containing Duplicate Elements (Homework)
#include <bits/stdc++.h>
using namespace std;

void Subset(string ans, string original, vector<string>& v, bool flag) {
    if (original == "") {
        v.push_back(ans);
        return;
    }

    char ch = original[0];

    if (original.length() == 1) { 
        // Base case: only one character left
        Subset(ans + ch, original.substr(1), v, true);
        Subset(ans, original.substr(1), v, true);
    }
    else { 
        char dh = original[1];
        if (ch == dh) { // duplicate found
            if (flag == true) Subset(ans + ch, original.substr(1), v, true);
            Subset(ans, original.substr(1), v, false);
        }
        else { // no duplicate
            if (flag == true) Subset(ans + ch, original.substr(1), v, true);
            Subset(ans, original.substr(1), v, true);
        }
    }
}

int main() {
    string str = "aab"; 
    sort(str.begin(), str.end()); // important for duplicates
    vector<string> v;
    Subset("", str, v, true);

    for (int i = 0; i < v.size(); i++) {
        cout << (v[i] == "" ? "\"\"" : v[i]) << endl;
    }
}

// Print all the Sub sequence of length 3 of the first n natural numbers .
# include<bits/stdc++.h>
using namespace std;

void subSequence(int arr[], int n, int idx, vector<int> ans,int k){
    if(idx==n){
        if(ans.size()==k){ 
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(ans.size()+(n-idx)<k) return;
    subSequence(arr,n,idx+1,ans,k);
    ans.push_back(arr[idx]);
    subSequence(arr,n,idx+1,ans,k);
} 

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int> v;
    subSequence(arr,n,0,v,k);
}

// Print all the permutations of the given string
# include<bits/stdc++.h>
using namespace std;

void Permutation(string ans,string original){
    if(original==""){
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<original.length(); i++){
        char ch = original[i];
        string leftstr = original.substr(0,i);
        string rightstr = original.substr(i+1);
        Permutation(ans+ch, leftstr+rightstr);
    }
}

int main(){ 
   string str = "abc";
   Permutation("",str);
}