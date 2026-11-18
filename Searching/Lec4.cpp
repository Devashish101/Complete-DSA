//                                          Binary Search on Answers.
// TODO: Leetcode 1011: Capacity to ship packages within D days.
# include <bits/stdc++.h>
using namespace std;

bool check (int mid, vector<int>& weights, int days){
    int n = weights.size();
    int m = mid;
    int count = 1;
    for(int i=0; i<n; i++){
        if(m>=weights[i]){
            m -= weights[i];
        }
        else{
            count++;
            m = mid;   
            m -= weights[i];
        }
    }
    if(count>days) return false;
    else return true;
}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    int n = weights.size();
    int max = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        if(max<weights[i]) max = weights[i];
        sum += weights[i];
    }
    int lo = max;
    int hi = sum;
    int minCapacity = sum;
    while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        if(check(mid,weights,days)){
            minCapacity = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout<<minCapacity;
}

// TODO: Leetcode 875: Capacity to ship packages within D days.
# include <bits/stdc++.h>
using namespace std;

bool check(int speed,vector<int>& piles, int h){
    long long count = 0;
    int n = piles.size();
    for(int i=0; i<n; i++){
            if(speed>=piles[i]) count++;
            else if(piles[i]%speed==0) count+= piles[i]/speed;//imp
            else count+=piles[i]/speed +1; //v.imp => In case of piles[i]%speed != 0
            if(count>h) return false;
    }
    return true;
}

int main(){
    vector<int> piles = {30,11,23,4,20};
    int h = 5;

    int n = piles.size();
    int mx = -1;
    for(int i=0; i<n; i++){
        mx = max(mx,piles[i]);
    }
    int lo = 1;
    int hi = mx;
    int ans = -1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid,piles,h)==true){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ans;
}

// TODO: Minimum Time to Complete Trips
# include <bits/stdc++.h>
using namespace std;

bool check(long long mid,vector<int>& time, int totalTrips){
    long long trips = 0;
    int n = time.size();
    // 1 2 3 midhrs = 2
    for(int i=0; i<n; i++){
        trips+=(long long)mid/(long long)time[i];
    }
    if(trips<totalTrips) return false;
    else return true;
}

int main(){
    vector<int> time = {1,2,3};
    int totalTrips = 5;

    int n = time.size();
    int mx = -1;
    for(int i=0; i<n; i++){
        mx = max(mx,time[i]);
    }
    long long lo = 1;
    long long hi = (long long)mx*(long long)totalTrips;
    long long ans = -1;
    while(lo<=hi){
        long long mid = lo+(hi-lo)/2;
        if(check(mid,time,totalTrips)==true){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid + 1;
    }
    return ans;
}