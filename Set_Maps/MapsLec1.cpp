//242: Valid Anagram by using 2 Hashmaps
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    string  s = "anagram";
    string t = "nagaram";

    unordered_map<char,int> m1;
    unordered_map<char,int> m2;

    // Storing the freq of each char of string S.
    for(int i=0; i<s.size(); i++){
        m1[s[i]]++; 
    }

    // Storing the freq of each char of string t.
    for(int i=0; i<t.size(); i++){
        m2[t[i]]++;
    }

    for(auto x:m1){
        char ch1 = x.first;
        int  freq1 = x.second;
        if(m2.find(ch1) != m2.end()){ //checking wheather the char of string s is present in string t
            int freq2 = m2[ch1]; // finding the freq of same char in string t
            if(freq1 != freq2){ // if freq of char is not same in both string s and t
                cout<<false;
                break;
            }
        }
        else{ //It means char of string s is not present in string t
            cout<<false;
            break;
        }
    }
    cout<<true;
    
    return 0;
}

//242: Valid Anagram by using 1 Hashmap only
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    string  s = "anagram";
    string t = "nagaram";

    unordered_map<char,int> m1;

    // Storing the freq of each char of string S in map m1
    for(int i=0; i<s.size(); i++){
        m1[s[i]]++; 
    }

    for(int i=0; i<t.length(); i++){ //finding the each char of string t in m1
        char ch = t[i];
        if(m1.find(ch) != m1.end()){
            m1[ch]--;                // if char is found then decrement the freq of that char by 1
            if(m1[ch]==0) m1.erase(ch); // when freq becomes 0 then simply erase the ele from the map 
        }
        else cout<<false; // char not found
    }
    if(m1.size()==0) cout<<true; //finally if map becomes empty then return true
    else cout<<false;
    
    return 0;
}

// Leetcode 1: Two Sum
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int> nums = {2,4,11,5};
    int target = 9;
    int n = nums.size();
        unordered_map<int,int> m;
        vector<int>arr;
        for(int i=0; i<n; i++){
            int rem = target-nums[i];
            if(m.find(rem)!=m.end()){
                arr.push_back(m[rem]);
                arr.push_back(i);
            }
            else{
                m[nums[i]]=i;
            }
        }
        for(auto ele:arr){
            cout<<ele<<" ";
        }
    
    return 0;
}

// Leetcode 290 - Word Pattern Self Solved
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    string  pattern = "abba"; //case2-"abba" , case 3-"abba"
    string s = "dog cat cat dog"; //case2-"dog cat cat fish" case3-"dog dog dog dog"

        int n = pattern.size();
        int m = s.size();

        vector<string> v;
        string str;
        int i=0;
        while(i<m){
            if(s[i]!=' '){
                str+=s[i];
            }
            if(s[i]==' '|| i==m-1){
                v.push_back(str);
                str="";
            }
            i++;
        }
        if(n != v.size()) return false;

        unordered_map<char,string> m1;
        unordered_set<string> s1;
        bool flag = true;
        for(int i=0; i<n; i++){
            char ch = pattern[i];
            string st = v[i];

            if(m1.find(ch)!=m1.end()){ //map me present hai but sahi value ke sath mapped nahi hai
                if(m1[ch] != st){
                    cout<<false;
                    flag = false;
                    break;
                } 
            }
            if(m1.find(ch)==m1.end()){ //map me present nahi hai but value is already used with another key
                if(s1.find(st)!=s1.end()){
                    cout<<false;
                    flag = false;
                    break;
                }
            } 

            m1[ch] = st; //map me daldo with value
            s1.insert(st);//aur value ko set me daldo
        }
        if(flag==true)cout<<true;
    
    return 0;
}