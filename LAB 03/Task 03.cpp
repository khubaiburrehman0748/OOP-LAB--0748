#include <iostream>
using namespace std;

class Library {
private:
    struct Book {
        string title;
        bool borrowedBooks;
    };
    
    Book bookList[100];
    int bookCount = 0;

public:
    void addBook(string bookName) {
        if (bookCount < 100) {
            bookList[bookCount++] = {bookName, false};
        }
    }

    void lendBook(string bookName) {
        for (int i = 0; i < bookCount; i++) {
            if (bookList[i].title == bookName && !bookList[i].borrowedBooks) {
                bookList[i].borrowedBooks = true;
                cout << "Book borrowed: " << bookName << endl;
                return;
            }
        }
        cout << "Book not available: " << bookName << endl;
    }

    void returnBook(string bookName) {
        for (int i = 0; i < bookCount; i++) {
            if (bookList[i].title == bookName && bookList[i].borrowedBooks) {
                bookList[i].borrowedBooks = false;
                cout << "Book returned: " << bookName << endl;
                return;
            }
        }
        cout << "Book was not borrowed: " << bookName << endl;
    }

    void displayInventory() {
        cout << "\nLibrary Inventory:\n";
        for (int i = 0; i < bookCount; i++) {
            cout << bookList[i].title << " - " 
                 << (bookList[i].borrowedBooks ? "Borrowed" : "Available") << endl;
        }
    }
};

int main() {
    Library lib;
    lib.addBook("Book1");
    lib.addBook("Book2");
    lib.addBook("Book3");
    
    lib.lendBook("Book1");
    lib.lendBook("Book2");
    
    lib.returnBook("Book1");

    lib.displayInventory();

    return 0;
}
