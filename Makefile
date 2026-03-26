CC = gcc
OBJ = main.o
LIBS = -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window
PRG_N = Chess

$(PRG_N): $(OBJ)
	$(CC) -Wall -g -o $(PRG_N) $(OBJ) $(LIBS)

$(OBJ):

.PHONY: clean
clean:
	-rm $(PRG_N) $(OBJ)
