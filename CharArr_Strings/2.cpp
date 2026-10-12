//                                                   String level-1
# include<iostream>
# include <string.h>
using namespace std; 

int main(){
    //creation
    string name;

    //print
    // cout <<"enter your string"<<"\n";

    //input
    // cin >> name; 
    // getline(cin,name);

    //printing the 1st character of string
    //cout<<" The 1st character of string is :"<<name[0]<<endl;

    int i=0;
    while(name[i] != '\0'){
        // cout<<"At Index :"<<i<<" "<<name[i]<<endl;
        i++;
    }

    int value=name[5];
    // cout<<value<<endl;


    // cout<<"length of string is :"<<name.length()<<endl;
    // cout<<"my string is empty or not :"<<name.empty()<<endl;


    // cout<<"character present in string at 0th position is :"<<name.at(0)<<endl;
    // cout<<"character present in string at 0th position is :"<<name[0]<<endl;


    // cout<<"front character of string is :"<<name.front()<<endl;
    // cout<<"back character of string is :"<<name.back()<<endl;


    string str1="hello";
    string str2="c++";
    // cout<<"before using append "<<"str1 is :"<<str1<<" and "<<"str2 is :"<<str2<<endl;
    // cout<<"after using append on str1 and str2 :"<<str1.append(str2);


    string temp ="this is my car";
    temp.erase(4,3);
    // cout<<temp<<endl;
    string middle="favourite";
    temp.insert(10,middle);
    // cout<<"printing the temp after insertion :"<<temp<<endl;


    name.push_back('r');
    // cout<<name<<endl;
    name.pop_back();
    // cout<<name<<endl;


     string str="my favourite car is GTR ";
    //  cout<<str.substr(3,9);
    //  cout<<str.find("favourite");
     string str3="GTR"; 

     if(str.find(str3) == string::npos){
        //i.e not found
        // cout<<"not found"<<"\n";
     }
     else{
        //found
        // cout<<"found"<<"\n";
     }


    string str4="hii";
    string str5="hii";
    if(str4.compare(str5)==0){
        // cout<<"matching"<<"\n";
    }
    else{
        // cout<<"not matching"<<endl;
    } 


    string desc="by using 'substr' fun we can print some part of the main string (:";
    // cout<<desc.substr(18,3);

    // Acessing The elements of the string
    string str6 = "Apna College";

    for(int i=0; i<str6.length(); i++){ // Normal for loop
        cout<<str6[i]<<" ";
    }
    cout<<endl;

    for(char ch: str6){ // This is by for-each Loop
        cout<<ch<<" ";
    }
    cout<<endl;

    return 0;
 }