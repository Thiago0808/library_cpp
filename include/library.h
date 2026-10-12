#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>

// ============================================================
// STRUCTS
// ============================================================
struct Address {
    std::string street;
    std::string city;
    int zipCode;
};

// ============================================================
// BOOK CLASS (Object-Oriented Programming)
// ============================================================
class Book {
private:
    std::string title;
    std::string author;
    int year;
    bool available;

public:
    // Constructor and Destructor
    Book(const std::string& title, const std::string& author, int year);
    ~Book();

    // Getters and Setters (Encapsulation)
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    bool isAvailable() const;
    void setAvailable(bool status);

    void display() const;
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
    Member(const std::string& name, int id, const Address& addr);
    ~Member();

    std::string getName() const;
    int getId() const;
    void display() const;
};

// ============================================================
// LIBRARY CLASS (uses vectors and pointers)
// ============================================================
class Library {
private:
    std::vector<Book*> collection;    // vector of pointers (heap)
    std::vector<Member*> members;
    std::string name;
    int nextMemberId;

public:
    Library(const std::string& name);
    ~Library();  // frees memory (destructor)

    void addBook(const std::string& title, const std::string& author, int year);
    void registerMember(const std::string& name, const Address& addr);
    bool lendBook(const std::string& title, int memberId);
    bool returnBook(const std::string& title);
    void listBooks() const;
    void listMembers() const;
    void listAvailable() const;
    int totalBooks() const;

    // Search returning a pointer
    Book* findBook(const std::string& title);
    Member* findMember(int id);
};

// ============================================================
// FREE FUNCTIONS (Functions - concepts and development)
// ============================================================
void showMenu();
void clearScreen();
bool confirmAction(const std::string& message);
int readValidOption(int min, int max);
std::string readNonEmptyString(const std::string& prompt);

// Function with a pointer parameter
void incrementCounter(int* counter);

// Function with a reference parameter
void formatTitle(std::string& text);

// Recursive function (bonus)
int factorial(int n);

// Simple template (extra concept)
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

#endif // LIBRARY_H
