// Input:
// 2<->2<->10<->8<->4<->2<->5<->2
// 2
// Output:
// 10<->8<->4<->5
// Explanation:
// All Occurences of 2 have been deleted.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

void deleteAllOccurOfX(struct Node **headref, int x)
{
    Node *curr = *headref;
    Node *next;

    while (curr)
    {

        // agar current node ka data x hai → delete karna hai
        if (curr->data == x)
        {

            next = curr->next;

            // case 1: node head hai
            if (curr == *headref)
            {
                *headref = next; // head ko aage move karo
                if (next)
                    next->prev = NULL; // new head ka prev NULL
                delete curr;           // purana head delete
                curr = next;           // aage badho
                continue;              // niche wali deletion skip karo
            }

            // case 2: middle ya last node delete
            if (curr->prev)
                curr->prev->next = curr->next; // previous ka next adjust
            if (curr->next)
                curr->next->prev = curr->prev; // next ka prev adjust

            delete curr; // node delete
            curr = next; // aage move
        }
        else
        {
            curr = curr->next; // agar match nahi karta → next node pe jao
        }
    }
}
