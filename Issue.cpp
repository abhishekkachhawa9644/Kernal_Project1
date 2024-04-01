#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Define structures for member and book

struct Member {
    int id;
    std::string name;
};

struct Book {

    int isbn;
    std::string title;
    bool available;
};


// Define functions to interact with the library system

void checkMemberDetails(const Member& member) {

    cout << "Member ID: " << member.id <<endl;
    cout << "Member Name: " << member.name <<endl;

}

void checkBookAvailability(const Book& book) {

    if (book.available) {

        cout << "Book with ISBN " << book.isbn << " is available" <<endl;

    } else {

        cout << "Book with ISBN " << book.isbn << " is not available" << endl;

    }

}

void printInvoice(const Member& member, const Book& book) {

    cout << "Invoice details for member " << member.name << ":" << endl;

    cout << "Book Title: " << book.title << endl;

    cout << "Book ISBN: " << book.isbn << endl;

    cout << "Total Amount: $10" << endl; // Assuming a fixed price for borrowing books

}



void removeBook(std::vector<Book>& books, int isbn) {

    for (auto it = books.begin(); it != books.end(); ++it) {

        if (it->isbn == isbn) {

            books.erase(it);

            cout << "Book with ISBN " << isbn << " removed from the library system" << endl;

            return;

        }

    }

    cout << "Book with ISBN " << isbn << " not found in the library system" << endl;

}


void createNewFileSystem() {

    std::ofstream file("library_system.txt");

    if (file.is_open()) {

        file << "Sample library system data" << endl;

        file.close();

        cout << "New file system created successfully" << endl;

    } else {

        std::cout << "Error creating new file system" << endl;

    }

}



int main() {

    Member member = {1, "John Doe"};

    Book book = {123456, "Sample Book", true};

    checkMemberDetails(member);

    checkBookAvailability(book);

    printInvoice(member, book);
    std::vector<Book> books = {{123456, "Sample Book 1", true}, {789012, "Sample Book 2", false}};
    removeBook(books, 789012);
    createNewFileSystem();

    return 0;

}