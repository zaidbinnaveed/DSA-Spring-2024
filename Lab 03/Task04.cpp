void printReverse(Node* head) {
    if (head == nullptr) return;
    printReverse(head->next);
    cout << head->name << ": " << head->score << endl;
}
