//                                              2-D ARRAY
# include <bits/stdc++.h>
using namespace std;

void printarray(int arr[][4] , int row , int col){
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
}

void colwiseprint(int arr[][4] , int row , int col){
        for(int i=0; i<col; i++){
            for(int j=0; j<row; j++){
                cout<<arr[j][i]<<" ";
            }
            cout<<endl;
        }
}

int main(){
    
    // initializing the 2-D array
    // int arr[row][col];
    //while initializing the 2-D array we have to atleast provide the columns.
    int row =3;
    int col =4;
    int arr[][4]={ {1,2,3,4} ,
                   {5,6,7,8} ,
                   {9,10,11,12}
                    };

    // printing the array 
    printarray(arr , row , col);
    colwiseprint(arr , row ,col);
    return 0;
}


// program on taking input in an array from usr in row-wise and col-wise  =>
# include <iostream>
using namespace std;

// void RowWiseInput(int arr[][3], int row , int col){
//     for (int i=0; i<row; i++ ){
//         for(int j=0; j<col ; j++){
//             cin>>arr[i][j];
//         }
//     }
// }

 void ColumnWiseInput(int arr[][3], int row , int col){
    for (int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            cin>>arr[j][i];
        }    
    }
 }
void printarray(int arr[][3] ,int row ,int col){
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
}

int main(){
    int row=3; 
    int col=3; 
    int arr[3][3];
    // RowWiseInput(arr , row ,col);
    ColumnWiseInput(arr , row ,col);
    cout<<"our array is :"<<endl;
    printarray(arr , row , col);
    return 0;
}

// program on linear search in 2D array => 
# include <iostream>
using namespace std;

void RowWiseInput(int arr[][3], int row , int col){
    for (int i=0; i<row; i++ ){
        for(int j=0; j<col ; j++){
            cin>>arr[i][j];
        }
    }
}

void printarray(int arr[][3] ,int row ,int col){
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
}

bool search(int arr[][3], int row , int col , int key ){
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
               if(arr[i][j]==70){
                return 1;
               }
            }
        }
               return 0;
}
int main(){
    int row=3; 
    int col=3; 
    int key=70;
    int arr[3][3];
    RowWiseInput(arr , row ,col);
    cout<<"our array is :"<<endl;
    printarray(arr , row , col);
    bool ans=search(arr , row , col ,key);
    if(ans==1){
        cout<<"key is found";
    }
    else
        cout<<"key is not found";
    return 0;
}


// program on finding maximum & minimum element in 2D array => 
# include <iostream>
# include <limits.h>
using namespace std;

void RowWiseInput(int arr[][3], int row , int col){
    for (int i=0; i<row; i++ ){
        for(int j=0; j<col ; j++){
            cin>>arr[i][j];
        }
    }
}

void printarray(int arr[][3] ,int row ,int col){
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
}

int maxelement(int arr[][3], int row , int col ){
    int max = INT_MIN;
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
               if(max<arr[i][j]){
                  max=arr[i][j];
               }
            }
        }
               return max;
}

int MinElement(int arr[][3], int row ,  int col){
    int min = INT_MAX;
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
               if(min>arr[i][j]){
                  min=arr[i][j];
               }
            }
        }
               return min;
}
int main(){
    int row=3; 
    int col=3; 
    int key=70;
    int arr[3][3];
    RowWiseInput(arr , row ,col);
    cout<<"our array is :"<<endl;
    printarray(arr , row , col);
    int ans1=maxelement(arr , row , col );
    cout<<"max element of an array is :"<<ans1 <<endl;
    int ans2=MinElement(arr , row , col);
    cout<<"min element of an array is :"<<ans2 <<endl;
    return 0;
}


// program on finding the row-wise and col-wise sum of element in 2D array => 
# include <iostream>
# include <limits.h>
using namespace std;

void RowWiseInput(int arr[][3], int row , int col){
    for (int i=0; i<row; i++ ){
        for(int j=0; j<col ; j++){
            cin>>arr[i][j];
        }
    }
}

void printarray(int arr[][3] ,int row ,int col){
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
}

void Rowsum(int arr[][3], int row , int col){
     cout<<"Rowise sum of matrix/2D array is :";
        for (int i=0; i<row; i++){
                int sum=0;  
                for(int j=0; j<col; j++){
                sum +=arr[i][j];
        }
                 cout<<sum<<" ";
    }
                cout<<endl;
}

void Colsum(int arr[][3], int row , int col){
    cout<<"Colwise sum of matrix/2D array is :";
        for (int i=0; i<col; i++){
                int sum=0;  
                for(int j=0; j<row; j++){
                sum +=arr[j][i];
        }
                 cout<<sum<<" ";
    }
} 

int main(){ 
    int row=3; 
    int col=3; 
    int key=70;
    int arr[3][3];
    RowWiseInput(arr , row ,col);
    cout<<"our array is :"<<endl;
    printarray(arr , row , col);
    Rowsum(arr , row , col);
    Colsum(arr , row , col);
    return 0;
}


