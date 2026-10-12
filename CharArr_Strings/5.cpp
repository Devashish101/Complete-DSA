// TODO: Most Occuring Word in a given String **
# include <iostream>
# include <sstream>
# include <algorithm>
# include <vector>
using namespace std;

int main(){
    
    string str = "Raghav sir is Maths Teacher And DSA Teacher as Well";  
    stringstream ss (str);
    string temp;
    vector<string> v;

    while(ss>>temp){
        v.push_back(temp);
    }
    cout<<"\n";

    sort(v.begin(),v.end());//By sorting we can arrange the simillar Words together
    int Maxcount = 1;
    int count = 1;
    for(int i=1; i<v.size(); i++){ //This loop is for finding the Max Count
        if(v[i]==v[i-1]){
            count++;
        }
        else{
            count = 1;
        }
        Maxcount=max(Maxcount,count);
    }

    count = 1;
    for(int i=1; i<v.size(); i++){ //This loop is for finding the Word which is occuring Maxcount Times
        if(v[i]==v[i-1]){
            count++;
        }
        else{
            count = 1;
        }
        if(count==Maxcount){
            cout<<v[i]<<" "<<Maxcount<<"\n";
        }
    }
    
    return 0;
}

// Maximum in a given String Array 
# include <bits/stdc++.h>
using namespace std;
int main(){
    
    string arr[] = {"0123","0023","456","00182","940","002901"};
    int max = stoi(arr[0]);
    string maxstr = arr[0]; // we are using maxstr just to store the string as it is. 
                            // becoz "stoi" doesn't consider the preciding zeroes while converting from string to integer or bool
    for(int i=1; i<6; i++){
        int x = stoi(arr[i]);
        if(x>max){
            max = x;
            maxstr = arr[i];
        }
    }
    cout<<maxstr;
     
    return 0;
}

// Longest common Prefix 14.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1){
            return strs[0];
        }
        sort(strs.begin(), strs.end());
        string s = "";
        string first = strs[0];
        string last = strs[n-1];
        for(int i=0; i<min(first.size(),last.size()); i++){
            if(first[i]==last[i]){
                s += first[i];
            }
            else{
                return s;
            }
        }
        return s;
    }
};

// Isomorphic String 205
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!= t.length()) return false;
        vector<int> v(150,1000);
        for(int i=0; i<s.length(); i++){
            int idx = (int)s[i];
            if(v[idx]==1000) v[idx] = s[i] - t[i];
            else if(v[idx] != (s[i]-t[i])) return false;
        }
        // Emptying the vector
        for(int i=0; i<150; i++){
            v[i] = 1000;
        }
         for(int i=0; i<t.length(); i++){
            int idx = (int)t[i];
            if(v[idx]==1000) v[idx] = t[i] - s[i];
            else if(v[idx] != (t[i]-s[i])) return false;
        }
        return true;

    }
};