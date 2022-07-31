#include "db.h"

namespace pdp
{
    Row* DB::create_row(const std::string& name)
    {
        Row* row = new Row(name);
        rows_.push_back(row);
        return row;
    }

    Cell* DB::create_cell(const std::string& name)
    {
        Cell *cell = new Cell(name);
        cells_.push_back(cell);
        return cell;
    }
}