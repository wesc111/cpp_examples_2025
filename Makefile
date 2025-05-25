# makefile to run CPP
# Copyright (c) 2022-2025, Werner Schoegler
#     V0.0: initial version: 25-Oct-2022
#     V0.1: added compile options, link options, and user definitions: 25-May-2025
#           tested on UBUNTU linux and MAC OS-X 16.5

# USER definitions
INC_DIR = -I./include -I/usr/local/include
PRG_NAME = hello
# define compile options, eg -std=c++14 -std=c++20 or -std=c++23 -lfmt 
# For usage of catch2: note that link order must be first -lCatch2Main and then -lCatch2 
COMPILE_OPTIONS = -std=c++23 -Wall 
LINK_OPTIONS = -lfmt -lCatch2Main -lCatch2 
# define which CPP compiler should be used: g++ or clang++
CPP_COMPILER = clang++
# USER definitions for complink of programs made of several modules
OBJ_LIST2  = myfunc 
TEST_LIST2 = test_myfunc
PRG_NAME2  = test_myfunc.out
# end of USER definitions

OBJ_FILES = $(addsuffix .o, $(CPP_FILES))

# show usage of this makefile
.PHONY: help show_usage compile run complink clean
help: show_usage

# compile rule compiling each cpp file into a .o file
%.o: src/%.cpp
	$(CPP_COMPILER) $(INC_DIR) -c $< $(COMPILE_OPTIONS)
%.o: test/%.cpp
	$(CPP_COMPILER) $(INC_DIR) -c $< $(COMPILE_OPTIONS)

# for simple compile of just one cpp file
compile: src/$(PRG_NAME).cpp
	$(CPP_COMPILER) $(INC_DIR) $< -o $(PRG_NAME).out $(COMPILE_OPTIONS) $(LINK_OPTIONS)

# compile and link programs that defined by several cpp modules into PRG_NAME2
OBJ_LIST2_O = $(addsuffix .o, $(OBJ_LIST2))
TEST_LIST2_O = $(addsuffix .o, $(TEST_LIST2))
complink: $(OBJ_LIST2_O) $(TEST_LIST2_O)
	$(CPP_COMPILER) $(INC_DIR) $^ -o $(PRG_NAME2) $(COMPILE_OPTIONS) $(LINK_OPTIONS)

# start the executable
run: compile
	./$(PRG_NAME).out

clean:
	-rm *.o *.out

show_usage:
	@echo "Makefile for compiling and running C++ programs"
	@echo "--------------------------------------------------"
	@echo "This makefile allows you to compile and run C++ programs with optional parameters."
	@echo "To compile and run a program, use 'make run' or 'make compile' with optional PRG_NAME."
	@echo "To compile a program with multiple modules, use 'make complink'."
	@echo "To clean up generated files, use 'make clean'."
	@echo "For more details, see the help below."
	@echo "> make compile                 ... compile file (default)"
	@echo "> make compile PRG_NAME=pascal ... compile file (pascal.cpp)"
	@echo "> make run                     ... compile and run program (default)"
	@echo "> make run PRG_NAME=pascal     ... compile and run program (pascal.cpp)"
	@echo "> make complink                ... compile program with more than one module"
	@echo "> make clean                   ... remove all generated files"

# just some trials with debugging to show values of automatic variables
test_: test_.oo
test_.oo: src/hello.cpp src/pascal.cpp
	@echo "the name of the target: $@"
	@echo "the filename of the first prerequisite: $<"
	@echo "the filename of all prerequisites: $^"
	@echo "the filename of all prerequisites that are newer then the target: @echo $?"
	@echo $%
	@echo $*