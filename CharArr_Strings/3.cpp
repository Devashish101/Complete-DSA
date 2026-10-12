
//                              Different Neighbouring Characters
# include <bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    cin >> s;
    int n = s.length();
    int count = 0;

    for(int i=0; i<n; i++){
        if(n==1){
            break;
        }
        else if(i==0){
            if(s[i]!= s[i+1]){
                count++;
            }
        }
        else if(i==n-1){
            if(s[i]!= s[i-1]){
                count++;
                break;
            }
        }
        else if(s[i]!=s[i-1] && s[i] != s[i+1]){
            count++;
        }

    }
    cout<<count;
    return 0;
}

// remove-all-adjacent-duplicates-in-string leetcode problem no. 1047
# include <iostream>
# include <string.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans;
    // getline(cin,s);
        int i=0;
        while(i<s.length()){
          //In case of ans ka rightmost char and s ka current char are same
          if((ans.length() > 0) && (ans[ans.length()-1] == s[i])){
            ans.pop_back();
          }
          else{
            //in case of different
            ans.push_back(s[i]);
          }
          i++;
       }
       cout<<ans;
       
    return 0;
}

// remove-all-occurrences-of-a-substring leet code problem no.1910
// INPUT s = "daabcbaabcbc", part = "abc"
# include <iostream>
# include <string.h>
using namespace std;

string removeoccurence(string s,string sub){
      while(s.find(sub) != string::npos){
            //if inside loop, it means that sub exists in s string
            s.erase(s.find(sub), sub.length());
        }
        return s;
}

int main(){
  string s;
  cout<<"enter your string :"<<endl;
  cin>>s;

  string sub;
  cout<<"enter the sub-string :"<<endl;
  cin>>sub;

  string ans=removeoccurence(s,sub);
  cout<<"final string will be :"<<ans<<endl;
  return 0;
}


// *********************Valid Anagram***********************
# include <iostream>
# include <string.h>
using namespace std;

bool checkAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        cout<<"Not a Valid Anagram\n";
        return false;
    }

    int count[26] = {0};

    for(int i=0; i<str1.length(); i++){
        int idx = str1[i] - 'a';
        count[idx]++;
    }

    for(int i=0; i<str2.length(); i++){
        int idx = str2[i] - 'a';
        if(count[idx]==0){
            cout<<"Not a valid Anagram\n";
            return false;
        }
        else{
            count[idx]--;
        }
    }

    cout<<"Valid Anagram\n";
    return true;
}

int main(){

    string str1 = "agagram";
    string str2 = "nagaram";

    checkAnagram(str1,str2);
    return 0;
}

// Chracter Having Highest frequency 
// => Approach 1
# include <bits/stdc++.h>
using namespace std;
int main(){
    
    string s = "Physicswallah";
    int max = 0;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        int count = 1;
        for(int j=i+1; j<s.length(); j++){
            if(s[i]==s[j]) count++;
        }
        if(max<count) max = count;
    }

    for(int i=0; i<s.length(); i++){ 
        char ch = s[i];
        int count = 1;
        for(int j=i+1; j<s.length(); j++){
            if(s[j]==s[i])count++;
        }
        if(count==max){
            cout<<ch<<" "<<max<<"\n";
        }
    }
    return 0;
}
// Approach 2 => best Approach
# include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s = "leetcode";
    vector<int>arr(26,0);
    
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        int ascii = (int)ch;
        arr[ascii-97]++;
    }
    int max = 0;
    for(int i=0; i<26; i++){
        if(arr[i]>max) max = arr[i];
    }

    for(int i=0; i<26; i++){
        if(arr[i]==max){
            int ascii = i+97;
            char ch = (char)ascii;
            cout<<ch<<" "<<max<<"\n";
        }
    }
   
    return 0;
}

