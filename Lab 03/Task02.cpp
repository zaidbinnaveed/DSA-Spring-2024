class BookNode {
public:
    string title;
    BookNode* next;
    BookNode(string t) : title(t), next(nullptr) {}
};

class LibraryCatalog {
public:
    BookNode* head;
    LibraryCatalog() : head(nullptr) {}

    void addBook(string title) {
        BookNode* newBook = new BookNode(title);
        if (!head) {
            head = newBook;
        } else {
            BookNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
    }

    void deleteFromFront() {
        if (head) {
            BookNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    BookNode* searchByTitle(string title) {
        BookNode* temp = head;
        while (temp) {
            if (temp->title == title) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    BookNode* searchByPosition(int position) {
        BookNode* temp = head;
        int count = 0;
        while (temp) {
            if (count == position) {
                return temp;
            }
            count++;
            temp = temp->next;
        }
        return nullptr;
    }

    void display() {
        BookNode* temp = head;
        while (temp) {
            cout << temp->title << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LibraryCatalog catalog;
    catalog.addBook("The Catcher in the Rye");
    catalog.addBook("To Kill a Mockingbird");
    catalog.addBook("1984");

    catalog.display();

    BookNode* foundBook = catalog.searchByTitle("1984");
    if (foundBook) {
        cout << "Found book: " << foundBook->title << endl;
    }

    BookNode* bookAtPosition = catalog.searchByPosition(1);
    if (bookAtPosition) {
        cout << "Book at position 1: " << bookAtPosition->title << endl;
    }

    catalog.deleteFromFront();
    catalog.display();

    return 0;
}
