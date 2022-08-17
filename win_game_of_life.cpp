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
    // gotoxy(getTerminalHeight(), getTerminalWidth());

    // for(int i = 0; i < board[0].size()-10; i++) {
    //     cout << " - ";
    // }
    // cout << endl;
    // GoToXY(0,0);
    // system("CLS");

    for(int i = 0; i < board.size(); i++) {
        // cout << i << ") ";
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

// void printBoard(vector<vector<bool>> board, int height, int width) {

//     for(int i = 0; i < height; i++) {
//         for(int j = 0; j < width; j++) {
//             if(board[i][j]) {
//                 cout << " * ";
//             } else {
//                 cout << "   ";
//             }
//         }
//         cout << endl;
//     }

// }

vector<vector<bool>> randomBoard() {
    // int height = ;
    // int width = ;
    vector<vector<bool>> board(getTerminalHeight()-1, vector<bool>(getTerminalWidth()/3, false));
    srand(time(NULL));
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            board[i][j] = rand() % 2;
        }
    }
    return board;
}

// vector<vector<bool>> randomBoard(int height, int width) {
//     vector<vector<bool>> board(height, vector<bool>(width, false));
//     srand(time(NULL));
//     for(int i = 0; i < board.size(); i++) {
//         for(int j = 0; j < board[0].size(); j++) {
//             board[i][j] = rand() % 2;
//         }
//     }
//     return board;
// }

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

// void runGame(vector<vector<bool>> board) {
//     while(true) {
//         printBoard(board);
//         board = updateBoard(board);
//         sleep(1);
//         clearScreen();
//     }
// }




void runGame(vector<vector<bool>> board, int runtime) {
    system("CLS");
    printBoard(board);
    for(int i = 0; i < runtime; i++) {
        Sleep(35);
        cout << endl;
        resetCursor();
        // cout << "Frame #" << i;
        board = updateBoard(board);

        // cout << "Hello World" << endl;
        printBoard(board);
    }
}


int main() {

    // cout << "Width: " << getTerminalWidth() << endl;
    // int width = getTerminalWidth() - 5;
    // int height = getTerminalHeight() - 5;
    // // int width = windowWidth-5;
    // // int height = windowHeight-5;
    // cout << "Width: " << width << endl;
    // cout << "Height: " << height << endl;
    // int runtime = 10;
    // cout << "Height: " << getTerminalHeight() << endl;
    // return 0;

    // vector<vector<bool>> board(getTerminalHeight()-5, vector<bool>(getTerminalWidth()-5, false));
    // vector<vector<bool>> board = randomBoard(height, width);
    // cout << "Width: " << board[0].size() << endl;
    // cout << "Height: " << board.size() << endl;

    // runGame(board, runtime);
    // runGame(randomBoard(height,width), runtime);
    // for(int i = 0; i < runtime; i++) {
    //     cout << "Frame #" << i << endl;
    //     board = updateBoard(board);
    //     printBoard(board);
    // }
    // cout << "Width: " << board[0].size() << endl;
    // cout << "Height: " << board.size() << endl;

    // runGame(randomBoard(getTerminalHeight()-5,getTerminalWidth()-5), 10);
    runGame(randomBoard(), 500);
    // cout << "Successful run, terminating" << endl;
    return 0;
}