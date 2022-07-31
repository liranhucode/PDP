#pragma once
#include <iostream>
#include <vector>

#include "utility.h"
#include "db_cell.h"
#include "db_row.h"
#include "db_net.h"

namespace pdp {

    class Site {
         
    };


    class DB {
      public:
        bool read_def(const std::string& file_name);

      public:
        std::vector<Cell *> &get_cell() { return cells_; }

        Row *create_row(const std::string &name);
        Cell *create_cell(const std::string &name);

      private:
        std::vector<Row *> rows_;
        std::vector<Cell *> cells_;
    };
}  // namespace PDP
