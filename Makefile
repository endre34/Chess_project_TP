CC = gcc
OBJ = main.o helper.o
LIBS = -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window
PRG_N = Chess

$(PRG_N) : $(OBJ)
	$(CC) -Wall -g -o $(PRG_N) $(OBJ) $(LIBS)

$(OBJ) : helper.h

.PHONY : clean
clean :
	-rm prg $(OBJ)
