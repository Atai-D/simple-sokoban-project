#ifndef LEVEL_H
#define LEVEL_H

#include <cstddef>

class level {
public:
    level();
    ~level();

    void load_level(const level& lvl);
    void unload_level();
    [[nodiscard]] bool is_cell_inside_level(int row, int column) const;
    [[nodiscard]] char& get_level_cell(size_t row, size_t column) const;
    void set_level_cell(size_t row, size_t column, char cell);

private:
    size_t rows, columns;
    char *data;
};

#endif // LEVEL_H
