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

Node *addTwo(Node *head1, Node *head2)
{
    Node *res = new Node(0); // this will store resultant sum
    Node *tmp = res;
    int carry = 0; // to handle carry over

    while ((head1 || head2) || carry)
    {   
        // if head1 is not there create 0 to next to it for addition
        if (!head1)
        {
            head1 = new Node(0);
        }
        // if head2 is not there create 0 to next to it for addition
        if (!head2)
        {
            head2 = new Node(0);
        }
        // calculate sum of both nodes and carry
        int sum = head1->data + head2->data + carry;
        tmp->next = new Node(sum % 10); // create new node with sum%10
        carry = sum / 10; // update carry
        tmp = tmp->next; // move to next node
        head1 = head1->next; // move to next node
        head2 = head2->next; // move to next node
    }

    return res->next;
}

int main()
{
    Node *head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node *result = addTwo(head1, head2);

    while (result)
    {
        cout << result->data << " ";
        result = result->next;
    }
}