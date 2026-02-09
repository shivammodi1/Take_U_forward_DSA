// Check for Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
// the difference btw the heights of the left and right subtrees of any node is not more than one.
// balance tree = abs(height of left subtree - height of right subtree) <= 1
#include <bits/stdc++.h>
using namespace std;


int height(TreeNode* root,bool &valid){
    if(!root){
        return 0;
    }

    int l = height(root->left, valid);
    int r = height(root->right, valid);

    if(abs(l - r) > 1){
        valid = 0;
    }

    return 1 + max(l, r);
}

bool isBalanced(TreeNode* root) {
    bool valid = 1;
    height(root, valid);
    return valid;
}


int main(){
    return 0;
}
