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

int lengthOfLoop(Node *head)
{
    if(!head){
        return NULL;
    }    

    Node* slow = head;
    Node* fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        // loop found
        if(slow==fast){
            int count=1;
            // jab tak fast ka next slow ke barabar na ho count++
            while(fast->next!=slow){
                count++;
                fast=fast->next;
            }
            return count;
        }
    }
    return 0;
}

int main()
{
}
