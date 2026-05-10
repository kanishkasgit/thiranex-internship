#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
private:
    int bookId;
    string title;
    string author;
    bool issued;

public:
    Book(int id, string t, string a)
    {
        bookId = id;
        title = t;
        author = a;
        issued = false;
    }

    int getBookId()
    {
        return bookId;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    bool isIssued()
    {
        return issued;
    }

    void issueBook()
    {
        issued = true;
    }

    void returnBook()
    {
        issued = false;
    }

    void displayBook()
    {
        cout << "\nBook ID      : " << bookId << endl;
        cout << "Book Title   : " << title << endl;
        cout << "Author Name  : " << author << endl;

        if (issued)
            cout << "Status       : Issued" << endl;
        else
            cout << "Status       : Available" << endl;
    }
};

class Member
{
private:
    int memberId;
    string memberName;

public:
    Member(int id, string name)
    {
        memberId = id;
        memberName = name;
    }

    void displayMember()
    {
        cout << "Member ID    : " << memberId << endl;
        cout << "Member Name  : " << memberName << endl;
    }
};

vector<Book> books;
vector<Member> members;

void addBook()
{
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));

    cout << "\nBook Added Successfully!\n";
}

void addMember()
{
    int id;
    string name;

    cout << "Enter Member ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));

    cout << "\nMember Added Successfully!\n";
}

void displayBooks()
{
    if (books.empty())
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    cout << "\n========== BOOK LIST ==========\n";

    for (int i = 0; i < books.size(); i++)
    {
        books[i].displayBook();
        cout << "-----------------------------" << endl;
    }
}

void searchByTitle()
{
    string title;
    bool found = false;

    cin.ignore();

    cout << "Enter Book Title to Search: ";
    getline(cin, title);

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle() == title)
        {
            cout << "\nBook Found!\n";
            books[i].displayBook();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nBook Not Found!\n";
    }
}

void searchByAuthor()
{
    string author;
    bool found = false;

    cin.ignore();

    cout << "Enter Author Name to Search: ";
    getline(cin, author);

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getAuthor() == author)
        {
            cout << "\nBook Found!\n";
            books[i].displayBook();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo Books Found by this Author!\n";
    }
}

void issueBook()
{
    int id;
    bool found = false;

    cout << "Enter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getBookId() == id)
        {
            found = true;

            if (books[i].isIssued())
            {
                cout << "\nBook Already Issued!\n";
            }
            else
            {
                books[i].issueBook();
                cout << "\nBook Issued Successfully!\n";
            }
        }
    }

    if (!found)
    {
        cout << "\nBook ID Not Found!\n";
    }
}

void returnBook()
{
    int id;
    bool found = false;

    cout << "Enter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getBookId() == id)
        {
            found = true;

            if (!books[i].isIssued())
            {
                cout << "\nBook Was Not Issued!\n";
            }
            else
            {
                books[i].returnBook();
                cout << "\nBook Returned Successfully!\n";
            }
        }
    }

    if (!found)
    {
        cout << "\nBook ID Not Found!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n======================================";
        cout << "\n     LIBRARY MANAGEMENT SYSTEM";
        cout << "\n======================================";
        cout << "\n1. Add Book";
        cout << "\n2. Add Member";
        cout << "\n3. Display Books";
        cout << "\n4. Search Book by Title";
        cout << "\n5. Search Book by Author";
        cout << "\n6. Issue Book";
        cout << "\n7. Return Book";
        cout << "\n8. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            addMember();
            break;

        case 3:
            displayBooks();
            break;

        case 4:
            searchByTitle();
            break;

        case 5:
            searchByAuthor();
            break;

        case 6:
            issueBook();
            break;

        case 7:
            returnBook();
            break;

        case 8:
            cout << "\nThank You for Using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 8);

    return 0;
}
