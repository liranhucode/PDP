#pragma once

#include <tcl.h>
#include <iostream>

namespace pdp {


    class pdp_cmd_manager
    {
      public:
        static int init_tcl_cmd(Tcl_Interp* interp)
        {
            Tcl_CreateCommand(interp, "help", (Tcl_CmdProc*)help,
                              (ClientData)0, 0);
            Tcl_CreateCommand(interp, "load_lef", (Tcl_CmdProc*)read_lef_cmd,
                              (ClientData)0, 0);
            Tcl_CreateCommand(interp, "load_def", (Tcl_CmdProc*)read_def_cmd,
                              (ClientData)0, 0);
            Tcl_CreateCommand(interp, "detail_place", (Tcl_CmdProc*)detail_place_cmd,
                              (ClientData)0, 0);

            return TCL_OK;
        }

        static int help()
        {
            std::cout << " %load lef xxx.lef" << std::endl;
            std::cout << " %load def xxx.lef" << std::endl;
            std::cout << " %detail_pace " << std::endl;
            return TCL_OK;
        }

        static int read_lef_cmd(ClientData notUsed, Tcl_Interp *interp, int argc, char **argv);
        static int read_def_cmd(ClientData notUsed, Tcl_Interp *interp, int argc, char **argv);
        static int detail_place_cmd(ClientData notUsed, Tcl_Interp *interp, int argc, char **argv);
        // static int detail_place();
    };

}  // namespace pdp
