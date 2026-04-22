# ===== Program =====
PRG_N = Chess

# ===== Compiler & compiler settings =====
CC = gcc
CFLAGS = -Wall -Wextra -g -O0 -I include

# ===== Libraries =====
LIBS = -l csfml-graphics -l csfml-system -l csfml-window -l m

# ===== Program directories =====
SRC_DIR = src
INC_DIR = include
BLD_DIR = build

# ===== Building program from =====
OBJ = $(BLD_DIR)/main.o $(BLD_DIR)/button.o $(BLD_DIR)/main_menu.o $(BLD_DIR)/display_field.o $(BLD_DIR)/ui_utils.o

all: $(PRG_N)

$(PRG_N): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PRG_N) $(LIBS)

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR)/main.o: $(SRC_DIR)/main.c

$(BLD_DIR)/main_menu.o: $(SRC_DIR)/main_menu.c $(INC_DIR)/main_menu.h $(INC_DIR)/interfaces.h $(INC_DIR)/ui_elements.h $(INC_DIR)/button.h $(INC_DIR)/mouse.h

$(BLD_DIR)/ui_utils.o: $(SRC_DIR)/ui_utils.c $(INC_DIR)/ui_utils.h
$(BLD_DIR)/button.o: $(SRC_DIR)/button.c $(INC_DIR)/button.h $(INC_DIR)/ui_elements.h $(INC_DIR)/ui_utils.h
$(BLD_DIR)/display_field.o: $(SRC_DIR)/display_field.c $(INC_DIR)/display_field.h $(INC_DIR)/ui_elements.h


.PHONY: clean rebuild run

clean:
	-rm -rf $(PRG_N) $(OBJ) build

rebuild: clean all

run: $(PRG_N)	# build and run
	./$(PRG_N)