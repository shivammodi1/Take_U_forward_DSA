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

Node *sortLinkedList(Node *head)
{
    if (!head || !head->next)
        return head;

    vector<int> values;
    Node *temp = head;
    while (temp)
    {
        values.push_back(temp->data);
        temp = temp->next;
    }

    sort(values.begin(), values.end());

    temp = head;
    int index = 0;
    while (temp)
    {
        temp->data = values[index++];
        temp = temp->next;
    }

    return head;
}

int main()
{
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    head = sortLinkedList(head);

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}

