// ----------------------------------------------------------- Single Inheritence --------------------------------------------------------------------
# include <bits/stdc++.h>
using namespace std;

class Scooty{ // parent Class
public:
    int topSpeed;
    float mileage;

private:
    int bootSpace;

public:
    void setBootSpace(int x) { // Setter 
        bootSpace = x;
    }

    int getBootSpace() { // getter
        return bootSpace;
    }
};

// Child Class or Derived Class of Scooty Class -> It Inherits all the public properties of the Scooty class. 
class motorBike : public Scooty{
public:
    int gears;
};

    
int main(){
    
    motorBike b1;
    b1.topSpeed = 200;
    b1.mileage = 55.5;
    b1.gears = 4;
    
    // b1.bootSpace = 12;  // This is Invalid Way of Accessing the bootSpace
    b1.setBootSpace(12);   // We will use setter for seting the value
    cout << b1.getBootSpace();  // We will use getter for accessing the value
    
}

// ----------------------------------------------------------- MultiLevel  Inheritence --------------------------------------------------------------------
# include <bits/stdc++.h>
using namespace std;

class Vehicle{ // parent Class
public:
    int topSpeed;
    float mileage;
    string fuelType;
};

class TwoWheeler : public Vehicle{ // Sub- Parent Class
public:
    int gears;
};

class Bike : public TwoWheeler{ // 1st Child Class or Derived Class of Sub Parent Clas
public:
    string type;
};

class Cycle : public TwoWheeler{ // 2nd Child Class or Derived Class of Sub Parent Clas
public:
    string type;
};

    
int main(){
    Bike b1;
    b1.topSpeed = 200;       // From Vehicle
    b1.mileage = 55.5;       // From Vehicle
    b1.fuelType = "Petrol";  // From Vehicle

    b1.gears = 4;            // From TwoWheeler

    b1.type = "Sports Bike"; // From Bike

}

// ----------------------------------------------------------- Multiple Inheritence --------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Cricketer { // Parent Class
public:
    int runs;
    int wickets;
    float avg;
};

class Engineer { // Parent Class
public:
    int experience;
    string domain;
};

class Person : public Cricketer, public Engineer {
public:
    string name;
    int age;
};

int main() {

    Person p1;

    p1.runs = 100;             // From Cricketer
    p1.wickets = 5;            // From Cricketer
    p1.avg = 50.5;             // From Cricketer

    p1.experience = 3;         // From Engineer
    p1.domain = "Software";    // From Engineer

    p1.name = "Devashish";     // Person's own
    p1.age = 21;               // Person's own

    return 0;
}

/*
===============================================================================
                    ACCESS MODIFIERS - FLOW / TABLE
===============================================================================

                         WHERE CAN IT BE ACCESSED?
              ------------------------------------------------
              | Outside Class | Derived Class | Within Class |
--------------|---------------|---------------|---------------|
 public       |      YES      |      YES      |      YES      |
 protected    |      NO       |      YES      |      YES      |
 private      |      NO       |      NO       |      YES      |
--------------|---------------|---------------|---------------|

===============================================================================
                              EASY FLOW CHART
===============================================================================

                           ACCESS MODIFIER
                                  |
                 +----------------+----------------+
                 |                |                |
               PUBLIC         PROTECTED         PRIVATE
                 |                |                |
          +------+-----+     +----+----+       +---+---+
          |            |     |         |       |       |
       Outside      Inside  Inside   Derived  Inside  Derived/
       Class        Class   Class     Class   Class   Outside
          |            |     |         |       |       |
         YES          YES   YES       YES      YES      NO


===============================================================================
                              KEY POINTS
===============================================================================

1. PUBLIC
   -> Can be accessed everywhere.

2. PROTECTED
   -> Can be accessed inside the class.
   -> Can be accessed inside the derived/child class.
   -> Cannot be accessed directly from outside.

3. PRIVATE
   -> Can be accessed only inside the same class.
   -> Cannot be accessed directly from derived class.
   -> Cannot be accessed directly from outside.

===============================================================================
                              QUICK MEMORY TRICK
===============================================================================

        PUBLIC       →  Everyone
        PROTECTED    →  Class + Children
        PRIVATE      →  Only Class

===============================================================================
*/