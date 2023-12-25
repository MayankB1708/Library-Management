#include<bits/stdc++.h>
using namespace std;

struct Book {
    string title;
    string author;
    int id;
};

void add(Book library[], int& count);
void display(const Book library[], int count);
void search(const Book library[], int count, const string& title);

int main() {
    const int MAX_BOOKS = 1000;
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add(library, count);
                break;
            case 2:
                display(library, count);
                break;
            case 3:
                {
                    string searchTitle;
                    cout << "Enter the title to search: ";
                    cin.ignore(); 
                    getline(cin, searchTitle);
                    search(library, count, searchTitle);
                }
                break;
            case 4:
                cout << "Exiting the program.\n Thank you";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void add(Book library[], int& count) {
    if (count < 1000) { 
        cout << "Enter book title: ";
        cin.ignore(); // Clear input buffer
        getline(cin, library[count].title);
        cout << "Enter book author: ";
        getline(cin, library[count].author);
        library[count].id = count + 1; 
        count++;
        cout << "Book added successfully.\n";
    } else {
        cout << "Library is full. Cannot add more books.\n";
    }
}

void display(const Book library[], int count) {
    if (count > 0) {
        cout << "\nBook List:\n";
        for (int i = 0; i < count; i++) {
            cout << "ID: " << library[i].id << "\n";
            cout << "Title: " << library[i].title << "\n";
            cout << "Author: " << library[i].author << "\n\n";
        }
    } else {
        cout << "No books in the library.\n";
    }
}

void search(const Book library[], int count, const string& title) {
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (library[i].title == title) {
            cout << "Book found:\n";
            cout << "ID: " << library[i].id << "\n";
            cout << "Title: " << library[i].title << "\n";
            cout << "Author: " << library[i].author << "\n\n";
            found = true;
            break; // 
        }
    }

    if (!found) {
        cout << "Book not found in the library.\n";
    }
}
