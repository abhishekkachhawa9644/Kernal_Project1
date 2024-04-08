#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
int k;
string Member_Name, Member_Sername, Member_DOB, Member_Mobile_No, Member_Gmail, Member_Address, Adhar_Id, Member_Password;
char s;
class Book // class Book to store and encapsulate data
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
void add_book(Book B) // add book funcion
{
    system("cls");
    cout << "\n\n\t\t --------- Add book ---------\n\n";
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

void remove_book() //  function for remove book
{
    system("cls");
    cout << "\n\n\t\t --------- Remove book ---------\n\n";
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
void search_book() // function for search book
{
    system("cls");
    cout << "\n\n\t\t --------- Search book ---------\n\n";
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
                cout << "\n\n\tTitle   : " << tt;
                cout << "\n\n\tAuthor  : " << at;
                cout << "\n\n\tGenre   : " << gn;
                cout << "\n\n\tISBN    : " << ib;
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
class Login // class login
{
private:
    string LoginID, Password;

public:
    void setID(string id)
    {
        LoginID = id;
    }

    void setPW(string pw)
    {
        Password = pw;
    }

    string getID()
    {
        return LoginID;
    }

    string getPW()
    {
        return Password;
    }
};

void registration(Login log) // function for registration
{
    system("cls");
    cout << "\n\n\t\t --------- Registration Form ---------\n\n";
    string id, pw;
    cout << "\tEnter Login ID: ";
    cin >> id;
    log.setID(id);

start:
    cout << "\tEnter A Strong Password: ";
    cin >> pw;
    if (pw.length() >= 8)
    {
        log.setPW(pw);
    }
    else
    {
        cout << "\tEnter Minimum 8 Characters!" << endl;
        goto start;
    }
    ofstream outfile;
    outfile.open("Login.txt", ios::app);
    if (!outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }
    else
    {
        outfile << "\t" << log.getID() << " : " << log.getPW() << endl
                << endl;
        cout << "\tUser Registered Successfuly!" << endl;
    }
    outfile.close();
    Sleep(3000);
}

int login() // login function
{
    system("cls");
    cout << "\n\n\t\t --------- Login ---------\n\n";
    string id, pw;
    cout << "\tEnter Login ID: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;

    ifstream infile;
    infile.open("Login.txt");
    if (!infile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }
    else
    {
        string line;
        bool found = false;
        while (getline(infile, line))
        {
            stringstream ss;
            ss << line;
            string userID, userPW;
            char delimiter;
            ss >> userID >> delimiter >> userPW;

            if (id == userID && pw == userPW)
            {
                found = true;

                cout << "\tPlease Wait";
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    Sleep(800);
                }
                system("cls");
                cout << "\tLogin Successful" << endl;
                Sleep(2000);
                return 1;
            }
        }
        if (!found)
        {
            cout << "\tError: Incorrect Login ID Or Password!" << endl;
            Sleep(2000);
            return 0;
        }

    }
    infile.close();
    Sleep(5000);
    return 0;
}

void update_book() // function to update any entity
{
    system("cls");
    cout << "\n\n\t\t --------- Update book ---------\n\n";
    string searchStr, replaceStr;
    cout << "\tEnter the book title you want to update: ";
    cin.ignore();
    getline(cin, searchStr);
    cout << "\n\tEnter the new book title: ";
    getline(cin, replaceStr);
    ifstream file("library_all_books.txt");
    string line, modifiedContent;
    if (!file.is_open())
    {
        cout << "Unable to open file";
        return;
    }
    while (getline(file, line))
    {
        size_t found = line.find(searchStr);
        if (found != string::npos)
        {
            line.replace(found, searchStr.length(), replaceStr); // Replace search string with replace string
        }
        modifiedContent += line + "\n";
    }
    file.close();
    ofstream outFile("library_all_books.txt");
    if (!outFile.is_open())
    {
        cout << "Unable to open file";
        return;
    }
    outFile << modifiedContent;
    outFile.close();
    cout << "\n\n\t-------  Operation done. Updated Successfuly  ----------";

    Sleep(3000);
}

void Issue_book() // function to issue book
{
    system("cls");
    cout << "\n\n\t\t --------- Issue book ---------\n\n";
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

    ifstream usersFile("library_member.txt");
    if (!usersFile.is_open())
    {
        cout << "\tError opening users file for reading!" << endl;
        return;
    }

    bool userFound = false;
    while (usersFile >> Member_Name >> Member_Sername >> s >> Member_DOB >> s >> Member_Mobile_No >> s >> Member_Gmail >> s >> Member_Address >> s >> Adhar_Id >> s >> Member_Password)
    {

        if (Member_Gmail == userName)
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
    cout << "\n\n\t How many days you want to borrow : ";
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
    // Get the current time
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Print the current date
    string current_date;
    cout << "\tCurrent Date: ";
    cout << ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year << endl;

    // Calculate new date
    time_t newTime = now + days * 24 * 60 * 60; // seconds in a day
    tm *newLtm = localtime(&newTime);

    // Print the new date
    string return_date;
    cout << "\tReturn  Date: ";
    cout << newLtm->tm_mday << "-" << 1 + newLtm->tm_mon << "-" << 1900 + newLtm->tm_year << endl;

    issuedBooksFile << bookTitle << " : " << at << " : " << gn << " : " << ib << " : " << userName << " : " << ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year << " : " << newLtm->tm_mday << "-" << 1 + newLtm->tm_mon << "-" << 1900 + newLtm->tm_year << endl;
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
    cout << "\n\n\t************INVOICE************\n\n";

    cout << "\n\t User member         :  " << userName << endl;
    cout << "\n\t Book Title          :  " << bookTitle << endl;
    cout << "\n\t Book Author         :  " << at << endl;
    cout << "\n\t Book Genre          :  " << gn << endl;
    cout << "\n\t Book ISBN           :  " << ib << endl;
    cout << "\n\t Issued on Date      :  " << ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year << endl;
    cout << "\n\t Issued for          :  " << days << " days" << endl;
    cout << "\n\t Return Date         :  " << newLtm->tm_mday << "-" << 1 + newLtm->tm_mon << "-" << 1900 + newLtm->tm_year << endl;
    cout << "\n\t Book charge per day : $10" << endl;
    cout << "\n\t Total amount        : $" << charge << endl;

    Sleep(10000);
}
void return_book() // function to  return a book
{
    system("cls");
    cout << "\n\n\t\t --------- Return book ---------\n\n";
    string bookTitle;
    cout << "Enter book Title : ";
    cin >> bookTitle;
    ifstream read_issued_books;
    read_issued_books.open("issued_books.txt");
    string line;
    while (getline(read_issued_books, line))
    {
        stringstream ss(line);
        string tt, at, gn, ib, un, cd, ct, rd;
        char delimiter;
        ss >> tt >> delimiter >> at >> delimiter >> gn >> delimiter >> ib >> delimiter >> un >> delimiter >> cd >> delimiter >> ct >> delimiter >> rd;
        if (tt == bookTitle)
        {
            ofstream write_book;
            write_book.open("library_all_books.txt", ios::app);
            write_book << "\t" << tt << " : " << at << " : " << gn << " : " << ib << endl;
        }
    }
    read_issued_books.close();

    ifstream inFile;
    inFile.open("issued_books.txt");
    if (!inFile.is_open())
    {
        cout << "Error opening file for reading!" << endl;
    }

    ofstream tempFile;
    tempFile.open("temp.txt", ios::app);
    if (!tempFile.is_open())
    {
        cout << "Error opening temporary file!" << endl;
        inFile.close();
    }

    while (getline(inFile, line))
    {
        stringstream ss(line);

        string tt, at, gn, ib, un, cd, ct, rd;
        char delimiter;
        ss >> bookTitle >> delimiter >> at >> delimiter >> gn >> delimiter >> ib >> delimiter >> un >> delimiter >> cd >> delimiter >> ct >> delimiter >> rd;

        if (tt != bookTitle)
        {
            tempFile << "\t" << bookTitle << " : " << at << " : " << gn << " : " << ib << " : " << un << " : " << cd << " : " << ct << " : " << rd << endl;
        }
        if (tt == bookTitle)
        {
            cout << "\n\n\tNo dues";
            // Get the current time
            time_t currentTime = std::time(nullptr);

            // Convert the current time to a tm structure for local time
            tm *localTime = std::localtime(&currentTime);
            mktime(localTime);
            int days = 0;
            if (30 < localTime->tm_mday)
            {
                days = 30 - localTime->tm_mday;
                cout << "\n\n\tfine applied of " << days << " days ";
                cout << "\n\ttotal amount : " << days * 20;
            }
        }

        getline(inFile, line);
    }

    inFile.close();
    tempFile.close();

    remove("issued_books.txt");
    rename("temp.txt", "issued_books.txt");
    cout << "\n\n\tBook returned successfully ";

    Sleep(4000);
}
void add_member() // function to add members
{
    system("cls");

    cout << "\n\n\t---------------- Add Member ------------------";
    cout << "\n\tEnter your name : ";
    cin >> Member_Name;
    cout << "\n\tEnter your sername  : ";
    cin >> Member_Sername;
    cout << "\n\tEnter your Date of Birth   : ";
    cin >> Member_DOB;
start:
    cout << "\n\tEnter your mobile number    : ";
    cin >> Member_Mobile_No;
    if (Member_Mobile_No.length() < 10)
    {
        cout << "\n\tInvalid Mobile number !! Enter atleast 10 digit number.";
        goto start;
    }
    cout << "\n\tEnter your Gmail : ";
    cin >> Member_Gmail;
    cout << "\n\tEnter your Address       : ";
    cin >> Member_Address;
start1:
    cout << "\n\tEnter your Adhar Id       : ";
    cin >> Adhar_Id;
    if (Adhar_Id.length() != 12)
    {
        cout << "\n\tInvalid Adhar number !! Try Again.";
        goto start1;
    }
start2:
    cout << "\n\n\tEnter a strong password  : ";
    cin >> Member_Password;
    if (Adhar_Id.length() <= 8)
    {
        cout << "\n\tEnter minimum 8 character password";
        goto start2;
    }

    ofstream write_member_data;
    write_member_data.open("library_member.txt", ios::app);
    write_member_data << "\t" << Member_Name << " " << Member_Sername << "  :  " << Member_DOB << "  :  " << Member_Mobile_No << " : " << Member_Gmail << "  :  " << Member_Address << "  :  " << Adhar_Id << " : " << Member_Password << endl;
    write_member_data.close();
}
void view_member() // function to view members
{
    system("cls");
    cout << "\n\t------------- View Member ----------------";

    ifstream read_library_member;
    read_library_member.open("library_member.txt");

    int i = 1;
    while (read_library_member >> Member_Name >> Member_Sername >> s >> Member_DOB >> s >> Member_Mobile_No >> s >> Member_Gmail >> s >> Member_Address >> s >> Adhar_Id >> s >> Member_Password)
    {
        cout << "\n\n\t---------- User " << i << " ---------------" << endl;
        cout << "\n\t Name            :   " << Member_Name << " " << Member_Sername << endl;
        cout << "\n\t Date of Birth   :   " << Member_DOB << endl;
        cout << "\n\t Mobile no.      :   " << Member_Mobile_No << endl;
        cout << "\n\t Gmail           :   " << Member_Gmail << endl;
        cout << "\n\t Address         :   " << Member_Address << endl;
        cout << "\n\t Adhar ID        :   " << Adhar_Id << endl;
        cout << "\n\t Password        :   " << Member_Password << endl;
        i++;
    }
    Sleep(10000);
}
void user_menu() // function for user menu
{
    int i = 1;
    while (i)
    {
        Login log;
        int option;
        system("cls");
        cout << "\n\n\t------------ WELCOME TO THE USER MENU -------------\n\n";
        cout << "\t1. Add member\n\n\t2. view member \n\n\t3. Issue Book\n\n\t4. Return Book\n\n\t5. Exit\n\n\tEnter your choice : ";
        cin >> option;
        switch (option)
        {
        case 1:
            add_member();
            break;
        case 2:
            view_member();
            break;
        case 3:
            Issue_book();
            break;
        case 4:
            return_book();
            break;
        case 5:
            i = 0;
            break;

        default:
            system("cls");
            cout << "\tInvalid choice!! Try Again";
            Sleep(3000);
            break;
        }
    }
}
void view_book() // function to view book
{
    system("cls");
    cout << "\n\n\t-------------- View Book ------------------";

    ifstream read_library_books;
    read_library_books.open("library_all_books.txt");
    string tt, at, gn, ib;
    string line;
    int i = 1;
    while (read_library_books >> tt >> s >> at >> s >> gn >> s >> ib)
    {
        cout << "\n\n\t---------- Book  " << i << " ---------------" << endl;
        cout << "\n\t Book Title     :     " << tt << endl;
        cout << "\n\t Book Author    :     " << at << endl;
        cout << "\n\t Book Genre     :     " << gn << endl;
        cout << "\n\t Book ISBN      :     " << ib << endl;
        i++;
        getline(read_library_books, line);
    }
    Sleep(10000);
}
int main()
{
    int j = 1;
    while (j)
    {
        Login log;
        int option;
        system("cls");
        cout << "\n\n\t------------------ LIBRARY MANAGEMENT SYSTEM ------------------------";
        cout << "\n\n\t1. Login \n\n\t2. Registration\n\n\t3. EXit \n\n\tEnter your choice : ";
        cin >> option;
        switch (option)
        {
        case 1:
            k = login();
            if (k)
            {
                int i = 1;
                while (i)
                {
                    system("cls");
                    Book B;

                    cout << "\n\n         ---------- WELCOME TO THE LIBRARY SYSTEM -----------\n\n";
                    cout << "\t1. Add Book\n\n\t2. Remove Book\n\n\t3. Update Book\n\n\t4. Search Book\n\n\t5. User Menu\n\n\t6. View Book\n\n\t7. Exit\n\n\tEnter your choice : ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                        add_book(B);
                        break;
                    case 2:
                        remove_book();
                        break;
                    case 3:
                        update_book();
                        break;
                    case 4:
                        search_book();
                        break;
                    case 5:
                        user_menu();
                        break;
                    case 6:
                        view_book();
                        break;
                    case 7:
                        i = 0;
                        system("cls");
                        cout << "\n\n\n\t---------   THANK YOU fOR USING THIS APPLICATION   ----------";
                        Sleep(3000);
                        break;

                    default:
                        system("cls");
                        cout << "\n\n\tInvalid Choice !!! Try Again" << endl;
                        Sleep(3000);
                        break;
                    }
                }
            }
            break;
        case 2:
            registration(log);
            break;
        case 3:
            j = 0;
            break;
        default:
            cout << "\n\tInvalid Choice";
            break;
        }
    }

    return 0;
}