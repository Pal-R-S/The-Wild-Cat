#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
using namespace std;

vector<vector<char>> create_chess_board(unsigned int n);

void solve_nQueens(
    const vector<vector<char>>& board, 
    unsigned int row, 
    unsigned int n, 
    vector<bool>& cols, 
    vector<bool>& diag1, 
    vector<bool>& diag2, 
    vector<vector<vector<char>>>& solutions);

void display_board(const vector<vector<char>>& board);

#endif
