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
    node* delNode->data = delNode->next->data;
    node* toDelete = delNode->next;
    delNode->next = delNode->next->next;
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

int main(){

}