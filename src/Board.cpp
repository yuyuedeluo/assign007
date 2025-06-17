#include "Board.h"
#include <cstdlib>
#include <ctime>

Board::Board(int level) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int maxColor = std::min(5, level); // Level 決定能用幾種顏色

    answer.resize(5, std::vector<int>(5, 0));
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            answer[i][j] = std::rand() % (maxColor + 1); 
    resetPlayer();
}

void Board::resetPlayer() {
    colored.assign(5, std::vector<int>(5, 0)); 
}


void Board::paint(int x, int y, int brushColor) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        colored[y][x] = brushColor;
    }
}

void Board::dig(int x, int y) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        colored[y][x] = 0;
    }
}


bool Board::isColored(int x, int y) const {
    return colored[y][x];
}

bool Board::isCorrect() const {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (colored[i][j] != answer[i][j])
                return false;
    return true;
}

int Board::getAnswerValue(int x, int y) const {
    return answer[y][x];
}

int Board::getColoredValue(int x, int y) const {
    return colored[y][x];
}
