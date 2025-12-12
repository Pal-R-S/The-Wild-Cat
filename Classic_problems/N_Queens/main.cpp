//Create a Chess board class that maintains the Size and the positions of the n queens in an array
#include <iostream>
#include <vector>
#include <string>
#include "chessboard.h"
using namespace std;
int main(){
    cout<<"enter size of chess board: ";
    unsigned int n;
    cin>>n;
    vector<vector<vector<char>>>solutions;
    vector<vector<char>>board=create_chess_board(n);
    
    vector<bool> cols(n, false);
    vector<bool> diag1(2*n-1, false); // for \ diagonal
    vector<bool> diag2(2*n-1, false); // for / diagonal
    solve_nQueens(board, 0, n, cols, diag1, diag2, solutions);
    cout<<"Total solutions: "<<solutions.size()<<endl;
    for (auto& k : solutions){
        display_board(k);
        cout<<endl;
    }

    return 0;

}