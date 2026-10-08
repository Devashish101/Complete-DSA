

// program on finding the  sum of diagonal element and transpose of a 2D array => 
# include <bits/stdc++.h>
using namespace std;

void printarray(int arr[][4] ,int row ,int col){
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
}

void transpose( int arr[][4] ,int row ,int col){ // It is only Valid for square Matrix
        for (int i=0; i<row; i++){
            for(int j=i; j<col; j++){ // j=i
                swap(arr[i][j],arr[j][i]);          
            }
            cout<<endl;
        }
}

vector<vector<int>> transpose(vector<vector<int>>& matrix) { // leetcode 867. for M*N Matrix
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> resmatrix(m, vector<int>(n));
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                resmatrix[j][i] = matrix[i][j];
            }
            cout<<"\n";
        }
        return resmatrix;
    }

int diagonalsum(int arr[][4], int row , int col){
        int sum =0;
        for (int i=0; i<row; i++){
            sum+=arr[i][i];
        }
        return sum;
    }


int main(){ 
    int row=4; 
    int col=4; 
    int arr[][4]={ {1,2,3,4} ,
                   {5,6,7,8} ,
                   {9,10,11,12},
                   {13,14,15,16}
                    };
    cout<<"our array is :"<<endl;
    printarray(arr , row , col);
    int ans = diagonalsum(arr, row , col);
    cout<<"sum of diagonal elements of an array is :"<<ans<<endl;
    cout<<"Transpose of a matrix is:";
    transpose(arr , row , col);
    printarray(arr , row , col);
    return 0;
}

// 											Leetcode-48.Rotate Image
# include <bits/stdc++.h>
using namespace std;

int main(){
	int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	cout<<"Matrix Before Rotation :"<<"\n";
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	//step1. Transpose of the matrix
	for(int i=0; i<3; i++){
		for(int j=i; j<3; j++){
			swap(matrix[i][j],matrix[j][i]);
		}
		cout<<endl;
	}
	//step2. Doing the reverse of Each row
	for(int k=0; k<3; k++){
		for(int i=0,j=2; i<=j; i++,j--){
			swap(matrix[k][i],matrix[k][j]);
		}
		cout<<endl;
	}
	cout<<"Matrix After rotating 90deg"<<"\n";
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

// 												         Matrix Multiplication						
# include <bits/stdc++.h>
using namespace std;

int main(){
	int a[2][3] = {{1,2,3},{4,5,6}};
	int b[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int res[2][4];

	for(int i=0; i<2; i++){
		for(int j=0; j<4; j++){
			res[i][j] = 0;
			for(int k=0; k<3; k++){
				res[i][j] += a[i][k]*b[k][j];
			}
		}
		cout<<endl;
	}

	for(int i=0; i<2; i++){
		for(int j=0; j<4; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

	
}

// 										Matrix in Wave Form							
# include <bits/stdc++.h>
using namespace std;

int main(){
	int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	cout<<"Matrix printing in Wave format :"<<"\n";
	for(int i=0; i<3; i++){
		if(i%2==0){
			for(int j=0; j<3; j++){
				cout<<matrix[i][j]<<" ";
			}
		}
		else{ //1,3,5
			for(int j=2; j>=0; j--){
				cout<<matrix[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	
}

// TODO:***************** Spiral of a MATRIX *********************
# include <iostream>
using namespace std;

void spiralMatrix(int mat[][4], int n, int m){
    int strow = 0, stcol = 0;
    int endrow = n-1, endcol = m-1;

    while(strow<=endrow && stcol<=endcol){

        // Top
        for(int j=stcol; j<=endcol; j++){
            cout<<mat[strow][j]<<" ";
        }

        // Right
        for(int i=strow+1; i<=endrow; i++){
            cout<<mat[i][endcol]<<" ";
        }

        // Bottom
        for(int j=endcol-1; j>=stcol; j--){
            if(strow == endrow){ //Corner Case => middle row Incase of odd Matrix
                break; // so if we are at middle then simply get out since it has already been printed by our top
            }
            cout<<mat[endrow][j]<<" ";
        }

        // Left
        for(int i=endrow-1; i>=strow+1; i--){
            if(stcol == endcol){ //Corner Case => middle col Incase of odd Matrix
                break; // so if we are at middle col then simply get out since it has already been printed by our right
            }
            cout<<mat[i][stcol]<<" ";
        }

        strow++;stcol++;
        endrow--;endcol--;
    }
}


int main(){
    int matrix[4][4] = {{1,2,3,4},
                     {5,6,7,8},
                     {9,10,11,12},
                     {13,14,15,16}};
    spiralMatrix(matrix,4,4);

    return 0;
}

// ************************************** Search in a Sorted Matrix******************************************
# include <iostream>
using namespace std;

bool sortedMatrix(int mat[][4], int n, int m , int key){
        int i=0, j=m-1;
        while(i<n && j>=0){
            if(mat[i][j] == key){
                cout<<"("<<i<<","<<j<<")";
                return true;
            }
            else if(mat[i][j] > key){ // move Downwards
                j--;
            }
            else{ //(mat[i][j] < key) => move Left
                i++;
            }
        }
        cout<<"key not found";
        return false;
}


int main(){
    int matrix[4][4] = {{10,20,30,40},
                        {15,25,35,45},
                        {27,29,37,48},
                        {32,33,39,50}};
    int key = 33;
    sortedMatrix(matrix , 4 , 4 , key);
    
    return 0;
}