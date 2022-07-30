#pragma once
#include <iostream>
#include <vector>

namespace pdp {

    enum class Power
    {
        GND = 0,
        VDD = 1
    };

    enum class Orient 
    {
        N = 0,
        S = 1
    };

    class Site {
         
    };


    class Cell
    {

    };

    class Net
    {


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

        Row(const std::string& name)
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
        unsigned    site_;
        int         orig_x_; /* (in DBU) */
        int         orig_y_; /* (in DBU) */
        int         step_x_; /* (in DBU) */
        int         step_y_; /* (in DBU) */
        int         num_sites_;
        Orient      orient_;
        Power       top_power_;

        std::vector<Cell*> cell_list;
    };

    class DB {
      public:
        bool read_def(const std::string& file_name);

      public:
        Row *create_row(const std::string &name);
      private:
        std::vector<Row *> rows;
    };
}  // namespace PDP
