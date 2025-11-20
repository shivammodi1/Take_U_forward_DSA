#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
}

Node* reverseDLL(Node* head) {
    if (!head) return NULL;

    Node* curr = head;
    Node* tmp = NULL;

    // Traverse and swap next and prev for every node.
    // 'head' is updated to the most recently processed node — final becomes new head.
    while (curr) {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        head = curr;           // candidate for new head
        curr = curr->prev;     // move to original next (since we swapped)
    }
    return head;
}

// helper to insert at tail (for building test lists)
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* t = head;
    while (t->next) t = t->next;
    t->next = newNode;
    newNode->prev = t;
    return head;
}

void printForward(Node* head) {
    Node* t = head;
    while (t) {
        cout << t->data;
        if (t->next) cout << " <-> ";
        t = t->next;
    }
    cout << '\n';
}

void printBackward(Node* head) {
    if (!head) { cout << '\n'; return; }
    Node* t = head;
    while (t->next) t = t->next; // go to tail
    while (t) {
        cout << t->data;
        if (t->prev) cout << " <-> ";
        t = t->prev;
    }
    cout << '\n';
}

int main() {
    Node* head = NULL;
    head = insertTail(head, 1);
    head = insertTail(head, 2);
    head = insertTail(head, 3);
    head = insertTail(head, 4);

    cout << "Original forward: ";
    printForward(head);
    cout << "Original backward: ";
    printBackward(head);

    head = reverseDLL(head);

    cout << "Reversed forward: ";
    printForward(head);
    cout << "Reversed backward: ";
    printBackward(head);

    return 0;
}
