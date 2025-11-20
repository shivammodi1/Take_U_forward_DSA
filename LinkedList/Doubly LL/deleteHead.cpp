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

// delete last node of doubly linked list
Node* lastNodeDelete(Node* head){
    if(!head){
        return NULL;
    }

    // only 1 node
    if(!head->next){
        delete head;
        return NULL;
    }

    Node* tmp = head;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->prev->next = NULL;
    delete tmp;
    return head;
}

// Function to delete a node at a given position in a doubly linked list
Node *deleteAtPosition(Node* head, int pos){
    if(!head){
        return NULL;
    }

    // delete head
    if(pos == 0){
        return deleteHead(head);
    }

    Node* curr = head;
    for(int i=0; curr && i<pos; i++){
        curr = curr->next;
    }

    // if position is more than number of nodes
    if(!curr){
        return head;
    }

    // delete last node
    if(!curr->next){
        return lastNodeDelete(head);
    }

    // delete in between node
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
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