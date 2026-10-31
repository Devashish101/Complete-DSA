//--------------------------------------- Access modifiers & Getter and Setters ---------------------------------------------------
// Abstraction - Hiding the internal working of a class and showing only the necessary functions or information.
                                    /*              ABSTRACTION
                                                        |
                                                +--------+--------+
                                                |                 |
                                        Access Specifiers   Abstract Class
                                                |                 |
                                        private / public      Pure Virtual
                                                                Function   */

// Encapsulation means wrapping data and the functions that operate on that data into a single unit (class) and controlling access to that data.
// Mainly to achieve data protection and controlled access.
                                            /*            Class
                                                    +-------------+
                                                    |    Data     |  ← variables
                                                    |-------------|
                                                    |  Functions  |  ← methods
                                                    +-------------+ */

// TODO: As Class and Struct are same thing the only diff is their default access Modifiers.
// -> In Class Default Access Modifier is " private ".
// -> In struct Default Access Modifier is " Public ".
# include <bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int rno;

    Student(){ // Default constructor

    }

    Student(string name, int rno, float marks){ // parameterized constructor
        this->name = name;
        this->rno = rno;
        this->marks = marks;
    }
    
    float getMarks(){ // Getter Function
        return marks;
    }

    void setMarks(float newMarks){ // Setter Function
        marks = newMarks;
    }

private:
    float marks;
};
    
int main(){
    //TODO: We can initialize and use private members through a constructor, because the constructor is a member of the class.

    Student s1("Tushar", 65, 85.5);  // Hence this is Valid becoz we are setting the marks using constructor 
    // cout<<s1.marks<<endl;// This is Invalid becoz we are trying to access the private member directly(for getting the marks).

    Student s2;
    s2.name = "Rupesh";
    s2.rno = 88;
    // s2.marks = 82.7; // Here this is also InValid becoz we are trying to access the private member directly(for setting the marks).

    //TODO: Hence We can't " set " or " get " the private members directly.
    //FIXME: For this we use getter and Setter functions.
    //FIXME: Getter and Setter are usually public functions used to access private data members safely.
    cout<<s1.getMarks()<<endl; // 85.5
    
    cout<<s2.getMarks()<<endl; // garbage value
    s2.setMarks(82.7);
    cout<<s2.getMarks()<<endl; // 82.7
    
    return 0;
}