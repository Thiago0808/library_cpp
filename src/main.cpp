/*
 * ============================================================
 *  C++ LIBRARY SYSTEM
 *  Teaching project covering every topic in the course:
 *
 *  [x] Variables and data types
 *  [x] Input/output (cin/cout)
 *  [x] Arithmetic, relational and logical operators
 *  [x] if-else, ternary operator, switch-case
 *  [x] while, do-while, for
 *  [x] Functions (concepts and development)
 *  [x] Pointers (*) — concepts and practice
 *  [x] References (&) — concepts and practice
 *  [x] Arrays and Matrices
 *  [x] Pointer arithmetic
 *  [x] Classes, Objects, Attributes and Methods (OOP)
 *  [x] Stack vs Heap (new / delete)
 *  [x] .h vs .cpp — separating interface from implementation
 *  [x] The this pointer (implicit in methods)
 *  [x] Constructors and Destructors
 *  [x] Structs
 *  [x] Additional concepts (template, nullptr, const)
 * ============================================================
 */

#include <iostream>
#include <string>
#include <limits>
#include "../include/library.h"

// ============================================================
// STANDALONE DEMO: Pointers and References
// ============================================================
void demoPointersReferences() {
    std::cout << "\n======= DEMO: POINTERS AND REFERENCES =======\n\n";

    // --- Variables on the Stack ---
    int x = 10;
    int y = 20;

    std::cout << "Variables on the STACK:\n";
    std::cout << "  x = " << x << " | address of x: " << &x << "\n";
    std::cout << "  y = " << y << " | address of y: " << &y << "\n";

    // --- Pointer ---
    int* ptr = &x;  // ptr stores the ADDRESS of x
    std::cout << "\nPointer ptr points to x:\n";
    std::cout << "  ptr     = " << ptr   << "  (address stored in ptr)\n";
    std::cout << "  *ptr    = " << *ptr  << "  (value at *ptr, dereferenced)\n";

    *ptr = 99;  // changes x through the pointer
    std::cout << "  After *ptr = 99 -> x is: " << x << "\n";

    // --- Pointer Arithmetic with an Array ---
    std::cout << "\nPointer Arithmetic with an Array:\n";
    int grades[5] = {7, 8, 6, 9, 10};
    int* pGrades = grades;  // points to the first element

    std::cout << "  Grades: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *(pGrades + i) << " ";  // ptr + i moves i * sizeof(int) bytes
    }
    std::cout << "\n";

    // Pointer increment
    pGrades++;  // now points to grades[1]
    std::cout << "  After pGrades++: *pGrades = " << *pGrades << " (was grades[1])\n";
    pGrades--;  // move back

    // --- Reference ---
    int& refX = x;  // refX is an alias for x
    std::cout << "\nReference refX = x:\n";
    std::cout << "  refX = " << refX << "\n";
    refX = 42;
    std::cout << "  After refX = 42 -> x is: " << x << "\n";

    // --- Heap with new/delete ---
    std::cout << "\nAllocation on the HEAP with new/delete:\n";
    int* heapVal = new int(55);  // allocate on the heap
    std::cout << "  *heapVal = " << *heapVal
              << " | address on the heap: " << heapVal << "\n";
    delete heapVal;              // free memory
    heapVal = nullptr;           // good practice: null the pointer after delete
    std::cout << "  Memory freed. heapVal = nullptr\n";

    // --- Function with a pointer ---
    int counter = 0;
    std::cout << "\nFunction with a pointer (incrementCounter):\n";
    std::cout << "  Before: counter = " << counter << "\n";
    incrementCounter(&counter);
    incrementCounter(&counter);
    incrementCounter(&counter);
    std::cout << "  After 3 calls: counter = " << counter << "\n";

    // --- Function with a reference ---
    std::string title = "dom casmurro - machado de assis";
    std::cout << "\nFunction with a reference (formatTitle):\n";
    std::cout << "  Before: \"" << title << "\"\n";
    formatTitle(title);
    std::cout << "  After:  \"" << title << "\"\n";

    // --- Template ---
    std::cout << "\nTemplate maxValue<T>:\n";
    std::cout << "  maxValue(10, 25)    = " << maxValue(10, 25) << "\n";
    std::cout << "  maxValue(3.14, 2.7) = " << maxValue(3.14, 2.7) << "\n";
    std::cout << "  maxValue('a', 'z')  = " << maxValue('a', 'z') << "\n";

    std::cout << "\n=============================================\n";
}

