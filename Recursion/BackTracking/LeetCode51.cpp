#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
    public:
        bool isSafe(vector<string> &board, int row, int col, int n) {  // O(n)
            
            // Horizontal 
            for(int i=0; i < n; i++){
                if(board[row][i] == 'Q') return false;
            }
            // Verticle 
            for(int i=0; i < n; i++){
                if(board[i][col] == 'Q') return false;
            }
            // Left Diagonal
            for(int i = row, j = col; i >= 0 && j >= 0; j--, i--){
                if(board[i][j] == 'Q') return false;
            }
            // Right Diagonal
            for(int i = row, j = col; i >= 0 && j >= 0; j++, i--){
                if(board[i][j] == 'Q') return false;
            }
            return true;
        }

        void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
            if(row == n){
                ans.push_back({board});
                return;
            }

            for(int j=0; j<n; j++){
                if(isSafe(board, row, j, n)){
                    board[row][j] = 'Q';
                    nQueens(board, row+1, n, ans);
                    board[row][j] = '.';

                }
            }

        }
        vector<vector<string>> solveNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            vector<vector<string>> ans;

            nQueens(board, 0, n, ans);
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