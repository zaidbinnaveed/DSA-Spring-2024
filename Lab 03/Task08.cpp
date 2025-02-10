class DoublyNode {
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyNode* head;
    DoublyNode* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteAtFront() {
        if (!head) return;
        DoublyNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    bool search(int val) {
        DoublyNode* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        DoublyNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
