// Leetcode 1005 -> Maximize sum of arr after k negations.
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int> arr = {2,-3,-1,5,-4}; // 13
    int k = 2;

    int sum = 0;
    for(int i=0; i<arr.size(); i++)sum+=arr[i];

    priority_queue<int, vector<int >, greater<int >>pq;
    for(int i=0; i<arr.size(); i++)pq.push(arr[i]);

    while(k--){
        int ele = pq.top();
        if(ele == 0)break;
        pq.pop();
        sum-=ele;
        pq.push(-ele);
        sum+=-ele;
    }
    cout<<sum;
    
    return 0;
}

// Fractional knapsack - GFG
# include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int>& a, pair<int,int>& b){
    double a1 = (1.0 * a.first) / a.second;
    double b1 = (1.0 * b.first) / b.second;

    return a1 > b1;
}
    
int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    vector<pair<int,int>> v;
    for(int i=0; i<val.size(); i++){
        v.push_back({val[i],wt[i]});
    }
    sort(v.begin(),v.end(),cmp);
    
    double maxVal = 0.0;
    for(int i=0; i<v.size(); i++){
        int val = v[i].first;
        int wt = v[i].second;
        
        if(capacity >= wt){
            maxVal += (double)val;
            capacity -= wt;
        }
        else{
            maxVal += ((double)val/wt)*capacity;
            break;
        }
    }
    cout<<maxVal;
}

// Leetcode 1710 : Maximum Units on a Truck
# include <bits/stdc++.h>
using namespace std;

static bool cmp1(vector<int>& a, vector<int>& b){
    return a[1] > b[1];
}
    
int main(){
    vector<vector<int>>boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    int truckSize = 10;

    sort(boxTypes.begin(), boxTypes.end(), cmp1);
    int maxUnit = 0;

    for(int i=0; i<boxTypes.size(); i++){
        int boxes = boxTypes[i][0];
        int units = boxTypes[i][1];

        if(truckSize >= boxes){
            maxUnit += (boxes*units);
            truckSize -= boxes;
        }
        else{ //truckSize < boxes
            maxUnit += (truckSize * units); 
            break;
        }
    }
    cout<<maxUnit;
}

// Leetcode 881. Boats to Save People
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    vector<int>people = {3,5,3,4};
    int limit = 5;

     sort(people.begin(),people.end());
        int boat = 0;
        int i = 0, j = people.size()-1;
        while(i <= j){
            if(people[i] + people[j] <= limit){ // Allocating a boat to a pair of combined wts less than or equl to limit.
                boat++;
                j--;
                i++;
            }
            else{ // Allocating a boat to a single heavy person.
                boat++;
                j--;
            }
        } 
        cout<<boat;
    
    return 0;
}


// Min Product Subset - GFG
# include <bits/stdc++.h>
using namespace std;

int minProd(vector<int>& arr) {
    int n = arr.size();
    
    int count_zero = 0, count_neg = 0, lowest_pos = INT_MAX;
    int largest_neg = INT_MIN, prod_pos = 1, prod_neg = 1;
    
    for(int i=0; i<n; i++){
        if(arr[i] < 0){
            count_neg++;
            largest_neg = max(largest_neg,arr[i]);
            prod_neg *= arr[i]; 
        }
        else if(arr[i] == 0)count_zero++;
        else{
            lowest_pos = min(lowest_pos,arr[i]);
            prod_pos *= arr[i];
        }
    }
    
    if(count_neg == 0){
        if(count_zero != 0)return 0;
        else return lowest_pos;
    }else{
        if(count_neg % 2 == 0){
            return(prod_neg/largest_neg)*prod_pos;
        }
        else{
            return (prod_neg*prod_pos);
        }
    }
    return -1;
}

int main(){
    
    vector<int>arr = {4, -2, 5};
    cout<<minProd(arr);
    return 0;
}

// Minimum Cost to Cut a Board into Squares - GFG.
# include <bits/stdc++.h>
using namespace std;

int minCost(int n, int m, vector<int>& x, vector<int>& y) {
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());
    
    int ans = 0;
    int hz = 1, vt = 1; // Intially 1 Horizontal and 1 Vertical Board.
    int h = 0, v = 0;
    while(v < x.size() && h < y.size()){
        if(x[v] > y[h]){ // In case of Vertical Cuts
            ans += (hz*x[v]); // Total cost = No. of horizontal blocks * cost of vertical cut.
            vt++; // No. vertical blocks will also increase by 1.
            
            v++;
        }
        else{ // In case of Horizontal Cuts
            ans += (vt*y[h]); // Total cost = No. of Vertical blocks * cost of Horizontal cut.
            hz++; // No. Horizontal blocks will also increase by 1.
            
            h++;
        }
    }
    // For Remaining Vertical cuts
    while(v < x.size()){
        ans += (hz*x[v]);
        vt++;
        
        v++;
    }
    
    // For Remaining Horizontal Cuts
    while(h < y.size()){
        ans += (vt*y[h]);
        hz++;
        
        h++;
    }
    return ans;
    
}
    
int main(){
    
    int n = 4, m = 6;
    vector<int> x = {2, 1, 3, 1, 4};
    vector<int> y = {4,1,2};

    cout<<minCost(n,m,x,y);
    
    return 0;
}

// Leetcode 2182 : Construct a string with repeatlimit
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    string s = "cczazcc";
    int repeatLimit = 3;

    unordered_map<char, int>mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }

    priority_queue<pair<char, int>>pq;
    for(auto m: mp){
        pq.push(m);
    }

    string str = "";
    while(!pq.empty()){
        pair<char,int> largest = pq.top();
        pq.pop();
        int len = min(largest.second, repeatLimit);
        for(int i=0; i<len; i++){
            str += largest.first;
        }

        if(largest.second - len > 0){
            pair<char,int> seclargest;

            if(!pq.empty()){
                seclargest = pq.top();
                str += seclargest.first;
                pq.pop();
            }
            
            else{
                cout<<str;
            }

            if(seclargest.second - 1 > 0)pq.push({seclargest.first, seclargest.second-1});
            pq.push({largest.first, largest.second-len});

        }

    }
    cout<<str;
    
    return 0;
}