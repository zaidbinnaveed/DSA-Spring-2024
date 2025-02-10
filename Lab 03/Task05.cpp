void sortList(Node* head) {
    if (!head) return;
    Node* i = head;
    while (i) {
        Node* j = i->next;
        while (j) {
            if (i->score > j->score) {
                swap(i->score, j->score);
                swap(i->name, j->name);
            }
            j = j->next;
        }
        i = i->next;
    }
}
