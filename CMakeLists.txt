cmake_minimum_required(VERSION 3.10)
project(SimPascal)

find_package(LLVM REQUIRED CONFIG)
include_directories(.)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(/usr/include/llvm-10)
include_directories(/usr/include/llvm-c-10)

execute_process(COMMAND llvm-config --libs OUTPUT_VARIABLE LLVM_LINK_LIBRARIES)
string(STRIP "${LLVM_LINK_LIBRARIES}" LLVM_LINK_LIBRARIES)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(AST AST_SOURCE)
aux_source_directory(generator GEN_SOURCE)
aux_source_directory(VIS VIS_SOURCE)

add_custom_command(
    OUTPUT token.cpp
    COMMAND lex -o token.cpp ${CMAKE_CURRENT_LIST_DIR}/SimPascal.l
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/SimPascal.l parser.cpp
)

add_custom_command(
    OUTPUT parser.hpp parser.cpp 
    COMMAND yacc -d -o parser.cpp ${CMAKE_CURRENT_LIST_DIR}/SimPascal.y
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/SimPascal.y
)

add_executable(
    SimPascal
    main.cpp ${AST_SOURCE} ${GEN_SOURCE} ${VIS_SOURCE} token.cpp
    parser.cpp parser.hpp
    )

set_target_properties(SimPascal PROPERTIES LINK_LIBRARIES "${LLVM_LINK_LIBRARIES}")