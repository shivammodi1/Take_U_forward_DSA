#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node *sort012(Node *head){
    // Dummy node created first store anything 
    // just to initialize the next pointers
    // after travers in LL first for 0s
    // then for 1s and then for 2s
    Node *dummy = new Node(-1);
    Node *ans = dummy;
    // First traversing for 0s
    Node *temp = head;
    while(temp){
        if(temp->data == 0){
            dummy->next = new Node(0);
            dummy = dummy->next;
        }
        temp = temp->next;
    }
    // Then traversing for 1s
    temp = head;
    while(temp){
        if(temp->data == 1){
            dummy->next = new Node(1);
            dummy = dummy->next;
        }
        temp = temp->next;
    }
    // Finally traversing for 2s
    temp = head;
    while(temp){
        if(temp->data == 2){
            dummy->next = new Node(2);
            dummy = dummy->next;
        }
        temp = temp->next;
    }
    return ans->next;
    
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    head = sort012(head);

    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}