// "Patterns"

# include <iostream>
using namespace std;

int main(){

// pattern 1
    int n;
    cout<<"Take the value of n"<<endl;
    cin>>n;

    int i = 1;

  //   while(i<=n){

  //       int j = 1;

  //       while(j<=n){
  //       cout <<"*"<<" ";
  //       j = j+1;
  //    }
  //    cout<<endl;
  //   i = i+1;
        
  // }

// patern 2

  /*while (i<=n){

    int j = 1;
    while (j<=n){

    cout <<i<<" ";
    j = j+1;
    }
    cout<<endl;
    i = i+1;
  }*/

// pattern 3

  /* while(i<=n){
    
    int j=1;
    while (j<=n){
    cout<<j<<" ";
    j = j+1;
   }
    cout<<endl;
    i = i+1;
 }*/

//pattern 4

 /* while(i<=n){
    int j =1;
    while(j<=i){
      cout<<j<<" ";
      j = j+1;

    }
    cout<<endl;
    i = i+1;
  }*/

  // pattern 5

 /*while(i<=n){
    int j =1;
    while(j<=i){
      cout<<i<<" ";
      j = j+1;

    }
    cout<<endl;
    i = i+1;
  }*/

  // pattern 6

    int count=1;
    while(i<=n){
    int j =1;
    while(j<=i){
      cout<<count<<" ";
      count = count+1;
      j = j+1;

    }
    cout<<endl;
    i = i+1;
    
  }

    return 0;
    
        
}


