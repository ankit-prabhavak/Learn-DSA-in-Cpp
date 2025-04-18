#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       bool isValid(vector<vector<char>> &board, int row, int col, char dig){
        // horizontal
        for(int i = 0; i < 9; i++){
            if(board[row][i] == dig){
                return false;
            }
        }

        // vertical
        for(int i = 0; i < 9; i++){
            if(board[i][col] == dig){
                return false;
                }
        }

        // box
        int sr = (row/3)*3;
        int sc = (col/3)*3;

        for(int i = sr; i <= sr+2; i++){
            for(int j = sc; j <= sc+2; j++){    
                if(board[i][j] == dig){
                    return false;
                    }
            }
        }
           
        return true;
       } 
        
       bool helper(vector<vector<char>> &board, int row, int col){
           if(row == 9){
            return true;
            }
           
           int nextRow = row, nextCol = col+1;
           if(nextCol == 9){
            nextRow = row+1;
            nextCol = 0;
           }

           if(board[row][col] != '.'){
              return helper(board, nextRow, nextCol); 
           }

           //place the digits
           for(char dig = '1'; dig <= '9'; dig++){
              if(isValid(board, row, col, dig)){
                board[row][col] = dig;
                if(helper(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col] = '.';
              }
           }
           return false;
       }
        
        
        void solveSudoku(vector<vector<char>>& board) {

            helper(board, 0, 0);

            
        }
    };


int main(){
    Solution solution;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };

    solution.solveSudoku(board);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}