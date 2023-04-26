# Compiler options
CC = g++
CFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
DATA_DIR = data

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
BIN_FILE = $(BIN_DIR)/cardingo

# Targets
all: $(BIN_FILE)

$(BIN_FILE): | $(BIN_DIR) $(OBJ_DIR) $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Directory targets
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# PHONY targets
.PHONY: all clean