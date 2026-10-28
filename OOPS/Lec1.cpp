// ------------------------------------------------- Classes and Objects ----------------------------------------------
# include <bits/stdc++.h>
using namespace std;

// My own Data Type(Student)
class Student{
public:
    string name;
    int age;
    int roll;
    float sgpa;
};

class Car{
public:
    string name;
    int price;
    string type;
};

void print(Car c){
    cout<<c.name<<" "<<c.price<<" "<<c.type<<"\n";
}

void change(Car c){
    c.name = "Mercedes";
}
    
int main(){
    
    // Initializing the Value without using Constructors
    Student s1;
    s1.name = "Devashish";
    s1.age = 22;
    s1.roll = 72; 
    // cin>>s1.roll;
    s1.sgpa = 7.4;

    Student s2;
    s2.name = "Bhargav";
    s2.age = 22;
    // cin>>s2.age;
    s2.roll = 64;
    s2.sgpa = 8.5;

    // cout<<s1.name<<" "<<s1.age<<" "<<s1.sgpa<<endl;
    // cout<<s2.name<<" "<<s2.age<<" "<<s2.sgpa<<endl;

    Car c1;
    c1.name = "BMW";
    c1.price = 7500000;
    c1.type = "sports";

    Car c2;
    c2.name = "Defender";
    c2.price = 15000000;
    c2.type = "SUV";

    Car c3;
    c3.name = "Porshe";
    c3.price = 10000000;
    c3.type = "Sports car";

    // print(c1);
    // print(c2);
    // print(c3);
    
    change(c1); // pass By value
    print(c1);

    return 0;
}