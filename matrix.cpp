#include <iostream>
using namespace std;
int main(){
    int row1,row2,col1,col2;
    int **matrix1 = new int *[row1];
    int **matrix2 = new int *[row2];
    int **result = new int *[row1];
    for (int i = 0;i<row1;i++){
        matrix1[i]=new int [col1];
        result[i]=new int [col2];
    }
    for(int i = 0 ;i< row2;i++){
        matrix2[i]= new int[col2];
    }
}