// Check for Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
// the difference btw the heights of the left and right subtrees of any node is not more than one.
// balance tree = abs(height of left subtree - height of right subtree) <= 1
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int Height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftH = Height(root->left);
    int rightH = Height(root->right);
    return max(leftH, rightH) + 1;
}

bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }

    int leftH = Height(root->left);
    int rightH = Height(root->right);

    if(abs(leftH - rightH) > 1){
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    return 0;
}
