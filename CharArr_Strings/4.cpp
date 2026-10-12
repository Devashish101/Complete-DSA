// About StringStream Built-in Library
# include <bits/stdc++.h>
using namespace std;
int main(){
    
    string str = "Hello Myself Devashish";
    stringstream ss(str);//passing our string in stringstream for parsing the input from it

    string temp;
    while(ss>>temp){ //taking input from ss in temp
        cout<<temp<<"\n"; //printing the taken input
    }
    
    return 0;
}

// About Built-in Functions of String 
# include <bits/stdc++.h>
using namespace std;
int main(){

    // 1. stoi => Used for Converting string to Integer
    string str = "123456";
    int x = stoi(str);
    cout<<x+1<<endl;;

    // 2. stoll => Used for Converting string to long long
    string str2 = "1234567891234";
    long long y = stoll(str2);
    cout<<y+1;

    return 0;
}