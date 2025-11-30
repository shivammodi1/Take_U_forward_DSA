#include <bits/stdc++.h>
using namespace std;

// Node class representing a single digit in the linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// function to reverse the linked list
Node *reverseList(Node *node)
{
    Node *prev = nullptr;
    Node *current = node;

    while (current)
    {
        Node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// Function to add one to the number represented by the linked list
Node *addOne(Node *head)
{
    // Reverse the list to make least significant digit accessible
    head = reverseList(head);

    Node *current = head;
    // Initial carry since we want to add 1
    int carry = 1;

    // Traverse the list and add carry
    while (current && carry)
    {
        int sum = current->data + carry;
        current->data = sum % 10;
        carry = sum / 10;

        // If there's no next node and we still have a carry, append a new node
        if (!current->next && carry)
        {
            current->next = new Node(carry);
            carry = 0;
        }

        current = current->next;
    }

    // Reverse the list back to restore original order
    head = reverseList(head);
    return head;
}
