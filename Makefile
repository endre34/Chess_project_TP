CC = gcc
OBJ = main.o helper.o

prg : $(OBJ)
	$(CC) -Wall -g -o prg $(OBJ)

$(OBJ) : helper.h

.PHONY : clean
clean :
	-rm prg $(OBJ)
