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

int main(){

}