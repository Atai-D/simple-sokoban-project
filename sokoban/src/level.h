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

    void load_next();
    void unload();
    [[nodiscard]] bool is_cell_inside(int row, int column) const;
    [[nodiscard]] char& get_cell(size_t row, size_t column) const;
    void set_cell(size_t row, size_t column, char cell);
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

level_info parse_level();

size_t get_level_count();

#endif // LEVEL_H
