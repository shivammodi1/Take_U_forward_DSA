#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *deleteMid(Node *head)
{
    if (!head || !head->next) // single node or empty list
        return NULL;

    int count = 0;
    Node *tmp = head;

    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }

    int mid = count / 2;

    tmp = head;
    Node *prev = NULL;

    for (int i = 0; i < mid; i++)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    prev->next = tmp->next;
    delete tmp;
    return head;
}

// method 2 using slow fast pointer
Node *deleteMid(Node *head)
{
    if (!head || !head->next) // single node or empty list
        return NULL;

    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (!fast && !fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow is now middle node
    prev->next = slow->next;
    delete slow;

    return head;
}