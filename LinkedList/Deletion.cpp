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

int main(){

}