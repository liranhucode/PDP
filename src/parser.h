/******************************************************************************
*   
*  Author: liranhu
*******************************************************************************/
#pragma once
#include "db.h"
#include "defrReader.hpp"
#include "defiAlias.hpp"

namespace pdp {

    class Parser {
      public:
        static Parser& get_instance()
        {
            static Parser instance;
            return instance;
        }

        void read_def(std::string &def_file);
        static int def_row_cbk(defrCallbackType_e c, defiRow* ro, defiUserData ud);
      private:
        DB db_;
        static void *userData;

    };

}  // namespace pdp