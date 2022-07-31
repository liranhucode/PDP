cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(PDP)

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_compile_options(-Wall)
add_compile_options(-D PDP_DEBUG)

set(THREADS_PREFER_PTHREAD_FLAG ON)


#set(PDP_HOME ${PROJECT_SOURCE_DIR} )
set(DEFLIB_HOME
  ${PROJECT_SOURCE_DIR}/src/def
)
set(LEFLIB_HOME
  ${PROJECT_SOURCE_DIR}/src/lef
)
set(DB_HOME
  ${PROJECT_SOURCE_DIR}/src/database
)

file(GLOB SRC_FILES src/*.cpp)
message(STATUS "SRC_FILES = ${SRC_FILES}")
file(GLOB DB_SRC_FILES src/database/*.cpp)
message(STATUS "DB_SRC_FILES = ${DB_SRC_FILES}")



##Third party
find_package(TCL COMPONENTS REQUIRED)
if (TCL_FOUND)
  #message(STATUS "TCL_= ${}")
  message(STATUS "TCL_INCLUDE_DIR = ${TCL_INCLUDE_PATH}")
  message(STATUS "TCL_LIBS = ${TCL_LIBRARY}")
  include_directories(${TCL_INCLUDE_PATH})
endif (TCL_FOUND)

if (TK_FOUND)
  message(STATUS "TK_INCLUDE_DIR = ${TK_INCLUDE_PATH}")
  message(STATUS "TK_LIBS = ${TK_LIBRARY}")
  include_directories(${TK_INCLUDE_PATH})
endif (TK_FOUND)

add_subdirectory(${DEFLIB_HOME})
add_subdirectory(${LEFLIB_HOME})
add_subdirectory(${DB_HOME})



############################################################
# Include directories
############################################################

include_directories(src) 
include_directories(src/database) 

include_directories (
  ${LEFLIB_HOME}/lef
  ${LEFLIB_HOME}/lefzlib
  ${LEFLIB_HOME}/clef
  ${LEFLIB_HOME}/clefzlib

  ${DEFLIB_HOME}/def
  ${DEFLIB_HOME}/defzlib
  ${DEFLIB_HOME}/cdef
  ${DEFLIB_HOME}/cdefzlib
)

############################################################
# Libraries setting 
############################################################


add_executable( PDP
  ${SRC_FILES} 
  ${DB_SRC_FILES}
)

target_link_libraries( PDP 
  PUBLIC
  def
  defzlib
  cdef
  cdefzlib
  lef
  lefzlib
  clef
  clefzlib
  ${TCL_LIBRARY}
  ${TK_LIBRARY}
)

target_link_libraries(PDP ${database})
#target_link_libraries(${PROGNAME} ${TCL_LIBRARY})
#target_link_libraries(${PROGNAME} ${TK_LIBRARY})

add_dependencies( PDP def )
add_dependencies( PDP lef )
add_dependencies( PDP database )

