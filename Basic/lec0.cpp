#include <iostream>
#include <iostream>
using namespace std;

int main(){

    cout<<"namaste world \n";

    int x,y,z;
    x=4,y=6,z=0;
    cout << x+y+z <<"\n"; //while using \n for new line dont forget to put it in double inverted commas//

    double pi=3.14;
    cout <<pi <<endl;

    char mynamestartswith='D'; //value of string should be in single inverted commas//  
    cout <<mynamestartswith <<endl; //while using endl for new line dont forget to put it in insertion operator//

    string myname="Devashish"; //value of string should be in double inverted commas//
    cout <<myname <<endl;

    bool p=3.14;
    cout <<p;
    
    return 0;
}


#include <iostream>
using namespace std;
int main(){
      double x,y;
    cout<< "the value of x\n";
    cin>> x;
    cout<< "the  value of y\n";
    cin>> y;
    cout <<x/y;
    return 0;
}