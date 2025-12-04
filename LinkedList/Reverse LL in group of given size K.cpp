#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Method 1: Brootforce approach
// Reverse linked list in groups of size k
// step1: store the linked list elements in an array
// step2: reverse the array in groups of size k
// step3: create a new linked list from the modified array
Node *reverseKGroup(Node *head, int k)
{
    if(!head){
        return NULL;
    }
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int n = arr.size();

    // if size of array and k is equal
    // reverse whole LL
    if(n==k){
        reverse(arr.begin(),arr.end());
        Node *newHead = new Node(-1);
        Node *curr = newHead;
        for(int i=0;i<n;i++){
            curr->next = new Node(arr[i]);
            curr = curr->next;
        }
        return newHead->next;
    }

    for(int i=0;i<n;i+=k){
        int end = i+k;
        if(end<n){
            reverse(arr.begin()+i,arr.begin()+end);
        }
        
    }
    Node *newHead = new Node(-1);
    Node *curr = newHead;
    for(int i=0;i<n;i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return newHead->next;
}

int main()
{
}