CC = gcc
OBJ = main.o button.o
LIBS = -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window
PRG_N = Chess

$(PRG_N): $(OBJ)
	$(CC) -Wall -g -o $(PRG_N) $(OBJ) $(LIBS)

main.o: button.h
button.o: interactables.h button.h

.PHONY: clean
clean:
	-rm $(PRG_N) $(OBJ)
