#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {

        if (!head) return nullptr;   // If list is empty, return NULL

        Node *curr = head;           // Pointer to traverse the list

        while (curr && curr->next)
        {
            Node *next = curr->next; // Check nodes ahead for duplicates

            // Remove all nodes that have the same value as current node
            while (next && next->data == curr->data)
            {
                Node *del = next;    // Duplicate node to delete
                next = next->next;   // Move to next node
                delete del;          // Free memory of duplicate
            }

            curr->next = next;       // Connect current node to first non-duplicate

            if (next)
            {
                next->prev = curr;   // Update prev link only if next is not NULL
            }

            curr = curr->next;       // Move forward in the list
        }

        return head;                 // Return updated head
    }
};
