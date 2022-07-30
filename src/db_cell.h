#pragma once
#include <string>

namespace pdp
{

    class Macro
    {
      public:
        Macro() {}

      private:
        std::string name_;
    };

    class Cell
    {
      public:
        Cell(const std::string &name)
            : name_(name)
        {
        }

        unsigned id() const { return id_; }
        void print(){}

      private:
        // std::vector<Pin *> pins_;
        std::string name_;
        Macro *macro_ = nullptr;

        unsigned id_;
        int x_coord_;
        int y_coord_;
        int init_x_coord_;
        int init_y_coord_;
        double width_; 
        double height_;
        bool is_fixed_ = false;
        bool is_placed_ = false;
        bool is_group_;
        unsigned bin_id_;
    };
}  // namespace pdp