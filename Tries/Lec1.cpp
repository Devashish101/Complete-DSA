// Trie -> Prefix Tree or N child Tree or Generic Tree
// A specialized tree-based data structure used to efficiently store and retrieve keys in a dataset of strings
// -> It helps us in prefix matching ex - In searching Contacts

//Leetcode 208. Implement Trie (Prefix Tree)
# include <bits/stdc++.h>
using namespace std;

class Node{
 public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;
    Node(char data){
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
        for(int i=0; i<word.size(); i++){
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
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            }else{
               return false;
            }
        }
        return(curr->terminal)?true:false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            }else{
               return false;
            }
        }
        return true;
    }
};

// Leetcode 1804: Implement Trie ||
# include <bits/stdc++.h>
using namespace std;

class Node{
 public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;
    int countWordsEndingHere;
    int countWordsStarting;

    Node(char data){
        this->data = data;
        this->terminal = false;
        this->countWordsEndingHere = this->countWordsStarting = 0;
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
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch];
                curr->countWordsStarting++;
            }else{
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr->countWordsStarting++;
                curr = curr->children[ch];
            }
        }
        curr->terminal = true;
        curr->countWordsEndingHere++;
    }

    int countWordsEqualTo(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            }else{
                return 0;
            }
        }
        return curr->countWordsEndingHere;
    }

    int countWordsStartingWith(string prefix) {
        Node* curr = root;
        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            }else{
                return 0;
            }
        }
        return curr->countWordsStarting;
    }

    void erase(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch];
                curr->countWordsStarting--;
            }
        }
        curr->countWordsEndingHere--;
    }
};

// Leetcode 421
