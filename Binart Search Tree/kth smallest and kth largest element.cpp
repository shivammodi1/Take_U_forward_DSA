/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root,vector<int>&arr){
        if(!root){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        if(!root){
            return -1;
        }
        
        vector<int>arr;
        inorder(root,arr);
        if(k>arr.size()){
            return -1;
        }
        
        return arr[k-1];
        
    }

    int kthLargest(Node *root, int k) {
        // code here
        if(!root){
            return -1;
        }
        
        vector<int>arr;
        inorder(root,arr);
        if(k>arr.size()){
            return -1;
        }
        
        return arr[arr.size()-k];
        
    }
};