#include<iostream>
using namespace std;

const int MAX_ITEMS = 100;

// Abstract Base Class
class LibraryItem
{
private:
    char title[50];
    char author[50];
    char dueDate[20];
    int checkedOut;

protected:
    void setStatus(int s)
    {
        checkedOut = s;
    }

public:
    LibraryItem(char t[], char a[], char d[])
    {
        int i;

        for(i = 0; t[i] != '\0' && i < 49; i++)
            title[i] = t[i];
        title[i] = '\0';

        for(i = 0; a[i] != '\0' && i < 49; i++)
            author[i] = a[i];
        author[i] = '\0';

        for(i = 0; d[i] != '\0' && i < 19; i++)
            dueDate[i] = d[i];
        dueDate[i] = '\0';

        checkedOut = 0;
    }

    virtual ~LibraryItem() {}

    char* getTitle()
    {
        return title;
    }

    char* getAuthor()
    {
        return author;
    }

    char* getDueDate()
    {
        return dueDate;
    }

    int isCheckedOut()
    {
        return checkedOut;
    }

    void setTitle(char t[])
    {
        int i;
        for(i = 0; t[i] != '\0' && i < 49; i++)
            title[i] = t[i];
        title[i] = '\0';
    }

    void setAuthor(char a[])
    {
        int i;
        for(i = 0; a[i] != '\0' && i < 49; i++)
            author[i] = a[i];
        author[i] = '\0';
    }

    void setDueDate(char d[])
    {
        int i;
        for(i = 0; d[i] != '\0' && i < 19; i++)
            dueDate[i] = d[i];
        dueDate[i] = '\0';
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
};

// Book Class
class Book : public LibraryItem
{
private:
    char ISBN[20];

public:
    Book(char t[], char a[], char d[], char isbn[])
        : LibraryItem(t, a, d)
    {
        int i, digits = 0;

        for(i = 0; isbn[i] != '\0' && i < 19; i++)
        {
            if(isbn[i] >= '0' && isbn[i] <= '9')
                digits++;
            else if(isbn[i] != '-')
                throw "Invalid ISBN format";
        }

        if(digits != 10 && digits != 13)
            throw "ISBN must have 10 or 13 digits";

        for(i = 0; isbn[i] != '\0' && i < 19; i++)
            ISBN[i] = isbn[i];
        ISBN[i] = '\0';
    }

    void checkOut()
    {
        if(isCheckedOut())
            cout << "Book is already checked out.\n";
        else
        {
            setStatus(1);
            cout << "Book checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if(!isCheckedOut())
            cout << "Book was not checked out.\n";
        else
        {
            setStatus(0);
            cout << "Book returned successfully.\n";
        }
    }

    void displayDetails()
    {
        cout << "\nType: Book";
        cout << "\nTitle: " << getTitle();
        cout << "\nAuthor: " << getAuthor();
        cout << "\nDue Date: " << getDueDate();
        cout << "\nISBN: " << ISBN;
        cout << "\nStatus: "
             << (isCheckedOut() ? "Checked Out" : "Available");
        cout << "\n";
    }
};

// DVD Class
class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(char t[], char a[], char d[], int minutes)
        : LibraryItem(t, a, d)
    {
        if(minutes <= 0)
            throw "Duration must be positive";

        duration = minutes;
    }

    void checkOut()
    {
        if(isCheckedOut())
            cout << "DVD is already checked out.\n";
        else
        {
            setStatus(1);
            cout << "DVD checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if(!isCheckedOut())
            cout << "DVD was not checked out.\n";
        else
        {
            setStatus(0);
            cout << "DVD returned successfully.\n";
        }
    }

    void displayDetails()
    {
        cout << "\nType: DVD";
        cout << "\nTitle: " << getTitle();
        cout << "\nAuthor: " << getAuthor();
        cout << "\nDue Date: " << getDueDate();
        cout << "\nDuration: " << duration << " minutes";
        cout << "\nStatus: "
             << (isCheckedOut() ? "Checked Out" : "Available");
        cout << "\n";
    }
};

// Magazine Class
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(char t[], char a[], char d[], int issue)
        : LibraryItem(t, a, d)
    {
        if(issue <= 0)
            throw "Issue number must be positive";

        issueNumber = issue;
    }

