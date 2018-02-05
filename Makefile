# Target
TARGET = byol

# Commands
CC = gcc
MKDIR_P = mkdir -pv
VAPORIZE = rm -rfv

# Directories
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build

# Compiler flags and linked libs
LIBS = -lm
CFLAGS = -Wall -std=c99

# Object files
_OBJ = main.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

all: $(TARGET)

run: $(TARGET)
	$(BUILD_DIR)/$(TARGET)

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# Build executable target
$(TARGET): $(OBJ)
	$(MKDIR_P) $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

# Delete build and obj directories
clean:
	$(VAPORIZE) $(OBJ_DIR) $(BUILD_DIR)
