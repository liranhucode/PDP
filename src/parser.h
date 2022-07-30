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
        void read_lef(std::string &lef_file) {}

        //call back
        static int def_row_cbk(defrCallbackType_e ct, defiRow* defrow, defiUserData ud);
      private:
        DB db_;

    };

}  // namespace pdp