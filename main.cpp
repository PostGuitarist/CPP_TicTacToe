#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printBoard(char mainArray[3][3]);

int main() {
    int playerNumber = 1;
    char playerChoice = 0;
    char mainArray[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
    };

    printBoard(mainArray);

    do {
        cout << "Player " << playerNumber << ", please enter a number: ";
        cin >> playerChoice;

        string s(1, playerChoice);
        int tmpChoice = stoi(s);

        while (cin.fail() || tmpChoice < 1 || tmpChoice > 9) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a number between 1 and 9: ";
            cin >> playerChoice;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mainArray[i][j] == playerChoice) {
                    if (playerNumber == 1) {
                        mainArray[i][j] = 'x';
                    } else {
                        mainArray[i][j] = 'O';
                    }
                }
            }
        }

        printBoard(mainArray);

        if (playerNumber == 1) {
            playerNumber = 2;
        } else {
            playerNumber = 1;
        }
    } while (playerChoice != 'q');

    return 0;
}

void printBoard(char mainArray[3][3]) {
    cout << "\n\n";
    cout << "        Tic Tac Toe        " << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << mainArray[0][0] << "  |  " << mainArray[0][1] << "  |  " << mainArray[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << mainArray[1][0] << "  |  " << mainArray[1][1] << "  |  " << mainArray[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << mainArray[2][0] << "  |  " << mainArray[2][1] << "  |  " << mainArray[2][2] << endl;
    cout << "     |     |     " << endl << endl;
    cout << "Press q to quit" << endl << endl;
}
