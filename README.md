# Habit Tracker

A terminal-based **habit tracker and planner** written in **C++23** using [FTXUI](https://github.com/ArthurSonzogni/FTXUI). Track and manage your daily habits through an interactive terminal interface.

---
![Latest Release](https://img.shields.io/github/v/release/OxidizedToast/habit-tracker?label=version)
![Build Status](https://github.com/OxidizedToast/habit-tracker/actions/workflows/c-cpp.yml/badge.svg)
![License](https://img.shields.io/github/license/OxidizedToast/habit-tracker)
![Contributors](https://img.shields.io/github/contributors/OxidizedToast/habit-tracker)
![Last Commit](https://img.shields.io/github/last-commit/OxidizedToast/habit-tracker)
![Open Issues](https://img.shields.io/github/issues/OxidizedToast/habit-tracker)
![GitHub stars](https://img.shields.io/github/stars/OxidizedToast/habit-tracker?style=social)
![GitHub forks](https://img.shields.io/github/forks/OxidizedToast/habit-tracker?style=social)


## Features

* Add, edit, and remove habits
* Track completion of habits daily
* Interactive TUI (terminal user interface) powered by FTXUI
* Stores habits locally in `~/.config/ht/habits.txt`

---

## Installation

Clone the repository and build the project using the Makefile or Cmake:
### Makefile
> The Makefile is configured for **C++23** and runs the CMake file
`git clone https://github.com/OxidizedToast/habit-tracker.git` \
`cd habit-tracker` \
`make`
### Cmake
> CMake is configured for **C++23** 
`git clone https://github.com/OxidizedToast/habit-tracker.git` \
`mkdir build` \
`cd build` \
`cmake ..` \
`cmake --build .`

### [AUR](https://aur.archlinux.org/packages/habit-tracker)
> Although there is another habit-tracker named habit-tracker-bin, that is not my project so make sure to install correct program
`paru -Sy habit-tracker`

### Run the program:
`cd build` \
`./habit-tracker`

---

## Commands

```
Usage: ht [flag]\n"
    "Options:"
    "--help     -h  Show this help screen"
    "--version  -v  Show version number"
```

---

## Usage

* Use arrow keys to navigate the interface
* Press `Enter` to select options
* Stage new habits, mark habits as complete, or remove habits
* All data is saved locally so your progress persists between sessions

---

## Roadmap / TODO

* [x] Add, edit, and remove habits
* [ ] Track habits daily
* [ ] Display streaks and completion statistics
* [x] Save/load habit history more efficiently
* [x] Improve TUI navigation and usability
* [x] Add version display inside the app
* [x] Fix project file structure

---

## Requirements

* C++23 compiler (e.g., `g++`)
* [FTXUI](https://github.com/ArthurSonzogni/FTXUI) 
* Cmake (for building and managing dependencies)
* Make (only if using Makefile wrapper)

---

## Contributing

Contributions are welcome! You can:

* Submit issues for bugs or feature requests
* Fork the repository and create pull requests
* Suggest improvements or optimizations
