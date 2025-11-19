#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

// if particular node only needs to be deleted
void deleteNode(node* delNode){
    if (!delNode || !delNode->next) {
        // cannot delete if node is null or it's the last node
        return;
    }

    node* toDelete = delNode->next;
    delNode->data = toDelete->data;
    delNode->next = toDelete->next;
    delete toDelete;
}


// Function to delete the first node of the linked list
node* deleteAtFirst(node* head){
    if(!head){
        return NULL;
    }
    // if there is only one node
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    node *toDelete = head;
    head=head->next;
    delete toDelete;
    return head;
}

// Function to delete the last node of the linked list
node* deleteAtEnd(node* head){
    if(!head){
        return NULL;
    }
    node* tmp=head;
    // till we reach second last node
    while(tmp->next->next != NULL){
        tmp=tmp->next;
    }
    // now tmp points to second last node
    node* toDelete = tmp->next;
    tmp->next = NULL; // unlink the last node
    delete toDelete; // free memory
    return head;
}

// Function to delete a node at a given position (0-indexed)
node *deleteAtPosition(node* head, int pos){
    if(pos == 0){
        return deleteAtFirst(head);
    }
    node* tmp = head;
    for(int i=0; i<pos-1; i++){
        if(tmp == NULL || tmp->next == NULL){
            // position is out of bounds
            return head;
        }
        tmp = tmp->next;
    }
    node* toDelete = tmp->next;
    if(toDelete == NULL){
        // position is out of bounds
        return head;
    }
    tmp->next = toDelete->next;
    delete toDelete;
    return head;
}


int main(){
    // Example usage:
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);

    head = deleteAtFirst(head); // Deletes node with value 1
    head = deleteAtEnd(head);   // Deletes node with value 4
    head = deleteAtPosition(head, 0); // Deletes node with value 2

    // Print remaining list
    node* tmp = head;
    while(tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    return 0;
}