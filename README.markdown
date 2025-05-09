# Rectangle Class Program

## Overview
This C++ program defines a `Rectangle` class to manage rectangle properties: side lengths (`sideA`, `sideB`), color (`color`), and area (`area`). It includes default and overloaded constructors, a `show` method to display details, and a private `calculateArea` method. The program creates an array of four rectangles with varying attributes and prints their properties.

## Features
- **Rectangle Class**:
  - Private attributes: `sideA`, `sideB` (side lengths), `color` (rectangle color), `area` (surface area).
  - Constructors: Default, with sides and color, and with sides only (default yellow color).
  - `show` method: Displays side lengths, color, and area in English.
  - Private `calculateArea` method: Computes area as `sideA * sideB` (cast to float).
- **Main Program**:
  - Creates an array of four `Rectangle` objects.
  - Initializes objects with different constructors: default, sides with color (blue, green), and sides only (yellow).
  - Iterates through the array to display each rectangle’s details using `show`.

## Requirements
- C++ compiler (e.g., g++, clang++)
- Standard C++ libraries: `<iostream>`, `<string>`
- Operating system: Any supporting a C++ compiler (e.g., Windows, Linux, macOS)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Save the provided code as `rectangle.cpp`.
3. Compile the program:
   ```bash
   g++ rectangle.cpp -o rectangle
   ```
4. Run the program:
   ```bash
   ./rectangle
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Output**:
   - Displays details for four rectangles:
     - Rectangle #1: Default (0x0, black, area 0).
     - Rectangle #2: 5x7, blue, area 35.
     - Rectangle #3: 3x10, green, area 30.
     - Rectangle #4: 8x8, yellow, area 64.
3. **Actions**:
   - Observe the console output for rectangle properties.
   - Modify constructor parameters in `main` to test different rectangle configurations.

## File Structure
- `rectangle.cpp`: Main C++ source file with `Rectangle` class and program logic.
- `README.md`: This file, providing project documentation.

## Notes
- Output uses English text (e.g., "Side lengths", "Color") for clarity.
- Area is calculated as `sideA * sideB` and cast to float for precision.
- No locale settings; uses standard ASCII colors (e.g., "blue", "yellow").
- Extend the class by adding methods (e.g., setters, perimeter calculation) for more functionality.
- No external dependencies; uses only standard C++ libraries.
- Test with different side lengths and colors by editing the array initialization in `main`.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.