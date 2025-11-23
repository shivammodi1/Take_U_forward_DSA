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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
        return NULL;
    }

    // using slow fast pointer method
    ListNode* slow=head;
    ListNode* fast=head;
    
    while(slow && fast && fast->next){
        slow=slow->next; // 1x speed
        fast=fast->next->next; // 2x speed
        // loop detected
        if(slow==fast){
            slow=head; // now placed slow at head

            while(slow!=fast){
                //now movw both pointer are 1x speed 
                slow=slow->next; 
                fast=fast->next;
            }
            return slow;
        }
    }

    return NULL; // no loop detetced
    }
};