// --------------------------------------------- Constructors --------------------------------------------
# include <bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int age;
    int roll;
    float sgpa;

    // parametarized Constructor with only 3 parameters
    Student(string s, int ag, int rol){
        name = s;
        age = ag;
        roll = rol;
    }
};

class Bike{
public:
    string name;
    int price;
    int cc;

    //TODO: MULTIPLE CONSTRUCTORs:-

    // Constructor 1
    Bike(){ // Dfault Constructor

    }

    // Constructor 2 -> with 2 parameters
    // Making a parametarized Constructor using this Keyword
    Bike(string name, int price){
        this->name = name;
        this->price = price;
    }

    // Constructor 3 -> with 3 parameters
    // Making a parametarized Constructor using this Keyword
    Bike(string name, int price, int cc){
        this->name = name;
        this->price = price;
        this->cc = cc;
    }

    // TODO: Functions Inside Class
    void print(){
        cout<<name<<" "<<price<<" "<<cc<<endl;
    }
    
    int OnRoadprice(){
        return 500000+price;
    }
};

int main(){
    
    // Initializing the Value using Constructors
    Student s1("Amit",21, 17);
    s1.sgpa = 7.5; // giving the value Seperatly
    s1.age = 15; // overriding my pre-defined value

    Student s2("Sumit",20, 71);
    s2.sgpa = 8.1;

    cout<<s1.name<<" "<<s1.age<<" "<<s1.sgpa<<endl;
    cout<<s2.name<<" "<<s2.age<<" "<<s2.sgpa<<endl;
    
    // This way of initialization is possible due to my parametarized Constructor 3
    Bike b1("ZX10R", 1200000, 800);

    // This way of initialization is possible due to my parametarized Constructor 2
    Bike b2("Harley Davidson", 2200000);
    b2.cc = 1500;

    // This way of initialization is posssible due to default Constructor
    Bike b3;
    b3.name = "BMW";
    b3.price = 2500000;
    b3.cc = 1000;

    Bike b4 = b1; // Deep Copy
    b4.name = "H2R";

    Bike b5(b1); // Copy constructor -> Deep Copy
    b5.price = 2500000;
    
    cout<<b1.name<<" "<<b1.price<<" "<<b1.cc<<endl;
    b2.print();
    b3.print();
    b4.print();
    b5.print();

    cout<<b1.OnRoadprice()<<"\n"; // pass by Value
}