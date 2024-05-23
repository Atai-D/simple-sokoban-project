#ifndef LEVELS_H
#define LEVELS_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "globals.h"
#include "level.h"

std::vector<std::string> parse_sl_file() {
    std::ifstream sl_file("../data/levels.sl");
    if (!sl_file.is_open()) {
        throw std::runtime_error("Failed to open the file");
    }
    std::stringstream buffer;
    buffer << sl_file.rdbuf();
    std::string input = buffer.str();

    size_t last = 0;
    size_t next = 0;

    std::vector<std::string> levels;
    while ((next = input.find("\n", last)) != std::string::npos) {
        levels.push_back(input.substr(last, next - last));
        last = next + 1;
    }

    return levels;
}

level_info parse_level() {
    level_info level_info{};

    auto levels = parse_sl_file();

    if (level_index * 2 >= levels.size()) {
        throw std::out_of_range("Invalid level index: " + std::to_string(level_index));
    }

    std::string cur_level = levels[level_index * 2];
    std::vector<std::vector<char>> temp_level;

    bool last_char_is_digit = false;
    bool last_char_is_double_digit = false;

    size_t rows_count = 0;
    std::vector<char> row;

    for (int j = 0; j < cur_level.length(); j++) {
        if (last_char_is_digit) {
            last_char_is_digit = false;
            continue;
        } else if (last_char_is_double_digit) {
            last_char_is_double_digit = false;
            continue;
        }

        char current_char = cur_level[j];
        if (isdigit(current_char)) {
            int multiplier = current_char - '0';
            char char_to_push = cur_level[j + 1];
            if (isdigit(cur_level[j + 1])) {
                last_char_is_double_digit = true;
                char_to_push = cur_level[j + 2];
                std::string res = std::string(1, current_char) + std::string(1, cur_level[j + 1]);
                multiplier = std::stoi(res);
            }
            last_char_is_digit = true;

            for (int k = 0; k < multiplier; k++) {
                row.push_back(char_to_push);
            }
        } else if (current_char == '|') {
            rows_count++;
            temp_level.push_back(row);
            row.clear();
        } else {
            row.push_back(cur_level[j]);
        }

    }
    temp_level.push_back(row);
    row.clear();
    rows_count++;
    size_t max_columns = 0;

    for (auto j: temp_level) {
        if (j.size() > max_columns) max_columns = j.size();
    }

    level_info.level_data = new char[rows_count * max_columns];

    for (int j = 0; j < temp_level.size(); j++) {
        for (int k = 0; k < max_columns; k++) {
            if (k < temp_level[j].size()) {
                level_info.level_data[k + max_columns * j] = temp_level[j][k];
            } else {
                level_info.level_data[k + max_columns * j] = ' ';
            }
        }
    }

    level_info.rows = rows_count;
    level_info.columns = max_columns;

    return level_info;
}

size_t get_level_count() {
    auto level = parse_sl_file();
    return level.size() / 2;
}

#endif // LEVELS_H
