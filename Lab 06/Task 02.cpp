#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int length(Node* head, int count = 0) {
    if (!head) return count;
    return length(head->next, count + 1);
}
