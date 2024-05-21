#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

class player {
public:

    static player* get_instance();
    void move(int dx, int dy, level &level);
    void display() const;

private:
    player();
    ~player();
    int x, y;
    char symbol;
    static player* instance;
};

#endif // PLAYER_H
