cmake_minimum_required(VERSION 3.14)
project(MiniDecaf)

set(CMAKE_CXX_STANDARD 14)


include_directories(
    ${PROJECT_SOURCE_DIR}/generated/
    ${PROJECT_SOURCE_DIR}/third_party/
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime
    ${PROJECT_SOURCE_DIR}/src/
)

set(src_dir
    ${PROJECT_SOURCE_DIR}/generated/LuaLexer.cpp
    ${PROJECT_SOURCE_DIR}/generated/LuaParser.cpp
    ${PROJECT_SOURCE_DIR}/generated/LuaVisitor.cpp
    ${PROJECT_SOURCE_DIR}/generated/LuaBaseVisitor.cpp
)

execute_process(
    COMMAND 
        antlr4 -Dlanguage=Cpp ${g4-file} -visitor
)

file(g4-file
    ${PROJECT_SOURCE_DIR}/MiniDecaf.g4}
)

file(GLOB antlr4-cpp-src
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/atn/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/dfa/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/misc/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/support/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/tree/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/tree/pattern/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/tree/xpath/*.cpp
)

add_library(antlr4-cpp-rurntime ${antlr4-cpp-src})
add_executable(MiniDecaf ${src_dir} ${PROJECT_SOURCE_DIR}/src/*.cpp)
target_link_libraries(MiniDecaf antlr4-cpp-runtime)