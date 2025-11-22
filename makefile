# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Source and target
SRC = main.cpp
TARGET = ht

# Default build
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Run the program after building
run: $(TARGET)
	./$(TARGET)

# Clean the build
clean:
	rm -f $(TARGET)

.PHONY: all clean run