// ============================================================
// DEMO: Matrix (2D Arrays)
// ============================================================
void demoMatrix() {
    std::cout << "\n======= DEMO: MATRIX (2D ARRAY) =======\n\n";

    const int ROWS = 3;
    const int COLS = 4;

    // Matrix initialization
    int table[ROWS][COLS] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    std::cout << "Matrix " << ROWS << "x" << COLS << ":\n";

    // Nested for loop to walk through the matrix
    for (int i = 0; i < ROWS; i++) {
        std::cout << "  [ ";
        for (int j = 0; j < COLS; j++) {
            std::cout << table[i][j];
            if (j < COLS - 1) std::cout << ", ";
        }
        std::cout << " ]\n";
    }

    // Pointer walking through the matrix linearly
    int* pMat = &table[0][0];
    int sum = 0;
    for (int k = 0; k < ROWS * COLS; k++) {
        sum += *(pMat + k);  // pointer arithmetic
    }
    std::cout << "  Sum of all elements (via pointer): " << sum << "\n";
    std::cout << "========================================\n";
}

// ============================================================
// LOAD THE LIBRARY WITH SAMPLE DATA
// ============================================================
void loadSampleData(Library& lib) {
    // Add books
    lib.addBook("Dom Casmurro",           "Machado de Assis",   1899);
    lib.addBook("O Cortico",              "Aluisio Azevedo",    1890);
    lib.addBook("Grande Sertao Veredas",  "Guimaraes Rosa",     1956);
    lib.addBook("A Hora da Estrela",      "Clarice Lispector",  1977);
    lib.addBook("C++ Primer",             "Lippman & Lajoie",   2012);
    lib.addBook("Clean Code",             "Robert C. Martin",   2008);

    // Register members
    Address a1 = {"Rua das Flores, 10", "Sao Paulo",      1310};
    Address a2 = {"Av. Brasil, 250",    "Rio de Janeiro", 20040};
    Address a3 = {"Rua XV, 88",         "Curitiba",       80020};

    lib.registerMember("Ana Paula",      a1);
    lib.registerMember("Carlos Eduardo", a2);
    lib.registerMember("Mariana Silva",  a3);

    std::cout << "\n[Sample data loaded!]\n";
}

// ============================================================
// MAIN — Main program loop
// ============================================================
int main() {
    // Configure output
    std::cout << std::boolalpha;

    // Object on the Stack — constructor called automatically
    Library lib("C++ Public Library");

    // Fill with demo data
    loadSampleData(lib);

    int option;

    // Main menu loop — do-while guarantees it runs at least once
    do {
        showMenu();
        option = readValidOption(0, 9);

        // Switch-case to choose an action
        switch (option) {

            case 1: { // Add Book
                std::cout << "\n--- ADD BOOK ---\n";
                std::string title  = readNonEmptyString("Title: ");
                std::string author = readNonEmptyString("Author: ");
                std::cout << "Publication year: ";
                int year = readValidOption(1000, 2099);
                lib.addBook(title, author, year);
                std::cout << "Book added!\n";
                break;
            }

            case 2: { // Register Member
                std::cout << "\n--- REGISTER MEMBER ---\n";
                std::string name   = readNonEmptyString("Name: ");
                std::string street = readNonEmptyString("Street: ");
                std::string city   = readNonEmptyString("City: ");
                std::cout << "ZIP code (numbers only): ";
                int zip = readValidOption(1000, 99999999);
                Address addr = {street, city, zip};
                lib.registerMember(name, addr);
                break;
            }

            case 3: { // Lend Book
                std::cout << "\n--- LEND BOOK ---\n";
                lib.listAvailable();
                std::string title = readNonEmptyString("\nBook title: ");
                std::cout << "Member ID: ";
                int id = readValidOption(1, 9999);
                lib.lendBook(title, id);
                break;
            }

            case 4: { // Return Book
                std::cout << "\n--- RETURN BOOK ---\n";
                std::string title = readNonEmptyString("Book title: ");
                lib.returnBook(title);
                break;
            }

            case 5: // List All
                lib.listBooks();
                break;

            case 6: // List Available
                lib.listAvailable();
                break;

            case 7: // List Members
                lib.listMembers();
                break;

            case 8: { // Recursive factorial
                std::cout << "\n--- FACTORIAL (RECURSION) ---\n";
                std::cout << "Enter a number (0-12): ";
                int n = readValidOption(0, 12);

                // for loop showing the recursion "countdown"
                std::cout << "Calculating: ";
                for (int i = n; i > 1; i--) {
                    std::cout << i << " x ";
                }
                std::cout << "1 = " << factorial(n) << "\n";
                break;
            }

            case 9: // Pointers and references demo
                demoPointersReferences();
                demoMatrix();
                break;

            case 0: // Exit
                if (confirmAction("Are you sure you want to exit?")) {
                    std::cout << "\nShutting down...\n";
                    // lib goes out of scope here -> ~Library() is called automatically
                } else {
                    option = -1;  // force the loop to continue
                }
                break;

            default:
                std::cout << "Invalid option!\n";
        }

        // Pause between operations (except on exit)
        if (option != 0) {
            std::cout << "\nPress ENTER to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (option != 0);

    std::cout << "\nThank you for using the Library System!\n";
    std::cout << "(The Library destructor will be called now)\n\n";

    // ~Library() is called automatically at the end of main()'s scope
    return 0;
}
