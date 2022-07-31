
#pragma once

#include <iostream>
#include <vector>

#include "db_cell.h"

namespace pdp
{

    enum class Power
    {
        GND = 0,
        VDD = 1
    };

    enum class Orient
    {
        N = 0,
        W = 1,
        S = 2,
        E = 3,
        FN = 4,
        FW = 5,
        FS = 6,
        FE = 7,
        UNKNOW = 8
    };

    class Row
    {
      public:
        Row()
            : name_("")
            , site_(0)
            , orig_x_(0)
            , orig_y_(0)
            , step_x_(0)
            , step_y_(0)
            , num_sites_(0)
            , orient_(Orient::N)
        {
        }

        Row(const std::string &name)
            : name_(name)
            , site_(0)
            , orig_x_(0)
            , orig_y_(0)
            , step_x_(0)
            , step_y_(0)
            , num_sites_(0)
            , orient_(Orient::N)
        {
        }

        void print() { std::cout << "Loading row " << name_ << " x " << orig_x_ << " y " << orig_y_ << std::endl; }

        void orig_x(int x) { orig_x_ = x; }
        void orig_y(int y) { orig_y_ = y; }
        void step_x(int x) { step_x_ = x; }
        void step_y(int x) { step_y_ = x; }
        void num_sites(int num) { num_sites_ = num; }

      private:
        std::string name_;
        unsigned site_;
        unsigned orig_x_; /* (in DBU) */
        unsigned orig_y_; /* (in DBU) */
        unsigned step_x_; /* (in DBU) */
        unsigned step_y_; /* (in DBU) */
        unsigned num_sites_;
        Orient orient_;
        Power top_power_;
        Power bottom_power_;

        std::vector<Cell *> cell_list;
    };

}  // namespace pdp