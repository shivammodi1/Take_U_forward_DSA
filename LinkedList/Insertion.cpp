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

// insert at first position
Node *insertAtFirst(Node *head, int val){
    Node* tmp = new Node(val);
    tmp->next = head;
    head=tmp;
    return head;
}

// insert at last position
Node *insertAtLast(Node* head,int val){
    Node* tmp = head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    Node* newNode = new Node(val);
    tmp->next=newNode;
    return head;
}

// insert at given position
Node* insertAtPosition(Node* head, int val, int pos){
    if(pos==0){
        return insertAtFirst(head,val);
    }
    Node* tmp = head;
    for(int i=0;i<pos-1;i++){
        if(tmp==NULL){
            cout<<"Position out of bounds"<<endl;
            return head;
        }
        tmp=tmp->next;
    }
    Node* newNode = new Node(val);
    newNode->next=tmp->next;
    tmp->next=newNode;
    return head;
}

int main(){

}