#include "Cursor.h"

Cursor::Cursor() {
    x = 0;
    y = 0;
}

void Cursor::move(char dir) {
    switch (dir) {
        case 'w':
        case 'W':
            if (y > 0) y--;
            break;
        case 's':
        case 'S':
            if (y < 4) y++;
            break;
        case 'a':
        case 'A':
            if (x > 0) x--;
            break;
        case 'd':
        case 'D':
            if (x < 4) x++;
            break;
    }
}

int Cursor::getX() const {
    return x;
}

int Cursor::getY() const {
    return y;
}
