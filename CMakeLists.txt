CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)
# set(CMAKE_CXX_COMPILER "clang")


# ANTLR_CMD = antlr4 -visitor lambda.g4 -o source/frontend/ -Dlanguage=Cpp


project(LambdaCalculus)

set(ANTLR4_ZIP_REPOSITORY ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/antlr/antlr4-master.zip)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 17)

# required if linking to static library
# add_definitions(-DANTLR4CPP_STATIC)
add_definitions(-DANTLR4CPP_SHARED)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.8-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
# antlr_target(SampleGrammarLexer TLexer.g4 LEXER
#              PACKAGE antlrcpptest)
# antlr_target(SampleGrammarParser TParser.g4 PARSER
#              PACKAGE antlrcpptest
#              DEPENDS_ANTLR SampleGrammarLexer
#              COMPILE_FLAGS -lib ${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
antlr_target(Sample lambda.g4)
# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

include_directories(${PROJECT_SOURCE_DIR}/thirdparty/switch/include)
include_directories(${PROJECT_SOURCE_DIR}/thirdparty/argh/include)

file(GLOB_RECURSE SOURCES "source/*.cpp")

# add generated grammar to demo binary target
add_executable(lcalc ${SOURCES}
               ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
               ${ANTLR_SampleGrammarParser_CXX_OUTPUTS}
               antlr4_runtime
               )
# target_link_libraries(lcalc antlr4_static)
target_link_libraries(lcalc antlr4_shared)


set(STD_SOURCE ${PROJECT_SOURCE_DIR}/language/std.la)

add_custom_command(TARGET lcalc PRE_BUILD
    COMMAND cp ${STD_SOURCE} ${CMAKE_BINARY_DIR}
    COMMENT "Coppied standard library to build directory."
)