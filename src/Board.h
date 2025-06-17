#pragma once
#include <vector>

class Board {
private:
std::vector<std::vector<int>> answer;
std::vector<std::vector<int>> colored;

public:
    Board(int level);
    void resetPlayer(); //清空
    bool isColored(int x, int y) const;  // 判斷著色
    void paint(int x, int y, int brushColor); // 著色
    void dig(int x, int y); // 挖空
    bool isCorrect() const; //比較
    int getAnswerValue(int x, int y) const; // 題目顏色
    int getColoredValue(int x, int y) const; // 玩家顏色
};
