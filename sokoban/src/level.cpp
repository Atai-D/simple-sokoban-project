#include "level.h"
#include "player.h"
#include "globals.h"

level::level() : rows(0), columns(0), data(nullptr) {};

level::~level() {
    unload_level();
}

void level::load_level(char* level_data) {
    rows = 11;
    columns = 19;
    data = new char[rows * columns];

    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            char cell = level_data[row * columns + column];
            if (cell == PLAYER) {
                set_level_cell(row, column, FLOOR);
                game_player.spawn_player(row, column);
            } else if (cell == PLAYER_ON_GOAL) {
                set_level_cell(row, column, GOAL);
                game_player.spawn_player(row, column);
            } else {
                set_level_cell(row, column, cell);
            }
        }
    }

    derive_graphics_metrics_from_loaded_level();
}

void level::unload_level() {
    if (data) {
        delete[] data;
        data = nullptr;
    }
    rows = 0;
    columns = 0;
}

bool level::is_cell_inside_level(int row, int column) const {
    return row < rows && column < columns;
}

char& level::get_level_cell(size_t row, size_t column) const {
    return data[row * columns + column];
}

void level::set_level_cell(size_t row, size_t column, char cell) {
    data[row * columns + column] = cell;
}
