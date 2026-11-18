//TODO: Infix Evaluation with Brackets
# include <bits/stdc++.h>
using namespace std;

int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    else { //ch=='*' || ch=='/'
        return 2;
    }
}

int solve(int val1, int val2, int ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}

    
int main(){
    
    string s = "(7+9)*4/8-3";
    // We need 2 stacks one for Value and one for operators
    stack<int> val;
    stack<char> op;
    for(int i=0; i<s.length();i++){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);

        else{ // s[i] is *, / , +, - ,( , ) 
            if(op.size()==0 || s[i]=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop(); 
                    int ans = solve(val1,val2,ch);
                    val.push(ans); 
                }
                op.pop(); //popping the opening bkt
            }
            else if(op.top()=='(' || prio(s[i])>prio(op.top())){
                    op.push(s[i]);
            }
            else{// prio(s[i]) <= prio(op.top())
                while(op.size()>0 && prio(s[i]) <= prio(op.top())){
                    // do val1 op val2.
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop(); 
                    int ans = solve(val1,val2,ch);
                    val.push(ans); 
                }
                op.push(s[i]);
            }
        }
    }

    // The operator Stack can still have values
    // so make it empty 
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop(); 
        int ans = solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top();
    
    return 0;
}


//TODO: Infix to prefix Conversion with Brackets
# include <bits/stdc++.h>
using namespace std;

int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    else { //ch=='*' || ch=='/'
        return 2;
    }
}

    
int main(){
    
    string s = "(7+9)*4/8-3";
    cout<<s<<endl;
    // We need 2 stacks one for Value and one for operators
    stack<string> val;
    stack<char> op;
    for(int i=0; i<s.length();i++){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));

        else{ // s[i] is *, / , +, - ,( , ) 
            if(op.size()==0 || s[i]=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop(); 
                    string ans = ch+val1+val2;
                    val.push(ans); 
                }
                op.pop(); //popping the opening bkt
            }
            else if(op.top()=='(' || prio(s[i])>prio(op.top())){
                    op.push(s[i]);
            }
            else{// prio(s[i]) <= prio(op.top())
                while(op.size()>0 && prio(s[i]) <= prio(op.top())){
                    // do val1 op val2.
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop(); 
                    string ans = ch+val1+val2;
                    val.push(ans); 
                }
                op.push(s[i]);
            }
        }
    }

    // The operator Stack can still have values
    // so make it empty 
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop(); 
        string ans = ch+val1+val2;
        val.push(ans); 
    }
    cout<<val.top()<<endl;
    // cout<<int (val.top())<<endl;
    
    return 0;
}


//TODO: Infix to postfix Conversion with Brackets
# include <bits/stdc++.h>
using namespace std;

int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    else { //ch=='*' || ch=='/'
        return 2;
    }
}

    
int main(){
    
    string s = "(7+9)*4/8-3";
    cout<<s<<endl;
    // We need 2 stacks one for Value and one for operators
    stack<string> val;
    stack<char> op;
    for(int i=0; i<s.length();i++){
        // check if s[i] is a digit b/w (0-9)
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));

        else{ // s[i] is *, / , +, - ,( , ) 
            if(op.size()==0 || s[i]=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop(); 
                    string ans = val1+val2+ch;
                    val.push(ans); 
                }
                op.pop(); //popping the opening bkt
            }
            else if(op.top()=='(' || prio(s[i])>prio(op.top())){
                    op.push(s[i]);
            }
            else{// prio(s[i]) <= prio(op.top())
                while(op.size()>0 && prio(s[i]) <= prio(op.top())){
                    // do val1 op val2.
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop(); 
                    string ans = val1+val2+ch;
                    val.push(ans); 
                }
                op.push(s[i]);
            }
        }
    }

    // The operator Stack can still have values
    // so make it empty 
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop(); 
        string ans = val1+val2+ch;
        val.push(ans); 
    }
    cout<<val.top()<<endl;
    // cout<<int (val.top())<<endl;
    
    return 0;
}


