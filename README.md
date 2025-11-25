> ⚠️ This project is currently in **beta** / under active development. Features may change, and bugs may exist.

# Habit Tracker

A terminal-based **habit tracker and planner** written in **C++23** using [FTXUI](https://github.com/ArthurSonzogni/FTXUI). Track and manage your daily habits through an interactive terminal interface.

---
[![Habit Tracker CI](https://github.com/OxidizedToast/habit-tracker/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/OxidizedToast/habit-tracker/actions/workflows/c-cpp.yml)

## Features

* Add, edit, and remove habits
* Track completion of habits daily
* Interactive TUI (terminal user interface) powered by FTXUI
* Stores habits locally in `~/.config/ht/habits.txt`

---

## Installation

Clone the repository and build the project using the Makefile:

`git clone https://github.com/OxidizedToast/habit-tracker.git`
`cd habit-tracker`
`make`

> The Makefile is configured for **C++23** and links against FTXUI.

Run the program:

`./ht`

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

* [ ] Add, edit, and remove habits
* [ ] Track habits daily
* [ ] Display streaks and completion statistics
* [ ] Save/load habit history more efficiently
* [ ] Improve TUI navigation and usability
* [x] Add version display inside the app

---

## Requirements

* C++23 compiler (e.g., `g++`)
* [FTXUI](https://github.com/ArthurSonzogni/FTXUI)
* Make (for building)

---

## Versioning

Current version: `0.3.1` (Beta)

Follows [Semantic Versioning](https://semver.org/):

* **MAJOR**: breaking changes
* **MINOR**: new features
* **PATCH**: bug fixes

---

## Contributing

Contributions are welcome! You can:

* Submit issues for bugs or feature requests
* Fork the repository and create pull requests
* Suggest improvements or optimizations

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.
