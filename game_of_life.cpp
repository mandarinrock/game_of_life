#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

/**
 * @brief 
 * 
 * @param board 
 */
void printBoard(vector<vector<bool>> board) {

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j]) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

}

vector<vector<bool>> randomBoard(vector<vector<bool>> board) {
    srand(time(NULL));
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            board[i][j] = rand() % 2;
        }
    }
    return board;
}


int main() {

    vector<vector<bool>> board(5, vector<bool>(5, false));
    printBoard(board);
    board = randomBoard(board);
    printBoard(board);

    cout << "Successful run, terminating" << endl;
    return 0;
}