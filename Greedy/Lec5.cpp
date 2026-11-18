// Minimum Platforms - GFG.
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    vector<vector<int>>finalarr;
    for(int i=0; i<arr.size(); i++){
        finalarr.push_back({arr[i],dep[i]});
    }
    sort(finalarr.begin(),finalarr.end());
    priority_queue<int,vector<int>,greater<int> > pq;
    pq.push(finalarr[0][1]);
    
    int platforms = 1;
    for(int i=1; i<finalarr.size(); i++){
        if(pq.top() >= finalarr[i][0]){
            platforms++;
        }
        else{
            pq.pop();
        }
        pq.push(finalarr[i][1]);
    }
    cout<<platforms;
}

//Leetcode 678. Valid Parenthesis String
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    string s = "((*))())";
    stack<int> open;
    stack<int> star;

    for(int i = 0; i < s.length(); i++) {

        if(s[i] == '(') {
            open.push(i);
        }
        else if(s[i] == '*') {
            star.push(i);
        }
        else { // ')'

            if(!open.empty()) {
                open.pop();
            }
            else if(!star.empty()) {
                star.pop();
            }
            else {
                return false;
            }
        }
    }

    // Use '*' as ')' to match remaining '('
    while(!open.empty() && !star.empty()) {

        // '*' must appear after '('
        if(open.top() > star.top()) {
            return false;
        }
        open.pop();
        star.pop();
    }

    return open.empty();
}

// Leetcode 135. Candy
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int>ratings = {1,2,2,3,1,4,5,2}; //13
    int n = ratings.size();
    vector<int>left(n,1);

    // Distribution according to left neighbour
    for(int i=1; i<n; i++){
        if(ratings[i-1] < ratings[i]) left[i] = left[i-1]+1;
    }

    // Distribution according to right neighbour
    vector<int>right(n,1);
    for(int i=n-2; i>=0; i--){
        if(ratings[i] > ratings[i+1]) right[i] = right[i+1]+1;
    }

    int sum = 0; // Max of left and right will be added in sum
    for(int i=0; i<n; i++){
        sum += max(left[i],right[i]);
    }
    return sum;
}

// Leetcode 134: Gas Station
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int>gas = {1,2,3,4,5};
    vector<int>cost = {3,4,5,1,2};

    int totalgas = 0, totalcost = 0;
    for(int i=0; i<gas.size(); i++){
        totalgas += gas[i];
        totalcost += cost[i];
    }
    if(totalcost > totalgas)return -1;

    int idx = 0, currgas = 0;
    int i=0;
    while(i < gas.size()){
        currgas += (gas[i]-cost[i]);
        if(currgas < 0){
            idx = i+1;
            currgas = 0;
        }
        i++;
    }
    cout<<idx;
}