// // mini calculator using swich case
// # include <iostream>
// using namespace std;
// int main (){
//     int a,b;
//     cout<<"enter a:"<<endl;
//     cin>> a;
//     cout<<"enter b:"<<endl;
//     cin>> b;
//     char opr;
//     cout<<"enter the operation which you want to apply:"<<endl;
//     cin>>opr;
//     switch (opr)
//     {
//     case '+': cout<<a+b;
//         break;
//     case '-': cout<<a-b;
//         break;
//     case '/': cout<<a/b;
//         break;
//     case '*': cout<<a*b;
//         break;
//     case '%': cout<<a%b;
//         break;
//     default:cout<<"enter a valid operation, Thankyou";
//         break;
//     }
// }


//calculating the total no. of 100 , 50, 20 and 1  rupee note used in given amount
# include <iostream>
# include <math.h>
using namespace std;

int main (){
   int n;
   cout<<"enter your amount n:";
   cin>>n;
   
   int note;
   cout<<" For total no.of Rs100, Rs50, Rs20 and Rs1 note used: please enter 1"<<endl;
   cin>>note;
   switch(note){   //1575
    case 1: cout << "100rupee note is:" <<n/100<<endl;//50
       
    case 2: cout << "50rupee note is:"<<(n%100)/50<<endl;//1
       
    case 3: cout<<"20rupee note is:"<<((n%100)%50)/20<<endl;//1
      
    case 4: cout<<"1rupee note is:" <<(((n%100)%50)%20)/1<<endl;//5

   }
}

