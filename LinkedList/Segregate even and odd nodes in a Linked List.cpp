#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *divide(Node *head)
{
    
    Node *tmp1 = head;
    Node *tmp2 = new Node(0);
    Node* ans = tmp2;

    // for even first
    while(tmp1){
        if(tmp1->data%2==0){
            Node *tmp = new Node(tmp1->data);
            tmp2->next = tmp;
            tmp2 = tmp2->next;
        }
        tmp1=tmp1->next;
    }

    //for odd 
    tmp1=head;
    while(tmp1){
        if(tmp1->data%2!=0){
            Node *tmp = new Node(tmp1->data);
            tmp2->next = tmp;
            tmp2 = tmp2->next;
        }
        tmp1=tmp1->next;
    }
    return ans->next;
}

int main()
{
}