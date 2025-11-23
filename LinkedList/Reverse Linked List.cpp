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

node* reverseList(node *head){
    if(!head){
        return NULL;
    }

    node* pre=NULL;
    node* cur=head;
    node* fur=head->next;

    while(cur){
        cur->next = pre; // reverse link
        pre = cur; // move pre
        cur = fur; // move current pointer
        if(fur){ 
            // move fur pointer if fur is exists
            fur = fur->next;
        }
    }
    return pre;
}

int main(){

}