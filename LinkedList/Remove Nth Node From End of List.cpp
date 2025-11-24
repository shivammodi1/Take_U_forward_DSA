#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* getKthFromLast(Node *head, int k)
{
    // agar list hi empty hai
    if(!head){
        return NULL;
    }

    // agar sirf 1 node hai aur hume last se 1 node delete karni hai
    if(!head->next && k==1){
        return NULL;
    }

    // pehle total nodes count karenge
    Node* tmp=head;
    int count=0;
    while(tmp){
        count++;
        tmp=tmp->next;
    }

    // delete karne wali node ka index head se nikalna
    tmp=head;
    count = count - k;

    // agar delete karne wala element head hi hai
    if(count == 0){
        Node *del = head;
        head=head->next;   // head ko aage badhaya
        delete del;         // purana head delete
        return head;        
    }
    
    Node* prev = NULL;

    // jis node ko delete karna hai waha tak ja rahe
    while(count--){
        prev = tmp;
        tmp=tmp->next;
    }

    // node ko skip karke delete kar diya
    prev->next = tmp->next;
    delete tmp;

    return head;
}
