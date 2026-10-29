//---------------------------------------------------  Object Pointer and Dynamic Allocation ----------------------------------------------
# include <bits/stdc++.h>
using namespace std;

class Cricketer{
public:

    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg){
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }
};

void change(Cricketer* c1){ // we are receving the add. of a cricketer obj
    // Modifying the obj attributes/values using pointers

    // (*c1).avg = 68.5; // Method 1
    c1->avg = 68.5;     //  Method 2
}
    
int main(){
    
    Cricketer c1("virat kohli", 25000, 55.2);
    Cricketer* c2 = new Cricketer("Rohit Sharma", 18000, 47.8); // Dynamic allocation using pointrs
    cout<<(*c2).name<<c2->runs<<endl;
    
    Cricketer* p1 = &c1;
    cout<<(*p1).runs<<endl; // c1.runs

    (*p1).avg = 56.5; // c1.avg is modified.
    cout<<(*p1).avg<<endl;

    change(&c1);
    cout<<c1.avg<<"\n";

}