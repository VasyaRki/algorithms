#ifndef TABLE_H
#define TABLE_H
#include <algorithm>
#include <utility>
template <typename T>
class Table
{
public:
    Table()
    {
        row = 0; col = 0; table = NULL;
    }
    Table(size_t _row, size_t _col) : row(_row), col(_col) {
        if (_row == 0 || _col == 0)
            row = col = 0;
        else
            initialization();
    }
    T*& operator[](int index) {
        return table[index];
    }

    T*& operator[](int index) const {
        return table[index];
    }

    void Resize(size_t new_row, size_t new_col)
    {
        T** new_table = new T * [new_row];
        for (int i = 0; i < new_row; i++)
            new_table[i] = new T[new_col];
        size_t copy_idx_row = std::min(new_row, row);
        size_t copy_idx_col = std::min(new_col, col);
        for (size_t i = 0; i < copy_idx_row; ++i) {
            for (size_t j = 0; j < copy_idx_col; j++)
            {
                new_table[i][j] = table[i][j];
            }
        }
        for (int i = 0; i < row; ++i)
            delete[] table[i];
        delete[] table;
        table = new_table;
        row = new_row;
        col = new_col;
    }

    std::pair<size_t, size_t> Size() const
    {
        if(row == 0 || col == 0)
            return {0, 0};
        return {row, col};
    }
private:
    void initialization() {
        table = new T * [row];
        for (int i = 0; i < row; i++)
            table[i] = new T[col];
    }
    size_t row;
    size_t col;
    T** table;
};

#endif
