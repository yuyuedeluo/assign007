#pragma once

class Cursor {
private:
    int x, y;
public:
    Cursor();
    void move(char dir); 
    int getX() const;
    int getY() const;
};
