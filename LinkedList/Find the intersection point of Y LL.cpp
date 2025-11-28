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

// method 1 using counting the length of both LLs
Node* getIntersectionNode(Node* headA,Node* headB){
    int countA = 0, countB = 0;
    Node* tempA = headA;
    Node* tempB = headB;

    while(tempA){
        countA++;
        tempA = tempA->next;
    }

    while(tempB){
        countB++;
        tempB = tempB->next;
    }

    if(countA > countB){
        int diff = countA - countB;
        while(diff){
            headA = headA->next;
            diff--;
        }
    }else{
        int diff = countB - countA;
        while(diff){
            headB = headB->next;
            diff--;
        }
    }
    while(headA && headB){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main(){}