#include "ftxui/component/component.hpp"          // for Menu
#include "ftxui/component/component_options.hpp"  // for MenuOption
#include "ftxui/component/screen_interactive.hpp" // for ScreenInteractive
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// NOTE: The if statements do nothing but just make code easier for me to read
void check_file_exists(const std::string &file_path) {
  if (std::filesystem::exists(file_path)) {
  } else {
    std::cout << "File: " << file_path << " does not exists!" << std::endl;
    std::ofstream new_file(file_path);
    if (!new_file) {
      std::cout << "Failed to create file!" << std::endl;
      std::exit(1);
    } else {
      std::cout << "File: " << file_path << " created successfully!"
                << std::endl;
    }
  }
}

// NOTE: The if statements do nothing but just make code easier for me to read
void check_dir_exists(const std::string &dir, const std::string &file_path) {
  if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir)) {
  } else {
    std::cout << "Directory " << dir << " doesn't exist" << std::endl;
    std::filesystem::create_directory(dir);
    std::cout << "Directory created!" << std::endl;
    check_file_exists(file_path);
  }
}

int main() {
  using namespace ftxui;
  system("clear");
  const char *user = std::getenv("USER");
  if (!user) {
    std::cerr << "USER environment variable not set!\n";
    return 1;
  }
  std::string habit_dir_path = std::string("/home/") + user + "/.config/ht";
  std::string habit_file_path = habit_dir_path + "/habits.txt";

  check_dir_exists(habit_dir_path, habit_file_path);
  check_file_exists(habit_file_path);

  // NOTE: start of code for tui interface
  std::vector<std::string> entries = {"Read Habits", "Edit Habits", "Quit"};
  int selected = 0;
  auto screen = ScreenInteractive::TerminalOutput();
  MenuOption option;
  option.on_enter = screen.ExitLoopClosure();
  auto menu = Menu(&entries, &selected, option);
  screen.Loop(menu);

  switch (selected) {
  case 0:
    std::cout << "Reading habit..." << std::endl;
    // TODO: READ HABIT
    break;
  case 1:
    std::cout << "Editing habit..." << std::endl;
    // TODO: Edit HABIT
    break;
  case 2:
    std::cout << "Exiting..." << std::endl;
    // Quits
    exit(0);
  }

  // TODO: Ask options if the user wants to modify their habit / routine list.
  // TODO: Make way for file to be read by the program to print out habit
  // list/order
  return 0;
}
