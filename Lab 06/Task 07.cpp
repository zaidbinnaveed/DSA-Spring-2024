#include <iostream>

using namespace std;

class Stack {
    int top, capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x) {
        if (isFull()) return;
        arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) return;
        top--;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }
};
