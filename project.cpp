#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

class Book
{
private:
    string Book_Title, Book_Author, Book_Genre, Book_ISBN;

public:
    void setTitle(string title)
    {
        Book_Title = title;
    }
    void setAuthor(string author)
    {
        Book_Author = author;
    }
    void setGenre(string genre)
    {
        Book_Genre = genre;
    }
    void setISBN(string isbn)
    {
        Book_ISBN = isbn;
    }

    string getTitle()
    {
        return Book_Title;
    }
    string getAuthor()
    {
        return Book_Author;
    }
    string getGenre()
    {
        return Book_Genre;
    }
    string getISBN()
    {
        return Book_ISBN;
    }
};
void add_book(Book B)
{
    system("cls");
    string tt, at, gn, ib;
    cout << "\tEnter The Title of the book : ";
    cin >> tt;
    B.setTitle(tt);
    cout << "\tEnter The Author name : ";
    cin >> at;
    B.setAuthor(at);
    cout << "\tEnter The genre : ";
    cin >> gn;
    B.setGenre(gn);
    cout << "\tEnter The ISBN number : ";
    cin >> ib;
    B.setISBN(ib);

    ofstream outfile;
    outfile.open("library_all_books.txt", ios::app);
    if (!outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }
    else
    {
        outfile << "\t" << B.getTitle() << " : " << B.getAuthor() << " : " << B.getGenre() << " : " << B.getISBN() << endl
                << endl;
        cout << "\n\n\tBook added in library Successfuly!\n\n"
             << endl;
    }
    outfile.close();
    Sleep(3000);
}

void remove_book()

{
    system("cls");
    string ttt;
    cout << "\tWhich book you have to remove : ";
    cin >> ttt;
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
    string line;

    while (getline(inFile, line))
    {
        stringstream ss;
        ss << line;
        string tt, at, gn, ib;
        char delimiter;
        ss >> tt >> delimiter >> at >> delimiter >> gn >> delimiter >> ib;

        if (tt != ttt)
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

    if (!found)
    {
        cout << "Record with ID " << ttt << " not found!" << endl;
        remove("temp.txt");
    }
    else
    {
        remove("library_all_books.txt");
        rename("temp.txt", "library_all_books.txt");
        cout << "Record with book name " << ttt << " removed successfully.\n"
             << endl;
    }
    Sleep(3000);
}
void search_book()
{
    system("cls");
    string ttt;
    cout << "\n\n\tEnter the book Title you want to search : ";
    cin >> ttt;
    ifstream inFile;
    inFile.open("library_all_books.txt");
    if (!inFile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }
    else
    {
        string line;
        bool found = false;
        while (getline(inFile, line))
        {
            stringstream ss;
            ss << line;
            string tt, at, gn, ib;
            char delimiter;
            ss >> tt >> delimiter >> at >> delimiter >> gn >> delimiter >> ib;

            if (ttt == tt)
            {
                found = true;

                cout << "\tPlease Wait";
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    Sleep(800);
                }
                system("cls");
                cout << "\tBook found!" << endl;
            }
        }
        if (!found)
        {
            cout << "\tBook not found!" << endl;
        }
    }
    inFile.close();
    Sleep(5000);
}
