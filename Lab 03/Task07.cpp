class TableNode {
public:
    int tableNumber;
    TableNode* next;
    TableNode(int num) : tableNumber(num), next(nullptr) {}
};

class CircularLinkedList {
public:
    TableNode* head;
    CircularLinkedList() : head(nullptr) {}

    void addTable(int tableNumber) {
        TableNode* newNode = new TableNode(tableNumber);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            TableNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (!head) return;
        TableNode* temp = head;
        do {
            cout << "Table " << temp->tableNumber << endl;
            temp = temp->next;
        } while (temp != head);
    }
};
