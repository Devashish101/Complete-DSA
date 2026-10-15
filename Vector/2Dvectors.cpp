# include <bits/stdc++.h>
using namespace std;

void change2Dvector(vector<vector<int>> &v){
    v[0][2] = 20;
}

void printlen(vector<vector<int>> &v){
    cout<<v.size();
}

int main(){
    // Initialization
    vector<vector<int>> v;
    vector<vector<int>> v4(3,vector<int>(4)); // 2D vector of 3 rows and 4 cols
    vector<vector<int>> v5(3,vector<int>(4,12)); // 2D vector of 3 rows and 4 cols having values 12 12 12 12
    vector<vector<int>> v6{{10,20,30},{40,50,60}};

    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int>v2;
    v2.push_back(4);
    v2.push_back(5);

    vector<int>v3;
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(10);

    //{{1,2,3},{4,5},{6,7,8,9,10}}
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    //  Accesing the elements of the vector
    cout<<v[0][2]<<"\n";

    // 1. passing 2Dvector to a function
    change2Dvector(v);
    cout<<v[0][2]<<"\n";

    // printing the len of vector without passing its size
    printlen(v); // len = 3 ({v1},{v2},{v3})

    return 0;
} 
