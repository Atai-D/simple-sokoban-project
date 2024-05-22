#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

class player {
public:
    static player& get_instance();
    void move(int dx, int dy);
    void spawn(int row, int column);
    [[nodiscard]] int get_row() const {
        return player_row;
    }
    [[nodiscard]] int get_column() const {
        return player_column;
    }

private:
    player();
    ~player();

    player(const player&) = delete;
    player& operator=(const player&) = delete;
    int player_row, player_column;
};

#endif // PLAYER_H
