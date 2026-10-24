// Basic and Concept Building
# include <bits/stdc++.h>
using namespace std;

// T.C = sqrt(n)
void isprime(int n){
    bool flag = true;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            cout<<"n is not a prime No."<<endl;
            flag = false;
            break;
        }
    }
    if(flag==true) cout<<"n is a prime No."<<endl;

}

// Total No. of factors of n (T.C = sqrt(n))
void factor(int n){
    for(int i=1; i<sqrt(n); i++){
        if(n%i==0) cout<<i<<" ";
    }
    for(int i=sqrt(n); i>=1; i--){
        if(n%i==0) cout<<n/i<<" ";
    }

}

int main(){
    
    // isprime(15);
    factor(60);

    return 0;
}


// 2614 : Prime in Diagonal
# include <bits/stdc++.h>
using namespace std;

bool is_prime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    
    vector<vector<int>> nums = {{1,2,3},{5,6,7},{9,10,11}};
    int n = nums.size();
        int max_prime = 0;
        for(int i=0; i<n; i++){
            if(is_prime(nums[i][i])){
                max_prime = max(max_prime,nums[i][i]);
            }
            if(is_prime(nums[i][n-i-1])){
                max_prime = max(max_prime,nums[i][n-i-1]);
            } 
        }
        if(max_prime==1) cout<<0;
        else cout<<max_prime;

    return 0;
}

// 507 : Perfect Number
# include <bits/stdc++.h>
using namespace std;
    
int main(){
    
        int num = 28;
        int sum = 0;
        for(int i=1; i<sqrt(num); i++){
           if(num%i==0){
             sum+=i;
             if(i!=1)sum+=num/i; //To avoid the number itself
           }

        }
        
        if(sum==num) cout<<true;
        else cout<<false;
    
    
    return 0;
}