#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char> > &board);
void displayBoard(const vector<vector<char> > &board);
bool makeMove(vector<vector<char> > &board, char currentPlayer, int row, int col);
bool checkWin(const vector<vector<char> > &board, char currentPlayer);
bool checkDraw(const vector<vector<char> > &board);
void switchPlayer(char &currentPlayer);
bool playAgain();

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    do {
        initializeBoard(board);
        displayBoard(board);

        while (true) {
            int row, col;

            // Player input
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Make a move
            if (makeMove(board, currentPlayer, row, col)) {
                displayBoard(board);

                // Check for win
                if (checkWin(board, currentPlayer)) {
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }

                // Check for draw
                if (checkDraw(board)) {
                    cout << "It's a draw!" << endl;
                    break;
                }

                // Switch players
                switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    } while (playAgain());

    cout << "Thanks for playing! Goodbye." << endl;

    return 0;
}

void initializeBoard(vector<vector<char> > &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char> > &board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl;
    }
    cout << endl;
}

bool makeMove(vector<vector<char> > &board, char currentPlayer, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false; // Invalid move
    }
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin(const vector<vector<char> > &board, char currentPlayer) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char> > &board) {
    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // Board is not full
            }
        }
    }
    return true; // Board is full, and no player has won
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
