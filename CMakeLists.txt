#core
project(Core) 
cmake_minimum_required(VERSION 2.6)

set(INCLUDE_FILES include/plataform.h
		  include/CTime.h)

set(SOURCE_FILES src/CTime.cpp)

include_directories( include/)
add_definitions(-DUNIX -DLINUX -DUSE_STL)
add_library(Core STATIC ${SOURCE_FILES})
