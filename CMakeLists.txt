cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(PDP)

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_compile_options(-Wreturn-type)

set(THREADS_PREFER_PTHREAD_FLAG ON)


set(PDP_HOME ${PROJECT_SOURCE_DIR} )
set(DEFLIB_HOME
  ${PROJECT_SOURCE_DIR}/def
)
set(LEFLIB_HOME
  ${PROJECT_SOURCE_DIR}/lef
)

find_package( TCL )

add_subdirectory(${DEFLIB_HOME})
add_subdirectory(${LEFLIB_HOME})



file(GLOB SRC_FILES src/*.cpp)


############################################################
# Include directories
############################################################

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


############################################################
# Executable setting 
############################################################

add_executable( PDP
  ${SRC_FILES}
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
  ${TCL_LIBRARIES}
)

add_dependencies( PDP def )
add_dependencies( PDP lef )

############################################################
# Install  
############################################################

