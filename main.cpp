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

// Funksioni per te shtuar nje liber
void addBook() {
    if (countBooks >= MAX) {
        cout << "Biblioteka eshte e mbushur!\n";
        return;
    }

    cout << "\n--- SHTO LIBER TE RI ---\n";

    cout << "Shkruaj ID: ";
    cin >> books[countBooks].id;
    cin.ignore();

    cout << "Shkruaj titullin e librit: ";
    getline(cin, books[countBooks].title);

    cout << "Shkruaj autorin: ";
    getline(cin, books[countBooks].author);

    countBooks++;
    cout << "Libri u shtua me sukses!\n";
}

// Funksioni per te shfaqur librat
void displayBooks() {
    if (countBooks == 0) {
        cout << "Nuk ka libra per te shfaqur.\n";
        return;
    }

    cout << "\n========== LISTA E LIBRAVE ==========\n";
    for (int i = 0; i < countBooks; i++) {
        cout << "------------------------------------\n";
        cout << "ID: " << books[i].id << endl;
        cout << "Titulli: " << books[i].title << endl;
        cout << "Autori: " << books[i].author << endl;
    }
    cout << "------------------------------------\n";
}

// Funksioni per te kerkuar liber
void searchBook() {
    string searchTitle;
    cout << "\n--- KERKO LIBER ---\n";
    cout << "Shkruaj titullin e librit: ";
    getline(cin, searchTitle);

    for (int i = 0; i < countBooks; i++) {
        if (books[i].title == searchTitle) {
            cout << "Libri u gjet!\n";
            cout << "ID: " << books[i].id << endl;
            cout << "Titulli: " << books[i].title << endl;
            cout << "Autori: " << books[i].author << endl;
            return;
        }
    }
    cout << "Libri nuk u gjet.\n";
}

// Funksioni per te fshire liber
void deleteBook() {
    string deleteTitle;
    cout << "\n--- FSHI LIBER ---\n";
    cout << "Shkruaj titullin e librit: ";
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

    cout << "=====================================\n";
    cout << "     SISTEMI I MENAXHIMIT TE LIBRAVE  \n";
    cout << "=====================================\n";

    do {
        cout << "\n========== MENYJA E BIBLIOTEKES ==========\n";
        cout << " [1] Shto Liber\n";
        cout << " [2] Shfaq Librat\n";
        cout << " [3] Kerko Liber\n";
        cout << " [4] Fshi Liber\n";
        cout << " [5] Dil\n";
        cout << "-----------------------------------------\n";
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
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                cout << "\nProgrami u mbyll. Faleminderit!\n";
                break;
            default:
                cout << "Zgjedhje e pavlefshme.\n";
        }

        if (choice != 5) {
            cout << "\nShtyp ENTER per te vazhduar...";
            cin.get();
        }

    } while (choice != 5);

    return 0;
}
