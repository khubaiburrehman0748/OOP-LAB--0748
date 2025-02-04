#include <iostream>
using namespace std;

int main() {
    int rows;
    
    cout<<"enter the rows =";
    cin>>rows;
    
    int **matrix_1 =  new int*[rows];
    int **matrix_2 = new int*[rows];
    int **result = new int*[rows];
    
    for(int i=0;i<rows;i++){
        matrix_1[i] = new int [rows];
        matrix_2[i] = new int [rows];
        result[i] = new int [rows];
    }
    
    cout<<"Enter the elements of Matrix 1 "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            cout<<"row "<<i+1<<" column "<<j+1<<" = ";
            cin>>matrix_1[i][j];
        }
    }
    
    
    cout<<"\n\nEnter the elements of Matrix 2 "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            cout<<"row "<<i+1<<" column "<<j+1<<" = ";
            cin>>matrix_2[i][j];
        }
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            result[i][j]=matrix_1[i][j]+matrix_2[i][j];
        }
    }
    
    cout<<"\nResultant matrix in Addition of matrix 1 and 2 ="<<endl;
    for(int i=0;i<rows;i++){
        cout<<"|  ";
        for(int j=0;j<rows;j++){
            cout<<result[i][j]<<"  ";
        }
        cout<<"|\n";
    }
    
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            result[i][j]=matrix_1[i][j]-matrix_2[i][j];
        }
    }
    
    cout<<"\nResultant matrix in Subtraction of matrix 1 and 2 ="<<endl;
    for(int i=0;i<rows;i++){
        cout<<"|  ";
        for(int j=0;j<rows;j++){
            cout<<result[i][j]<<"  ";
        }
        cout<<"|\n";
    }
    
    
    for(int i = 0; i < rows; i++) {
        delete[] matrix_1[i];
        delete[] matrix_2[i];
        delete[] result[i];
    }
    delete[] matrix_1;
    delete[] matrix_2;
    delete[] result;
    return 0;
}
