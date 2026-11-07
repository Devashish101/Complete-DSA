//                                  Dynamic_Memory_Allocation (Day-15)
# include <iostream>
using namespace std;

void funcint (){
    int *ptr = new int;
    *ptr = 5;
    
    cout<<ptr;
    delete ptr; // if we create a dynamic Memory outside the main fun then we have to use the "delete" keyword...
                //...before returning from the func to free the space occupied in D_M_A.
}

void funcArr(){
    int size;
    cin>>size;
    int *ptr = new int[size]; // Dynamic Array 

    int x=1;
    for(int i=0; i<size; i++){
        ptr[i] = x;
        cout<<ptr[i]<<" ";
        x++;
    }
    delete [] ptr; // Deleting the Memory of an Array
}
int main(){
    
    // int arr[5] = {1,2,3,4,5}; // Static Memory Allocation => Stack based

    int size;
    cin>>size;

    int *ptr = new int[size]; //Dynamic Memory allocation using "new" keyword => Heap based

    funcint();
    funcArr();
    return 0;
}


//                                       Creating a 2-D Dynamic Array
# include <iostream>
using namespace std;

int main(){
    int rows,cols;
    cout<<"Enter rows";
    cin>>rows;
    cout<<"Enter cols";
    cin>>cols;

    int * *matrix = new int *[rows]; // arrary(Matrix) pointing to an integer pointer array

    for(int i=0; i<cols; i++){
        matrix[i] = new int [cols];
    }
    
    int x=1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix[i][j] = x++;
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<matrix[2][2]<<"\n";
    cout<<*(*(matrix+2)+2)<<"\n";

    return 0;
}