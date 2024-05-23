#include <iostream>
#include "level.h"
#include "player.h"
#include "globals.h"
#include "levels.h"

level::level() : rows(0), columns(0), data(nullptr) {};

level::~level() {
    unload();
}

void level::load_next() {
    level_index++;
    if (level_index >= LEVEL_COUNT) {
        level_index = 0;
        game_state = VICTORY_STATE;
        create_victory_menu_background();
    }

    level_info level_info{};

    try{
        level_info = parse_level();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    };

    rows = level_info.rows;
    columns = level_info.columns;
    data = new char[rows * columns];

    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            char cell = level_info.level_data[row * columns + column];
            if (cell == PLAYER) {
                set_cell(row, column, FLOOR);
                game_player.spawn(row, column);
            } else if (cell == PLAYER_ON_GOAL) {
                set_cell(row, column, GOAL);
                game_player.spawn(row, column);
            } else {
                set_cell(row, column, cell);
            }
        }
    }

    derive_graphics_metrics_from_loaded_level();
}

void level::unload() {
    if (data) {
        delete[] data;
        data = nullptr;
    }
    rows = 0;
    columns = 0;
}

bool level::is_cell_inside(int row, int column) const {
    return row < rows && column < columns;
}

char& level::get_cell(size_t row, size_t column) const {
    return data[row * columns + column];
}

void level::set_cell(size_t row, size_t column, char cell) {
    data[row * columns + column] = cell;
}

