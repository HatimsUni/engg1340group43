FLAGS = -pedantic-errors -std=c++11
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/play
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(OBJ_DIR) $(BIN_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(wildcard $(SRC_DIR)/*.h)
	g++ $(FLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	g++ $(FLAGS) $^ -o $(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)