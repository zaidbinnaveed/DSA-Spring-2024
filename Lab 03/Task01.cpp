#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int score;
    Node* next;

    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void addFront(string name, int score) {
        Node* newNode = new Node(name, score);
        newNode->next = head;
        head = newNode;
    }

    void addTail(string name, int score) {
        Node* newNode = new Node(name, score);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void addAfter(string afterName, string name, int score) {
        Node* temp = head;
        while (temp && temp->name != afterName) temp = temp->next;
        if (temp) {
            Node* newNode = new Node(name, score);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void search(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << name << ": " << temp->score << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->name << ": " << temp->score << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    list.addFront("David", 95);
    list.addFront("Carol", 78);
    list.addFront("Bob", 85);
    list.addFront("Alice", 90);
    list.addFront("Eve", 88);
    list.addTail("Frank", 89);
    list.addAfter("Bob", "Grace", 92);
    list.search("Carol");
    list.display();
    return 0;
}
