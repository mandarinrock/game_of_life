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

bool updateCell(vector<vector<bool>> board, int x, int y) {
    int neighbors = 0;

    // Top
    if(x > 0) {
        // Top left
        if(y > 0) {
            if(board[x - 1][y - 1]) {
                neighbors++;
            }
        } else {
            if(board[x - 1][board[0].size() - 1]) {
                neighbors++;
            }
        }
        // Top center
        if(board[x - 1][y]) {
            neighbors++;
        }
        // Top right
        if(y < board[0].size() - 1) {
            if(board[x - 1][y + 1]) {
                neighbors++;
            }
        } else {
            if(board[x - 1][0]) {
                neighbors++;
            }
        }
    } else {
        // Top left
        if(y > 0) {
            if(board[board.size() - 1][y - 1]) {
                neighbors++;
            }
        } else {
            if(board[board.size() - 1][board[0].size() - 1]) {
                neighbors++;
            }
        }
        // Top center
        if(board[board.size() - 1][y]) {
            neighbors++;
        }
        // Top right
        if(y < board[0].size() - 1) {
            if(board[board.size() - 1][y + 1]) {
                neighbors++;
            }
        } else {
            if(board[board.size() - 1][0]) {
                neighbors++;
            }
        }
    }

    // Middle
    // Middle left
    if(y > 0) {
        if(board[x][y - 1]) {
            neighbors++;
        }
    } else {
        if(board[x][board[0].size() - 1]) {
            neighbors++;
        }
    }
    // Middle right
    if(y < board[0].size() - 1) {
        if(board[x][y + 1]) {
            neighbors++;
        }
    } else {
        if(board[x][0]) {
            neighbors++;
        }
    }

    // Bottom
    if(x < board.size() - 1) {
        // Bottom left
        if(y > 0) {
            if(board[x + 1][y - 1]) {
                neighbors++;
            }
        } else {
            if(board[x + 1][board[0].size() - 1]) {
                neighbors++;
            }
        }
        // Bottom center
        if(board[x + 1][y]) {
            neighbors++;
        }
        // Bottom right
        if(y < board[0].size() - 1) {
            if(board[x + 1][y + 1]) {
                neighbors++;
            }
        } else {
            if(board[x + 1][0]) {
                neighbors++;
            }
        }
    } else {
        // Bottom left
        if(y > 0) {
            if(board[0][y - 1]) {
                neighbors++;
            }
        } else {
            if(board[0][board[0].size() - 1]) {
                neighbors++;
            }
        }
        // Bottom center
        if(board[0][y]) {
            neighbors++;
        }
        // Bottom right
        if(y < board[0].size() - 1) {
            if(board[0][y + 1]) {
                neighbors++;
            }
        } else {
            if(board[0][0]) {
                neighbors++;
            }
        }
    }

    if(board[x][y]) {
        if(neighbors < 2 || neighbors > 3) {
            return false;
        } else {
            return true;
        }
    } else {
        if(neighbors == 3) {
            return true;
        } else {
            return false;
        }
    }
}


int main() {
    vector<vector<bool>> board(5, vector<bool>(50, false));
    printBoard(board);
    board = randomBoard(board);
    printBoard(board);

    cout << "Successful run, terminating" << endl;
    return 0;
}