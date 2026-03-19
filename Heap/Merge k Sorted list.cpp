#include<bits/stdc++.h>
using namespace std;

/*
    # Merge K Sorted Lists (Using Your Approach)

    - Sabhi linked lists ke elements ko min heap me daalenge
    - Fir heap se nikal ke sorted linked list banayenge
*/

// Node definition
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {

        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = arr.size();

        // step 1: push all elements into heap
        for(int i = 0; i < n; i++){
            Node* tmp = arr[i];
            while(tmp){
                pq.push(tmp->data);
                tmp = tmp->next;
            }
        }

        // step 2: create new sorted list
        Node* ans = new Node(-1);
        Node* temp = ans;

        while(!pq.empty()){
            Node* node = new Node(pq.top());
            temp->next = node;
            temp = temp->next;
            pq.pop();
        }

        return ans->next;
    }
};

int main(){
    // You can create test linked lists here if needed
    return 0;
}