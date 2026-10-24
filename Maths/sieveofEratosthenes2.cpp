// 2507 : Smallest value after replacing with the sum of prime factors
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

int smallestValue(int n){
    if(isprime(n)) return n;
    int sum = 0;
    // Finding the prime factors of n
    for(int i=2; i<sqrt(n); i++){
        if(n%i==0 && isprime(i)) {
            int m = n;
            while(m%i==0){
                sum += i;
                m /= i;
            }
        }
    }
    for(int i=sqrt(n); i>=2; i--){
        if(n%i==0 && isprime(n/i)){
            int m = n;
            while(m%(n/i)==0){
                sum += (n/i);
                m /= (n/i);
            }
        }
    }
    if(sum==n) return n; // only in case of 4 = 2^2 => 2+2=4 so infinite loop
    return smallestValue(sum); // Recursive call
}

int main(){
    int n = 15;
    cout << smallestValue(n);
    return 0;
}


// 204: count prime
# include <bits/stdc++.h>
using namespace std;

void fillSieve(vector<bool>& sieve){
    int n = sieve.size()-1;
    for(int i=2; i<=sqrt(n); i++){
        for(int j=i*2; j<=n; j+=i){
            sieve[j] = 0;
        }
    }
}

int countPrimes(int n) {
        if(n<=2) return 0;
        int count = 0;
        vector<bool> sieve(n+1,1); //1 means prime and 0 means not prime
        fillSieve(sieve);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2; i<n; i++){
            if(sieve[i]==1) count++;
        }
        return count;
}

int main(){
    
    int n = 10;
    cout<<countPrimes(n);
    return 0;
}

// 2521 : Distinct prime factors of product of Array
# include <bits/stdc++.h>
using namespace std;

void fillSieve(vector<bool>& sieve){
        int n = sieve.size()-1;
        for(int i=2; i<=sqrt(n); i++){
            for(int j=i*2; j<=n; j+=i){
                sieve[j] = 0;
            }
        }
    }
    
int main(){
    
    vector<int> nums = {2,4,3,7,10,6};
    int n = nums.size();
        // Finding the maximum Element from the given Vector
        int mx = -1; 
        for(int i=0; i<n; i++){
            mx = max(mx,nums[i]);
        }

        // now finding all the prime no. till our max Element using sieve method
        vector<bool> sieve(mx+1,1);
        if(mx+1>0) sieve[0]=0;
        if(mx+1>1) sieve[1]=0;
        fillSieve(sieve);

        // separating all the prime no. in a separate vector
        vector<int> primes;
        for(int i=2; i<=mx; i++){
            if(sieve[i]==1) primes.push_back(i);
        }

        // Now creating a taken vector for final ans
        vector<bool> taken(primes.size(),0);
        for(int i=0; i<nums.size(); i++){
            int ele = nums[i];
            for(int j=0; j<primes.size(); j++){
                if(primes[j]>ele) break;
                if(ele%primes[j]==0){
                    taken[j]=1;
                }
            }
        }

        int count = 0;
        for(int i=0; i<taken.size(); i++){
            if(taken[i]==1) count++;
        }
        cout<<count;
    
    return 0;
}

// 650: 2 Keys keyboard
# include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0) return 0;
        }
        return 1;
    }

    int greatestfactor(int n){
        for(int i=n/2; i>=1; i--){
            if(n%i==0) return i;
        }
        return 1;
    }
    
int main(){
    int n = 90;
    int count = 0;
        while(n>1){
            if(isprime(n)){
                count+=n;
                break;
            }
            int highest_factor = greatestfactor(n);
            count += (n/highest_factor);
            n = highest_factor;
        }
        cout<<count;
    
    return 0;
}