# 🦶 MyHunter - Feet Hunter

![SFML Game](https://img.shields.io/badge/SFML-Game-brightgreen)
![Language](https://img.shields.io/badge/Language-C-blue)

A quirky twist on the classic Duck Hunt game, where you hunt feet instead of ducks! This project was developed as part of the Epitech B-MUL-100 module.

![Game Screenshot](https://i.imgur.com/mrr36I3.png)

## 🎮 Game Overview

In Feet Hunter, your mission is to shoot the feet before they reach the other side of the screen. The game features:

- Moving animated feet sprites
- Point system based on successful hits
- Health system (you lose if feet reach the other side 5 times)
- Two types of bonuses:
  - Small bonuses: +10 points
  - Big bonuses: Reset lives to 5
- Custom cursor and sound effects for an immersive experience

## 🔧 Controls

- **Left Click**: Shoot
- **TAB**: Pause the game
- **ESC**: Exit the game

## 🛠️ Technical Features

- Sprite animations using sprite sheets
- Event-based interaction
- Score tracking and display
- Health system with visual health bar
- Custom cursor
- Dynamic difficulty that increases with progress
- Sound effects and background music
- Random bonus spawn system

## 📋 Requirements

- CSFML library
- GCC compiler
- Make

## 🚀 Installation

1. Clone the repository:
```bash
git clone https://github.com/9nickss/my_hunter.git
cd myhunter
```

2. Compile the game:
```bash
make
```

3. Run the game:
```bash
./my_hunter
```

4. Alternatively, view the help:
```bash
./my_hunter -h
```

## 📁 Project Structure

- `include/` - Header files
- `src/` - Source files
- `Images/` - Game assets (sprites, backgrounds)
- `Music/` - Sound effects and music
- `fonts/` - Font files

## 🧩 Code Architecture

The game is architected around several key components:

- **Game Loop**: Manages the main execution flow
- **Event Handling**: Processes user input
- **Rendering**: Displays sprites and UI elements
- **Animation**: Controls sprite animations
- **Sound Management**: Handles audio playback
- **Asset Management**: Loads and manages game resources

## 👥 Credits

- Developed by: Yannick Kahl
- Project for: Epitech Nice
- SFML Library: [CSFML](https://www.sfml-dev.org/download/csfml/)

---

*Note: This game contains sound elements. For the best experience, please enable your audio.*