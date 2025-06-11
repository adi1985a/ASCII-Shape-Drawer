// ============================================================================
//  Shape Drawer  ASCII Art Console Application (fixed)
//  Author: Adrian Lesniak
//  Description: Draws colourful ASCII shapes, stores them in a file, loads
//               them back, and logs every action. Compatible with Windows and
//               POSIX systems  builds cleanly even with older MinGW headers.
// ============================================================================
//  * Menu Options *
//    1  Draw a new figure  (circle ⭕ / square ◻ / triangle 🔺)
//    2  Show figures drawn in this session
//    3  Save figures to file (shapes.txt)
//    4  Load figures from file (shapes.txt)
//    5  Exit program
// ---------------------------------------------------------------------------
//  After every action press <Enter> to return to the menu.
// ============================================================================

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <exception>
#include <limits>

#ifdef _WIN32                          // ── Windows colour support
#  define NOMINMAX                     // avoid <windows.h> min/max macros
#  include <windows.h>
   // Some MinGW distributions miss this flag  define it manually if needed
#  ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#     define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#  endif
#endif

// -----------------------------------------------------------------------------
//  ANSI colour codes  bright variants (avoid dark colours)
// -----------------------------------------------------------------------------
#define CLR_RESET   "\033[0m"
#define CLR_CYAN    "\033[96m"
#define CLR_YELLOW  "\033[93m"
#define CLR_MAGENTA "\033[95m"
#define CLR_GREEN   "\033[92m"

// -----------------------------------------------------------------------------
//  Simple logger  writes time‑stamped events to app.log
// -----------------------------------------------------------------------------
class Logger {
    std::ofstream logFile;
public:
    explicit Logger(const std::string& fileName = "app.log") {
        logFile.open(fileName, std::ios::app);
        if (!logFile)
            std::cerr << "Cannot open log file!\n";
    }
    ~Logger() { if (logFile) logFile.close(); }

    template<typename T>
    void info(const T& msg) {
        if (!logFile) return;
        auto now = std::chrono::system_clock::to_time_t(
                       std::chrono::system_clock::now());
        std::tm tm {};
#ifdef _WIN32
        localtime_s(&tm, &now);
#else
        localtime_r(&now, &tm);
#endif
        logFile << std::put_time(&tm, "%F %T") << " | " << msg << '\n';
    }
};

Logger logger;   // global logger instance

// -----------------------------------------------------------------------------
//  Shape hierarchy  base and derived classes
// -----------------------------------------------------------------------------
class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw()       const = 0;
    virtual std::string name() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << CLR_CYAN
                  << "      _______  \n"
                     "   .-'       '-.\n"
                     "  /             \\\n"
                     " |               |\n"
                     " |      ___      |\n"
                     "  \\             /\n"
                     "   '-._______.-'\n"
                  << CLR_RESET;
    }
    std::string name() const override { return "Circle"; }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << CLR_YELLOW
                  << "  ________\n"
                     " |        |\n"
                     " |        |\n"
                     " |        |\n"
                     " |________|\n"
                  << CLR_RESET;
    }
    std::string name() const override { return "Square"; }
};

class Triangle : public Shape {
public:
    void draw() const override {
        std::cout << CLR_MAGENTA
                  << "      /\\\n"
                     "     /  \\\n"
                     "    /____\\\n"
                  << CLR_RESET;
    }
    std::string name() const override { return "Triangle"; }
};

// -----------------------------------------------------------------------------
//  Factory function  returns proper concrete shape
// -----------------------------------------------------------------------------
std::unique_ptr<Shape> makeShape(char choice) {
    switch (choice) {
        case '1': return std::make_unique<Circle>();
        case '2': return std::make_unique<Square>();
        case '3': return std::make_unique<Triangle>();
        default:  throw std::invalid_argument("Unknown shape choice");
    }
}

// -----------------------------------------------------------------------------
//  Enable ANSI colour sequences on Windows 10+ consoles
// -----------------------------------------------------------------------------
void enableColourOnWindows() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode)) return;

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
#endif
}

// -----------------------------------------------------------------------------
//  Persistence helpers  save / load vector<unique_ptr<Shape>>
// -----------------------------------------------------------------------------
void saveShapes(const std::vector<std::unique_ptr<Shape>>& shapes,
                const std::string& fileName = "shapes.txt") {
    std::ofstream out(fileName);
    if (!out) throw std::ios_base::failure("Cannot open file for writing");
    for (const auto& s : shapes) out << s->name() << '\n';
    logger.info("Saved " + std::to_string(shapes.size()) + " shapes to " + fileName);
}

