#include "ftxui/component/component.hpp"          // for Menu
#include "ftxui/component/component_options.hpp"  // for MenuOption
#include "ftxui/component/screen_interactive.hpp" // for ScreenInteractive
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <print>
#include <string>
#include <vector>

// NOTE: The if statements do nothing but just make code easier for me to read
void check_file_exists(const std::string &file_path) {
  if (std::filesystem::exists(file_path)) {
  } else {
    std::print("File: {} does not exists! \n", file_path);
    std::ofstream new_file(file_path);
    if (!new_file) {
      std::print("Failed to create file! \n");
      std::exit(1);
    } else {
      std::print("File: {} created successfully! \n", file_path);
    }
  }
}

// NOTE: The if statements do nothing but just make code easier for me to read
void check_dir_exists(const std::string &dir, const std::string &file_path) {
  if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir)) {
  } else {
    std::print("Directory {} doesn't exist \n", dir);
    std::filesystem::create_directory(dir);
    std::print("Directory created! \n");
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
    case 0: {
      system("clear");
      // TODO: READ HABIT
      bool is_empty = true;
      std::string file_contents;
      std::ifstream file_to_read(habit_file_path);
      while (getline(file_to_read, file_contents)) {
        std::print("{} \n", file_contents);
        is_empty = false;
      }
      file_to_read.close();
      if (is_empty){
        std::print("File is empty! \n");
      }
    } break;
    case 1: {
      std::print("Editing habit... \n");
      // TODO: Edit HABIT
    } break;
    case 2:
      std::print("Exiting... \n");
      // Quits
      exit(0);
  }

  // TODO: Ask options if the user wants to modify their habit / routine list.
  // TODO: Make way for file to be read by the program to print out habit
  // list/order
  return 0;
}
