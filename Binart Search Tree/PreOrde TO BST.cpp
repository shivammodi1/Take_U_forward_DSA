#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Construct Binary Search Tree from Preorder Traversal
// Approach: Recursion
// 1. The root node range is between(-infinity, +infinity)
// 2. If the current node value is out of range then return NULL
//    - if(index==preorder.size() || lower>preorder[index] || upper<preorder[index]){
//        return NULL;
//    }
// 3. Create a new node with the current node value
// 4. The left child node range is between(-infinity, root node value)
// 5. The right child node range is between(root node value, +infinity)
// 6. Recursively call the function for left and right child nodes
// return the root node


class Solution {
public:
    TreeNode* BST(vector<int>& preorder, int &index,int lower,int upper){
        if(index==preorder.size() || lower>preorder[index] || upper<preorder[index]){
            return NULL;
        }
        //node
        TreeNode* root= new TreeNode(preorder[index++]);
        //lower ,root->val
        root->left = BST(preorder, index, lower, root->val);  
        //root->val ,upper
        root->right = BST(preorder, index, root->val, upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return BST(preorder,index,INT_MIN,INT_MAX);
    }
};