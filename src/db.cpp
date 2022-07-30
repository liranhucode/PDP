#include "db.h"

namespace pdp
{
    Row* DB::create_row(const std::string& name)
    {
        Row* row = new Row(name);
        rows.push_back(row);
        return row;
    }
}