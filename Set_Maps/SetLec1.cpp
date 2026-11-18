
// Leetcode 2442: Count no. of Distinct integers after reverse opern
# include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
        int rev = 0;
        while(n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
    
int main(){
    
    vector<int> nums = {1,13,10,12,31};
    int n = nums.size();
        unordered_set<int> s;
        
        for(int i=0; i<n; i++){
            int newnum = reverse(nums[i]);
            s.insert(nums[i]);
            s.insert(newnum);
        }
        cout<< s.size();
    
    return 0;
}

//Leetcode : 2744 Find the Maximum number of string pairs
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<string> words = {"cd","ac","dc","ca","zz"};
        int n = words.size();
        unordered_set<string> s(words.begin(),words.end());
        int count = 0;
        for(int i=0; i<n; i++){
           string rev = words[i];
           reverse(rev.begin(),rev.end());
           if(rev==words[i]) continue;
           if(s.find(rev) != s.end()){
                count++;
                s.erase(words[i]);
           }

        }
        cout<< count;
    
    return 0;
}