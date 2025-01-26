#include <iostream>
#include <cstring>
using namespace std;

class Dictionary {
private:
    char** words;
    char** definitions;
    int size;
    int capacity;

    void deepCopy(const Dictionary& other) {
        size = other.size;
        capacity = other.capacity;
        words = new char*[capacity];
        definitions = new char*[capacity];
        for (int i = 0; i < size; ++i) {
            words[i] = new char[strlen(other.words[i]) + 1];
            strcpy(words[i], other.words[i]);
            definitions[i] = new char[strlen(other.definitions[i]) + 1];
            strcpy(definitions[i], other.definitions[i]);
        }
    }

    void freeMemory() {
        for (int i = 0; i < size; ++i) {
            delete[] words[i];
            delete[] definitions[i];
        }
        delete[] words;
        delete[] definitions;
    }

public:
    Dictionary(int cap) : size(0), capacity(cap) {
        words = new char*[capacity];
        definitions = new char*[capacity];
    }

    ~Dictionary() {
        freeMemory();
    }

    Dictionary(const Dictionary& other) {
        deepCopy(other);
    }

    Dictionary& operator=(const Dictionary& other) {
        if (this != &other) {
            freeMemory();
            deepCopy(other);
        }
        return *this;
    }

    void addEntry(const char* word, const char* definition) {
        if (size < capacity) {
            words[size] = new char[strlen(word) + 1];
            strcpy(words[size], word);
            definitions[size] = new char[strlen(definition) + 1];
            strcpy(definitions[size], definition);
            size++;
        } else {
            cout << "Dictionary is full.\n";
        }
    }

    void printDictionary() const {
        for (int i = 0; i < size; ++i) {
            cout << words[i] << ": " << definitions[i] << endl;
        }
    }
};

int main() {
    Dictionary dict(5);
    dict.addEntry("apple", "A fruit");
    dict.addEntry("book", "A set of written or printed pages");
    dict.printDictionary();

    Dictionary dictCopy = dict;
    dictCopy.addEntry("cat", "A small domesticated carnivorous mammal");
    cout << "Original Dictionary:\n";
    dict.printDictionary();
    cout << "Copied Dictionary:\n";
    dictCopy.printDictionary();

    return 0;
}
