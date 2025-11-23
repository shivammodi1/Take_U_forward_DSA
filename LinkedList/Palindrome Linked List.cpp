#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};

class Solution {
  public:
    bool isPalindrome(Node *head) {
        if(!head || !head->next){
            return true;
        }
        
        vector<int> arr;
        Node* tmp=head;
        
        while(tmp){
            arr.push_back(tmp->data);
            tmp=tmp->next;
        }
        
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            if(arr[i]!=arr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};