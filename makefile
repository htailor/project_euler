
CC = g++ -Ilib
COMPILE = $(CC)

BINARY_FILES = $(patsubst %.cpp, %, $(wildcard *.cpp))

#Tell make to make one .out file for each .cpp file found in the current directory

all: $(BINARY_FILES)

#Rule how to create arbitary .out files. 
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
#Then the command to create the .out file, probably you want to add further options to the g++ call.

%: %.cpp
	$(COMPILE) $< -o $@

clean: 
	rm -rf $(BINARY_FILES)
