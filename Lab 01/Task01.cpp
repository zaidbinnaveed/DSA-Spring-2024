#include <iostream>
#include <string>
using namespace std;

class Task {
private:
    string description;
    string dueDate;

public:
    Task(const string& desc, const string& date) : description(desc), dueDate(date) {}
    void display() const {
        cout << "Task: " << description << ", Due Date: " << dueDate << endl;
    }
};

int main() {
    Task** tasks = nullptr;
    int taskCount = 0;

    while (true) {
        cout << "1. Add Task\n2. Display Tasks\n3. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter task description: ";
            string desc;
            cin.ignore();
            getline(cin, desc);
            cout << "Enter due date: ";
            string date;
            getline(cin, date);

            Task** newTasks = new Task*[taskCount + 1];
            for (int i = 0; i < taskCount; ++i)
                newTasks[i] = tasks[i];

            newTasks[taskCount] = new Task(desc, date);
            delete[] tasks;
            tasks = newTasks;
            taskCount++;

        } else if (choice == 2) {
            for (int i = 0; i < taskCount; ++i)
                tasks[i]->display();

        } else if (choice == 3) {
            for (int i = 0; i < taskCount; ++i)
                delete tasks[i];
            delete[] tasks;
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
