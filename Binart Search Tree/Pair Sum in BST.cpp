#include<bits/stdc++.h>
using namespace std;

/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Pair sum in BST
// Appraoch:
//1. Do an inorder traversal and store the elements in a vector.
//2. Use two pointer approach to find if there is a pair with given sum in the vector.
// Time Complexity: O(N) for inorder traversal + O(N) for two pointer approach = O(N)
// Space Complexity: O(N) for storing the elements in the vector.

class Solution {
  public:
    
    void Inorder(Node* root, vector<int>& arr){
        if(!root){
            return;
        }
        Inorder(root->left,arr);
        arr.push_back(root->data);
        Inorder(root->right,arr);
    }
    
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int>arr;
        Inorder(root,arr);
        
        int st=0;
        int end=arr.size()-1;
        
        while(st<end){
            int sum=arr[st]+arr[end];
            if(sum==target){
                return true;
            }else if(sum>target){
                end--;
            }else{
                st++;
            }
        }
        return false;
    }
};