std::vector<std::unique_ptr<Shape>> loadShapes(const std::string& fileName = "shapes.txt") {
    std::ifstream in(fileName);
    if (!in) throw std::ios_base::failure("Cannot open file for reading");

    std::vector<std::unique_ptr<Shape>> vec;
    std::string line;
    while (std::getline(in, line)) {
        char key = (line == "Circle")   ? '1'
                 : (line == "Square")   ? '2'
                 : (line == "Triangle") ? '3' : '0';
        if (key != '0') vec.emplace_back(makeShape(key));
    }
    logger.info("Loaded " + std::to_string(vec.size()) + " shapes from " + fileName);
    return vec;
}

// -----------------------------------------------------------------------------
//  ASCII header and menu
// -----------------------------------------------------------------------------
void printHeader() {
    std::cout << CLR_GREEN
              << "========================================================\n"
              << " *  Adrian Lesniak  Shape Drawer ASCII Console  *\n"
              << "========================================================\n"
              << " Draw colourful ASCII shapes, store them, load them, \n"
              << " and enjoy a simple, cross-platform CLI demo.        \n\n"
              << CLR_RESET;
}

void printMenu() {
    std::cout << CLR_YELLOW
              << "******************* MENU *******************\n"
              << " 1  Draw a new figure\n"
              << " 2  Show figures drawn in this session\n"
              << " 3  Save figures to file\n"
              << " 4  Load figures from file\n"
              << " 5  Exit\n"
              << "*********************************************\n"
              << CLR_RESET;
}

void waitForKey() {
    std::cout << "\nPress <Enter> to return to menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// -----------------------------------------------------------------------------
//  Clear screen – portable-ish (Windows + POSIX)
// -----------------------------------------------------------------------------
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

// -----------------------------------------------------------------------------
//  Main application loop
// -----------------------------------------------------------------------------
int main() {
    enableColourOnWindows();
    try {
        std::vector<std::unique_ptr<Shape>> shapes;
        char option{};
        do {
            clearScreen();
            printHeader();
            printMenu();
            std::cout << "Choose an option > ";
            std::cin >> option;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (option) {
                case '1': {
                    std::cout << "\nChoose figure (1-Circle, 2-Square, 3-Triangle): ";
                    char sel{};
                    std::cin >> sel;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    try {
                        auto sh = makeShape(sel);
                        sh->draw();
                        logger.info("Drew " + sh->name());
                        shapes.emplace_back(std::move(sh));
                    } catch (const std::exception& ex) {
                        std::cerr << "Error: " << ex.what() << '\n';
                        logger.info(std::string("Draw error: ") + ex.what());
                    }
                    waitForKey();
                    break;
                }
                case '2': {
                    std::cout << '\n';
                    if (shapes.empty()) {
                        std::cout << CLR_MAGENTA << "No shapes yet." << CLR_RESET << '\n';
                    } else {
                        for (const auto& s : shapes) {
                            s->draw();
                            std::cout << '\n';
                        }
                    }
                    waitForKey();
                    break;
                }
                case '3': {
                    try {
                        saveShapes(shapes);
                        std::cout << CLR_GREEN << "Saved successfully." << CLR_RESET << '\n';
                    } catch (const std::exception& ex) {
                        std::cerr << "Error: " << ex.what() << '\n';
                        logger.info(std::string("Save error: ") + ex.what());
                    }
                    waitForKey();
                    break;
                }
                case '4': {
                    try {
                        shapes = loadShapes();
                        std::cout << CLR_GREEN << "Loaded successfully." << CLR_RESET << '\n';
                    } catch (const std::exception& ex) {
                        std::cerr << "Error: " << ex.what() << '\n';
                        logger.info(std::string("Load error: ") + ex.what());
                    }
                    waitForKey();
                    break;
                }
                case '5':
                    std::cout << "\nExiting... Goodbye!\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
                    waitForKey();
            }
        } while (option != '5');
    }
    catch (const std::exception& ex) {
        std::cerr << "Fatal error: " << ex.what() << '\n';
        logger.info(std::string("Fatal: ") + ex.what());
    }
    return 0;
}
