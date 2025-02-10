class TaskNode {
public:
    string task;
    TaskNode* next;
    TaskNode(string t) : task(t), next(nullptr) {}
};

class ToDoList {
public:
    TaskNode* head;
    ToDoList() : head(nullptr) {}

    void addFront(string task) {
        TaskNode* newTask = new TaskNode(task);
        newTask->next = head;
        head = newTask;
    }

    void addTail(string task) {
        TaskNode* newTask = new TaskNode(task);
        if (!head) {
            head = newTask;
        } else {
            TaskNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newTask;
        }
    }

    void deleteFromFront() {
        if (head) {
            TaskNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteFromTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        TaskNode* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (!head) return;
        if (position == 0) {
            deleteFromFront();
            return;
        }
        TaskNode* temp = head;
        for (int i = 0; temp && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp && temp->next) {
            TaskNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void display() {
        TaskNode* temp = head;
        while (temp) {
            cout << temp->task << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ToDoList list;
    list.addFront("Buy groceries");
    list.addFront("Finish a report");
    list.addFront("Go for a run");

    list.display();

    list.deleteFromFront();
    list.addTail("Call a friend");
    list.deleteFromTail();
    list.deleteAtPosition(0);

    list.display();

    return 0;
}
