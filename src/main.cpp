/*
  Habit / Routine Tracker app
  Started by Oxidized Toast Nov, 21, 2025

*/
#include "../include/version.hpp"
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
    std::ofstream new_file(file_path);
    if (!new_file) {
      std::print("Failed to create config/habit file! \n");
      std::exit(1);
    }
  }
}

// NOTE: The if statements do nothing but just make code easier for me to read
void check_dir_exists(const std::string &dir, const std::string &file_path) {
  if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir)) {
  } else {
    std::filesystem::create_directory(dir);
    check_file_exists(file_path);
  }
}

std::string help_text() {
  return "Usage: ht [flag]\n"
         "Options:\n"
         "--help     -h  Show this help screen\n"
         "--version  -v  Show version number\n";
}

void edit_habit(std::string file_path) {
  using namespace ftxui;

  // Load entire file into string
  std::ifstream in(file_path);
  std::string file_text((std::istreambuf_iterator<char>(in)),
                        std::istreambuf_iterator<char>());

  auto input_text = Input(&file_text, "Habits: ");
  ScreenInteractive screen = ScreenInteractive::TerminalOutput();

  auto save_button = Button(" Save & Exit ", [&] { screen.Exit(); });

  auto container = Container::Vertical({input_text, save_button});

  auto renderer = Renderer(container, [&] {
    return vbox({
               hbox(text(" Habits: "), input_text->Render()),
               save_button->Render(),
           }) |
           border;
  });

  screen.Loop(renderer);

  // Save edited content back to file
  std::ofstream(file_path) << file_text;
}

int main(int argc, char *argv[]) {
  // Code to check if arguments passed
  if (argc > 1) {
    std::string arg = argv[1];
    if (arg == "--help" || arg == "-h") {
      std::print("{}", help_text());
      return 0;
    }
    if (arg == "--version" || arg == "-v") {
      std::print("Version: {}\n", PROJECT_VERSION);
      return 0;
    } else {
      std::print("Option: {} not recognized\n", arg);
    }
  }
  // TUI App Code
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
    // NOTE: READ HABIT
    bool is_empty = true;
    std::string file_contents;
    std::ifstream file_to_read(habit_file_path);
    while (getline(file_to_read, file_contents)) {
      std::print("{} \n", file_contents);
      is_empty = false;
    }
    file_to_read.close();
    if (is_empty) {
      std::print("File is empty! \n");
    }
  } break;
  case 1: {
    edit_habit(habit_file_path);
  } break;
  case 2:
    std::print("Exiting... \n");
    // Quits
    exit(0);
  }
  return 0;
}
