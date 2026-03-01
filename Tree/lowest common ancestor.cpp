//  Lowest Common Ancestor of a Binary Tree
// example:- LCA(4,7)  tree:-    1
//                             /   \
//                            2     3
//                           / \
//                          4   5
//                         /   / \
//                        6   7   8
// Output: 2

// Approach:-
//1. If the root is NULL, return NULL.
//2. If the root's data matches either p or q, return the root.
//3. Recursively search for p and q in the left and right subtrees.
//4. If both left and right recursive calls return non-NULL, it means p and q are found in different subtrees, so return the current root as the LCA.


#include<bits/stdc++.h>
using namespace std;


Node* lowestCommonAncestor(Node* root,int p,int q){
    if(root==NULL) return NULL;
    if(root->data==p || root->data==q) return root;

    Node* left=lowestCommonAncestor(root->left,p,q);
    Node* right=lowestCommonAncestor(root->right,p,q);

    if(left!=NULL && right!=NULL) return root;
    if(left!=NULL) return left;
    else return right;
}

int main(){
    return 0;
}