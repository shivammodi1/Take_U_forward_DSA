#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// array representation of doubly linked list
// [10, 20, 30]
// 10 <-> 20 <-> 30

node* arrayToDLL(vector<int> arr)
{
    if(arr.size()==0){
        return NULL;
    }

    node*head = new node(arr[0]);
    node*temp = head;
    for(int i=1;i<arr.size();i++){
        temp->next = new node(arr[i]);
        temp->next->prev = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    node* head = new node(10);
    head->next = new node(20);
    head->next->prev = head;
    head->next->next = new node(30);
    head->next->next->prev = head->next;
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    // array to DLL
    vector<int> arr = {1,2,3,4,5};
    node* head2 = arrayToDLL(arr);
    node* temp2 = head2;
    cout<<endl;

    while(temp2 != NULL){
        cout<<temp2->data<<" ";
        temp2 = temp2->next;
    }

    return 0;
}