#pragma once
#include "utility.h"

namespace pdp
{

    class Macro
    {
      public:
        Macro() {}

      private:
        std::string name_;
        std::string type_;   /* equivalent to class, I/O pad or CORE */
        bool is_multi_row;       /* single row = false , multi row = true */
        double x_orig_m_;       /* in microns */
        double y_orig_m_;       /* in microns */
        double width_;       /* in microns */
        double height_;      /* in microns */
        std::vector<unsigned> sites_;

        std::vector<Rect> obs_; /* keyword OBS for non-rectangular shapes in micros */
        //power top_power;         // VDD = 0  VSS = 1 enum
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
        unsigned region_;
    };
}  // namespace pdp