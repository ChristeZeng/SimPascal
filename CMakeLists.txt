project(compiler)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(myparser
                ${CMAKE_SOURCE_DIR}/SimPascal.y
                ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
                COMPILE_FLAGS "--defines=${CMAKE_CURRENT_BINARY_DIR}/parser.hpp --verbose")
FLEX_TARGET(mylexer
                ${CMAKE_SOURCE_DIR}/SimPascal.l
                ${CMAKE_CURRENT_BINARY_DIR}/tokenizer.cpp)
ADD_FLEX_BISON_DEPENDENCY(mylexer myparser)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${CMAKE_SOURCE_DIR}/ ${CMAKE_BINARY_DIR} ${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

file(GLOB SOURCE_FILES
        "/*.cpp"
        "/*.h"
        "AST/*.h"
        "AST/*.cpp"
        "generator/*.h"
        "generator/*.cpp"
        )

add_executable(
        ${CMAKE_PROJECT_NAME}
        ${SOURCE_FILES}
        ${FLEX_our_lexer_OUTPUTS}
        ${BISON_our_parser_OUTPUTS}
        generator/CodeGenerator.cpp generator/genConstType.cpp generator/genExp.cpp generator/genFunc.cpp generator/genProgram.cpp generator/genStmt.cpp)
target_include_directories(${CMAKE_PROJECT_NAME}
        PRIVATE
        .
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/
        ${LLVM_INCLUDE_DIRS})
set_property(TARGET ${CMAKE_PROJECT_NAME}
        PROPERTY CXX_STANDARD 14)

llvm_map_components_to_libnames(llvm_libs all)
target_link_libraries(${CMAKE_PROJECT_NAME} ${llvm_libs})
