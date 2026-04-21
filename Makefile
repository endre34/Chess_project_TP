CC = gcc
OBJ = main.o button.o main_menu.o display_field.o ui_utils.o
LIBS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm
PRG_N = Chess
CFLAGS = -Wall -Wextra -g -O0

$(PRG_N): $(OBJ)
	$(CC) $(CFLAGS) -o $(PRG_N) $(OBJ) $(LIBS)

main.o: main.c

main_menu.o: main_menu.c main_menu.h interfaces.h ui_elements.h button.h mouse.h

ui_utils.o: ui_utils.c ui_utils.h
button.o: button.c button.h ui_elements.h ui_utils.h
display_field.o: display_field.c display_field.h ui_elements.h


.PHONY: clean
clean:
	-rm -f $(PRG_N) $(OBJ)
