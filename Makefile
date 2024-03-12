# Compiler
CC := g++

# Compiler flags
CFLAGS := -std=c++11 -Wall

# Directories
SRC_DIR := src
LIB_DIR := $(SRC_DIR)/lib
BUILD_DIR := build
BIN_DIR := bin

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(LIB_DIR)/*.cpp)

# Object files
OBJS := $(SRCS:%.cpp=%.o)

# Executable name
EXEC := $(BIN_DIR)/main

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
