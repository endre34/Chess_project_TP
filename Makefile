CC = gcc
OBJ = helper.o

prg : $(OBJ)
	CC -Wall -g  -o prg $(OBJ)

$(OBJ) : helper.h

.PHONY : clean
clean :
	-rm prg $(OBJ)
