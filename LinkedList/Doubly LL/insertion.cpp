#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list (forward direction)
    Node* next;     
    // Pointer to the previous node in the list (backward direction)
    Node* back;     

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node
        prev->next = temp; 
         // Move 'prev' to the newly created node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

 


// Function to insert a new node with value 'k' at the end of the doubly linked list
Node* insertAtTail(Node* head, int k) {
    // Create a new node with data 'k'
    Node* newNode = new Node(k);

    // If the doubly linked list is empty, set 'head' to the new node
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the end of the doubly linked list
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Connect the new node to the last node in the list
    tail->next = newNode;
    newNode->back = tail;

    return head;
}


// insert at the head of doubly linked list
Node* insertAtHead(Node* head, int k) {
    // Create a new node with data 'k'
    Node* newNode = new Node(k);

    // If the doubly linked list is empty, set 'head' to the new node
    if (head == nullptr) {
        return newNode;
    }

    // Connect the new node to the current head
    newNode->next = head;
    head->back = newNode;

    // Update head to point to the new node
    return newNode;
}

// Main function to demonstrate insertion in doubly linked list
Node* atAnyPosition(Node* head, int pos, int k) {
    // If inserting at the head (position 0)
    if (pos == 0) {
        return insertAtHead(head, k);
    }

    // Create a new node with data 'k'
    Node* newNode = new Node(k);
    Node* curr = head;

    // Traverse to the position just before where the new node will be inserted
    for (int i = 0; curr != nullptr && i < pos - 1; i++) {
        curr = curr->next;
    }

    // If the current node is null, position is out of bounds; return original head
    if (curr == nullptr) {
        return head;
    }

    // Insert the new node at the specified position
    newNode->next = curr->next;
    newNode->back = curr;

    if (curr->next != nullptr) {
        curr->next->back = newNode;
    }
    curr->next = newNode;

    return head;
}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

cout << "Doubly Linked List Initially: " << endl;
    print(head);


    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
     // Insert a node with value 10 at the end
    head = insertAtTail(head, 10);
    print(head);

    return 0;
}