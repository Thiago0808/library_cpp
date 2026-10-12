#include "../include/library.h"
#include <iostream>
#include <iomanip>

// ============================================================
// IMPLEMENTATION: BOOK CLASS
// Separate file (.cpp) - the .h vs .cpp concept
// ============================================================

Book::Book(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year), available(true)
{
    // Constructor: initializes attributes via an initializer list
    std::cout << "[Book created on the heap]: " << title << "\n";
}

Book::~Book() {
    // Destructor: called when the object is deleted
    std::cout << "[Book removed from memory]: " << title << "\n";
}

std::string Book::getTitle() const  { return title; }
std::string Book::getAuthor() const { return author; }
int         Book::getYear()   const { return year; }
bool        Book::isAvailable() const { return available; }

void Book::setAvailable(bool status) {
    available = status;
}

void Book::display() const {
    std::string status = available ? "Available" : "On loan";
    std::cout << std::left
              << std::setw(35) << title
              << std::setw(25) << author
              << std::setw(6)  << year
              << "[" << status << "]\n";
}

// ============================================================
// IMPLEMENTATION: MEMBER CLASS
// ============================================================

Member::Member(const std::string& name, int id, const Address& addr)
    : name(name), id(id), address(addr)
{
    std::cout << "[Member registered]: " << name << " (ID: " << id << ")\n";
}

Member::~Member() {
    std::cout << "[Member removed]: " << name << "\n";
}

std::string Member::getName() const { return name; }
int         Member::getId()   const { return id; }

void Member::display() const {
    std::cout << "  ID: " << std::setw(4) << id
              << " | Name: " << std::setw(20) << name
              << " | City: " << address.city << "\n";
}
