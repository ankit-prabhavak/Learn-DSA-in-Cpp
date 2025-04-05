#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> vec(3, vector<int>(3, 0)); // 3x3 matrix initialized to 0

    // rows = vec.size()
    // cols = vec[i].size()


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vec[i][j] = i * 3 + j + 1; // Fill the matrix with values from 1 to 9
        }
    }
    cout << "Matrix elements:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> vec1 = {{1, 2, 3}, {4, 5, 6, 0, 0}, {7, 8, 9}}; 
    cout << "Matrix elements:" << endl;
    for (int i = 0; i < vec1.size(); i++) {
        for (int j = 0; j < vec1[i].size(); j++) {
            cout << vec1[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
    
}