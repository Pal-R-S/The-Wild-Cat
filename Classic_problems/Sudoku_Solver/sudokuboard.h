#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <vector>
using namespace std;

vector<vector<int>> create_sudoku_board(unsigned int n);

void solve_sudoku(
    const vector<vector<int>>& board, 
    unsigned int row_on, 
    unsigned int int_on,
    unsigned int n, 
    vector<vector<bool>>& cols, 
    vector<vector<bool>>& rows, 
    vector<vector<bool>>& squares, 
    vector<vector<vector<int>>>& solutions);

void read_sudoku_board_from_file(
    const string& filename,
    vector<vector<int>>& board,
    unsigned int n,
    vector<vector<bool>>& rows,
    vector<vector<bool>>& cols,
    vector<vector<bool>>& boxes
);
void write_sudoku_board_to_file(
    const string& filename,
    unsigned int n,
    const vector<vector<int>>& board

);

#endif
