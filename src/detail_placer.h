#pragma once
#include "database/db.h"

namespace pdp
{
    class placer
    {
      public:
        placer(DB *db)
            : db_(db)
        {
        }
        placer() = delete;

        void run()
        {
            Timer timer("detail_place");
            std::cout << "Runing detail placer" << std::endl;
            timer.Report("");
        }
        void report()
        {
            std::cout << "After detail placer" << std::endl;
            std::cout << "Report : " << std::endl;
        }

    private : DB *db_;
    };
} // namespace pdp
