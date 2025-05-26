#include <bits/stdc++.h>
#include <vector>
#include <algorithm>


using namespace std;



int flippingMatrix(vector<vector<int>> matrix) {
   int n = matrix.size()/2;
   
   int maxi = 0;
   
   for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        int a = matrix[i][j];
        int b = matrix[i][2*n-1-j];
        int c = matrix[2*n-1-i][j];
        int d = matrix[2*n-1-i][2*n-1-j];
        
        
        maxi += max(max(a,b), max(c,d));
    }
   }
   
   return maxi;
    

}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(2 * n, vector<int>(2 * n));
    
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << flippingMatrix(matrix) << endl;
    
    return 0;
}