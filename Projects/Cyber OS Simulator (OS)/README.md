# 🖥️ Project : Cyber OS Simulator

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![OS](https://img.shields.io/badge/Platform-Linux-lightgrey.svg)

> A command-line based **Operating System simulator** in C++ built as an academic project to demonstrate OS-level concepts like process management, memory handling, and multitasking. CyberOS also comes with a set of interactive mini-apps including games, tools, and utilities — all inside a simulated terminal UI.

## 🤝🏼 Collaborators

- 👨‍💻 [Shawaiz Shahid](https://github.com/MadG0blin359)
- 👨‍💻 [Waleed Afzal](https://github.com/beastwaleed)

## ✍🏼 Contributions

Each collaborator has actively contributed to the development of the project, bringing their unique skills and perspectives to enhance its functionality.
This project is developed and maintained by:

- **Shawaiz Shahid**
- **Waleed Afzal**

## 🌟 Features

### Core OS Simulation
- Process scheduling (FCFS/Round Robin)
- Memory management (RAM/HD allocation)
- File system operations
- Multi-threading and synchronization
- Terminal-based UI with system monitoring

### Mini Applications
- 📝 Notepad
- 🔄 Processes Manager
- 🎮 Snake Game
- 🎵 Music Player (ASCII visualization)
- 🖼️ ASCII Art Gallery
- ⏱️ Digital Clock
- 📅 Calendar
- 🔍 File Explorer
- 📁 File Copier
- 🎲 Fortune Teller
- ⏳ Stopwatch
- 🧩 Maze Game
- 📊 Resource Monitor
- ⭕ Tic-Tac-Toe Game
- 🔮 Fortune Teller
- 🐍 Classic Snake Game

### Key Features

#### 🛠️ System Utilities
- `monitor.cpp` 📊 - Resource monitor
- `process.cpp` 🔄 - Processes manager  
- `copier.cpp` 📁 - File copier

#### 📚 Productivity Apps
- `notepad.cpp` 📝 - Text editor
- `calculator.cpp` ➗ - Calculator app  
- `calendar.cpp` 📅 - Interactive calendar
- `clock.cpp` ⏰ - Digital clock
- `explorer.cpp` 📂 - File browser

#### 🎮 Games & Entertainment
- `snake.cpp` 🐍 - Classic snake game
- `maze.cpp` 🧩 - Maze game  
- `tictactoe.cpp` ❌⭕ - Tic-Tac-Toe game
- `fortune.cpp` 🔮 - Fortune teller
- `gallery.cpp` 🖼️ - ASCII art display
- `music.cpp` 🎵 - Music player simulator

#### ⚙️ Core Utilities  
- `stopwatch.cpp` ⏱️ - Timer application

## 🛠️ Project Structure
```
CyberOS/
├── main.cpp
└── tasks/
    ├── notepad.cpp
    ├── snake.cpp
    ├── music.cpp
    ├── gallery.cpp
    ├── clock.cpp
    ├── calendar.cpp
    ├── explorer.cpp
    ├── fortune.cpp
    ├── stopwatch.cpp
    ├── maze.cpp
    ├── monitor.cpp
    ├── process.cpp
    ├── copier.cpp
    ├── calculator.cpp
    ├── tictactoe.cpp
    ├── shutdown.cpp
    └── autosave.cpp
```

## 💻 Installation & Usage

### Prerequisites
- Linux OS
- GCC/G++ compiler
- GNU Make
- POSIX threads library

### Steps to Run

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/MadG0blin359/CPP-CodeGlitch

2. **Navigate to the Project Directory:**

   ```bash
   cd CPP-CodeGlitch/Projects/'Cyber OS Simulator (OS)'

3. **Compile the C++ Code:**

   ```bash
   g++ main.cpp -o main

4. **Run the Executable:**

   ```bash
   ./main <RAM> <HDD> <CORES>

## 📧 Contact

For any inquiries or collaboration opportunities, please contact:

- shawaizshahid312+github@gmail.com
- waleedafzalshaikh+github@gmail.com
