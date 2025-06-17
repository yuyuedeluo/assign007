#pragma once
#include "Board.h"
#include "Cursor.h"

class View {
public:
    static void draw(const Board& board, const Cursor& cursor, int level, int score);
};
