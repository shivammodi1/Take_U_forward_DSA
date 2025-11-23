#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next=NULL;
    }
};

//Method 1
int getMiddle(node* head){
    if(!head){
        return NULL;
    }
    // step 1: count number of nodes
    // step 2: traverse till count/2
    int count = 0;
    node* tmp = head;
    while(tmp){
        count++;
        tmp=tmp->next;
    }

    int mid = count/2;
    tmp=head;
    while(mid--){
        tmp=tmp->next;
    }

    return tmp->data;
}


// Method 2 Slow and fast pointer
int getMid(node* head){
    if(!head){
        return NULL;
    }
    node* slow = head; // it will move 1x speed
    node* fast = head; // it will move 2x speed
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    // at the end fast is placed at end node 
    // and slow at mid node
    return slow->data;

}

int main(){

}