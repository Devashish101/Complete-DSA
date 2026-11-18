// TODO: Prefix Evaluation 

// FIXME: 1. Here we iterate from reverse order.
        //2. 1st popped ele is stored in val1 then val2 becoz of rev iteration.
# include <bits/stdc++.h>
using namespace std;

int solve(int val1, int val2, int ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
    
int main(){
    
    string s = "-/*+79483"; //Prefix Expression
    // We need only 1 stacks
    stack<int> val;
    for(int i=s.length()-1; i>=0; i--){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);

        else{ // s[i] is *, / , +, - ,( , ) 
            int val1 = val.top();
            val.pop();
            int val2 = val.top();
            val.pop();
            int ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top(); 
    return 0;
}

//TODO: Prefix to Infix Conversion
# include <bits/stdc++.h>
using namespace std;
    
int main(){ 
    string s = "-/*+79483"; //Postfix Expression
    // We need only 1 stacks
    stack<string> val;
    for(int i=s.length()-1; i>=0; i--){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));

        else{ // s[i] is *, / , +, - ,( , ) 
            string val1 = val.top();
            val.pop();
            string val2 = val.top();
            val.pop();
            string ans = val1+s[i]+val2;
            val.push(ans);
        }
    }
    cout<<val.top(); 
    return 0;
}

//TODO: Prefix to Postfix Conversion
# include <bits/stdc++.h>
using namespace std;
    
int main(){ 
    string s = "-/*+79483"; //Postfix Expression
    // We need only 1 stacks
    stack<string> val;
    for(int i=s.length()-1; i>=0; i--){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));

        else{ // s[i] is *, / , +, - ,( , ) 
            string val1 = val.top();
            val.pop();
            string val2 = val.top();
            val.pop();
            string ans = val1+val2+s[i];
            val.push(ans);
        }
    }
    cout<<val.top(); 
    return 0;
}