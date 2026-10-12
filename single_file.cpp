/*
 * ============================================================
 *  C++ LIBRARY SYSTEM — SINGLE FILE
 *  Paste this file into any online compiler:
 *  - https://www.onlinegdb.com/online_c++_compiler
 *  - https://replit.com
 *  - https://godbolt.org
 *
 *  Topics covered:
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
 *  [x] Constructors and Destructors
 *  [x] Structs
 *  [x] Additional concepts (template, nullptr, const)
 * ============================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <cctype>
#include <algorithm>

// ============================================================
// STRUCT
// ============================================================
struct Address {
    std::string street;
    std::string city;
    int zipCode;
};

// ============================================================
// TEMPLATE (additional concept)
// ============================================================
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// ============================================================
// BOOK CLASS
// ============================================================
class Book {
private:
    std::string title;
    std::string author;
    int year;
    bool available;

public:
    Book(const std::string& t, const std::string& a, int year)
        : title(t), author(a), year(year), available(true)
    {
        std::cout << "[Book created on the heap]: " << title << "\n";
    }

    ~Book() {
        std::cout << "[Book removed from memory]: " << title << "\n";
    }

    std::string getTitle()    const { return title; }
    std::string getAuthor()   const { return author; }
    int         getYear()     const { return year; }
    bool        isAvailable() const { return available; }
    void setAvailable(bool s)       { available = s; }

    void display() const {
        std::string status = available ? "Available" : "On loan";
        std::cout << std::left
                  << std::setw(35) << title
                  << std::setw(25) << author
                  << std::setw(6)  << year
                  << "[" << status << "]\n";
    }
};

// ============================================================
// MEMBER CLASS
// ============================================================
class Member {
private:
    std::string name;
    int id;
    Address address;

public:
    Member(const std::string& name, int id, const Address& addr)
        : name(name), id(id), address(addr)
    {
        std::cout << "[Member registered]: " << name << " (ID: " << id << ")\n";
    }

    ~Member() {
        std::cout << "[Member removed]: " << name << "\n";
    }

    std::string getName() const { return name; }
    int         getId()   const { return id; }

    void display() const {
        std::cout << "  ID: " << std::setw(4) << id
                  << " | Name: " << std::setw(20) << name
                  << " | City: " << address.city << "\n";
    }
};

// ============================================================
// LIBRARY CLASS
// ============================================================
class Library {
private:
    std::vector<Book*>   collection;
    std::vector<Member*> members;
    std::string name;
    int nextMemberId;

public:
    Library(const std::string& name)
        : name(name), nextMemberId(1)
    {
        std::cout << "\n=== Library \"" << name << "\" initialized ===\n\n";
    }

    ~Library() {
        std::cout << "\n[Freeing heap memory...]\n";
        for (Book*   b : collection) delete b;
        for (Member* m : members)    delete m;
        std::cout << "[Memory freed successfully]\n";
    }

    void addBook(const std::string& title,
                 const std::string& author, int year) {
        collection.push_back(new Book(title, author, year));
    }

    void registerMember(const std::string& memberName, const Address& addr) {
        members.push_back(new Member(memberName, nextMemberId++, addr));
    }

    Book* findBook(const std::string& title) {
        for (int i = 0; i < (int)collection.size(); i++) {
            Book* ptr = collection[i];
            if (ptr->getTitle() == title) return ptr;
        }
        return nullptr;
    }

    Member* findMember(int id) {
        for (Member* m : members)
            if (m->getId() == id) return m;
        return nullptr;
    }

    bool lendBook(const std::string& title, int memberId) {
        Book*   book   = findBook(title);
        Member* member = findMember(memberId);

        if (book == nullptr)       { std::cout << "Book not found!\n";      return false; }
        if (member == nullptr)     { std::cout << "Member not found!\n";    return false; }
        if (!book->isAvailable())  { std::cout << "Book already on loan!\n"; return false; }

        book->setAvailable(false);
        std::cout << "\"" << title << "\" lent to " << member->getName() << "!\n";
        return true;
    }

    bool returnBook(const std::string& title) {
        Book* book = findBook(title);
        if (book == nullptr)      { std::cout << "Book not found!\n";      return false; }
        if (book->isAvailable())  { std::cout << "Book was not on loan!\n"; return false; }
        book->setAvailable(true);
        std::cout << "\"" << title << "\" returned!\n";
        return true;
    }

    void listBooks() const {
        if (collection.empty()) { std::cout << "The collection is empty.\n"; return; }
        std::cout << "\n" << std::string(72, '-') << "\n";
        std::cout << std::left
                  << std::setw(35) << "TITLE"
                  << std::setw(25) << "AUTHOR"
                  << std::setw(6)  << "YEAR" << "STATUS\n";
        std::cout << std::string(72, '-') << "\n";
        for (int i = 0; i < (int)collection.size(); i++)
            collection[i]->display();
        std::cout << std::string(72, '-') << "\n";
    }

    void listAvailable() const {
        std::cout << "\n--- Available Books ---\n";
        bool any = false;
        for (Book* b : collection)
            if (b->isAvailable()) { b->display(); any = true; }
        if (!any) std::cout << "None available.\n";
    }

    void listMembers() const {
        if (members.empty()) { std::cout << "No members.\n"; return; }
        std::cout << "\n--- Members ---\n";
        for (Member* m : members) m->display();
    }
};

// ============================================================
// UTILITY FUNCTIONS
// ============================================================

// Function with a pointer parameter
void incrementCounter(int* counter) {
    if (counter != nullptr) (*counter)++;
}

// Function with a reference parameter
void formatTitle(std::string& text) {
    bool newWord = true;
    for (char& c : text) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isspace(uc))  { newWord = true; }
        else if (newWord)      { c = std::toupper(uc); newWord = false; }
        else                     c = std::tolower(uc);
    }
}

// Recursive function
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

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

bool confirmAction(const std::string& msg) {
    std::cout << msg << " (y/n): ";
    char r; std::cin >> r;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return (r == 'y' || r == 'Y') ? true : false;
}

int readValidOption(int min, int max) {
    int option;
    while (true) {
        std::cin >> option;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid. Enter a number between " << min << " and " << max << ": ";
        } else if (option < min || option > max) {
            std::cout << "Out of range. Try again: ";
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
        if (input.empty()) std::cout << "Cannot be empty!\n";
    } while (input.empty());
    return input;
}

// ============================================================
// DEMO: Pointers and References
// ============================================================
void demoPointersReferences() {
    std::cout << "\n======= DEMO: POINTERS AND REFERENCES =======\n\n";

    int x = 10, y = 20;
    std::cout << "Stack: x=" << x << " address=" << &x << "\n";
    std::cout << "Stack: y=" << y << " address=" << &y << "\n";

    int* ptr = &x;
    std::cout << "\nptr points to x:\n";
    std::cout << "  ptr=" << ptr << "  *ptr=" << *ptr << "\n";
    *ptr = 99;
    std::cout << "  After *ptr=99, x=" << x << "\n";

    // Pointer arithmetic with an array
    int grades[5] = {7, 8, 6, 9, 10};
    int* pGrades = grades;
    std::cout << "\nArray via pointer arithmetic: ";
    for (int i = 0; i < 5; i++)
        std::cout << *(pGrades + i) << " ";
    std::cout << "\n";

    // Reference
    int& refX = x;
    refX = 42;
    std::cout << "\nReference: refX=42 -> x=" << x << "\n";

    // Heap
    int* heapVal = new int(55);
    std::cout << "\nHeap: *heapVal=" << *heapVal << " address=" << heapVal << "\n";
    delete heapVal;
    heapVal = nullptr;
    std::cout << "Memory freed. heapVal=nullptr\n";

    // Function with a pointer
    int counter = 0;
    incrementCounter(&counter);
    incrementCounter(&counter);
    incrementCounter(&counter);
    std::cout << "\nCounter after 3 increments via pointer: " << counter << "\n";

    // Function with a reference
    std::string title = "dom casmurro - machado de assis";
    formatTitle(title);
    std::cout << "Title formatted via reference: \"" << title << "\"\n";

    // Template
    std::cout << "\nTemplate maxValue:\n";
    std::cout << "  int:    " << maxValue(10, 25)    << "\n";
    std::cout << "  double: " << maxValue(3.14, 2.7) << "\n";
    std::cout << "  char:   " << maxValue('a', 'z')  << "\n";

    std::cout << "=============================================\n";
}

// ============================================================
// DEMO: Matrix
// ============================================================
void demoMatrix() {
    std::cout << "\n======= DEMO: MATRIX (2D ARRAY) =======\n";
    const int R = 3, C = 4;
    int tab[R][C] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    for (int i = 0; i < R; i++) {
        std::cout << "  [ ";
        for (int j = 0; j < C; j++)
            std::cout << tab[i][j] << (j<C-1?", ":"");
        std::cout << " ]\n";
    }

    int* p = &tab[0][0];
    int sum = 0;
    for (int k = 0; k < R*C; k++) sum += *(p + k);
    std::cout << "  Sum via pointer: " << sum << "\n";
    std::cout << "========================================\n";
}

// ============================================================
// LOAD SAMPLE DATA
// ============================================================
void loadSampleData(Library& lib) {
    lib.addBook("Dom Casmurro",          "Machado de Assis",  1899);
    lib.addBook("O Cortico",             "Aluisio Azevedo",   1890);
    lib.addBook("Grande Sertao Veredas", "Guimaraes Rosa",    1956);
    lib.addBook("A Hora da Estrela",     "Clarice Lispector", 1977);
    lib.addBook("C++ Primer",            "Lippman & Lajoie",  2012);
    lib.addBook("Clean Code",            "Robert C. Martin",  2008);

    Address a1 = {"Rua das Flores, 10", "Sao Paulo",      1310};
    Address a2 = {"Av. Brasil, 250",    "Rio de Janeiro", 20040};
    Address a3 = {"Rua XV, 88",         "Curitiba",       80020};

    lib.registerMember("Ana Paula",      a1);
    lib.registerMember("Carlos Eduardo", a2);
    lib.registerMember("Mariana Silva",  a3);
    std::cout << "\n[Sample data loaded!]\n";
}

// ============================================================
// MAIN
// ============================================================
int main() {
    std::cout << std::boolalpha;

    Library lib("C++ Public Library");
    loadSampleData(lib);

    int option;
    do {
        showMenu();
        option = readValidOption(0, 9);

        switch (option) {
            case 1: {
                std::cout << "\n--- ADD BOOK ---\n";
                std::string title  = readNonEmptyString("Title: ");
                std::string author = readNonEmptyString("Author: ");
                std::cout << "Year (1000-2099): ";
                int year = readValidOption(1000, 2099);
                lib.addBook(title, author, year);
                std::cout << "Book added!\n";
                break;
            }
            case 2: {
                std::cout << "\n--- REGISTER MEMBER ---\n";
                std::string name   = readNonEmptyString("Name: ");
                std::string street = readNonEmptyString("Street: ");
                std::string city   = readNonEmptyString("City: ");
                std::cout << "ZIP code: ";
                int zip = readValidOption(1, 99999999);
                lib.registerMember(name, {street, city, zip});
                break;
            }
            case 3: {
                std::cout << "\n--- LEND BOOK ---\n";
                lib.listAvailable();
                std::string title = readNonEmptyString("\nTitle: ");
                std::cout << "Member ID: ";
                int id = readValidOption(1, 9999);
                lib.lendBook(title, id);
                break;
            }
            case 4: {
                std::cout << "\n--- RETURN BOOK ---\n";
                std::string title = readNonEmptyString("Title: ");
                lib.returnBook(title);
                break;
            }
            case 5: lib.listBooks();     break;
            case 6: lib.listAvailable(); break;
            case 7: lib.listMembers();   break;
            case 8: {
                std::cout << "\n--- FACTORIAL (RECURSION) ---\n";
                std::cout << "Enter a number (0-12): ";
                int n = readValidOption(0, 12);
                std::cout << "Calculating: ";
                for (int i = n; i > 1; i--) std::cout << i << " x ";
                std::cout << "1 = " << factorial(n) << "\n";
                break;
            }
            case 9:
                demoPointersReferences();
                demoMatrix();
                break;
            case 0:
                if (!confirmAction("Are you sure?")) option = -1;
                break;
        }

        if (option != 0) {
            std::cout << "\nPress ENTER to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (option != 0);

    std::cout << "\nShutting down... (the destructor will be called now)\n\n";
    return 0;
}
