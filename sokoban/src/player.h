#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

class player {
public:
    player();
    ~player();

    void move(int dx, int dy, level &level);
    void display() const;

private:
    int x, y;
    char symbol;
};

#endif // PLAYER_H
