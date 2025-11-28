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
// time complexity: O(N+M)
// space complexity: O(1)
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


// method 2
// optimal approach without calculating lengths
// idea is to traverse both LLs simultaneously
// when any pointer reaches end of LL, redirect it to head of other LL
// this will equalize the path length for both pointers
// they will meet at intersection point or end(NULL) if no intersection exists 
// time complexity: O(N+M)
// space complexity: O(1)
Node* getIntersectionNodeOptimal(Node* A,Node *B){
    if(!A || !B){
        return NULL;
    }

    Node* ptr1 = A;
    Node* ptr2 = B;
    while(ptr1 != ptr2){
        if(!ptr1){
            ptr1 = B;
        }else{
            ptr1 = ptr1->next;
        }

        if(!ptr2){
            ptr2 = A;
        }else{
            ptr2 = ptr2->next;
        }
    }
    return ptr1;
}

int main(){}