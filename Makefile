# ===== Program =====
PRG_N = Chess

# ===== Compiler & compiler settings =====
CC = gcc
CFLAGS = -Wall -Wextra -g -O0 -I include

# ===== Libraries =====
LIBS = -l csfml-graphics -l csfml-system -l csfml-window -l m

# ===== Building program from =====
OBJ = build/main.o build/button.o build/main_menu.o build/display_field.o build/ui_utils.o

all: $(PRG_N)

$(PRG_N): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PRG_N) $(LIBS)

build/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build/main.o:

build/main_menu.o: include/main_menu.h include/interfaces.h include/ui_elements.h include/button.h include/mouse.h

build/ui_utils.o: include/ui_utils.h
build/button.o: include/button.h include/ui_elements.h include/ui_utils.h
build/display_field.o: include/display_field.h include/ui_elements.h


.PHONY: clean rebuild run

clean:
	-rm -rf $(PRG_N) $(OBJ) build

rebuild: clean all

run: $(PRG_N)	# build and run
	./$(PRG_N)