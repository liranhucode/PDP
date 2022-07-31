#pragma once
#include <iostream>
#include <string>

#include "pdp_timer.h"
#include "pdp_option.h"

namespace pdp
{
    class Rect
    {
      public:
        Rect() {}
        ~Rect() {}

      private:
        int lx = 0;
        int ly = 0;
        int ux = 0;
        int uy = 0;
    };

}  // namespace pdp