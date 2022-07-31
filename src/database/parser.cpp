#include "parser.h"

namespace pdp
{

    void Parser::read_def(std::string &def_file)
    {
        FILE *fp = nullptr;
        if ((fp = fopen(def_file.c_str(), "r")) == 0) {
            fprintf(stderr, "**\nERROR: Couldn't open input file '%s'\n", def_file.c_str());
            exit(1);
        }

        defrSetLogFunction(log_func);
        defrInitSession(0);
        defrSetWarningLogFunction(warning_func);

        defrSetUserData((void *)db_);
        defrSetRowCbk(def_row_cbk);
        defrSetComponentStartCbk(def_start_cbk);
        defrSetComponentCbk(def_component_cbk);

        defrInit();
        defrReset();

        int res = defrRead(fp, def_file.c_str(), (void *)db_, 1);
        if (res) {
            std::cout << "Error in reading LEF: " << std::endl;
            exit(1);
        }
        else {
            std::cout << "Reading " << def_file.c_str() << " is Done" << std::endl;
        }

        defrReleaseNResetMemory();
        defrUnsetCallbacks();

        fclose(fp);

        is_done_ = true;
    }

    int Parser::def_row_cbk(defrCallbackType_e ct, defiRow *defrow, defiUserData ud)
    {
        DB *db = (DB *)ud;
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

#ifdef PDP_DEBUG
        row->print();
#endif

        return 0;
    }

    int Parser::def_component_cbk(defrCallbackType_e ct, defiComponent *defcom, defiUserData ud)
    {
        if (defcom == nullptr) {
            return 0;
        }
        DB *db = (DB *)ud;
        Cell *cell = db->create_cell(defcom->name());
        cell->print();

        return 0;
    }
    int Parser::def_start_cbk(defrCallbackType_e ct, int num, defiUserData ud)
    {
        DB *db = (DB *)ud;
        db->get_cell().reserve(num);
        return 0;
    }
}  // namespace pdp
