/******************************************************************************
*   
*  Author: liranhu
*******************************************************************************/
#pragma once
#include "db.h"
#include "defrReader.hpp"
#include "defiAlias.hpp"

namespace pdp {

    //static FILE *fout;

    class Parser {
      public:
        static Parser& get_instance()
        {
            static Parser instance;
            return instance;
        }

        Parser() { db_ = new DB(); }

        DB *get_db() { return db_; }

        bool is_done() const { return is_done_; }
        void read_def(std::string &def_file);
        void read_lef(std::string &lef_file) {}

        static void log_func(const char *errMsg) { fprintf(stdout, "ERROR: found error: %s\n", errMsg); }
        static void warning_func(const char *errMsg) { fprintf(stdout, "WARNING: found error: %s\n", errMsg); }

        //call back
        static int def_row_cbk(defrCallbackType_e ct, defiRow* defrow, defiUserData ud);
        static int def_component_cbk(defrCallbackType_e ct, defiComponent *defcom, defiUserData ud);
        static int def_start_cbk(defrCallbackType_e ct, int num, defiUserData ud);

      private:
        DB *db_;
        bool is_done_ = false;
    };

}  // namespace pdp