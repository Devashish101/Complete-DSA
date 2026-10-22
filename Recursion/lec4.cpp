// Print all the SubArray of the given Array
# include<bits/stdc++.h>
using namespace std;

void subArray(vector<int>ans, int arr[] ,int n,int idx){

    if(idx==n){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
        }
        cout<<endl;
        return;
    }
    subArray(ans,arr,n,idx+1); //This is for the left call in which we dont push anything in our ans SubArray

    //If our ans SubArray is empty or our (idx-1)th element of array is equal to the ans's Array last element 
    // Then only We make our Right Call , By doing so we Maintain the Continuous Sequence of the Sub-Array
    if(ans.size()==0 || arr[idx-1] == ans[ans.size()-1]){
        ans.push_back(arr[idx]);
        subArray(ans,arr,n,idx+1);
    }
}

// This is the better and more preffered solun for this problem.
vector<vector<int>> ans;
void subarr(int arr[], int n,int start) {
    if (start == n)
        return;

    vector<int> nums;
    for (int i = start; i < n; i++) {
        nums.push_back(arr[i]);
        ans.push_back(nums);
    }

    subarr(arr, n, start + 1);
}

int main(){ 
   int arr[] = {1,2,3,4};
   int n = sizeof(arr)/sizeof(arr[0]);
// Printing the Sub Array using for loop
   for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            for(int k=i; k<=j; k++){
                cout<<k<<" ";
            }
            cout<<endl;
        }
    }
   vector<int> v;
   subArray(v,arr,n,0);
   subarr(arr,n,0);
}

// Check Wheather Given String is Pallindrome or Not
# include<bits/stdc++.h>
using namespace std;

bool Pallindrome(string str,int i,int j){
    if(i>j) return true; //base case
    if(str[i]!=str[j]) return false;
    else  return Pallindrome(str,i+1,j-1);
    
}

int main(){ 
   string str = "aba";
   int i = 0;
   int j = str.length()-1;
   cout<<Pallindrome(str,i,j);
}

// HCF i.e(greatest Common Divisor) of two numbers
# include<bits/stdc++.h>
using namespace std;

int hcf(int a,int b){
    for(int i=min(a,b); i>=2; i--){
        if(a%i==0 && b%i==0) return i;
    }
    return 1;
}

int gcd(int a,int b){ //T.C = O(log(a+b))
    if(a==0) return b;
    else gcd(b%a,a);
}

int main(){ 
    int a = 27;
    int b = 45;
   cout<<gcd(27,45)<<endl;
   cout<<hcf(27,45);
}

// Print all binary strings of length n and
# include<bits/stdc++.h>
using namespace std;

void binStr(string str,int k){
    
    // base case
    if(str.length()==k){
        cout<<str<<endl;
        return;
    }
    // code or Recursive call
    binStr(str+"0", k);
    binStr(str+"1", k);
}

// Print all binary strings of length n without consequtive 1's
void binStr2(string str,int k){

    // base case
    if(str.length()==k){
        cout<<str<<endl;
        return;
    }
    // code or Recursive call
    if(str.length()==0 || str[str.length()-1]!='1'){
        binStr2(str+"0", k);
        binStr2(str+"1", k);
    }
    else{ //str[str.length()-1]==1
        binStr2(str+"0", k);
    }
}

int main(){ 
    int n = 4;
    // binStr("",n);
    binStr2("",n);
}


// Leetcode 39.print all the unique combination sum which are equal to the given target
# include<bits/stdc++.h>
using namespace std;

void combination(vector<int>ans,int arr[],int n,int target,int idx){

    if(target==0){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        } 
        cout<<endl;
        return;
    }

    if(target<0) return;

    for(int i=idx; i<n; i++){
        ans.push_back(arr[i]);
        combination(ans,arr,n,target-arr[i],i);
        ans.pop_back(); // for Emptying the Vector for next call
    } 
}

vector<vector<int> >ans;
void combination1(int arr[],vector<int> &nums,int n,int target, int idx){
    if(target == 0){
        ans.push_back(nums);
        return;
    }

    if(idx == n){
        return;
    }

    if(arr[idx] <= target){
        nums.push_back(arr[idx]);
        combination1(arr,nums,n,target-arr[idx],idx);
        nums.pop_back();
    }
    combination1(arr,nums,n,target,idx+1);
}

int main(){ 
    int arr[] = {2,3,5};
    int target = 8;
    int idx = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    combination(v,arr,n,target,idx);
    combination1(arr,v,n,target,idx);
}


// Leetcode 22.Generate Parenthesis
# include<bits/stdc++.h>
using namespace std;

void generate(string str,int open,int close,int n){ //open and close are count of opening and closing brackets
    //Main Concept => Opening brackets is always greater or equal to Closing brackets
    if(close==n){
        cout<<str<<endl;
        return;
    }
    if(open<n) generate(str+"(",open+1,close,n); //This is for Opening brackets
    if(close<open) generate(str+")",open,close+1,n); // This is for Closing Brackets
}

int main(){ 
    int n = 3;
    vector<string>ans;
    generate("",0,0,n);
}


// Leetcode 779. Kth Symbol in Grammer
#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k) {
    if (n == 1) return 0;  // base case

    if (k % 2 == 0) { // even -> flip previous
        int prevAns = kthGrammar(n - 1, k / 2);
        return (prevAns == 0) ? 1 : 0; 
    } 
    else { // odd -> same as previous
        int prevAns = kthGrammar(n - 1, (k + 1) / 2);
        return prevAns;
    }
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << "The " << k << "-th symbol in row " << n << " is: " 
         << kthGrammar(n, k) << endl;

    return 0;
}

//Leetcode 38. Count And Say ****
#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    if(n==1) return "1";
    string str = countAndSay(n-1);
    string ztr = "";
    int freq = 1;
    char ch = str[0];
    
    for(int i=1; i<str.length(); i++){ // strictly < not <=
        char dh = str[i];
        if(ch==dh){
            freq++;
        }
        else{
            ztr += to_string(freq) + ch;
            freq = 1;
            ch = dh;
        }
    }
    // don't forget the last group
    ztr += to_string(freq) + ch;
    
    return ztr;
}

int main(){
    int n = 5;   // Example: 5th term
    string ans = countAndSay(n);
    cout << ans << endl;
}

// Leetcode 60. Permutation Sequence (HARD)
class Solution {
public:
    string helper(string str, int k, string ans) {
        int n = str.length();
        if (n == 1) {   // base case
            ans += str;
            return ans;
        }

        // factorial of (n-1)
        int fact = 1;
        for (int i = 2; i <= n - 1; i++) {
            fact *= i;
        }

        int idx = k / fact;
        if (k % fact == 0) idx--; // adjust for 1-based indexing

        char ch = str[idx];
        string left = str.substr(0, idx);
        string right = str.substr(idx + 1);
        
        int q;
        if (k % fact == 0) q = fact;
        else q = k % fact;

        return helper(left + right, q, ans + ch);
    }

    string getPermutation(int n, int k) {
        string str = "";
        for (int i = 1; i <= n; i++) {  // should start from 1, not 0
            str += to_string(i);
        }
        return helper(str, k, "");
    }
};
