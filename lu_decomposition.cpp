// lu_decomposition.cpp
// This program performs LU decomposition of a given matrix A
// It decomposes A into a lower triangular matrix L and an upper triangular matrix U
#include <iostream>
using namespace std;

int main(){
   int n = 3;
   float A[3][3] = {{2, -1, -2}, {-4, 6, 3}, {-4, -2, 8}};
   float L[3][3], U[3][3];
   int i, j, k;

   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         if(i > j){
            U[i][j] = 0;
            L[i][j] = A[i][j];
         }
         else if(i == j){
            L[i][j] = 1;
            U[i][j] = A[i][j];
         }
         else{
            L[i][j] = 0;
            U[i][j] = A[i][j];
         }
      }
   }
   for(k = 0; k < n; k++){
      for(i = k + 1; i < n; i++){
         L[i][k] = U[i][k] / U[k][k];
         for(j = k; j < n; j++){
            U[i][j] = U[i][j] - L[i][k] * U[k][j];
         }
      }
   }
   cout << "L Matrix" << endl;
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         cout << L[i][j] << " ";
      }
      cout << endl;
   }
   cout << "U Matrix" << endl;
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         cout << U[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}