// ------------------------------------------------------------------ Polymorphism ---------------------------------------------------------
// polymorphism allows the same function/operator to behave differently in different situations.
/*                   POLYMORPHISM
                         |
             +-----------+-----------+
             |                       |
     Compile-Time              Run-Time
     Polymorphism              Polymorphism
             |                       |
       +-----+-----+             Function
       |           |             Overriding
Function       Operator              |
Overloading     Overloading       virtual
                                   function  */

//FIXME: Compile - Time Polymorphism
//TODO: 1. Function Overloading:-
// Same function name, but different parameters, in the same class.
# include <bits/stdc++.h>
using namespace std;

class Calculator {
public:

    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    float add(float a, float b) {
        return a + b;
    }
};

    
int main(){
    
    Calculator c;

    cout << c.add(2, 3);          // add(int, int)
    cout << c.add(2, 3, 4);       // add(int, int, int)
    cout << c.add(2.5f, 3.5f);    // add(float, float)
    
}

// 2. Operator Overloading:-
// Operator overloading means teaching an operator like +, -, *, == how to work with your own class objects.
# include <bits/stdc++.h>
using namespace std;

class Fraction{
public:
    int num;
    int den;

    Fraction(int num, int den){
        this->num = num;
        this->den = den;
    }

    void display(){
        cout<<num<<" \ "<<den<<endl;
    }

    Fraction operator+(Fraction f){
        int newNum = this->num*f.den + f.num*this->den;
        int newDen = this->den*f.den;
        Fraction ans(newNum, newDen);
        return ans;
    }
    Fraction operator-(Fraction f){
        int newNum = this->num*f.den - f.num*this->den;
        int newDen = this->den*f.den;
        Fraction ans(newNum, newDen);
        return ans;
    }
    Fraction operator*(Fraction f){
        int newNum = this->num*f.num;
        int newDen = this->den*f.den;
        Fraction ans(newNum, newDen);
        return ans;
    }

};
    
int main(){
    
    Fraction f1(1,2);
    Fraction f2(2,4);
    f1.display();
    f2.display();
    // Fraction f3 = f1.add(f2);
    Fraction f3 = f1 + f2;
    f3.display();
    Fraction f4 = f1 - f2;
    f4.display();
    
    return 0;
}

//FIXME: Run - Time Polymorphism
//TODO: 1. Function Overriding
// Same function name + same parameters, but in parent and child classes.
# include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal sound";
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark";
    }
};
    
int main(){
    Dog d;
    d.sound();
}

//TODO: 2. Virtual Function
// A function declared with the virtual keyword in the parent class is called a virtual function.
// The virtual keyword tells C++: "Don't decide which sound() to call based only on the pointer type. Check the actual object at runtime."
#include <bits/stdc++.h>
using namespace std;

class Animal{
public:

    virtual void sound(){
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal{
public:

    void sound() override{
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal{
public:

    void sound() override{
        cout << "Cat meows" << endl;
    }
};

int main(){

    Animal* ptr;

    Dog d;
    Cat c;

    ptr = &d;
    ptr->sound();

    ptr = &c;
    ptr->sound();

}