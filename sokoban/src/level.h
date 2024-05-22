#ifndef LEVEL_H
#define LEVEL_H

#include <cstddef>

struct level_info {
    size_t rows, columns;
    char* level_data;
};

class level {
public:
    level();
    ~level();

    void load_level();
    void unload_level();
    [[nodiscard]] bool is_cell_inside_level(int row, int column) const;
    [[nodiscard]] char& get_level_cell(size_t row, size_t column) const;
    void set_level_cell(size_t row, size_t column, char cell);
    [[nodiscard]] size_t get_rows() const{
        return rows;
    }

    [[nodiscard]] size_t get_columns() const{
        return columns;
    }

private:
    size_t rows, columns;
    char *data;
};

level_info parse_and_load_next_level();

size_t get_level_count();

#endif // LEVEL_H
