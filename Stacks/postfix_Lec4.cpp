//TODO: Postfix Evaluation 
# include <bits/stdc++.h>
using namespace std;

int solve(int val1, int val2, int ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
    
int main(){
    
    string s = "79+4*8/3-"; //Postfix Expression
    // We need only 1 stacks
    stack<int> val;
    for(int i=0; i<s.length();i++){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);

        else{ // s[i] is *, / , +, - ,( , ) 
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top(); 
    return 0;
}


//TODO: Postfix to infix Conversion
# include <bits/stdc++.h>
using namespace std;
    
int main(){ 
    string s = "79+4*8/3-"; //Postfix Expression
    // We need only 1 stacks
    stack<string> val;
    for(int i=0; i<s.length();i++){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]));

        else{ // s[i] is *, / , +, - ,( , ) 
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = val1+s[i]+val2;
            val.push(ans);
        }
    }
    cout<<val.top(); 
    return 0;
}

//TODO: Postfix to infix Conversion
# include <bits/stdc++.h>
using namespace std;
    
int main(){ 
    string s = "79+4*8/3-"; //Postfix Expression
    // We need only 1 stacks
    stack<string> val;
    for(int i=0; i<s.length();i++){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));

        else{ // s[i] is *, / , +, - ,( , ) 
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = val1+s[i]+val2;
            val.push(ans);
        }
    }
    cout<<val.top(); 
    return 0;
}

// Postfix to prefix Conversion
# include <bits/stdc++.h>
using namespace std;
    
int main(){ 
    string s = "79+4*8/3-"; //Postfix Expression
    // We need only 1 stacks
    stack<string> val;
    for(int i=0; i<s.length();i++){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));

        else{ // s[i] is *, / , +, - ,( , ) 
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = s[i]+val1+val2;
            val.push(ans);
        }
    }
    cout<<val.top(); 
    return 0;
}
