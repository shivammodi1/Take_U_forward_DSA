#include<bits/stdc++.h>
using namespace std;

// To check it is BST or not

// Method 1: 
// 1. using inorder traversal -> it should be in sorted order

// Method 2:
// 1. using recursion
// 2. The root node range is between(-infinity, +infinity)
// 3. The left child node range is between(-infinity, root node value)
// 4. The right child node range is between(root node value, +infinity)
// 5. if any node value is out of range then it is not a BST

bool isBST(Node* root, int mini,int maxi){
    if(!root){
        return true;
    }

    if(root->data >= mini && root->data <= maxi){
        bool left = isBST(root->left, mini, root->data);
        bool right = isBST(root->right, root->data, maxi);
        return left && right;
    }
    else{
        return false;
    }

}

bool validateBST(Node* root){
    return isBST(root, INT_MIN, INT_MAX);
}


int main(){
    return 0;
}