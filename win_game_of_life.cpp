#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int getTerminalWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getTerminalHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void resetCursor() {
    for(int i = 0; i < getTerminalHeight()-1; i++) {
        cout << "\x1b[A";
    }
}

void printBoard(vector<vector<bool>> board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            // Sleep(1);
            if(board[i][j]) {
                cout << " * ";
            } else {
                cout << "   ";
            }
        }
        if(i < board.size()-1) cout << endl;
    }

}

vector<vector<bool>> randomBoard() {
    vector<vector<bool>> board(getTerminalHeight()-1, vector<bool>(getTerminalWidth()/3, false));
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

vector<vector<bool>> updateBoard(vector<vector<bool>> board) {
    vector<vector<bool>> newBoard(board.size(), vector<bool>(board[0].size()));
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            newBoard[i][j] = updateCell(board, i, j);
        }
    }
    return newBoard;
}

void runGame(vector<vector<bool>> board, int runtime) {
    system("CLS");
    printBoard(board);
    for(int i = 0; i < runtime; i++) {
        Sleep(50);
        cout << endl;
        resetCursor();
        board = updateBoard(board);
        printBoard(board);
    }
}

int main() {
    runGame(randomBoard(), 500);
    return 0;
}