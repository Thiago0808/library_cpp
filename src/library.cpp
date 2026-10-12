#include "../include/library.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// ============================================================
// IMPLEMENTATION: LIBRARY CLASS
// Demonstrates: vectors, pointers, heap (new/delete), this
// ============================================================

Library::Library(const std::string& name)
    : name(name), nextMemberId(1)
{
    std::cout << "\n=== Library \"" << name << "\" initialized ===\n\n";
}

// Destructor: frees all memory allocated on the heap (Stack vs Heap)
Library::~Library() {
    std::cout << "\n[Freeing heap memory...]\n";

    // Walking through the vector — implicit pointer arithmetic via iterator
    for (Book* book : collection) {
        delete book;    // calls ~Book()
    }
    for (Member* m : members) {
        delete m;       // calls ~Member()
    }

    std::cout << "[Memory freed successfully]\n";
}

// Allocates a new Book on the heap with 'new'
void Library::addBook(const std::string& title,
                      const std::string& author,
                      int year)
{
    Book* newBook = new Book(title, author, year);  // heap allocation
    collection.push_back(newBook);
}

void Library::registerMember(const std::string& memberName, const Address& addr) {
    Member* newMember = new Member(memberName, nextMemberId++, addr);
    members.push_back(newMember);
}

// Search with a pointer — returns nullptr if not found
Book* Library::findBook(const std::string& title) {
    // Using a pointer to walk through (pointer arithmetic with a vector)
    for (int i = 0; i < (int)collection.size(); i++) {
        Book* ptr = collection[i];        // ptr points to the book
        if (ptr->getTitle() == title) {
            return ptr;                   // returns the address
        }
    }
    return nullptr;
}

Member* Library::findMember(int id) {
    for (Member* m : members) {
        if (m->getId() == id) return m;
    }
    return nullptr;
}

bool Library::lendBook(const std::string& title, int memberId) {
    Book*   book   = findBook(title);       // pointer
    Member* member = findMember(memberId);  // pointer

    if (book == nullptr) {
        std::cout << "Book not found!\n";
        return false;
    }
    if (member == nullptr) {
        std::cout << "Member not found!\n";
        return false;
    }
    if (!book->isAvailable()) {
        std::cout << "Book is already on loan!\n";
        return false;
    }

    book->setAvailable(false);
    std::cout << "Book \"" << title << "\" lent to "
              << member->getName() << "!\n";
    return true;
}

bool Library::returnBook(const std::string& title) {
    Book* book = findBook(title);

    if (book == nullptr) {
        std::cout << "Book not found!\n";
        return false;
    }
    if (book->isAvailable()) {
        std::cout << "This book was not on loan!\n";
        return false;
    }

    book->setAvailable(true);
    std::cout << "Book \"" << title << "\" returned successfully!\n";
    return true;
}

void Library::listBooks() const {
    if (collection.empty()) {
        std::cout << "The collection is empty.\n";
        return;
    }
    std::cout << "\n" << std::string(72, '-') << "\n";
    std::cout << std::left
              << std::setw(35) << "TITLE"
              << std::setw(25) << "AUTHOR"
              << std::setw(6)  << "YEAR"
              << "STATUS\n";
    std::cout << std::string(72, '-') << "\n";

    // Walking through the vector by index (demonstrates array-style access)
    for (int i = 0; i < (int)collection.size(); i++) {
        collection[i]->display();
    }
    std::cout << std::string(72, '-') << "\n";
}

void Library::listAvailable() const {
    std::cout << "\n--- Available Books ---\n";
    bool any = false;
    for (Book* b : collection) {
        if (b->isAvailable()) {
            b->display();
            any = true;
        }
    }
    if (!any) std::cout << "No books available at the moment.\n";
}

void Library::listMembers() const {
    if (members.empty()) {
        std::cout << "No members registered.\n";
        return;
    }
    std::cout << "\n--- Registered Members ---\n";
    for (Member* m : members) {
        m->display();
    }
}

int Library::totalBooks() const {
    return (int)collection.size();
}
