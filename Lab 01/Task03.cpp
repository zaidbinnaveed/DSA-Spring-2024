#include <iostream>
#include <cstring>
using namespace std;

class Document {
private:
    char* content;

public:
    Document(const char* text = "") {
        content = new char[strlen(text) + 1];
        strcpy(content, text);
    }

    ~Document() {
        delete[] content;
    }

    Document(const Document& other) {
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
    }

    Document& operator=(const Document& other) {
        if (this != &other) {
            delete[] content;
            content = new char[strlen(other.content) + 1];
            strcpy(content, other.content);
        }
        return *this;
    }

    void setContent(const char* text) {
        delete[] content;
        content = new char[strlen(text) + 1];
        strcpy(content, text);
    }

    void displayContent() const {
        cout << "Document Content: " << content << endl;
    }
};

int main() {
    Document doc1("Original Document");
    doc1.displayContent();

    Document doc2 = doc1;
    doc2.displayContent();

    Document doc3("Temporary Document");
    doc3.displayContent();

    doc3 = doc1; 
    doc3.displayContent();

    doc1.setContent("Modified Document");
    doc1.displayContent();

    doc2.displayContent();
    doc3.displayContent();

    return 0;
}
