#include <iostream>
#include <vector>

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


int main() {

    vector<vector<bool>> board(5, vector<bool>(5, false));
    printBoard(board);

    cout << "Successful run, terminating" << endl;
    return 0;
}