CC = g++
CFLAGS = -pedantic-errors -std=c++11

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
DATA_DIR = data

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
BIN_FILE = $(BIN_DIR)/play

all: $(BIN_FILE)

$(BIN_FILE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_FILE)

.PHONY: all clean