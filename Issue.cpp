#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;



void Issue_book()
{
    system("cls");
    string bookTitle, userName;
    string tt, at, gn, ib;
    cout << "\n\n\tEnter the book title you want to issue: ";
    cin.ignore();
    getline(cin, bookTitle);
    cout << "\n\n\tEnter user name: ";
    getline(cin, userName);

    ifstream booksFile("library_all_books.txt");
    if (!booksFile.is_open())
    {
        cout << "\tError opening file for reading!" << endl;
        return;
    }

    bool bookFound = false;
    string line;
    while (getline(booksFile, line))
    {
        stringstream ss(line);
        string title, author, genre, isbn;
        char delimiter;
        ss >> title >> delimiter >> author >> delimiter >> genre >> delimiter >> isbn;

        if (title == bookTitle)

        {
            tt = title;
            at = author;
            gn = genre;
            ib = isbn;

            bookFound = true;
            break;
        }
    }
    booksFile.close();

    if (!bookFound)
    {
        cout << "\tBook not found in the library!" << endl;
        Sleep(3000);
        return;
    }

    ifstream usersFile("Login.txt");
    if (!usersFile.is_open())
    {
        cout << "\tError opening users file for reading!" << endl;
        return;
    }

    bool userFound = false;
    while (getline(usersFile, line))
    {
        stringstream ss(line);
        string id, password;
        char delimiter;
        ss >> id >> delimiter >> password;

        if (id == userName)
        {
            userFound = true;
            break;
        }
    }
    usersFile.close();

    if (!userFound)
    {
        cout << "\tUser not found in the system!" << endl;
        Sleep(3000);
        return;
    }
    int days, charge = 10;
    cout << "\n\n How many days you want to borrow : ";
    cin >> days;
    charge *= days;

    cout << "\n\n";

    // If both book and user are found, add the book to the issued_books.txt file
    ofstream issuedBooksFile("issued_books.txt", ios::app);
    if (!issuedBooksFile.is_open())
    {
        cout << "\tError opening issued books file for writing!" << endl;
        return;
    }
    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);

    // Convert the current time to a tm structure for local time
    std::tm *returnTime = std::localtime(&currentTime);

    // Add 4 days to the current date
    returnTime->tm_mday += days;

    // Normalize the date (adjusting month and year if necessary)
    mktime(returnTime);

    // Print the updated date
    cout << "Updated date: " << (returnTime->tm_year + 1900) << "-"
         << (returnTime->tm_mon + 1) << "-"
         << returnTime->tm_mday << endl;

    issuedBooksFile << bookTitle << " : " << at << " : " << gn << " : " << ib << " : " << userName << " : " << (localTime->tm_year + 1900) << "-" << (localTime->tm_mon + 1) << "-" << localTime->tm_mday << " : " << (localTime->tm_hour) << ":" << (localTime->tm_min) << ":" << localTime->tm_sec << " : " << (returnTime->tm_year + 1900) << "-" << (returnTime->tm_mon + 1) << "-" << returnTime->tm_mday << endl;
    issuedBooksFile.close();

    cout << "\tBook issued successfully!" << endl;
    Sleep(3000);

    system("cls");

    ifstream inFile;
    inFile.open("library_all_books.txt");
    if (!inFile.is_open())
    {
        cout << "Error opening file for reading!" << endl;
    }

    ofstream tempFile;
    tempFile.open("temp.txt");
    if (!tempFile.is_open())
    {
        cout << "Error opening temporary file!" << endl;
        inFile.close();
    }

    bool found = false;

    while (getline(inFile, line))
    {
        stringstream ss;
        ss << line;
        string tt, at, gn, ib;
        char delimiter;
        ss >> tt >> delimiter >> at >> delimiter >> gn >> delimiter >> ib;

        if (tt != bookTitle)
        {
            tempFile << "\t" << tt << " : " << at << " : " << gn << " : " << ib << endl
                     << endl;
        }
        else
        {
            found = true;
        }
        getline(inFile, line);
    }

    inFile.close();
    tempFile.close();

    remove("library_all_books.txt");
    rename("temp.txt", "library_all_books.txt");

    system("cls");
    cout << "\n\n\t*****INVOICE*****\n\n";

    cout << "\n\t User member     :  " << userName << endl;
    cout << "\n\t Book Title      :  " << bookTitle << endl;
    cout << "\n\t Book Author     :  " << at << endl;
    cout << "\n\t Book Genre      :  " << gn << endl;
    cout << "\n\t Book ISBN       :  " << ib << endl;

    cout << "\n\tIssued on Date   :  " << (localTime->tm_year + 1900) << "-" << (localTime->tm_mon + 1) << "-" << localTime->tm_mday << endl;
    cout << "\n\t          Time   :  " << (localTime->tm_hour) << ":" << (localTime->tm_min) << ":" << localTime->tm_sec << endl;

    cout << "\n\tIssued for       :  " << days << " days" << endl;
    cout << "\n\tReturn Date      :  " << (returnTime->tm_year + 1900) << "-" << (returnTime->tm_mon + 1) << "-" << returnTime->tm_mday << endl;
    cout << "\n\tBook charge per day : $10" << endl;
    cout << "\n\tTotal amount        : $" << charge << endl;
    Sleep(10000);
}

int main(){

    Issue_book();
    return 0;
}