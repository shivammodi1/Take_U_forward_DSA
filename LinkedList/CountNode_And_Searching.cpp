#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

// Count Nodes in Linked List
int countNodes(Node *head){
    int count = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}

// Search for a value in Linked List
bool searchInLinkedList(Node *head, int key){
    Node* tmp = head;
    while(tmp!=NULL){
        if(tmp->data == key){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

int main(){
    // Creating a simple linked list: 1 -> 2 -> 3 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Count nodes
    cout << "Number of nodes in the linked list: " << countNodes(head) << endl;

    // Search for values
    int keyToSearch = 2;
    if(searchInLinkedList(head, keyToSearch)){
        cout << keyToSearch << " found in the linked list." << endl;
    } else {
        cout << keyToSearch << " not found in the linked list." << endl;
    }

    keyToSearch = 5;
    if(searchInLinkedList(head, keyToSearch)){
        cout << keyToSearch << " found in the linked list." << endl;
    } else {
        cout << keyToSearch << " not found in the linked list." << endl;
    }

    return 0;
}