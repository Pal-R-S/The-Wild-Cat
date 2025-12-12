#include "sudokuboard.h"
#include <iostream>
using namespace std;

vector<vector<int>> create_sudoku_board(unsigned int n){
    vector<vector<int>> board(n, vector<int>(n, 0)); // Create a 9 x 9 Sudoku board initialized with 0
    return board;
}
void read_sudoku_board_from_file(
    const string& filename,
    vector<vector<int>>& board,
    unsigned int n,
    vector<vector<bool>>& rows,
    vector<vector<bool>>& cols,
    vector<vector<bool>>& boxes
){  //if the number of entries in the sudoku file is not n**2 or they include invalid numbers, the function will misbehave thus end gracefully
    freopen(filename.c_str(), "r", stdin);
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            if (num < 0 || num > static_cast<int>(n)) {
                cout << "Error: Invalid number in Sudoku file." << endl;
                exit(1);
            }
            board[i][j] = num;
            if (num != 0) {
                rows[i][num - 1] = true;
                cols[j][num - 1] = true;
                unsigned int box_index = (i / static_cast<unsigned int>(sqrt(n))) * static_cast<unsigned int>(sqrt(n)) + (j / static_cast<unsigned int>(sqrt(n)));
                boxes[box_index][num - 1] = true;
            }
        }
    }
    freopen("/dev/tty", "r", stdin); // Restore standard input
}

void write_sudoku_board_to_file(
    const string& filename,
    unsigned int n,
    const vector<vector<int>>& board
){//initialize board to zero
    freopen(filename.c_str(), "w", stdout);
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    freopen("/dev/tty", "w", stdout); // Restore standard output
}
void solve_sudoku(
    const vector<vector<int>>& board, 
    unsigned int row_on, 
    unsigned int int_on,
    unsigned int n, 
    vector<vector<bool>>& cols, 
    vector<vector<bool>>& rows, 
    vector<vector<bool>>& squares, 
    vector<vector<vector<int>>>& solutions){
    if (row_on == n ) {
        solutions.push_back(board);
        return;
    }
    else {
        unsigned int next_row = (int_on + 1 == n) ? row_on + 1 : row_on;
        unsigned int next_int = (int_on + 1) % n;
        if (board[row_on][int_on] != 0) {
            solve_sudoku(board, next_row, next_int, n, cols, rows, squares, solutions);
        } else {
            for (unsigned int num = 1; num <= n; ++num) {
                unsigned int square_index = (row_on / static_cast<unsigned int>(sqrt(n))) * static_cast<unsigned int>(sqrt(n)) + (int_on / static_cast<unsigned int>(sqrt(n)));
                if (!rows[row_on][num - 1] && !cols[int_on][num - 1] && !squares[square_index][num - 1]) {
                    vector<vector<int>> new_board = board;
                    new_board[row_on][int_on] = num;
                    rows[row_on][num - 1] = cols[int_on][num - 1] = squares[square_index][num - 1] = true;
                    solve_sudoku(new_board, next_row, next_int, n, cols, rows, squares, solutions);
                    rows[row_on][num - 1] = cols[int_on][num - 1] = squares[square_index][num - 1] = false;
                }
            }
        }
    }
    
}
