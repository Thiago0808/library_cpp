# 📚 Library System — C++ Teaching Project

A complete project that demonstrates **every topic in the course**, using a library management system as the common thread.

---

## 🚀 How to build and run

```bash
# With the Makefile (Linux/macOS)
make
./library

# Or directly with g++
g++ -std=c++17 -Wall src/main.cpp src/book.cpp src/library.cpp src/utils.cpp -Iinclude -o library
./library

# Windows (MinGW)
g++ -std=c++17 src/main.cpp src/book.cpp src/library.cpp src/utils.cpp -Iinclude -o library.exe
library.exe
```

Prefer a single file? `single_file.cpp` contains the whole program and can be pasted into any online compiler (OnlineGDB, Replit, Godbolt).

---

## 📁 File Structure

```
library/
├── include/
│   └── library.h          ← declarations (interface)
├── src/
│   ├── main.cpp           ← main program + demos
│   ├── book.cpp           ← Book and Member implementation
│   ├── library.cpp        ← Library class implementation
│   └── utils.cpp          ← utility functions
├── single_file.cpp        ← everything in one file
├── Makefile
└── README.md
```

---

## 🗺️ Course Topics → Code Map

| Course Topic | Where it is in the code |
|---|---|
| Variables and types | `main.cpp` — `int`, `std::string`, `bool`, `char` throughout the project |
| Input (`cin`) | `utils.cpp` — `readNonEmptyString()`, `readValidOption()` |
| Arithmetic/relational/logical operators | `utils.cpp` — comparisons in loops; `library.cpp` — `\|\|`, `&&`, `!` |
| `if-else` | `library.cpp` — `lendBook()`, `returnBook()` |
| Ternary operator `? :` | `book.cpp` — `available` in `display()`; `utils.cpp` — `confirmAction()` |
| `switch-case` | `main.cpp` — main menu |
| `while` | `utils.cpp` — `readValidOption()` |
| `do-while` | `main.cpp` — main loop; `utils.cpp` — `readNonEmptyString()` |
| `for` | `main.cpp` — `demoMatrix()`, factorial display |
| Functions | `utils.cpp` — free utility functions; `library.h` — prototypes |
| `*Pointers` | `main.cpp` → `demoPointersReferences()` — step-by-step explanation |
| `&References` | `utils.cpp` — `formatTitle(std::string&)`, `main.cpp` — `loadSampleData(Library&)` |
| Vectors/Arrays | `library.cpp` — `std::vector<Book*>`, `main.cpp` — `int grades[5]` |
| Matrices (2D) | `main.cpp` → `demoMatrix()` — `int table[3][4]` |
| Pointer arithmetic | `main.cpp` — `*(pGrades + i)`, `library.cpp` — index-based access |
| Classes, Objects, Attributes, Methods | `Book`, `Member`, `Library` — complete classes |
| Stack vs Heap | `main.cpp` — explicit demo with `new`/`delete`; `library.cpp` — `new Book(...)` |
| `.h` vs `.cpp` | Split into `library.h` (declaration) and `.cpp` files (implementation) |
| The `this` pointer | Implicit in every class method |
| Constructors and Destructors | Every class has a constructor and destructor with visible `std::cout` |
| Structs | `include/library.h` — `struct Address` |
| Additional OOP concepts | `template<T>` in `maxValue()`, `nullptr`, `const`, encapsulation |

---

## 🎮 Program Menu

```
╔══════════════════════════════════╗
║        C++ LIBRARY SYSTEM        ║
╠══════════════════════════════════╣
║  1. Add Book                     ║
║  2. Register Member              ║
║  3. Lend Book                    ║
║  4. Return Book                  ║
║  5. List All Books               ║
║  6. List Available Books         ║
║  7. List Members                 ║
║  8. Factorial (recursion)        ║
║  9. Demo: Pointers & Refs        ║
║  0. Exit                         ║
╚══════════════════════════════════╝
```

**Option 9** is especially useful: it runs an interactive demonstration of pointers, references, pointer arithmetic, heap/stack and templates — all with explanatory `cout` output.

---

## 💡 Key Concepts Illustrated

### Stack vs Heap
```cpp
// Stack: local variable, destroyed when it goes out of scope
Library lib("Public");         // ~Library() is called at the end of main()

// Heap: manual allocation, requires delete
Book* book = new Book(...);    // outlives the scope
delete book;                   // must be done manually
```

### Pointer vs Reference
```cpp
void increment(int* ptr) { (*ptr)++; }    // pointer — can be nullptr
void format(std::string& s) { ... }       // reference — always valid, no *
```

### Constructor/Destructor (visible at runtime)
When adding books you will see `[Book created on the heap]`; when exiting, you will see `[Book removed from memory]` for each one.
