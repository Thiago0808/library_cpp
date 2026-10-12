#include "../include/library.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>
#include <cstdlib>

// ============================================================
// UTILITY FUNCTIONS
// Demonstrates: functions, pointer parameters, references,
//               recursion, loops, conditionals
// ============================================================

void showMenu() {
    std::cout << "\n╔══════════════════════════════════╗\n";
    std::cout << "║        C++ LIBRARY SYSTEM        ║\n";
    std::cout << "╠══════════════════════════════════╣\n";
    std::cout << "║  1. Add Book                     ║\n";
    std::cout << "║  2. Register Member              ║\n";
    std::cout << "║  3. Lend Book                    ║\n";
    std::cout << "║  4. Return Book                  ║\n";
    std::cout << "║  5. List All Books               ║\n";
    std::cout << "║  6. List Available Books         ║\n";
    std::cout << "║  7. List Members                 ║\n";
    std::cout << "║  8. Factorial (recursion)        ║\n";
    std::cout << "║  9. Demo: Pointers & Refs        ║\n";
    std::cout << "║  0. Exit                         ║\n";
    std::cout << "╚══════════════════════════════════╝\n";
    std::cout << "Option: ";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Confirmation using the ternary operator
bool confirmAction(const std::string& message) {
    std::cout << message << " (y/n): ";
    char answer;
    std::cin >> answer;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Ternary operator
    return (answer == 'y' || answer == 'Y') ? true : false;
}

// Validated input with a while loop + if-else
int readValidOption(int min, int max) {
    int option;
    while (true) {
        std::cin >> option;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number between "
                      << min << " and " << max << ": ";
        } else if (option < min || option > max) {
            std::cout << "Option out of range ["
                      << min << "-" << max << "]. Try again: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return option;
        }
    }
}

std::string readNonEmptyString(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Input cannot be empty!\n";
        }
    } while (input.empty());  // do-while loop
    return input;
}

// ============================================================
// FUNCTION WITH A POINTER PARAMETER
// Modifies the original value through its memory address
// ============================================================
void incrementCounter(int* counter) {
    if (counter != nullptr) {   // null pointer check
        (*counter)++;           // dereference and increment
    }
}

// ============================================================
// FUNCTION WITH A REFERENCE PARAMETER
// An alias for the original variable — no copy is made
// ============================================================
void formatTitle(std::string& text) {
    // Capitalizes the first letter of each word
    bool newWord = true;
    for (char& c : text) {     // reference to each char
        if (std::isspace(static_cast<unsigned char>(c))) {
            newWord = true;
        } else if (newWord) {
            c = std::toupper(static_cast<unsigned char>(c));
            newWord = false;
        } else {
            c = std::tolower(static_cast<unsigned char>(c));
        }
    }
}

// ============================================================
// RECURSIVE FUNCTION
// factorial(n) = n * factorial(n-1); base case: n <= 1
// ============================================================
int factorial(int n) {
    if (n <= 1) return 1;        // base case (simple if)
    return n * factorial(n - 1); // recursive call
}
