//Create a Chess board class that maintains the Size and the positions of the n queens in an array
#include <iostream>
#include <vector>
#include <string>
#include "sudokuboard.h"
using namespace std;
int main(){
    cout<<"enter size of Sudoku board (It must be a perfect square): ";
    unsigned int n;
    cin>>n;
    //check if n is a perfect square
    unsigned int root = static_cast<unsigned int>(sqrt(n));
    if (root * root != n) {
        cout << "Error: Size must be a perfect square." << endl;
        return 0;
    }
    vector<vector<vector<int>>>solutions;
    vector<vector<int>>board=create_sudoku_board(n);
    
    vector<vector<bool>> cols(n, vector<bool>(n, false));
    vector<vector<bool>> rows(n, vector<bool>(n, false));
    vector<vector<bool>> boxes(n, vector<bool>(n, false));
    write_sudoku_board_to_file("sudoku_input.txt", n, board);
    cout<<"The Sudoku_input.txt file contains a default Sudoku puzzle. Please change that and enter 1 "<<endl;
    unsigned int prefill;
    cin>>prefill;
    read_sudoku_board_from_file("sudoku_input.txt", board, n, rows, cols, boxes);
    solve_sudoku(board, 0, 0, n, cols, rows, boxes, solutions);
    cout<<"Total solutions: "<<solutions.size()<<endl;
    for (auto& k : solutions){
        //create an outfile for each solution
        write_sudoku_board_to_file("sudoku_output.txt", n, k);
        cout<<"Solution " << (&k - &solutions[0]) + 1 << " written to sudoku_output.txt. "<<"Please enter 0 to view the next solution."<<endl;
        int wait;
        cin>>wait;
    }
    cout<<"All solutions have been viewed."<<endl;


    return 0;

}