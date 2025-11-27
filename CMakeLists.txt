cmake_minimum_required(VERSION 3.16)

# Project info
project(
  habit-tracker
  VERSION 1.1.0
  LANGUAGES CXX)

# Use C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add FTXUI as a subdirectory (replace with your path if different)
add_subdirectory(deps/ftxui EXCLUDE_FROM_ALL)

# Generate version.hpp from version.hpp.in
configure_file("${CMAKE_SOURCE_DIR}/version.hpp.in"
               "${CMAKE_BINARY_DIR}/version.hpp" @ONLY)

# Include the generated header
include_directories("${CMAKE_BINARY_DIR}")

# Add your executable
add_executable(
  habit-tracker src/main.cpp # add other source files here if you have them
)

# Link FTXUI
target_link_libraries(habit-tracker PRIVATE ftxui::screen ftxui::dom
                                            ftxui::component)
