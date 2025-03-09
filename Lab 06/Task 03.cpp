#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool search(Node* head, int key) {
    if (!head) return false;
    if (head->data == key) return true;
    return search(head->next, key);
}
