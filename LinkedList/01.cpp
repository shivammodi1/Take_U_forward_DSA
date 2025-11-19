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

// Print Linked List
void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//Array to Linked List
Node* arrayToLinkedList(vector<int> arr){
    if(arr.size() == 0){
        return NULL;
    }

    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i=1; i<arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// LL to Array
vector<int> LLtoArray(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return arr;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    // Convert array to linked list
    Node* head = arrayToLinkedList(arr);
    printLinkedList(head);
    // Convert back to array
    vector<int> newArr = LLtoArray(head);
    for(int val : newArr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}