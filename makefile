# Compiler
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -O2

# Source and target
SRC = main.cpp
TARGET = ht

# Libraries
LIBS = -lftxui-component -lftxui-dom -lftxui-screen

# Default build
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Run the program after building
run: $(TARGET)
	./$(TARGET)

# Clean the build
clean:
	rm -f $(TARGET)

.PHONY: all clean run
