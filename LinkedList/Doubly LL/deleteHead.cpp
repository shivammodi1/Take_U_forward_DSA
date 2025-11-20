#include<bits/stdc++.h>
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
};
// Function to delete the head node of a doubly linked list
Node *deleteHead(Node* head){
    if(!head){
        return NULL;
    }
    Node *tmp=head;
    head = head->next;
    if(head){
        head->prev = NULL;
    }
    delete tmp;
    return head;
}

// print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    cout << "Original list: ";
    printList(head);

    head = deleteHead(head);

    cout << "List after deleting head: ";
    printList(head);

    return 0;
}