#include "parser.h"


namespace pdp
{
    //static DB* db = new DB();
    static int i = 0;
    //static void* userData;
    void Parser::read_def(std::string& def_file)
    {

        //userData = &db_;
        defrInitSession(0);
        //defrSetUserData((void*)db);
        defrSetRowCbk((defrRowCbkFnType)def_row_cbk);

        FILE*       f       = nullptr;
        const char* fileStr = def_file.c_str();
        if ((f = fopen(fileStr, "r")) == 0) {
            fprintf(stderr, "**\nERROR: Couldn't open input file '%s'\n", fileStr);
            exit(1);
        }

        int res = defrRead(f, fileStr, &db_, 1);
        if (res) {
            std::cout << "Reader returns bad status: " << fileStr << std::endl;
            exit(1);
        }
        else {
            std::cout << "Reading " << fileStr << " is Done" << std::endl;
        }

        defrUnsetRowCbk();
    }

    int Parser::def_row_cbk(defrCallbackType_e c, defiRow* defrow, defiUserData ud)
    {
        DB  *db  = (DB *)ud;
        Row *row = db->create_row(defrow->name());

        row->orig_x(defrow->x());
        row->orig_y(defrow->y());
        if (defrow->hasDo()) {
            row->num_sites(defrow->xNum());
        }
        if (defrow->hasDoStep()) {
            row->step_x(defrow->xStep());
            row->step_y(defrow->yStep());
        }

        row->print();

        return 0;
    }
} // namespace pdp

