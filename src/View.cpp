#include "View.h"
#include <iostream>
#include <windows.h>
using namespace std;

string getColorCode(int color) {
    switch (color) {
        case 1: return "\033[47m \033[0m"; // 白
        case 2: return "\033[44m \033[0m"; // 藍
        case 3: return "\033[42m \033[0m"; // 綠
        case 4: return "\033[43m \033[0m"; // 黃
        case 5: return "\033[41m \033[0m"; // 紅
        default: return " ";
    }
}

string getColorCursorCode(int color) {
    switch (color) {
        case 1: return "\033[30;47mX\033[0m";
        case 2: return "\033[30;44mX\033[0m";
        case 3: return "\033[30;42mX\033[0m";
        case 4: return "\033[30;43mX\033[0m";
        case 5: return "\033[30;41mX\033[0m";
        default: return "\033[37;40mX\033[0m";
    }
}

void View::draw(const Board& board, const Cursor& cursor, int level, int score) {
    cout << "Level: " << level << "    Score: " << score << endl;
    cout << "Target             Your Board" << endl;
    cout << "+-----+            +-----+" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << "|";
        // target
        for (int j = 0; j < 5; ++j) {
            int c = board.getAnswerValue(j, i); 
            cout << getColorCode(c);
        }
        cout << "|            |";

        // plaer
        for (int j = 0; j < 5; ++j) {
            bool isCursor = (cursor.getX() == j && cursor.getY() == i);
            int color = board.getColoredValue(j, i);  

            if (isCursor) {
                cout << getColorCursorCode(color);
            } else {
                cout << getColorCode(color);
            }
        }
        cout << "|" << endl;
    }

    cout << "+-----+            +-----+" << endl;
    cout << "[WASD] Move  [E] Paint " << endl;
    cout << "[Space] Erase" << endl;
    cout << "[F] Change brush color" << endl;
    cout << "[C] Submit   [R] Reset   [Q] Quit" << endl;
}
