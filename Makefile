# makefile to run CPP
# WSC, 25-Oct-2022
#
# example usage:   >make compile PRG_NAME=pascal

# USER definitions
INC_DIR = ./src
PRG_NAME = hello
# define compile options, eg -std=c++20 or -std=c++23
COMPILE_OPTIONS = -std=c++23 -Wall -lfmt
# define which CPP compiler should be used: g++ or clang++
CPP_COMPILER = clang++
# end of USER definitions

OBJ_FILES = $(addsuffix .o, $(CPP_FILES))

echo:
	@echo "help: makefile to run cpp"
	@echo "> make compile     ... compile file"
	@echo "> make run         ... compile all files and run program"
	@echo "> make clean       ... remove all generated files"

# compile rule for modules
%.o: src/%.cpp
	$(CPP_COMPILER) -I$(INC_DIR) -c $< $(COMPILE_OPTIONS)

# for simple compile of just one cpp file
compile: src/$(PRG_NAME).cpp
	$(CPP_COMPILER) -I$(INC_DIR) $< -o $(PRG_NAME).out $(COMPILE_OPTIONS)

# start the executable
run: compile
	./$(PRG_NAME).out

clean:
	-rm *.o *.out