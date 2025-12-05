#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// copy linked list with next and random pointer
Node* copyRandomList(Node* head) {
    if(!head){
        return NULL;
    }
    Node *temp = head;
   // step 1: copy node and insert next to original node to it
    while(temp){
       Node *newNode = new Node(temp->val);
       newNode->next = temp->next;
       temp->next = newNode;
       temp = newNode->next;
    };
    // step 2: if random pointer is not null then point the random pointer of copied node
    temp = head;
    while(temp){
        Node *Copy = temp->next;

        if(temp->random){
            Copy->random = temp->random->next; // temp->random store original but its next it is a copy so temp->random->next
        }else{
            Copy->random = NULL;
        }
        temp = temp->next->next;
    };

    // step 3: Now Separate the Copied Node from Original Node
    Node* original = head;
    Node* copy = head->next;
    Node* ans = head->next;
    while(original && copy){
        if(original->next){
            original->next = original->next->next;
        }
        if(copy->next){
            copy->next = copy->next->next;
        }
        original = original->next;
        copy = copy->next;
    }
    return ans;
}



int main(){
    return 0;
}