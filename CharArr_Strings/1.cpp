//                                  Char-Array   &  string  level-1       
# include <iostream>
# include <string.h>

using namespace std;


int main(){
    // creation
    char mych[10];

    //input
    cout<<"enter input in mych"<<endl;
    // cin>>mych; // it will not consider the value  in array after "tab" or "space" .
    cin.getline(mych,100);//it's format is :-it stores values in mych and maximum values that  can be  stored is 100 .
    // use :- by using this we will make it consider the value even after hiiting the "tab" or "space".


    //print
    cout<<"printing the value of  mych :"<<mych<<'\n';

    //printing at particular index
    cout<<"value at index 2 is :"<<mych[2]<<endl;

    // printing the values using loop
    // for(int i=0; i<10; i++){
    //         cout<<"At index :"<< i <<" "<<mych[i]<<" "<<endl;
    // }

    char temp=mych[9]; // null char is present at 9th index
    int value=int(temp); // Ascii value of null is 0 in integer
    // cout<<"integer value of char "<<value;
     
    return 0;
}

// pogram to find the length of char-array
# include <iostream>
using namespace std;
int main(){
    char ch[100];
    cout<<"enter the input in char-array"<<endl;
    // cin>>ch;
    cin.getline(ch,100);
    int len=0;
    int i=0;
    // while (ch[len] !='\0'){
    //     len++;
    // }
    for(int i=0; i<100; i++){
        if(ch[i]=='\0'){
            break;
        }
        else{
            len++;
        }
    }
    cout<<"length of string is "<<len;
    cout<<"length of string is "<<strlen(ch);// pre defined function
    return 0;
}

// pogram to reverse the length of char-array
# include <iostream>
# include <string.h>
using namespace std;

void reverse(char ch[],int n){
    int i=0;
    int j=n-1;
    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
}

int main(){
    int n=100;
    char ch[n];
    cout<<"enter the input in char-array :-"<<endl;
    // cin>>ch;
    cin.getline(ch,100);
    cout<<"printing the ch-arr before reverse  :"<<ch<<endl;
    cout<<"length of string is :"<<strlen(ch)<<endl;
    int len=strlen(ch);
    reverse(ch,len);
    cout<<"printing the ch-arr after reverse  :"<<ch<<endl;
    return 0;
}

// pogram to convert lowercase char to uppercase char or from uppercase char to lowercase char in a char-array
# include <iostream>
# include <string.h>
using namespace std;

void converttouppercase(char ch[],int n){
    int index = 0;
    while(ch[index] != '\0'){   // till my char arr doesnot reaches to null value
        if (ch[index] >= 'a' && ch[index] <= 'z'){ //if it is a lowercase character then convert it into uppercase char.
            ch[index] = ch[index] - 'a' + 'A'; // formula of conversion from L.C char to U.C char
        }
        index++;
    }
}

void converttolowercase(char ch[], int n){
    int index = 0;
    while(ch[index] != '\0'){   // till my char arr doesnot reaches to null value
        if (ch[index] >= 'A' && ch[index] <= 'Z'){ //if it is a uppercase character then convert it into lowercase char.
            ch[index] = ch[index] - 'A' + 'a'; // formula of conversion from U.C char to L.C char
        }
        index++;
    }
}

int main(){
    int n=100;
    char ch[n];
    cout<<"enter the input in char-array :-"<<endl;
    // cin>>ch;
    cin.getline(ch,100);
    cout<<"printing the ch-arr before conversion :"<<ch<<endl;
    // converttouppercase(ch,n);
    converttolowercase(ch,n);
    cout<<"printing the ch-arr after conversion  :"<<ch<<endl;
    return 0;
}

// pogram to replce '@' with space in a char-array
# include <iostream>
# include <string.h>
using namespace std;

void replace(char ch[],int n){
    int index = 0;
    while(ch[index] != '\0'){   // till my char arr doesnot reaches to null value
        if (ch[index] == '@'){ //if ch[index] contains '@' then replace it with space.
            ch[index] = ' '; 
        }
        index++;
    }
}


int main(){
    int n=100;
    char ch[n];
    cout<<"enter the input in char-array :-"<<endl;
    // cin>>ch;
    cin.getline(ch,100);
    cout<<"printing the ch-arr before replacement of the @ with space :"<<ch<<endl;
    replace(ch,n);
    cout<<"printing the ch-arr after replacement of the @  with space:"<<ch<<endl;
    return 0;
}

// pogram to check weather given string is pallindrome or not (eg- noon,racecar,etc).
#include <iostream>
#include <string.h>
using namespace std;

bool checkpallindrome(char ch[], int len){
    int i = 0;
    int j = len - 1;
    while(i <= j){
        if(ch[i] != ch[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    char ch[100];
    cout << "Enter the input in char-array: " << endl;
    cin.getline(ch, 100);  // Read the full line
    int len = strlen(ch);
    bool ans = checkpallindrome(ch, len);
    if(ans){
        cout << "Given string is a palindrome" << endl;
    }
    else{
        cout << "Given string is not a palindrome" << endl;
    }
    return 0;
}

// **************************************Some Pre-defined Functions of the String*********************************************
# include <iostream>
# include <string.h>

using namespace std;
int main(){
    char str1[100];
    char str2[100];

    strcpy(str1,"Apna college");
    strcpy(str2,"Learning DSA");

    // cout<<"Before Updation str1 and str2 are :-"<<"\n";
    // cout<<str1<<"\n"; 
    // cout<<str2<<"\n";

    strcat(str1,str2);
    // cout<<"After Updation str1 and str2 are :-"<<"\n";

    // cout<<str1<<"\n";
    // cout<<str2<<"\n";

    // cout<<strcmp(str1,str2); // A < L => -ve value

    return 0;
}