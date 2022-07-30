#include "pdpCommand.h"
#include "parser.h"

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

        
        Parser &ps = Parser::get_instance();

        ps.read_def(def_file);

        return TCL_OK;
    }
}  // namespace pdp