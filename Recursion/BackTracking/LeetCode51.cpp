#include <iostream>
#include <vector>
#include <string>

using namespace std;


// class Solution {
//     public:
//         bool isSafe(vector<string> &board, int row, int col, int n) {  // O(n)
            
//             // Horizontal 
//             for(int i=0; i < n; i++){
//                 if(board[row][i] == 'Q') return false;
//             }
//             // Verticle 
//             for(int i=0; i < n; i++){
//                 if(board[i][col] == 'Q') return false;
//             }
//             // Left Diagonal
//             for(int i = row, j = col; i >= 0 && j >= 0; j--, i--){
//                 if(board[i][j] == 'Q') return false;
//             }
//             // Right Diagonal
//             for(int i = row, j = col; i >= 0 && j >= 0; j++, i--){
//                 if(board[i][j] == 'Q') return false;
//             }
//             return true;
//         }

//         void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
//             if(row == n){
//                 ans.push_back({board});
//                 return;
//             }

//             for(int j=0; j<n; j++){
//                 if(isSafe(board, row, j, n)){
//                     board[row][j] = 'Q';
//                     nQueens(board, row+1, n, ans);
//                     board[row][j] = '.';

//                 }
//             }

//         }
//         vector<vector<string>> solveNQueens(int n) {
//             vector<string> board(n, string(n, '.'));
//             vector<vector<string>> ans;

//             nQueens(board, 0, n, ans);
//             return ans;
//         }
//     };


// Optimized Approach
// class Solution {
// public:

//     bool isSafe(vector<string>& board, int row, int col, int n) {

//         // Left row
//         for (int j = col; j >= 0; j--) {
//             if (board[row][j] == 'Q')
//                 return false;
//         }

//         // Upper-left diagonal
//         for (int i = row, j = col;
//              i >= 0 && j >= 0;
//              i--, j--) {

//             if (board[i][j] == 'Q')
//                 return false;
//         }

//         // Lower-left diagonal
//         for (int i = row, j = col;
//              i < n && j >= 0;
//              i++, j--) {

//             if (board[i][j] == 'Q')
//                 return false;
//         }

//         return true;
//     }

//     void nQueens(vector<string>& board,
//                  int col,
//                  int n,
//                  vector<vector<string>>& ans) {

//         // All columns processed
//         if (col == n) {
//             ans.push_back(board);
//             return;
//         }
//         // Try every row in the current column
//         for (int row = 0; row < n; row++) {
//             if (isSafe(board, row, col, n)) {
//                 board[row][col] = 'Q';
//                 // Move to next column
//                 nQueens(board, col + 1, n, ans);
//                 // Backtrack
//                 board[row][col] = '.';
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {

//         vector<string> board(n, string(n, '.'));
//         vector<vector<string>> ans;

//         nQueens(board, 0, n, ans);
//         return ans;
//     }
// };

// Optimized Approach
class Solution {
public:

    void nQueens(vector<string>& board,
                 int col,
                 int n,
                 vector<vector<string>>& ans,
                 vector<int>& rowHash,
                 vector<int>& upperDiag,
                 vector<int>& lowerDiag) {

        // All columns processed
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {

            // row       -> row
            // row-col   -> upper diagonal
            // row+col   -> lower diagonal

            if (rowHash[row] ||
                upperDiag[row - col + n - 1] ||
                lowerDiag[row + col]) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';

            rowHash[row] = 1;
            upperDiag[row - col + n - 1] = 1;
            lowerDiag[row + col] = 1;

            // Move to next column
            nQueens(board, col + 1, n, ans,
                    rowHash, upperDiag, lowerDiag);

            // Backtrack
            board[row][col] = '.';

            rowHash[row] = 0;
            upperDiag[row - col + n - 1] = 0;
            lowerDiag[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        vector<int> rowHash(n, 0);

        // Maximum diagonal index = 2*n - 2
        // Therefore size = 2*n - 1
        vector<int> upperDiag(2 * n - 1, 0);
        vector<int> lowerDiag(2 * n - 1, 0);

        nQueens(board, 0, n, ans,
                rowHash, upperDiag, lowerDiag);

        return ans;
    }
};



int main(){
        Solution solution;
        int n = 4;
        vector<vector<string>> result = solution.solveNQueens(n);
        int count = 1;
        for(auto &board : result){
            cout << "Solution " << count++ << ":\n";
            for(const string &row : board){
                cout << row << endl;
            }
            cout << endl;
        }
       
        return 0;
    }