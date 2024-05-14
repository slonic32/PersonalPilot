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
SRCS := $(SRC_DIR)/main.cpp $(LIB_DIR)/Task.cpp $(LIB_DIR)/Timeline.cpp \
		$(LIB_DIR)/ReportGenerator.cpp $(LIB_DIR)/FakeStorageAPI.cpp \
		$(LIB_DIR)/CLI.cpp $(LIB_DIR)/Date.cpp $(LIB_DIR)/StorageAPI.cpp

# Object files
OBJS := $(BUILD_DIR)/main.o $(BUILD_DIR)/Task.o $(BUILD_DIR)/Timeline.o \
		$(BUILD_DIR)/ReportGenerator.o $(BUILD_DIR)/FakeStorageAPI.o \
		$(BUILD_DIR)/CLI.o $(BUILD_DIR)/Date.o $(BUILD_DIR)/StorageAPI.o

# Executable name
EXEC := $(BIN_DIR)/personalpilot

.PHONY: clean

all: $(EXEC)

$(EXEC): $(BIN_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJS): $(BUILD_DIR) $(SRCS)
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/main.o $(SRC_DIR)/main.cpp 
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/Date.o $(LIB_DIR)/Date.cpp 
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/Task.o $(LIB_DIR)/Task.cpp 
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/Timeline.o $(LIB_DIR)/Timeline.cpp 
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/ReportGenerator.o $(LIB_DIR)/ReportGenerator.cpp 
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/FakeStorageAPI.o $(LIB_DIR)/FakeStorageAPI.cpp 
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/StorageAPI.o $(LIB_DIR)/StorageAPI.cpp 
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/CLI.o $(LIB_DIR)/CLI.cpp 

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