    void checkOut()
    {
        if(isCheckedOut())
            cout << "Magazine is already checked out.\n";
        else
        {
            setStatus(1);
            cout << "Magazine checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if(!isCheckedOut())
            cout << "Magazine was not checked out.\n";
        else
        {
            setStatus(0);
            cout << "Magazine returned successfully.\n";
        }
    }

    void displayDetails()
    {
        cout << "\nType: Magazine";
        cout << "\nTitle: " << getTitle();
        cout << "\nAuthor: " << getAuthor();
        cout << "\nDue Date: " << getDueDate();
        cout << "\nIssue Number: " << issueNumber;
        cout << "\nStatus: "
             << (isCheckedOut() ? "Checked Out" : "Available");
        cout << "\n";
    }
};

// Main Function
int main()
{
    LibraryItem* items[MAX_ITEMS] = {NULL};
    int count = 0;
    int choice, number, i, found;

    char title[50], author[50], dueDate[20], isbn[20];

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Search Item\n";
        cout << "6. Check Out Item\n";
        cout << "7. Return Item\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        try
        {
            if(!(cin >> choice))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw "Enter a valid number";
            }

            cin.ignore(10000, '\n');

            if(choice == 8)
                break;

            if(choice < 1 || choice > 8)
                throw "Invalid menu choice";

            if(choice >= 1 && choice <= 3)
            {
                if(count >= MAX_ITEMS)
                    throw "Library is full";

                cout << "Enter title: ";
                cin.getline(title, 50);

                if(title[0] == '\0')
                    throw "Title cannot be empty";

                cout << "Enter author: ";
                cin.getline(author, 50);

                if(author[0] == '\0')
                    throw "Author cannot be empty";

                cout << "Enter due date: ";
                cin.getline(dueDate, 20);

                if(dueDate[0] == '\0')
                    throw "Due date cannot be empty";

                if(choice == 1)
                {
                    cout << "Enter ISBN (10 or 13 digits): ";
                    cin.getline(isbn, 20);

                    items[count] =
                        new Book(title, author, dueDate, isbn);
                }
                else if(choice == 2)
                {
                    int minutes;

                    cout << "Enter duration in minutes: ";

                    if(!(cin >> minutes))
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw "Invalid duration";
                    }

                    cin.ignore(10000, '\n');

                    items[count] =
                        new DVD(title, author, dueDate, minutes);
                }
                else
                {
                    int issue;

                    cout << "Enter issue number: ";

                    if(!(cin >> issue))
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw "Invalid issue number";
                    }

                    cin.ignore(10000, '\n');

                    items[count] =
                        new Magazine(title, author, dueDate, issue);
                }

                count++;
                cout << "Item added successfully.\n";
            }

            else if(choice == 4)
            {
                if(count == 0)
                    cout << "Library is empty.\n";

                for(i = 0; i < count; i++)
                {
                    cout << "\nItem Number: " << i + 1 << "\n";
                    items[i]->displayDetails();
                }
            }

            else if(choice == 5)
            {
                cout << "Enter title to search: ";
                cin.getline(title, 50);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(strcmp(items[i]->getTitle(), title) == 0)
                    {
                        items[i]->displayDetails();
                        found = 1;
                    }
                }

                if(!found)
                    cout << "Item not found.\n";
            }

            else if(choice == 6 || choice == 7)
            {
                if(count == 0)
                    throw "Library is empty";

                cout << "Enter item number (1 to "
                     << count << "): ";

                if(!(cin >> number))
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw "Invalid item number";
                }

                cin.ignore(10000, '\n');

                if(number < 1 || number > count)
                    throw "Invalid item number";

                if(choice == 6)
                    items[number - 1]->checkOut();
                else
                    items[number - 1]->returnItem();
            }
        }
        catch(const char* error)
        {
            cout << "Error: " << error << "\n";
        }
        catch(...)
        {
            cout << "Unknown error occurred.\n";
        }

    } while(true);

    for(i = 0; i < count; i++)
    {
        delete items[i];
        items[i] = NULL;
    }

    cout << "Thank you for using the Library Management System!\n";

    return 0;
}
