// Longest Common Prefix of Strings -> GFG.
# include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    class Node{
    public:
        char data;
        bool terminal;
        unordered_map<char, Node*>children;

        Node(char data){
            this->data = data;
            this->terminal = false;
        }
    };
    
    class Trie{
    public:
        Node* root;
        Trie(){
            root = new Node('\0');
        }

        void insert(string word){
            Node* curr = root;
            for(int i=0; i<word.length(); i++){
                char ch = word[i];
                if(curr->children.count(ch)){
                    curr = curr->children[ch];
                }else{
                    Node* child = new Node(ch);
                    curr->children[ch] = child;
                    curr = child;
                }
            }
            curr->terminal = true;
        }

        string search(string str) {
            Node* curr = root;

            while (curr->children.size() == 1) {
                auto child = curr->children.begin(); // get the single child
                curr = child->second;                 // move to it
                str += curr->data;                 // append its character
            }

            return str;
        }
    };
    
    string longestCommonPrefix(vector<string> words) {
        Trie tr;

        for(int i=0; i<words.size(); i++){
            tr.insert(words[i]);
        }

        string str = "";
        return tr.search(str);
        
    }
};

// Longest Valid Word with All Prefixes - GFG
class Solution {
public:
    class Node {
    public:
        char data;
        bool terminal;
        unordered_map<char, Node*> children;

        Node(char data) {
            this->data = data;
            this->terminal = false;
        }
    };

    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node('\0');
        }

        void insert(string word) {
            Node* curr = root;
            for (int i = 0; i < word.length(); i++) {
                char ch = word[i];
                if (curr->children.count(ch)) {
                    curr = curr->children[ch];
                } else {
                    Node* child = new Node(ch);
                    curr->children[ch] = child;
                    curr = child;
                }
            }
            curr->terminal = true;
        }

        // checks that every prefix of 'word' is marked terminal
        bool isValid(string word) {
            Node* curr = root;
            for (int i = 0; i < word.length(); i++) {
                char ch = word[i];
                if (!curr->children.count(ch)) return false;
                curr = curr->children[ch];
                if (!curr->terminal) return false; // prefix must be a full word too
            }
            return true;
        }
    };

    string longestValidWord(vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i]);
        }

        string result = "";
        for (int i = 0; i < words.size(); i++) {
            if (trie.isValid(words[i])) {
                if (words[i].length() > result.length()) {
                    result = words[i];
                }
                else if((words[i].length() == result.length() && words[i] < result)) {
                    result = words[i];
                }
            }
        }
        return result;
    }
};

// Count Distinct Substrings -GFG
// Brute Force Approach
class Solution {
  public:
    unordered_set<string> st;
    void substrings(int idx, string str){
        string s = to_string (str[idx]);
        if(!st.count(s))st.insert(s);
        for(int i=idx+1; i<str.length(); i++){
            s += str[i];
            if(!st.count(s))st.insert(s);
        }
        return;
    }
    int countSubs(string& s) {
        int n = s.length();
        for(int i=0; i<n; i++){
            substrings(i, s);
        }
        return st.size();
    }
};

// Trie Approach
class Solution {
  public:
    
    class Node{
    public:
        char data;
        unordered_map<char, Node*>children;
        bool terminal;
        
        Node(char data){
            this->data = data;
            this->terminal = false;
        }
    };
    
    class Trie{
    public:
        Node* root = new Node('\0');
        
        void insert(char ch, Node*& curr, int& count){
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            }else{
                count++;
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }
        }
    };
    
    int countSubs(string& s) {
        Trie trie;
        int n = s.length();
        
        int count = 0;
        for(int i=0; i<n; i++){
            Node* curr = trie.root;

            for(int j=i; j<n; j++){
                trie.insert(s[j], curr, count);
            }
        }
        return count;
    }
};
