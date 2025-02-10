void concatenate(Node* &head1, Node* head2) {
    if (!head1) {
        head1 = head2;
    } else {
        Node* temp = head1;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}
