#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

// Struktura per librin
struct Book {
    int id;
    string title;
    string author;
};

Book books[MAX];
int countBooks = 0;

// Funksioni per shtimin e nje libri
void addBook() {
    if (countBooks >= MAX) {
        cout << "Biblioteka eshte plot.\n";
        return;
    }

    cout << "Shkruaj ID e librit: ";
    cin >> books[countBooks].id;
    cin.ignore();

    cout << "Shkruaj titullin e librit: ";
    getline(cin, books[countBooks].title);

    cout << "Shkruaj autorin e librit: ";
    getline(cin, books[countBooks].author);

    countBooks++;
    cout << "Libri u shtua me sukses!\n";
}

// Funksioni per shfaqjen e librave
void displayBooks() {
    if (countBooks == 0) {
        cout << "Nuk ka libra per te shfaqur.\n";
        return;
    }

    cout << "\n--- Lista e Librave ---\n";
    for (int i = 0; i < countBooks; i++) {
        cout << "ID: " << books[i].id
             << ", Titulli: " << books[i].title
             << ", Autori: " << books[i].author << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== MENYJA E BIBLIOTEKES =====\n";
        cout << "1. Shto Liber\n";
        cout << "2. Shfaq Librat\n";
        cout << "3. Dil\n";
        cout << "Zgjedhja juaj: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            cout << "Programi u mbyll.\n";
            break;
        default:
            cout << "Zgjedhje e pavlefshme.\n";
        }
    } while (choice != 3);

    return 0;
}
