# 📏🎨 **Shape Drawer ASCII Console**: Modern C++ OOP Demo 🖼️  

<img alt="License: MIT" src="https://img.shields.io/badge/License-MIT-yellow.svg">
<img alt="C++" src="https://img.shields.io/badge/Language-C++-blue.svg">
<img alt="Platform: Cross-platform" src="https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg">

## 📋 Table of Contents
1. [Overview](#-overview)  
2. [Key Features](#-key-features)  
3. [Demo Screens](#-screenshots)  
4. [System Requirements](#️-system-requirements)  
5. [Installation & Setup](#-installation-and-setup)  
6. [Usage Guide](#-usage-guide)  
7. [File Structure](#-file-structure)  
8. [Technical Notes](#-technical-notes)  
9. [Contributing](#-contributing)  
10. [License](#-license)  
11. [Contact](#-contact)  

---

## 📄 Overview
**Shape Drawer**, created by **Adrian Leśniak**, is a cross-platform C++ console application that demonstrates object-oriented design, RAII, the Factory pattern and ANSI-colour terminal output.  
The program lets you draw colourful ASCII **circles**, **squares** and **triangles**, review the current session, and save / load shape lists from a text file.  
Every operation is time-stamped in an `app.log` file.

![Demo GIF](screenshots/1.gif)

---

## ✨ Key Features
| Category | Details |
|----------|---------|
| 🎨 **ASCII Art** | Clearly aligned shapes with bright ANSI colours (works on Windows 10+ & POSIX). |
| 🏗️ **OOP Design** | Abstract base class `Shape`, concrete subclasses `Circle`, `Square`, `Triangle`, and a factory helper. |
| 💾 **Persistence** | Save / load shape sequences to `shapes.txt`. |
| 📝 **Logging** | `Logger` writes time-stamped events to `app.log`. |
| ⚙️ **Exception Safety** | Robust try/catch around I/O and menu actions. |
| 🌐 **Cross-platform** | Builds with GCC/Clang/MSVC; enables virtual-terminal colours on Windows automatically. |

---

## 🖼️ Screenshots

**Example Console Output:**
<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
  <img src="screenshots\7.jpg" width="300"/>
  <img src="screenshots\8.jpg" width="300"/>
</p>

> *Conceptual rendering* — real console colours depend on your terminal.

```


========================================================
 *  Adrian Lesniak  Shape Drawer ASCII Console  *
========================================================
 Draw colourful ASCII shapes, store them, load them, 
 and enjoy a simple, cross-platform CLI demo.        

******************* MENU *******************
 1  Draw a new figure
 2  Show figures drawn in this session
 3  Save figures to file
 4  Load figures from file
 5  Exit
*********************************************
Choose an option > 1

Choose figure (1-Circle, 2-Square, 3-Triangle): 2
  ________
 |        |
 |        |
 |        |
 |________|

Press <Enter> to return to menu...
```

**Example: Drawing a triangle**
```
      /\
     /  \
    /____\
```

**Example: No shapes yet**
```
No shapes yet.
```

---

## ⚙️ System Requirements
| Component | Minimum |
|-----------|---------|
| OS | Windows 10+, Linux, macOS |
| Compiler | C++11-enabled (GCC, Clang, MSVC) |
| Libraries | Standard C++ only (no external deps) |

---

## 🛠️ Installation and Setup
```bash
# Clone repository
git clone <repository-url>
cd <repository-directory>

# Build (GCC/Clang)
g++ -std=c++11 -O2 -o shape_drawer main.cpp
#   Windows + MinGW: add -static-libgcc -static-libstdc++

# Run
./shape_drawer        # Linux/macOS
shape_drawer.exe      # Windows
```

---

## 💡 Usage Guide

1. Run the executable.
2. Use the menu to:
   - Draw a new figure (circle, square, triangle)
   - Show all figures drawn in this session
   - Save figures to `shapes.txt`
   - Load figures from `shapes.txt`
   - Exit with option 5
3. Press Enter after each action to return to the menu.
4. All actions are logged to `app.log`.

---

## 🗂️ File Structure

```
├─ main.cpp                # Main source (this repo)
├─ README.md               # You are here
├─ app.log                 # Generated at runtime
├─ shapes.txt              # Optional save-file
└─ screenshots/            # Demo images (optional)
```

---

## 📝 Technical Notes

- **Colours** – Bright ANSI sequences (\033[9xm]) avoid dark text on dark backgrounds.
- **Windows Support** – ENABLE_VIRTUAL_TERMINAL_PROCESSING flag is set at runtime; a fallback macro is defined for older MinGW headers.
- **Memory Management** – All Shape objects are handled via std::unique_ptr, ensuring automatic cleanup.
- **Pattern Usage** – Factory Method creates shapes from simple menu keys.
- **Extensibility** – Add new shapes by inheriting from Shape and extending the factory.

---

## 🤝 Contributing

1. Fork the repo.
2. Create a feature branch  
   `git checkout -b feature/NewShape`
3. Commit your changes with clear messages.
4. Push and open a Pull Request.

Please follow modern C++ best practices and keep code well-commented.

---

## 📃 License

Licensed under the MIT License — see LICENSE for details.

---

## 📧 Contact

Created with ❤️ by Adrian Leśniak.  
For questions or feedback, open an issue or reach out via the repository page.

---

🖼️ Bringing geometry to life in vibrant ASCII!




