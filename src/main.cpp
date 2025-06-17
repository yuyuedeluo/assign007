#include <iostream>
#include <conio.h> // _getch()
#include <cstdlib>
#include "Board.h"
#include "Cursor.h"
#include "View.h"

using namespace std;

int main() {
    int level = 1;
    int score = 0;
    int brushColor = 1;

    while (true) {
        Board board(level);
        Cursor cursor;

        while (true) {
            system("cls"); 
            View::draw(board, cursor, level, score);

            char input = _getch(); 

            if (input == 'w' || input == 'a' || input == 's' || input == 'd')
                cursor.move(input);
            else if (input == 'e' || input == 'E') {
                board.paint(cursor.getX(), cursor.getY(), brushColor);
            }
            else if (input == ' ') {
                board.dig(cursor.getX(), cursor.getY());
            }
            else if (input == 'c' || input == 'C') {
                if (board.isCorrect()) {
                    cout << "CORRECT! Next level!" << endl;
                    score++;
                    level++;
                    system("pause");
                    break;
                } else {
                    cout << "WRONG ANSWER! Push [R] to reset or keep editing!" << endl;
                    system("pause");
                }
            } else if (input == 'r' || input == 'R') {
                board.resetPlayer();
            } else if (input == 'q' || input == 'Q' || input == 27 ) {
                cout << "Quit the game. Levels: " << score << endl;
                return 0;
            }else if (input == 'f' || input == 'F') {
                system("cls");
                View::draw(board, cursor, level, score);
                cout << "Select Brush Color:\n";
                if (level >= 1) cout << "[1]\033[47m \033[0m";
                if (level >= 2) cout << "  [2]\033[44m \033[0m";
                if (level >= 3) cout << "  [3]\033[42m \033[0m";
                if (level >= 4) cout << "  [4]\033[43m \033[0m";
                if (level >= 5) cout << "  [5]\033[41m \033[0m";
                cout << "\nEnter choice: ";

                char choice = _getch();
                int maxColor = std::min(level, 5);
                if (choice >= '0' && choice <= ('0' + maxColor)) {
                    brushColor = choice - '0';
                    cout << "\nBrush color changed to " << brushColor << "!" << endl;
                } else {
                    brushColor = 1;
                    cout << "\nInvalid choice." << endl;
                    cout << "\nBrush color changed to 1!" << endl;
                    system("pause");
                }
            }


        }
    }

    return 0;
}
