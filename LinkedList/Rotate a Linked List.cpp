// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Explanation:
// The list is rotated to the right by 2 places.
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
#include<bits/stdc++.h>
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

// this for rotating the linked list to the right by k places
Node* rotate(Node* head, int k){
    if(!head || k==0){
        return head;
    }
    // compute the length of linked list
    int count=0;
    Node*tmp = head;
    while(tmp){
        count++;
        tmp = tmp->next;
    }
    k=k%count; // in case k is greater than length of linked list
    if(k==0){
        return head;
    }
   
    count = count - k; // to find the new tail position
    Node* prev= NULL;
    Node* curr = head;
    while(count--){
        prev = curr;
        curr = curr->next;
    }
    //now curr is at new head position
    // and prev is at new tail position
    prev->next = NULL; // break the link
    tmp=curr;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = head; // link the old tail to old head
    return curr; // new head
}

// this for rotating the linked list to the left by k places
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if(!head || k==0){
            return head;
        }

        int count=0;
        Node* tmp = head;
        while(tmp){
            count++;
            tmp = tmp->next;
        }

        k = k % count;
        if(k == 0){
            return head;
        }

        // FIX: rotate left → break after k nodes
        count = k;

        Node* prev = NULL;
        Node* curr = head;

        while(count--){
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        tmp = curr;

        while(tmp->next){
            tmp = tmp->next;
        }

        tmp->next = head;

        return curr;
    }
};


int main(){
    return 0;
}