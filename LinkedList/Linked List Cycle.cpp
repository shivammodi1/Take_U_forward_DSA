#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

//method 1 using 2 pointer
bool detectLoop(node *head)
{
    if(!head){
        return NULL;
    }
    node* slow = head;
    node* fast = head;

    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;

}

//method 2 using map
// In map store node and their bool value present or not
// if node already present return true 
// return false

bool detectLoop(node* head){
    unordered_map<node*,bool> visit;
    node* tmp = head;
    while(tmp){
        // if node already present
        if(visit[tmp]==1){
            return true;
        }
        // In evry visit make it present at that node
        visit[tmp] = 1;
        tmp=tmp->next;
    }
    //after traversing there is no loop detected
    return false;
}