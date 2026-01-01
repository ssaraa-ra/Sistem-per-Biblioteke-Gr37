#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

// Struktura e librit
struct Book {
    int id;
    string title;
    string author;
};

Book books[MAX];
int countBooks = 0;

// Funksioni për të shtuar libra
void addBook() {
    if (countBooks >= MAX) {
        cout << "Biblioteka është e mbushur!\n";
        return;
    }

    cout << "\nShkruaj ID: ";
    cin >> books[countBooks].id;
    cin.ignore();

    cout << "Shkruaj titullin e librit: ";
    getline(cin, books[countBooks].title);

    cout << "Shkruaj autorin: ";
    getline(cin, books[countBooks].author);

    countBooks++;
    cout << "Libri u shtua me sukses!\n";
}

// Funksioni për të shfaqur librat
void displayBooks() {
    if (countBooks == 0) {
        cout << "Nuk ka libra për të shfaqur.\n";
        return;
    }

    cout << "\n--- Lista e Librave ---\n";
    for (int i = 0; i < countBooks; i++) {
        cout << "ID: " << books[i].id
             << ", Titulli: " << books[i].title
             << ", Autori: " << books[i].author << endl;
    }
}

// Funksioni për të kërkuar libër
void searchBook() {
    string searchTitle;
    cin.ignore(); // parandalon kalimin e input-it
    cout << "\nShkruaj titullin e librit që dëshiron të kërkosh: ";
    getline(cin, searchTitle);

    for (int i = 0; i < countBooks; i++) {
        if (books[i].title == searchTitle) {
            cout << "\nLibri u gjet!\n";
            cout << "ID: " << books[i].id
                 << ", Titulli: " << books[i].title
                 << ", Autori: " << books[i].author << endl;
            return;
        }
    }
    cout << "Libri nuk u gjet.\n";
}

// Funksioni për të fshirë libër
void deleteBook() {
    string deleteTitle;
    cin.ignore(); // parandalon kalimin e input-it
    cout << "\nShkruaj titullin e librit që dëshiron të fshish: ";
    getline(cin, deleteTitle);

    for (int i = 0; i < countBooks; i++) {
        if (books[i].title == deleteTitle) {
            for (int j = i; j < countBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            countBooks--;
            cout << "Libri u fshi me sukses.\n";
            return;
        }
    }
    cout << "Libri nuk u gjet.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== MENYJA E BIBLIOTEKES =====\n";
        cout << "1. Shto Liber\n";
        cout << "2. Shfaq Librat\n";
        cout << "3. Kerko Liber\n";
        cout << "4. Fshi Liber\n";
        cout << "5. Dil\n";
        cout << "Zgjedhja juaj: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: cout << "Programi u mbyll.\n"; break;
            default: cout << "Zgjedhje e pavlefshme. Provoni përsëri.\n";
        }
    } while (choice != 5);

    return 0;
}
