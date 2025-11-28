# Makefile for building project with CMake

# Build directory
BUILD_DIR = build

# Target executable name
TARGET = habit-tracker

# --- Default: build the project ---
all:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && cmake --build .

# --- Run the program ---
run: all
	./$(BUILD_DIR)/$(TARGET)

# --- Clean the build directory ---
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
