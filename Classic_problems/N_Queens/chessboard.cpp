#include "chessboard.h"
#include <iostream>
using namespace std;


vector<vector<char>> create_chess_board(unsigned int n){
    vector<vector<char>> board; // Create an n x n chess board initialized with '.'
    for (unsigned int i = 0; i < n; ++i) {
        vector<char> row(n, '.');
        board.push_back(row);
    }
    return board;
}
void solve_nQueens(
    const vector<vector<char>>& board, 
    unsigned int row, 
    unsigned int n, 
    vector<bool>& cols, 
    vector<bool>& diag1, 
    vector<bool>& diag2, 
    vector<vector<vector<char>>>& solutions){
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    else {
        for (unsigned int col = 0; col < n; ++col) {
            if (!cols[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
                vector<vector<char>> new_board = board;
                new_board[row][col] = 'Q';
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
                solve_nQueens(new_board, row + 1, n, cols, diag1, diag2, solutions);
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
            }
        }
    }
    

}
void display_board(const vector<vector<char>>& board){
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}