#include "pdpCommand.h"
#include "database/parser.h"
#include "detail_placer.h"


namespace pdp {

    int pdp_cmd_manager::read_lef_cmd(ClientData  notUsed,
                                      Tcl_Interp* interp,
                                      int         argc,
                                      char**      argv)
    {
        std::cout << "Loading lef ..." << std::endl;
        std::cout << argc << " " << argv[1] << std::endl;
        return TCL_OK;
    }

    int pdp_cmd_manager::read_def_cmd(ClientData  notUsed,
                                      Tcl_Interp* interp,
                                      int         argc,
                                      char**      argv)
    {
        std::cout << "Loading def " << argv[1] << std::endl;
        std::string def_file = std::string(argv[1]);
        Parser &paser = Parser::get_instance();
        paser.read_def(def_file);
        return TCL_OK;
    }

    int pdp_cmd_manager::detail_place_cmd(ClientData notUsed, Tcl_Interp *interp, int argc, char **argv)
    {
        std::cout << "Doing detail placement " << std::endl;
        Parser &paser = Parser::get_instance();
        if (!paser.is_done()) {
            return TCL_ERROR;
        }

        placer dplacer(paser.get_db());

        dplacer.run();
        dplacer.report();
        
        return TCL_OK;
    }
}  // namespace pdp