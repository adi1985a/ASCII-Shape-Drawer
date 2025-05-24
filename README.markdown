# 📏🎨 RectangleClass Demo: C++ Object-Oriented Design 🖼️
_A C++ console program demonstrating a `Rectangle` class with multiple constructors, property management (sides, color, area), and a display method._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features of the `Rectangle` Class](#-key-features-of-the-rectangle-class)
3.  [Screenshots (Conceptual Output)](#-screenshots-conceptual-output)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Setup](#️-installation-and-setup)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure](#-file-structure)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

The **RectangleClass Demo**, developed by Adrian Lesniak, is a C++ console application designed to illustrate fundamental object-oriented programming (OOP) concepts through the implementation of a `Rectangle` class. This class manages properties of a rectangle, including its side lengths (`sideA`, `sideB`), its `color` (as a string), and its calculated `area`. The program showcases the use of default and overloaded constructors for flexible object initialization. A `show()` method is provided to display the rectangle's details. The `main` function demonstrates the creation of an array of `Rectangle` objects, initialized using different constructors, and then iterates through them to display their properties.

## ✨ Key Features of the `Rectangle` Class

*   📦 **Attributes (Private)**:
    *   `sideA`, `sideB`: Integer values representing the lengths of the rectangle's sides.
    *   `color`: A `std::string` storing the color of the rectangle (e.g., "black", "blue", "yellow").
    *   `area`: A `float` storing the calculated surface area of the rectangle.
*   🛠️ **Constructors**:
    *   **Default Constructor**: Initializes a rectangle with default values (e.g., sides 0, color "black", area 0).
    *   **Overloaded Constructor (Sides and Color)**: Initializes a rectangle with specified side lengths and color. Calculates area internally.
    *   **Overloaded Constructor (Sides Only)**: Initializes a rectangle with specified side lengths and a default color (e.g., "yellow"). Calculates area internally.
*   📊 **Methods**:
    *   `show()`: A public method that prints the rectangle's side lengths, color, and calculated area to the console in a formatted way (using English text).
    *   `calculateArea()`: A private helper method that computes the area (`sideA * sideB`, cast to `float`) and stores it in the `area` attribute. This is typically called by the constructors.
*   👨‍💻 **Demonstration in `main()`**:
    *   Creates a fixed-size array (e.g., of four `Rectangle` objects).
    *   Initializes these objects using the various constructors to demonstrate their usage and flexibility.
    *   Iterates through the array, calling the `show()` method for each `Rectangle` object to display its properties.

## 🖼️ Screenshots (Conceptual Output)

The program produces direct console output based on the `show()` method.

**Example Console Output:**
*--- Rectangle #1 ---
Side lengths: 0 x 0
Color: black
Area: 0.00
--- Rectangle #2 ---
Side lengths: 5 x 7
Color: blue
Area: 35.00
--- Rectangle #3 ---
Side lengths: 3 x 10
Color: green
Area: 30.00
--- Rectangle #4 ---
Side lengths: 8 x 8
Color: yellow
Area: 64.00*

*(The exact formatting and English phrases will depend on the `show()` method's implementation.)*

## ⚙️ System Requirements

*   **Operating System**: Any OS supporting a standard C++ compiler (e.g., Windows, Linux, macOS).
*   **C++ Compiler**: A C++ compiler (e.g., g++, clang++, MSVC). C++11 or later is good practice.
*   **Standard C++ Libraries**: `<iostream>` (for console I/O), `<string>` (for color attribute), `<vector>` (if the array of rectangles were dynamic, though the example implies a fixed-size C-style array or `std::array`).

## 🛠️ Installation and Setup

1.  **Clone the Repository (if applicable)**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    *(Replace `<repository-url>` and `<repository-directory>` if this code is part of a larger repository).*

2.  **Save Main Code**:
    Ensure your C++ source code (containing the `Rectangle` class definition and implementation, and the `main` function) is saved as `rectangle.cpp` (or your chosen file name) in your project directory.

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, Bash, etc.) in the project directory.
    **Example using g++:**
    ```bash
    g++ rectangle.cpp -o rectangle -std=c++11
    ```
    *(Add `-static-libgcc -static-libstdc++` on Windows with MinGW if desired for standalone executables. Add optimization flags like `-O2` for release builds if needed).*

4.  **Run the Program**:
    *   On Windows: `.\rectangle.exe` or `rectangle.exe`
    *   On Linux/macOS: `./rectangle` (ensure execute permissions: `chmod +x rectangle`)

## 💡 Usage Guide

1.  Compile `rectangle.cpp` as detailed in the "Installation and Setup" section.
2.  Run the compiled executable (`rectangle` or `rectangle.exe`).
3.  **Output**:
    *   The program will directly print the details for each of the four `Rectangle` objects created and initialized in the `main` function. This includes their side lengths, color, and calculated area.
4.  **Actions**:
    *   Observe the console output to verify the properties of each rectangle, confirming that the different constructors work as expected.
    *   The program runs a fixed sequence (creating and displaying rectangles) and then terminates. There are no interactive prompts for the user.
    *   To experiment, you can modify the parameters used when initializing the `Rectangle` objects in the `main` function's array and recompile.

## 🗂️ File Structure

*   `rectangle.cpp`: The main (and likely only) C++ source file containing the `Rectangle` class definition and implementation, and the `main()` demonstration function.
*   `README.md`: This documentation file.

*(No external data files, log files, or user-provided header files are indicated for this specific program as described.)*

## 📝 Technical Notes

*   **Encapsulation**: The `Rectangle` class demonstrates encapsulation by keeping its attributes (`sideA`, `sideB`, `color`, `area`) private and providing public methods (constructors, `show()`) to interact with and display object data. The `calculateArea()` method is private as it's an internal utility.
*   **Constructors**: The use of a default constructor and multiple overloaded constructors allows for flexible object creation.
*   **Area Calculation**: The area is calculated as `sideA * sideB`. The description notes it's cast to `float` for precision, which is good practice if `sideA` and `sideB` are integers but a floating-point area is desired.
*   **Output Language**: The program uses English text (e.g., "Side lengths", "Color", "Area") in its `show()` method for clarity.
*   **No Locale Settings**: Standard ASCII characters are used for colors (e.g., "blue", "yellow", "black", "green" as strings), so no special locale settings are required for text display.
*   **Fixed Demonstration**: The `main` function demonstrates a fixed set of rectangle creations. There is no user input to define rectangles at runtime.
*   **Potential Enhancements**:
    *   Adding setter methods (mutators) to modify rectangle properties after creation.
    *   Implementing a `getPerimeter()` method.
    *   Adding input validation if user-defined rectangles were to be implemented.
    *   Using `const` correctness for methods like `show()` and potentially getters.

## 🤝 Contributing

Contributions to this **RectangleClass Demo** are welcome, especially if they aim to:

*   Add more methods to the `Rectangle` class (e.g., `getPerimeter()`, `isSquare()`).
*   Implement comparison operators (e.g., to compare areas of rectangles).
*   Introduce user input for creating rectangles dynamically.
*   Showcase inheritance by creating specialized rectangle types.

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/RectangleEnhancements`).
3.  Make your changes and commit them (`git commit -m 'Feature: Add perimeter calculation'`).
4.  Push to the branch (`git push origin feature/RectangleEnhancements`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ OOP practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues related to this OOP demonstration, please open an issue on the GitHub repository or contact the repository owner.

---
🖼️ _Illustrating C++ class design and object creation with simple rectangles!_
