cmake_minimum_required(VERSION 3.16)
project(ht LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Source files ---
file(GLOB_RECURSE SOURCES src/*.cpp)

# --- Executable ---
add_executable(ht ${SOURCES})

# --- Include your headers ---
target_include_directories(ht PRIVATE include)

# --- Try to find system FTXUI first ---
find_package(ftxui QUIET)

if(ftxui_FOUND)
  message(STATUS "Using system-installed FTXUI")
else()
  message(STATUS "System FTXUI not found, fetching FTXUI...")
  include(FetchContent)
  FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG v6.1.9)
  FetchContent_MakeAvailable(ftxui)
endif()

# --- Link FTXUI modules ---
target_link_libraries(ht PRIVATE ftxui::screen ftxui::dom ftxui::component)
